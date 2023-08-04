#ifndef CONNECTDB
#define CONNECTDB

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

void connectDb(QSqlDatabase db);
void connectDb_pg(QSqlDatabase db);
#endif // CONNECTDB

