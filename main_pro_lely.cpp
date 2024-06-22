#include "main_pro_lely.h"
#include "ui_main_pro_lely.h"
#include "debug/logger.h"

#include "FormsMenu/form_1_1.h"
#include "FormsMenu/form_1_2.h"
#include "FormsMenu/form_1_2_general.h"
#include "FormsMenu/form_dataentry_settings.h"
#include "FormsMenu/form_analyse_reports___reports.h"

#include "form_2_1.h"
#include "form_in_work.h"


#include "dataanimals.h"
#include "db/SqlDataBase.h"

#include "./json/json_w.h"

#include "FormsMenu/formlibrary_1_9.h"

#include <memory>
#include <QScopedPointer>


Main_pro_lely::Main_pro_lely(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //***************** Инициализация ****************************//

    //***************** Осчистка логов отладки и дефолтная установка значений параметров системы (БД, наименований, таблиц) ****************************//
    logger::ClearLog();
    DataSystems::Instance().clear();
    //***************** End Осчистка логов отладки и дефолтная установка значений параметров системы (БД, наименований, таблиц) ****************************//

    setWindowTitle("ВИМ");

    //***************** Установка белого цвета приложения и размеров ****************************//
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    setGeometry(QRect(200, 100, 1600, 800));
    //***************** End Установка белого цвета приложения и размеров ****************************//

    //*****************  Стили отображения groupbox ****************************//
    ui->widget_title->setStyleSheet("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 "+DataSystems::Instance().settings___color_header+", stop:1 "+DataSystems::Instance().settings___color_header+");"
                                    "foreground: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #FFFFFF, stop:1 #FFFFFF);");
    ui->widget_title_2->setStyleSheet("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 "+DataSystems::Instance().settings___color_header+", stop:1 "+DataSystems::Instance().settings___color_header+");"
                                    "foreground: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #FFFFFF, stop:1 #FFFFFF);");    
    //***************** End Стили отображения groupbox ****************************//

    //***************** Основное приложение ****************************//

    //***************** Загрузка меню в левую панель ****************************//
    w_m = new Widget_menu();
    ui->verticalLayout->addWidget(w_m);
    //***************** End Загрузка меню в левую панель ****************************//


    //***************** Загрузка главного окна в правую панель ****************************//
    //Form_2_1 *w_f_2_1 = new Form_2_1();
    Form_in_work *fm_ = new Form_in_work;
    ui->verticalLayout_2->addWidget(fm_);
    //***************** End Загрузка главного окна в правую панель ****************************//

    //***************** Назначение событий нажатия на пункты меню (связь событий между виджетами меню в левой панели и его действием виджетом в правом меню ) ****************************//
    connect(this, &Main_pro_lely::signal, w_m, &Widget_menu::slot);
    connect(w_m, &Widget_menu::signalMenu, this, &Main_pro_lely::slotMenu);
    //***************** End Назначение событий нажатия на пункты меню (связь событий между виджетами меню в левой панели и его действием виджетом в правом меню ) ****************************//

    QTimer::singleShot(100, this, SLOT(InitDBautorization()));
}

//*****************  Функция обработки авторизации в системе - если нажата кнопка выход то выход из приложения, если вход то работа с приложением ****************************//

//void Main_pro_lely::Exit(){}

void Main_pro_lely::InitDBautorization()
{    
    AutorizationDialog autorization(this);
    if(!(autorization.exec()==QDialog::Accepted)){
        if(DataSystems::Instance().exit_application)
        {
            QMessageBox::information(this,"Спасибо","Вы вышли из системы");
            QApplication::closeAllWindows();
            QApplication::quit();
        }
        else{

            /**/

            create();
        }
    }
}
//***************** End Функция обработки авторизации в системе - если нажата кнопка выход то выход из приложения, если вход то работа с приложением ****************************//

