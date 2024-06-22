#include "src/pbsDatabase/pbssqlitedatabase.h"

PBSSQLiteDatabase::PBSSQLiteDatabase(const QString connectName, const QString dbName) :
    PBSDatabase (connectName, "QSQLITE", dbName)
    //PBSDatabase (connectName, "QPSQL", dbName)
{
}

PBSSQLiteDatabase::PBSSQLiteDatabase(const QString connectName) :
    PBSDatabase (connectName, "QSQLITE")
{
}

PBQPSQLDatabase::PBQPSQLDatabase(const QString connectName, const QString dbName, const QString login,  const QString password,  const QString  hostname,  const int port) :
      PBSDatabase (connectName, "QPSQL", dbName, login, password, hostname, port)
{
}

PBQPSQLDatabase::PBQPSQLDatabase(const QString connectName) :
    PBSDatabase (connectName, "QPSQL")
{
}
