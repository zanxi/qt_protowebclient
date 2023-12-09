#include "table_form_1_2_otel.h"
#include "ui_table_form_1_2_otel.h"
#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "FormsMenu/table_form_1_2_otel_add.h"

#include "json/json_w.h"
#include "dataanimals.h"

#include <QCheckBox>
#include <QMessageBox>

table_form_1_2_otel::table_form_1_2_otel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::table_form_1_2_otel)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    ui->groupBox_2->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:"+DataSystems::Instance().settings___color_header+";"
                                  "padding: 4 20000 4 10;"
                                  "}");

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:"+DataSystems::Instance().settings___color_header+";"
                                "padding: 4 20000 4 10;"
                                "}");

    ui->pushButton_add_cow->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );
    ui->pushButton_select_cow->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );

    //addRandom();
    GetData();

    mTimer=new QTimer(this);
    connect(mTimer, SIGNAL(timeout()),this, SLOT(GetData()));
    mTimer->start(1000);

    ui->comboBox->setCurrentIndex(0);

    //on_comboBox_activated(0);

}

table_form_1_2_otel::~table_form_1_2_otel()
{
    delete ui;
}

void table_form_1_2_otel::addRandom()
{
    for(int i=0;i<1;i++)
    {
        DataSystems::Instance().otel_animal_No = "cow"+QString::number(rand()%100); // ui->lineEdit_animal_N->text();
        DataSystems::Instance().otel_number = QString::number(rand()%100); // ui->lineEdit_animal_N->text();
        DataSystems::Instance().otel_Robot_No = "robot"+QString::number(rand()%100); // ui->lineEdit_animal_N->text();
        DataSystems::Instance().otel_lactation_No = QString::number(rand()%1000);
        DataSystems::Instance().otel_lactation_days = QString::number(rand()%1000); // ui->lineEdit_animal_N->text();
        //DataSystems::Instance().dataentry_dataentry_cow_card_present = ui->lineEdit->text();
        DataSystems::Instance().otel_days_pregnant = QString::number(rand()%1000);
        DataSystems::Instance().otel_lactation_production = QString::number(rand()%1000);// QDateTime(); ui->dateEdit_birth_date->text();
        DataSystems::Instance().otel_average_lactation = QString::number(rand()%1000);
        DataSystems::Instance().otel_average_refusals = QString::number(rand()%1000);
        DataSystems::Instance().otel_average_falures = QString::number(rand()%1000); //  QString::number(operatingModeGroup_use_as_sire->checkedId());

        DataSystems::Instance().otel_current_location =""; // 1 calving
        DataSystems::Instance().otel_days_dry =QString::number(rand()%50);
        DataSystems::Instance().otel_waiting_time_dry_off =""; // ------------------
        DataSystems::Instance().otel_remarks_previous ="pregnant";
        DataSystems::Instance().otel_expected_calving =QString::number(rand()%50);
        DataSystems::Instance().otel_calving_date =""; // ---------------
        DataSystems::Instance().otel_waiting_time_colostrum =""; // -----------------
        DataSystems::Instance().otel_number_of_calves = QString::number(rand()%150);
        DataSystems::Instance().otel_remarks ="otel future";
        DataSystems::Instance().otel_group ="automatic";
        DataSystems::Instance().otel_cow_number =QString::number(rand()%150);
        DataSystems::Instance().otel_responder ="responder  " + QString::number(rand()%150);
        DataSystems::Instance().otel_teat ="++++";
        DataSystems::Instance().otel_separation_milk_tank ="tank"+QString::number(rand()%50);
        DataSystems::Instance().otel_calf_born_dead ="-"; // 2 calf 1
        DataSystems::Instance().otel_calf_keep_calf ="-";
        DataSystems::Instance().otel_calf_calf_number =QString::number(rand()%11150);
        DataSystems::Instance().otel_calf_life_number =QString::number(rand()%11150);
        DataSystems::Instance().otel_calf_name ="calf"+QString::number(rand()%150);
        DataSystems::Instance().otel_calf_weight =QString::number(rand()%1150);
        DataSystems::Instance().otel_calf_sex ="w";
        DataSystems::Instance().otel_calf_hair_color = "gray";
        DataSystems::Instance().otel_calf_group ="automatic";


        //DataSystems::Instance().otel_ = QString::number(rand()%1000);
        //DataSystems::Instance().dataentry_dataentry_cow_card_ = ui->dateEdit_birth_date->text();
        //DataSystems::Instance().dataentry_dataentry_cow_card_ = ui->dateEdit_birth_date->text();


        QScopedPointer<DataBase> db_func(new DataBase());
        //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
        if(db_func->StatusOpen())
        {

            QString sql = QString("INSERT INTO  dataentry_otel("
                                  "animal_No,"
                                  "number,"
                                  "Robot_No,"
                                  "lactation_No,"
                                  "lactation_days,"
                                  "days_pregnant,"
                                  "lactation_production,"
                                  "average_lactation,"
                                  "average_refusals,"
                                  "average_falures,"
                                  "average_milk_speed,"
                                  // расширенные
                                  "current_location," // 1 calving
                                  "days_dry,"
                                  "waiting_time_dry_off,"
                                  "remarks_previous,"
                                  "expected_calving,"
                                  "calving_date,"
                                  "waiting_time_colostrum,"
                                  "number_of_calves,"
                                  "remarks,"
                                  "group_,"
                                  "cow_number,"
                                  "responder,"
                                  "teat,"
                                  "separation_milk_tank,"
                                  "calf_born_dead," // 2 calf 1
                                  "calf_keep_calf,"
                                  "calf_calf_number,"
                                  "calf_life_number,"
                                  "calf_name,"
                                  "calf_weight,"
                                  "calf_sex,"
                                  "calf_hair_color,"
                                  "calf_group"
                                  ")")+
                          QString("VALUES (")+
                          "'" +
                          DataSystems::Instance().otel_animal_No + "', '" +
                          DataSystems::Instance().otel_number + "', '" +
                          DataSystems::Instance().otel_Robot_No + "', '" +
                          DataSystems::Instance().otel_lactation_No + "', '" +
                          DataSystems::Instance().otel_lactation_days + "', '" +
                          DataSystems::Instance().otel_days_pregnant + "', '" +
                          DataSystems::Instance().otel_lactation_production + "', '" +
                          DataSystems::Instance().otel_average_lactation + "', '" +
                          DataSystems::Instance().otel_average_refusals + "', '" +
                          DataSystems::Instance().otel_average_falures + "', '" +
                          DataSystems::Instance().otel_average_milk_speed + "', '" +
                          DataSystems::Instance().otel_current_location + "', '" +
                          DataSystems::Instance().otel_days_dry + "', '" +
                          DataSystems::Instance().otel_waiting_time_dry_off + "', '" +
                          DataSystems::Instance().otel_remarks_previous + "', '" +
                          DataSystems::Instance().otel_expected_calving + "', '" +
                          DataSystems::Instance().otel_calving_date + "', '" +
                          DataSystems::Instance().otel_waiting_time_colostrum + "', '" +
                          DataSystems::Instance().otel_number_of_calves + "', '" +
                          DataSystems::Instance().otel_remarks + "', '" +
                          DataSystems::Instance().otel_group + "', '" +
                          DataSystems::Instance().otel_cow_number + "', '" +
                          DataSystems::Instance().otel_responder + "', '" +
                          DataSystems::Instance().otel_teat + "', '" +
                          DataSystems::Instance().otel_separation_milk_tank + "', '" +
                          DataSystems::Instance().otel_calf_born_dead + "', '" +
                          DataSystems::Instance().otel_calf_keep_calf + "', '" +
                          DataSystems::Instance().otel_calf_calf_number + "', '" +
                          DataSystems::Instance().otel_calf_life_number + "', '" +
                          DataSystems::Instance().otel_calf_name + "', '" +
                          DataSystems::Instance().otel_calf_weight + "', '" +
                          DataSystems::Instance().otel_calf_sex + "', '" +
                          DataSystems::Instance().otel_calf_hair_color + "', '" +
                          DataSystems::Instance().otel_calf_group +
                          "');";  //,// '" +
            /*
        sql = QString("INSERT INTO dataentry_cow_card("
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
                      "use_as_sire"
                      //"father_life_number,"
                      //"father_name,"
                      //"mother_life_number,"
                      //"mother_name"
                              ")")+
                      QString("VALUES (")+
                      "'" +
                      DataSystems::Instance().dataentry_dataentry_cow_card_animals + "', '" +
                      DataSystems::Instance().dataentry_dataentry_cow_card_responder + "', '" +
              DataSystems::Instance().dataentry_dataentry_cow_card_name + "', '" +
              DataSystems::Instance().dataentry_dataentry_cow_card_group + "', '" +
              DataSystems::Instance().dataentry_dataentry_cow_card_life_number +  "', '" +
              DataSystems::Instance().dataentry_dataentry_cow_card_present + "', '" +
              DataSystems::Instance().dataentry_dataentry_cow_card_birth_date + "', '" +
              DataSystems::Instance().dataentry_dataentry_cow_card_location + "', '" +
              DataSystems::Instance().dataentry_dataentry_cow_card_label +  "', '" +
              DataSystems::Instance().dataentry_dataentry_cow_card_keep +  "', '" +
              DataSystems::Instance().dataentry_dataentry_cow_card_gender +  "', '" +
              DataSystems::Instance().dataentry_dataentry_cow_card_use_as_sire + // "', '" +
              //DataSystems::Instance().dataentry_dataentry_cow_card_father_life_number + "', '" +
              //DataSystems::Instance().dataentry_dataentry_cow_card_father_name + "', '" +
              //DataSystems::Instance().dataentry_dataentry_cow_card_mother_life_number + "', '" +
              //DataSystems::Instance().dataentry_dataentry_cow_card_mother_name + // "', '" +
                       "');";  //,// '" +

        /**/

            //"----------" + "')";
            db_func->sql_exec(sql, "add otel");
        }
    }

}


