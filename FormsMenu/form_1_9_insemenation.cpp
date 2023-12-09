#include "form_1_9_insemenation.h"
#include "ui_form_1_9_insemenation.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "json/json_w.h"

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>

#include "Debug/logger.h"

#include "dataanimals.h"

// 1. Навигатор: Ввод данных 2. Меню: Дневная запись           3. Подменю: Осеменение


Form_1_9_insemenation::Form_1_9_insemenation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_1_9_insemenation)
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


    ui->groupBox_3->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:"+DataSystems::Instance().settings___color_header+";"
                                  "padding: 4 20000 4 10;"
                                  "}"
                                  );
    ui->groupBox_4->setStyleSheet(
        "QGroupBox {"
        "background-color: white;"
        "}"
        "QGroupBox::title {"
        "color: white;"
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "padding: 4 20000 4 10;"
        "}"
                                     );

    ui->groupBox_5->setStyleSheet(
        "QGroupBox {"
        "background-color: white;"
        "}"
        "QGroupBox::title {"
        "color: white;"
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                            "padding: 4 20000 4 10;"
                                                            "}"
        );



    ui->pushButton_2->setStyleSheet(
                                    "background-color:"+DataSystems::Instance().settings___color_header+";"
                                    "color: white;"
                                    "padding: 4 50 4 10;"
                                    );
    ui->pushButton_3->setStyleSheet(
                                    "background-color:"+DataSystems::Instance().settings___color_header+";"
                                    "color: white;"
                                    "padding: 4 50 4 10;"
                                  );
    ui->pushButton_4->setStyleSheet(
        "background-color:#14B143;"
        "color: white;"
        "padding: 4 50 4 10;"
                                    );
    ui->pushButton_5->setStyleSheet(
                                    "background-color:"+DataSystems::Instance().settings___color_header+";"
                                    "color: white;"
                                    "padding: 4 50 4 10;"
                                    );
    ui->pushButton_6->setStyleSheet("background-color:"+DataSystems::Instance().settings___color_header+";"
                                    "color: white;"
                                    "padding: 4 50 4 10;"
                                    );

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    ui->label_number->setText(DataSystems::Instance().Insemenation_animal_No);
    ui->label_current_lactation->setText(DataSystems::Instance().Insemenation_animal_No);
    ui->label_days_lactation_2->setText(DataSystems::Instance().Insemenation_lactation_days);

    ui->label_previous_heat->setText(DataSystems::Instance().Insemenation_days_since_heat);
    ui->label_previous_insemenation->setText(DataSystems::Instance().Insemenation_since_insemenation);
    ui->label_status_reproduction->setText(DataSystems::Instance().Insemenation_day_production);

    //ui->label_->setText(DataSystems::Instance().Insemenation_day_production);

    check_insert_or_update = false;
    create();
}


Form_1_9_insemenation::Form_1_9_insemenation(QString checkAnimals, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form_1_9_insemenation)
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


    ui->groupBox_3->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                      "padding: 4 20000 4 10;"
                                                                                      "}"
                                  );
    ui->groupBox_4->setStyleSheet(
        "QGroupBox {"
        "background-color: white;"
        "}"
        "QGroupBox::title {"
        "color: white;"
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                            "padding: 4 20000 4 10;"
                                                            "}"
        );

    ui->groupBox_5->setStyleSheet(
        "QGroupBox {"
        "background-color: white;"
        "}"
        "QGroupBox::title {"
        "color: white;"
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                            "padding: 4 20000 4 10;"
                                                            "}"
        );



    ui->pushButton_2->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_3->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_4->setStyleSheet(
        "background-color:#14B143;"
        "color: white;"
        "padding: 4 50 4 10;"
        );
    ui->pushButton_5->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_6->setStyleSheet("background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                                            "color: white;"
                                                                                                            "padding: 4 50 4 10;"
                                    );

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    ui->label_number->setText(DataSystems::Instance().Insemenation_animal_No);
    ui->label_current_lactation->setText(DataSystems::Instance().Insemenation_animal_No);
    ui->label_days_lactation_2->setText(DataSystems::Instance().Insemenation_lactation_days);

    ui->label_previous_heat->setText(DataSystems::Instance().Insemenation_days_since_heat);
    ui->label_previous_insemenation->setText(DataSystems::Instance().Insemenation_since_insemenation);
    ui->label_status_reproduction->setText(DataSystems::Instance().Insemenation_day_production);

    //ui->label_->setText(DataSystems::Instance().Insemenation_day_production);

    check_insert_or_update = true;
    SetData();

    create();
}



Form_1_9_insemenation::~Form_1_9_insemenation()
{
    delete ui;
}

void Form_1_9_insemenation::SetData()
{

    ui->label_number->setText(DataSystems::Instance().Insemenation_animal_No);
    //ui->label_->setText(DataSystems::Instance().Insemenation_Robot_number);
    ui->label_current_lactation->setText(DataSystems::Instance().Insemenation_lactation_number);
    ui->label_days_lactation_2->setText(DataSystems::Instance().Insemenation_lactation_days);
    //ui->label_->setText(DataSystems::Instance().Insemenation_since_insemenation);
    ui->label_previous_insemenation->setText(DataSystems::Instance().Insemenation_insemenation_number);
    ui->label_status_reproduction->setText(DataSystems::Instance().Insemenation_day_production);
    //ui->label_->setText(DataSystems::Instance().Insemenation_Activity);
    ui->label_previous_heat->setText(DataSystems::Instance().Insemenation_days_since_heat);
    ui->label_wait_otel->setText(DataSystems::Instance().Insemenation_expected_otel);
    //ui->label_->setText(DataSystems::Instance().Insemenation_type);
    //ui->dateEdit_datr_insemenation->setText(DataSystems::Instance().Insemenation_date);
    ui->comboBox_sires->setCurrentText(DataSystems::Instance().Insemenation_sire);
    ui->comboBox_persons->setCurrentText(DataSystems::Instance().Insemenation_person);
    ui->comboBox_group->setCurrentText(DataSystems::Instance().Insemenation_group);
    ui->textEdit_comment->setText(DataSystems::Instance().Insemenation_remarks);


}


