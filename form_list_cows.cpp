#include "form_list_cows.h"
#include "ui_form_list_cows.h"

#include "dataanimals.h"
#include "FormsMenu/Form_add_cow.h"
#include "Debug/logger.h"


#include <QPrintPreviewDialog>

#include "Src/pbs/pbsfileutil.h"
#include "Src/pbs/pbstools.h"
#include "Src/pbsmodelexporter.h"
#include "src/pbstableprinter.h"

Form_List_Cows::Form_List_Cows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_List_Cows)
    , actSaveExcel(QIcon(":/Resource/Images/xls.png"), PBSTR("Excel "), this)
    , actSaveExcelXML(QIcon(":/Resource/Images/xls.png"), PBSTR("Excel (XML)"), this)
    , actSaveWordXML(QIcon(":/Resource/Images/word.png"), PBSTR("Word (XML)"), this)
    , actSavePDF(QIcon(":/Resource/Images/pdf.png"), PBSTR("PDF "), this)
    , actSaveCSV(QIcon(":/Resource/Images/csv.png"), PBSTR("Text (CSV)"), this)
    , actSaveXML(QIcon(":/Resource/Images/xml.png"), PBSTR("XML "), this)
    , actSaveHTML(QIcon(":/Resource/Images/htm.png"), PBSTR("HTML "), this)
    , actFilter(QIcon(":/Resource/Images/filter.png"), PBSTR("HTML "), this)

{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);





     create_table_view();

     ThisStyle(DataSystems::Instance().settings___color_header);

    //addRandom();

}

Form_List_Cows::~Form_List_Cows()
{
    delete ui;
}

void Form_List_Cows::ThisStyle(QString color_h)
{

    QList<QPushButton*> allButton = findChildren<QPushButton*>();
    for(int i=0;i<allButton.size();i++)
    {
        allButton[i]->setStyleSheet(
            "background-color:"+color_h+";"
                                            "color: white;"
                                            "padding: 4 50 4 10;");
    }

    QList<QGroupBox*> allGroup = findChildren<QGroupBox*>();
    for(int i=0;i<allGroup.size();i++)
    {
        allGroup[i]->setStyleSheet(
            "QGroupBox {"
            "background-color: white;"
            "}"
            "QGroupBox::title {"
            "color: white;"
            "background-color:"+color_h+";"
                        "padding: 4 20000 4 10;"
                        "}"
            );
    }

//    ui->tableWidget_list_cows->setStyleSheet("QTableView"
//                               "{"
//                               "   background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
//                                                                                             "}"

//                                                                                             "QTabWidget:tab-bar"
//                                                                                             "{"
//                                                                                             "    alignment: center;"
//                                                                                             "}"

//                                                                                             "QTabBar:tab"
//                                                                                             "{"
//                                                                                             "   width: "+DataSystems::Instance().settings___tabwidget_width+";"
//                                                                                      "   height: 30px;"
//                                                                                      "}"

//                                                                                      "QTabBar:selected"
//                                                                                      "{"
//                                                                                      "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
//                                                                                             "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
//                                                                                             "}"

//                                                                                             "QTabBar:tab:!selected"
//                                                                                             "{"
//                                                                                             "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
//                                                                                             "}"


//                                                                                             "QTabBar:tab:!selected:hover"
//                                                                                             "{"
//                                                                                             "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
//                                                                                             "    color.rgb(255,255,255);"
//                                                                                             "}"
//                                                                                             ")");


}


void Form_List_Cows::on_pushButton_delete_clicked()
{
    if(checkAnimals.isEmpty())
    {
        QMessageBox::information(this,"","Не выбрали животное из таблицы");
        return;
    }

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        QString sql2=QString("Delete from dataentry_cow_card ")+
                   " where animal_No =  '"+ checkAnimals + "';";
        db_func->sql_exec(sql2, "delete cow");
    }

    QMessageBox::information(this,"Успешно","Запись удалена");

   GetData();
}