void table_form_1_2_otel::GetData()
{
    addRandom();
    GetData_search(searchText);
    return;
    /**/

}

void  table_form_1_2_otel::tabwidget_insert_add_column(QSqlQuery *query, QTableWidget *tab, QString nameColumn, int numRow, int numColumn)
{
        QTableWidgetItem *item = new QTableWidgetItem(query->value(nameColumn).toString()); item->setTextAlignment(Qt::AlignHCenter);
        tab->setItem( numRow, numColumn,  item);
        //ui->comboBox->addItem(query->value(nameColumn).toString());
}

void table_form_1_2_otel::GetData_search(QString str)
{
    ui->tableWidget->clear();
    ui->comboBox->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QString tab = "dataentry_otel";
        QString sql =  QString("SELECT * FROM public."+tab+" WHERE animal_No LIKE '%"+str+"%' OR Robot_No LIKE '%"+str+"%' ORDER BY id;").toLower();
        qDebug()<<"sql: "<<sql;

        //QString tab = "dataentry_robot";
        //QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        int i=0;

        QList<QString> allColumns = json_w::form_table2("table_form_1_2_otel.json");
        QStringList NameColumns;
        NameColumns;
        foreach (QString cols, allColumns)
        {
            qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
            i++;
            NameColumns<<cols;
        }

        ui->tableWidget->setColumnCount( allColumns.count() );
        ui->tableWidget->setRowCount( 1 );
        for(int i=0;i<allColumns.count()+1;i++)ui->tableWidget->setColumnWidth(i, 150);

        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
        //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

        //ui->tableWidget->hideColumn(0);

        auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

        ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
        ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
        ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);

        i=0;

        i=0;
        while(query->next())
        {
            tabwidget_insert_add_column(query,ui->tableWidget,"animal_No",i,0);
            ui->comboBox->addItem(query->value("animal_No").toString());

            tabwidget_insert_add_column(query,ui->tableWidget,"number",i,1);
            tabwidget_insert_add_column(query,ui->tableWidget,"Robot_No",i,2);
            tabwidget_insert_add_column(query,ui->tableWidget,"lactation_No",i,3);
            tabwidget_insert_add_column(query,ui->tableWidget,"lactation_days",i,4);
            tabwidget_insert_add_column(query,ui->tableWidget,"days_pregnant",i,5);
            tabwidget_insert_add_column(query,ui->tableWidget,"lactation_production",i,6);
            tabwidget_insert_add_column(query,ui->tableWidget,"average_lactation",i,7);
            tabwidget_insert_add_column(query,ui->tableWidget,"lactation_production",i,8);
            tabwidget_insert_add_column(query,ui->tableWidget,"average_lactation text",i,9);
            tabwidget_insert_add_column(query,ui->tableWidget,"average_refusals",i,10);

            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            i++;
        }
    }

    /**/
}


