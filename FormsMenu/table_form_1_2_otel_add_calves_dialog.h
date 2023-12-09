#ifndef TABLE_FORM_1_2_OTEL_ADD_CALVES_DIALOG_H
#define TABLE_FORM_1_2_OTEL_ADD_CALVES_DIALOG_H

#include <QDialog>

namespace Ui {
class table_form_1_2_otel_add_calves_Dialog;
}

class table_form_1_2_otel_add_calves_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit table_form_1_2_otel_add_calves_Dialog(QWidget *parent = nullptr);
    ~table_form_1_2_otel_add_calves_Dialog();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::table_form_1_2_otel_add_calves_Dialog *ui;
};

#endif // TABLE_FORM_1_2_OTEL_ADD_CALVES_DIALOG_H
