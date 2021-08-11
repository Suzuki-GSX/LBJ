#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

void MainWindow::on_checkBox_key_pass_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_pass(6);
    }
    else if(arg1==0)
    {
        test_error(6);
    }
}

void MainWindow::on_checkBox_key_error_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_error(6);
    }
    else if(arg1==0)
    {
        test_error(6);
    }
}

