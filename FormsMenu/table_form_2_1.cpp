#include "table_form_2_1.h"
#include "ui_table_form_2_1.h"

#include "tabelwidget_module/comboboxitemdelegate.h"
#include "tabelwidget_module/spinboxitemdelegate.h"
#include "tabelwidget_module/checkboxitemdelegate.h"

#include <QPushButton>
#include <QLabel>

#include "json/json_w.h"

#include "dataanimals.h"

#include "dataanimals.h"
#include "Debug/logger.h"


#include <QMessageBox>
#include <QMessageBox>

//#include "tabelwidget_module2/CustomDelegateView.h"
#include "tabelwidget_module2/customdelegate.h"




// ************** Начало *********************************
Table_Form_2_1::Table_Form_2_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table_Form_2_1)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    ui->tableWidget_lists_signals->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    ui->groupBox->setStyleSheet("QGroupBox {"
                            "background-color: white;"
                            "}"
                            "QGroupBox::title {"
                            "color: white;"
                            "background-color:"+DataSystems::Instance().settings___color_header+";"
                            "padding: 4 20000 4 10;"
                            "}");



    auto comboBoxDelegate = new ComboBoxItemDelegate(ui->tableWidget_lists_signals);
    auto spinBoxDelegate = new SpinBoxItemDelegate(ui->tableWidget_lists_signals);
    auto checkBoxDelegate = new CheckBoxItemDelegate(ui->tableWidget_lists_signals);

    //QMap<QString, QString> allColumns = json_w::form_table2("table_form_2_1.json");
    QList<QString> allColumns = json_w::form_table2("table_form_2_1.json");
    //qDebug()<< " ||| " << allTabs.count() << " ||| " ;
    //QString firstColumn = allColumns.keys().first();
    //QList<QString> tab = allTabs.value(firstTab);
    //qDebug()<< " ||| " << firstColumn << " ||| " ;
    QStringList NameColumns;
    foreach (QString key, allColumns)
    {
        //NameColumns.append(allColumns[key]);
        NameColumns<<(key);
        qDebug()<<key;
    }

    ui->tableWidget_lists_signals->setColumnCount( allColumns.count() );
    ui->tableWidget_lists_signals->setRowCount( 1 );
    //ui->tableWidget_lists_signals->setItemDelegateForColumn(0, spinBoxDelegate);
    //ui->tableWidget_lists_signals->setItemDelegateForColumn(1, comboBoxDelegate);
    //ui->tableWidget_lists_signals->setItemDelegateForColumn(2, spinBoxDelegate);
    //ui->tableWidget_lists_signals->setItemDelegateForColumn(3, checkBoxDelegate);
    for(int i=0;i<allColumns.count();i++)ui->tableWidget_lists_signals->setColumnWidth(i, 150);

    ui->tableWidget_lists_signals->setHorizontalHeaderLabels( NameColumns );
    //ui->tableWidget_lists_signals->horizontalHeader()->setStretchLastSection(true);

    //ui->tableWidget_lists_signals->hideColumn(0);

    for(int i=0;i<3;i++)
    {
        QLabel *lb = new QLabel;
        //MainTextEdit->setFontItalic(ItalyStyle->isChecked());
        //lb->setFont(QFont::StyleNormal);
        lb->setStyleSheet("border-radius: 0px; border-bottom-style: solid; border-bottom-color: red; border-bottom-width: 1px;");
        lb->setText(QString::number(rand()%100000));
        ui->tableWidget_lists_signals->setCellWidget( i, 0,  lb );

        //ui->tableWidget_lists_signals->setItem( i, 0,  new QTableWidgetItem(QString::number(rand()%2222)));
        ui->tableWidget_lists_signals->setItem( i, 1,  new QTableWidgetItem(QString::number(rand()%22)));
        ui->tableWidget_lists_signals->setItem( i, 2,  new QTableWidgetItem(QString::number(rand()%22)));
        ui->tableWidget_lists_signals->setItem( i, 3,  new QTableWidgetItem(QString::number(rand()%22)));
        ui->tableWidget_lists_signals->setItem( i, 4,  new QTableWidgetItem(QString::number(rand()%22)));

//        QPushButton *pb = new QPushButton;
//        pb->setText("инструкция");
//        ui->tableWidget_lists_signals->setCellWidget( i, 5,  pb );
//        ui->tableWidget_lists_signals->insertRow( ui->tableWidget_lists_signals->rowCount() );

//        connect(
//            pb,
//            &QPushButton::clicked,
//            this,
//            [this](QModelIndex index)
//            {
//                int result = QMessageBox::warning(this,"Warnings", "delete?", QMessageBox::Yes, QMessageBox::No);
//                if(result == QMessageBox::Yes);// this->onBtnClicked(index);
//            }
//            );

        //for(int j=0;j<allColumns.count();j++)
        {
            //ui->tableWidget_lists_signals->setItem( i, j,  new QTableWidgetItem(QString::number(rand()%2222)));
            //tw->setItem( i, 1,  new QTableWidgetItem("one"));
            //tw->setItem( i, 2,  new QTableWidgetItem(QString::number(rand()%3333)));

            //auto check = new QCheckBox();
            //check->setCheckState(((rand()%2==1)?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked)));
            //tw->setCellWidget(i, 3,  check);
        }
    }
    //createButton();
}

void Table_Form_2_1::createButton() {
    logger::WriteMsg("void form_dataentry_Robot::createButton()");
    //logger::WriteMsg("createButton() " + QString::number(index));
    logger::WriteMsg("createButton() ");
    CustomDelegate *delegate = new CustomDelegate(5,this);
    ui->tableWidget_lists_signals->setItemDelegateForColumn(5,delegate);

    connect(
        delegate,
        &CustomDelegate::signalClicked,
        [this](QModelIndex index)
        {
            int result = QMessageBox::warning(this,"Warnings", "delete?", QMessageBox::Yes, QMessageBox::No);
            if(result == QMessageBox::Yes);// this->onBtnClicked(index);
        }
        );

    //    connect(delegate, &CustomDelegate::signalClicked, ui->tableView, [this](QModelIndex index) {
    //        int result = QMessageBox::warning(this, "Предупреждение!", "Подтвердите удаление", QMessageBox::Yes, QMessageBox::No);
    //        if(result == QMessageBox::Yes);
    //            //this->onBtnClicked(index);
    //    });
}


Table_Form_2_1::~Table_Form_2_1()
{
    delete ui;
}
