#include "form_1_2_general.h"
#include "ui_form_1_2_general.h"

Form_1_2_General::Form_1_2_General(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_1_2_General)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
}

Form_1_2_General::~Form_1_2_General()
{
    delete ui;
}