void table_form_1_2_otel::GetData(QString str)
{


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        //QString sql =  QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();
        //QString sql =  QString("SELECT * FROM public.dataentry_cow_card ORDER BY id ASC ").toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        QString sql =  QString("SELECT * FROM public.dataentry_otel WHERE animal_No =  '" + str +"';").toLower();
        //logger::WriteLog("SELECT vars: ----- " + sql);

        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;
        //logger::WriteMsg("чтение завершено: кол-во записей: "+ query->size());

        int i=0;
        while(query->next())
        {

            QVariant val;

            val = query->value("animal_no"); DataSystems::Instance().otel_animal_No =  (!val.isNull())?val.toString():" ";
            qDebug()<<"animals: "<<DataSystems::Instance().otel_animal_No;

            val =  query->value("number"); DataSystems::Instance().otel_number =  (!val.isNull())?val.toString():" ";
            val = query->value("Robot_No"); DataSystems::Instance().otel_Robot_No =  (!val.isNull())?val.toString():" ";
            val = query->value("lactation_No").toString(); DataSystems::Instance().otel_lactation_No = (!val.isNull())?val.toString():" ";
            val = query->value("lactation_days").toString(); DataSystems::Instance().otel_lactation_days = (!val.isNull())?val.toString():" ";
            val = query->value("days_pregnant"); DataSystems::Instance().otel_days_pregnant = (!val.isNull())?val.toString():" ";
            val = query->value("lactation_production"); DataSystems::Instance().otel_lactation_production =  (!val.isNull())?val.toString():" ";
            val = query->value("average_lactation"); DataSystems::Instance().otel_average_lactation =  (!val.isNull())?val.toString():" ";
            val = query->value("average_refusals"); DataSystems::Instance().otel_average_refusals =  (!val.isNull())?val.toString():" ";
            val = query->value("average_falures"); DataSystems::Instance().otel_average_falures =  (!val.isNull())?val.toString():" ";
            val = query->value("average_milk_speed"); DataSystems::Instance().otel_average_milk_speed =  (!val.isNull())?val.toString():" ";

            val = query->value("current_location"); DataSystems::Instance().otel_current_location =  (!val.isNull())?val.toString():" "; // 1 calving
            val = query->value("days_dry"); DataSystems::Instance().otel_days_dry =  (!val.isNull())?val.toString():" ";
            val = query->value("waiting_time_dry_off"); DataSystems::Instance().otel_waiting_time_dry_off =  (!val.isNull())?val.toString():" "; // ------------------
            val = query->value("remarks_previous"); DataSystems::Instance().otel_remarks_previous =  (!val.isNull())?val.toString():" ";
            val = query->value("expected_calving"); DataSystems::Instance().otel_expected_calving =  (!val.isNull())?val.toString():" ";
            val = query->value("calving_date"); DataSystems::Instance().otel_calving_date =  (!val.isNull())?val.toString():" "; // ---------------
            val = query->value("waiting_time_colostrum"); DataSystems::Instance().otel_waiting_time_colostrum =  (!val.isNull())?val.toString():" "; // -----------------
            val = query->value("number_of_calves"); DataSystems::Instance().otel_number_of_calves =  (!val.isNull())?val.toString():" ";
            val = query->value("remarks"); DataSystems::Instance().otel_remarks =  (!val.isNull())?val.toString():" ";
            val = query->value("group_"); DataSystems::Instance().otel_group =  (!val.isNull())?val.toString():" ";
            val = query->value("cow_number"); DataSystems::Instance().otel_cow_number =  (!val.isNull())?val.toString():" ";
            val = query->value("responder"); DataSystems::Instance().otel_responder =  (!val.isNull())?val.toString():" ";
            val = query->value("teat"); DataSystems::Instance().otel_teat =  (!val.isNull())?val.toString():" ";
            val = query->value("separation_milk_tank"); DataSystems::Instance().otel_separation_milk_tank =  (!val.isNull())?val.toString():" ";
            val = query->value("calf_born_dead"); DataSystems::Instance().otel_calf_born_dead =  (!val.isNull())?val.toString():" "; // 2 calf 1
            val = query->value("calf_keep_calf"); DataSystems::Instance().otel_calf_keep_calf =  (!val.isNull())?val.toString():" ";
            val = query->value("calf_calf_number"); DataSystems::Instance().otel_calf_calf_number =  (!val.isNull())?val.toString():" ";
            val = query->value("calf_life_number"); DataSystems::Instance().otel_calf_life_number =  (!val.isNull())?val.toString():" ";
            val = query->value("calf_name"); DataSystems::Instance().otel_calf_name =  (!val.isNull())?val.toString():" ";
            val = query->value("calf_weight"); DataSystems::Instance().otel_calf_weight = (!val.isNull())?val.toString():" ";
            val = query->value("calf_sex"); DataSystems::Instance().otel_calf_sex =  (!val.isNull())?val.toString():" ";
            val = query->value("calf_hair_color"); DataSystems::Instance().otel_calf_hair_color =  (!val.isNull())?val.toString():" ";
            val = query->value("calf_group"); DataSystems::Instance().otel_calf_group = (!val.isNull())?val.toString():" ";
            /**/

            break;
        }
    }





    /**/

}




