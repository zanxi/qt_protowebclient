#ifndef FORM_DATAENTRY_SETTINGS_H
#define FORM_DATAENTRY_SETTINGS_H

#include <QWidget>

namespace Ui {
class Form_DataEntry_Settings;
}

//1. Навигатор: Ввод данных 2. Меню: Настройки

class Form_DataEntry_Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Form_DataEntry_Settings(QWidget *parent = nullptr);
    ~Form_DataEntry_Settings();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form_DataEntry_Settings *ui;
    void create_feeding___feed_tables();
    void create_feeding___access_milk();


    void addRandom__milking__general_milking();
    void GetData__milking__general_milking();

    void addRandom__milking__post_milking();
    void GetData__milking__post_milking();


};

#endif // FORM_DATAENTRY_SETTINGS_H
