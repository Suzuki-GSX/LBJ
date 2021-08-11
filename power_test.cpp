#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

int TP3=0;
int TP4=0;

void MainWindow::on_checkBox_TP3_stateChanged(int arg1)
{
    if(arg1==2)//打勾
    {
        TP3=1;
    }
    else if(arg1==0)
    {
        TP3=0;
    }
    power_result();
}
void MainWindow::on_checkBox_TP4_stateChanged(int arg1)
{
    if(arg1==2)
    {
        TP4=1;
    }
    else if(arg1==0)
    {
        TP4=0;
    }
    power_result();
}

void MainWindow::power_result()
{
    if(TP3&&TP4)
    {
        test_pass(1);
    }
    else
    {
        test_error(1);
    }
}

