#include "form_z_1.h"
#include "ui_form_z_1.h"

#include "FormsMenu/form_1_1.h"
#include "FormsMenu/form_1_2.h"
#include "FormsMenu/form_tabview.h"

#include "connectiondialog.h"


Form_Z_1::Form_Z_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_Z_1)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    setGeometry(QRect(600, 100, 900, 700));

    // ************************************
    Form_1_1 *fe_1_1 = new Form_1_1;
    ui->tabWidget->insertTab(0,fe_1_1,QString("Ферма"));
    Form_1_2 *fe_1_2 = new Form_1_2;
    ConnectionDialog dialog(this);
    //dialog.show();
    Form_tabview *form_tabvie = new Form_tabview(
        dialog.username(),
        dialog.password(),
        dialog.hostname(),
        dialog.databasename(),
        this);

    QHBoxLayout *hlayot = new QHBoxLayout();     // горизонтальный слой с кнопками
    hlayot->addWidget(fe_1_2);
    //hlayot->addSpacing(300);
    hlayot->addWidget(form_tabvie);
    //hlayot->addSpacing(300);
    //hlayot->addSpacing(300);

    QWidget *placeholderWidget = new QWidget;        //  стандартный приём, добавляем главный слой на простой виджет, и этот виджет делаем центральным. Т.к.  setCentralWidget принимает лишь виджет.
    placeholderWidget->setLayout(hlayot);

    ui->tabWidget->insertTab(1,placeholderWidget,"Стада");

}

Form_Z_1::~Form_Z_1()
{
    delete ui;
}
