#include "form_dataentry_dataentry___dry_off__add.h"
#include "ui_form_dataentry_dataentry___dry_off__add.h"

#include "dataanimals.h"
#include "Debug/logger.h"

form_dataentry_dataentry___dry_off__add::form_dataentry_dataentry___dry_off__add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_dataentry_dataentry___dry_off__add)
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
    ui->groupBox_2->setStyleSheet("QGroupBox {"
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

    ui->dateEdit_dry_off->setDate(QDate().currentDate());
    ui->dateEdit_meat->setDate(QDate().currentDate());
    ui->dateEdit_milk->setDate(QDate().currentDate());

    ui->timeEdit_meat->setDate(QDate().currentDate());
    ui->timeEdit_milk->setDate(QDate().currentDate());


    ui->label_current_lactation->setText(DataSystems::Instance().dry_off_lactation_number);
    ui->label_number->setText(DataSystems::Instance().dry_off_animal_No);
    ui->label_days_suhostoinost->setText(DataSystems::Instance().dry_off_day_production);
    ui->label_24_H_product->setText(DataSystems::Instance().dry_off_total_day);
    //ui->label_days_lactation->setText(DataSystems::Instance().otel_lactation_days);

    check_insert_or_update = false;
    create();
}

form_dataentry_dataentry___dry_off__add::form_dataentry_dataentry___dry_off__add(QString checkAnimals, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_dataentry_dataentry___dry_off__add)
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
    ui->groupBox_2->setStyleSheet("QGroupBox {"
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

    ui->dateEdit_dry_off->setDate(QDate().currentDate());
    ui->dateEdit_meat->setDate(QDate().currentDate());
    ui->dateEdit_milk->setDate(QDate().currentDate());

    ui->timeEdit_meat->setDate(QDate().currentDate());
    ui->timeEdit_milk->setDate(QDate().currentDate());


    ui->label_current_lactation->setText(DataSystems::Instance().dry_off_lactation_number);
    ui->label_number->setText(DataSystems::Instance().dry_off_animal_No);
    ui->label_days_suhostoinost->setText(DataSystems::Instance().dry_off_day_production);
    ui->label_24_H_product->setText(DataSystems::Instance().dry_off_total_day);
    //ui->label_days_lactation->setText(DataSystems::Instance().otel_lactation_days);

    create();

    check_insert_or_update = true;
    SetData();
}

void form_dataentry_dataentry___dry_off__add::SetData()
{
}


void form_dataentry_dataentry___dry_off__add::create()
{
    QStringList NameColumns;
    NameColumns<<"Номер лактации"<<"Дата отела"<<"Дата сухостойности";

        ui->tableWidget->setColumnCount( 2 );
    ui->tableWidget->setRowCount( 1 );

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
    for(int i=0;i<2;i++)ui->tableWidget->setColumnWidth(i, 150);

    for(int i=0;i<1;i++)
    {
        if(DataSystems::Instance().dry_off_animal_No=="")
        {
            ui->tableWidget->setItem( i, 0,  new QTableWidgetItem("Новый"));
            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem(QDate().currentDate().toString()));
            ui->tableWidget->setItem( i, 2,  new QTableWidgetItem(QDate().currentDate().toString()));
            ui->tableWidget->item(i,0)->setBackground( Qt::yellow);
            ui->tableWidget->item(i,1)->setBackground( Qt::yellow);
            ui->tableWidget->item(i,2)->setBackground( Qt::yellow);
        }
        else
        {
            ui->tableWidget->setItem( i, 0,  new QTableWidgetItem(DataSystems::Instance().dry_off_lactation_number));
            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem(QDate().currentDate().toString()));
            ui->tableWidget->setItem( i, 2,  new QTableWidgetItem(QDate().currentDate().toString()));
        }

    }



}


form_dataentry_dataentry___dry_off__add::~form_dataentry_dataentry___dry_off__add()
{
    delete ui;
}

