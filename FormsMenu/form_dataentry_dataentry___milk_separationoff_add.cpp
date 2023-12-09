#include "form_dataentry_dataentry___milk_separationoff_add.h"
#include "ui_form_dataentry_dataentry___milk_separationoff_add.h"

#include "dataanimals.h"
#include "Debug/logger.h"


form_dataentry_dataentry___milk_separationoff_add::form_dataentry_dataentry___milk_separationoff_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_dataentry_dataentry___milk_separationoff_add)
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

    ui->dateEdit_start_separation->setDate(QDate().currentDate());
    ui->timeEdit_start_separation->setDate(QDate().currentDate());
    ui->dateEdit_end_separation->setDate(QDate().currentDate());
    ui->timeEdit_end_separation->setDate(QDate().currentDate());

    ui->dateEdit_start_separation->setEnabled(false);
    ui->timeEdit_start_separation->setEnabled(false);


    //ui->label_current_lactation->setText(DataSystems::Instance().dry_off_lactation_number);
    //ui->label_number->setText(DataSystems::Instance().dry_off_animal_No);
    //ui->label_days_suhostoinost->setText(DataSystems::Instance().dry_off_day_production);
    //ui->label_24_H_product->setText(DataSystems::Instance().dry_off_total_day);
    //ui->label_days_lactation->setText(DataSystems::Instance().otel_lactation_days);

    check_insert_or_update = false;

    create();

}

form_dataentry_dataentry___milk_separationoff_add::form_dataentry_dataentry___milk_separationoff_add(QString animals_number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_dataentry_dataentry___milk_separationoff_add)
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

    ui->dateEdit_start_separation->setDate(QDate().currentDate());
    ui->timeEdit_start_separation->setDate(QDate().currentDate());
    ui->dateEdit_end_separation->setDate(QDate().currentDate());
    ui->timeEdit_end_separation->setDate(QDate().currentDate());

    ui->dateEdit_start_separation->setEnabled(false);
    ui->timeEdit_start_separation->setEnabled(false);


    //ui->label_current_lactation->setText(DataSystems::Instance().dry_off_lactation_number);
    //ui->label_number->setText(DataSystems::Instance().dry_off_animal_No);
    //ui->label_days_suhostoinost->setText(DataSystems::Instance().dry_off_day_production);
    //ui->label_24_H_product->setText(DataSystems::Instance().dry_off_total_day);
    //ui->label_days_lactation->setText(DataSystems::Instance().otel_lactation_days);

    check_insert_or_update = true;
    SetData();

    create();

}

form_dataentry_dataentry___milk_separationoff_add::~form_dataentry_dataentry___milk_separationoff_add()
{
    delete ui;
}

void form_dataentry_dataentry___milk_separationoff_add::SetData()
{
    ui->label_number->setText(DataSystems::Instance().milk_separation_animal_No);
    //ui->label_number->setText(DataSystems::Instance().milk_separation_Robot_number);
    ui->label_current_lactation->setText(DataSystems::Instance().milk_separation_lactation_number);
    ui->label_days_lactation->setText(DataSystems::Instance().milk_separation_lactation_days);
    ui->label_last_milk_separation->setText(DataSystems::Instance().milk_separation_end_separation_y);
    ui->label_24_H_product->setText(DataSystems::Instance().milk_separation_lactation_number);

    ui->label_last_lactation->setText(DataSystems::Instance().milk_separation_lactation_number);
    ui->label_expected_dry->setText(DataSystems::Instance().milk_separation_expected_dry);
    ui->lineEdit_type_milk_separation->setText(DataSystems::Instance().milk_separation_milk_separation_type);
    ui->lineEdit_status_separation->setText(DataSystems::Instance().milk_separation_milk_separation_status);
}


void form_dataentry_dataentry___milk_separationoff_add::create()
{
    QStringList NameColumns;
    NameColumns<<"Дата сепарации"<<"Тип сепарации";

        ui->tableWidget->setColumnCount( 2 );
    ui->tableWidget->setRowCount( 10 );

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Сепарация молока"));
    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
    for(int i=0;i<2;i++)ui->tableWidget->setColumnWidth(i, 150);

    for(int i=0;i<3;i++)
    {
        if(DataSystems::Instance().dry_off_animal_No=="")
        {
            ui->tableWidget->setItem( i, 0,  new QTableWidgetItem(QDate().currentDate().toString()));
            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem("type separation - "+QString::number(rand()%10000)));
            ui->tableWidget->item(i,0)->setBackground( Qt::yellow);
            ui->tableWidget->item(i,1)->setBackground( Qt::yellow);

        }
        else
        {
            ui->tableWidget->setItem( i, 0,  new QTableWidgetItem(DataSystems::Instance().dry_off_lactation_number));
            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem(QDate().currentDate().toString()));

        }

    }

}

