#ifndef FORM_DATAENTRY_DATAENTRY___FIXED_FEEDING_H
#define FORM_DATAENTRY_DATAENTRY___FIXED_FEEDING_H

#include <QWidget>

namespace Ui {
class Form_dataentry_dataentry___fixed_feeding;
}

class Form_dataentry_dataentry___fixed_feeding : public QWidget
{
    Q_OBJECT

public:
    explicit Form_dataentry_dataentry___fixed_feeding(QWidget *parent = nullptr);
    ~Form_dataentry_dataentry___fixed_feeding();

public slots:
    void GetData();
    void create();

private:
    Ui::Form_dataentry_dataentry___fixed_feeding *ui;


    int selectRow=-1;
    int selectRowOld=-1;

    QString checkId="";
    QTimer *mTimer;


    //void GetData(QString str);
    void addRandom();

};

#endif // FORM_DATAENTRY_DATAENTRY___FIXED_FEEDING_H