void table_form_1_2_otel::on_comboBox_activated(int index)
{
    DataSystems::Instance().clear_otel();

    mTimer->stop();

    int i=0;
    selectRow=-1;
    //qDebug()<<"check: "<<ui->comboBox->currentText();
    //QString check = ui->comboBox->currentData(index).toString();
    checkAnimals = ui->comboBox->currentText();

    qDebug()<<"check: "<<checkAnimals;
    //logger::;
    for(i=0;i<ui->tableWidget->rowCount();i++)
    {
        QString val;
        QTableWidgetItem *item = ui->tableWidget->item(i,0);
        qDebug()<<"check2: "<<item->text();
        if (NULL != item) {
            val = item->text();
            if(checkAnimals.contains(val))
            {
                selectRow = i;
                if(selectRowOld!=-1)for(int j=0;j<5;j++)ui->tableWidget->item(selectRowOld,j)->setBackground( Qt::white);
                if(selectRow!=-1)for(int j=0;j<5;j++)ui->tableWidget->item(selectRow,j)->setBackground( Qt::lightGray);
                selectRowOld=selectRow;
                qDebug()<<"--- break: "<<"i: "<<i<<"; "<<val;
                break;
            }
            qDebug()<<"check: "<<checkAnimals<<"; "<<"i: "<<i<<"; "<<val;
        }
    }

    return;

    if(selectRow==-1)return;
    DataSystems::Instance().otel_animal_No = ui->tableWidget->item(selectRow,1)->text();
    DataSystems::Instance().otel_number = ui->tableWidget->item(selectRow,2)->text();
    DataSystems::Instance().otel_Robot_No = ui->tableWidget->item(selectRow,3)->text();
    DataSystems::Instance().otel_lactation_No = ui->tableWidget->item(selectRow,4)->text();
    DataSystems::Instance().otel_lactation_days = ui->tableWidget->item(selectRow,5)->text();
    DataSystems::Instance().otel_days_pregnant = ui->tableWidget->item(selectRow,6)->text();
    DataSystems::Instance().otel_lactation_production = ui->tableWidget->item(selectRow,7)->text();
    DataSystems::Instance().otel_average_lactation = ui->tableWidget->item(selectRow,8)->text();
    DataSystems::Instance().otel_average_refusals = ui->tableWidget->item(selectRow,9)->text();
    DataSystems::Instance().otel_average_falures = ui->tableWidget->item(selectRow,10)->text();
    DataSystems::Instance().otel_average_milk_speed = ui->tableWidget->item(selectRow,11)->text();

    return;
    QTableWidgetItem *item_animal_No = ui->tableWidget->item(selectRow,1);
    QTableWidgetItem *item_number = ui->tableWidget->item(selectRow,2);
    QTableWidgetItem *item_Robot_No = ui->tableWidget->item(selectRow,3);
    QTableWidgetItem *item_lactation_No = ui->tableWidget->item(selectRow,4);
    QTableWidgetItem *item_lactation_days = ui->tableWidget->item(selectRow,5);
    QTableWidgetItem *item_days_pregnant = ui->tableWidget->item(selectRow,6);
    QTableWidgetItem *item_lactation_production = ui->tableWidget->item(selectRow,7);
    QTableWidgetItem *item_average_lactation = ui->tableWidget->item(selectRow,8);
    QTableWidgetItem *item_average_refusals = ui->tableWidget->item(selectRow,9);
    QTableWidgetItem *item_average_falures = ui->tableWidget->item(selectRow,10);
    QTableWidgetItem *item_average_milk_speed = ui->tableWidget->item(selectRow,11);


    if(selectRow!=-1)
    {
        for(int j=0;j<ui->tableWidget->columnCount();i++)
        {
            QString val;
            QTableWidgetItem *item = ui->tableWidget->item(selectRow,j);
            if (NULL != item)
            {
                //val = item->text();
                //qDebug()<<"val: "<<val;
                //qDebug()<<ui->tableWidget->col<<"val: "<<val;
            }
        }
    }

    return;

    ui->tableWidget->item(i,0)->setBackground( Qt::yellow);

    for(int j=0;j<ui->tableWidget->columnCount();i++)
    {
        QString val;
        QTableWidgetItem *item = ui->tableWidget->item(selectRow,j);
        if (NULL != item) {
            //val = item->text();
            //qDebug()<<"val: "<<val;
            //qDebug()<<ui->tableWidget->col<<"val: "<<val;
        }
    }



}


