#include "form_maintenance___backup_restoree_dialog.h"
#include "ui_form_maintenance___backup_restoree_dialog.h"

#include "dataanimals.h"

form_maintenance___backup_restoree_Dialog::form_maintenance___backup_restoree_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_maintenance___backup_restoree_Dialog)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    //setGeometry(QRect(600, 100, 900, 700));

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                    "padding: 4 20000 4 10;"
                                                                                    "}");



    ui->pushButton_download->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_close->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

}

form_maintenance___backup_restoree_Dialog::~form_maintenance___backup_restoree_Dialog()
{
    delete ui;
}

void form_maintenance___backup_restoree_Dialog::on_pushButton_download_clicked()
{

}


void form_maintenance___backup_restoree_Dialog::on_pushButton_close_clicked()
{
    this->close();
}

