#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

int MainWindow::temp_send=0;

void MainWindow::on_pushButton_temp_clicked()
{
    temp_send=1;
    send_command("E1");
}


void MainWindow::send_command(QString str)
{
    if(!str.isEmpty())
    {
        int len=str.length();
        if(len%2==1)
        {
            str=str.insert(len-1,'0');
        }
        QByteArray senddata;
        StringToHex(str,senddata);
    }
}

void MainWindow::on_checkBox_temp_pass_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_pass(3);
    }
    else if(arg1==0)
    {
        test_error(3);
    }
}

void MainWindow::on_checkBox_temp_error_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_error(3);
    }
    else if(arg1==0)
    {
        test_error(3);
    }
}
