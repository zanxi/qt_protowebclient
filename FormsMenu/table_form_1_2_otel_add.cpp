#include "table_form_1_2_otel_add.h"
#include "ui_table_form_1_2_otel_add.h"

#include "dataanimals.h"

#include "Debug/logger.h"
#include "FormsMenu/table_form_1_2_otel_add_calves_dialog.h"

table_form_1_2_otel_add::table_form_1_2_otel_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_form_1_2_otel_add)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    setWindowTitle("Добавить отел");

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

    ui->groupBox_4->setStyleSheet("QGroupBox {"
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
    ui->pushButton_close->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );

    ui->dateEdit_wait_otel->setDate(QDate().currentDate());
    ui->dateTimeEdit_wait_molosive->setDate(QDate().currentDate());
    ui->dateTimeEdit_wait_molosive->setTime(QTime().currentTime());

    ui->label_current_lactation->setText(DataSystems::Instance().otel_lactation_No);
    ui->label_number->setText(DataSystems::Instance().otel_animal_No);
    ui->label_days_suhostoinost->setText(DataSystems::Instance().otel_days_pregnant);
    ui->label_days_lactation->setText(DataSystems::Instance().otel_lactation_days);

    create();

    check_insert_or_update = false; // вставить - false; обновить - true
}


table_form_1_2_otel_add::table_form_1_2_otel_add(const QString &animals_number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_form_1_2_otel_add)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    setWindowTitle("Добавить отел");

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

    ui->groupBox_4->setStyleSheet("QGroupBox {"
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
    ui->pushButton_close->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    ui->dateEdit_wait_otel->setDate(QDate().currentDate());
    ui->dateTimeEdit_wait_molosive->setDate(QDate().currentDate());
    ui->dateTimeEdit_wait_molosive->setTime(QTime().currentTime());

    ui->label_current_lactation->setText(DataSystems::Instance().otel_lactation_No);
    ui->label_number->setText(DataSystems::Instance().otel_animal_No);
    ui->label_days_suhostoinost->setText(DataSystems::Instance().otel_days_pregnant);
    ui->label_days_lactation->setText(DataSystems::Instance().otel_lactation_days);

    SetData();
     check_insert_or_update = true; // вставить - false; обновить - true

}


table_form_1_2_otel_add::~table_form_1_2_otel_add()
{
    delete ui;
}

void table_form_1_2_otel_add::create()
{
    QStringList NameColumns;
    NameColumns<<"Номер лактации"<<"Дата отела";

    ui->tableWidget->setColumnCount( 2 );
    ui->tableWidget->setRowCount( 1 );

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
    for(int i=0;i<2;i++)ui->tableWidget->setColumnWidth(i, 150);

    for(int i=0;i<1;i++)
    {
        if(DataSystems::Instance().otel_animal_No=="")
        {
            ui->tableWidget->setItem( i, 0,  new QTableWidgetItem("Новый"));
            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem(QDate().currentDate().toString()));
            ui->tableWidget->item(i,0)->setBackground( Qt::yellow);
            ui->tableWidget->item(i,1)->setBackground( Qt::yellow);
        }
        else
        {
            ui->tableWidget->setItem( i, 0,  new QTableWidgetItem(DataSystems::Instance().otel_number));
            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem(QDate().currentDate().toString()));
        }

    }
}

