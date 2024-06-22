#include "Form_add_cow.h"
//#include "FormsMenu/ui_Form_add_cow.h"
#include "ui_form_add_cow.h"


#include "dataanimals.h"
#include "Debug/logger.h"

// 1. Навигатор: Ввод данных  2. Меню: Дневная запись      3. Подменю: Карты коров

Form_add_cow::Form_add_cow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_add_cow)
{
    ui->setupUi(this);

    check_insert_or_update = false; // добавить данные

    ui->pushButton_save->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );


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


    //return;

    ui->dateEdit_birth_date->setDate(QDate().currentDate());
    ui->dateEdit_transition->setDate(QDate().currentDate());



    // **************** group radiobutton ********************************
    operatingModeGroup_YN = new QButtonGroup(this);
    operatingModeGroup_YN->addButton(ui->radioButton_yes, AC_YES);
    operatingModeGroup_YN->addButton(ui->radioButton_no, AC_NO);
    connect(operatingModeGroup_YN, SIGNAL(buttonToggled(int,bool)), this, SLOT(operatingModeButtonsToggled_YN(int,bool)));
    connect(operatingModeGroup_YN, SIGNAL(buttonClicked(int)), this, SLOT(operatingModeButtonsClicked_YN(int)));
    // *******************************************************************
    operatingModeGroup_MW = new QButtonGroup(this);
    operatingModeGroup_MW->addButton(ui->radioButton_m, AC_M);
    operatingModeGroup_MW->addButton(ui->radioButton_w, AC_W);
    connect(operatingModeGroup_MW, SIGNAL(buttonToggled(int,bool)), this, SLOT(operatingModeButtonsToggled_MW(int,bool)));
    connect(operatingModeGroup_MW, SIGNAL(buttonClicked(int)), this, SLOT(operatingModeButtonsClicked_MW(int)));
    // *******************************************************************
    operatingModeGroup_use_as_sire = new QButtonGroup(this);
    operatingModeGroup_use_as_sire->addButton(ui->radioButton_m, AC_use);
    operatingModeGroup_use_as_sire->addButton(ui->radioButton_w, AC_unuse);
    //connect(operatingModeGroup_use_as_sire, SIGNAL(buttonToggled(int,bool)), this, SLOT(operatingModeButtonsToggled_MW(int,bool)));
    //connect(operatingModeGroup_use_as_sire, SIGNAL(buttonClicked(int)), this, SLOT(operatingModeButtonsClicked_MW(int)));
    // *******************************************************************
    operatingModeGroup_Local = new QButtonGroup(this);
    //operatingModeGroup_Local->addButton(ui->radioButton_, AC_1);
    //operatingModeGroup_Local->addButton(ui->radioButton_2, AC_2);
    //operatingModeGroup_Local->addButton(ui->radioButton_, AC_2);
    //operatingModeGroup_Local->addButton(ui->radioButton_m, AC_3);
    connect(operatingModeGroup_Local, SIGNAL(buttonToggled(int,bool)), this, SLOT(operatingModeButtonsToggled_Local(int,bool)));
    connect(operatingModeGroup_Local, SIGNAL(buttonClicked(int)), this, SLOT(operatingModeButtonsClicked_Local(int)));
    // *******************************************************************

}


