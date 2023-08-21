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


    bool inserIntoTableSqlScript(QString table);          // публичный метод - вставить в таблицу
    void FillValue();
    bool inserIntoTable(QString table, const QList<QString>  clumns, const QVariantList &data);          // публичный метод - вставить в таблицу

    ~DataBase();
    void createTables();                  //   создать таблицу
    bool Open();
    bool CreateDataBase(QString table);
    void DropTables();
    void UpdateTables();
    void UpdateTable(QString file_sql);
    void DropTable(QString table);
    void DropDataBase(QString nameDB);
    void UseDataBase(QString nameDB);
    void closeDataBase();                                 //  закрыть бд
    bool StatusOpen(){ return db_open; };
    QString GetLog();
    void WriteLog(QString msg);



    QSqlDatabase   db;                         // Сам объект базы данных
    bool sql_exec(QString nameDB, QString comment="");
    QSqlQuery* sql_exec2(QString nameDB, QString comment="");

private:
    //QSqlDatabase   db;                         // Сам объект базы данных

    bool db_open = false;
    bool connectToDataBase();                                      //  публичный метод - соединиться с бд
    void DropDB(QString nameDB);
    //bool sql_exec(QString nameDB, QString comment="");

    QString log="";



};

#endif   // DATABASE_H
