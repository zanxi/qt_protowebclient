#ifndef FORM_DATAENTRY_ROUTING_6_6_1_ADD_DIALOG__H
#define FORM_DATAENTRY_ROUTING_6_6_1_ADD_DIALOG__H

#include <QDialog>

namespace Ui {
class form_dataentry_routing_6_6_1_add_Dialog_;
}

class form_dataentry_routing_6_6_1_add_Dialog_ : public QDialog
{
    Q_OBJECT

public:
    explicit form_dataentry_routing_6_6_1_add_Dialog_(QWidget *parent = nullptr);
    explicit form_dataentry_routing_6_6_1_add_Dialog_(const QString &checkAnimals, QWidget *parent = nullptr);
    ~form_dataentry_routing_6_6_1_add_Dialog_();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::form_dataentry_routing_6_6_1_add_Dialog_ *ui;

    bool check_insert_or_update = false; // вставить - false; обновить - true
    void SetData();
    bool status = true;
};

#endif // FORM_DATAENTRY_ROUTING_6_6_1_ADD_DIALOG__H
