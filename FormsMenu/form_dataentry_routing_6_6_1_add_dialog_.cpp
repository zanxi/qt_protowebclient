#include "form_dataentry_routing_6_6_1_add_dialog_.h"
#include "ui_form_dataentry_routing_6_6_1_add_dialog_.h"

#include "dataanimals.h"

form_dataentry_routing_6_6_1_add_Dialog_::form_dataentry_routing_6_6_1_add_Dialog_(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_dataentry_routing_6_6_1_add_Dialog_)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    setWindowTitle("Сухостойность");

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
    ui->pushButton_4->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    check_insert_or_update = false;




}

form_dataentry_routing_6_6_1_add_Dialog_::form_dataentry_routing_6_6_1_add_Dialog_(QString checkAnimals, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_dataentry_routing_6_6_1_add_Dialog_)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    setWindowTitle("Сухостойность");

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
    ui->pushButton_4->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    check_insert_or_update = true;
    SetData();

}


form_dataentry_routing_6_6_1_add_Dialog_::~form_dataentry_routing_6_6_1_add_Dialog_()
{
    delete ui;
}

void form_dataentry_routing_6_6_1_add_Dialog_::SetData()
{
    ui->label_number->setText(DataSystems::I().routing_animal_No);
    ui->label_current_lactation->setText(DataSystems::I().routing_lactation_number);
    ui->label_days_lactation->setText(DataSystems::I().routing_lactation_days);
    ui->label_last_lactation->setText(DataSystems::I().routing_lactation_number);
    ui->label_24_H_product->setText(DataSystems::I().routing_active_routing);
    ui->label_last_milk_separation->setText(DataSystems::I().routing_lactation_days);
    ui->label_expected_dry->setText(DataSystems::I().routing_Robot_number);

    ui->comboBox_area_routing->setCurrentText(DataSystems::I().routing_active_routing);
    //ui->dateEdit_from->setDate(DataSystems::I().routing_from_date);
    //ui->dateEdit_till->setDate(DataSystems::I().routing_till_date);
    ui->checkBox_activity->setCheckState(DataSystems::I().routing_active_routing=="+"?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked));

}

void form_dataentry_routing_6_6_1_add_Dialog_::on_pushButton_3_clicked()
{


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {

        QString tab = "dataentry_routing";
        QString parameterId = "animal_No";
        QString valueId = DataSystems::Instance().routing_animal_No;

        //db_func->update_add(tab, parameterId, valueId, "animal_No", DataSystems::Instance().routing_animal_No);
        db_func->update_add(tab, parameterId, valueId,  "Robot_No", DataSystems::Instance().routing_Robot_number);
        db_func->update_add(tab, parameterId, valueId, "lactation_No", DataSystems::Instance().routing_lactation_number);
        db_func->update_add(tab, parameterId, valueId, "lactation_days", DataSystems::Instance().routing_lactation_days);
        db_func->update_add(tab, parameterId, valueId, "area", DataSystems::Instance().routing_area);
        db_func->update_add(tab, parameterId, valueId, "from_date", DataSystems::Instance().routing_from_date);
        db_func->update_add(tab, parameterId, valueId, "till_date", DataSystems::Instance().routing_till_date);
        db_func->update_add(tab, parameterId, valueId, "from_till_time", DataSystems::Instance().routing_from_till_time);
        QString sql_update=db_func->update_add(tab, parameterId, valueId, "active_routing", DataSystems::Instance().routing_active_routing);


        /**/

        db_func->insert_add(tab, "animal_No", DataSystems::Instance().routing_animal_No);
        db_func->insert_add(tab, "Robot_No", DataSystems::Instance().routing_Robot_number);
        db_func->insert_add(tab, "lactation_No", DataSystems::Instance().routing_lactation_number);
        db_func->insert_add(tab, "lactation_days", DataSystems::Instance().routing_lactation_days);
        db_func->insert_add(tab, "area", DataSystems::Instance().routing_area);
        db_func->insert_add(tab, "from_date", DataSystems::Instance().routing_from_date);
        db_func->insert_add(tab, "till_date", DataSystems::Instance().routing_till_date);
        db_func->insert_add(tab, "from_till_time", DataSystems::Instance().routing_from_till_time);
        QString sql_insert=db_func->insert_add(tab, "active_routing", DataSystems::Instance().routing_active_routing);


        if(!check_insert_or_update)db_func->sql_exec(sql_insert, "add milk separation");
        else db_func->sql_exec(sql_update, "update milk separation");

    }

    status = true;


    QMessageBox::information(this,"Спасибо","Сохранеы данные");


    this->close();
}


void form_dataentry_routing_6_6_1_add_Dialog_::on_pushButton_4_clicked()
{
    status = false;
    this->close();
}