Form_add_cow::Form_add_cow(const QString &nnn, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_add_cow)
{
    ui->setupUi(this);

    check_insert_or_update = true; // update

    ui->pushButton_save->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );


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
                                                                                      "}");\

        ui->lineEdit_animal_N->setEnabled(false);

    ui->dateEdit_birth_date->setDate(QDate().currentDate());
    ui->dateEdit_transition->setDate(QDate().currentDate());

    // **************** group radiobutton ********************************
    operatingModeGroup_YN = new QButtonGroup(this);
    operatingModeGroup_YN->addButton(ui->radioButton_yes, AC_YES);
    operatingModeGroup_YN->addButton(ui->radioButton_no, AC_NO);
    connect(operatingModeGroup_YN, SIGNAL(buttonToggled(int,bool)), this, SLOT(operatingModeButtonsToggled_YN(int,bool)));
    connect(operatingModeGroup_YN, SIGNAL(buttonClicked(int)), this, SLOT(operatingModeButtonsClicked_YN(int)));
    // *******************************************************************
    operatingModeGroup_MW = new QButtonGroup(this);
    operatingModeGroup_MW->addButton(ui->radioButton_m, AC_M);
    operatingModeGroup_MW->addButton(ui->radioButton_w, AC_W);
    connect(operatingModeGroup_MW, SIGNAL(buttonToggled(int,bool)), this, SLOT(operatingModeButtonsToggled_MW(int,bool)));
    connect(operatingModeGroup_MW, SIGNAL(buttonClicked(int)), this, SLOT(operatingModeButtonsClicked_MW(int)));
    // *******************************************************************
    operatingModeGroup_use_as_sire = new QButtonGroup(this);
    operatingModeGroup_use_as_sire->addButton(ui->radioButton_m, AC_use);
    operatingModeGroup_use_as_sire->addButton(ui->radioButton_w, AC_unuse);
    //connect(operatingModeGroup_use_as_sire, SIGNAL(buttonToggled(int,bool)), this, SLOT(operatingModeButtonsToggled_MW(int,bool)));
    //connect(operatingModeGroup_use_as_sire, SIGNAL(buttonClicked(int)), this, SLOT(operatingModeButtonsClicked_MW(int)));
    // *******************************************************************
    operatingModeGroup_Local = new QButtonGroup(this);
    //operatingModeGroup_Local->addButton(ui->radioButton_, AC_1);
    //operatingModeGroup_Local->addButton(ui->radioButton_2, AC_2);
    //operatingModeGroup_Local->addButton(ui->radioButton_, AC_2);
    //operatingModeGroup_Local->addButton(ui->radioButton_m, AC_3);
    connect(operatingModeGroup_Local, SIGNAL(buttonToggled(int,bool)), this, SLOT(operatingModeButtonsToggled_Local(int,bool)));
    connect(operatingModeGroup_Local, SIGNAL(buttonClicked(int)), this, SLOT(operatingModeButtonsClicked_Local(int)));
    // *******************************************************************

    SetData();


}


void Form_add_cow::operatingModeButtonsToggled_YN(int id, bool status)
{
    int tmp = operatingModeGroup_YN->checkedId();
    switch(tmp){
    case operatingModeTypes_YN::AC_YES:
        break;
    case operatingModeTypes_YN::AC_NO:
        break;
    }

    QString str = operatingModeGroup_YN->checkedButton()->text();
    QByteArray byteArray = str.toLocal8Bit();
    //qDebug("flag = %d, status = %d, tmp = %d, checked = %s", id, status, tmp, byteArray.data());
}
void Form_add_cow::operatingModeButtonsClicked_YN(int id)
{

    qDebug("Clicked YN: %d", id);

    //operatingModeGroup->
    if(id==0);
}

void Form_add_cow::operatingModeButtonsToggled_MW(int id, bool status)
{

    int tmp = operatingModeGroup_MW->checkedId();
    switch(tmp){
    case operatingModeTypes_MW::AC_M:
        break;
    case operatingModeTypes_MW::AC_W:
        break;
    }

    QString str = operatingModeGroup_MW->checkedButton()->text();
    QByteArray byteArray = str.toLocal8Bit();
    //qDebug("flag = %d, status = %d, tmp = %d, checked = %s", id, status, tmp, byteArray.data());
}
void Form_add_cow::operatingModeButtonsClicked_MW(int id)
{

    qDebug("Clicked MW: %d", id);

    //operatingModeGroup->
    if(id==0);
    //qDebug("flag = %d, status = %d, tmp = %d, checked = %s", id, status, tmp, byteArray.data());
}


void Form_add_cow::operatingModeButtonsToggled_Local(int id, bool status)
{

    int tmp = operatingModeGroup_Local->checkedId();
    switch(tmp){
    case operatingModeTypes_Local::AC_1:
        break;
    case operatingModeTypes_Local::AC_2:
        break;
    }

    QString str = operatingModeGroup_Local->checkedButton()->text();
    QByteArray byteArray = str.toLocal8Bit();
    //qDebug("flag = %d, status = %d, tmp = %d, checked = %s", id, status, tmp, byteArray.data());
}
void Form_add_cow::operatingModeButtonsClicked_Local(int id)
{

    qDebug("Clicked MW: %d", id);

    //operatingModeGroup->
    if(id==0);
    //qDebug("flag = %d, status = %d, tmp = %d, checked = %s", id, status, tmp, byteArray.data());
}


