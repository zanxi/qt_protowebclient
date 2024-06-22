#ifndef FORM_DATAENTRY_DATAENTRY___MILK_SEPARATIONOFF_ADD_H
#define FORM_DATAENTRY_DATAENTRY___MILK_SEPARATIONOFF_ADD_H

#include <QDialog>

namespace Ui {
class form_dataentry_dataentry___milk_separationoff_add;
}

class form_dataentry_dataentry___milk_separationoff_add : public QDialog
{
    Q_OBJECT

public:
    explicit form_dataentry_dataentry___milk_separationoff_add(QWidget *parent = nullptr);
    explicit form_dataentry_dataentry___milk_separationoff_add(const QString &animals_number, QWidget *parent = nullptr);
    ~form_dataentry_dataentry___milk_separationoff_add();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::form_dataentry_dataentry___milk_separationoff_add *ui;
    void create();

    bool check_insert_or_update = false; // вставить - false; обновить - true
    void SetData();
    bool status = true;
};

#endif // FORM_DATAENTRY_DATAENTRY___MILK_SEPARATIONOFF_ADD_H
