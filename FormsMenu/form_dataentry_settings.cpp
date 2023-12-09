#include "form_dataentry_settings.h"
#include "ui_form_dataentry_settings.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "json/json_w.h"

#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>
#include <QStringListModel>

#include "dataanimals.h"


//1. Навигатор: Ввод данных 2. Меню: Настройки

//1. Навигатор: Ввод данных 2. Меню: Настройки 3. Подменю: Кормления  4. Вкладка: Таблицы кормлени


Form_DataEntry_Settings::Form_DataEntry_Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_DataEntry_Settings)
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




ui->tabWidget->setStyleSheet("QTabWidget"
"{"
"   background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
"}"

"QTabWidget:tab-bar"
"{"
"    alignment: center;"
"}"

"QTabBar:tab"
"{"
"   width: 210px;"
"   height: 30px;"
"}"

"QTabBar:selected"
"{"
"    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
"    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
"}"

"QTabBar:tab:!selected"
"{"
"    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
"}"


"QTabBar:tab:!selected:hover"
"{"
"    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
"    color.rgb(255,255,255);"
"}"
")");

    ui->tabWidget_2->setStyleSheet("QTabWidget"
                                 "{"
                                 "   background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabWidget:tab-bar"
                                                                                               "{"
                                                                                               "    alignment: center;"
                                                                                               "}"

                                                                                               "QTabBar:tab"
                                                                                               "{"
                                                                                               "   width: 210px;"
                                                                                               "   height: 30px;"
                                                                                               "}"

                                                                                               "QTabBar:selected"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabBar:tab:!selected"
                                                                                               "{"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"


                                                                                               "QTabBar:tab:!selected:hover"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb(255,255,255);"
                                                                                               "}"
                                                                                               ")");


    ui->tabWidget_3->setStyleSheet("QTabWidget"
                                 "{"
                                 "   background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabWidget:tab-bar"
                                                                                               "{"
                                                                                               "    alignment: center;"
                                                                                               "}"

                                                                                               "QTabBar:tab"
                                                                                               "{"
                                                                                               "   width: 210px;"
                                                                                               "   height: 30px;"
                                                                                               "}"

                                                                                               "QTabBar:selected"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabBar:tab:!selected"
                                                                                               "{"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"


                                                                                               "QTabBar:tab:!selected:hover"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb(255,255,255);"
                                                                                               "}"
                                                                                               ")");


    ui->tableWidget_feeding___feed_tables->setStyleSheet("QTabWidget"
                                 "{"
                                 "   background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabWidget:tab-bar"
                                                                                               "{"
                                                                                               "    alignment: center;"
                                                                                               "}"

                                                                                               "QTabBar:tab"
                                                                                               "{"
                                                                                               "   width: 210px;"
                                                                                               "   height: 30px;"
                                                                                               "}"

                                                                                               "QTabBar:selected"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabBar:tab:!selected"
                                                                                               "{"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"


                                                                                               "QTabBar:tab:!selected:hover"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb(255,255,255);"
                                                                                               "}"
                                                                                               ")");



    ui->pushButton->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );

    ui->treeView->setWindowTitle("Стадо");

    QStringListModel *m_qlist_model = new QStringListModel();
    QStringList list;
    list<<(QString("1) 100 production"));
    list<<(QString("2) 10 production"));
    list<<(QString("3) Стерильный"));
    list<<(QString("4) Нагрев "));
    list<<(QString("5) 20 production "));
    list<<(QString("6) 10 production "));
    list<<(QString("7) 40 production "));
    list<<(QString("8) 50 production "));
    list<<(QString("9) 80 production "));
    list<<(QString("10) 90 production "));

    m_qlist_model->setStringList(list);

    ui->treeView->setModel(m_qlist_model);
    ui->treeView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);


    create_feeding___feed_tables();

    //addRandom__milking__general_milking();
    //GetData__milking__general_milking();

    if(DataSystems::Instance().db_generate_random)addRandom__milking__post_milking();
    GetData__milking__post_milking();
}