void table_form_1_2_otel_add::SetData()
{
    //ui->label_number->setText(DataSystems::Instance().otel_number);
    ui->label_number->setText(DataSystems::Instance().otel_animal_No);
    ui->label_current_lactation->setText(DataSystems::Instance().otel_current_location);
    ui->label_days_suhostoinost->setText(DataSystems::Instance().otel_days_dry);
    ui->label_time_wait_otel->setText(DataSystems::Instance().otel_waiting_time_colostrum);
    ui->label_before_comments->setText(DataSystems::Instance().otel_remarks_previous);
    ui->label_days_lactation->setText(DataSystems::Instance().otel_lactation_days);
    ui->checkBox_lt->setCheckState(DataSystems::Instance().otel_teat[0]=='+'?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked));
    ui->checkBox_lb->setCheckState(DataSystems::Instance().otel_teat[2]=='+'?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked));
    ui->checkBox_rt->setCheckState(DataSystems::Instance().otel_teat[3]=='+'?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked));
    ui->checkBox_rb->setCheckState(DataSystems::Instance().otel_teat[4]=='+'?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked));

    ui->dateEdit_wait_otel->setDate(QDate().currentDate());
    ui->dateTimeEdit_wait_molosive->setDate(QDate().currentDate());
    ui->dateTimeEdit_wait_molosive->setTime(QTime().currentTime());

    ui->lineEdit_number_cow->setText(DataSystems::Instance().otel_cow_number);
    ui->lineEdit_respondent->setText(DataSystems::Instance().otel_responder);
    ui->label_telyat_counter->setText(DataSystems::Instance().otel_number_of_calves);

    ui->checkBox_depth->setCheckState(DataSystems::Instance().otel_calf_born_dead[0]=='+'?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked));

    ui->radioButton_Y->setChecked(DataSystems::Instance().otel_calf_keep_calf[0]=='+'?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked));
    ui->radioButton_N->setChecked(!(DataSystems::Instance().otel_calf_keep_calf[0]=='+')?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked));

    ui->radioButton_m->setChecked(DataSystems::Instance().otel_calf_sex[0]=='+'?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked));
    ui->radioButton_w->setChecked(!(DataSystems::Instance().otel_calf_sex   [0]=='+')?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked));

    ui->lineEdit_number_cow->setText(DataSystems::Instance().otel_calf_calf_number);
    ui->lineEdit_personal_number->setText(DataSystems::Instance().otel_calf_life_number);
    ui->lineEdit_name->setText(DataSystems::Instance().otel_calf_name);
    ui->comboBox_color->setCurrentText(DataSystems::Instance().otel_calf_hair_color);
    ui->comboBox_group->setCurrentText(DataSystems::Instance().otel_calf_group);
    ui->lineEdit_weight->setText(DataSystems::Instance().otel_calf_weight);



}

void table_form_1_2_otel_add::on_pushButton_4_clicked()
{
    this->close();
}


