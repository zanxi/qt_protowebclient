#include "dataanimals.h"

void DataSystems::clear()
{
    db_check = DB_check::SQLITE;

    db_host="";
    db_name="";
    db_login="";
    db_password="";
    db_sql_create="create.sql";
    db_sql_drop="drop.sql";
    db_sqlite_file="./db-lely3.db";

    name_animals="корова";




}
