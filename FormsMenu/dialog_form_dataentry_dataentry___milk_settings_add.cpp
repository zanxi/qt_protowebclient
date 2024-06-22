#include "dialog_form_dataentry_dataentry___milk_settings_add.h"
#include "ui_dialog_form_dataentry_dataentry___milk_settings_add.h"

#include "dataanimals.h"

Dialog_form_dataentry_dataentry___milk_settings_add::Dialog_form_dataentry_dataentry___milk_settings_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_form_dataentry_dataentry___milk_settings_add)
{
    ui->setupUi(this);

    setWindowTitle("Настройки локтации");

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                    "padding: 4 20000 4 10;"
                                                                                    "}");

    ui->groupBox_3->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                      "padding: 4 20000 4 10;"
                                                                                      "}");



    ui->pushButton->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );
    ui->pushButton_2->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );
    ui->pushButton_3->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );
    ui->pushButton_3->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );

    check_insert_or_update = false;

}


Dialog_form_dataentry_dataentry___milk_settings_add::Dialog_form_dataentry_dataentry___milk_settings_add(const QString &checkAnimals, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_form_dataentry_dataentry___milk_settings_add)
{
    ui->setupUi(this);

    setWindowTitle("Настройки локтации");

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                    "padding: 4 20000 4 10;"
                                                                                    "}");

    ui->groupBox_3->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                      "padding: 4 20000 4 10;"
                                                                                      "}");




    ui->pushButton->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_2->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_3->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_3->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    check_insert_or_update = true;

    SetData();

}

void Dialog_form_dataentry_dataentry___milk_settings_add::SetData()
{
    ui->label_number->setText(DataSystems::Instance().milk_settings_animal_No);
    ui->label_current_lactation->setText(DataSystems::Instance().milk_settings_lactation_number);
    ui->label_days_suhostoinost->setText(DataSystems::Instance().milk_settings_lactation_days);
    ui->label_last_lactation->setText(DataSystems::Instance().milk_settings_lactation_number);
    ui->label_24_H_product->setText(DataSystems::Instance().milk_settings_training_period);
    ui->label_expected_calving->setText(DataSystems::Instance().milk_separation_lactation_number);
    ui->label_24_H_product->setText(DataSystems::Instance().milk_settings_training_period);

}


Dialog_form_dataentry_dataentry___milk_settings_add::~Dialog_form_dataentry_dataentry___milk_settings_add()
{
    delete ui;
}

void Dialog_form_dataentry_dataentry___milk_settings_add::on_pushButton_4_clicked()
{

}


void Dialog_form_dataentry_dataentry___milk_settings_add::on_pushButton_close_clicked()
{
    status = false;
    this->close();
}


void Dialog_form_dataentry_dataentry___milk_settings_add::on_pushButton_save_clicked()
{

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {

        QString tab = "dataentry_milk_settings";
        QString parameterId = "animal_No";
        QString valueId = DataSystems::Instance().milk_settings_animal_No;

        //db_func->update_add(tab, parameterId, valueId, "animal_No", DataSystems::Instance().milk_settings_animal_No);
        db_func->update_add(tab, parameterId, valueId, "Robot_No", DataSystems::Instance().milk_settings_Robot_number);
        db_func->update_add(tab, parameterId, valueId, "lactation_No", DataSystems::Instance().milk_settings_lactation_number);
        db_func->update_add(tab, parameterId, valueId, "lactation_days", DataSystems::Instance().milk_settings_lactation_days);
        db_func->update_add(tab, parameterId, valueId, "priority_feeding", DataSystems::Instance().milk_settings_priority_feeding);
        db_func->update_add(tab, parameterId, valueId, "milk_teat_lf", DataSystems::Instance().milk_settings_milk_teat_lf);
        db_func->update_add(tab, parameterId, valueId, "milk_teat_lr", DataSystems::Instance().milk_settings_milk_teat_lr);
        db_func->update_add(tab, parameterId, valueId, "milk_teat_rf", DataSystems::Instance().milk_settings_milk_teat_rf);
        db_func->update_add(tab, parameterId, valueId, "milk_teat_rr", DataSystems::Instance().milk_settings_milk_teat_rr);
        db_func->update_add(tab, parameterId, valueId, "milk_under_supervision", DataSystems::Instance().milk_settings_milk_under_supervision);
        QString sql_update=db_func->update_add(tab, parameterId, valueId, "training_period", DataSystems::Instance().milk_settings_training_period);

        db_func->insert_add(tab, "animal_No", DataSystems::Instance().milk_settings_animal_No);
        db_func->insert_add(tab, "Robot_No", DataSystems::Instance().milk_settings_Robot_number);
        db_func->insert_add(tab, "lactation_No", DataSystems::Instance().milk_settings_lactation_number);
        db_func->insert_add(tab, "lactation_days", DataSystems::Instance().milk_settings_lactation_days);
        db_func->insert_add(tab, "priority_feeding", DataSystems::Instance().milk_settings_priority_feeding);
        db_func->insert_add(tab, "milk_teat_lf", DataSystems::Instance().milk_settings_milk_teat_lf);
        db_func->insert_add(tab, "milk_teat_lr", DataSystems::Instance().milk_settings_milk_teat_lr);
        db_func->insert_add(tab, "milk_teat_rf", DataSystems::Instance().milk_settings_milk_teat_rf);
        db_func->insert_add(tab, "milk_teat_rr", DataSystems::Instance().milk_settings_milk_teat_rr);
        db_func->insert_add(tab, "milk_under_supervision", DataSystems::Instance().milk_settings_milk_under_supervision);
        QString sql_insert=db_func->insert_add(tab, "training_period", DataSystems::Instance().milk_settings_training_period);

        if(!check_insert_or_update)db_func->sql_exec(sql_insert, "add milk separation");
        else db_func->sql_exec(sql_update, "update milk separation");
    }

    status = true;
    QMessageBox::information(this,"Спасибо","Сохранеы данные");
    this->close();

}

