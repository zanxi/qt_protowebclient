#include "form_dataentry_dataentry___dry_off.h"
#include "ui_form_dataentry_dataentry___dry_off.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "json/json_w.h"
#include "FormsMenu/cell_check_and_edit.h"
#include "FormsMenu/form_dataentry_dataentry___dry_off__add.h"


#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>


#include "dataanimals.h"


#include <QMessageBox>



// 1. Навигатор: Ввод данных   2. Меню: Дневная запись         3. Выбрать: «Сухостойность»

form_dataentry_dataentry___dry_off::form_dataentry_dataentry___dry_off(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_dataentry_dataentry___dry_off)
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

    if(DataSystems::Instance().db_generate_random)addRandom();
    GetData();

    //create();

    //on_comboBox_numbers_activated(0);
}

form_dataentry_dataentry___dry_off::~form_dataentry_dataentry___dry_off()
{
    delete ui;
}

void form_dataentry_dataentry___dry_off::create()
{
    auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);
    QList<QString> allColumns = json_w::form_table2("table_form_1_9_dry_off.json");
    qDebug()<< " Чтение конфига ---------------- ";

    QStringList NameColumns;
    int i=0;
    foreach (QString cols, allColumns)
    {
        qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
        i++;
        NameColumns<<cols;
    }

    ui->tableWidget->setColumnCount( allColumns.count() );
    ui->tableWidget->setRowCount( 10 );

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("История"));
    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //ui->tableWidget->hideColumn(0);

    for(int i=0;i<allColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

    for(int i=0;i<3;i++)
    {
        // checkbox
        QCheckBox *checkbox = new QCheckBox();
        checkbox->installEventFilter(this);
        checkbox->setText("");
        checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
        ui->tableWidget->setCellWidget(i,0,checkbox);
        // animal no.
        QString combo = QString::number(rand()%2222);
        ui->tableWidget->setItem( i, 1,  new QTableWidgetItem(combo));
        ui->comboBox_numbers->addItem(combo);
        // Robot
        ui->tableWidget->setItem( i, 2,  new QTableWidgetItem(" "));
        // Lac No.
        ui->tableWidget->setItem( i, 3,  new QTableWidgetItem(QString::number(rand()%22)));
        // Lac Days
        ui->tableWidget->setItem( i, 4,  new QTableWidgetItem(QString::number(rand()%33)));

        QString val=rand()%4==2?(rand()%2==0?"Да":"Нет"):"";
                                                                    QString val2=rand()%4==2?(rand()%2==0?"Да":"Нет"):"";
                                                                                                                    // Приоритет кормления
                                                                                                                    ui->tableWidget->setItem( i, 5,  new QTableWidgetItem(val));
                                                                                         //Milt Teat LF
                                                                                         ui->tableWidget->setItem( i, 6,  new QTableWidgetItem(val));
                                                                                         //Milt Teat LF
                                                                                         ui->tableWidget->setItem( i, 7,  new QTableWidgetItem(val2));
                                                                                         //Milt Teat RF
                                                                                         ui->tableWidget->setItem( i, 8,  new QTableWidgetItem(val));
                                                                                         //Milt Teat RR
                                                                                         ui->tableWidget->setItem( i, 9,  new QTableWidgetItem(val2));
                                                                                         //Лактация под управлением
                                                                                         ui->tableWidget->setItem( i, 10,  new QTableWidgetItem(val));


        //            QComboBox *combobox_active = new QComboBox();
        //            combobox_active->installEventFilter(this);
        //            combobox_active->addItem(QString::number(rand()%2222));
        //            combobox_active->addItem(QString::number(rand()%2222));
        //            combobox_active->addItem(QString::number(rand()%2222));
        //            combobox_active->addItem(QString::number(rand()%2222));
        //            ui->tableWidget->setCellWidget(i,3,combobox_active);

        //            QPushButton *pushButton_show_all = new QPushButton();
        //            pushButton_show_all->installEventFilter(this);
        //            pushButton_show_all->setText("show_all");
        //            ui->tableWidget->setCellWidget(i,5,pushButton_show_all);

        //ui->tableWidget->setItem( i, 3,  new QTableWidgetItem(QDate().currentDate().toString()));
        //ui->tableWidget->setItem( i, 5,  new QTableWidgetItem(QDate().currentDate().toString()));
        //ui->tableWidget->setItem( i, 6,  new QTableWidgetItem(QDate().currentDate().toString()));


    }

}


