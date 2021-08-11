#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "database.h"

int MainWindow::page;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QSqlDatabase db=createConnection();

    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("LBJ测试"));
    GetPort();

}

MainWindow::~MainWindow()
{
    delete ui;
}

/************************手动按键切换*****************************/


void MainWindow::on_pushButton_power_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    page=0;
}

void MainWindow::on_pushButton_light_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    page=1;
}

void MainWindow::on_pushButton_tem_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    page=2;
}

void MainWindow::on_pushButton_flash_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    page=3;
}

void MainWindow::on_pushButton_wgd_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    page=4;
}

void MainWindow::on_pushButton_key_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    page=5;
}

void MainWindow::on_pushButton_port_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    page=6;
}

void MainWindow::on_pushButton_voice_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    page=7;
}

void MainWindow::on_pushButton_ffsk_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    page=8;
}

void MainWindow::on_pushButton_code_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
    page=9;
}

void MainWindow::on_pushButton_ptt_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    page=10;
}

void MainWindow::on_pushButton_sq_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    page=11;
}

void MainWindow::on_pushButton_power_c_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
    page=12;
}

void MainWindow::on_pushButton_end_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
    page=13;
}

/************************手动按键切换*****************************/



void MainWindow::next_page_clicked(int n)
{
    n=n+1;
    ui->stackedWidget->setCurrentIndex(n);
}

void MainWindow::last_page_clicked(int n)
{
    n=n-1;
    ui->stackedWidget->setCurrentIndex(n);
}



void MainWindow::on_pushButton_last_clicked()
{
    last_page_clicked(page);
    page--;
}

void MainWindow::on_pushButton_next_clicked()
{
    next_page_clicked(page);
    page++;
}

void MainWindow::on_pushButton_start_clicked()
{
    on_pushButton_power_clicked();
}

void MainWindow::on_pushButton_end_clicked()
{
    on_pushButton_end_2_clicked();
}


