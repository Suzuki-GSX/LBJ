#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QMessageBox>
#include <QDataStream>

int MainWindow::sendBytes = 0;
int MainWindow::receBytes = 0;

//获得串口端口号
void MainWindow::GetPort()
{
    const auto infos = QSerialPortInfo::availablePorts();//获取可用串口 COM
    for(const QSerialPortInfo &info : infos)//检测串口是否能打开
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))//定义串口对象
        {
            ui->PortBox->addItem(info.portName());
            //qDebug()<<info.portName();
            serial.close();
        }
    }
}

//读取数据
void MainWindow::ReadData()
{

    QByteArray buf;

    if (serialPort)//串行端口能使用
    {
    buf = serialPort->readAll();//读取串口中的所有数据

    if (!buf.isEmpty())//判断缓冲区的返回值
    {
        int sq_0=0;
        int sq_1=0;

        receBytes += buf.size();//读取缓冲区长度
        QString redata = QString("received:%1").arg(QString::number(receBytes));//数据长度
//        ui->ReceiveBrowser->setText(redata);//显示在setText窗口
        QString myStrTemp = QString::fromLocal8Bit(buf); //支持中文显示
        QString str=myStrTemp;
        qDebug()<<"receive"<<str;

        ui->ReceiveBrowser->insertPlainText(str);//显示数据

        if(temp_send==1)
        {
            ui->label_temp->setText(str);
            temp_send=0;
        }

        if(flash_send==1)
        {
            if(str ==QString::fromLocal8Bit("Flash Test OK"))
            {
                test_pass(4);
                ui->label_flash_result->setText(QStringLiteral("通过"));
            }
            else
            {
                test_error(4);
                ui->label_flash_result->setText(QStringLiteral("不通过"));
            }
            flash_send=0;
        }

        if(uart_send==1)
        {
            if(str=="Uart Test OK")
            {
                test_pass(7);
                ui->label_port_result->setText(QStringLiteral("通过"));
            }
            else
            {
                test_error(7);
                ui->label_port_result->setText(QStringLiteral("不通过"));
            }
            uart_send=0;
        }

        if(ffsk_send==1)
        {
            if(str=="FFSK Test OK")
            {
                ui->label_FFSK_result->setText(QStringLiteral("通过"));
            }
            else
            {
                ui->label_FFSK_result->setText(QStringLiteral("不通过"));
            }
            ffsk_send=0;
        }

        if(sq_send==1)
        {
            ui->label_SQ_result->setText(str);
            sq_send=0;
        }

        if(pwc_send==1)
        {
            ui->label_DET_PW_result->setText(str);
            ui->label_V->setText(str);
            pwc_send=0;
        }
    }
    buf.clear();
    }
}
//单字符转16进制
char MainWindow::ConvertHexChart(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;  // 0x30 对应 ‘0’
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    //else return (-1);
    else    return ch-ch;//不在0-f范围内的会发送成0

}
//字符串转16进制发送
void MainWindow::StringToHex(QString str, QByteArray &senddata)
{
    int hexdata,lowhexdata;
           int hexdatalen = 0;
           int len = str.length();
           senddata.resize(len/2);
           char lstr,hstr;
           for(int i=0; i<len; )
           {
               //char lstr,
               hstr=str[i].toLatin1();
               if(hstr == ' ')
               {
                   i++;
                   continue;
               }
               i++;
               if(i >= len)
                   break;
               lstr = str[i].toLatin1();
               hexdata = ConvertHexChart(hstr);
               lowhexdata = ConvertHexChart(lstr);
               if((hexdata == 16) || (lowhexdata == 16))
                   break;
               else
                   hexdata = hexdata*16+lowhexdata;
               i++;
               senddata[hexdatalen] = (char)hexdata;
               qDebug()<<"send:"<<QString("%1").arg(hexdata,2,16,QLatin1Char('0')).toUpper();//不足二位补0;
               hexdatalen++;

           }
           senddata.resize(hexdatalen);

}
//16进制读取
void MainWindow::readToHex()
{
          QString str;
          QByteArray temp;
          temp = serialPort->readAll();
          QDataStream out(&temp,QIODevice::ReadOnly);    //将字节数组读入
          while(!out.atEnd())
          {
                 qint8 outChar = 0;
                 out>>outChar;   //每字节填充一次，直到结束
                 //十六进制的转换
                 str = QString("%1").arg(outChar&0xFF,2,16,QLatin1Char('0'));

                 ui->ReceiveBrowser->insertPlainText(str.toUpper());//大写
                 ui->ReceiveBrowser->insertPlainText(" ");//每发送两个字符后添加一个空格
                 ui->ReceiveBrowser->moveCursor(QTextCursor::End);
                 qDebug()<<"receive:"<<str;

           }

}

void MainWindow::on_openButton_clicked()
{
    if (ui->openButton->text() == QStringLiteral("打开串口"))//串口按钮文字变化
    {
        serialPort = new QSerialPort;

        serialPort->setPortName(ui->PortBox->currentText());

        if(serialPort->open(QIODevice::ReadWrite))
        {
            switch (ui->BaudBox->currentIndex()) {
            case 7:
                serialPort->setBaudRate(QSerialPort::Baud115200);//波特率115200
                break;
            default:
                break;
            }

            switch (ui->StopBox->currentIndex()) {
            case 0:
                serialPort->setStopBits(QSerialPort::OneStop);//停止位1位
                break;
            default:
                break;
            }

            switch (ui->DataBox->currentIndex()) {
            case 3:
                serialPort->setDataBits(QSerialPort::Data8);//数据位8位
                break;
            default:
                break;
            }

            switch (ui->ParityBox->currentIndex()) {
            case 0:
                serialPort->setParity(QSerialPort::NoParity);//奇偶校验位为无
                break;
            default:
                break;
            }

            ui->openButton->setText(QStringLiteral("关闭串口"));//串口按钮文字变化
            ui->PortBox->setEnabled(false);
            ui->BaudBox->setEnabled(false);
            ui->StopBox->setEnabled(false);
            ui->DataBox->setEnabled(false);
            ui->ParityBox->setEnabled(false);

            if(ui->rHexRadio->isChecked())
            {
                connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::ReadData);
                disconnect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readToHex);
            }
            else
            {
                disconnect(serialPort, &QSerialPort::readyRead, this, &MainWindow::ReadData);
                connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readToHex);
            }
 //           connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::ReadData);//以可读写方式字符接收
 //           connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::readToHex);//16进制接收
        }
        else
        {
            QMessageBox::critical(this, tr("Error"), serialPort->errorString());
        }
    }
    else
    {
        serialPort->clear();
        serialPort->close();
        serialPort->deleteLater();

        ui->openButton->setText(QStringLiteral("打开串口"));
        ui->PortBox->setEnabled(true);
        ui->BaudBox->setEnabled(true);
        ui->StopBox->setEnabled(true);
        ui->DataBox->setEnabled(true);
        ui->ParityBox->setEnabled(true);

        ui->ReceiveBrowser->clear();
    }
}

void MainWindow::on_ClearButton_clicked()
{
    ui->ReceiveBrowser->clear();
}

