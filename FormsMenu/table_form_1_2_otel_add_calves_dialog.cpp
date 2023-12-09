#include "table_form_1_2_otel_add_calves_dialog.h"
#include "ui_table_form_1_2_otel_add_calves_dialog.h"

#include "dataanimals.h"

table_form_1_2_otel_add_calves_Dialog::table_form_1_2_otel_add_calves_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_form_1_2_otel_add_calves_Dialog)
{
    ui->setupUi(this);

    setWindowTitle("Кол-во телят");


}

table_form_1_2_otel_add_calves_Dialog::~table_form_1_2_otel_add_calves_Dialog()
{
    delete ui;
}

void table_form_1_2_otel_add_calves_Dialog::on_pushButton_save_clicked()
{
    DataSystems::Instance().otel_number_of_calves = ui->lineEdit_number_calves->text();
    this->close();

}


void table_form_1_2_otel_add_calves_Dialog::on_pushButton_cancel_clicked()
{
    this->close();
}