void Form_DataEntry_Settings::create_feeding___feed_tables()
{
    ui->tableWidget_feeding___feed_tables->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableWidget_feeding___feed_tables->clear();
    //auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

    //QMap<QString, QString> allColumns = json_w::form_table("table_form_1_2_bf.json");
    //QList<QString> allColumns = json_w::form_table2("table_form_1_9_series.json");

    QStringList NameColumns;
    NameColumns<<" "<<"Добавочный корм";
    //int i=0;


    ui->tableWidget_feeding___feed_tables->setColumnCount( 2 );
    for(int i=0;i<2;i++)ui->tableWidget_feeding___feed_tables->setColumnWidth(i, 250);

    ui->tableWidget_feeding___feed_tables->setRowCount( 10 );

    ui->tableWidget_feeding___feed_tables->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
    ui->tableWidget_feeding___feed_tables->setHorizontalHeaderLabels( NameColumns );
    //ui->tableWidget_feeding___feed_tables->horizontalHeader()->setStretchLastSection(true);

    //ui->tableWidget_feeding___feed_tables->hideColumn(0);

    for(int i=0;i<3;i++)
    {
        QTableWidgetItem *widgetitem =  new QTableWidgetItem("feed "+QString::number(i*10));
        //if(i==5)widgetitem->setBackground(Qt::gray);
        //else widgetitem->setBackground(Qt::green);
         ui->tableWidget_feeding___feed_tables->setItem( i, 0,  new QTableWidgetItem("feed "+QString::number(i*10)));
        if(i==5)ui->tableWidget_feeding___feed_tables->item(i,0)->setBackground( Qt::gray);


            QPushButton *pushButton_show_all = new QPushButton();
            pushButton_show_all->installEventFilter(this);
            pushButton_show_all->setText("Показать");
            ui->tableWidget_feeding___feed_tables->setCellWidget(i,1,pushButton_show_all);

            //ui->tableWidget->setItem( i, 3,  new QTableWidgetItem(QDate().currentDate().toString()));
    }    
}


void Form_DataEntry_Settings::create_feeding___access_milk()
{

}




Form_DataEntry_Settings::~Form_DataEntry_Settings()
{
    delete ui;
}

void Form_DataEntry_Settings::on_pushButton_clicked()
{
    QMessageBox::information(this,"Спасибо","Сохранеы данные");    
}


void Form_DataEntry_Settings::addRandom__milking__general_milking()
{
    for(int i=0;i<1;i++)
    {

            DataSystems::I().dataentry_settings____milking__general_milking__colostrum_day = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_destination = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__separation_milk_destination = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_lf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_lr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_rf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_rr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__reset_teat_coordinates_aftre_dry = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__training_period = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_under_supervision = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__optimal_sampling_period = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__teat_position_known = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__correction_time = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__alternative_connection_method = QString::number(rand()%100);

            QScopedPointer<DataBase> db_func(new DataBase());
            if(db_func->StatusOpen())
            {
                QString tab = "dataentry_settings____milking__general_milking";
                db_func->insert_add(tab, "colostrum_day", DataSystems::I().dataentry_settings____milking__general_milking__colostrum_day);
                db_func->insert_add(tab, "milk_destination", DataSystems::I().dataentry_settings____milking__general_milking__milk_destination);
                db_func->insert_add(tab, "separation_milk_destination", DataSystems::I().dataentry_settings____milking__general_milking__separation_milk_destination);
                db_func->insert_add(tab, "milk_teat_lf", DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_lf);
                db_func->insert_add(tab, "milk_teat_lr", DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_lr);
                db_func->insert_add(tab, "milk_teat_rf", DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_rf);
                db_func->insert_add(tab, "milk_teat_rr", DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_rr);
                db_func->insert_add(tab, "reset_teat_coordinates_aftre_dry", DataSystems::I().dataentry_settings____milking__general_milking__reset_teat_coordinates_aftre_dry);
                db_func->insert_add(tab, "training_period", DataSystems::I().dataentry_settings____milking__general_milking__training_period);
                db_func->insert_add(tab, "milk_under_supervision", DataSystems::I().dataentry_settings____milking__general_milking__milk_under_supervision);
                db_func->insert_add(tab, "optimal_sampling_period", DataSystems::I().dataentry_settings____milking__general_milking__optimal_sampling_period);
                db_func->insert_add(tab, "teat_position_known", DataSystems::I().dataentry_settings____milking__general_milking__teat_position_known);
                db_func->insert_add(tab, "correction_time", DataSystems::I().dataentry_settings____milking__general_milking__correction_time);
                QString sql_insert = db_func->insert_add(tab, "alternative_connection_method", DataSystems::I().dataentry_settings____milking__general_milking__alternative_connection_method);

                //"----------" + "')";
                db_func->sql_exec(sql_insert, "add milking__general_milking");
            }
    }

}

