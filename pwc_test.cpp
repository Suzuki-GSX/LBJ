#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

int MainWindow::DET_PW=0;
int MainWindow::BAT_ADC=0;
int MainWindow::BAT_EN=0;

void MainWindow::on_pushButton_DET_PW_clicked()
{
    send_command("EC");
}

void MainWindow::on_pushButton_BAT_ADC_clicked()
{
    send_command("ED");
}

void MainWindow::on_pushButton_BAT_EN_clicked()
{
    send_command("EE");
}

void MainWindow::on_checkBox_DET_PW_pass_stateChanged(int arg1)
{
    if(arg1==2)
        DET_PW=1;
    else if(arg1==0)
        DET_PW=0;

    pwc_result();
}

void MainWindow::on_checkBox_BAT_ADC_pass_stateChanged(int arg1)
{
    if(arg1==2)
        BAT_ADC=1;
    else if(arg1==0)
        BAT_ADC=0;

    pwc_result();
}

void MainWindow::on_checkBox_BAT_EN_pass_stateChanged(int arg1)
{
    if(arg1==2)
        BAT_EN=1;
    else if(arg1==0)
        BAT_EN=0;

    pwc_result();
}

void MainWindow::pwc_result()
{
    if(DET_PW&&BAT_ADC&&BAT_EN)
        test_pass(13);
    else
        test_error(13);
}
