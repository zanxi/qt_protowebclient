#include "table_form_1_2_batch_transfer.h"
#include "ui_table_form_1_2_batch_transfer.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"

#include "json/json_w.h"

#include <QLineEdit>
#include <QCompleter>
#include <QStringList>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QList>
#include <QTableWidgetItem>

#include "dataanimals.h"
#include "qlineeditext.h"


Table_Form_1_2_batch_transfer::Table_Form_1_2_batch_transfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table_Form_1_2_batch_transfer)
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

    ui->pushButton->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );


    // **************** group radiobutton ********************************
    operatingModeGroup = new QButtonGroup(this);
    operatingModeGroup->addButton(ui->radioButton_start, OM_Start);
    operatingModeGroup->addButton(ui->radioButton_transfer, OM_Transfer);
    connect(operatingModeGroup, SIGNAL(buttonToggled(int,bool)), this, SLOT(operatingModeButtonsToggled(int,bool)));
    connect(operatingModeGroup, SIGNAL(buttonClicked(int)), this, SLOT(operatingModeButtonsClicked(int)));
    // *******************************************************************

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
    ui->tableWidget->setRowCount( 10 );

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
    for(int i=0;i<allColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);


    //QStringList wordList;
    //wordList << "alpha" << "omega" << "omega2" << "omega3" <<"omicron" << "zeta";

    ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
    ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
    ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);
    //ui->tableWidget->hideColumn(0);

    for(int i=0;i<5;i++)
    {
        //for(int j=0;j<allColumns.count();j++)
        {
            QLineEditExt *lineEdit_animal = new QLineEditExt(this);
            lineEdit_animal->installEventFilter(this);
            lineEdit_animal->setText(QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,0,lineEdit_animal);
            lineEdit_animal->row = i;
            lineEdit_animal->row = 0;
            connect(lineEdit_animal, &QLineEdit::textEdited, lineEdit_animal,
                    [=](const QString & text)
                    {
                        qDebug() << "changed lineedit [text]: "<<text<<"; row: "<<i<<"; col: "<<0;

                    });

            QLineEditExt *lineEdit_responder = new QLineEditExt(this);
            lineEdit_responder->installEventFilter(this);
            lineEdit_responder->setText(QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,1,lineEdit_responder);
            lineEdit_responder->row = i;
            lineEdit_responder->row = 1;
            connect(lineEdit_responder, &QLineEdit::textEdited, lineEdit_responder,
                    [=](const QString & text)
                    {
                        qDebug() << "changed lineedit [text]: "<<text<<"; row: "<<i<<"; col: "<<1;

                    });

            QLineEditExt *lineEdit_life_number = new QLineEditExt(this);
            lineEdit_life_number->installEventFilter(this);
            lineEdit_life_number->setText(QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,2,lineEdit_life_number);
            lineEdit_life_number->row = i;
            lineEdit_life_number->row = 2;
            connect(lineEdit_life_number, &QLineEdit::textEdited, lineEdit_life_number,
                    [=](const QString & text)
                    {
                        qDebug() << "changed lineedit [text]: "<<text<<"; row: "<<i<<"; col: "<<2;

                    });

            QLineEditExt *lineEdit_loctation_no = new QLineEditExt(this);
            lineEdit_loctation_no->installEventFilter(this);
            lineEdit_loctation_no->setText(QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,4,lineEdit_loctation_no);
            lineEdit_loctation_no->row = i;
            lineEdit_loctation_no->row = 4;
            connect(lineEdit_loctation_no, &QLineEdit::textEdited, lineEdit_loctation_no,
                    [=](const QString & text)
                    {
                           qDebug() << "changed lineedit [text]: "<<text<<"; row: "<<i<<"; col: "<<4;

                    });

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

    //connect(ui->tableWidget, SIGNAL(cellChanged(int, int) ),ui->tableWidget, SLOT(ProtocolChanged(int, int)) );

    //connect(ui->tableWidget, SIGNAL(cellChanged(int, int) ),ui->tableWidget,
    QObject::connect(ui->tableWidget, &QTableWidget::cellChanged,
                     ui->tableWidget,
    [=](int row, int col) {
        QString text = ui->tableWidget->item(row,col)->text();
        qDebug() << "In slot:: [text]: "<<text<<"; col: "<<col;

        if(col==1 || col==2 || col==4)
        {
            //QLineEdit* lineedit = (QLineEdit*)ui->tableWidget->cellWidget(row,col);
            qDebug() << "lineedit [text]: "<<text;
        }

        //ui->tableWidget->setCurrentIndex(index);
        //qDebug() << "Calling edit() "+index.data().toString();
        //ui->tableWidget->edit(index);

//        int row = ui->tableWidget->currentRow();
//        int col = ui->tableWidget->currentColumn();
//        qDebug() << "Called edit(): "+index.data().toString()+" | " + QString::number(row);
//        //QString label = ui->tableWidget->verticalHeaderItem(row)->text();
//        QString parameter = ui->tableWidget->horizontalHeaderItem(col)->text();
//        QString value = index.data().toString();
//        //qDebug() << "Called edit(): "+index.data().toString()+" | " + QString::number(row) +" | " + label;

//        QString sql="UPDATE " + tab + " SET "+parameter+" = '"+value;

        //ui->textEdit->append("("+QString::number(row)+", "+QString::number(col) +") -- Called edit(): "+index.data().toString()+" | " + QString::number(col) +" | " + label);
    });
}

void Table_Form_1_2_batch_transfer::operatingModeButtonsToggled(int id, bool status)
{

    int tmp = operatingModeGroup->checkedId();
    switch(tmp){
    case operatingModeTypes::OM_Start:
         break;
    case operatingModeTypes::OM_Transfer:
         break;
    }
    QString str = operatingModeGroup->checkedButton()->text();
    QByteArray byteArray = str.toLocal8Bit();
    qDebug("flag = %d, status = %d, tmp = %d, checked = %s", id, status, tmp, byteArray.data());
}
void Table_Form_1_2_batch_transfer::operatingModeButtonsClicked(int id)
{

    //qDebug("Clicked: %d", id);

    //operatingModeGroup->
    if(id==0);
}


Table_Form_1_2_batch_transfer::~Table_Form_1_2_batch_transfer()
{
    delete ui;
}

void Table_Form_1_2_batch_transfer::on_comboBox_2_activated(int index)
{

}


void Table_Form_1_2_batch_transfer::on_comboBox_activated(int index)
{

}


void Table_Form_1_2_batch_transfer::on_comboBox_3_activated(int index)
{

}


void Table_Form_1_2_batch_transfer::on_pushButton_clicked()
{
    QMessageBox::information(this,"Спасибо","Сохранены данные");
}

