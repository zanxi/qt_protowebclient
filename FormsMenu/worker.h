#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include "rwlock/shd.h"
#include "damager.h"

class Worker :  QThread //QObject,
{
    //Q_OBJECT
public:
    Worker();
    Worker(int start, int end, int t);
    Worker(QString name, LIST_DataPlot list_dataPlot_, Damager dam);

    QString name;
    Damager dam;

    void run();
    bool status = true;

private:
    int start, end, threadN;
    MAP_DataPlot map_dataPlot;
    LIST_DataPlot list_dataPlot;

    //bool isWork(int i);
};

#endif // WORKER_H
