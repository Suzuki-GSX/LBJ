#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

void MainWindow::on_pushButton_voice_2_clicked()
{
    send_command("E6");
}

void MainWindow::on_pushButton_voice_add_clicked()
{
    QString voice_add="F1";
    QString add=ui->lineEdit_add->text();
    if(add.isEmpty())
    {
        add="13";
    }
    voice_add+=add;
    send_command(voice_add);
}

void MainWindow::on_checkBox_pass_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_pass(8);
    }
    else if(arg1==0)
    {
        test_error(8);
    }
}

void MainWindow::on_checkBox_error_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_error(8);
    }
    else if(arg1==0)
    {
        test_error(8);
    }
}

