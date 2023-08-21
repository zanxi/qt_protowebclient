#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "debug/logger.h"

#include "FormsMenu/form_1_1.h"
#include "FormsMenu/form_1_2.h"
#include "FormsMenu/form_1_2_general.h"

#include "form_2_1.h"
#include "form_in_work.h"
#include "AdminPanel/mainwidget.h"

#include "dataanimals.h"
#include "db/SqlDataBase.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("ВИМ");

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    setGeometry(QRect(200, 100, 1600, 800));

    ui->widget_title->setStyleSheet("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #14B143, stop:1 #14B143);"
                                    "foreground: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #FFFFFF, stop:1 #FFFFFF);");
    ui->widget_title_2->setStyleSheet("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #14B143, stop:1 #14B143);"
                                    "foreground: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #FFFFFF, stop:1 #FFFFFF);");


    logger::ClearLog();
    DataSystems::Instance().clear();

    SqlDataBase::DropTables();
    SqlDataBase::DropDataBase(DataSystems::Instance().db_name.toStdString());
    SqlDataBase::UseDataBase("Use "+DataSystems::Instance().db_name.toStdString()+";");
    SqlDataBase::CreateDataBase(DataSystems::Instance().db_name.toStdString());
    SqlDataBase::CreateTables();
    SqlDataBase::AllTablesInsert();
    SqlDataBase::DropTables();
    SqlDataBase::TablesUpdate();
    SqlDataBase::DropDataBase(DataSystems::Instance().db_name.toStdString());

    DataSystems::Instance().db = new DataBase();
    if(DataSystems::Instance().db->Open())
    {
        //DataSystems::Instance().db->sql_exec("DROP TABLE DataService;");
        //DataSystems::Instance().db->sql_exec("CREATE TABLE IF NOT EXISTS  DataService(AnimalsId text NOT NULL,NumberAnswerId text NOT NULL,GroupId text NOT NULL,LabelId text NOT NULL,CONSTRAINT RIndication_pkey PRIMARY KEY (RecordId));");

        //DataSystems::Instance().db->DropTables();

        DataSystems::Instance().db->createTables();
        DataSystems::Instance().db->FillValue();
    }


    w_m = new Widget_menu();
    ui->verticalLayout->addWidget(w_m);

    Form_2_1 *w_f_2_1 = new Form_2_1();
    ui->verticalLayout_2->addWidget(w_f_2_1);

    connect(this, &MainWindow::signal, w_m, &Widget_menu::slot);
    connect(w_m, &Widget_menu::signalMenu, this, &MainWindow::slotMenu);

}

void MainWindow::slotMenu(QString val)
{
    QLayoutItem *child = ui->verticalLayout_2->takeAt(0);
    //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)

        if(!child) {return;}
        QWidget* w = child->widget();

        delete child;
        if(!w) {return;}
        ui->verticalLayout_2->removeWidget(w);
        delete w;
        //child = ui->verticalLayout_2->takeAt(0);               

    //************************************************************

        if(!CollectionAction.contains(val)){
            CollectionAction.insert(val, new QWidget(this));
            logger::WriteMsg("Action button <<<TREE ITEM>>> treeview: "+val.toStdString());
        }

        QWidget *fm;
        if(val.contains("Начало"))
        {
                 fm = new Form_2_1;
            qDebug()<<"Начало работает";
        }
        else if(val.contains("Глобальные установки фермы"))
        {
                 fm = new Form_1_1;
        }
        else if(val.contains("Дневная запись"))
        {
                 fm = new Form_1_2;
        }
        else if(val.contains("Группы"))
        {
                 fm = new Form_1_2_General;
        }        
        else
        {
           //fm = new Form_1_2_General;
           fm = new Form_in_work;
        }

        ui->verticalLayout_2->addWidget(fm);

}

MainWindow::~MainWindow()
{
    if(DataSystems::Instance().db!=nullptr) DataSystems::Instance().db->closeDataBase();
    delete ui;
}


void MainWindow::on_action_triggered()
{
    //admin = new mainWidget;
    admin2 = new AdminWidget();
    //admin.setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);
    admin2->show();

}