// ***********************************************************************************************************************

void form_dataentry_dataentry___dry_off::addRandom()
{
    for(int i=0;i<3;i++)
    {
        DataSystems::Instance().dry_off_animal_No = "cow"+QString::number(rand()%1000);
        DataSystems::Instance().dry_off_Robot_number = "robot"+QString::number(rand()%100);
        DataSystems::Instance().dry_off_lactation_number = QString::number(rand()%100);
        DataSystems::Instance().dry_off_lactation_days = QString::number(rand()%1000);
        DataSystems::Instance().dry_off_days_pregnant = QString::number(rand()%1000);
        DataSystems::Instance().dry_off_day_production = QString::number(rand()%1000);
        DataSystems::Instance().dry_off_total_day = QString::number(rand()%100);
        DataSystems::Instance().dry_off_udder_health_add = QString::number(rand()%100);
        DataSystems::Instance().dry_off_udder_health_add_count = QString::number(rand()%100);

        DataSystems::Instance().dry_off_animal_No = "cow"+QString::number(rand()%100);
        DataSystems::Instance().dry_off_Robot_number = "robot"+QString::number(rand()%100);
        DataSystems::Instance().dry_off_lactation_number = QString::number(rand()%1000);


        QScopedPointer<DataBase> db_func(new DataBase());
        if(db_func->StatusOpen())
        {

            QString tab = "dataentry_dry_off";

                db_func->insert_add(tab, "animal_No", DataSystems::Instance().dry_off_animal_No);
                db_func->insert_add(tab, "Robot_No", DataSystems::Instance().dry_off_Robot_number);
                db_func->insert_add(tab, "lactation_No", DataSystems::Instance().dry_off_lactation_number);
                db_func->insert_add(tab, "lactation_days", DataSystems::Instance().dry_off_lactation_days);
                db_func->insert_add(tab, "days_pregnant", DataSystems::Instance().dry_off_days_pregnant);
                db_func->insert_add(tab, "day_production", DataSystems::Instance().dry_off_day_production);
                db_func->insert_add(tab, "total_day", DataSystems::Instance().dry_off_total_day);
                db_func->insert_add(tab, "udder_health_add", DataSystems::Instance().dry_off_udder_health_add);
                db_func->insert_add(tab, "udder_health_add_count", DataSystems::Instance().dry_off_udder_health_add_count);
                db_func->insert_add(tab, "date", DataSystems::Instance().dry_off_date);
                db_func->insert_add(tab, "medicine_used", DataSystems::Instance().dry_off_medicine_used);
                db_func->insert_add(tab, "medicine_category", DataSystems::Instance().dry_off_medicine_category);
                db_func->insert_add(tab, "medicine", DataSystems::Instance().dry_off_medicine);
                db_func->insert_add(tab, "dosage", DataSystems::Instance().dry_off_dosage);
                db_func->insert_add(tab, "Teat_LF", DataSystems::Instance().dry_off_Teat_LF);
                db_func->insert_add(tab, "Teat_RF", DataSystems::Instance().dry_off_Teat_LR);
                db_func->insert_add(tab, "Teat_LR", DataSystems::Instance().dry_off_Teat_RF);
                db_func->insert_add(tab, "Teat_RR", DataSystems::Instance().dry_off_Teat_RR);
                db_func->insert_add(tab, "separate_meat_untill", DataSystems::Instance().dry_off_separate_meat_untill);
                db_func->insert_add(tab, "separate_milk_untill", DataSystems::Instance().dry_off_separate_milk_untill);
                QString sql_insert = db_func->insert_add(tab, "group_", DataSystems::Instance().dry_off_group);


                //"----------" + "')";
                db_func->sql_exec(sql_insert, "add dry off");
        }
    }

}




