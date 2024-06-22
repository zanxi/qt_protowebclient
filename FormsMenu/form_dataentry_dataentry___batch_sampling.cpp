#include "form_dataentry_dataentry___batch_sampling.h"
#include "ui_form_dataentry_dataentry___batch_sampling.h"

#include "dataanimals.h"

#include <QCheckBox>
#include <QLineEdit>

form_dataentry_dataentry___Batch_Sampling::form_dataentry_dataentry___Batch_Sampling(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_dataentry_dataentry___Batch_Sampling)
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

    ui->pushButton_save->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_clear->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    for(int i=0; i<ui->tableWidget->columnCount();i++)
        ui->tableWidget->setColumnWidth(i, this->width()/ui->tableWidget->columnCount());

    GetData();

}


void form_dataentry_dataentry___Batch_Sampling::GetData()
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
        for(i=0;i<14;i++)
        {
            QCheckBox *checkbox = new QCheckBox();
            checkbox->installEventFilter(this);
            checkbox->setText("");
            checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
            //ui->tableWidget_general_milking->setCellWidget(i,0,checkbox);
            ui->tableWidget->setItem( i, 0,  new QTableWidgetItem( QString::number((rand()%4378) )));

            {
               QLineEdit *lineedit = new QLineEdit();
               lineedit->installEventFilter(this);
               lineedit->setText(QString::number((rand()%43/71.0)));
               ui->tableWidget->setCellWidget( i, 1,  lineedit );
            }
            {
               QLineEdit *lineedit = new QLineEdit();
               lineedit->installEventFilter(this);
               lineedit->setText(QString::number((rand()%43/71.0)));
               ui->tableWidget->setCellWidget( i, 2,  lineedit );
            }
            {
               QLineEdit *lineedit = new QLineEdit();
               lineedit->installEventFilter(this);
               lineedit->setText(QString::number((rand()%43/71.0)));
               ui->tableWidget->setCellWidget( i, 3,  lineedit );
            }
            {
               QLineEdit *lineedit = new QLineEdit();
               lineedit->installEventFilter(this);
               lineedit->setText(QString::number((rand()%43/71.0)));
               ui->tableWidget->setCellWidget( i, 4,  lineedit );
            }
            {
               QLineEdit *lineedit = new QLineEdit();
               lineedit->installEventFilter(this);
               lineedit->setText(QString::number((rand()%43/71.0)));
               ui->tableWidget->setItem( i, 5,  new QTableWidgetItem( QString::number((rand()%4378) )));
            }



            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            //i++;
        }
    }


    /**/

}


form_dataentry_dataentry___Batch_Sampling::~form_dataentry_dataentry___Batch_Sampling()
{
    delete ui;
}

void form_dataentry_dataentry___Batch_Sampling::on_pushButton_clear_clicked()
{

}


void form_dataentry_dataentry___Batch_Sampling::on_pushButton_clear_2_clicked()
{

}


void form_dataentry_dataentry___Batch_Sampling::on_pushButton_save_clicked()
{

}

