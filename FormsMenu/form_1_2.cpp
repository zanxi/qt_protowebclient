#include "form_1_2.h"
#include "ui_form_1_2.h"

#include "table_form_1_2.h"
#include "table_form_1_2_batch_transfer.h"

#include "table_form_1_2_in_work.h"
#include "table_form_1_2_otel.h"
#include "FormsMenu/form_1_9_add_cow.h"
#include "FormsMenu/form_1_9_insemenation_s.h"
#include "FormsMenu/form_dataentry_dataentry___fixed_feeding.h"
#include "FormsMenu/form_dataentry_dataentry___milk_settings.h"
#include "FormsMenu/form_dataentry_dataentry___dry_off.h"
#include "FormsMenu/form_dataentry_dataentry___milk_separationoff.h"
#include "FormsMenu/form_dataentry_routing_6_6_1.h"
#include "FormsMenu/form_dataentry_dataentry___transfer.h"
#include "FormsMenu/form_dataentry_robot.h"
#include "FormsMenu/form_dataentry_dataentry___batch_sampling.h"
#include "form_dataentry_dataentry___batch_condition.h"


#include "form_list_cows.h"

#include <QDebug>
#include "dataanimals.h"
#include "Debug/logger.h";

Form_1_2::Form_1_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_1_2)
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



    logger::WriteMsg("Дневная запись");

    UpdateList();

    mTimer=new QTimer(this);
    connect(mTimer, SIGNAL(timeout()),this, SLOT(UpdateList()));
    mTimer->start(1000);


    ui->listView->setModel(m_qlist_model);
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);

    //Table_Form_1_2 *tf_1_2 = new Table_Form_1_2(this);
    //ui->horizontalLayout->addWidget(tf_1_2);
    Form_List_Cows *list_cow = new Form_List_Cows(this); // по умолчанию отображаются -  карточки коров
    ui->horizontalLayout->addWidget(list_cow);
    //return;

    connect(ui->listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(SelectionChanged(QItemSelection)));



}

void Form_1_2::UpdateList()
{
    GetDataCounter();

    int counterSections;
    m_qlist_model = nullptr;
    m_qlist_model = new QStringListModel();
    QStringList list;
    list<<(QString("Параметры робота ")+"("+QString::number(DataSystems::Instance().dataentry_robot_counter)+")");
    list<<(QString("Карточки коров ")+"("+QString::number(DataSystems::Instance().dataentry_cow_card_counter)+")");
    list<<(QString("Перевод ")+"("+QString::number(DataSystems::Instance().dataentry_transfer_counter)+")");
    list<<(QString("Отел ")+"("+QString::number(DataSystems::Instance().dataentry_otel_counter)+")");
    list<<(QString("Осеменение ")+"("+QString::number(DataSystems::Instance().dataentry_insemenation_counter)+")");
    list<<(QString("Сухостойность ")+"("+QString::number(DataSystems::Instance().dataentry_dry_off_counter)+")");
    list<<(QString("Cепарация молока ")+"("+QString::number(DataSystems::Instance().dataentry_milk_separation_counter)+")");
    list<<(QString("Настройки локтации ")+"("+QString::number(DataSystems::Instance().dataentry_milk_settings_counter)+")");
    list<<(QString("Фиксированное кормление ")+"("+QString::number(DataSystems::Instance().dataentry_fixed_feeding_counter)+")");
    list<<(QString("Маршрутизация ")+"("+QString::number(DataSystems::Instance().dataentry_routing_counter)+")");
    list<<(QString("Пакетная базовая ")+"(0)");
    list<<(QString("Пакетный перевод ")+"(0)");
    list<<(QString("Состояние партии ")+"(0)");
    list<<(QString("Напоминание ")+"(0)");
    list<<(QString("Взятие проб у партии")+"(0)");
    list<<(QString("Кондиция партии")+"(0)");

    m_qlist_model->setStringList(list);

    ui->listView->setModel(m_qlist_model);
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);
    connect(ui->listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(SelectionChanged(QItemSelection)));
    ui->listView->update();

}

