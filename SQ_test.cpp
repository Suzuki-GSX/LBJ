#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"


void MainWindow::on_pushButton_SQ_clicked()
{
    send_command("EB");
}

void MainWindow::on_checkBox_SQ_pass_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_pass(12);
    }
    else if(arg1==0)
    {
        test_error(12);
    }
}

void MainWindow::on_checkBox_SQ_error_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_error(12);
    }
    else if(arg1==0)
    {
        test_error(12);
    }
}
