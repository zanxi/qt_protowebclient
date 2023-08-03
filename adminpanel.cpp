#include "adminpanel.h"
#include "ui_adminpanel.h"

AdminPanel::AdminPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
}

AdminPanel::~AdminPanel()
{
    delete ui;
}
