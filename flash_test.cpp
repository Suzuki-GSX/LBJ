﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

void MainWindow::on_pushButton_flash_2_clicked()
{
    send_command("E2");
}
