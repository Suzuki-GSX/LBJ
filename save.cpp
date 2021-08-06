#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QFileDialog>
#include "database.h"

QString MainWindow::savename()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Save File"),"",
        tr("Text Files(*.txt)"));
    return fileName;
}

void MainWindow::datasave(QString name,QString str,QString a)
{
    QFile data(name);
    str+="         ";
    if(data.open(QFile::Append|QIODevice::Append))
    {
        QTextStream out(&data);
        out << str << a;
        out << "\r\n" ;
        data.close();
    }
}

void MainWindow::test_pass(int n)
{
    QSqlQuery query;
    QString update_sql="update test set result = :result where id = :id";
    query.prepare(update_sql);
    query.bindValue(":result",QStringLiteral("通过"));
    query.bindValue(":id",n);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    else
    {
        qDebug() << "updated";
    }
}

void MainWindow::test_error(int n)
{
    QSqlQuery query;
    QString update_sql="update test set result = :result where id = :id";
    query.prepare(update_sql);
    query.bindValue(":result",QStringLiteral("不通过"));
    query.bindValue(":id",n);
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    else
    {
        qDebug() << "updated";
    }
}

void MainWindow::data_remake()
{
    QSqlQuery query;
    QString update_sql="update test set result = :result";
    query.prepare(update_sql);
    query.bindValue(":result",QStringLiteral("不通过"));
    if(!query.exec())
    {
        qDebug() << query.lastError();
    }
    else
    {
        qDebug() << "updated";
    }
}
