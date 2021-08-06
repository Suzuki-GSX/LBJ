#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

void MainWindow::on_pushButton_FFSK_clicked()
{
    send_command("E7");
}

void MainWindow::on_pushButton_FFSK_add_clicked()
{
    QString FFSK_add="E8";
    QString add=ui->lineEdit_FFSK_add->text();
    if(add.isEmpty())
    {
        add="09";
    }
    FFSK_add+=add;
    send_command(FFSK_add);
}

void MainWindow::on_checkBox_FFSK_pass_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_pass(9);
    }
    else if(arg1==0)
    {
        test_error(9);
    }
}

void MainWindow::on_checkBox_FFSK_error_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_error(9);
    }
    else if(arg1==0)
    {
        test_error(9);
    }
}


