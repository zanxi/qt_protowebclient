#include "table_form_1_2_in_work.h"
#include "ui_table_form_1_2_in_work.h"

table_form_1_2_in_work::table_form_1_2_in_work(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::table_form_1_2_in_work)
{
    ui->setupUi(this);

    ui->groupBox_2->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:#14B143;"
                                  "padding: 4 20000 4 10;"
                                  "}");

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:#14B143;"
                                "padding: 4 20000 4 10;"
                                "}");

    ui->tableWidget->hideColumn(0);



}

table_form_1_2_in_work::~table_form_1_2_in_work()
{
    delete ui;
}