void Form_1_2::UpdateList2()
{
    int counterSections;
    m_qlist_model = nullptr;
    m_qlist_model = new QStringListModel();
    QStringList list;
    counterSections=GetData("dataentry_robot"); list<<(QString("Параметры робота ")+"("+QString::number(counterSections)+")");
    counterSections=GetData("dataentry_cow_card"); list<<(QString("Карточки коров ")+"("+QString::number(counterSections)+")");
    counterSections=GetData("dataentry_transfer"); list<<(QString("Перевод ")+"("+QString::number(counterSections)+")");
    counterSections=GetData("dataentry_otel"); list<<(QString("Отел ")+"("+QString::number(counterSections)+")");
    counterSections=GetData("dataentry_insemenation"); list<<(QString("Осеменение ")+"("+QString::number(counterSections)+")");
    counterSections=GetData("dataentry_dry_off"); list<<(QString("Сухостойность ")+"("+QString::number(counterSections)+")");
    counterSections=GetData("dataentry_milk_separation"); list<<(QString("Cепарация молока ")+"("+QString::number(counterSections)+")");
    counterSections=GetData("dataentry_milk_settings"); list<<(QString("Настройки локтации ")+"("+QString::number(counterSections)+")");
    list<<(QString("Фиксированное кормление ")+"(0)");
    counterSections=GetData("dataentry_routing"); list<<(QString("Маршрутизация ")+"("+QString::number(counterSections)+")");
    list<<(QString("Пакетная базовая ")+"(0)");
    list<<(QString("Пакетный перевод ")+"(0)");
    list<<(QString("Состояние партии ")+"(0)");
    list<<(QString("Напоминание ")+"(0)");

    m_qlist_model->setStringList(list);

    ui->listView->setModel(m_qlist_model);
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);
    connect(ui->listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(SelectionChanged(QItemSelection)));
    ui->listView->update();

}


int Form_1_2::GetData(const QString &tab)
{
    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        //QString sql =  QString("SELECT * FROM public.rmilksettings ORDER BY tagid ASC ").toLower();
        //QString sql =  QString("SELECT * FROM public. " + tab + " ORDER BY id ASC ").toLower();
        QString sql =  QString("SELECT * FROM " + tab + " ORDER BY id ASC ").toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        //QString sql =  QString("SELECT * FROM dataentry_cow_card WHERE id =  " + QString::number(DataSystems::Instance().DataService_Id)).toLower();
        //logger::WriteLog("SELECT vars: ----- " + sql);

        QSqlQuery* query = db_func->sql_exec2(sql);

        qDebug()<<tab<<": "<<query->size();
        logger::WriteMsg("Дневная запись:" + QString(tab+": " + QString::number(query->size())).toStdString());

        return query->size();

        if(query->size()<1)return -1;
   }
    else
    {
        qDebug()<<tab<<": -1";
        return -1;
    }
}

