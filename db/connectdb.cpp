#include "connectdb.h"

void connectDb(QSqlDatabase db)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./db-lely3.db");

//    db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");
//    db.setUserName("root");
//    db.setPassword("MySql");
//    db.setDatabaseName("qtdb");

    if (!db.open())
    {
       qDebug() << "Database Opened Fail";
       qDebug() << db.lastError();
    }
    else
    {
       qDebug() << "Database Opened";
       QSqlQuery query;

       if (!db.tables().contains("student"))
       {
           bool createStuTb = query.exec("create table student \
                                         (Id char(10) primary key, Name varchar(20), Sex varchar(10),\
                                          Major varchar(30), Birth char(8), Tel char(11), Address varchar(50))");

           if (createStuTb)
           {
               query.exec("insert into student values(1,NULL,NULL,NULL,NULL,NULL,NULL)");
           }
       }
       else
       {
           qDebug() << "Table student already exsit" ;
           qDebug() << query.lastError();
       }

       if (!db.tables().contains("teacher"))
       {
           bool createTeaTb = query.exec("create table teacher \
                                         (Id char(10) primary key, Name varchar(20), Sex varchar(10), Major varchar(30),\
                                          Birth char(8), Tel char(11), Address varchar(50), Class varchar(20))");

           if (createTeaTb)
           {
               query.exec("insert into teacher values(1,NULL,NULL,NULL,NULL,NULL,NULL,NULL)");
           }
       }
       else
       {
           qDebug() << "Table teacher already exsit" ;
           qDebug() << query.lastError();
       }
    }
}
