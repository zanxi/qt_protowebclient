#ifndef PBSSQLITEDATABASE_H
#define PBSSQLITEDATABASE_H

#include <QObject>
#include "src/pbsDatabase/pbsdatabase.h"

class PBSSQLiteDatabase : public PBSDatabase
{
    Q_OBJECT
public:
    explicit PBSSQLiteDatabase(const QString connectName, const QString dbName);
    explicit PBSSQLiteDatabase(const QString connectName);

signals:

public slots:
};

class PBQPSQLDatabase : public PBSDatabase
{
    Q_OBJECT
public:
    explicit PBQPSQLDatabase(const QString connectName, const QString dbName, const QString login,  const QString password,   const QString hostname,  const int port);
    explicit PBQPSQLDatabase(const QString connectName);

signals:

public slots:
};


#endif // PBSSQLITEDATABASE_H
