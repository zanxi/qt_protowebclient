#include "form_1_1.h"
#include "ui_form_1_1.h"

#include "./db/database.h"
#include "dataanimals.h"

#include "./Debug/logger.h"

Form_1_1::Form_1_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_1_1)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);


    ui->groupBox_2->setStyleSheet("QGroupBox {"
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


    ui->lineEdit_login->setText(DataSystems::Instance().db_login);
    ui->lineEdit_password->setText(DataSystems::Instance().db_password);

    m_qlist_model_country = new QStringListModel();
    m_qlist_model_culture = new QStringListModel();
    m_qlist_model_lang = new QStringListModel();
    m_qlist_list_devices = new QStringListModel();

    QStringList list_country,  list_culture,  list_lang, list_device;
    list_country.append(QString("Россия "));
    list_country.append(QString("Германия "));
    list_country.append(QString("Голландия "));
    list_country.append(QString("Германия "));
    list_country.append(QString("Англия "));
    list_country.append(QString("Сша "));
    list_country.append(QString("Китай "));
    list_country.append(QString("Франция "));

    list_culture.append(QString("русская "));
    list_culture.append(QString("азиатская "));
    list_culture.append(QString("Голландия "));
    list_culture.append(QString("индо-европейская "));
    list_culture.append(QString("восточная "));
    list_culture.append(QString("западная "));
    list_culture.append(QString("буддизм "));
    list_culture.append(QString("атеизм "));

    list_lang.append(QString("русский "));
    list_lang.append(QString("немецкий "));
    list_lang.append(QString("голландский "));
    list_lang.append(QString("австрийский "));
    list_lang.append(QString("английский "));
    list_lang.append(QString("английский(Сша) "));
    list_lang.append(QString("китайский "));
    list_lang.append(QString("французский "));

    list_device.append(QString("1.0"));
    list_device.append(QString("2.0"));
    list_device.append(QString("3.0"));
    list_device.append(QString("4.0"));


    m_qlist_model_country->setStringList(list_country);
    m_qlist_model_culture->setStringList(list_culture);
    m_qlist_model_lang->setStringList(list_lang);
    m_qlist_list_devices->setStringList(list_device);

    //ui->comboBox->setModel(m_qlist_model);
    ui->comboBox_counrty->setModel(m_qlist_model_country);
    ui->comboBox_culture->setModel(m_qlist_model_culture);
    ui->comboBox_lang->setModel(m_qlist_model_lang);
    ui->comboBox_list_devices->setModel(m_qlist_list_devices);

    GetRegisterData();

    //ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);

}

Form_1_1::~Form_1_1()
{
    delete ui;
}

void Form_1_1::GetRegisterData()
{
    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
       //QString sql =  QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();
       //QString sql =  QString("SELECT * FROM public."+nameTab+" ORDER BY "+primaryKey+" ASC ").toLower();
       QString sql =  QString("SELECT * FROM DataService WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
       logger::WriteLog("SELECT vars: ----- " + sql);

       QSqlQuery* query = db_func->sql_exec2(sql);

       if(query->size()<1)return;

    int i=0;
    while(query->next())
    {
        DataSystems::Instance().DataService_FarmDepart =  query->value("data_farmdepart").toString();
        DataSystems::Instance().DataService_counrty =  query->value("data_country").toString();
        DataSystems::Instance().DataService_lang =  query->value("data_language").toString();
        DataSystems::Instance().DataService_culture =  query->value("data_culture").toString();
        DataSystems::Instance().DataService_Index =  query->value("data_index").toString();
        DataSystems::Instance().DataService_street =  query->value("data_street").toString();
        DataSystems::Instance().DataService_street_number =  query->value("data_street_number").toString();
        DataSystems::Instance().DataService_city =  query->value("data_city").toString();
        DataSystems::Instance().DataService_telephone =  query->value("data_telephone").toString();
        DataSystems::Instance().DataService_owner_name =  query->value("data_owner_name").toString();
        //DataSystems::Instance().DataService_ =  query->value("data_street").toString();

        i++;
    }
    }

    ui->lineEdit_FarmDepart->setText(DataSystems::Instance().DataService_FarmDepart);
    ui->comboBox_counrty->setCurrentText(DataSystems::Instance().DataService_counrty);
    ui->comboBox_lang->setCurrentText(DataSystems::Instance().DataService_lang);
    ui->comboBox_culture->setCurrentText(DataSystems::Instance().DataService_culture);
    ui->lineEdit_Index->setText(DataSystems::Instance().DataService_Index);
    ui->lineEdit_city->setText(DataSystems::Instance().DataService_city);
    ui->lineEdit_street->setText(DataSystems::Instance().DataService_street);
    ui->lineEdit_street_number->setText(DataSystems::Instance().DataService_street_number);
    ui->lineEdit_zip_code->setText(DataSystems::Instance().DataService_zip_code);
    ui->lineEdit_telephone->setText(DataSystems::Instance().DataService_telephone);
    ui->lineEdit_owner_name->setText(DataSystems::Instance().DataService_owner_name);



    /**/

}

