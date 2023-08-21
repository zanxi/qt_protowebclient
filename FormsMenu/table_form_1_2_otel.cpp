#include "table_form_1_2_otel.h"
#include "ui_table_form_1_2_otel.h"
#include "tabelwidget_module/datetimestyleditemdelegate.h"

#include "json/json_w.h"

#include <QCheckBox>

table_form_1_2_otel::table_form_1_2_otel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::table_form_1_2_otel)
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



    auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

    QList<QString> allColumns = json_w::form_table2("table_form_1_2_otel.json");
    QStringList NameColumns;
    int i=0;
    NameColumns<<" ";
    foreach (QString cols, allColumns)
    {
        qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
        i++;
        NameColumns<<cols;
    }

    ui->tableWidget->setColumnCount( allColumns.count()+1 );
    ui->tableWidget->setRowCount( 20 );

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    ui->tableWidget->hideColumn(0);


    //QStringList wordList;
    //wordList << "alpha" << "omega" << "omega2" << "omega3" <<"omicron" << "zeta";

    ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
    ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
    ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);


    for(int i=0;i<20;i++)
    {
        for(int j=1;j<allColumns.count()+1;j++)
        {
            auto check = new QCheckBox();
            check->setCheckState(((rand()%2==1)?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked)));
            ui->tableWidget->setCellWidget(i, 0,  check);

            ui->tableWidget->setItem( i, j,  new QTableWidgetItem(QString::number(rand()%444)));
            //ui->tableWidget->setItem( i, 2,  new QTableWidgetItem(QString::number(rand()%444)));
            //ui->tableWidget->setItem( i, 3,  new QTableWidgetItem(QString::number(rand()%444)));
            //ui->tableWidget->setItem( i, j,  new QTableWidgetItem(QString::number(rand()%444)));
        }
    }



}

table_form_1_2_otel::~table_form_1_2_otel()
{
    delete ui;
}
