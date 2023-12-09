#ifndef FORM_DATAENTRY_DATAENTRY___MILK_SEPARATIONOFF_H
#define FORM_DATAENTRY_DATAENTRY___MILK_SEPARATIONOFF_H

#include <QWidget>

namespace Ui {
class form_dataentry_dataentry___milk_separationoff;
}

class form_dataentry_dataentry___milk_separationoff : public QWidget
{
    Q_OBJECT

public:
    explicit form_dataentry_dataentry___milk_separationoff(QWidget *parent = nullptr);
    ~form_dataentry_dataentry___milk_separationoff();

private slots:
    void on_comboBox_numbers_activated(int index);

    void on_pushButton_add_clicked();

    void on_pushButton_select_clicked();

private:
    Ui::form_dataentry_dataentry___milk_separationoff *ui;

    void create();

    int selectRow=-1;
    int selectRowOld=-1;
    QString checkAnimals="";

    void GetData();
    void GetData(QString str);
    void addRandom();

};

#endif // FORM_DATAENTRY_DATAENTRY___MILK_SEPARATIONOFF_H
