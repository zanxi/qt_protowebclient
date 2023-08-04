#include "form_z_1.h"
#include "ui_form_z_1.h"

#include "FormsMenu/form_1_1.h"
#include "FormsMenu/form_1_2.h"

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

    // ***********************************

    ui->groupBox->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:#14B143;"
                                  "padding: 4 20000 4 10;"
                                  "}");


    // ************************************
    Form_1_1 *fe_1_1 = new Form_1_1;
    ui->tabWidget->insertTab(0,fe_1_1,QString("Ферма"));
    Form_1_2 *fe_1_2 = new Form_1_2;
    ConnectionDialog dialog(this);
    //dialog.show();

    QHBoxLayout *hlayot = new QHBoxLayout();     // горизонтальный слой с кнопками
    hlayot->addWidget(fe_1_2);
    //hlayot->addSpacing(300);
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