void Form_DataEntry_Settings::GetData__milking__general_milking()
{
    ui->tableWidget_general_milking->clear();
    QString tab = "dataentry_settings____milking__general_milking";

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
            QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
            QSqlQuery* query = db_func->sql_exec2(sql);
            if(query->size()<1)return;
            int i=0;

            auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget_general_milking);
            ui->tableWidget_general_milking->setRowCount( 1 );
            ui->tableWidget_general_milking->setHorizontalHeaderItem(0, new QTableWidgetItem("Общее доение"));

            for(int i=0;i<ui->tableWidget_general_milking->columnCount();i++)ui->tableWidget_general_milking->setColumnWidth(i, 150);
            //ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
            //ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
            //ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);

            i=0;
            while(query->next())
            {
                QCheckBox *checkbox = new QCheckBox();
                checkbox->installEventFilter(this);
                checkbox->setText("");
                checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
                ui->tableWidget_general_milking->setCellWidget(i,0,checkbox);

                ui->tableWidget_general_milking->setItem( i, 1,  new QTableWidgetItem( query->value("colostrum_day").toString() ));
                ui->tableWidget_general_milking->setItem( i, 2,  new QTableWidgetItem( query->value("milk_destination").toString() ));
                ui->tableWidget_general_milking->setItem( i, 3,  new QTableWidgetItem( query->value("separation_milk_destination").toString() ));
                ui->tableWidget_general_milking->setItem( i, 4,  new QTableWidgetItem( query->value("milk_teat_lf").toString() ));
                ui->tableWidget_general_milking->setItem( i, 5,  new QTableWidgetItem( query->value("milk_teat_lr").toString() ));
                ui->tableWidget_general_milking->setItem( i, 6,  new QTableWidgetItem( query->value("milk_teat_rf").toString() ));
                ui->tableWidget_general_milking->setItem( i, 7,  new QTableWidgetItem( query->value("milk_teat_rr").toString() ));
                ui->tableWidget_general_milking->setItem( i, 8,  new QTableWidgetItem( query->value("reset_teat_coordinates_aftre_dry").toString() ));
                ui->tableWidget_general_milking->setItem( i, 9,  new QTableWidgetItem( query->value("training_period").toString() ));
                ui->tableWidget_general_milking->setItem( i, 10,  new QTableWidgetItem( query->value("milk_under_supervision").toString() ));
                ui->tableWidget_general_milking->setItem( i, 11,  new QTableWidgetItem( query->value("optimal_sampling_period").toString() ));
                ui->tableWidget_general_milking->setItem( i, 12,  new QTableWidgetItem( query->value("teat_position_known").toString() ));
                ui->tableWidget_general_milking->setItem( i, 13,  new QTableWidgetItem( query->value("correction_time").toString() ));
                ui->tableWidget_general_milking->setItem( i, 14,  new QTableWidgetItem( query->value("alternative_connection_method").toString() ));

                ui->tableWidget_general_milking->insertRow( ui->tableWidget_general_milking->rowCount() );
                i++;
            }
    }


    /**/

}