Form_add_cow::~Form_add_cow()
{
    delete ui;
}




void Form_add_cow::on_pushButton_save_clicked()
{
    DataSystems::Instance().dataentry_dataentry_cow_card_animal_No = ui->lineEdit_animal_N->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_responder = ui->lineEdit_responder->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_name = ui->lineEdit_name->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_group = ui->comboBox_group->currentText();
    DataSystems::Instance().dataentry_dataentry_cow_card_life_number = ui->lineEdit_life_no->text();
    //DataSystems::Instance().dataentry_dataentry_cow_card_present = ui->lineEdit->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_label = ui->comboBox_label->currentText();
    DataSystems::Instance().dataentry_dataentry_cow_card_birth_date = ui->dateEdit_birth_date->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_keep = QString::number(operatingModeGroup_YN->checkedId()); // value 0 - yes 1 - No
    DataSystems::Instance().dataentry_dataentry_cow_card_gender = QString::number(operatingModeGroup_MW->checkedId()); // value 0 - man 1 - wom
    DataSystems::Instance().dataentry_dataentry_cow_card_use_as_sire = QString::number(operatingModeGroup_use_as_sire->checkedId());
    DataSystems::Instance().dataentry_dataentry_cow_card_father_life_number = ui->lineEdit_father_life_number->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_mother_life_number = ui->lineEdit->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_hair_color = ui->comboBox_mair_color->currentText();
    DataSystems::Instance().dataentry_dataentry_cow_card_gestation = ui->lineEdit_gestaton->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_calm = ui->comboBox_calm->currentText();
    DataSystems::Instance().dataentry_dataentry_cow_card_blood_type = ui->comboBox_blood_type->currentText();
    DataSystems::Instance().dataentry_dataentry_cow_card_percentage = ui->comboBox_percentage->currentText();
    DataSystems::Instance().dataentry_dataentry_cow_card_description = ui->textEdit_description->placeholderText();
    DataSystems::Instance().dataentry_dataentry_cow_card_transfer_in = (ui->checkBox_transfer->checkState()==Qt::CheckState::Checked)?"0":"1";
    //DataSystems::Instance().dataentry_dataentry_cow_card_ = ui->dateEdit_birth_date->text();
    //DataSystems::Instance().dataentry_dataentry_cow_card_ = ui->dateEdit_birth_date->text();


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
             /**/

             QString tab = "dataentry_cow_card";
             QString parameterId = "animals";
             QString valueId = DataSystems::Instance().dataentry_dataentry_cow_card_animal_No;

             db_func->update_add(tab, parameterId, valueId, "responder", DataSystems::Instance().dataentry_dataentry_cow_card_responder);
             db_func->update_add(tab, parameterId, valueId, "name_", DataSystems::Instance().dataentry_dataentry_cow_card_name);
             db_func->update_add(tab, parameterId, valueId, "group_", DataSystems::Instance().dataentry_dataentry_cow_card_group);
             db_func->update_add(tab, parameterId, valueId, "life_number", DataSystems::Instance().dataentry_dataentry_cow_card_life_number);
             db_func->update_add(tab, parameterId, valueId, "present", DataSystems::Instance().dataentry_dataentry_cow_card_present);
             db_func->update_add(tab, parameterId, valueId, "birth_date", DataSystems::Instance().dataentry_dataentry_cow_card_birth_date);
             db_func->update_add(tab, parameterId, valueId, "location_", DataSystems::Instance().dataentry_dataentry_cow_card_location);
             db_func->update_add(tab, parameterId, valueId, "label_", DataSystems::Instance().dataentry_dataentry_cow_card_label);
             db_func->update_add(tab, parameterId, valueId, "keep", DataSystems::Instance().dataentry_dataentry_cow_card_keep);
             db_func->update_add(tab, parameterId, valueId, "gender", DataSystems::Instance().dataentry_dataentry_cow_card_gender);
             db_func->update_add(tab, parameterId, valueId, "use_as_sire", DataSystems::Instance().dataentry_dataentry_cow_card_use_as_sire);
             db_func->update_add(tab, parameterId, valueId, "father_life_number", DataSystems::Instance().dataentry_dataentry_cow_card_father_life_number);
             db_func->update_add(tab, parameterId, valueId, "father_name", DataSystems::Instance().dataentry_dataentry_cow_card_father_name);
             db_func->update_add(tab, parameterId, valueId, "mother_life_number", DataSystems::Instance().dataentry_dataentry_cow_card_mother_life_number);
             db_func->update_add(tab, parameterId, valueId, "mother_name", DataSystems::Instance().dataentry_dataentry_cow_card_mother_name);
             db_func->update_add(tab, parameterId, valueId, "hair_color", DataSystems::Instance().dataentry_dataentry_cow_card_hair_color);
             db_func->update_add(tab, parameterId, valueId, "gestation", DataSystems::Instance().dataentry_dataentry_cow_card_gestation);
             db_func->update_add(tab, parameterId, valueId, "calm", DataSystems::Instance().dataentry_dataentry_cow_card_calm);
             db_func->update_add(tab, parameterId, valueId, "blood_type", DataSystems::Instance().dataentry_dataentry_cow_card_blood_type);
             db_func->update_add(tab, parameterId, valueId, "percentage", DataSystems::Instance().dataentry_dataentry_cow_card_percentage);
             db_func->update_add(tab, parameterId, valueId, "description", DataSystems::Instance().dataentry_dataentry_cow_card_description);
             QString sql_update__ = db_func->update_add(tab, parameterId, valueId,  "transfer_in", DataSystems::Instance().dataentry_dataentry_cow_card_transfer_in);

             //logger::WriteMsg("sql__update: " + sql_update__.toStdString());
/**/
        //qDebug()<<"after try catch ----------------------";

             db_func->insert_add(tab, "animal_No", DataSystems::Instance().dataentry_dataentry_cow_card_animal_No);
             db_func->insert_add(tab, "responder", DataSystems::Instance().dataentry_dataentry_cow_card_responder);
             db_func->insert_add(tab, "name_", DataSystems::Instance().dataentry_dataentry_cow_card_name);
             db_func->insert_add(tab, "group_", DataSystems::Instance().dataentry_dataentry_cow_card_group);
             db_func->insert_add(tab, "life_number", DataSystems::Instance().dataentry_dataentry_cow_card_life_number);
             db_func->insert_add(tab, "present", DataSystems::Instance().dataentry_dataentry_cow_card_present);
             db_func->insert_add(tab, "birth_date", DataSystems::Instance().dataentry_dataentry_cow_card_birth_date);
             db_func->insert_add(tab, "location_", DataSystems::Instance().dataentry_dataentry_cow_card_location);
             db_func->insert_add(tab, "label_", DataSystems::Instance().dataentry_dataentry_cow_card_label);
             db_func->insert_add(tab, "keep", DataSystems::Instance().dataentry_dataentry_cow_card_keep);
             db_func->insert_add(tab, "gender", DataSystems::Instance().dataentry_dataentry_cow_card_gender);
             db_func->insert_add(tab, "use_as_sire", DataSystems::Instance().dataentry_dataentry_cow_card_use_as_sire);
             db_func->insert_add(tab, "father_life_number", DataSystems::Instance().dataentry_dataentry_cow_card_father_life_number);
             db_func->insert_add(tab, "father_name", DataSystems::Instance().dataentry_dataentry_cow_card_father_name);
             db_func->insert_add(tab, "mother_life_number", DataSystems::Instance().dataentry_dataentry_cow_card_mother_life_number);
             db_func->insert_add(tab, "mother_name", DataSystems::Instance().dataentry_dataentry_cow_card_mother_name);
             db_func->insert_add(tab, "hair_color", DataSystems::Instance().dataentry_dataentry_cow_card_hair_color);
             db_func->insert_add(tab, "gestation", DataSystems::Instance().dataentry_dataentry_cow_card_gestation);
             db_func->insert_add(tab, "calm", DataSystems::Instance().dataentry_dataentry_cow_card_calm);
             db_func->insert_add(tab, "blood_type", DataSystems::Instance().dataentry_dataentry_cow_card_blood_type);
             db_func->insert_add(tab, "percentage", DataSystems::Instance().dataentry_dataentry_cow_card_percentage);
             db_func->insert_add(tab, "description", DataSystems::Instance().dataentry_dataentry_cow_card_description);
             QString sql_insert = db_func->insert_add(tab, "transfer_in", DataSystems::Instance().dataentry_dataentry_cow_card_transfer_in);


        /**/
        //qDebug()<<"error -------- : "+sql2;
        //qDebug()<<"error -------- : "+sql_update__;
        //"----------" + "')";
        if(!check_insert_or_update)db_func->sql_exec(sql_insert, "add cow");
        else db_func->sql_exec(QString(sql_update__), "update cow");

    }
    status = true;
    this->close();
}