void Form_1_9_insemenation::create()
{
    auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);
    QList<QString> allColumns = json_w::form_table2("table_form_1_9_insemenation.json");
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

    for(int i=0;i<allColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

    //ui->tableWidget->hideColumn(0);

    for(int i=0;i<2;i++)
    {
        //for(int j=0;j<allColumns.count();j++)
        {
            QLabel *label_location_No = new QLabel();
            label_location_No->installEventFilter(this);
            label_location_No->setText("sire-"+QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,0,label_location_No);

            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem(QDate().currentDate().toString()));

            QLabel *label_remarks = new QLabel();
            label_remarks->installEventFilter(this);
            label_remarks->setText("comments-"+QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,2,label_remarks);

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
}




void Form_1_9_insemenation::on_pushButton_6_clicked()
{

    this->close();

}


void Form_1_9_insemenation::on_pushButton_5_clicked()
{
    //DataSystems::Instance().otel_number = ui->label_number->text();
    //DataSystems::Instance().otel_current_location = ui->label_current_lactation->text();
    //ui->label_days_suhostoinost->setText(DataSystems::Instance().otel_days_dry);
    //ui->label_time_wait_otel->setText(DataSystems::Instance().otel_waiting_time_colostrum);
    //ui->label_before_comments->setText(DataSystems::Instance().otel_remarks_previous);
    //ui->label_days_lactation->setText(DataSystems::Instance().otel_lactation_days);

    //ui->label_number->setText(DataSystems::Instance().Insemenation_animal_No);
    //ui->label_->setText(DataSystems::Instance().Insemenation_Robot_number);
    //ui->label_current_lactation->setText(DataSystems::Instance().Insemenation_lactation_number);
    //ui->label_days_lactation_2->setText(DataSystems::Instance().Insemenation_lactation_days);
    //ui->label_->setText(DataSystems::Instance().Insemenation_since_insemenation);
    //ui->label_previous_insemenation->setText(DataSystems::Instance().Insemenation_insemenation_number);
    //ui->label_status_reproduction->setText(DataSystems::Instance().Insemenation_day_production);
    //ui->label_->setText(DataSystems::Instance().Insemenation_Activity);
    //ui->label_previous_heat->setText(DataSystems::Instance().Insemenation_days_since_heat);
    //ui->label_wait_otel->setText(DataSystems::Instance().Insemenation_expected_otel);
    //ui->label_->setText(DataSystems::Instance().Insemenation_type);
    //ui->dateEdit_datr_insemenation->setText(DataSystems::Instance().Insemenation_date);
    DataSystems::Instance().Insemenation_sire = ui->comboBox_sires->currentText();
    DataSystems::Instance().Insemenation_person = ui->comboBox_persons->currentText();
    DataSystems::Instance().Insemenation_group = ui->comboBox_group->currentText();
    DataSystems::Instance().Insemenation_remarks = ui->textEdit_comment->placeholderText();


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {

        QString sql_update=QString("UPDATE dataentry_insemenation SET ")+

                             "animal_No = '" + DataSystems::Instance().Insemenation_animal_No + "', '" +
                             "Robot_No = '" + DataSystems::Instance().Insemenation_Robot_number + "', '" +
                             "lactation_No = '" + DataSystems::Instance().Insemenation_Robot_number + "', '" +
                             "lactation_days = '" + DataSystems::Instance().Insemenation_lactation_days + "', '" +
                             "since_insemenation = '" + DataSystems::Instance().Insemenation_since_insemenation + "', '" +
                             "insemenation_number = '" + DataSystems::Instance().Insemenation_insemenation_number + "', '" +
                             "day_production = '" + DataSystems::Instance().Insemenation_day_production + "', '" +
                             "Activity = '" + DataSystems::Instance().Insemenation_Activity + "', '" +
                             "days_since_heat = '" + DataSystems::Instance().Insemenation_days_since_heat + "', '" +
                             "expected_otel = '" + DataSystems::Instance().Insemenation_expected_otel + "', '" +
                             "type = '" + DataSystems::Instance().Insemenation_type + "', '" +
                             "date = '" + DataSystems::Instance().Insemenation_date + "', '" +
                             "sire = '" + DataSystems::Instance().Insemenation_sire + "', '" +
                             "person = '" + DataSystems::Instance().Insemenation_person + "', '" +
                             "group_ = '" + DataSystems::Instance().Insemenation_group + "', '" +
                             "remarks = '" + DataSystems::Instance().Insemenation_remarks + "' " +
                             " where animal_No =  '"+ DataSystems::Instance().Insemenation_animal_No + "';";

        /**/

        QString sql_insert = QString("INSERT INTO  dataentry_insemenation("
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

        //if(check_insert_or_update)logger::WriteMsg(sql_insert.toStdString());
        //else logger::WriteMsg(sql_update.toStdString());

        //"----------" + "')";
        if(!check_insert_or_update)db_func->sql_exec(sql_insert, "add insemenation");
        else db_func->sql_exec(sql_update, "update insemenation");

        logger::WriteMsg("check change otel: "+check_insert_or_update);
    }

    status = true;

    QMessageBox::information(this,"Спасибо","Сохранены данные");
    this->close();
}

