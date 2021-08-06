#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

void MainWindow::on_pushButton_wdg_clicked()
{
    send_command("E3");
}

void MainWindow::on_checkBox_wdg_pass_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_pass(5);
    }
    else if(arg1==0)
    {
        test_error(5);
    }
}

void MainWindow::on_checkBox_wdg_error_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_pass(5);
    }
    else if(arg1==0)
    {
        test_error(5);
    }
}