void Form_List_Cows::on_pushButton_select_clicked()
{
    if(checkAnimals.isEmpty())
    {
        QMessageBox::information(this,"","Не выбрали животное из таблицы");
        return;
    }
    GetData(checkAnimals);

    Form_add_cow f_1_9_add_cow("",this);
    if(!(f_1_9_add_cow.exec()==QDialog::Accepted))
    {


        if(f_1_9_add_cow.checkStatus()) QMessageBox::information(this,"Успешно","Обновили данные животного");
    }

    GetData();
}


void
Form_List_Cows::on_pushButton_add_clicked()
{
    Form_add_cow f_1_9_add_cow(this);
    if(!(f_1_9_add_cow.exec()==QDialog::Accepted))
    {
        QMessageBox::information(this,"Успешно","Добавили животное");
        //QApplication::closeAllWindows();
        //QApplication::quit();


        //        if(selectRowOld==-1)return;
        //        DataSystems::Instance().otel_animal_No = ui->tableWidget->item(selectRow,1)->text();
        //        DataSystems::Instance().otel_number = "";
        //        DataSystems::Instance().otel_Robot_No = ui->tableWidget->item(selectRow,3)->text();
        //        DataSystems::Instance().otel_lactation_No = ui->tableWidget->item(selectRow,4)->text();
        //        DataSystems::Instance().otel_lactation_days = ui->tableWidget->item(selectRow,5)->text();
        //        DataSystems::Instance().otel_days_pregnant = ui->tableWidget->item(selectRow,6)->text();
        //        DataSystems::Instance().otel_lactation_production = ui->tableWidget->item(selectRow,7)->text();
        //        DataSystems::Instance().otel_average_lactation = ui->tableWidget->item(selectRow,8)->text();
        //        DataSystems::Instance().otel_average_refusals = ui->tableWidget->item(selectRow,9)->text();
        //        DataSystems::Instance().otel_average_falures = ui->tableWidget->item(selectRow,10)->text();
        //        DataSystems::Instance().otel_average_milk_speed = ui->tableWidget->item(selectRow,11)->text();

    }

    GetData();

}


void Form_List_Cows::create()
{

}

void Form_List_Cows::on_comboBox_numbers_activated(int index)
{
    //DataSystems::Instance().clear_otel();

    int i=0;
    selectRow=-1;
    //qDebug()<<"check: "<<ui->comboBox->currentText();
    //QString check = ui->comboBox->currentData(index).toString();
    checkAnimals = ui->comboBox_numbers->currentText();
    qDebug()<<"check: "<<checkAnimals;
    for(i=0;i<ui->tableWidget_list_cows->rowCount();i++)
    {
        QString val;
        QTableWidgetItem *item = ui->tableWidget_list_cows->item(i,0);
        if (NULL != item) {
            val = item->text();
            if(checkAnimals.contains(val))
            {
                selectRow = i;
                if(selectRowOld!=-1)for(int j=0;j<ui->tableWidget_list_cows->columnCount();j++)ui->tableWidget_list_cows->item(selectRowOld,j)->setBackground( Qt::white);
                for(int j=0;j<ui->tableWidget_list_cows->columnCount();j++)ui->tableWidget_list_cows->item(selectRow,j)->setBackground( Qt::lightGray);
                selectRowOld=selectRow;
                //ui->lineEdit_cow->setText("ответчик: " + ui->tableWidget_list_cows->item(i,1)->text() );
                qDebug()<<"--- break: "<<"i: "<<i<<"; "<<val;
                break;
            }
            qDebug()<<"check: "<<checkAnimals<<"; "<<"i: "<<i<<"; "<<val;
        }
    }

}