void Form_1_1::SaveRegisterData()
{
    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        //QString sql="UPDATE DataService SET "+parameter+" = '"+value+"'" + " where " + parameterID + " = "+ ""+ valueId +"";
        QString sql2=QString("UPDATE DataService SET ")+
                       "data_farmdepart = '" + ui->lineEdit_FarmDepart->text() + "', " +
                       "data_country = '" + ui->comboBox_counrty->currentText() + "', " +
                       "data_language = '" + ui->comboBox_lang->currentText() + "', " +
                       "data_culture = '" + ui->comboBox_culture->currentText() + "', " +
                       "data_index = '" + ui->lineEdit_Index->text() + "', " +
                       "data_street = '" + ui->lineEdit_street->text() + "', " +
                       "data_street_number = '" + ui->lineEdit_street_number->text() + "', " +
                       "data_zip_code = '" + ui->lineEdit_zip_code->text() + "', " +
                       "data_city = '" + ui->lineEdit_city->text() + "', " +
                       "data_telephone = '" + ui->lineEdit_telephone->text() + "', " +
                       "data_owner_name = '" + ui->lineEdit_owner_name->text() + "' " +
                       " where id =  "+QString::number(DataSystems::Instance().DataService_Id);

        QString sql = "INSERT INTO DataService("
                              "db_type,"
                              "data_work,"
                              "db_host,"
                              "db_name,"
                              "db_login,"
                              "db_password,"
                              "data_farmdepart,"
                              "data_country,"
                              "data_language,"
                              "data_culture,"
                              "data_index,"
                              "data_street,"
                              "data_street_number,"
                              "data_zip_code,"
                              "data_city,"
                              "data_telephone,"
                              "data_owner_name"
                              ")"+
                      QString("VALUES (")+
                      ((DataSystems::Instance().db_check ==  DB_check::PGSQL)?"'postgresql'":"'sqlite'")  +  ", '"  +
                      QString::fromStdString(datetime::utcExample()) + "', '" +
                      DataSystems::Instance().db_host + "', '" +
                      DataSystems::Instance().db_name + "', '" +
                      DataSystems::Instance().db_login + "', '" +
                      DataSystems::Instance().db_password + "', '" +
                      ui->lineEdit_FarmDepart->text()+ "', '" +
                      ui->comboBox_counrty->currentText()+ "', '" +
                      ui->comboBox_lang->currentText()+ "', '" +
                      ui->comboBox_culture->currentText()+ "', '"+
                      ui->lineEdit_Index->text()+ "', '" +
                      ui->lineEdit_street->text()+ "', '" +
                      ui->lineEdit_street_number->text()+ "', '" +
                      ui->lineEdit_zip_code->text()+ "', '" +
                      ui->lineEdit_city->text()+ "', '" +
                      ui->lineEdit_telephone->text()+ "', '" +
                      ui->lineEdit_owner_name->text()+ "')";
        //DataSystems::Instance().db_password + "')";
        //logger::WriteMsg(sql.toStdString());
        //logger::WriteLog("SaveAutorizartion: ---- "+sql);
        //ui->textEdit_log->setText(DataSystems::Instance().log);
        db_func->sql_exec(sql2);
    }
}

void Form_1_1::on_pushButton_clicked()
{
    if(QMessageBox::question(0,"Не сохранять","Сохранить",
                              QMessageBox::No,QMessageBox::Yes)==QMessageBox::Yes)
    {
       SaveRegisterData();
       QMessageBox::information(this,"Данные сохранены в базе данных VIM- DataService"," номер записи id: "+QString::number(DataSystems::Instance().DataService_Id));
    }
}

