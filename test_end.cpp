#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"
#include <QVariant>

void MainWindow::on_pushButton_report_clicked()
{
    QString txt_name=savename();
    QFile file(txt_name);
    qDebug()<<txt_name;
    QSqlQuery query;
    QString select_sql;
    for(int i=1;i<=13;i++)
    {
        select_sql="select id, name, result from test where id =";
        query.prepare(select_sql);
        select_sql+=QString::number(i);
        //qDebug()<<select_sql;
        if(!query.exec(select_sql))
        {
            //qDebug()<<i;
            qDebug()<<query.lastError();
        }
        else
        {
            //qDebug()<<"shuju ok";
            while(query.next())
            {
                int id=query.value(0).toInt();
                QString name=query.value(1).toString();
                QString result=query.value(2).toString();
                datasave(txt_name,name,result);
            }
        }
    }

    if(!file.open(QFile::Append|QIODevice::Append))//写入备注
    {
        QMessageBox::critical(this,tr("Error"),
                              tr("Save Error!"));
    }
    else
    {
        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText();
        stream.flush();
        file.close();
    }

    QMessageBox::warning(this,QStringLiteral("ok"),
                         QStringLiteral("报告生成结束"));

    data_remake();

}
