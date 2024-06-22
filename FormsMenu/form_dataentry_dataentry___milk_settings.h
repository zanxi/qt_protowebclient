#ifndef FORM_DATAENTRY_DATAENTRY___MILK_SETTINGS_H
#define FORM_DATAENTRY_DATAENTRY___MILK_SETTINGS_H

#include <QWidget>

namespace Ui {
class form_dataentry_dataentry___milk_settings;
}

class form_dataentry_dataentry___milk_settings : public QWidget
{
    Q_OBJECT

public:
    explicit form_dataentry_dataentry___milk_settings(QWidget *parent = nullptr);
    ~form_dataentry_dataentry___milk_settings();

private slots:
    void on_comboBox_numbers_activated(int index);

    void on_pushButton_add_clicked();

    void on_pushButton_select_clicked();

private:
    Ui::form_dataentry_dataentry___milk_settings *ui;
    void create();

    int selectRow=-1;
    int selectRowOld=-1;

    QString checkAnimals="";
    QString tab = "dataentry_milk_settings";

    void GetData();
    void GetData(const QString &str);
    void addRandom();
};

#endif // FORM_DATAENTRY_DATAENTRY___MILK_SETTINGS_H