void Form_List_Cows::GetData()
{
    ui->tableWidget_list_cows->clear();
    ui->comboBox_numbers->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        //QString sql =  QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();
        QString sql =  QString("SELECT * FROM public.dataentry_cow_card ORDER BY id ASC ").toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        //logger::WriteLog("SELECT vars: ----- " + sql);

        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;

        ui->tableWidget_list_cows->clear();
        int i=0;

        QStringList NameColumns;
        NameColumns<<"Выбор"<<"Номер животного"<<"Ответчик"<<"Название"<<"Группа"<<"Номер жизни"<<"Представление"<<" "<<" ";

        ui->tableWidget_list_cows->setColumnCount( NameColumns.count() );
        ui->tableWidget_list_cows->setRowCount( query->size() );

        //ui->tableWidget_list_cows->setHorizontalHeaderItem(0, new QTableWidgetItem("История"));
        ui->tableWidget_list_cows->setHorizontalHeaderLabels( NameColumns );

        for(i=0;i<NameColumns.count();i++)ui->tableWidget_list_cows->setColumnWidth(i, 150);

        i=0;
        while(query->next())
        {
            ui->tableWidget_list_cows->setItem( i, 1,  new QTableWidgetItem( query->value("animal_No").toString() ));
            ui->comboBox_numbers->addItem(query->value("animal_No").toString());
            ui->tableWidget_list_cows->setItem( i, 2,  new QTableWidgetItem(query->value("responder").toString()));
            ui->tableWidget_list_cows->setItem( i, 3,  new QTableWidgetItem( query->value("name_").toString() ));
            ui->tableWidget_list_cows->setItem( i, 4,  new QTableWidgetItem( query->value("group_").toString() ));
            ui->tableWidget_list_cows->setItem( i, 5,  new QTableWidgetItem( query->value("life_number").toString() ));
            ui->tableWidget_list_cows->setItem( i, 6,  new QTableWidgetItem( query->value("present").toString() ));
            ui->tableWidget_list_cows->setItem( i, 7,  new QTableWidgetItem( query->value("birth_date").toString() ));
            ui->tableWidget_list_cows->setItem( i, 8,  new QTableWidgetItem( query->value("location_").toString() ));
            i++;
        }
    }

    /**/

}


void Form_List_Cows::GetData(const QString &str)
{


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        //QString sql =  QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();
        //QString sql =  QString("SELECT * FROM public.dataentry_cow_card ORDER BY id ASC ").toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        QString sql =  QString("SELECT * FROM public.dataentry_cow_card WHERE animal_No =  '" + str +"';").toLower();
        //logger::WriteLog("SELECT vars: ----- " + sql);

        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;
        logger::WriteMsg("чтение завершено: кол-во записей: "+ query->size());

        int i=0;
        while(query->next())
        {
            DataSystems::Instance().dataentry_dataentry_cow_card_animal_No =  query->value("animal_No").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_responder =  query->value("responder").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_name = query->value("name_").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_group = query->value("group_").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_life_number = query->value("number").toString();
            //DataSystems::Instance().dataentry_dataentry_cow_card_present = ui->lineEdit->text();
            DataSystems::Instance().dataentry_dataentry_cow_card_label = query->value("label_").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_birth_date = query->value("birth_date").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_keep = query->value("keep").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_gender = query->value("gender").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_use_as_sire = query->value("use_as_sire").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_father_life_number = query->value("father_life_number").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_mother_life_number = query->value("mother_life_number").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_hair_color = query->value("hair_color").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_gestation = query->value("gestation").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_calm = query->value("calm").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_blood_type = query->value("blood_type").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_percentage = query->value("percentage").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_description = query->value("description").toString();
            DataSystems::Instance().dataentry_dataentry_cow_card_transfer_in = query->value("transfer_in").toString();
            break;
        }
    }





    /**/

}




