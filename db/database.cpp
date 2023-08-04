#include "database.h"
#include "dataanimals.h"


DataBase::DataBase(QObject *parent) : QObject(parent) { }

DataBase::~DataBase() {}


void DataBase::connectToDataBase()                                          //  метод подключения к БД.   Если нашей бд не существовало, она будет создана и подключена.
{
    switch(DataSystems::Instance().db_check)
    {
    case DB_check::SQLITE:
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DataSystems::Instance().db_sqlite_file);
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
         break;
    }
    }

         if (db.open())  {
               if(tryCreateNewDataBase(DataSystems::Instance().db_sql_create)){
                      QMessageBox::information(0, "Ок", "База данных " DB_NAME " создана. Подключение прошло успешно.");              //  пытаемся создать нашу БД, если она уже существует, то не будет создана.

               }
               db.setDatabaseName(DataSystems::Instance().db_name);                                                                                                                                   //  переподключаемся к ней.
               if (!db.open()) {
                     // QMessageBox::critical(0, "Ошибка", "Не удалось подключиться к базе данных " DB_NAME);
               }
               else {
                      //QMessageBox::information(0, "Ок", "Успешное подключение к базе данных " DB_NAME);
               }
         }
         else { QMessageBox::critical(0, "Ошибка", "Не удалось подключиться к серверу."); }

      tryCreateNewDataBase(DataSystems::Instance().db_sql_create);
}

void DataBase::createTables(QString file_sql)                       // Метод  создания таблиц
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE IF NOT EXISTS "  " ("                       //   создаем qual_table  ,  если она не создана.
                            "p00    CHARACTER VARYING(2) UNIQUE, "
                            "p01    TEXT  "
                        "  )"  )) {
        qDebug() << "DataBase: error of create " << file_sql;                     //  вывод возможной ошибки при создании.
        qDebug() << query.lastError().text();
    }


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


bool DataBase::tryCreateNewDataBase(QString file_sql)
{
    QFile file(file_sql);
    bool ret = file.open(QFile::ReadOnly);
    if (ret) {
        QSqlQuery *query = new QSqlQuery(db);
        if(!query->exec(file.readAll())) {
                      qDebug() << "DataBase: error of create database " << DB_NAME;                     //  если такая БД уже существует, эта информация будет выведена в отладке.
                      qDebug() << query->lastError().text();
                      return false;
        }
        file.close();
    }
    else return true;
}

void DataBase::closeDataBase()  {  db.close();  }
