#ifndef TABLE_FORM_1_2_OTEL_ADD_H
#define TABLE_FORM_1_2_OTEL_ADD_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class table_form_1_2_otel_add;
}

class table_form_1_2_otel_add : public QDialog
{
    Q_OBJECT

public:
    explicit table_form_1_2_otel_add(QWidget *parent = nullptr);
    explicit table_form_1_2_otel_add(QString animals_number, QWidget *parent = nullptr);
    ~table_form_1_2_otel_add();

    bool checkStatus(){ return status; }  // сохранены true; не сохранены - false

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_add_telyat_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::table_form_1_2_otel_add *ui;
    void create();
    bool check_insert_or_update = false; // вставить - false; обновить - true

    void SetData();

    bool status = true;



};

#endif // TABLE_FORM_1_2_OTEL_ADD_H
