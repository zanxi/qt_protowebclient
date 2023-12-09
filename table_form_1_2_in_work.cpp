#include "table_form_1_2_in_work.h"
#include "ui_table_form_1_2_in_work.h"

#include "dataanimals.h"

table_form_1_2_in_work::table_form_1_2_in_work(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::table_form_1_2_in_work)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    ui->groupBox_2->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:"+DataSystems::Instance().settings___color_header+";"
                                  "padding: 4 20000 4 10;"
                                  "}");

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:"+DataSystems::Instance().settings___color_header+";"
                                "padding: 4 20000 4 10;"
                                "}");

    ui->groupBox_3->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                    "padding: 4 20000 4 10;"
                                                                                    "}");

    //ui->tableWidget->hideColumn(0);




}

table_form_1_2_in_work::~table_form_1_2_in_work()
{
    delete ui;
}
