#include "form_list_cows.h"
#include "ui_form_list_cows.h"

#include "dataanimals.h"
#include "FormsMenu/Form_add_cow.h"
#include "Debug/logger.h"

Form_List_Cows::Form_List_Cows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_List_Cows)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);



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

    ui->pushButton_add->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    ui->pushButton_select->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    ui->pushButton_delete->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    ui->pushButton_add->setToolTip("Нажмите чтобы добавить новую корову ");
    ui->pushButton_select->setToolTip("Нажмите чтобы показать данные о выборанной корове ");


    //addRandom();
    //GetData();

    //AsyncSql::DatabaseConnection::setDefaultDatabaseName(QApplication::applicationDirPath()+"/"+ "example.db");
    AsyncSql::DatabaseConnection::setDefaultDriver(AsyncSql::DatabaseConnection::QPSQL);
    AsyncSql::DatabaseConnection::setDefaultHostName(DataSystems::Instance().db_host);
    AsyncSql::DatabaseConnection::setDefaultDatabaseName(DataSystems::Instance().db_name);
    AsyncSql::DatabaseConnection::setDefaultPort(DataSystems::Instance().db_port);
    AsyncSql::DatabaseConnection::setDefaultUserName(DataSystems::Instance().db_login);
    AsyncSql::DatabaseConnection::setDefaultPassword(DataSystems::Instance().db_password);
    TableName = "dataentry_cow_card";
    //OptionsDialog::setTableName("per_test");

    model = new AsyncSql::AsyncSqlTableModel(this);

    model->setTable(TableName);
    //model->setTable(OptionsDialog::getTableName());
    //ui->tableView->verticalHeader()->hide();                                                //Скрытие вертикального заголовка таблицы
    ui->tableView->setModel(model);
    model->select();
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    //connect(model, SIGNAL(AsyncSql::AsyncSqlTableModel::dataUpdated()), this, SLOT(createButton()));
    //createButton();
}

Form_List_Cows::~Form_List_Cows()
{
    delete ui;
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
                   " where animals =  '"+ checkAnimals + "';";
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

//    qDebug()<<"check: "<<checkAnimals;
//    for(i=0;i<ui->tableWidget_list_cows->rowCount();i++)
//    {
//        QString val;
//        QTableWidgetItem *item = ui->tableWidget_list_cows->item(i,0);
//        if (NULL != item) {
//            val = item->text();
//            if(checkAnimals.contains(val))
//            {
//                selectRow = i;
//                if(selectRowOld!=-1)for(int j=0;j<ui->tableWidget_list_cows->columnCount();j++)ui->tableWidget_list_cows->item(selectRowOld,j)->setBackground( Qt::white);
//                for(int j=0;j<ui->tableWidget_list_cows->columnCount();j++)ui->tableWidget_list_cows->item(selectRow,j)->setBackground( Qt::lightGray);
//                selectRowOld=selectRow;
//                //ui->lineEdit_cow->setText("ответчик: " + ui->tableWidget_list_cows->item(i,1)->text() );
//                qDebug()<<"--- break: "<<"i: "<<i<<"; "<<val;
//                break;
//            }
//            qDebug()<<"check: "<<checkAnimals<<"; "<<"i: "<<i<<"; "<<val;
//        }
//    }

}