void form_dataentry_dataentry___milk_separationoff_add::on_pushButton_4_clicked()
{
    status = false; // без сохранения
    this->close();
}


void form_dataentry_dataentry___milk_separationoff_add::on_pushButton_3_clicked()
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

    //DataSystems::Instance().Insemenation_sire = ui->comboBox_->currentText();
    //DataSystems::Instance().Insemenation_person = ui->comboBox_persons->currentText();
    //DataSystems::Instance().Insemenation_group = ui->comboBox_group->currentText();
    //DataSystems::Instance().Insemenation_remarks = ui->textEdit_comment->placeholderText();


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {

        QString tab = "dataentry_milk_separation";
        QString parameterId = "animal_No";
        QString valueId = DataSystems::Instance().milk_separation_animal_No;

        //db_func->update_add(tab, parameterId, valueId, "animal_No",DataSystems::Instance().milk_separation_animal_No);
        db_func->update_add(tab, parameterId, valueId, "Robot_No",DataSystems::Instance().milk_separation_Robot_number);
        db_func->update_add(tab, parameterId, valueId, "lactation_No",DataSystems::Instance().milk_separation_lactation_number);
        db_func->update_add(tab, parameterId, valueId, "lactation_days",DataSystems::Instance().milk_separation_lactation_days);
        db_func->update_add(tab, parameterId, valueId, "milk_separation_type",DataSystems::Instance().milk_separation_milk_separation_type);
        db_func->update_add(tab, parameterId, valueId, "milk_separation_tank",DataSystems::Instance().milk_separation_milk_separation_tank);
        db_func->update_add(tab, parameterId, valueId, "end_date",DataSystems::Instance().milk_separation_end_date);
        db_func->update_add(tab, parameterId, valueId, "milk_separation_status",DataSystems::Instance().milk_separation_milk_separation_status);
        db_func->update_add(tab, parameterId, valueId, "start_separation_y",DataSystems::Instance().milk_separation_start_separation_y);
        db_func->update_add(tab, parameterId, valueId, "start_separation_h",DataSystems::Instance().milk_separation_start_separation_h);
        db_func->update_add(tab, parameterId, valueId, "end_separation_y",DataSystems::Instance().milk_separation_end_separation_y);
        db_func->update_add(tab, parameterId, valueId, "end_separation_h",DataSystems::Instance().milk_separation_start_separation_h);
        QString sql_update = db_func->update_add(tab, parameterId, valueId, "expected_dry",DataSystems::Instance().milk_separation_expected_dry);



        /**/

        db_func->insert_add(tab, "animal_No",DataSystems::Instance().milk_separation_animal_No);
        db_func->insert_add(tab, "Robot_No",DataSystems::Instance().milk_separation_Robot_number);
        db_func->insert_add(tab, "lactation_No",DataSystems::Instance().milk_separation_lactation_number);
        db_func->insert_add(tab, "lactation_days",DataSystems::Instance().milk_separation_lactation_days);
        db_func->insert_add(tab, "milk_separation_type",DataSystems::Instance().milk_separation_milk_separation_type);
        db_func->insert_add(tab, "milk_separation_tank",DataSystems::Instance().milk_separation_milk_separation_tank);
        db_func->insert_add(tab, "end_date",DataSystems::Instance().milk_separation_end_date);
        db_func->insert_add(tab, "milk_separation_status",DataSystems::Instance().milk_separation_milk_separation_status);
        db_func->insert_add(tab, "start_separation_y",DataSystems::Instance().milk_separation_start_separation_y);
        db_func->insert_add(tab, "start_separation_h",DataSystems::Instance().milk_separation_start_separation_h);
        db_func->insert_add(tab, "end_separation_y",DataSystems::Instance().milk_separation_end_separation_y);
        db_func->insert_add(tab, "end_separation_h",DataSystems::Instance().milk_separation_start_separation_h);
        QString sql_insert = db_func->insert_add(tab, "expected_dry",DataSystems::Instance().milk_separation_expected_dry);

        if(!check_insert_or_update)db_func->sql_exec(sql_insert, "add milk separation");
        else db_func->sql_exec(sql_update, "update milk separation");


    }

    status = true;


    QMessageBox::information(this,"Спасибо","Сохранеы данные");

    this->close();
}

