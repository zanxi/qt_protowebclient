#include "form_dataentry_dataentry___milk_settings.h"
#include "ui_form_dataentry_dataentry___milk_settings.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "json/json_w.h"
#include "FormsMenu/dialog_form_dataentry_dataentry___milk_settings_add.h"

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>

#include "dataanimals.h"


form_dataentry_dataentry___milk_settings::form_dataentry_dataentry___milk_settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_dataentry_dataentry___milk_settings)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

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

    //create();

    if(DataSystems::Instance().db_generate_random)addRandom();
    GetData();
}

form_dataentry_dataentry___milk_settings::~form_dataentry_dataentry___milk_settings()
{
    delete ui;
}

void form_dataentry_dataentry___milk_settings::addRandom()
{
    for(int i=0;i<1;i++)
    {
        DataSystems::I().milk_settings_animal_No = "cow"+QString::number(rand()%1000);
        DataSystems::I().milk_settings_Robot_number = "robot"+QString::number(rand()%100);
        DataSystems::I().milk_settings_lactation_number = QString::number(rand()%100);
        DataSystems::I().milk_settings_lactation_days = QString::number(rand()%1000);
        int valr = rand()%3;DataSystems::I().milk_settings_priority_feeding = (valr==0)?("Да"):((valr==1)?"нет":"");
        DataSystems::I().milk_settings_milk_teat_lf = QString::number(rand()%1000);
        DataSystems::I().milk_settings_milk_teat_lr = QString::number(rand()%100);
        DataSystems::I().milk_settings_milk_teat_rf = QString::number(rand()%100);
        DataSystems::I().milk_settings_milk_teat_rr = QString::number(rand()%100);
        DataSystems::I().milk_settings_milk_under_supervision = QString::number(rand()%100);
        DataSystems::I().milk_settings_training_period = QString::number(rand()%100);

        QScopedPointer<DataBase> db_func(new DataBase());
        if(db_func->StatusOpen())
        {
            //QString tab = "dataentry_milk_settings";
            db_func->insert_add(tab, "animal_No", DataSystems::I().milk_settings_animal_No);
            db_func->insert_add(tab, "Robot_No", DataSystems::I().milk_settings_Robot_number);
            db_func->insert_add(tab, "lactation_No", DataSystems::I().milk_settings_lactation_number);
            db_func->insert_add(tab, "lactation_days", DataSystems::I().milk_settings_lactation_days);
            db_func->insert_add(tab, "priority_feeding", DataSystems::I().milk_settings_priority_feeding);
            db_func->insert_add(tab, "milk_teat_lf", DataSystems::I().milk_settings_milk_teat_lf);
            db_func->insert_add(tab, "milk_teat_lr", DataSystems::I().milk_settings_milk_teat_lr);
            db_func->insert_add(tab, "milk_teat_rf", DataSystems::I().milk_settings_milk_teat_rf);
            db_func->insert_add(tab, "milk_teat_rr", DataSystems::I().milk_settings_milk_teat_rr);
            db_func->insert_add(tab, "milk_under_supervision", DataSystems::I().milk_settings_milk_under_supervision);
            QString sql_insert = db_func->insert_add(tab, "training_period", DataSystems::I().milk_settings_training_period);

            db_func->sql_exec(sql_insert, "add separation");
        }
    }
}

void form_dataentry_dataentry___milk_settings::create()
{
}

