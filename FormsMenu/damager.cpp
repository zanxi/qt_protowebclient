#include "damager.h"
#include "./rwlock/thr_safe.h"
#include "./db/database.h"
#include "Debug/logger.h"
#include "dataanimals.h"


Damager::Damager()
{

}

Damager::Damager(Damager const &dam)
{

}

void Damager::addResponce(Data_xyzt data)
{
    list_dataPlot.push(data);

}

void Damager::Workers()
{

    for (unsigned i = 0; i < No_THREADS; ++i)
        damagers.push_back(std::thread([&, i]() {
            // I/O locked
            {
                std::lock_guard<std::mutex> lock(cerrMutex);
                std::cerr << "THREAD #" << i << " pushing " << i * No_THREADS << " into Queue.\n";
                //logger::WriteMsg("THREAD #" + std::to_string(i) + " pushing " + std::to_string(i * No_THREADS) + " into Queue.");
            }
            ///queue.push(i*No_THREADS);
            //GetWorkStroki_Run("test3.txt", queue_shd);
        }));
    // consumers are creating

    for (unsigned i = 0; i < No_THREADS_con; i++)
        responders.push_back(std::thread([&, i]() {

            Data_xyzt data;
            ThreadSafeQ<Data_xyzt>::QueueResult result;
            while ((result = list_dataPlot.pop(data)) != ThreadSafeQ<Data_xyzt>::CLOSED)
            {
                std::lock_guard<std::mutex> lock(cerrMutex);
                FindSearch("bigdata",0,10, data, map_dataplot);
            }
        }));
}

void Damager::FindSearch(
    string mask,
    Data_xyzt _data,
    MAP_DataPlot& safe_ResultSearch_data)
{

}

void Damager::FindSearch(
    QString tab,
    int idStart,
    int idEnd,
    Data_xyzt _data,
    MAP_DataPlot& safe_ResultSearch_data)
{
    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {

        QString sql =  QString("SELECT * FROM public."+tab+" WHERE id >=  " + QString::number(idStart) +" AND idEnd < "+QString::number(idEnd)).toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        int i=0;
        while(query->next())
        {
            Data_xyzt data;
            data.id =  query->value("id").toInt();
            data.x =  query->value("prime1").toDouble();
            data.y =  query->value("prime2").toDouble();

            //map_dataplot.insert(std::map<int, Data_xyzt>::value_type(data.id, data));
            list_dataPlot.push(data);

            //DataSystems::Instance().dataentry_dataentry_cow_card_description = query->value("description").toString();
            //DataSystems::Instance().dataentry_dataentry_cow_card_transfer_in = query->value("transfer_in").toString();
            //break;
        }
    }

}
