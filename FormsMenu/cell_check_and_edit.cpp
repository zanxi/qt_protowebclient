#include "cell_check_and_edit.h"
#include "ui_cell_check_and_edit.h"

cell_check_and_edit::cell_check_and_edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cell_check_and_edit)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
}

cell_check_and_edit::~cell_check_and_edit()
{
    delete ui;
}
