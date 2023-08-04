#include "connectdb.h"

void connectDb(QSqlDatabase db)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./db-lely3.db");


    if (!db.open())
    {
       qDebug() << "Database Opened Fail";
       qDebug() << db.lastError();
    }
    else
    {
       qDebug() << "Database Opened";
       QSqlQuery query;       
    }
}

void connectDb_pg(QSqlDatabase db)
{    
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("192.168.124.135");
    db.setUserName("postgres");
    db.setPassword("000");
    db.setDatabaseName("vim");

    if (!db.open())
    {
       qDebug() << "Database Opened Fail";
       qDebug() << db.lastError();
    }
    else
    {
       qDebug() << "Database Opened";

       QSqlQuery query;
    }
}
