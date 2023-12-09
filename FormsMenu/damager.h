#ifndef DAMAGER_H
#define DAMAGER_H

#include <QThread>
#include "rwlock/shd.h"

class Damager// : QThread
{
public:
    //Damager();
    LIST_DataPlot list_dataPlot;
    QString name;

    Damager();
    Damager(Damager const&);
    void addResponce(Data_xyzt data);

    Damager& operator=(Damager other)
    {
        //std::cout << "copy assignment of A\n";
        //other.list_dataPlot = list_dataPlot;
        //std::swap(list_dataPlot, other.list_dataPlot);
        //std::swap(s1, other.s1);
        return *this;
    }

    void Workers();

private:
    //void run();


    unsigned const No_THREADS = 1;
    unsigned const No_THREADS_con = 4;
    unsigned const CO = 3;
    string mask = "quali???t";
    std::vector<std::thread> damagers, responders;
    std::mutex cerrMutex;
    string fname;
    //std::atomic<int> xxxx(0);
    //ThreadSafeQ<int> queue(6);
    //_SearchTextData queue_shd(size_t(5000));
    LIST_DataPlot list_dataplot;
    MAP_DataPlot map_dataplot;

    void FindSearch(
        QString tab,
        int idStart,
        int idEnd,
        Data_xyzt _data,
        MAP_DataPlot& safe_ResultSearch_data);
    void FindSearch(
        string mask,
        Data_xyzt _data,
        MAP_DataPlot& safe_ResultSearch_data);




};

#endif // DAMAGER_H