void Form_List_Cows::addRandom()
{
    for(int i=0;i<3;i++)
    {
        DataSystems::Instance().dataentry_dataentry_cow_card_animal_No = "cow"+QString::number(rand()%100); // ui->lineEdit_animal_N->text();
        DataSystems::Instance().dataentry_dataentry_cow_card_responder = "responder"+QString::number(rand()%100); // ui->lineEdit_animal_N->text();
        DataSystems::Instance().dataentry_dataentry_cow_card_name = "vm"+QString::number(rand()%100); // ui->lineEdit_animal_N->text();
        DataSystems::Instance().dataentry_dataentry_cow_card_group = "automat";
        DataSystems::Instance().dataentry_dataentry_cow_card_life_number = QString::number(rand()%1000); // ui->lineEdit_animal_N->text();
        //DataSystems::Instance().dataentry_dataentry_cow_card_present = ui->lineEdit->text();
        DataSystems::Instance().dataentry_dataentry_cow_card_label = "label";
        DataSystems::Instance().dataentry_dataentry_cow_card_birth_date = "10.10.2023";// QDateTime(); ui->dateEdit_birth_date->text();
        DataSystems::Instance().dataentry_dataentry_cow_card_keep = "0";
        DataSystems::Instance().dataentry_dataentry_cow_card_gender = "0";
        DataSystems::Instance().dataentry_dataentry_cow_card_use_as_sire = "0"; //  QString::number(operatingModeGroup_use_as_sire->checkedId());
        DataSystems::Instance().dataentry_dataentry_cow_card_father_life_number = "f" + QString::number(rand()%1000); // ui->lineEdit_father_life_number->text();
        DataSystems::Instance().dataentry_dataentry_cow_card_mother_life_number = "m" + QString::number(rand()%1000); // ui->lineEdit->text();
        DataSystems::Instance().dataentry_dataentry_cow_card_hair_color = "black";
        DataSystems::Instance().dataentry_dataentry_cow_card_gestation = "gest" + QString::number(rand()%1000); // ui->lineEdit_gestaton->text();
        DataSystems::Instance().dataentry_dataentry_cow_card_calm = "calm";
        DataSystems::Instance().dataentry_dataentry_cow_card_blood_type = "4";
        DataSystems::Instance().dataentry_dataentry_cow_card_percentage = "90";
        DataSystems::Instance().dataentry_dataentry_cow_card_description = "robot: " + QString::number(rand()%1000); //;// ui->textEdit_description->placeholderText();
        DataSystems::Instance().dataentry_dataentry_cow_card_transfer_in = "+";
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
                                  "animal_No,"
                                  "responder,"
                                  "name_,"
                                  "group_,"
                                  "life_number,"
                                  "present,"
                                  "birth_date,"
                                  "location_,"
                                  "label_,"
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
                          DataSystems::Instance().dataentry_dataentry_cow_card_animal_No + "', '" +
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

            db_func->insert_add("dataentry_cow_card", "animal_No", DataSystems::Instance().dataentry_dataentry_cow_card_animal_No);
            db_func->insert_add("dataentry_cow_card", "responder", DataSystems::Instance().dataentry_dataentry_cow_card_responder);
            db_func->insert_add("dataentry_cow_card", "name_", DataSystems::Instance().dataentry_dataentry_cow_card_name);
            db_func->insert_add("dataentry_cow_card", "group_", DataSystems::Instance().dataentry_dataentry_cow_card_group);
            db_func->insert_add("dataentry_cow_card", "life_number", DataSystems::Instance().dataentry_dataentry_cow_card_life_number);
            db_func->insert_add("dataentry_cow_card", "present", DataSystems::Instance().dataentry_dataentry_cow_card_present);
            db_func->insert_add("dataentry_cow_card", "birth_date", DataSystems::Instance().dataentry_dataentry_cow_card_birth_date);
            db_func->insert_add("dataentry_cow_card", "location_", DataSystems::Instance().dataentry_dataentry_cow_card_location);
            db_func->insert_add("dataentry_cow_card", "label_", DataSystems::Instance().dataentry_dataentry_cow_card_label);
            db_func->insert_add("dataentry_cow_card", "keep", DataSystems::Instance().dataentry_dataentry_cow_card_keep);
            db_func->insert_add("dataentry_cow_card", "gender", DataSystems::Instance().dataentry_dataentry_cow_card_gender);
            db_func->insert_add("dataentry_cow_card", "use_as_sire", DataSystems::Instance().dataentry_dataentry_cow_card_use_as_sire);
            db_func->insert_add("dataentry_cow_card", "father_life_number", DataSystems::Instance().dataentry_dataentry_cow_card_father_life_number);
            db_func->insert_add("dataentry_cow_card", "father_name", DataSystems::Instance().dataentry_dataentry_cow_card_father_name);
            db_func->insert_add("dataentry_cow_card", "mother_life_number", DataSystems::Instance().dataentry_dataentry_cow_card_mother_life_number);
            db_func->insert_add("dataentry_cow_card", "mother_name", DataSystems::Instance().dataentry_dataentry_cow_card_mother_name);
            db_func->insert_add("dataentry_cow_card", "hair_color", DataSystems::Instance().dataentry_dataentry_cow_card_hair_color);
            db_func->insert_add("dataentry_cow_card", "gestation", DataSystems::Instance().dataentry_dataentry_cow_card_gestation);
            db_func->insert_add("dataentry_cow_card", "calm", DataSystems::Instance().dataentry_dataentry_cow_card_calm);
            db_func->insert_add("dataentry_cow_card", "blood_type", DataSystems::Instance().dataentry_dataentry_cow_card_blood_type);
            db_func->insert_add("dataentry_cow_card", "percentage", DataSystems::Instance().dataentry_dataentry_cow_card_percentage);
            db_func->insert_add("dataentry_cow_card", "description", DataSystems::Instance().dataentry_dataentry_cow_card_description);
            QString sql__ = db_func->insert_add("dataentry_cow_card", "transfer_in", DataSystems::Instance().dataentry_dataentry_cow_card_transfer_in);

            //"----------" + "')";
            db_func->sql_exec(sql__, "add cow");
        }
    }

}

