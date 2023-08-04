#ifndef DataSystems_H
#define DataSystems_H

#include <QString>

enum DB_check{ SQLITE, PGSQL };

class DataSystems   //Singleton
{
public:

    DB_check db_check;

    QString db_host;
    QString db_name;
    QString db_login;
    QString db_password;
    QString db_sql_create;
    QString db_sql_drop;

    QString db_sqlite_file;

    QString name_animals;

    static DataSystems& Instance()
    {
        static DataSystems singleton;
        return singleton;
    }

    void clear();

    // Other non-static member functions
private:
    DataSystems() {}                                  // Private constructor
    ~DataSystems() {}
    DataSystems(const DataSystems&);                 // Prevent copy-construction
    DataSystems& operator=(const DataSystems&);      // Prevent assignment
};

#endif // DataSystems_H
