#include "form_dataentry_dataentry___batch_condition.h"
#include "ui_form_dataentry_dataentry___batch_condition.h"

#include "dataanimals.h"
#include <QLineEdit>


form_dataentry_dataentry___batch_condition::form_dataentry_dataentry___batch_condition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_dataentry_dataentry___batch_condition)
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
    ui->groupBox_2->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                      "padding: 4 20000 4 10;"
                                                                                      "}");

    for(int i=0; i<ui->tableWidget->columnCount();i++)
        ui->tableWidget->setColumnWidth(i, this->width()/(ui->tableWidget->columnCount()+1));

    GetData();

}

void form_dataentry_dataentry___batch_condition::GetData()
{
    //ui->tableWidget->col->clear();
    QString tab = "dataentry_settings____milking__general_milking";

    //QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    //if(db_func->StatusOpen())
    {
        QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
        //QSqlQuery* query = db_func->sql_exec2(sql);
        //if(query->size()<1)return;
        int i=0;

        ui->tableWidget->insertRow( ui->tableWidget->rowCount() );


        i=0;
        //while(query->next())
        for(i=0;i<3;i++)
        {
            {
                QLineEdit *lineedit = new QLineEdit();
                lineedit->installEventFilter(this);
                lineedit->setText("");
                ui->tableWidget->setCellWidget( i, 0,  lineedit );
            }

            {
                QLineEdit *lineedit = new QLineEdit();
                lineedit->installEventFilter(this);
                lineedit->setText("");
                ui->tableWidget->setCellWidget( i, 1,  lineedit );
            }
            {
                QLineEdit *lineedit = new QLineEdit();
                lineedit->installEventFilter(this);
                lineedit->setText("");
                ui->tableWidget->setCellWidget( i, 2,  lineedit );
            }
            {
                QLineEdit *lineedit = new QLineEdit();
                lineedit->installEventFilter(this);
                lineedit->setText("");
                ui->tableWidget->setCellWidget( i, 3,  lineedit );
            }
            {
                QLineEdit *lineedit = new QLineEdit();
                lineedit->installEventFilter(this);
                lineedit->setText("");
                ui->tableWidget->setCellWidget( i, 4,  lineedit );
            }




            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            //i++;
        }
    }


    /**/

}

form_dataentry_dataentry___batch_condition::~form_dataentry_dataentry___batch_condition()
{
    delete ui;
}