void Form_List_Cows::on_pushButton_delete_all_clicked()
{


    if(QMessageBox::question(0,"Удалить все записи","Не удалять: Уверены?",
                                  QMessageBox::No,QMessageBox::Yes)==QMessageBox::No)
    {
        return;

    }
    else{

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
            QString sql2=QString("TRUNCATE TABLE dataentry_cow_card;");
        db_func->sql_exec(sql2, "delete cow");
    }

    QMessageBox::information(this,"Успешно","Записи удалены");
    }

    GetData();
}


void Form_List_Cows::on_pushButton_addrandom_clicked()
{
    if(DataSystems::Instance().db_generate_random)addRandom();
    GetData();
}


void Form_List_Cows::on_lineEdit_cow_textChanged(const QString &arg1)
{


    QString sql =  QString("SELECT * FROM public.dataentry_cow_card ORDER BY id ASC ").toLower();
    sql =  QString("SELECT * FROM dataentry_cow_card WHERE animal_No LIKE '%"+arg1+"%' ORDER BY animal_No;");
    qDebug()<<"text: "<<sql;
    //return;

    ui->tableWidget_list_cows->clear();
    ui->comboBox_numbers->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
    //QString sql =  QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();

    //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
    //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
    //logger::WriteLog("SELECT vars: ----- " + sql);

    QSqlQuery* query = db_func->sql_exec2(sql);

    if(query->size()<1)return;

    ui->tableWidget_list_cows->clear();
    int i=0;

    QStringList NameColumns;
    NameColumns<<"Номер животного"<<"Ответчик"<<"Название"<<"Группа"<<"Номер жизни"<<"Представление"<<" "<<" ";

    ui->tableWidget_list_cows->setColumnCount( NameColumns.count() );
    ui->tableWidget_list_cows->setRowCount( query->size() );

    //ui->tableWidget_list_cows->setHorizontalHeaderItem(0, new QTableWidgetItem("История"));
    ui->tableWidget_list_cows->setHorizontalHeaderLabels( NameColumns );

    for(i=0;i<NameColumns.count();i++)ui->tableWidget_list_cows->setColumnWidth(i, 150);

    i=0;
    while(query->next())
    {
        ui->tableWidget_list_cows->setItem( i, 1,  new QTableWidgetItem( query->value("animal_No").toString() ));
        ui->comboBox_numbers->addItem(query->value("animal_No").toString());
        ui->tableWidget_list_cows->setItem( i, 2,  new QTableWidgetItem(query->value("responder").toString()));
        ui->tableWidget_list_cows->setItem( i, 3,  new QTableWidgetItem( query->value("name_").toString() ));
        ui->tableWidget_list_cows->setItem( i, 4,  new QTableWidgetItem( query->value("group_").toString() ));
        ui->tableWidget_list_cows->setItem( i, 5,  new QTableWidgetItem( query->value("life_number").toString() ));
        ui->tableWidget_list_cows->setItem( i, 6,  new QTableWidgetItem( query->value("present").toString() ));
        ui->tableWidget_list_cows->setItem( i, 7,  new QTableWidgetItem( query->value("birth_date").toString() ));
        ui->tableWidget_list_cows->setItem( i, 8,  new QTableWidgetItem( query->value("location_").toString() ));
        i++;
    }
    }

    checkAnimals = ui->tableWidget_list_cows->item(0,0)->text();
    qDebug()<<"search: "<<checkAnimals;

}


