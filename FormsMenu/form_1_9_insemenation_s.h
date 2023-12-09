#ifndef FORM_1_9_INSEMENATION_S_H
#define FORM_1_9_INSEMENATION_S_H

#include <QWidget>

namespace Ui {
class form_1_9_insemenation_s;
}

class form_1_9_insemenation_s : public QWidget
{
    Q_OBJECT

public:
    explicit form_1_9_insemenation_s(QWidget *parent = nullptr);    
    ~form_1_9_insemenation_s();

private slots:
    void on_comboBox_numbers_activated(int index);

    void on_pushButton_add_clicked();

    void on_pushButton_select_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::form_1_9_insemenation_s *ui;
    void create();


    int selectRow=-1;
    int selectRowOld=-1;
    QString checkAnimals="";

    void GetData();
    void GetData(QString str);
    void addRandom();


};

#endif // FORM_1_9_INSEMENATION_S_H