//***************** Функция инициализации работы с базой данных - конфигурирование таблиц, заполнение уставками ****************************//
void Main_pro_lely::create()
{
    logger::WriteMsg("json_w::CreateJsonVarTab()");

    json_w::CreateJsonVarTab();

    SqlDataBase::DropTables();
    SqlDataBase::DropDataBase(DataSystems::Instance().db_name.toStdString());
    SqlDataBase::UseDataBase("Use "+DataSystems::Instance().db_name.toStdString()+";");
    SqlDataBase::CreateDataBase(DataSystems::Instance().db_name.toStdString());
    SqlDataBase::CreateTables();
    SqlDataBase::AllTablesInsert();
    SqlDataBase::DropTables();
    SqlDataBase::TablesUpdate();
    SqlDataBase::DropDataBase(DataSystems::Instance().db_name.toStdString());
    qDebug()<<"Default Postgresql database ";

    //DataSystems::Instance().db = new DataBase();
    {

        QScopedPointer<DataBase> db_func(new DataBase());
        //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
        if(db_func->StatusOpen())
        {


            {
                QScopedPointer<DataBase> db_func_sqlite_autorization(new DataBase("sqlite"));
                //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
                if(db_func_sqlite_autorization->StatusOpenSQLite())
                {
                    logger::WriteMsg("Save data user autorization ");


                    /*

                        db_func_sqlite_autorization->sql_exec("DROP TABLE LocalSettings;");
                    db_func_sqlite_autorization->sql_exec("CREATE TABLE [LocalSettings] ( [ParameterValue] NVARCHAR(512), [id] INTEGER PRIMARY KEY NOT NULL, [ParameterName] NVARCHAR(32) UNIQUE );");

                        db_func_sqlite_autorization->sql_exec("DROP TABLE autorization_local_data;");
                        db_func_sqlite_autorization->sql_exec("CREATE TABLE IF NOT EXISTS  autorization_local_data"
                                          "(ID INTEGER PRIMARY KEY   AUTOINCREMENT, "
                                          "hostname text,"
                                          "db_name text,"
                                          "port text,"
                                          "login_ text,"
                                          "password_ text,"
                                          "date_ text,"
                                          "param text"
                                          ")+");
                    /**/
                        QDateTime dt1 = QDateTime::currentDateTime();
                        QString time_ = dt1.toString("yyyy-MM-dd hh:mm:ss.ms");
                        //QString sql_update = db_func_sqlite_autorization->update_add("autorization_local_data", "login_", DataSystems::Instance().db_login, "date_", dt1.toString("yyyy-MM-dd hh:mm:ss.ms"));

                        db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->UpdateParameter("hostname", DataSystems::Instance().db_host));
                        db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->UpdateParameter("db_name", DataSystems::Instance().db_name));
                        db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->UpdateParameter("db_port", QString::number(DataSystems::Instance().db_port)));
                        db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->UpdateParameter("db_login", DataSystems::Instance().db_login));
                        db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->UpdateParameter("db_password", DataSystems::Instance().db_password));
                        db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->UpdateParameter("date_work", time_));

                }

            }



        if(DataSystems::Instance().db_check_create)
        {
            logger::WriteMsg("create new table -------------------- ");
            db_func->DropTables();
            db_func->createTables();
            //db_func->FillValue();

            db_func->sql_exec("DROP TABLE DataService;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  DataService"
                         "(id BIGSERIAL PRIMARY KEY, "
                         "db_type text,"
                         "db_host text,"
                         "db_port text,"
                         "db_name text,"
                         "db_sqlite_file text,"

                         "db_login text,"
                         "db_password text,"
                         "data_work text,"

                         "data_farmdepart text,"
                         "data_country text,"
                         "data_language text,"
                         "data_culture text,"
                         "data_index text,"
                         "data_street text,"
                         "data_street_number text,"
                         "data_zip_code text,"
                         "data_city text,"
                         "data_telephone text,"
                         "data_owner_name text)");
            qDebug()<<"Create Dataservice ";


            db_func->sql_exec("DROP TABLE dataentry_library;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_library"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "siries_number text,"
                              "siries_life_number text,"
                              "siries_sire_code text,"
                              "siries_active text,"
                              "feed_types_number_feed_types text,"
                              "feed_types_dry_matter text,"
                              "feed_types_name text,"
                              "feed_types_active text,"
                              "feed_types_type text,"
                              "feed_types_remark text"
                              ")");

            db_func->sql_exec("DROP TABLE dataentry_cow_card;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_cow_card"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "animals text,"
                              "responder text,"
                              "name_ text,"
                              "group_ text,"
                              "life_number text,"
                              "present text,"
                              "birth_date text,"
                              "location_ text,"
                              "label_ text,"
                              "keep text,"
                              "gender text,"
                              "use_as_sire text,"
                              "father_life_number text,"
                              "father_name text,"
                              "mother_life_number text,"
                              "mother_name text,"
                              "hair_color text,"
                              "gestation text,"
                              "calm text,"
                              "blood_type text,"
                              "percentage text,"
                              "description text,"
                              "transfer_in text"
                              ")");


            db_func->sql_exec("DROP TABLE dataentry_transfer;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_transfer"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "animal_No text,"                              
                              "Robot_No text,"
                              "lactation_No text,"
                              "lactation_days text,"
                              "days_pregnant text,"
                              "present text"
                              ")");


            db_func->sql_exec("DROP TABLE dataentry_otel;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_otel"
              "(id BIGSERIAL PRIMARY KEY, "
            "animal_No text,"
            "number text,"
            "Robot_No text,"
            "lactation_No text,"
            "lactation_days text,"
            "days_pregnant text,"
            "lactation_production text,"
            "average_lactation text,"
            "average_refusals text,"
            "average_falures text,"
            "average_milk_speed text,"
            // расширенные
            "current_location text," // 1 calving
            "days_dry text,"
            "waiting_time_dry_off text,"
            "remarks_previous text,"
            "expected_calving text,"
            "calving_date text,"
            "waiting_time_colostrum text,"
            "number_of_calves text,"
            "remarks text,"
            "group_ text,"
            "cow_number text,"
            "responder text,"
            "teat text,"
            "separation_milk_tank text,"
            "calf_born_dead text," // 2 calf 1
            "calf_keep_calf text,"
            "calf_calf_number text,"
            "calf_life_number text,"
            "calf_name text,"
            "calf_weight text,"
            "calf_sex text,"
            "calf_hair_color text,"
            "calf_group text"
            ")", "create table");


            db_func->sql_exec("DROP TABLE dataentry_milk_separation;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_milk_separation"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "animal_No text,"
                              "Robot_No text,"
                              "lactation_No text,"
                              "lactation_days text,"
                              "milk_separation_type text,"
                              "milk_separation_tank text,"
                              "end_date text,"
                              "milk_separation_status text,"
                              "start_separation_y text,"
                              "start_separation_h text,"
                              "end_separation_y text,"
                              "end_separation_h text,"
                              "expected_dry text"
                              ")", "create table");


            db_func->sql_exec("DROP TABLE dataentry_insemenation;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_insemenation"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "animal_No text,"
                              "Robot_No text,"
                              "lactation_No text,"
                              "lactation_days text,"
                              "since_insemenation text,"
                              "insemenation_number text,"
                              "day_production text,"
                              "Activity text,"
                              "days_since_heat text,"
                              "expected_otel text,"
                              "type text,"
                              "date text,"
                              "sire text,"
                              "person text,"
                              "group_ text,"
                              "remarks text"
                              ")", "create table");

            db_func->sql_exec("DROP TABLE dataentry_dry_off;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_dry_off"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "animal_No text,"
                              "Robot_No text,"
                              "lactation_No text,"
                              "lactation_days text,"
                              "days_pregnant text,"
                              "day_production text,"
                              "total_day text,"
                              "udder_health_add text,"
                              "udder_health_add_count text,"
                              "date text,"
                              "medicine_used text,"
                              "medicine_category text,"
                              "medicine text,"
                              "dosage text,"
                              "Teat_LF text,"
                              "Teat_RF text,"
                              "Teat_LR text,"
                              "Teat_RR text,"
                              "separate_meat_untill text,"
                              "separate_milk_untill text,"
                              "group_ text"
                              ")", "create table");


            db_func->sql_exec("DROP TABLE dataentry_milk_settings;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_milk_settings"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "animal_No text,"
                              "Robot_No text,"
                              "lactation_No text,"
                              "lactation_days text,"
                              "priority_feeding text,"
                              "milk_teat_lf text,"
                              "milk_teat_lr text,"
                              "milk_teat_rf text,"
                              "milk_teat_rr text,"
                              "milk_under_supervision text,"
                              "training_period text"
                              ")", "create table");

            db_func->sql_exec("DROP TABLE dataentry_fixed_feeding;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_fixed_feeding"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "animal_No text,"
                              "name text,"
                              "group_ text,"
                              "days_in text,"
                              "days_feed text,"
                              "milk_yield text,"
                              "mb_markant text,"
                              "mb_focus text,"
                              "transition text"
                              ")", "create table");



            db_func->sql_exec("DROP TABLE dataentry_routing;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_routing"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "animal_No text,"
                              "Robot_No text,"
                              "lactation_No text,"
                              "lactation_days text,"
                              "area text,"
                              "from_date text,"
                              "till_date text,"
                              "from_till_time text,"
                              "active_routing text"
                              ")", "create table");




            db_func->sql_exec("DROP TABLE dataentry_library_feed_types;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_library_feed_types"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "number_feed_types text,"
                              "dry_matter text,"
                              "types_name text,"
                              "types_active text,"
                              "types_type text,"
                              "types_remark text"
                              ")", "create table");


            db_func->sql_exec("DROP TABLE dataentry_library_batch_transfer;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_library_batch_transfer"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "animal_No text,"
                              "responder text,"
                              "life_number text,"
                              "birth_date text,"
                              "location text,"
                              "calving_date text,"
                              "insemenation_date text"
                              ")", "create table");

            db_func->sql_exec("DROP TABLE dataentry_library_siries;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_library_siries"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "number text,"
                              "sire_name text,"
                              "life_number text,"
                              "sire_code text,"
                              "active text"
                              ")", "create table");



            db_func->sql_exec("DROP TABLE dataentry_settings____milking__general_milking;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_settings____milking__general_milking"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "colostrum_day text,"
                              "milk_destination text,"
                              "separation_milk_destination text,"
                              "milk_teat_lf text,"
                              "milk_teat_lr text,"
                              "milk_teat_rf text,"
                              "milk_teat_rr text,"
                              "reset_teat_coordinates_aftre_dry text,"
                              "training_period text,"
                              "milk_under_supervision text,"
                              "optimal_sampling_period text,"
                              "teat_position_known text,"
                              "correction_time text,"
                              "alternative_connection_method text"
                              ")", "create table");


            db_func->sql_exec("DROP TABLE dataentry_settings____milking__post_milking;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_settings____milking__post_milking"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "number_of_treatments_lf text,"
                              "number_of_treatments_lr text,"
                              "number_of_treatments_rf text,"
                              "number_of_treatments_rr text,"
                              "duration_per_treatment_lf text,"
                              "duration_per_treatment_lr text,"
                              "duration_per_treatment_rf text,"
                              "duration_per_treatment_rr text,"
                              "sampling text,"
                              "clean_milk_equipment text,"
                              "priority_feeding text"
                              ")", "create table");

            db_func->sql_exec("DROP TABLE dataentry_robot;");
            db_func->sql_exec("CREATE TABLE IF NOT EXISTS  dataentry_robot"
                              "(id BIGSERIAL PRIMARY KEY, "
                              "Robot_No text,"
                              "paramfile1 bytea,"
                              "paramfile2 bytea,"
                              "coord_teat_lf text,"
                              "coord_teat_lr text,"
                              "coord_teat_rf text,"
                              "coord_teat_rr text,"
                              "param1 text,"
                              "param2 text,"
                              "param3 text,"
                              "param4 text,"
                              "paramtime1 text,"
                              "paramtime2 text,"
                              "paramtime3 text,"
                              "paramtime4 text"
                              ")", "create table");

        }

    }
    else
    {
        QMessageBox::information(this,"Неверные параметры связи","Вы вышли из системы");
        QApplication::closeAllWindows();
        QApplication::quit();
    }
    }

    //logger::WriteMsg("Main_pro_lely before - SaveAutorizartion() - closed db : ~DataBase");

    //QThread::msleep(100);

    SaveAutorizartion();
}
//***************** End Функция инициализации работы с базой данных - конфигурирование таблиц, заполнение уставками ****************************//