void form_dataentry_dataentry___milk_settings::GetData()
{

    ui->tableWidget->clear();
    ui->comboBox_numbers->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {

        QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);
        QList<QString> allColumns = json_w::form_table2("table_form_1_9_milk_settings.json");
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
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Настройки лактации"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );

        for(int i=0;i<allColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);
        QList<QString> columns={
            "",
            "animal_No",
            "Robot_No",
            "lactation_No",
            "lactation_days",
            "priority_feeding",
            "milk_teat_lf",
            "milk_teat_lr",
            "milk_teat_rf",
            "milk_teat_rr",
            "milk_under_supervision",
            "training_period"
        };
        //columns.append(" ");
        //columns.append("animal_No");


        i=0;
        while(query->next())
        {
            QCheckBox *checkbox = new QCheckBox();
            checkbox->installEventFilter(this);
            checkbox->setText("");
            checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
            ui->tableWidget->setCellWidget(i,0,checkbox);

            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value("animal_No").toString()); item->setTextAlignment(Qt::AlignHCenter);
                ui->tableWidget->setItem( i, 1,  item);
                ui->comboBox_numbers->addItem(query->value("animal_No").toString());
            }
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value("Robot_No").toString()); item->setTextAlignment(Qt::AlignHCenter);
                ui->tableWidget->setItem( i, 2,  item);
            }
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value("lactation_No").toString()); item->setTextAlignment(Qt::AlignHCenter);
                ui->tableWidget->setItem( i, 3,  item);
            }
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value("lactation_days").toString()); item->setTextAlignment(Qt::AlignHCenter);
                ui->tableWidget->setItem( i, 4,  item);
            }
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value("priority_feeding").toString()); item->setTextAlignment(Qt::AlignHCenter);
                ui->tableWidget->setItem( i, 5,  item);
            }
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value("milk_teat_lf").toString()); item->setTextAlignment(Qt::AlignHCenter);
                ui->tableWidget->setItem( i, 6,  item);
            }
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value("milk_teat_lr").toString()); item->setTextAlignment(Qt::AlignHCenter);
                ui->tableWidget->setItem( i, 7,  item);
            }
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value("milk_teat_rf").toString()); item->setTextAlignment(Qt::AlignHCenter);
                ui->tableWidget->setItem( i, 8,  item);
            }
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value("milk_teat_rr").toString()); item->setTextAlignment(Qt::AlignHCenter);
                ui->tableWidget->setItem( i, 9,  item);
            }
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value("milk_under_supervision").toString()); item->setTextAlignment(Qt::AlignHCenter);
                ui->tableWidget->setItem( i, 10,  item);
            }
            {
                QTableWidgetItem *item = new QTableWidgetItem(query->value("training_period").toString()); item->setTextAlignment(Qt::AlignHCenter);
                ui->tableWidget->setItem( i, 11,  item);
            }

            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            //ui->tableWidget->;
            i++;
        }
    }


    /**/

}

void form_dataentry_dataentry___milk_settings::GetData(const QString &str)
{
    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        QString sql =  QString("SELECT * FROM public.dataentry_milk_settings WHERE animal_No =  '" + str +"';").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;
        //logger::WriteMsg("чтение завершено: кол-во записей: "+ query->size());

        int i=0;
        while(query->next())
        {
            QVariant val;


            val = query->value("animal_No"); DataSystems::Instance().milk_settings_animal_No =  (!val.isNull())?val.toString():" ";
            val = query->value("Robot_No"); DataSystems::Instance().milk_settings_Robot_number =  (!val.isNull())?val.toString():" ";
            val = query->value("lactation_No"); DataSystems::Instance().milk_settings_lactation_number =  (!val.isNull())?val.toString():" ";
            val = query->value("lactation_days"); DataSystems::Instance().milk_settings_lactation_days =  (!val.isNull())?val.toString():" ";
            val = query->value("priority_feeding"); DataSystems::Instance().milk_settings_priority_feeding =  (!val.isNull())?val.toString():" ";
            val = query->value("milk_teat_lf"); DataSystems::Instance().milk_settings_milk_teat_lf =  (!val.isNull())?val.toString():" ";
            val = query->value("milk_teat_lr"); DataSystems::Instance().milk_settings_milk_teat_lr =  (!val.isNull())?val.toString():" ";
            val = query->value("milk_teat_rf"); DataSystems::Instance().milk_settings_milk_teat_rf =  (!val.isNull())?val.toString():" ";
            val = query->value("milk_teat_rr"); DataSystems::Instance().milk_settings_milk_teat_rr =  (!val.isNull())?val.toString():" ";
            val = query->value("milk_under_supervision"); DataSystems::Instance().milk_settings_milk_under_supervision =  (!val.isNull())?val.toString():" ";
            val = query->value("training_period"); DataSystems::Instance().milk_settings_training_period =  (!val.isNull())?val.toString():" ";

            /**/

            break;
        }
    }

    /**/

}



void form_dataentry_dataentry___milk_settings::on_comboBox_numbers_activated(int index)
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


void form_dataentry_dataentry___milk_settings::on_pushButton_add_clicked()
{
    Dialog_form_dataentry_dataentry___milk_settings_add tf(this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }
}





void form_dataentry_dataentry___milk_settings::on_pushButton_select_clicked()
{
    if(checkAnimals.isEmpty())
    {
        QMessageBox::information(this,"","Не выбрали животное из таблицы");
        return;
    }
    qDebug()<<"animal number: "<<checkAnimals;
    GetData(checkAnimals);

    Dialog_form_dataentry_dataentry___milk_settings_add tf("", this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }


    GetData();

}



