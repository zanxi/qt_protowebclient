#include "table_form_1_2_batch_transfer.h"
#include "ui_table_form_1_2_batch_transfer.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"

#include "BuildData/json_w.h"

#include <QLineEdit>
#include <QCompleter>
#include <QStringList>
#include <QDateTime>
#include <QList>
#include <QTableWidgetItem>


Table_Form_1_2_batch_transfer::Table_Form_1_2_batch_transfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table_Form_1_2_batch_transfer)
{
    ui->setupUi(this);

    auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

    //QMap<QString, QString> allColumns = json_w::form_table("table_form_1_2_bf.json");
    QList<QString> allColumns = json_w::form_table2("table_form_1_2_bf.json");
    //qDebug()<< " ||| " << allTabs.count() << " ||| " ;
    //QString firstColumn = allColumns.keys().first();
    //QList<QString> tab = allTabs.value(firstTab);
    //qDebug()<< " ||| " << firstColumn << " ||| " ;
    QStringList NameColumns;
    int i=0;
    foreach (QString cols, allColumns)
    {
        //NameColumns.append(allColumns[key]);        
        //ui->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(cols));
        qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
        i++;
        NameColumns<<cols;
    }

    ui->tableWidget->setColumnCount( allColumns.count() );
    ui->tableWidget->setRowCount( 1 );


    //header = ui->tableWidget->horizontalHeader();
    //ui->tableWidget->setSectionResizeMode(0, QtWidgets.QHeaderView.Stretch)
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));

    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
    //ui->tableWidget->setHorizontalHeaderItem(0, );
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //QStringList wordList;
    //wordList << "alpha" << "omega" << "omega2" << "omega3" <<"omicron" << "zeta";

    ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
    ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
    ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);

    for(int i=0;i<1;i++)
    {
        //for(int j=0;j<allColumns.count();j++)
        {            
            QLineEdit *lineEdit_animal = new QLineEdit();
            lineEdit_animal->installEventFilter(this);
            lineEdit_animal->setText(QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,0,lineEdit_animal);

            QLineEdit *lineEdit_responder = new QLineEdit();
            lineEdit_responder->installEventFilter(this);
            lineEdit_responder->setText(QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,1,lineEdit_responder);

            QLineEdit *lineEdit_life_number = new QLineEdit();
            lineEdit_life_number->installEventFilter(this);
            lineEdit_life_number->setText(QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,2,lineEdit_life_number);

            QLineEdit *lineEdit_loctation_no = new QLineEdit();
            lineEdit_loctation_no->installEventFilter(this);
            lineEdit_loctation_no->setText(QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,4,lineEdit_loctation_no);

            ui->tableWidget->setItem( i, 3,  new QTableWidgetItem(QDate().currentDate().toString()));
            ui->tableWidget->setItem( i, 5,  new QTableWidgetItem(QDate().currentDate().toString()));
            ui->tableWidget->setItem( i, 6,  new QTableWidgetItem(QDate().currentDate().toString()));

            //ui->tableWidget->setItem( i, 0,  new QTableWidgetItem(QString::number(rand()%2222)));
            //ui->tableWidget->setItem( i, 1,  new QTableWidgetItem(QString::number(rand()%2222)));
            //tw->setItem( i, 1,  new QTableWidgetItem("one"));
            //tw->setItem( i, 2,  new QTableWidgetItem(QString::number(rand()%3333)));

            //auto dateTime = new QDateTime();
            //dateTime->setDate(QDate().currentDate());
            //ui->tableWidget->setItemDelegate(i, 0,  dateTime);
            //ui->tableWidget->setCellWidget(i, 0,  dateTime);

            //QDateTime *dateTime = new QDateTime();
            //QCompleter *completer = new QCompleter(wordList);
            //completer->setCaseSensitivity(Qt::CaseInsensitive);
            //dateTime->  ->installEventFilter(this);
            //lineEdit->setCompleter(completer);
            //dateTime->setTime(QTime().currentTime());
            //ui->tableWidget->setCellWidget(i,i,lineEdit);
            //ui->tableWidget->setCellWidget(i,2,dateTime);
        }
    }
}

Table_Form_1_2_batch_transfer::~Table_Form_1_2_batch_transfer()
{
    delete ui;
}