int Form_1_2::GetDataCounter()
{
    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {

        //=GetData("dataentry_cow_card");

        {
        QString sql =  QString("SELECT * FROM  dataentry_robot  ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query!=nullptr) DataSystems::Instance().dataentry_robot_counter = query->size();
        }
        {
        QString sql =  QString("SELECT * FROM  dataentry_cow_card  ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query!=nullptr) DataSystems::Instance().dataentry_cow_card_counter = query->size();
        }

        {
        QString sql =  QString("SELECT * FROM  dataentry_fixed_feeding  ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query!=nullptr) DataSystems::Instance().dataentry_fixed_feeding_counter = query->size();
        }
        //dataentry_fixed_feeding

        {
        QString sql =  QString("SELECT * FROM  dataentry_transfer  ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query!=nullptr) DataSystems::Instance().dataentry_transfer_counter = query->size();
        }

        {
        QString sql =  QString("SELECT * FROM  dataentry_otel  ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query!=nullptr) DataSystems::Instance().dataentry_otel_counter = query->size();
        }

        {
        QString sql =  QString("SELECT * FROM  dataentry_insemenation  ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query!=nullptr) DataSystems::Instance().dataentry_insemenation_counter = query->size();
        }

        {
        QString sql =  QString("SELECT * FROM  dataentry_dry_off  ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query!=nullptr) DataSystems::Instance().dataentry_dry_off_counter = query->size();
        }

        {
        QString sql =  QString("SELECT * FROM  dataentry_milk_separation  ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query!=nullptr) DataSystems::Instance().dataentry_milk_separation_counter = query->size();
        }

        {
        QString sql =  QString("SELECT * FROM  dataentry_milk_settings  ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query!=nullptr) DataSystems::Instance().dataentry_milk_settings_counter = query->size();
        }

        {
        QString sql =  QString("SELECT * FROM  dataentry_routing  ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query!=nullptr) DataSystems::Instance().dataentry_routing_counter = query->size();
        }
    }
    else
    {
        qDebug()<<"connect database: -1";

    }
}

void Form_1_2::SelectionChanged(const QItemSelection& selection)
{
    //
    //UpdateList();

    QModelIndex index = selection.indexes().first();
    QString listCheck = index.data(Qt::DisplayRole).toString();

    qDebug()<<listCheck;

    if (listCheck.contains("робот"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            form_dataentry_Robot *tr = new form_dataentry_Robot(this);
            ui->horizontalLayout->addWidget(tr);
            return;
        }

        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        form_dataentry_Robot *tr = new form_dataentry_Robot(this);
        ui->horizontalLayout->addWidget(tr);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    else if (listCheck.contains("Перевод"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            form_dataentry_dataentry___transfer *tf = new form_dataentry_dataentry___transfer(this);
            ui->horizontalLayout->addWidget(tf);
            return;
        }

        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        form_dataentry_dataentry___transfer *tf = new form_dataentry_dataentry___transfer(this);
        ui->horizontalLayout->addWidget(tf);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    else if(listCheck.contains("Пакетная базовая"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            Table_Form_1_2 *tf_1_2 = new Table_Form_1_2(this);
            ui->horizontalLayout->addWidget(tf_1_2);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        Table_Form_1_2 *tf_1_2 = new Table_Form_1_2(this);
        ui->horizontalLayout->addWidget(tf_1_2);

    }
    else  if (listCheck.contains("Карточки коров"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            Form_List_Cows *f_1_9_add_cow = new Form_List_Cows(this);
            ui->horizontalLayout->addWidget(f_1_9_add_cow);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        Form_List_Cows *f_1_9_add_cow = new Form_List_Cows(this);

        ui->horizontalLayout->addWidget(f_1_9_add_cow);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    else  if (listCheck.contains("Cепарация молока"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            form_dataentry_dataentry___milk_separationoff *tf = new form_dataentry_dataentry___milk_separationoff(this);
            ui->horizontalLayout->addWidget(tf);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        form_dataentry_dataentry___milk_separationoff *tf = new form_dataentry_dataentry___milk_separationoff(this);
        ui->horizontalLayout->addWidget(tf);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    else  if (listCheck.contains("Пакетный перевод"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            Table_Form_1_2_batch_transfer *tf_1_2 = new Table_Form_1_2_batch_transfer(this);
            ui->horizontalLayout->addWidget(tf_1_2);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        Table_Form_1_2_batch_transfer *tf_1_2_bf = new Table_Form_1_2_batch_transfer(this);
        ui->horizontalLayout->addWidget(tf_1_2_bf);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }    
    else  if (listCheck.contains("Сухостойность"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            form_dataentry_dataentry___dry_off *tf = new form_dataentry_dataentry___dry_off(this);
            ui->horizontalLayout->addWidget(tf);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        form_dataentry_dataentry___dry_off *tf = new form_dataentry_dataentry___dry_off(this);
        ui->horizontalLayout->addWidget(tf);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";
    }

    else  if (listCheck.contains("Отел"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            table_form_1_2_otel *tf_1_2 = new table_form_1_2_otel(this);
            ui->horizontalLayout->addWidget(tf_1_2);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        table_form_1_2_otel *tf_1_2_bf = new table_form_1_2_otel(this);
        ui->horizontalLayout->addWidget(tf_1_2_bf);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    else  if (listCheck.contains("Маршрутизация"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            Form_dataentry_routing_6_6_1 *tf_1_2 = new Form_dataentry_routing_6_6_1(this);
            ui->horizontalLayout->addWidget(tf_1_2);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        Form_dataentry_routing_6_6_1 *tf_1_2_bf = new Form_dataentry_routing_6_6_1(this);
        ui->horizontalLayout->addWidget(tf_1_2_bf);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    else  if (listCheck.contains("Осеменение"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            form_1_9_insemenation_s *f_1_9_insemenation = new form_1_9_insemenation_s(this);
            ui->horizontalLayout->addWidget(f_1_9_insemenation);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        form_1_9_insemenation_s *f_1_9_insemenation = new form_1_9_insemenation_s(this);
        ui->horizontalLayout->addWidget(f_1_9_insemenation);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    else  if (listCheck.contains("Фиксированное кормление"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            Form_dataentry_dataentry___fixed_feeding *f_de_ff = new Form_dataentry_dataentry___fixed_feeding(this);
            ui->horizontalLayout->addWidget(f_de_ff);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        Form_dataentry_dataentry___fixed_feeding *f_de_ff = new Form_dataentry_dataentry___fixed_feeding(this);
        ui->horizontalLayout->addWidget(f_de_ff);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    //"Настройки локтации "
    else  if (listCheck.contains("Настройки локтации435345"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            form_dataentry_dataentry___milk_settings *page = new form_dataentry_dataentry___milk_settings(this);
            ui->horizontalLayout->addWidget(page);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        form_dataentry_dataentry___milk_settings *page = new form_dataentry_dataentry___milk_settings(this);
        ui->horizontalLayout->addWidget(page);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    else  if (listCheck.contains("Настройки локтации"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            form_dataentry_dataentry___milk_settings *page = new form_dataentry_dataentry___milk_settings(this);
            ui->horizontalLayout->addWidget(page);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        form_dataentry_dataentry___milk_settings *page = new form_dataentry_dataentry___milk_settings(this);
        ui->horizontalLayout->addWidget(page);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }    
    //Взятие проб у партии
    else  if (listCheck.contains("Взятие проб у партии"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            form_dataentry_dataentry___Batch_Sampling *page = new form_dataentry_dataentry___Batch_Sampling(this);
            ui->horizontalLayout->addWidget(page);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        form_dataentry_dataentry___Batch_Sampling *page = new form_dataentry_dataentry___Batch_Sampling(this);
        ui->horizontalLayout->addWidget(page);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    //"Кондиция партии"
    else  if (listCheck.contains("Кондиция партии"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            form_dataentry_dataentry___batch_condition *page = new form_dataentry_dataentry___batch_condition(this);
            ui->horizontalLayout->addWidget(page);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        form_dataentry_dataentry___batch_condition *page = new form_dataentry_dataentry___batch_condition(this);
        ui->horizontalLayout->addWidget(page);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }

    else
    {

        if(ui->horizontalLayout->count()<1) return;
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        table_form_1_2_in_work *tf_1_2_in = new table_form_1_2_in_work(this);
        ui->horizontalLayout->addWidget(tf_1_2_in);

    }

}

Form_1_2::~Form_1_2()
{
    delete ui;
}

