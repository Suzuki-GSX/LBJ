#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

void MainWindow::on_checkBox_light_pass_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_pass(2);
    }
    else if(arg1==0)
    {
        test_error(2);
    }
}
void MainWindow::on_checkBox_light_error_stateChanged(int arg1)
{
    if(arg1==2)
    {
        test_error(2);
    }
    else if(arg1==0)
    {
        test_error(2);
    }
}

