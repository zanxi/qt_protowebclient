#include "formlibrary_1_9_tab_series_dialog.h"
#include "ui_formlibrary_1_9_tab_series_dialog.h"

#include "dataanimals.h"

formlibrary_1_9_tab_series_Dialog::formlibrary_1_9_tab_series_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formlibrary_1_9_tab_series_Dialog)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
}

formlibrary_1_9_tab_series_Dialog::~formlibrary_1_9_tab_series_Dialog()
{
    delete ui;
}

void formlibrary_1_9_tab_series_Dialog::on_pushButton_input_clicked()
{
    //DataSystems::Instance().dataentry_library_active = (ui->radioButton_yes->;
    DataSystems::Instance().dataentry_library_siries_life_number = (ui->lineEdit_life_number->text());
    DataSystems::Instance().dataentry_library_siries_number = (ui->lineEdit_sire_number->text());
    DataSystems::Instance().dataentry_library_siries_sire_name = (ui->lineEdit_sire_name->text());

    QMessageBox::information(this,"Спасибо","Сохранеы данные");
    this->close();

    //DataSystems::Instance().dataentry_library_sire_code = (ui->lineEdit_sire_number->text());

}

