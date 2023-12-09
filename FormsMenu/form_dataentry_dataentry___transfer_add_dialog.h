#ifndef FORM_DATAENTRY_DATAENTRY___TRANSFER_ADD_DIALOG_H
#define FORM_DATAENTRY_DATAENTRY___TRANSFER_ADD_DIALOG_H

#include <QDialog>

namespace Ui {
class form_dataentry_dataentry___transfer_add_Dialog;
}

class form_dataentry_dataentry___transfer_add_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit form_dataentry_dataentry___transfer_add_Dialog(QWidget *parent = nullptr);
    explicit form_dataentry_dataentry___transfer_add_Dialog(QString checkAnimals, QWidget *parent = nullptr);
    ~form_dataentry_dataentry___transfer_add_Dialog();

private slots:
    void on_pushButton_save_clicked();

private:
    Ui::form_dataentry_dataentry___transfer_add_Dialog *ui;

    bool check_insert_or_update = false; // вставить - false; обновить - true
    void SetData();
    bool status = true;

};

#endif // FORM_DATAENTRY_DATAENTRY___TRANSFER_ADD_DIALOG_H
