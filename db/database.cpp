#include "database.h"
#include "dataanimals.h"
#include "Debug/logger.h"
#include "csv/csvfile.h"

#include <QSqlQuery>
#include <QDir>
#include <QSqlError>
#include <QJsonArray>
#include <QSqlRecord>

DataBase::DataBase(QObject *parent) : QObject(parent)
{
}

DataBase::~DataBase() {}

void DataBase::WriteLog(QString msg)
{
    log+=QString(" | ")+QString::fromStdString(datetime::utcExample())+"| message: "+msg+"  "+"\n";
}

bool DataBase::Open()                                          //  метод подключения к БД.   Если нашей бд не существовало, она будет создана и подключена.
{
    db_open = connectToDataBase();
    return db_open;
}

bool DataBase::connectToDataBase()                                          //  метод подключения к БД.   Если нашей бд не существовало, она будет создана и подключена.
{
    switch(DataSystems::Instance().db_check)
    {
        case DB_check::SQLITE:
        {
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName(DataSystems::Instance().db_sqlite_file);
            logger::WriteMsg(QString("Подключение к драйверу SQLITE; база данных <<<" + DataSystems::Instance().db_sqlite_file +  ">>>").toStdString());
            logger:WriteLog("Подключение к драйверу SQLITE; база данных <<<" + DataSystems::Instance().db_sqlite_file);
            break;
        }
         case DB_check::PGSQL:
         {
            db = QSqlDatabase::addDatabase("QPSQL");              //  драйвер
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
         bool ret = db.open();
         if (ret)
         {
                logger::WriteMsg(QString("База данных <<<" + DataSystems::Instance().db_sql_create +  ">>> создана. Подключение прошло успешно.").toStdString());
                logger::WriteLog("База данных <<<" + DataSystems::Instance().db_sql_create +  ">>> создана. Подключение прошло успешно.");
         }
         else
         {
                QMessageBox::critical(0, "Ошибка", "Не удалось подключиться к серверу.");
                logger::WriteLog("Не удалось подключиться к серверу. <<<" + DataSystems::Instance().db_sqlite_file +  ">>>");
         }
         return ret;
}

void DataBase::FillValue()                  //   метод вставки строки в таблицу qual_table ,  принимает QVariantList  т.к.  значения в таблицах могут быть разных типов.
{
         std::vector<std::string> tabFiles = csvfile::ReadFiles();
         //std::string sql_script="";

         for(auto fn:tabFiles)
         {
               inserIntoTableSqlScript(QString::fromStdString("insert_table_"+fn+".sql"));
               logger::WriteMsg(QString::fromStdString("insert_table_"+fn+".sql").toStdString());
               logger::WriteLog(QString::fromStdString("insert_table_"+fn+".sql"));
               //return;
         }
}

bool DataBase::inserIntoTableSqlScript(QString file_sql)                  //   метод вставки строки в таблицу qual_table ,  принимает QVariantList  т.к.  значения в таблицах могут быть разных типов.
{
         QFile file(file_sql);
         bool ret = file.open(QFile::ReadOnly);
         if (ret) {
               QString sql_script = QString(file.readAll());
               bool status = sql_exec(sql_script);
               if(!status) {
                   logger::WriteLog("Error Insert data to tables sql script: XXXXXXXXXXXXXXXXX ");
                   logger::WriteLog(file_sql);
               }
               else
               {
                   //logger::WriteLog("Excellent sql script: !!!!!!!!!!!!!!!!!! ");
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

void DataBase::createTables()
{
    std::vector<std::string> tabFiles = csvfile::ReadFiles();
    //std::string sql_script="";

    for(auto fn:tabFiles)
    {
        CreateDataBase(QString::fromStdString("create_table_"+fn+".sql"));
    }
}

void DataBase::DropTables()
{
    std::vector<std::string> tabFiles = csvfile::ReadFiles();

    for(auto fn:tabFiles)
    {
        DropTable(QString::fromStdString("drop_table_"+fn+".sql"));
    }
}

void DataBase::UpdateTables()
{
    std::vector<std::string> tabFiles = csvfile::ReadFiles();

    for(auto fn:tabFiles)
    {
        //UpdateTable(QString::fromStdString("update_table_"+fn+".sql"));
    }

    UpdateTable(QString::fromStdString("update_table_RIndication.sql"));
}


void DataBase::UpdateTable(QString file_sql)
{
    QFile file(file_sql);
    bool ret = file.open(QFile::ReadOnly);
    if (ret) {
        QString sql_script = QString(file.readAll());
        sql_script.remove("-");
        bool status = sql_exec(sql_script);
        if(!status) {
                   logger::WriteLog("Error Update sql script: XXXXXXXXXXXXXXXXX ");
                   logger::WriteLog(file_sql);
        }
        else
        {
            logger::WriteLog("Excellent Update sql script: !!!!!!!!!!!!!!!!!! ");
        }
        file.close();
    }
    else return;
}


void DataBase::DropTable(QString file_sql)
{
    QFile file(file_sql);
    bool ret = file.open(QFile::ReadOnly);
    if (ret) {
        QString sql_script = QString(file.readAll());
        bool status = sql_exec(sql_script);
        if(!status) {
            logger::WriteLog("Error Delete sql script: XXXXXXXXXXXXXXXXX ");
            logger::WriteLog(file_sql);
        }
        else
        {
            //logger::WriteLog("Excellent sql script: !!!!!!!!!!!!!!!!!! ");
        }
        file.close();
    }
    else return;
}

void DataBase::DropDB(QString file_sql)
{
    QFile file(file_sql);
    bool ret = file.open(QFile::ReadOnly);
    if (ret) {
        QString sql_script = QString(file.readAll());
        sql_exec(sql_script);
        file.close();
    }
    else return;
}

void DataBase::DropDataBase(QString nameDB)
{
    //std::string sql_script="";
    DropDB(QString::fromStdString("drop_db.sql"));

}

void DataBase::UseDataBase(QString nameDB)
{
    //std::string sql_script="";
    sql_exec(QString("USE database "+nameDB+";"));

}

bool DataBase::CreateDataBase(QString file_sql)
{
    QFile file(file_sql);
    bool ret = file.open(QFile::ReadOnly);
    if (ret) {        
        QString sql_script = QString(file.readAll());
        bool status = sql_exec(sql_script);
        if(!status) {
            logger::WriteLog("Error Executive Create sql script: XXXXXXXXXXXXXXXXX ");
            logger::WriteLog(file_sql);
        }
        else
        {
            logger::WriteLog("Excellent executive create sql script: !!!!!!!!!!!!!!!!!! ");
        }
        file.close();
    }
    else return true;
}

bool DataBase::sql_exec(QString sql_script, QString comment)
{
        QSqlQuery *query = new QSqlQuery(db);
        if(!query->exec(sql_script)) {
                 logger::WriteMsg(
                                 QString("Error sql script: XXXXXXXXXXXXXXXXX "+
                                 comment+
                                 " --- "+
                                 sql_script +
                                 " ----> error ").toStdString());
                //logger::WriteLog("Error sql script: XXXXXXXXXXXXXXXXX ");
                //logger::WriteLog(sql_script);
                return false;
        }
        else
        {
                //logger::WriteMsg(QString("DataBase::"+comment+" ---"+ sql_script +" ----> DataBase: create excellent !!!! <<<" + DataSystems::Instance().db_sqlite_file).toStdString());
                //logger::WriteLog("Error Excellent sql script: !!!!!!!!!!!!!!!!!! ");
                return true;
        }
}

QSqlQuery* DataBase::sql_exec2(QString sql_script, QString comment)
{
        QSqlQuery *query = new QSqlQuery(db);
        if(!query->exec(sql_script)) {
                logger::WriteMsg(
                    QString("Error sql script: XXXXXXXXXXXXXXXXX "+
                            comment+
                            " --- "+
                            sql_script +
                            " ----> error ").toStdString());
                //logger::WriteLog("Error sql script: XXXXXXXXXXXXXXXXX ");
                //logger::WriteLog(sql_script);
                return nullptr;
        }
        else
        {
                //logger::WriteMsg(QString("DataBase::"+comment+" ---"+ sql_script +" ----> DataBase: create excellent !!!! <<<" + DataSystems::Instance().db_sqlite_file).toStdString());
                //logger::WriteLog("Error Excellent sql script: !!!!!!!!!!!!!!!!!! ");
                return query;
        }
}


QString DataBase::GetLog()  {  return log;  }

void DataBase::closeDataBase()  {  db.close();  }