void Form_DataEntry_Settings::addRandom__milking__post_milking()
{
    for(int i=0;i<3;i++)
    {
            DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_lf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_lr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_rf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_rr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_lf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_lr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_rf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_rr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__clean_milk_equipment = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__priority_feeding = QString::number(rand()%100);

            QScopedPointer<DataBase> db_func(new DataBase());
            if(db_func->StatusOpen())
            {
                QString tab = "dataentry_settings____milking__post_milking";
                db_func->insert_add(tab, "number_of_treatments_lf", DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_lf);
                db_func->insert_add(tab, "number_of_treatments_lr", DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_lr);
                db_func->insert_add(tab, "number_of_treatments_rf", DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_rf);
                db_func->insert_add(tab, "number_of_treatments_rr", DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_rr);
                db_func->insert_add(tab, "duration_per_treatment_lf", DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_lf);
                db_func->insert_add(tab, "duration_per_treatment_lr", DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_lr);
                db_func->insert_add(tab, "duration_per_treatment_rf", DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_rf);
                db_func->insert_add(tab, "duration_per_treatment_rr", DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_rr);
                db_func->insert_add(tab, "sampling", DataSystems::I().dataentry_settings____milking__post_milking__sampling);
                db_func->insert_add(tab, "clean_milk_equipment", DataSystems::I().dataentry_settings____milking__post_milking__clean_milk_equipment);
                QString sql_insert = db_func->insert_add(tab, "priority_feeding", DataSystems::I().dataentry_settings____milking__post_milking__priority_feeding);

                //"----------" + "')";
                db_func->sql_exec(sql_insert, "add milking__post_milking");
            }
    }
}

void Form_DataEntry_Settings::GetData__milking__post_milking()
{
    ui->tableWidget_post_milking->clear();
    QString tab = "dataentry_settings____milking__post_milking";

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
            QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
            QSqlQuery* query = db_func->sql_exec2(sql);
            if(query->size()<1)return;
            int i=0;

            auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget_general_milking);
            ui->tableWidget_post_milking->setRowCount( 1 );
            ui->tableWidget_post_milking->setHorizontalHeaderItem(0, new QTableWidgetItem("Общее доение"));

            for(int i=0;i<ui->tableWidget_post_milking->columnCount();i++)ui->tableWidget_general_milking->setColumnWidth(i, 150);
            //ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
            //ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
            //ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);

            i=0;
            while(query->next())
            {
                QCheckBox *checkbox = new QCheckBox();
                checkbox->installEventFilter(this);
                checkbox->setText("");
                checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
                ui->tableWidget_post_milking->setCellWidget(i,0,checkbox);

                ui->tableWidget_post_milking->setItem( i, 1,  new QTableWidgetItem( query->value("number_of_treatments_lf").toString() ));
                ui->tableWidget_post_milking->setItem( i, 2,  new QTableWidgetItem( query->value("number_of_treatments_lr").toString() ));
                ui->tableWidget_post_milking->setItem( i, 3,  new QTableWidgetItem( query->value("number_of_treatments_rf").toString() ));
                ui->tableWidget_post_milking->setItem( i, 4,  new QTableWidgetItem( query->value("number_of_treatments_rr").toString() ));
                ui->tableWidget_post_milking->setItem( i, 5,  new QTableWidgetItem( query->value("duration_per_treatment_lf").toString() ));
                ui->tableWidget_post_milking->setItem( i, 6,  new QTableWidgetItem( query->value("duration_per_treatment_lr").toString() ));
                ui->tableWidget_post_milking->setItem( i, 7,  new QTableWidgetItem( query->value("duration_per_treatment_rf").toString() ));
                ui->tableWidget_post_milking->setItem( i, 8,  new QTableWidgetItem( query->value("duration_per_treatment_rr").toString() ));
                ui->tableWidget_post_milking->setItem( i, 9,  new QTableWidgetItem( query->value("sampling").toString() ));
                ui->tableWidget_post_milking->setItem( i, 10,  new QTableWidgetItem( query->value("clean_milk_equipment").toString() ));
                ui->tableWidget_post_milking->setItem( i, 11,  new QTableWidgetItem( query->value("priority_feeding").toString() ));

                ui->tableWidget_general_milking->insertRow( ui->tableWidget_general_milking->rowCount() );
                i++;
            }
    }
    /**/
}


