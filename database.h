#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>



#define DB_NAME   "vim2"


class DataBase : public QObject
{
    Q_OBJECT
public:
    DataBase(QObject *parent = 0);

    void connectToDataBase();                                      //  публичный метод - соединиться с бд
    bool inserIntoTableSqlScript(QString table);          // публичный метод - вставить в таблицу
    bool inserIntoTable(QString table, const QList<QString>  clumns, const QVariantList &data);          // публичный метод - вставить в таблицу

    ~DataBase();
    void createTables(QString fileSql);                  //   создать таблицу
    bool CreateDataBase(QString table);
    void closeDataBase();                                 //  закрыть бд
    QString GetLog();
    void WriteLog(QString msg);

private:
    QSqlDatabase   db;                         // Сам объект базы данных

    QString log="";



};

#endif   // DATABASE_H
