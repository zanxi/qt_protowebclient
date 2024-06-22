#include "dialog_form_dataentry_settings___post_during.h"
#include "ui_dialog_form_dataentry_settings___post_during.h"

#include "dataanimals.h"

// Дневная запись -> Настройки -> Во время доения

Dialog_form_dataentry_settings___post_during::Dialog_form_dataentry_settings___post_during(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_form_dataentry_settings___post_during)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                    "padding: 4 20000 4 10;"
                                                                                    "}");

    ui->pushButton_save->setStyleSheet(
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

Dialog_form_dataentry_settings___post_during::~Dialog_form_dataentry_settings___post_during()
{
    delete ui;
}

void Dialog_form_dataentry_settings___post_during::on_pushButton_close_clicked()
{
    this->close();
}


void Dialog_form_dataentry_settings___post_during::on_pushButton_save_clicked()
{



}

