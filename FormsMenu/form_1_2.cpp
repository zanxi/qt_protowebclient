#include "form_1_2.h"
#include "ui_form_1_2.h"

Form_1_2::Form_1_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_1_2)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
}

Form_1_2::~Form_1_2()
{
    delete ui;
}
