#include "form_1_9_add_cow.h"
//#include "FormsMenu/ui_form_1_9_add_cow.h"
#include "ui_form_1_9_add_cow.h"


#include "dataanimals.h"

// 1. Навигатор: Ввод данных  2. Меню: Дневная запись      3. Подменю: Карты коров

Form_1_9_add_cow::Form_1_9_add_cow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_1_9_add_cow)
{
    ui->setupUi(this);

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

void Form_1_9_add_cow::operatingModeButtonsToggled_YN(int id, bool status)
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
void Form_1_9_add_cow::operatingModeButtonsClicked_YN(int id)
{

    qDebug("Clicked YN: %d", id);

    //operatingModeGroup->
    if(id==0);
}

void Form_1_9_add_cow::operatingModeButtonsToggled_MW(int id, bool status)
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
void Form_1_9_add_cow::operatingModeButtonsClicked_MW(int id)
{

    qDebug("Clicked MW: %d", id);

    //operatingModeGroup->
    if(id==0);
    //qDebug("flag = %d, status = %d, tmp = %d, checked = %s", id, status, tmp, byteArray.data());
}


void Form_1_9_add_cow::operatingModeButtonsToggled_Local(int id, bool status)
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
void Form_1_9_add_cow::operatingModeButtonsClicked_Local(int id)
{

    qDebug("Clicked MW: %d", id);

    //operatingModeGroup->
    if(id==0);
    //qDebug("flag = %d, status = %d, tmp = %d, checked = %s", id, status, tmp, byteArray.data());
}


Form_1_9_add_cow::~Form_1_9_add_cow()
{
    delete ui;
}




void Form_1_9_add_cow::on_pushButton_save_clicked()
{
    DataSystems::Instance().dataentry_dataentry_cow_card_animals = ui->lineEdit->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_responder = ui->lineEdit_responder->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_name = ui->lineEdit_name->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_group = ui->comboBox_group->currentText();
    DataSystems::Instance().dataentry_dataentry_cow_card_life_number = ui->lineEdit_life_no->text();
    //DataSystems::Instance().dataentry_dataentry_cow_card_present = ui->lineEdit->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_label = ui->comboBox_label->currentText();
    DataSystems::Instance().dataentry_dataentry_cow_card_birth_date = ui->dateEdit_birth_date->text();
    DataSystems::Instance().dataentry_dataentry_cow_card_keep = QString::number(operatingModeGroup_YN->checkedId()); // value 0 - yes 1 - No
    DataSystems::Instance().dataentry_dataentry_cow_card_gender = QString::number(operatingModeGroup_MW->checkedId()); // value 0 - man 1 - wom
    DataSystems::Instance().dataentry_dataentry_cow_card_use_as_sire = operatingModeGroup_use_as_sire->checkedId();
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
             /*
             QString sql2=QString("UPDATE DataService SET ")+
                            "db_type = " + ((DataSystems::Instance().db_check ==  DB_check::PGSQL)?"'postgresql'":"'sqlite'") + ", " +
                            "data_work = '" + QString::fromStdString(datetime::utcExample()) + "', " +
                            "db_port = '" + QString::number(DataSystems::Instance().db_port) + "', " +
                            "db_host = '" + DataSystems::Instance().db_host + "', " +
                            "db_sqlite_file = '" + DataSystems::Instance().db_sqlite_file + "', " +
                            "db_name = '" + DataSystems::Instance().db_name + "', " +
                            "db_login = '" + DataSystems::Instance().db_login + "', " +

                            "db_password = '" + DataSystems::Instance().db_password + "' " +
                            " where id =  "+ QString::number(DataSystems::Instance().DataService_Id);

             /**/


             QString sql = QString("INSERT INTO dataentry_cow_card("
                              "animals,"
                              "responder,"
                              "name,"
                              "group_,"
                              "life_number,"
                              "present,"
                              "birth_date,"
                              "location,"
                              "label,"
                              "keep,"
                              "gender,"
                              "use_as_sire,"
                              "father_life_number,"
                              "father_name,"
                              "mother_life_number,"
                              "mother_name,"
                              "hair_color,"
                              "gestation,"
                              "calm,"
                              "blood_type,"
                              "percentage,"
                              "description,"
                              "transfer_in"
                              ")")+
                           QString("VALUES (")+
                           "'" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_animals + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_responder + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_name + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_group + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_life_number + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_present + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_birth_date + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_location + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_label + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_keep + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_gender + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_use_as_sire + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_father_life_number + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_father_name + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_mother_life_number + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_mother_name + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_hair_color + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_gestation + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_calm + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_blood_type + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_percentage + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_description + "', '" +
                           DataSystems::Instance().dataentry_dataentry_cow_card_transfer_in  + "');";  //,// '" +
             //"----------" + "')";
             db_func->sql_exec(sql, "add cow");
    }



    this->close();
}