//***************** Поиск последней записи входа пользователя в систему ****************************//
void Main_pro_lely::GetLastId()
{
    //QString parameterID = ui->tableView->model()->headerData(0, Qt::Horizontal).toString();
    QString sql = "SELECT id FROM DataService ORDER BY  id  DESC LIMIT 1;";
    QScopedPointer<DataBase> db_func(new DataBase());
    QSqlQuery* query = db_func->sql_exec2(sql);
    //logger::WriteMsg("GetNameTables();");

    //logger::WriteMsg(sql.toStdString());

    while(query->next())
    {
       DataSystems::Instance().DataService_Id= query->value(0).toInt();
    }
}
//***************** End Поиск последней записи входа пользователя в систему ****************************//

//***************** Поиск записи последнего входа пользователя в систему ****************************//
void Main_pro_lely::GetUserId()
{
    QString sql = "SELECT * FROM DataService where db_login ='" + DataSystems::Instance().db_login +"';";
    QScopedPointer<DataBase> db_func(new DataBase());
    QSqlQuery* query = db_func->sql_exec2(sql);

    DataSystems::Instance().DataService_Id = -1;

    while(query->next())
    {
       DataSystems::Instance().DataService_Id= query->value("id").toInt();
       logger::WriteMsg(QString("query->value(id) id: ").toStdString()+ QString::number(query->value("id").toInt()).toStdString());
    }
}
//***************** End Поиск записи последнего входа пользователя в систему ****************************//