void Form_List_Cows::GetData()
{
//    ui->tableWidget_list_cows->clear();
//    ui->comboBox_numbers->clear();

//    QScopedPointer<DataBase> db_func(new DataBase());
//    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
//    if(db_func->StatusOpen())
//    {
//        //QString sql =  QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();
//        QString sql =  QString("SELECT * FROM public.dataentry_cow_card ORDER BY id ASC ").toLower();
//        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
//        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
//        //logger::WriteLog("SELECT vars: ----- " + sql);

//        QSqlQuery* query = db_func->sql_exec2(sql);

//        if(query->size()<1)return;

//        ui->tableWidget_list_cows->clear();
//        int i=0;

//        QStringList NameColumns;
//        NameColumns<<"Номер животного"<<"Ответчик"<<"Название"<<"Группа"<<"Номер жизни"<<"Представление"<<" "<<" ";

//        ui->tableWidget_list_cows->setColumnCount( NameColumns.count() );
//        ui->tableWidget_list_cows->setRowCount( query->size() );

//        //ui->tableWidget_list_cows->setHorizontalHeaderItem(0, new QTableWidgetItem("История"));
//        ui->tableWidget_list_cows->setHorizontalHeaderLabels( NameColumns );

//        for(i=0;i<NameColumns.count();i++)ui->tableWidget_list_cows->setColumnWidth(i, 150);

//        i=0;
//        while(query->next())
//        {
//            ui->tableWidget_list_cows->setItem( i, 0,  new QTableWidgetItem( query->value("animal_No").toString() ));
//            ui->comboBox_numbers->addItem(query->value("animal_No").toString());
//            ui->tableWidget_list_cows->setItem( i, 1,  new QTableWidgetItem(query->value("responder").toString()));
//            ui->tableWidget_list_cows->setItem( i, 2,  new QTableWidgetItem( query->value("name_").toString() ));
//            ui->tableWidget_list_cows->setItem( i, 3,  new QTableWidgetItem( query->value("group_").toString() ));
//            ui->tableWidget_list_cows->setItem( i, 4,  new QTableWidgetItem( query->value("life_number").toString() ));
//            ui->tableWidget_list_cows->setItem( i, 5,  new QTableWidgetItem( query->value("present").toString() ));
//            ui->tableWidget_list_cows->setItem( i, 6,  new QTableWidgetItem( query->value("birth_date").toString() ));
//            ui->tableWidget_list_cows->setItem( i, 7,  new QTableWidgetItem( query->value("location_").toString() ));
//            i++;
//        }
//    }

//    /**/

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
                                  "animals,"
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
    qDebug()<<QString() + "void Form_List_Cows::on_lineEdit_cow_textChanged(const QString &arg1): "+arg1;
    logger::WriteMsg((QString() + "void Form_List_Cows::on_lineEdit_cow_textChanged(const QString &arg1): "+arg1).toStdString());
    model->setFilter(QString(" animal_No LIKE '%"+arg1+"%'"));
    model->select();
    ui->tableView->setModel(model);
    //sql =  QString("SELECT * FROM dataentry_cow_card WHERE animal_No LIKE '%"+arg1+"%' ORDER BY animals;");

    return;

    QString sql =  QString("SELECT * FROM public.dataentry_cow_card ORDER BY id ASC ").toLower();
    sql =  QString("SELECT * FROM dataentry_cow_card WHERE animals LIKE '%"+arg1+"%' ORDER BY animals;");
    qDebug()<<"text: "<<sql;
    //return;

//    ui->tableWidget_list_cows->clear();
//    ui->comboBox_numbers->clear();

//    QScopedPointer<DataBase> db_func(new DataBase());
//    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
//    if(db_func->StatusOpen())
//    {
//    //QString sql =  QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();

//    //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
//    //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
//    //logger::WriteLog("SELECT vars: ----- " + sql);

//    QSqlQuery* query = db_func->sql_exec2(sql);

//    if(query->size()<1)return;

//    ui->tableWidget_list_cows->clear();
//    int i=0;

//    QStringList NameColumns;
//    NameColumns<<"Номер животного"<<"Ответчик"<<"Название"<<"Группа"<<"Номер жизни"<<"Представление"<<" "<<" ";

//    ui->tableWidget_list_cows->setColumnCount( NameColumns.count() );
//    ui->tableWidget_list_cows->setRowCount( query->size() );

//    //ui->tableWidget_list_cows->setHorizontalHeaderItem(0, new QTableWidgetItem("История"));
//    ui->tableWidget_list_cows->setHorizontalHeaderLabels( NameColumns );

//    for(i=0;i<NameColumns.count();i++)ui->tableWidget_list_cows->setColumnWidth(i, 150);

//    i=0;
//    while(query->next())
//    {
//        ui->tableWidget_list_cows->setItem( i, 0,  new QTableWidgetItem( query->value("animal_No").toString() ));
//        ui->comboBox_numbers->addItem(query->value("animal_No").toString());
//        ui->tableWidget_list_cows->setItem( i, 1,  new QTableWidgetItem(query->value("responder").toString()));
//        ui->tableWidget_list_cows->setItem( i, 2,  new QTableWidgetItem( query->value("name_").toString() ));
//        ui->tableWidget_list_cows->setItem( i, 3,  new QTableWidgetItem( query->value("group_").toString() ));
//        ui->tableWidget_list_cows->setItem( i, 4,  new QTableWidgetItem( query->value("life_number").toString() ));
//        ui->tableWidget_list_cows->setItem( i, 5,  new QTableWidgetItem( query->value("present").toString() ));
//        ui->tableWidget_list_cows->setItem( i, 6,  new QTableWidgetItem( query->value("birth_date").toString() ));
//        ui->tableWidget_list_cows->setItem( i, 7,  new QTableWidgetItem( query->value("location_").toString() ));
//        i++;
//    }
//    }

//    checkAnimals = ui->tableWidget_list_cows->item(0,0)->text();
//    qDebug()<<"search: "<<checkAnimals;



}

