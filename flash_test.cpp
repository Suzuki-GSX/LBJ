#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

int MainWindow::flash_send=0;

void MainWindow::on_pushButton_flash_2_clicked()
{
    flash_send=1;
    //send_command("E2");
    serialPort->write("Flash Test OK");
}