void Form_List_Cows::create_table_view()
{
    GetData();

    //connect(model, SIGNAL(AsyncSql::AsyncSqlTableModel::dataUpdated()), this, SLOT(createButton()));
    //createButton();
    //GetData();

    createPopupMenu_();
    connect(ui->tableWidget_list_cows, SIGNAL(onCreatePopupMenu(QMenu *)), SLOT(onCreateFooterMenu(QMenu *)));
    connect(&actSaveExcel, &QAction::triggered, this, &Form_List_Cows::onActSaveExcel);
    connect(&actSaveExcelXML, &QAction::triggered, this, &Form_List_Cows::onActSaveExcelXML);
    connect(&actSaveWordXML, &QAction::triggered, this, &Form_List_Cows::onActSaveWordXML);
    connect(&actSavePDF, &QAction::triggered, this, &Form_List_Cows::onActSavePDF);
    connect(&actSaveCSV, &QAction::triggered, this, &Form_List_Cows::onActSaveCSV);
    connect(&actSaveXML, &QAction::triggered, this, &Form_List_Cows::onActSaveXML);
    connect(&actSaveHTML, &QAction::triggered, this, &Form_List_Cows::onActSaveHTML);
    connect(&actSendToPrinter, &QAction::triggered, this, &Form_List_Cows::onActSendToPrinter);

    //connect(ui->tableWidget_list_cows->horizontalHeader(), SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showCustomContextMenu(const QPoint&)));
    connect(ui->tableWidget_list_cows->horizontalHeader(), SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showCustomContextMenu(const QPoint&)));

    //ui->textEdit->setText(text);
}

void Form_List_Cows::createPopupMenu_()
{
    popupMenu.clear();
    popupMenu.addAction(&actFilter);
    popupMenu.addAction(&actFilter);
    popupMenu.addAction(&actFilter);
    popupMenu.addAction(&actFilter);
    popupMenu.addAction(&actFilter);
    popupMenu.addAction(&actFilter);
    popupMenu.addAction(&actFilter);
    popupMenu.addAction(&actFilter);
    popupMenu.addAction(&actFilter);
    popupMenu.addSeparator();
    //QMenu *saveAsMenu = popupMenu.addMenu(QIcon(":/Resource/Images/save.png"), ("Преобразовать в  ..."));
    QMenu *saveAsMenu = popupMenu.addMenu(PBSTR("Transpose -> (EXCEL)Преобразовать в  ..."));
    saveAsMenu->addAction(&actSaveExcel);
    saveAsMenu->addAction(&actSaveExcelXML);
    saveAsMenu->addAction(&actSaveWordXML);
    //saveAsMenu->addSeparator();
    saveAsMenu->addAction(&actSavePDF);
    saveAsMenu->addAction(&actSaveCSV);
    saveAsMenu->addAction(&actSaveXML);
    saveAsMenu->addAction(&actSaveHTML);

    //popupMenu.addSeparator();
    //popupMenu.addAction(&actSaveLayout);

    emit onCreatePopupMenu(HeaderMenu, &popupMenu);
}


