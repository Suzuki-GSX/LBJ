#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <windows.h>
#include <QString>
#include <dbt.h>
#include <QDebug>
#include<devguid.h>
#include<SetupAPI.h>
#include<InitGuid.h>

#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void GetPort();

    static int page;
    static int time;
    static   int sendBytes;
    static   int receBytes;

    static int temp_send;
    static int DET_PW;
    static int BAT_ADC;
    static int BAT_EN;

private slots:

    /***串口***/
    void ReadData();//读取数据
    char ConvertHexChart(char ch);//十六进制转换
    void StringToHex(QString str, QByteArray & senddata);//用于发送时进制转换
    void on_openButton_clicked();
    void on_ClearButton_clicked();
//   void Mdisplay();
    void readToHex();
    /***串口***/

    /***手动选择***/
    void on_pushButton_power_clicked();
    void on_pushButton_light_clicked();
    void on_pushButton_tem_clicked();
    void on_pushButton_flash_clicked();
    void on_pushButton_wgd_clicked();
    void on_pushButton_key_clicked();
    void on_pushButton_port_clicked();
    void on_pushButton_voice_clicked();
    void on_pushButton_ffsk_clicked();
    void on_pushButton_code_clicked();
    void on_pushButton_ptt_clicked();
    void on_pushButton_sq_clicked();
    void on_pushButton_power_c_clicked();
    void on_pushButton_end_2_clicked();
    /***手动选择***/

    /***翻页***/
    void next_page_clicked(int n);
    void last_page_clicked(int n);
    /***翻页***/

    /***自动选择***/
    void on_pushButton_last_clicked();
    void on_pushButton_next_clicked();
    void on_pushButton_start_clicked();
    void on_pushButton_end_clicked();
    /***自动选择***/


    /***结束测试模块***/
    void on_pushButton_report_clicked();

    /***结束测试模块***/

    void send_command(QString str);//发送指令

    /***数据储存***/
    QString savename();
    void datasave(QString name,QString str,QString a);
    void test_pass(int n);
    void test_error(int n);
    void data_remake();
    /***数据储存***/


    /***电源测试***/
    void on_checkBox_TP3_stateChanged(int arg1);
    void on_checkBox_TP4_stateChanged(int arg1);
    void power_result();
    /***电源测试***/

    /***指示灯测试***/
    void on_checkBox_light_pass_stateChanged(int arg1);
    void on_checkBox_light_error_stateChanged(int arg1);
    /***指示灯测试***/

    /***温度测试***/
    void on_pushButton_temp_clicked();
    void on_checkBox_temp_pass_stateChanged(int arg1);
    void on_checkBox_temp_error_stateChanged(int arg1);
    /***温度测试***/


    /***flash测试***/
    void on_pushButton_flash_2_clicked();
    /***flash测试***/

    /***看门狗测试***/
    void on_pushButton_wdg_clicked();
    void on_checkBox_wdg_pass_stateChanged(int arg1);
    void on_checkBox_wdg_error_stateChanged(int arg1);
    /***看门狗测试***/

    /***报警按键测试***/
    void on_checkBox_key_pass_stateChanged(int arg1);
    void on_checkBox_key_error_stateChanged(int arg1);
    /***报警按键测试***/

    /***串口功能测试***/
    void on_pushButton_port_2_clicked();
    /***串口功能测试***/

    /***音频功能测试***/
    void on_pushButton_voice_2_clicked();
    void on_checkBox_pass_stateChanged(int arg1);
    void on_checkBox_error_stateChanged(int arg1);
    void on_pushButton_voice_add_clicked();
    /***音频功能测试***/

    /***FFSK功能测试***/
    void on_pushButton_FFSK_clicked();
    void on_pushButton_FFSK_add_clicked();
    void on_checkBox_FFSK_pass_stateChanged(int arg1);
    void on_checkBox_FFSK_error_stateChanged(int arg1);
    /***FFSK功能测试***/

    /***寻呼码功能测试***/
    void on_pushButton_code_2_clicked();
    void on_checkBox_code_pass_stateChanged(int arg1);
    void on_checkBox_code_error_stateChanged(int arg1);
    /***寻呼码功能测试***/

    /***PTT功能测试***/
    void on_pushButton_PTT_clicked();
    void on_checkBox_PTT_pass_stateChanged(int arg1);
    void on_checkBox_PTT_error_stateChanged(int arg1);
    /***PTT功能测试***/

    /***SQ功能测试***/
    void on_pushButton_SQ_clicked();
    void on_checkBox_SQ_pass_stateChanged(int arg1);
    void on_checkBox_SQ_error_stateChanged(int arg1);
    /***SQ功能测试***/


    /***电源控制功能测试***/
    void on_pushButton_DET_PW_clicked();
    void on_pushButton_BAT_ADC_clicked();
    void on_pushButton_BAT_EN_clicked();
    void on_checkBox_DET_PW_pass_stateChanged(int arg1);
    void on_checkBox_BAT_ADC_pass_stateChanged(int arg1);
    void on_checkBox_BAT_EN_pass_stateChanged(int arg1);
    void pwc_result();
    /***电源控制功能测试***/

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
};
#endif // MAINWINDOW_H
