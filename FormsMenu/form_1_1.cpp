#include "form_1_1.h"
#include "ui_form_1_1.h"

Form_1_1::Form_1_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_1_1)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
}

Form_1_1::~Form_1_1()
{
    delete ui;
}
