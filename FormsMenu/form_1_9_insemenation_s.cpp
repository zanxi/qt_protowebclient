#include "form_1_9_insemenation_s.h"
#include "ui_form_1_9_insemenation_s.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "json/json_w.h"
#include "FormsMenu/form_1_9_insemenation.h"
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>
#include <QLabel>

#include "dataanimals.h"
#include <QMessageBox>


form_1_9_insemenation_s::form_1_9_insemenation_s(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_1_9_insemenation_s)
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
    //on_comboBox_numbers_activated(1);

}

void form_1_9_insemenation_s::create()
{
    auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);
    QList<QString> allColumns = json_w::form_table2("table_form_1_9_insemenation_s.json");
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
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Осеменение"));
    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );

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
        // Since insemenation
        ui->tableWidget->setItem( i, 5,  new QTableWidgetItem(val));
        //Number insemenation
        ui->tableWidget->setItem( i, 6,  new QTableWidgetItem(val));
        //Day production
        ui->tableWidget->setItem( i, 7,  new QTableWidgetItem(val2));
        //Activity
        ui->tableWidget->setItem( i, 8,  new QTableWidgetItem(val));
        //Day since heat
        ui->tableWidget->setItem( i, 9,  new QTableWidgetItem(val2));


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



form_1_9_insemenation_s::~form_1_9_insemenation_s()
{
    delete ui;
}


void form_1_9_insemenation_s::on_pushButton_delete_clicked()
{

}

// ***********************************************************************************************************************

void form_1_9_insemenation_s::addRandom()
{
    for(int i=0;i<3;i++)
    {
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

        QScopedPointer<DataBase> db_func(new DataBase());
        if(db_func->StatusOpen())
        {

            QString sql = QString("INSERT INTO  dataentry_insemenation("
                                  "animal_No,"
                                  "Robot_No,"
                                  "lactation_No,"
                                  "lactation_days,"
                                  "since_insemenation,"
                                  "insemenation_number,"
                                  "day_production,"
                                  "Activity,"
                                  "days_since_heat,"
                                  "expected_otel,"
                                  "type,"
                                  "date,"
                                  "sire,"
                                  "person,"
                                  "group_,"
                                  "remarks"
                                  ")")+
                          QString("VALUES (")+"'" +
            DataSystems::Instance().Insemenation_animal_No  + "', '" +
            DataSystems::Instance().Insemenation_Robot_number  + "', '" +
            DataSystems::Instance().Insemenation_lactation_number  + "', '" +
            DataSystems::Instance().Insemenation_lactation_days  + "', '" +
            DataSystems::Instance().Insemenation_since_insemenation  + "', '" +
            DataSystems::Instance().Insemenation_insemenation_number  + "', '" +
            DataSystems::Instance().Insemenation_day_production  + "', '" +
            DataSystems::Instance().Insemenation_Activity  + "', '" +
            DataSystems::Instance().Insemenation_days_since_heat  + "', '" +
            DataSystems::Instance().Insemenation_expected_otel  + "', '" +
            DataSystems::Instance().Insemenation_type  + "', '" +
            DataSystems::Instance().Insemenation_date  + "', '" +
            DataSystems::Instance().Insemenation_sire  + "', '" +
            DataSystems::Instance().Insemenation_person  + "', '" +
            DataSystems::Instance().Insemenation_group  + "', '" +
            DataSystems::Instance().Insemenation_remarks  +

                          "');";  //,// '" +


            //"----------" + "')";
            db_func->sql_exec(sql, "add separation");
        }
    }

}




void form_1_9_insemenation_s::GetData()
{

    ui->tableWidget->clear();
    ui->comboBox_numbers->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        //QString sql =  QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();
        QString sql =  QString("SELECT * FROM public.dataentry_insemenation ORDER BY id ASC ").toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        //logger::WriteLog("SELECT vars: ----- " + sql);

        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;

        auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);
        QList<QString> allColumns = json_w::form_table2("table_form_1_9_insemenation_s.json");
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
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Осеменение"));
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

            QLabel *lb = new QLabel;
            //MainTextEdit->setFontItalic(ItalyStyle->isChecked());
            //lb->setFont(QFont::StyleNormal);
            lb->setStyleSheet("border-radius: 0px; border-bottom-style: solid; border-bottom-color: red; border-bottom-width: 1px;");
            lb->setText(query->value("animal_No").toString());

            //ui->tableWidget->setItem( i, 1,  new QTableWidgetItem( query->value("animal_No").toString() ));
            //ui->tableWidget->setItem( i, 1,  new QTableWidgetItem( lb ));
            ui->tableWidget->setCellWidget(i, 1, lb);

            ui->comboBox_numbers->addItem(query->value("animal_No").toString());
            ui->tableWidget->setItem( i, 2,  new QTableWidgetItem( query->value("Robot_No").toString() ));
            ui->tableWidget->setItem( i, 3,  new QTableWidgetItem( query->value("lactation_No").toString() ));
            ui->tableWidget->setItem( i, 4,  new QTableWidgetItem( query->value("lactation_days").toString() ));
            ui->tableWidget->setItem( i, 5,  new QTableWidgetItem( query->value("since_insemenation").toString() ));
            ui->tableWidget->setItem( i, 6,  new QTableWidgetItem( query->value("insemenation_number").toString() ));
            ui->tableWidget->setItem( i, 7,  new QTableWidgetItem( query->value("day_production").toString() ));
            ui->tableWidget->setItem( i, 8,  new QTableWidgetItem( query->value("Activity").toString() ));
            ui->tableWidget->setItem( i, 9,  new QTableWidgetItem( query->value("days_since_heat").toString() ));
            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            //ui->tableWidget->;
            i++;
        }
    }


    /**/

}

void form_1_9_insemenation_s::GetData(const QString &str)
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



void form_1_9_insemenation_s::on_comboBox_numbers_activated(int index)
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


void form_1_9_insemenation_s::on_pushButton_add_clicked()
{
    Form_1_9_insemenation tf(this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }
}


void form_1_9_insemenation_s::on_pushButton_select_clicked()
{

    if(checkAnimals.isEmpty())
    {
        QMessageBox::information(this,"","Не выбрали животное из таблицы");
        return;
    }
    GetData(checkAnimals);

    Form_1_9_insemenation tf("", this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }


    GetData();


}



// ***********************************************************************************************************************

void form_1_9_insemenation_s::on_tableWidget_cellClicked(int row, int column)
{    
    QLabel *item =  qobject_cast<QLabel *>(ui->tableWidget->cellWidget(row,column));
    if(item == nullptr)return;
    QString animal_No = item->text();
    qDebug()<<animal_No;

}