void Form_List_Cows::showCustomContextMenu(const QPoint &p)
{

    logger::WriteMsg("showCustomContextMenu");

    QPoint mP = mapToGlobal(p);
    //mP.setY(mP.y()-50);

    //int iCol = ui->tableWidget_list_cows->horizontalHeader()->logicalIndexAt(p),
    // iSort = ui->tableWidget_list_cows->horizontalHeader()->sortIndicatorSection();

    //actSortAsc.setChecked(iCol == iSort && ui->tableWidget_list_cows->horizontalHeader()->sortIndicatorOrder() == Qt::AscendingOrder);
    //actSortDesc.setChecked(iCol == iSort && ui->tableWidget_list_cows->horizontalHeader()->sortIndicatorOrder() == Qt::DescendingOrder);

    popupMenu.popup(mP);
}

void Form_List_Cows::onActSaveExcelXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
    QFile f(sName);
    f.open(QIODevice::ReadWrite);
    PBSTableViewExcelXMLExporter e(ui->tableWidget_list_cows, &f, this);
    e.execute();
    f.close();
    }
}

void Form_List_Cows::onActSaveWordXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
    QFile f(sName);
    f.open(QIODevice::ReadWrite);
    PBSTableViewWordXMLExporter e(ui->tableWidget_list_cows, &f, this);
    e.execute();
    f.close();
    }
}

void Form_List_Cows::onActSaveCSV()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
    QFile f(sName);
    f.open(QIODevice::ReadWrite);
    PBSTableViewCSVExporter e(ui->tableWidget_list_cows, &f, this);
    e.execute();
    f.close();
    }
}

void Form_List_Cows::onActSaveHTML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
    QFile f(sName);
    f.open(QIODevice::ReadWrite);
    PBSTableViewHTMLExporter e(ui->tableWidget_list_cows, &f, this);
    e.execute();
    f.close();
    }
}

void Form_List_Cows::onActSaveExcel()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
    PBSTableViewXLSXExporter e(ui->tableWidget_list_cows, sName, this);
    e.execute();
    }
}

void Form_List_Cows::onActSaveXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
    QFile f(sName);
    f.open(QIODevice::ReadWrite);
    PBSTableViewXMLExporter e(ui->tableWidget_list_cows, &f, this);
    e.execute();
    f.close();
    }
}

void Form_List_Cows::onActSavePDF()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
    PBSTableViewPDFExporter e(ui->tableWidget_list_cows, sName, this);
    e.execute();
    }
}

void Form_List_Cows::onActSendToPrinter()
{
    QPrinter printer(QPrinter::ScreenResolution);
    printer.setPaperSize(QPrinter::A4);
    printer.setFullPage(false);

    printer.setOrientation(QPrinter::Portrait);
    printer.setPageMargins(0, 0, 0, 0, QPrinter::Unit::Millimeter);
    printer.setResolution(96); // QApplication::screens().at(0)->logicalDotsPerInch());

    QPrintPreviewDialog d(&printer, reinterpret_cast<QWidget*>(parent()));
    d.setWindowFlags(Qt::Window | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);

    connect(&d, SIGNAL(paintRequested(QPrinter *)), this, SLOT(print(QPrinter *)));

    d.exec();
}

void Form_List_Cows::print(QPrinter *prn)
{
    QPainter painter;

    painter.begin(prn);

    PBSTablePrinter p(&painter, ui->tableWidget_list_cows, this);
    p.setPrinter(prn);

    p.setHeadersFont(ui->tableWidget_list_cows->horizontalHeader()->font());
    p.setContentFont(font());

    p.execute();
}



void Form_List_Cows::onCreateFooterMenu(QMenu *m)
{
    emit onCreatePopupMenu(FooterMenu, m);
}




