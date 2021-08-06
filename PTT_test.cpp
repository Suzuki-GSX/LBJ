#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"


void MainWindow::on_pushButton_PTT_clicked()
{
    send_command("EA");
}

void MainWindow::on_checkBox_PTT_pass_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_pass(11);
    }
    else if(arg1==0)
    {
        test_error(11);
    }
}

void MainWindow::on_checkBox_PTT_error_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_error(11);
    }
    else if(arg1==0)
    {
        test_error(11);
    }
}

