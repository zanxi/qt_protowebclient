#include "generatedbdata.h"

#include "db/database.h"
#include "dataanimals.h"
#include <math.h>


GenerateDBData::GenerateDBData(QObject *parent): QThread(parent)
{

}

GenerateDBData::GenerateDBData(QString nameSubsystem,int ip, QObject *parent): QThread(parent)
{

}

void GenerateDBData::run()
{
    double now = QDateTime::currentDateTime().toTime_t();
    int i=0;
    QScopedPointer<DataBase> db_func(new DataBase());    
    while(status){
        //qDebug("thread one----------");
        //emit threadSignal1();
        //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);        
        if(db_func->StatusOpen())
        {
            //for(int i=0;i<10;i++)
            xi=xi+0.002;
            yi=5*cos(5*xi)-4*cos(xi)-3*sin(2*xi)+2*sin(4*xi)+6*sin(3*xi)-7*sin(2*xi);
            //zi=1*cos(3*xi)-2*cos(4*xi)-5*sin(xi)+3*sin(2*xi);
            zi=rand()%2*cos(3*xi);
            wi=10*cos((rand()%2)*xi)-7*cos((rand()%3)*xi);

            QDateTime dt1 = QDateTime::currentDateTime();
            //QDateTime dt2 = QDateTime::currentDateTime();
            //QDateTime dt1 = QDateTime::currentDateTime();
            //db_func->insert_add(tab, "paramtime1", dt1.toString("yyyy-MM-ddThh:mm:ss.ms"));

            db_func->insert_add("bigdata", "param1", QString::number(xi));
            //db_func->insert_add("bigdata", "timey1", dt1.toString("yyyy-MM-ddThh:mm:ss.ms"));
            db_func->insert_add("bigdata", "timey1", dt1.toString("yyyy-MM-ddThh:mm:ss.zzzZ"));
            now+=i+1000*100;
            i++;
            db_func->insert_add("bigdata", "timey2", QString::number(now));
            //db_func->insert_add("bigdata", "timeh1", dt2.toString());
            //db_func->insert_add("bigdata", "date2", QString::number(xi));
            db_func->insert_add("bigdata", "param2", QString::number(yi));
            db_func->insert_add("bigdata", "param3", QString::number(zi));
            QString sql_insert = db_func->insert_add("bigdata", "param4", QString::number(wi));

            db_func->sql_exec(sql_insert, "add bigdata");

        }

        usleep(1000*100);
    }
}
