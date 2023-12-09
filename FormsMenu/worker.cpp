#include "worker.h"

Worker::Worker()
{

}

Worker::Worker(int s, int e, int t):start(s),end(e),threadN(t)
{

}

Worker::Worker(QString name, LIST_DataPlot list_dataPlot_, Damager dam_)
{
    //dam = dam_;
    //list_dataPlot = list_dataPlot_;
}

void Worker::run()
{
    //QScopedPointer<DataBase> db_func(new DataBase());
    Data_xyzt data;
    ThreadSafeQ<Data_xyzt>::QueueResult result;
    while ((result = list_dataPlot.pop(data)) != ThreadSafeQ<Data_xyzt>::CLOSED)
    {
        //std::lock_guard<std::mutex> lock(cerrMutex);
        //FindSearch(mask, _searchtd, safe_ResultSearch);
    }
    while(status){        
        if(map_dataPlot.empty())
        {
            usleep(1000*1000);
            continue;
        }
    }
}

