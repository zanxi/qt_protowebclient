#ifndef FORM_ANALYSE_REPORTS___REPORTS_H
#define FORM_ANALYSE_REPORTS___REPORTS_H

#include <QWidget>

//#include "utils/customplot.h"

namespace Ui {
class Form_analyse_reports___reports;
}

class Form_analyse_reports___reports : public QWidget//, public CustomPlot
{
    Q_OBJECT

public:
    explicit Form_analyse_reports___reports(QWidget *parent = nullptr);
    ~Form_analyse_reports___reports();

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void plotRandom_();

private:
    int id=-1;
    int idmax = 0;
    QTimer *mTimer;
    const int milliSeconds=250;

    QVector<double> cow_graph1_x, cow_graph1_y, cow_graph2_x, cow_graph2_y, cow_graph3_x, cow_graph3_y, cow_graph4_y;

    QVector<double> x0, y0;
    QVector<double> x1, y1, y1err;
    QVector<double> x2, y2;
    QVector<double> x3, y3;
    QVector<double> x4, y4;

    const double pi=355.0/113.0;
    double xi=0,yi=0,zi=0,wi=0,ri=0, t_, cow_i=0.0, min1=0.0,max1=0.0,min2=0.0,max2=0.0,min3=0.0,max3=0.0;

    //GenerateDBData *genbigdata;

    int threadCount=8;
    int thStart=0, thEnd=10000, step=8;

    void addPoint(double x, double y, double z, double w, double r);
    void addPoint(double x, double y, double z, double w);
    void addPoint(double x, double y, double z);
    void addPoint(double x, double y);
    void addPoint_x1_5(double x, double y, double z, double w);
    void clearData();
    void setupAdvancedAxesDemo();
    void  GetData_search(QString tab, QString str2);


private:
    Ui::Form_analyse_reports___reports *ui;
};

#endif // FORM_ANALYSE_REPORTS___REPORTS_H