void table_form_1_2_otel_add::on_pushButton_3_clicked()
{
    logger::WriteMsg("on_pushButton_3_clicked : check change otel: "+check_insert_or_update);

    //DataSystems::Instance().otel_number = ui->label_number->text();
    //DataSystems::Instance().otel_current_location = ui->label_current_lactation->text();
    //ui->label_days_suhostoinost->setText(DataSystems::Instance().otel_days_dry);
    //ui->label_time_wait_otel->setText(DataSystems::Instance().otel_waiting_time_colostrum);
    //ui->label_before_comments->setText(DataSystems::Instance().otel_remarks_previous);
    //ui->label_days_lactation->setText(DataSystems::Instance().otel_lactation_days);
    DataSystems::Instance().otel_teat[0] = (ui->checkBox_lt->checkState()==Qt::CheckState::Checked)?('+'):('-');
    DataSystems::Instance().otel_teat[1] = (ui->checkBox_lb->checkState()==Qt::CheckState::Checked)?('+'):('-');
    DataSystems::Instance().otel_teat[2] = (ui->checkBox_rt->checkState()==Qt::CheckState::Checked)?('+'):('-');
    DataSystems::Instance().otel_teat[3] = (ui->checkBox_rb->checkState()==Qt::CheckState::Checked)?('+'):('-');

    DataSystems::Instance().otel_waiting_time_colostrum =  ui->dateEdit_wait_otel->dateTime().toString();
    DataSystems::Instance().otel_waiting_time_colostrum =  ui->dateTimeEdit_wait_molosive->dateTime().toString();
    DataSystems::Instance().otel_waiting_time_dry_off = ui->dateTimeEdit_wait_molosive->dateTime().toString();

    DataSystems::Instance().otel_cow_number = ui->lineEdit_number_cow->text();
    DataSystems::Instance().otel_responder = ui->lineEdit_respondent->text();
    //ui->label_telyat_counter->setText(DataSystems::Instance().otel_number_of_calves);

    DataSystems::Instance().otel_calf_born_dead[0] =  (ui->checkBox_depth->checkState()==Qt::CheckState::Checked)?('+'):('-');

    DataSystems::Instance().otel_calf_keep_calf[0] = ui->radioButton_Y->isChecked()?('+'):('-');

    DataSystems::Instance().otel_calf_sex[0] = ui->radioButton_m->isChecked()?('+'):('-');

    DataSystems::Instance().otel_calf_calf_number = ui->lineEdit_number_cow->text();
    DataSystems::Instance().otel_calf_life_number = ui->lineEdit_personal_number->text();
    DataSystems::Instance().otel_calf_name = ui->lineEdit_name->text();
    DataSystems::Instance().otel_calf_hair_color = ui->comboBox_color->currentText();
    DataSystems::Instance().otel_calf_group = ui->comboBox_group->currentText();
    DataSystems::Instance().otel_calf_weight = ui->lineEdit_weight->text();



    QScopedPointer<DataBase> db_func(new DataBase());    
    if(db_func->StatusOpen())
    {
        QString tab = "dataentry_otel";
        QString parameterId = "animal_No";
        QString valueId = DataSystems::Instance().otel_animal_No;

        //db_func->update_add(tab, parameterId, valueId, "animal_No",DataSystems::Instance().otel_animal_No);
        db_func->update_add(tab, parameterId, valueId, "number",DataSystems::Instance().otel_number);
        db_func->update_add(tab, parameterId, valueId, "Robot_No",DataSystems::Instance().otel_Robot_No);
        db_func->update_add(tab, parameterId, valueId, "lactation_No",DataSystems::Instance().otel_lactation_No);
        db_func->update_add(tab, parameterId, valueId, "lactation_days",DataSystems::Instance().otel_lactation_days);
        db_func->update_add(tab, parameterId, valueId, "days_pregnant",DataSystems::Instance().otel_days_pregnant);
        db_func->update_add(tab, parameterId, valueId, "lactation_production",DataSystems::Instance().otel_lactation_production);
        db_func->update_add(tab, parameterId, valueId, "average_lactation",DataSystems::Instance().otel_average_lactation);
        db_func->update_add(tab, parameterId, valueId, "average_refusals",DataSystems::Instance().otel_average_refusals);
        db_func->update_add(tab, parameterId, valueId, "average_falures",DataSystems::Instance().otel_average_falures);
        db_func->update_add(tab, parameterId, valueId, "average_milk_speed",DataSystems::Instance().otel_average_milk_speed);
        //db_func->update_add(tab, parameterId, valueId, // расширенные
        db_func->update_add(tab, parameterId, valueId, "current_location",DataSystems::Instance().otel_current_location); // 1 calving
        db_func->update_add(tab, parameterId, valueId, "days_dry",DataSystems::Instance().otel_days_dry);
        db_func->update_add(tab, parameterId, valueId, "waiting_time_dry_off",DataSystems::Instance().otel_waiting_time_dry_off);
        db_func->update_add(tab, parameterId, valueId, "remarks_previous",DataSystems::Instance().otel_remarks_previous);
        db_func->update_add(tab, parameterId, valueId, "expected_calving",DataSystems::Instance().otel_expected_calving);
        db_func->update_add(tab, parameterId, valueId, "calving_date",DataSystems::Instance().otel_calving_date);
        db_func->update_add(tab, parameterId, valueId, "waiting_time_colostrum",DataSystems::Instance().otel_waiting_time_colostrum);
        db_func->update_add(tab, parameterId, valueId, "number_of_calves",DataSystems::Instance().otel_number_of_calves);
        db_func->update_add(tab, parameterId, valueId, "remarks",DataSystems::Instance().otel_remarks);
        db_func->update_add(tab, parameterId, valueId, "group_",DataSystems::Instance().otel_group);
        db_func->update_add(tab, parameterId, valueId, "cow_number",DataSystems::Instance().otel_number);
        db_func->update_add(tab, parameterId, valueId, "responder",DataSystems::Instance().otel_responder);
        db_func->update_add(tab, parameterId, valueId, "teat",DataSystems::Instance().otel_teat);
        db_func->update_add(tab, parameterId, valueId, "separation_milk_tank",DataSystems::Instance().otel_separation_milk_tank);
        db_func->update_add(tab, parameterId, valueId, "calf_born_dead",DataSystems::Instance().otel_calf_born_dead); // 2 calf 1
        db_func->update_add(tab, parameterId, valueId, "calf_keep_calf",DataSystems::Instance().otel_calf_keep_calf);
        db_func->update_add(tab, parameterId, valueId, "calf_calf_number",DataSystems::Instance().otel_calf_calf_number);
        db_func->update_add(tab, parameterId, valueId, "calf_life_number",DataSystems::Instance().otel_calf_life_number);
        db_func->update_add(tab, parameterId, valueId, "calf_name",DataSystems::Instance().otel_calf_name);
        db_func->update_add(tab, parameterId, valueId, "calf_weight",DataSystems::Instance().otel_calf_weight);
        db_func->update_add(tab, parameterId, valueId, "calf_sex",DataSystems::Instance().otel_calf_sex);
        db_func->update_add(tab, parameterId, valueId, "calf_hair_color",DataSystems::Instance().otel_calf_hair_color);
        QString sql_update = db_func->update_add(tab, parameterId, valueId, "calf_group",DataSystems::Instance().otel_calf_group);

        db_func->insert_add(tab, "animal_No",DataSystems::Instance().otel_animal_No);
        db_func->insert_add(tab, "number",DataSystems::Instance().otel_number);
        db_func->insert_add(tab, "Robot_No",DataSystems::Instance().otel_Robot_No);
        db_func->insert_add(tab, "lactation_No",DataSystems::Instance().otel_lactation_No);
        db_func->insert_add(tab, "lactation_days",DataSystems::Instance().otel_lactation_days);
        db_func->insert_add(tab, "days_pregnant",DataSystems::Instance().otel_days_pregnant);
        db_func->insert_add(tab, "lactation_production",DataSystems::Instance().otel_lactation_production);
        db_func->insert_add(tab, "average_lactation",DataSystems::Instance().otel_average_lactation);
        db_func->insert_add(tab, "average_refusals",DataSystems::Instance().otel_average_refusals);
        db_func->insert_add(tab, "average_falures",DataSystems::Instance().otel_average_falures);
        db_func->insert_add(tab, "average_milk_speed",DataSystems::Instance().otel_average_milk_speed);
        //db_func->insert_add(tab, // расширенные
        db_func->insert_add(tab, "current_location",DataSystems::Instance().otel_current_location); // 1 calving
        db_func->insert_add(tab, "days_dry",DataSystems::Instance().otel_days_dry);
        db_func->insert_add(tab, "waiting_time_dry_off",DataSystems::Instance().otel_waiting_time_dry_off);
        db_func->insert_add(tab, "remarks_previous",DataSystems::Instance().otel_remarks_previous);
        db_func->insert_add(tab, "expected_calving",DataSystems::Instance().otel_expected_calving);
        db_func->insert_add(tab, "calving_date",DataSystems::Instance().otel_calving_date);
        db_func->insert_add(tab, "waiting_time_colostrum",DataSystems::Instance().otel_waiting_time_colostrum);
        db_func->insert_add(tab, "number_of_calves",DataSystems::Instance().otel_number_of_calves);
        db_func->insert_add(tab, "remarks",DataSystems::Instance().otel_remarks);
        db_func->insert_add(tab, "group_",DataSystems::Instance().otel_group);
        db_func->insert_add(tab, "cow_number",DataSystems::Instance().otel_number);
        db_func->insert_add(tab, "responder",DataSystems::Instance().otel_responder);
        db_func->insert_add(tab, "teat",DataSystems::Instance().otel_teat);
        db_func->insert_add(tab, "separation_milk_tank",DataSystems::Instance().otel_separation_milk_tank);
        db_func->insert_add(tab, "calf_born_dead",DataSystems::Instance().otel_calf_born_dead); // 2 calf 1
        db_func->insert_add(tab, "calf_keep_calf",DataSystems::Instance().otel_calf_keep_calf);
        db_func->insert_add(tab, "calf_calf_number",DataSystems::Instance().otel_calf_calf_number);
        db_func->insert_add(tab, "calf_life_number",DataSystems::Instance().otel_calf_life_number);
        db_func->insert_add(tab, "calf_name",DataSystems::Instance().otel_calf_name);
        db_func->insert_add(tab, "calf_weight",DataSystems::Instance().otel_calf_weight);
        db_func->insert_add(tab, "calf_sex",DataSystems::Instance().otel_calf_sex);
        db_func->insert_add(tab, "calf_hair_color",DataSystems::Instance().otel_calf_hair_color);
        QString sql_insert = db_func->insert_add(tab, "calf_group",DataSystems::Instance().otel_calf_group);

        if(!check_insert_or_update)db_func->sql_exec(sql_insert, "add otel");
        else db_func->sql_exec(sql_update, "update otel");
    }

    status = true;
    QMessageBox::information(this,"Спасибо","Сохранеы данные по отёлу");
    this->close();
}


void table_form_1_2_otel_add::on_pushButton_add_telyat_clicked()
{
    table_form_1_2_otel_add_calves_Dialog otel_add_number_calves(this);
    if(!(otel_add_number_calves.exec()==QDialog::Accepted))
    {
        ui->label_telyat_counter->setText(DataSystems::Instance().otel_number_of_calves);
    }

}


void table_form_1_2_otel_add::on_pushButton_close_clicked()
{
    status = false;
    this->close();
}

