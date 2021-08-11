#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

int MainWindow::uart_send=0;

void MainWindow::on_pushButton_port_2_clicked()
{
    uart_send=1;
    send_command("E5");
    //serialPort->write("Uart Test OK");测试用
}
