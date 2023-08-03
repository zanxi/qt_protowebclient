#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "debug/logger.h"

#include "FormsMenu/form_1_1.h"
#include "FormsMenu/form_1_2.h"
#include "FormsMenu/form_1_2_general.h"
//#include "FormsMenu/form_tabview.h"
#include "form_2_1.h"

#include "AdminPanel/mainwidget.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //if (objectName().isEmpty())  setObjectName(QString::fromUtf8("VIM"));
    //setObjectName(QString::fromUtf8("VIM"));
    setWindowTitle("ВИМ");

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    setGeometry(QRect(200, 100, 1600, 800));

    ui->widget_title->setStyleSheet("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #14B143, stop:1 #14B143);"
                                    "foreground: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #FFFFFF, stop:1 #FFFFFF);");
    ui->widget_title_2->setStyleSheet("background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #14B143, stop:1 #14B143);"
                                    "foreground: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #FFFFFF, stop:1 #FFFFFF);");

    w_m = new Widget_menu();
    ui->verticalLayout->addWidget(w_m);

    //w_f = new Widget_Form();
    //ui->verticalLayout_2->addWidget(w_f);

    Form_2_1 *w_f_2_1 = new Form_2_1();
    ui->verticalLayout_2->addWidget(w_f_2_1);
    //w_f = new Widget_Form();
    //ui->verticalLayout_2->addWidget(w_f);

    connect(this, &MainWindow::signal, w_m, &Widget_menu::slot);
    connect(w_m, &Widget_menu::signalMenu, this, &MainWindow::slotMenu);


}

void MainWindow::slotMenu(QString val)
{
    //ui->verticalLayout_2.de;
    //logger::WriteMsg("sent signal From Widget_menu to MainWindow: "+val.toStdString());

    //qDebug()<<"value tree item: "<<val;

    //return;

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
        if(val.contains("Глобальные установки фермы"))
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
           fm = new Form_2_1;
        }
        ui->verticalLayout_2->addWidget(fm);

//    ui.tabWidget->insertTab(0,fe_1_1,QString("Ферма"));
//    Form_1_2 *fe_1_2 = new Form_1_2;
//    ConnectionDialog dialog(this);
//    //dialog.show();
//    Form_tabview *form_tabvie = new Form_tabview(
//        dialog.username(),
//        dialog.password(),
//        dialog.hostname(),
//        dialog.databasename(),
//        this);

//    QHBoxLayout *hlayot = new QHBoxLayout();     // горизонтальный слой с кнопками
//    hlayot->addWidget(fe_1_2);
//    //hlayot->addSpacing(300);
//    hlayot->addWidget(form_tabvie);
//    //hlayot->addSpacing(300);
//    //hlayot->addSpacing(300);

//    QWidget *placeholderWidget = new QWidget;        //  стандартный приём, добавляем главный слой на простой виджет, и этот виджет делаем центральным. Т.к.  setCentralWidget принимает лишь виджет.
//    placeholderWidget->setLayout(hlayot);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    //admin = new mainWidget;
    admin2 = new AdminWidget();
    //admin.setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint);
    admin2->show();

}

