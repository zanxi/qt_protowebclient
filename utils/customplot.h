#ifndef CUSTOMPLOT_H
#define CUSTOMPLOT_H

#include <QDialog>

#include <QMainWindow>
#include <QTimer>
#include <QSqlQuery>
#include <QTableWidget>

#include "utils/qcustomplot.h"
#include "utils/axistag.h"

#include "./FormsMenu/generatedbdata.h"
#include "./FormsMenu/worker.h"


class CustomPlot
{
public:
    CustomPlot();

protected:
private:

    QCustomPlot *plot;
    int id=-1;

    QTimer *mTimer;
    const int milliSeconds=4*250;

    void createTableWidget();

    QVector<double> cow_graph1_x, cow_graph1_y, cow_graph2_x, cow_graph2_y, cow_graph3_x, cow_graph3_y;

    QVector<QCPGraphData> timeData;

    QVector<double> x0, y0;
    QVector<double> x1, y1, y1err;
    QVector<double> x2, y2;
    QVector<double> x3, y3;
    QVector<double> x4, y4;

    void addPoint(double x, double y, double z, double w);
    void addPoint(double x, double y, double z);
    void addPoint(double x, double y);
    void addPoint_x1_5(double x, double y, double z, double w);
    void clearData();
    void GetData();
    void tabwidget_insert_add_column(QSqlQuery *query, QTableWidget *tab, QString nameColumn, int numRow, int numColumn);
    void tabwidget_insert_add_column(QSqlQuery *query, QTableWidget *tab, QString nameColumnX, QString nameColumnY, int numRow, int numColumn);
    void GetData_search(QString str);
    void GetData_search(QString str, QString tab, QString str2);
    void GetData_FirstId(QString id, QString tab, QString str2);

    bool fromStringValue(const QString &inStr, QDateTime &value);


    void TimeOperation(QCustomPlot *customPlot);
    void TimeOperation();

    void setupAdvancedAxesDemo(QCustomPlot *customPlot);
    QPointer<QCPGraph> mGraph1;
    QPointer<QCPGraph> mGraph2;
    QPointer<QCPGraph> mGraph3;
    QPointer<QCPGraph> mGraph4;
    AxisTag *mTag1;
    AxisTag *mTag2;
    AxisTag *mTag3;

    const double pi=355.0/113.0;
    double xi=0,yi=0,zi=0,wi=0, t_, cow_i=0.0, min1=0.0,max1=0.0,min2=0.0,max2=0.0,min3=0.0,max3=0.0;

    //GenerateDBData *genbigdata;

    int threadCount=8;
    int thStart=0, thEnd=10000, step=8;
    //QList<QThread*> threads;
    //QList<Worker*>  jobs;




};

#endif // CUSTOMPLOT_H
