#include "form_dataentry_dataentry___milk_separationoff.h"
#include "ui_form_dataentry_dataentry___milk_separationoff.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "json/json_w.h"
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>
#include "dataanimals.h"
#include <QMessageBox>

#include "FormsMenu/form_dataentry_dataentry___milk_separationoff_add.h"

form_dataentry_dataentry___milk_separationoff::form_dataentry_dataentry___milk_separationoff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_dataentry_dataentry___milk_separationoff)
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

form_dataentry_dataentry___milk_separationoff::~form_dataentry_dataentry___milk_separationoff()
{
    delete ui;
}


void form_dataentry_dataentry___milk_separationoff::addRandom()
{
    for(int i=0;i<1;i++)
    {
        DataSystems::Instance().milk_separation_animal_No = "cow"+QString::number(rand()%100);
        DataSystems::Instance().milk_separation_Robot_number = "robot"+QString::number(rand()%100);
        DataSystems::Instance().milk_separation_lactation_number = QString::number(rand()%1000);
        DataSystems::Instance().milk_separation_lactation_days = QString::number(rand()%270);
        DataSystems::Instance().milk_separation_milk_separation_type = QString::number(rand()%100);
        DataSystems::Instance().milk_separation_milk_separation_tank=QString::number(rand()%100);
        DataSystems::Instance().milk_separation_end_date=QString::number(rand()%100);
        DataSystems::Instance().milk_separation_milk_separation_status=QString::number(rand()%100);
        DataSystems::Instance().milk_separation_start_separation_y=QString::number(rand()%100);
        DataSystems::Instance().milk_separation_start_separation_h=QString::number(rand()%100);
        DataSystems::Instance().milk_separation_end_separation_y=QString::number(rand()%100);
        DataSystems::Instance().milk_separation_end_separation_h=QString::number(rand()%100);
        DataSystems::Instance().milk_separation_expected_dry=QString::number(rand()%100);

        QScopedPointer<DataBase> db_func(new DataBase());
        if(db_func->StatusOpen())
        {

            QString sql = QString("INSERT INTO  dataentry_milk_separation("
                                  "animal_No,"
                                  "Robot_No,"
                                  "lactation_No,"
                                  "lactation_days,"
                                  "milk_separation_type,"
                                  "milk_separation_tank,"
                                  "end_date,"
                                  "milk_separation_status,"
                                  "start_separation_y,"
                                  "start_separation_h,"
                                  "end_separation_y,"
                                  "end_separation_h,"
                                  "expected_dry"
                                  ")")+
                          QString("VALUES (")+"'" +
                          DataSystems::Instance().milk_separation_animal_No + "', '" +
                          DataSystems::Instance().milk_separation_Robot_number + "', '" +
                          DataSystems::Instance().milk_separation_lactation_number + "', '" +
                          DataSystems::Instance().milk_separation_lactation_days + "', '" +
                          DataSystems::Instance().milk_separation_milk_separation_type + "', '" +
                          DataSystems::Instance().milk_separation_milk_separation_tank + "', '" +
                          DataSystems::Instance().milk_separation_end_date + "', '" +
                          DataSystems::Instance().milk_separation_milk_separation_status + "', '" +
                          DataSystems::Instance().milk_separation_start_separation_y + "', '" +
                          DataSystems::Instance().milk_separation_start_separation_h + "', '" +
                          DataSystems::Instance().milk_separation_end_separation_y + "', '" +
                          DataSystems::Instance().milk_separation_end_separation_h + "', '" +
                          DataSystems::Instance().milk_separation_expected_dry +
                          "');";  //,// '" +


            //"----------" + "')";
            db_func->sql_exec(sql, "add separation");
        }
    }

}




void form_dataentry_dataentry___milk_separationoff::GetData()
{
    ui->tableWidget->clear();
    ui->comboBox_numbers->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        //QString sql =  QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();
        QString sql =  QString("SELECT * FROM public.dataentry_milk_separation ORDER BY id ASC ").toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        //logger::WriteLog("SELECT vars: ----- " + sql);

        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;

        int i=0;

        auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);
        QList<QString> allColumns = json_w::form_table2("table_form_1_9_milk_separation.json");
        qDebug()<< " Чтение конфига ---------------- ";

        QStringList NameColumns;
        foreach (QString cols, allColumns)
        {
            qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
            i++;
            NameColumns<<cols;
        }

        ui->tableWidget->setColumnCount( allColumns.count() );
        ui->tableWidget->setRowCount( 1 );

        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("История"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
        //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

        //ui->tableWidget->hideColumn(0);

        for(int i=0;i<allColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);


        ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
        ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
        ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);

        QList<QString> columns={
            "",
            "animal_No",
            "Robot_No",
            "lactation_No",
            "lactation_days",
            "milk_separation_type",
            "milk_separation_tank",
            "end_date",
            "milk_separation_status"
        };

        i=0;
        while(query->next())
        {
            QCheckBox *checkbox = new QCheckBox();
            checkbox->installEventFilter(this);
            checkbox->setText("");
            checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
            ui->tableWidget->setCellWidget(i,0,checkbox);

            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem( query->value("animal_No").toString() ));
            ui->comboBox_numbers->addItem(query->value("animal_No").toString());
            ui->tableWidget->setItem( i, 2,  new QTableWidgetItem( query->value("Robot_No").toString() ));
            ui->tableWidget->setItem( i, 3,  new QTableWidgetItem( query->value("lactation_No").toString() ));
            ui->tableWidget->setItem( i, 4,  new QTableWidgetItem( query->value("lactation_days").toString() ));
            ui->tableWidget->setItem( i, 5,  new QTableWidgetItem( query->value("milk_separation_type").toString() ));
            ui->tableWidget->setItem( i, 6,  new QTableWidgetItem( query->value("milk_separation_tank").toString() ));
            ui->tableWidget->setItem( i, 7,  new QTableWidgetItem( query->value("end_date").toString() ));
            ui->tableWidget->setItem( i, 8,  new QTableWidgetItem( query->value("milk_separation_status").toString() ));
            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            //ui->tableWidget->;
            i++;
        }
    }


    /**/

}