//***************** Сохранение в базе данных записи об авторизации ****************************//
void Main_pro_lely::SaveAutorizartion()
{
    GetUserId();

    logger::WriteMsg("-----------  id: "+QString::number(DataSystems::Instance().DataService_Id).toStdString());

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {

       QString tab = "DataService";
       QString parameterId = "id";
       QString valueId = QString::number(DataSystems::Instance().DataService_Id);

        db_func->update_add(tab, parameterId, valueId, "db_type",((DataSystems::Instance().db_check ==  DB_check::PGSQL)?"postgresql":"sqlite"));
        db_func->update_add(tab, parameterId, valueId, "data_work", QString::fromStdString(datetime::utcExample()));
        db_func->update_add(tab, parameterId, valueId, "db_port", QString::number(DataSystems::Instance().db_port));
        db_func->update_add(tab, parameterId, valueId, "db_host", DataSystems::Instance().db_host);
        db_func->update_add(tab, parameterId, valueId, "db_sqlite_file", DataSystems::Instance().db_sqlite_file);
        db_func->update_add(tab, parameterId, valueId, "db_name", DataSystems::Instance().db_name);
        db_func->update_add(tab, parameterId, valueId, "db_login", DataSystems::Instance().db_login);
        QString sql_update=db_func->update_add(tab, parameterId, valueId, "db_password", DataSystems::Instance().db_password);


        db_func->insert_add(tab, "db_port", QString::number(DataSystems::Instance().db_port));
        db_func->insert_add(tab, "db_host", DataSystems::Instance().db_host);
        db_func->insert_add(tab, "db_sqlite_file", DataSystems::Instance().db_sqlite_file);
        db_func->insert_add(tab, "db_name", DataSystems::Instance().db_name);
        db_func->insert_add(tab, "db_login", DataSystems::Instance().db_login);
        QString sql_insert=db_func->insert_add(tab, "db_password", DataSystems::Instance().db_password);

        if(DataSystems::Instance().DataService_Id == -1)
        {           
            db_func->sql_exec(sql_insert);
        }
        else{           
           //db_func->sql_exec(sql_update);
            db_func->sql_exec(sql_insert);
        }
    }
    if(DataSystems::Instance().DataService_Id == -1)GetLastId();

    //logger::WriteMsg("-----------  id: "+QString::number(DataSystems::Instance().DataService_Id).toStdString());

}
//***************** End Сохранение в базе данных записи об авторизации ****************************//

