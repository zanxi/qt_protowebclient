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
    bool inserIntoTable(QString table, const QList<QString>  clumns, const QVariantList &data);          // публичный метод - вставить в таблицу

    ~DataBase();

private:
    QSqlDatabase   db;                         // Сам объект базы данных

    void closeDataBase();               //  закрыть бд
    void createTables(QString fileSql);                  //   создать таблицу
    bool tryCreateNewDataBase(QString table);
};

#endif   // DATABASE_H