void form_dataentry_dataentry___dry_off__add::on_pushButton_3_clicked()
{
    //DataSystems::Instance().otel_number = ui->label_number->text();
    //DataSystems::Instance().otel_current_location = ui->label_current_lactation->text();
    //ui->label_days_suhostoinost->setText(DataSystems::Instance().otel_days_dry);
    //ui->label_time_wait_otel->setText(DataSystems::Instance().otel_waiting_time_colostrum);
    //ui->label_before_comments->setText(DataSystems::Instance().otel_remarks_previous);
    //ui->label_days_lactation->setText(DataSystems::Instance().otel_lactation_days);

    //ui->label_number->setText(DataSystems::Instance().Insemenation_animal_No);
    //ui->label_->setText(DataSystems::Instance().Insemenation_Robot_number);
    //ui->label_current_lactation->setText(DataSystems::Instance().Insemenation_lactation_number);
    //ui->label_days_lactation_2->setText(DataSystems::Instance().Insemenation_lactation_days);
    //ui->label_->setText(DataSystems::Instance().Insemenation_since_insemenation);
    //ui->label_previous_insemenation->setText(DataSystems::Instance().Insemenation_insemenation_number);
    //ui->label_status_reproduction->setText(DataSystems::Instance().Insemenation_day_production);
    //ui->label_->setText(DataSystems::Instance().Insemenation_Activity);
    //ui->label_previous_heat->setText(DataSystems::Instance().Insemenation_days_since_heat);
    //ui->label_wait_otel->setText(DataSystems::Instance().Insemenation_expected_otel);
    //ui->label_->setText(DataSystems::Instance().Insemenation_type);
    //ui->dateEdit_datr_insemenation->setText(DataSystems::Instance().Insemenation_date);
    //DataSystems::Instance().milk_separation_start_separation_y = ui->dateEdit_->currentText();

    DataSystems::Instance().dry_off_date = ui->dateEdit_dry_off->text();
    DataSystems::Instance().dry_off_medicine_used = ui->radioButton_medicine_No->text();
    //DataSystems::Instance().Insemenation_group = ui->comboBox_group->currentText();
    //DataSystems::Instance().Insemenation_remarks = ui->textEdit->placeholderText();


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {



        QString tab = "dataentry_dry_off";
        QString parameterId = "animal_No";
        QString valueId = DataSystems::Instance().dry_off_animal_No;

        //db_func->update_add(tab, parameterId, valueId, "animal_No", DataSystems::Instance().dry_off_animal_No);
        db_func->update_add(tab, parameterId, valueId, "Robot_No", DataSystems::Instance().dry_off_Robot_number);
        db_func->update_add(tab, parameterId, valueId, "lactation_No", DataSystems::Instance().dry_off_lactation_number);
        db_func->update_add(tab, parameterId, valueId, "lactation_days", DataSystems::Instance().dry_off_lactation_days);
        db_func->update_add(tab, parameterId, valueId, "days_pregnant", DataSystems::Instance().dry_off_days_pregnant);
        db_func->update_add(tab, parameterId, valueId, "day_production", DataSystems::Instance().dry_off_day_production);
        db_func->update_add(tab, parameterId, valueId, "total_day", DataSystems::Instance().dry_off_total_day);
        db_func->update_add(tab, parameterId, valueId, "udder_health_add text", DataSystems::Instance().dry_off_udder_health_add);
        db_func->update_add(tab, parameterId, valueId, "udder_health_add_count", DataSystems::Instance().dry_off_udder_health_add_count);
        db_func->update_add(tab, parameterId, valueId, "date", DataSystems::Instance().dry_off_date);
        db_func->update_add(tab, parameterId, valueId, "medicine_used", DataSystems::Instance().dry_off_medicine_used);
        db_func->update_add(tab, parameterId, valueId, "medicine_category", DataSystems::Instance().dry_off_medicine_category);
        db_func->update_add(tab, parameterId, valueId, "medicine", DataSystems::Instance().dry_off_medicine);
        db_func->update_add(tab, parameterId, valueId, "dosage", DataSystems::Instance().dry_off_dosage);
        db_func->update_add(tab, parameterId, valueId, "Teat_LF", DataSystems::Instance().dry_off_Teat_LF);
        db_func->update_add(tab, parameterId, valueId, "Teat_RF", DataSystems::Instance().dry_off_Teat_RF);
        db_func->update_add(tab, parameterId, valueId, "Teat_LR", DataSystems::Instance().dry_off_Teat_LR);
        db_func->update_add(tab, parameterId, valueId, "Teat_RR", DataSystems::Instance().dry_off_Teat_RR);
        db_func->update_add(tab, parameterId, valueId, "separate_meat_untill", DataSystems::Instance().dry_off_separate_meat_untill);
        db_func->update_add(tab, parameterId, valueId, "separate_milk_untill", DataSystems::Instance().dry_off_separate_milk_untill);
        QString sql_update=db_func->update_add(tab, parameterId, valueId, "group_", DataSystems::Instance().dry_off_group);

        /**/

        db_func->insert_add(tab, "animal_No", DataSystems::Instance().dry_off_animal_No);
        db_func->insert_add(tab, "Robot_No", DataSystems::Instance().dry_off_Robot_number);
        db_func->insert_add(tab, "lactation_No", DataSystems::Instance().dry_off_lactation_number);
        db_func->insert_add(tab, "lactation_days", DataSystems::Instance().dry_off_lactation_days);
        db_func->insert_add(tab, "days_pregnant", DataSystems::Instance().dry_off_days_pregnant);
        db_func->insert_add(tab, "day_production", DataSystems::Instance().dry_off_day_production);
        db_func->insert_add(tab, "total_day", DataSystems::Instance().dry_off_total_day);
        db_func->insert_add(tab, "udder_health_add text", DataSystems::Instance().dry_off_udder_health_add);
        db_func->insert_add(tab, "udder_health_add_count", DataSystems::Instance().dry_off_udder_health_add_count);
        db_func->insert_add(tab, "date", DataSystems::Instance().dry_off_date);
        db_func->insert_add(tab, "medicine_used", DataSystems::Instance().dry_off_medicine_used);
        db_func->insert_add(tab, "medicine_category", DataSystems::Instance().dry_off_medicine_category);
        db_func->insert_add(tab, "medicine", DataSystems::Instance().dry_off_medicine);
        db_func->insert_add(tab, "dosage", DataSystems::Instance().dry_off_dosage);
        db_func->insert_add(tab, "Teat_LF", DataSystems::Instance().dry_off_Teat_LF);
        db_func->insert_add(tab, "Teat_RF", DataSystems::Instance().dry_off_Teat_RF);
        db_func->insert_add(tab, "Teat_LR", DataSystems::Instance().dry_off_Teat_LR);
        db_func->insert_add(tab, "Teat_RR", DataSystems::Instance().dry_off_Teat_RR);
        db_func->insert_add(tab, "separate_meat_untill", DataSystems::Instance().dry_off_separate_meat_untill);
        db_func->insert_add(tab, "separate_milk_untill", DataSystems::Instance().dry_off_separate_milk_untill);
        QString sql_insert=db_func->insert_add(tab, "group_", DataSystems::Instance().dry_off_group);

        if(!check_insert_or_update)db_func->sql_exec(sql_insert, "add dry_off");
        else db_func->sql_exec(sql_update, "update dry_off");


    }

    status = true;

    QMessageBox::information(this,"Спасибо","Сохранеы данные по сухостойности");
    this->close();
}


void form_dataentry_dataentry___dry_off__add::on_pushButton_4_clicked()
{
    status = false;
    this->close();
}