void table_form_1_2_otel::on_pushButton_add_cow_clicked()
{
    //DataSystems::Instance().clear();

    table_form_1_2_otel_add otel_add(this);
    if(!(otel_add.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Введите отел");
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
}


void table_form_1_2_otel::on_pushButton_select_cow_clicked()
{

    if(checkAnimals.isEmpty())
    {
        QMessageBox::information(this,"","Не выбрали животное из таблицы");
        return;
    }
    GetData(checkAnimals);

    table_form_1_2_otel_add form_otel_add("",this);
    if(!(form_otel_add.exec()==QDialog::Accepted))
    {

        if(form_otel_add.checkStatus()) QMessageBox::information(this,"Успешно","Обновили данные животного");
    }

    GetData();

}


void table_form_1_2_otel::on_pushButton_delete_clicked()
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
            QString sql2=QString("TRUNCATE TABLE dataentry_otel;");
            db_func->sql_exec(sql2, "delete cow");
        }

        QMessageBox::information(this,"Успешно","Записи удалены");
    }

    GetData();
}


void table_form_1_2_otel::on_pushButton_addRandom_clicked()
{
    addRandom();
    GetData();
}


void table_form_1_2_otel::on_lineEdit_textChanged(const QString &arg1)
{
    searchText = arg1;

    return;

    QString sql =  QString("SELECT * FROM dataentry_otel WHERE animal_no LIKE '%"+arg1+"%' ORDER BY animal_No;");

    ui->tableWidget->clear();
    ui->comboBox->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;

        ui->tableWidget->clear();
        int i=0;

        QList<QString> allColumns = json_w::form_table2("table_form_1_2_otel.json");
        QStringList NameColumns;
        NameColumns;
        foreach (QString cols, allColumns)
        {
            qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
            i++;
            NameColumns<<cols;
        }

        ui->tableWidget->setColumnCount( allColumns.count() );
        ui->tableWidget->setRowCount( query->size() );
        for(int i=0;i<allColumns.count()+1;i++)ui->tableWidget->setColumnWidth(i, 150);

        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
        //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

        //ui->tableWidget->hideColumn(0);

        auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

        ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
        ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
        ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);

        i=0;
        while(query->next())
        {
            ui->tableWidget->setItem( i, 0,  new QTableWidgetItem( query->value("animal_No").toString() ));
            ui->comboBox->addItem(query->value("animal_No").toString());
            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem(query->value("number").toString()));
            ui->tableWidget->setItem( i, 2,  new QTableWidgetItem( query->value("Robot_No").toString() ));
            ui->tableWidget->setItem( i, 3,  new QTableWidgetItem( query->value("lactation_No").toString() ));
            ui->tableWidget->setItem( i, 4,  new QTableWidgetItem( query->value("lactation_days").toString() ));
            ui->tableWidget->setItem( i, 5,  new QTableWidgetItem( query->value("days_pregnant").toString() ));
            ui->tableWidget->setItem( i, 6,  new QTableWidgetItem( query->value("lactation_production").toString() ));
            ui->tableWidget->setItem( i, 7,  new QTableWidgetItem( query->value("average_lactation").toString() ));
            ui->tableWidget->setItem( i, 8,  new QTableWidgetItem( query->value("lactation_production").toString() ));
            ui->tableWidget->setItem( i, 9,  new QTableWidgetItem( query->value("average_lactation text").toString() ));
            ui->tableWidget->setItem( i, 10,  new QTableWidgetItem( query->value("average_refusals").toString() ));
            i++;
        }
    }

    checkAnimals = ui->tableWidget->item(0,0)->text();
    qDebug()<<"search: "<<checkAnimals;

}

