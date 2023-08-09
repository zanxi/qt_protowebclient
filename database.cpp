#include "database.h"
#include "dataanimals.h"
#include "Debug/logger.h"


#include <QSqlQuery>
#include <QDir>
#include <QSqlError>
#include <QJsonArray>
#include <QSqlRecord>


DataBase::DataBase(QObject *parent) : QObject(parent) { }

DataBase::~DataBase() {}

void DataBase::WriteLog(QString msg)
{
    log+=QString(" | ")+QString::fromStdString(datetime::utcExample())+"| message: "+msg+"  "+"\n";

}

void DataBase::connectToDataBase()                                          //  метод подключения к БД.   Если нашей бд не существовало, она будет создана и подключена.
{
    switch(DataSystems::Instance().db_check)
    {
    case DB_check::SQLITE:
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DataSystems::Instance().db_sqlite_file);
        logger::WriteMsg(QString("Подключение к драйверу SQLITE; база данных <<<" + DataSystems::Instance().db_sqlite_file +  ">>>").toStdString());
        logger::WriteLog("Подключение к драйверу SQLITE; база данных <<<" + DataSystems::Instance().db_sqlite_file);
        break;
    }
    case DB_check::PGSQL:
    {
         QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");              //  драйвер
         db.setUserName(DataSystems::Instance().db_login);
         db.setPassword(DataSystems::Instance().db_password);
         db.setHostName(DataSystems::Instance().db_host);              // или  localhost
         db.setPort(5432);
         db.setDatabaseName(DataSystems::Instance().db_name);       //  сперва подключаемся к встроенной бд, что-бы иметь возможность создать нашу.
         logger::WriteMsg(QString("Подключение к драйверу PostgreSQL; база данных <<<" + DataSystems::Instance().db_name +  ">>>").toStdString());
         logger::WriteLog("Подключение к драйверу PostgreSQL; база данных <<<" + DataSystems::Instance().db_name +  ">>>");
         break;
    }
    }

         if (db.open())  {
               if(CreateDataBase(DataSystems::Instance().db_sql_create)){
                      //QMessageBox::information(0, "Ок", "База данных " DB_NAME " создана. Подключение прошло успешно.");              //  пытаемся создать нашу БД, если она уже существует, то не будет создана.
                      logger::WriteMsg(QString("База данных <<<" + DataSystems::Instance().db_sql_create +  ">>> создана. Подключение прошло успешно.").toStdString());
                      logger::WriteLog("База данных <<<" + DataSystems::Instance().db_sql_create +  ">>> создана. Подключение прошло успешно.");
                      return;

               }
         }
         else {
               QMessageBox::critical(0, "Ошибка", "Не удалось подключиться к серверу.");
               logger::WriteMsg(QString("Не удалось подключиться к серверу. <<<" + DataSystems::Instance().db_sqlite_file +  ">>>").toStdString());
               logger::WriteLog("Не удалось подключиться к серверу. <<<" + DataSystems::Instance().db_sqlite_file +  ">>>");
         }

      //tryCreateNewDataBase(DataSystems::Instance().db_sql_create);
}

bool DataBase::inserIntoTableSqlScript(QString file_sql)                  //   метод вставки строки в таблицу qual_table ,  принимает QVariantList  т.к.  значения в таблицах могут быть разных типов.
{
         QFile file(file_sql);
         bool ret = file.open(QFile::ReadOnly);
         if (ret) {
               QSqlQuery *query = new QSqlQuery(db);
               QString sql_script = QString(file.readAll());
               logger::WriteLog(sql_script);
               if(!query->exec(sql_script)) {
                      qDebug() << "DataBase: error INSERT to database " << DB_NAME;                     //  если такая БД уже существует, эта информация будет выведена в отладке.
                      logger::WriteLog(QString("DataBase::CreateDataBase ----> DataBase: error INSERT to  database <<<" + DataSystems::Instance().db_sqlite_file));
                      qDebug() << query->lastError().text();
                      return false;
               }
               else
               {
                      logger::WriteLog(QString("DataBase::CreateDataBase ----> DataBase:  INSERT excellent !!!! <<<" + DataSystems::Instance().db_sqlite_file));
               }
               file.close();
         }
         else return true;


}


bool DataBase::inserIntoTable(QString table, const QList<QString>  columns, const QVariantList  &data)                  //   метод вставки строки в таблицу qual_table ,  принимает QVariantList  т.к.  значения в таблицах могут быть разных типов.
{
    QSqlQuery query;

    QString vars = columns[0];
    for(int i=1; i<columns.count();i++)vars+=", "+ columns[i];
    QString insert="INSERT INTO " + table + " ( " + vars+ " ) " "VALUES ";

    QString values = data[0].toString();
    for(int i=1; i<data.count();i++)vars+=", "+ data[i].toString();

    insert+= " ( " + values+ ")";

    //query.prepare( "INSERT INTO " + table + " ( p00,  p01, p02 ) "            //   готовим запрос
    //                                       "VALUES  (?,?,?)");

    for(int i=1; i<data.count();i++)query.addBindValue(data[i].toString());
    query.addBindValue(data[1].toString());

    query.prepare(insert);

    if(!query.exec()){                                                                       //  выполняем запрос методом exec()
        qDebug() << "error insert into " << table;
        qDebug() << query.lastError().text();                                       //  в этом методе предусмотрен вывод информации об ошибках.
        return false;
    } else {
        return true;
    }
}

void DataBase::createTables(QString file_sql)
{

}

bool DataBase::CreateDataBase(QString file_sql)
{
    QFile file(file_sql);
    bool ret = file.open(QFile::ReadOnly);
    if (ret) {
        QSqlQuery *query = new QSqlQuery(db);
        QString sql_script = QString(file.readAll());
        logger::WriteLog(sql_script);
        if(!query->exec(sql_script)) {
                      qDebug() << "DataBase: error of create database " << DB_NAME;                     //  если такая БД уже существует, эта информация будет выведена в отладке.
                      logger::WriteLog(QString("DataBase::CreateDataBase ----> DataBase: error of create database <<<" + DataSystems::Instance().db_sqlite_file));
                      qDebug() << query->lastError().text();
                      return false;
        }
        else
        {
                logger::WriteLog(QString("DataBase::CreateDataBase ----> DataBase: create excellent !!!! <<<" + DataSystems::Instance().db_sqlite_file));
        }
        file.close();
    }
    else return true;
}

QString DataBase::GetLog()  {  return log;  }

void DataBase::closeDataBase()  {  db.close();  }
