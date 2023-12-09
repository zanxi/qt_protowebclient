#include "form_dataentry_routing_6_6_1.h"
#include "ui_form_dataentry_routing_6_6_1.h"
#include "form_dataentry_routing_6_6_1_add_dialog_.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "json/json_w.h"
#include "FormsMenu/cell_check_and_edit.h"

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>

#include "dataanimals.h"
#include "Debug/logger.h"
#include <QMessageBox>

// 1. Навигатор: Ввод данных   2. Меню: Дневная запись         3. Выбрать: Маршрутизация (Routing)


Form_dataentry_routing_6_6_1::Form_dataentry_routing_6_6_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_dataentry_routing_6_6_1)
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



}

Form_dataentry_routing_6_6_1::~Form_dataentry_routing_6_6_1()
{
    delete ui;
}

void Form_dataentry_routing_6_6_1::addRandom()
{
    for(int i=0;i<1;i++)
    {
        DataSystems::Instance().routing_animal_No = "cow"+QString::number(rand()%1000);
        DataSystems::Instance().routing_Robot_number = "robot"+QString::number(rand()%100);
        DataSystems::Instance().routing_lactation_number = QString::number(rand()%100);
        DataSystems::Instance().routing_lactation_days = QString::number(rand()%1000);
        DataSystems::Instance().routing_area = QString::number(rand()%1000);
        DataSystems::Instance().routing_from_date = QString::number(rand()%1000);
        DataSystems::Instance().routing_till_date = QString::number(rand()%100);
        DataSystems::Instance().routing_from_till_time = QString::number(rand()%100);
        DataSystems::Instance().routing_active_routing = QString::number(rand()%100);



        QScopedPointer<DataBase> db_func(new DataBase());
        if(db_func->StatusOpen())
        {

            QString tab = "dataentry_routing";
            //QString parameterId = "animals";
            //QString valueId = DataSystems::Instance().dataentry_dataentry_cow_card_animals;

            db_func->insert_add(tab, "animal_No", DataSystems::Instance().routing_animal_No);
            db_func->insert_add(tab, "Robot_No", DataSystems::Instance().routing_Robot_number);
            db_func->insert_add(tab, "lactation_No", DataSystems::Instance().routing_lactation_number);
            db_func->insert_add(tab, "lactation_days", DataSystems::Instance().routing_lactation_days);
            db_func->insert_add(tab, "area", DataSystems::Instance().routing_area);
            db_func->insert_add(tab, "from_date", DataSystems::Instance().routing_from_date);
            db_func->insert_add(tab, "till_date", DataSystems::Instance().routing_till_date);
            db_func->insert_add(tab, "from_till_time", DataSystems::Instance().routing_from_till_time);
            QString sql_insert=db_func->insert_add(tab, "active_routing", DataSystems::Instance().routing_active_routing);

            db_func->sql_exec(sql_insert, "add routing");
        }
    }

}


void Form_dataentry_routing_6_6_1::GetData()
{

    ui->tableWidget->clear();
    ui->comboBox_number->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

        QStringList NameColumns;
        NameColumns<<" "<<"Номер животного"<<"Номер Робота"<<"Номер лактации"<<"Дни лактации"<<"От даты"<<"До даты"<<"Активная машрутизация";

        ui->tableWidget->setColumnCount( NameColumns.count() );

        ui->tableWidget->setRowCount( 1 );
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Сухостойность"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );

        for(int i=0;i<NameColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

        int i=0;
        while(query->next())
        {
            QCheckBox *checkbox = new QCheckBox();
            checkbox->installEventFilter(this);
            checkbox->setText("");
            checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
            ui->tableWidget->setCellWidget(i,0,checkbox);

            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem( query->value("animal_No").toString() ));
            ui->comboBox_number->addItem(query->value("animal_No").toString());

            ui->tableWidget->setItem( i, 2,  new QTableWidgetItem( query->value("Robot_No").toString() ));
            ui->tableWidget->setItem( i, 3,  new QTableWidgetItem( query->value("lactation_No").toString() ));
            ui->tableWidget->setItem( i, 4,  new QTableWidgetItem( query->value("lactation_days").toString() ));
            ui->tableWidget->setItem( i, 5,  new QTableWidgetItem( query->value("area").toString() ));
            ui->tableWidget->setItem( i, 6,  new QTableWidgetItem( query->value("from_date").toString() ));
            ui->tableWidget->setItem( i, 7,  new QTableWidgetItem( query->value("till_date").toString() ));
            ui->tableWidget->setItem( i, 8,  new QTableWidgetItem( query->value("from_till_time").toString() ));
            ui->tableWidget->setItem( i, 9,  new QTableWidgetItem( query->value("active_routing").toString() ));

            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            //ui->tableWidget->;
            i++;
        }
    }


    /**/

}

void Form_dataentry_routing_6_6_1::GetData(QString str)
{


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {        
        QString sql =  QString("SELECT * FROM public."+tab+" WHERE animal_No =  '" + str +"';").toLower();
        //logger::WriteLog("SELECT vars: ----- " + sql);

        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;
        //logger::WriteMsg("чтение завершено: кол-во записей: "+ query->size());

        int i=0;
        while(query->next())
        {
            QVariant val;

            val = query->value("animal_No"); DataSystems::Instance().routing_animal_No =  (!val.isNull())?val.toString():" ";
            val = query->value("Robot_No"); DataSystems::Instance().routing_Robot_number =  (!val.isNull())?val.toString():" ";
            val = query->value("lactation_No"); DataSystems::Instance().routing_lactation_number =  (!val.isNull())?val.toString():" ";
            val = query->value("lactation_days"); DataSystems::Instance().routing_lactation_days =  (!val.isNull())?val.toString():" ";
            val = query->value("area"); DataSystems::Instance().routing_area =  (!val.isNull())?val.toString():" ";
            val = query->value("from_date"); DataSystems::Instance().routing_from_date =  (!val.isNull())?val.toString():" ";
            val = query->value("till_date"); DataSystems::Instance().routing_till_date =  (!val.isNull())?val.toString():" ";
            val = query->value("from_till_time"); DataSystems::Instance().routing_from_till_time =  (!val.isNull())?val.toString():" ";
            val = query->value("active_routing"); DataSystems::Instance().routing_active_routing =  (!val.isNull())?val.toString():" ";
            /**/

            break;
        }
    }

    /**/

}



void Form_dataentry_routing_6_6_1::on_comboBox_number_activated(int index)
{
    //DataSystems::Instance().clear_otel();

    int i=0;
    selectRow=-1;
    //qDebug()<<"check: "<<ui->comboBox->currentText();
    //QString check = ui->comboBox->currentData(index).toString();
    checkAnimals = ui->comboBox_number->currentText();
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


void Form_dataentry_routing_6_6_1::on_pushButton_add_clicked()
{
    form_dataentry_routing_6_6_1_add_Dialog_ tf(this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }
}


void Form_dataentry_routing_6_6_1::on_pushButton_select_clicked()
{

    if(checkAnimals.isEmpty())
    {
        QMessageBox::information(this,"","Не выбрали животное из таблицы");
        return;
    }
    GetData(checkAnimals);

    form_dataentry_routing_6_6_1_add_Dialog_ tf("", this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }


    GetData();


}


