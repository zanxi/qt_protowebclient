#ifndef DIALOG_FORM_DATAENTRY_DATAENTRY___MILK_SETTINGS_ADD_H
#define DIALOG_FORM_DATAENTRY_DATAENTRY___MILK_SETTINGS_ADD_H

#include <QDialog>

namespace Ui {
class Dialog_form_dataentry_dataentry___milk_settings_add;
}

class Dialog_form_dataentry_dataentry___milk_settings_add : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_form_dataentry_dataentry___milk_settings_add(QWidget *parent = nullptr);
    explicit Dialog_form_dataentry_dataentry___milk_settings_add(const QString &checkAnimals, QWidget *parent = nullptr);
    ~Dialog_form_dataentry_dataentry___milk_settings_add();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::Dialog_form_dataentry_dataentry___milk_settings_add *ui;

    bool check_insert_or_update = false; // вставить - false; обновить - true
    void SetData();
    bool status = true;
};

#endif // DIALOG_FORM_DATAENTRY_DATAENTRY___MILK_SETTINGS_ADD_H
