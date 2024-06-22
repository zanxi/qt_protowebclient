#ifndef FORM_DATAENTRY_ROUTING_6_6_1_H
#define FORM_DATAENTRY_ROUTING_6_6_1_H

#include <QWidget>

namespace Ui {
class Form_dataentry_routing_6_6_1;
}

class Form_dataentry_routing_6_6_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form_dataentry_routing_6_6_1(QWidget *parent = nullptr);
    ~Form_dataentry_routing_6_6_1();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_select_clicked();

    void on_comboBox_number_activated(int index);

private:
    Ui::Form_dataentry_routing_6_6_1 *ui;

    int selectRow=-1;
    int selectRowOld=-1;

    QString checkAnimals="", tab="dataentry_routing";


    void GetData();
    void GetData(const QString &str);
    void addRandom();

};

#endif // FORM_DATAENTRY_ROUTING_6_6_1_H