void Form_add_cow::SetData()
{
    ui->lineEdit_animal_N->setText(DataSystems::Instance().dataentry_dataentry_cow_card_animal_No);
    ui->lineEdit_responder->setText(DataSystems::Instance().dataentry_dataentry_cow_card_responder);
    ui->lineEdit_name->setText(DataSystems::Instance().dataentry_dataentry_cow_card_name);
    ui->comboBox_group->setEditText(DataSystems::Instance().dataentry_dataentry_cow_card_group);
    ui->lineEdit_life_no->setText(DataSystems::Instance().dataentry_dataentry_cow_card_life_number);
    //DataSystems::Instance().dataentry_dataentry_cow_card_present = ui->lineEdit->text();
    ui->comboBox_label->setEditText(DataSystems::Instance().dataentry_dataentry_cow_card_label);
    //ui->dateEdit_birth_date->setDate(DataSystems::Instance().dataentry_dataentry_cow_card_birth_date);
    //operatingModeGroup_YN-> setText(DataSystems::Instance().dataentry_dataentry_cow_card_keep = QString::number(operatingModeGroup_YN->checkedId()); // value 0 - yes 1 - No
    //DataSystems::Instance().dataentry_dataentry_cow_card_gender = QString::number(operatingModeGroup_MW->checkedId()); // value 0 - man 1 - wom
    //DataSystems::Instance().dataentry_dataentry_cow_card_use_as_sire = QString::number(operatingModeGroup_use_as_sire->checkedId());
    ui->lineEdit_father_life_number->setText(DataSystems::Instance().dataentry_dataentry_cow_card_father_life_number);
    ui->lineEdit->setText(DataSystems::Instance().dataentry_dataentry_cow_card_mother_life_number);
    //DataSystems::Instance().dataentry_dataentry_cow_card_hair_color = ui->comboBox_mair_color->currentText();
    ui->lineEdit_gestaton->setText(DataSystems::Instance().dataentry_dataentry_cow_card_gestation);
    //DataSystems::Instance().dataentry_dataentry_cow_card_calm = ui->comboBox_calm->currentText();
    //DataSystems::Instance().dataentry_dataentry_cow_card_blood_type = ui->comboBox_blood_type->currentText();
    //DataSystems::Instance().dataentry_dataentry_cow_card_percentage = ui->comboBox_percentage->currentText();
    ui->textEdit_description->setText(DataSystems::Instance().dataentry_dataentry_cow_card_description);
    DataSystems::Instance().dataentry_dataentry_cow_card_transfer_in = (ui->checkBox_transfer->checkState()==Qt::CheckState::Checked)?"0":"1";
    //DataSystems::Instance().dataentry_dataentry_cow_card_ = ui->dateEdit_birth_date->text();
    //DataSystems::Instance().dataentry_dataentry_cow_card_ = ui->dateEdit_birth_date->text();


}




void Form_add_cow::on_pushButton_close_clicked()
{
    QMessageBox::information(this,"Успешно","Вышли без изменния данных");
    status = false;
    this->close();
}

