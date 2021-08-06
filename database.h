#ifndef DATABASE_H
#define DATABASE_H


#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include<QtDebug>
#include<QString>
#include <QDate>
#include <QTableView>
#include <QHeaderView>


static QSqlDatabase createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("lbj.db");
    if (!db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to e  stablish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
//        return false;
    }


/*
    QSqlQuery query(db);

    if (!query.exec("CREATE TABLE test ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "name VARCHAR,"
                    "result VARCHAR)")) {
//        QMessageBox::critical(0, QObject::tr("Database Error"),
//                              query.lastError().text());

    }
    else{
        qDebug() << "插入数据employee";
        query.exec("insert into test(id,name,result) values(1,'电源测试','不通过');");
        query.exec("insert into test(id,name,result) values(2,'指示灯','不通过');");
        query.exec("insert into test(id,name,result) values(3,'温度功能','不通过');");
        query.exec("insert into test(id,name,result) values(4,'Flash存储功能','不通过');");
        query.exec("insert into test(id,name,result) values(5,'看门狗功能','不通过');");
        query.exec("insert into test(id,name,result) values(6,'报警按键功能','不通过');");
        query.exec("insert into test(id,name,result) values(7,'串口功能','不通过');");
        query.exec("insert into test(id,name,result) values(8,'音频功能','不通过');");
        query.exec("insert into test(id,name,result) values(9,'FFSK功能','不通过');");
        query.exec("insert into test(id,name,result) values(10,'寻呼码功能','不通过');");
        query.exec("insert into test(id,name,result) values(11,'PTT功能','不通过');");
        query.exec("insert into test(id,name,result) values(12,'SQ功能','不通过');");
        query.exec("insert into test(id,name,result) values(13,'电源控制功能','不通过');");
        qDebug() << "插入数据employee  ok ";
    }*/

    return db;

}


#endif // DATABASE_H