//***************** slot для отработки сигнала по нажатию на дерево меню ****************************//
void Main_pro_lely::slotMenu(QString val)
{
    QLayoutItem *child = ui->verticalLayout_2->takeAt(0);
    //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)

        if(!child) {return;}
        QWidget* w = child->widget();

        delete child;
        if(!w) {return;}
        ui->verticalLayout_2->removeWidget(w); //удаляем предыдущий виджет
        delete w;
        //child = ui->verticalLayout_2->takeAt(0);               

    //************************************************************

        if(!CollectionAction.contains(val)){
            CollectionAction.insert(val, new QWidget(this));
            logger::WriteMsg("Action button <<<TREE ITEM>>> treeview: "+val.toStdString());
        }
        //Загрузка виджетов по нажатию на ветку дерева

        QWidget *fm;
        if(val.contains("Начало"))
        {
                 fm = new Form_2_1;
            qDebug()<<"Начало работает";
        }
        else if(val.contains("Глобальные установки фермы"))
        {
                 fm = new Form_1_1;
        }
        else if(val.contains("Дневная запись"))
        {
                 fm = new Form_1_2;
        }
        else if(val.contains("Библиотеки"))
        {
                 fm = new FormLibrary_1_9;
        }

        else if(val.contains("Группы"))
        {
                 //fm = new Form_1_2_General;
                 fm = new Form_in_work;

        }
        else if(val.contains("Настройки"))
        {
                 fm = new Form_DataEntry_Settings;
        }
        else if(val.contains("Доклады"))
        {
                 fm = new Form_analyse_reports___reports;
        }
        else
        {
           //fm = new Form_1_2_General;
           fm = new Form_in_work;
        }

        ui->verticalLayout_2->addWidget(fm);

}
//***************** End slot для отработки сигнала по нажатию на дерево меню ****************************//

Main_pro_lely::~Main_pro_lely()
{
    //if(DataSystems::Instance().db!=nullptr) DataSystems::Instance().db->closeDataBase();
    delete ui;
}


//***************** Вход в панель настройки администратора ****************************//
void Main_pro_lely::on_action_triggered()
{
    return;
    //admin = new mainWidget;
    admin2 = new AdminWidget(this);
    admin2->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);
    //admin2->setWindowModality(Qt::WindowModality::WindowModal);
    //admin2->setmo;
    admin2->show();

}
//***************** End Вход в панель настройки администратора ****************************//

