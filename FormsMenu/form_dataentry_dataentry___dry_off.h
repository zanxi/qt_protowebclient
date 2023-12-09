#ifndef FORM_DATAENTRY_DATAENTRY___DRY_OFF_H
#define FORM_DATAENTRY_DATAENTRY___DRY_OFF_H

#include <QWidget>

// 1. Навигатор: Ввод данных   2. Меню: Дневная запись         3. Выбрать: «Сухостойность»

namespace Ui {
class form_dataentry_dataentry___dry_off;
}

class form_dataentry_dataentry___dry_off : public QWidget
{
    Q_OBJECT

public:
    explicit form_dataentry_dataentry___dry_off(QWidget *parent = nullptr);
    ~form_dataentry_dataentry___dry_off();

private slots:
    void on_comboBox_numbers_activated(int index);

    void on_pushButton_add_clicked();

    void on_pushButton_select_clicked();

private:
    Ui::form_dataentry_dataentry___dry_off *ui;
    void create();

    int selectRow=-1;
    int selectRowOld=-1;

    QString checkAnimals="";

    void GetData();
    void GetData(QString str);
    void addRandom();




};

#endif // FORM_DATAENTRY_DATAENTRY___DRY_OFF_H