void form_dataentry_dataentry___dry_off::GetData()
{

    ui->tableWidget->clear();
    ui->comboBox_numbers->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        //QString sql =  QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();
        QString sql =  QString("SELECT * FROM public.dataentry_dry_off ORDER BY id ASC ").toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        //logger::WriteLog("SELECT vars: ----- " + sql);

        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;

        auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);
        QList<QString> allColumns = json_w::form_table2("table_form_1_9_dry_off.json");
        qDebug()<< " Чтение конфига ---------------- ";

        QStringList NameColumns;
        int i=0;
        foreach (QString cols, allColumns)
        {
                qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
                i++;
                NameColumns<<cols;
        }

        ui->tableWidget->setColumnCount( allColumns.count() );

        ui->tableWidget->setRowCount( 1 );
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Сухостойность"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );

        //ui->tableWidget->hideColumn(0);

        for(int i=0;i<allColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

        //ui->tableWidget->hideColumn(0);

        i=0;
        while(query->next())
        {
                QCheckBox *checkbox = new QCheckBox();
                checkbox->installEventFilter(this);
                checkbox->setText("");
                checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
                ui->tableWidget->setCellWidget(i,0,checkbox);

                ui->tableWidget->setItem( i, 1,  new QTableWidgetItem( query->value("animal_No").toString() ));
                ui->tableWidget->setItem( i, 2,  new QTableWidgetItem( query->value("Robot_No").toString() ));
                ui->tableWidget->setItem( i, 3,  new QTableWidgetItem( query->value("lactation_No").toString() ));
                ui->tableWidget->setItem( i, 4,  new QTableWidgetItem( query->value("lactation_days").toString() ));
                ui->tableWidget->setItem( i, 5,  new QTableWidgetItem( query->value("days_pregnant").toString() ));
                ui->tableWidget->setItem( i, 6,  new QTableWidgetItem( query->value("day_production").toString() ));
                ui->tableWidget->setItem( i, 7,  new QTableWidgetItem( query->value("total_day").toString() ));
                ui->tableWidget->setItem( i, 8,  new QTableWidgetItem( query->value("udder_health_add text").toString() ));
                ui->tableWidget->setItem( i, 9,  new QTableWidgetItem( query->value("udder_health_add_count").toString() ));

                ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
                //ui->tableWidget->;
                i++;
        }
    }


    /**/

}

