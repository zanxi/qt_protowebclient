#ifndef GENERATEDBDATA_H
#define GENERATEDBDATA_H


#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QTcpSocket>
#include <QXmlStreamReader>
#include <QThread>
#include <QMutex>
#define maxId 1300



class GenerateDBData:public QThread
{
    Q_OBJECT
public:
    //    NetPhotoMaster();
    GenerateDBData(QString nameSubsystem,int ip, QObject *parent = 0);
    GenerateDBData(QObject *parent = 0);
    //void makeStep();
    //QString readVariable(QString name);
    void run();
    //QDateTime getLastTime();
    //QString toString();
    bool status = true;

private:
    int lastId;
    QMap<int,QString> values;
    QMap<QString,int> vars;
    QString nameSubsystem;
    QString ipPhoto;
    QTimer *tmr;
    int ip;
    QMutex mutex;
    QDateTime lastOperation=QDateTime::currentDateTime();

    const double pi=355.0/113.0;
    double xi=0,yi=0,zi=0,wi=0, cow_i=0.0;


};




#endif // GENERATEDBDATA_H
