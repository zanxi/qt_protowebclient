#include "form_dataentry_dataentry___fixed_feeding.h"
#include "ui_form_dataentry_dataentry___fixed_feeding.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "json/json_w.h"
#include "FormsMenu/cell_check_and_edit.h"

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>

#include "dataanimals.h"


// 1. Навигатор: Ввод данных 2. Меню: Дневная запись  3. Подменю: Кормления     4. Вкладка: Фиксированное кормление

Form_dataentry_dataentry___fixed_feeding::Form_dataentry_dataentry___fixed_feeding(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_dataentry_dataentry___fixed_feeding)
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

    mTimer=new QTimer(this);
    connect(mTimer, SIGNAL(timeout()),this, SLOT(create()));
    mTimer->start(1000);

    if(DataSystems::Instance().db_generate_random)addRandom();
    //GetData();
}

Form_dataentry_dataentry___fixed_feeding::~Form_dataentry_dataentry___fixed_feeding()
{
    delete ui;
}

void Form_dataentry_dataentry___fixed_feeding::create()
{
    if(DataSystems::Instance().db_generate_random)addRandom();
    GetData();

}


void Form_dataentry_dataentry___fixed_feeding::addRandom()
{
    for(int i=0;i<1;i++)
    {
            DataSystems::Instance().fixed_feeding_animal_No = "cow"+ QString::number(rand()%1000);
            DataSystems::Instance().fixed_feeding_name = "burenka" +  QString::number(rand()%100);
            DataSystems::Instance().fixed_feeding_group_ = "automat" + QString::number(rand()%100);
            DataSystems::Instance().fixed_feeding_days_in = QString::number(rand()%100);
            DataSystems::Instance().fixed_feeding_days_feed = QString::number(rand()%1000);
            DataSystems::Instance().fixed_feeding_milk_yield = QString::number(rand()%1000/37.0);
            DataSystems::Instance().fixed_feeding_mb_markant = QString::number(rand()%20);
            DataSystems::Instance().fixed_feeding_mb_focus = QString::number(rand()%20);
            DataSystems::Instance().fixed_feeding_transition = QString::number(rand()%10000/37.0);

            QScopedPointer<DataBase> db_func(new DataBase());
            if(db_func->StatusOpen())
            {
                QString tab = "dataentry_fixed_feeding";

                db_func->insert_add(tab, "animal_No", DataSystems::Instance().fixed_feeding_animal_No);
                db_func->insert_add(tab, "name", DataSystems::Instance().fixed_feeding_name);
                db_func->insert_add(tab, "group_", DataSystems::Instance().fixed_feeding_group_);
                db_func->insert_add(tab, "days_in", DataSystems::Instance().fixed_feeding_days_in);
                db_func->insert_add(tab, "days_feed", DataSystems::Instance().fixed_feeding_days_feed);
                db_func->insert_add(tab, "milk_yield", DataSystems::Instance().fixed_feeding_milk_yield);
                db_func->insert_add(tab, "mb_markant", DataSystems::Instance().fixed_feeding_mb_markant);
                db_func->insert_add(tab, "mb_focus", DataSystems::Instance().fixed_feeding_mb_focus);
                QString sql_insert = db_func->insert_add(tab, "transition", DataSystems::Instance().fixed_feeding_transition);


                //"----------" + "')";
                db_func->sql_exec(sql_insert, "add fixed feeding");
            }
    }

}


void Form_dataentry_dataentry___fixed_feeding::GetData()
{
    ui->tableWidget->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
            QString tab = "dataentry_fixed_feeding";
            QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
            QSqlQuery* query = db_func->sql_exec2(sql);
            qDebug()<<"koll-vo records: "<<query->size();
            if(query->size()<1)return;

            auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);
            QList<QString> allColumns = json_w::form_table2("table_form_1_9_fixed_feeding.json");
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
            ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Параметры робота"));
            ui->tableWidget->setHorizontalHeaderLabels( NameColumns );

            QList<QString> columns = {
            "animal_No",
            "name",
            "group_",
            "days_in",
            "days_feed",
            "milk_yield",
            "mb_markant",
            "mb_focus",
            "transition"
            };

            for(int i=0;i<NameColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

            i=0;
            while(query->next())
            {
                QCheckBox *checkbox = new QCheckBox();
                checkbox->installEventFilter(this);
                checkbox->setText("");
                checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);

                for(int j=0;j<columns.count();j++)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(query->value(columns[j]).toString()); item->setTextAlignment(Qt::AlignHCenter);
                    ui->tableWidget->setItem( i, j,  item);
                    qDebug()<<"j: "<<j;
                }
                ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
                i++;
            }
    }
}
