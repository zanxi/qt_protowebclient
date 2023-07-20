#include "form_2_1.h"
#include "ui_form_2_1.h"

Form_2_1::Form_2_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_2_1)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    //setGeometry(QRect(600, 100, 900, 700));
}

Form_2_1::~Form_2_1()
{
    delete ui;
}
