#include "form_dataentry_dataentry___transfer.h"
#include "ui_form_dataentry_dataentry___transfer.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "json/json_w.h"
#include "FormsMenu/cell_check_and_edit.h"
#include "dataanimals.h"

#include "FormsMenu/form_dataentry_dataentry___transfer_add_dialog.h"

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>

#include <QMessageBox>


form_dataentry_dataentry___transfer::form_dataentry_dataentry___transfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_dataentry_dataentry___transfer)
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

form_dataentry_dataentry___transfer::~form_dataentry_dataentry___transfer()
{
    delete ui;
}

// ***********************************************************************************************************************

void form_dataentry_dataentry___transfer::addRandom()
{
    for(int i=0;i<1;i++)
    {
        DataSystems::Instance().transfer_animal_No = "cow"+QString::number(rand()%1000);
        DataSystems::Instance().transfer_Robot_No = "robot"+QString::number(rand()%100);
        DataSystems::Instance().transfer_lactation_No = QString::number(rand()%100);
        DataSystems::Instance().transfer_lactation_days = QString::number(rand()%1000);
        DataSystems::Instance().transfer_days_pregnant = QString::number(rand()%1000);
        DataSystems::Instance().transfer_present = QString::number(rand()%1000);


        QScopedPointer<DataBase> db_func(new DataBase());
        if(db_func->StatusOpen())
        {
            QString tab = "dataentry_transfer";
            db_func->insert_add(tab, "animal_No", DataSystems::Instance().transfer_animal_No);
            db_func->insert_add(tab, "Robot_No", DataSystems::Instance().transfer_Robot_No);
            db_func->insert_add(tab, "lactation_No", DataSystems::Instance().transfer_lactation_No);
            db_func->insert_add(tab, "lactation_days", DataSystems::Instance().transfer_lactation_days);
            db_func->insert_add(tab, "days_pregnant", DataSystems::Instance().transfer_days_pregnant);
            QString sql_insert = db_func->insert_add(tab, "present", DataSystems::Instance().transfer_present);
            db_func->sql_exec(sql_insert, "add dry off");
        }
    }

}




void form_dataentry_dataentry___transfer::GetData()
{

    ui->tableWidget->clear();
    ui->comboBox_numbers->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        QString tab = "dataentry_transfer";
        QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);
        QStringList NameColumns;
        NameColumns<<" "<<"Номер животного"<<"Номер робота"<<"Номер лактации"<<"Дни лактации"<<"Дни беременности"<<"Представление";
        ui->tableWidget->setColumnCount( NameColumns.count() );
        ui->tableWidget->setRowCount( 1 );
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Сухостойность"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
        //ui->tableWidget->hideColumn(0);
        for(int i=0;i<NameColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);
        //ui->tableWidget->hideColumn(0);

        int i=0;
        while(query->next())
        {
            QCheckBox *checkbox = new QCheckBox();
            checkbox->installEventFilter(this);
            checkbox->setText("");
            checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
            ui->tableWidget->setCellWidget(i,0,checkbox);
            ui->comboBox_numbers->addItem(query->value("animal_No").toString());

            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem( query->value("animal_No").toString() ));
            ui->tableWidget->setItem( i, 2,  new QTableWidgetItem( query->value("Robot_No").toString() ));
            ui->tableWidget->setItem( i, 3,  new QTableWidgetItem( query->value("lactation_No").toString() ));
            ui->tableWidget->setItem( i, 4,  new QTableWidgetItem( query->value("lactation_days").toString() ));
            ui->tableWidget->setItem( i, 5,  new QTableWidgetItem( query->value("days_pregnant").toString() ));
            ui->tableWidget->setItem( i, 5,  new QTableWidgetItem( query->value("present").toString() ));
            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            //ui->tableWidget->;
            i++;
        }
    }


    /**/

}

void form_dataentry_dataentry___transfer::GetData(QString str)
{


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        QString tab = "dataentry_transfer";
        QString sql =  QString("SELECT * FROM public."+tab+" WHERE animal_No =  '" + str +"';").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;
        int i=0;
        while(query->next())
        {
            QVariant val;
            val = query->value("animal_No"); DataSystems::Instance().transfer_animal_No = (!val.isNull())?val.toString():" ";
            val = query->value("Robot_No"); DataSystems::Instance().transfer_Robot_No = (!val.isNull())?val.toString():" ";
            val = query->value("lactation_No").toString(); DataSystems::Instance().transfer_lactation_No = (!val.isNull())?val.toString():" ";
            val = query->value("lactation_days").toString(); DataSystems::Instance().transfer_lactation_days = (!val.isNull())?val.toString():" ";
            val = query->value("days_pregnant").toString(); DataSystems::Instance().transfer_days_pregnant = (!val.isNull())?val.toString():" ";
            val = query->value("present").toString(); DataSystems::Instance().transfer_present = (!val.isNull())?val.toString():" ";
            break;
        }
    }

    /**/

}

void form_dataentry_dataentry___transfer::on_comboBox_numbers_activated(int index)
{
    int i=0;
    selectRow=-1;
    checkAnimals = ui->comboBox_numbers->currentText();
    for(i=0;i<ui->tableWidget->rowCount();i++)
    {
        QString val;
        QTableWidgetItem *item = ui->tableWidget->item(i,1);
        if (NULL != item) {
            val = item->text();
            qDebug()<<"check: "<<checkAnimals<<"; "<<"i: "<<i<<"; "<<val;
            if(checkAnimals.contains(val))
            {
                selectRow = i;
                if(selectRowOld!=-1)ui->tableWidget->item(selectRowOld,1)->setBackground( Qt::white);
                ui->tableWidget->item(selectRow,1)->setBackground( Qt::gray);
                selectRowOld=selectRow;
                break;
            }
        }
    }

}


void form_dataentry_dataentry___transfer::on_pushButton_add_clicked()
{
    form_dataentry_dataentry___transfer_add_Dialog tf(this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }
}


void form_dataentry_dataentry___transfer::on_pushButton_select_clicked()
{

    if(checkAnimals.isEmpty())
    {
        QMessageBox::information(this,"","Не выбрали животное из таблицы");
        return;
    }
    GetData(checkAnimals);

    form_dataentry_dataentry___transfer_add_Dialog tf("", this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }


    GetData();


}


