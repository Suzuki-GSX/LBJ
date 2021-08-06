#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

void MainWindow::on_pushButton_code_2_clicked()
{
    send_command("E9");
}

void MainWindow::on_checkBox_code_pass_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_pass(10);
    }
    else if(arg1==0)
    {
        test_error(10);
    }
}

void MainWindow::on_checkBox_code_error_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_error(10);
    }
    else if(arg1==0)
    {
        test_error(10);
    }
}