void form_dataentry_dataentry___milk_separationoff::GetData(const QString &str)
{


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        //QString sql = QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();
        //QString sql = QString("SELECT * FROM public.dataentry_cow_card ORDER BY id ASC ").toLower();
        //QString sql = QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        QString sql =  QString("SELECT * FROM public.dataentry_milk_separation WHERE animal_No =  '" + str +"';").toLower();
        //logger::WriteLog("SELECT vars: ----- " + sql);

        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;
        //logger::WriteMsg("чтение завершено: кол-во записей: "+ query->size());

        int i=0;
        while(query->next())
        {
            QVariant val;

            val = query->value("animal_No"); DataSystems::Instance().milk_separation_animal_No =  (!val.isNull())?val.toString():" ";
            //qDebug()<<"animals: "<<DataSystems::Instance().otel_animal_No;

            val = query->value("Robot_No"); DataSystems::Instance().milk_separation_Robot_number =  (!val.isNull())?val.toString():" ";
            val = query->value("lactation_No").toString(); DataSystems::Instance().milk_separation_lactation_number = (!val.isNull())?val.toString():" ";
            val = query->value("lactation_days").toString(); DataSystems::Instance().milk_separation_lactation_days = (!val.isNull())?val.toString():" ";

            val = query->value("milk_separation_type"); DataSystems::Instance().milk_separation_milk_separation_type = (!val.isNull())?val.toString():" ";

            val = query->value("milk_separation_tank"); DataSystems::Instance().milk_separation_milk_separation_tank =  (!val.isNull())?val.toString():" ";
            val = query->value("end_date"); DataSystems::Instance().otel_average_lactation =  (!val.isNull())?val.toString():" ";
            val = query->value("milk_separation_status"); DataSystems::Instance().milk_separation_milk_separation_status =  (!val.isNull())?val.toString():" ";
            val = query->value("start_separation_y"); DataSystems::Instance().milk_separation_start_separation_y =  (!val.isNull())?val.toString():" ";
            val = query->value("start_separation_h"); DataSystems::Instance().milk_separation_start_separation_h =  (!val.isNull())?val.toString():" ";
            val = query->value("end_separation_y"); DataSystems::Instance().milk_separation_end_separation_y =  (!val.isNull())?val.toString():" ";
            val = query->value("end_separation_h"); DataSystems::Instance().milk_separation_end_separation_h =  (!val.isNull())?val.toString():" ";
            val = query->value("expected_dry"); DataSystems::Instance().milk_separation_expected_dry =  (!val.isNull())?val.toString():" ";

            /**/

            break;
        }
    }

    /**/

}


void form_dataentry_dataentry___milk_separationoff::create()
{
    auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);
    QList<QString> allColumns = json_w::form_table2("table_form_1_9_milk_separation.json");
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
        ui->tableWidget->setItem( i, 8,  new QTableWidgetItem(QDate().currentDate().toString()));
        //Milt Teat RR
        ui->tableWidget->setItem( i, 9,  new QTableWidgetItem(val2));
        //Лактация под управлением
        //ui->tableWidget->setItem( i, 10,  new QTableWidgetItem(val));


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

void form_dataentry_dataentry___milk_separationoff::on_comboBox_numbers_activated(int index)
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


void form_dataentry_dataentry___milk_separationoff::on_pushButton_add_clicked()
{
    form_dataentry_dataentry___milk_separationoff_add tf(this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }
}


void form_dataentry_dataentry___milk_separationoff::on_pushButton_select_clicked()
{

    if(checkAnimals.isEmpty())
    {
        QMessageBox::information(this,"","Не выбрали животное из таблицы");
        return;
    }
    GetData(checkAnimals);

    form_dataentry_dataentry___milk_separationoff_add tf("", this);
    if(!(tf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }


    GetData();


}