void form_dataentry_dataentry___dry_off::GetData(QString str)
{


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        //QString sql = QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();
        //QString sql = QString("SELECT * FROM public.dataentry_cow_card ORDER BY id ASC ").toLower();
        //QString sql = QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        QString sql =  QString("SELECT * FROM public.dataentry_insemenation WHERE animal_No =  '" + str +"';").toLower();
        //logger::WriteLog("SELECT vars: ----- " + sql);

        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;
        //logger::WriteMsg("чтение завершено: кол-во записей: "+ query->size());

        int i=0;
        while(query->next())
        {
                QVariant val;


                DataSystems::Instance().Insemenation_animal_No = "cow"+QString::number(rand()%100);
                DataSystems::Instance().Insemenation_Robot_number = "robot"+QString::number(rand()%100);
                DataSystems::Instance().Insemenation_lactation_number = QString::number(rand()%1000);
                DataSystems::Instance().Insemenation_lactation_days = QString::number(rand()%270);
                DataSystems::Instance().Insemenation_since_insemenation = QString::number(rand()%100);
                DataSystems::Instance().Insemenation_insemenation_number = QString::number(rand()%100);
                DataSystems::Instance().Insemenation_day_production = QString::number(rand()%100);
                DataSystems::Instance().Insemenation_Activity = QString::number(rand()%100);
                DataSystems::Instance().Insemenation_days_since_heat = QString::number(rand()%100);
                DataSystems::Instance().Insemenation_expected_otel = QString::number(rand()%100);
                DataSystems::Instance().Insemenation_type = QString::number(rand()%100);
                DataSystems::Instance().Insemenation_date = QString::number(rand()%100);
                DataSystems::Instance().Insemenation_sire = QString::number(rand()%100);
                DataSystems::Instance().Insemenation_person = QString::number(rand()%100);
                DataSystems::Instance().Insemenation_group = QString::number(rand()%100);
                DataSystems::Instance().Insemenation_remarks = QString::number(rand()%100);


                val = query->value("animal_No"); DataSystems::Instance().Insemenation_animal_No =  (!val.isNull())?val.toString():" ";
                //qDebug()<<"animals: "<<DataSystems::Instance().otel_animal_No;

                val = query->value("Robot_No"); DataSystems::Instance().Insemenation_Robot_number =  (!val.isNull())?val.toString():" ";
                val = query->value("lactation_No").toString(); DataSystems::Instance().Insemenation_lactation_number = (!val.isNull())?val.toString():" ";
                val = query->value("lactation_days").toString(); DataSystems::Instance().Insemenation_lactation_days = (!val.isNull())?val.toString():" ";

                val = query->value("since_insemenation"); DataSystems::Instance().Insemenation_since_insemenation = (!val.isNull())?val.toString():" ";

                val = query->value("insemenation_number"); DataSystems::Instance().Insemenation_insemenation_number =  (!val.isNull())?val.toString():" ";
                val = query->value("day_production"); DataSystems::Instance().Insemenation_day_production =  (!val.isNull())?val.toString():" ";
                val = query->value("Activity"); DataSystems::Instance().Insemenation_Activity =  (!val.isNull())?val.toString():" ";
                val = query->value("days_since_heat"); DataSystems::Instance().Insemenation_days_since_heat =  (!val.isNull())?val.toString():" ";
                val = query->value("expected_otel"); DataSystems::Instance().Insemenation_expected_otel =  (!val.isNull())?val.toString():" ";
                val = query->value("type"); DataSystems::Instance().Insemenation_type =  (!val.isNull())?val.toString():" ";
                val = query->value("date"); DataSystems::Instance().Insemenation_date =  (!val.isNull())?val.toString():" ";
                val = query->value("sire"); DataSystems::Instance().Insemenation_sire =  (!val.isNull())?val.toString():" ";
                val = query->value("person"); DataSystems::Instance().Insemenation_person =  (!val.isNull())?val.toString():" ";
                val = query->value("group_"); DataSystems::Instance().Insemenation_group =  (!val.isNull())?val.toString():" ";
                val = query->value("remarks"); DataSystems::Instance().Insemenation_remarks =  (!val.isNull())?val.toString():" ";

                /**/

                break;
        }
    }

    /**/

}



void form_dataentry_dataentry___dry_off::on_comboBox_numbers_activated(int index)
{
    //DataSystems::Instance().clear_otel();

    int i=0;
    selectRow=-1;
    //qDebug()<<"check: "<<ui->comboBox->currentText();
    //QString check = ui->comboBox->currentData(index).toString();
    checkAnimals = ui->comboBox_numbers->currentText();
    for(i=0;i<ui->tableWidget->rowCount();i++)
    {
        QString val;
        QTableWidgetItem *item = ui->tableWidget->item(i,1);
        qDebug()<<"--- break: "<<"i: "<<i<<"; "<<val;
        if (NULL != item) {
                val = item->text();
                qDebug()<<"check: "<<checkAnimals<<"; "<<"i: "<<i<<"; "<<val;
                if(checkAnimals.contains(val))
                {
                    selectRow = i;
                    if(selectRowOld!=-1)ui->tableWidget->item(selectRowOld,1)->setBackground( Qt::white);
                    ui->tableWidget->item(selectRow,1)->setBackground( Qt::gray);
                    selectRowOld=selectRow;
                    qDebug()<<"--- break: "<<"i: "<<i<<"; "<<val;
                    break;
                }
                //qDebug()<<"check: "<<checkAnimals<<"; "<<"i: "<<i<<"; "<<val;
        }
    }

}


void form_dataentry_dataentry___dry_off::on_pushButton_add_clicked()
{
    form_dataentry_dataentry___dry_off__add tf(this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }
}


void form_dataentry_dataentry___dry_off::on_pushButton_select_clicked()
{

    if(checkAnimals.isEmpty())
    {
        QMessageBox::information(this,"","Не выбрали животное из таблицы");
        return;
    }
    GetData(checkAnimals);

    form_dataentry_dataentry___dry_off__add tf("", this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }


    GetData();


}



// ***********************************************************************************************************************
