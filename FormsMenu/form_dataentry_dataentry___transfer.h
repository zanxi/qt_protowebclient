#ifndef FORM_DATAENTRY_DATAENTRY___TRANSFER_H
#define FORM_DATAENTRY_DATAENTRY___TRANSFER_H

#include <QWidget>

namespace Ui {
class form_dataentry_dataentry___transfer;
}

class form_dataentry_dataentry___transfer : public QWidget
{
    Q_OBJECT

public:
    explicit form_dataentry_dataentry___transfer(QWidget *parent = nullptr);
    ~form_dataentry_dataentry___transfer();

private slots:
    void on_pushButton_select_clicked();

    void on_pushButton_add_clicked();

    void on_comboBox_numbers_activated(int index);

private:
    Ui::form_dataentry_dataentry___transfer *ui;

    int selectRow=-1;
    int selectRowOld=-1;

    QString checkAnimals="";

    void GetData();
    void GetData(QString str);
    void addRandom();

};

#endif // FORM_DATAENTRY_DATAENTRY___TRANSFER_H
