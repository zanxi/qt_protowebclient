#include "form_2_1.h"
#include "ui_form_2_1.h"

#include "FormsMenu/table_form_2_1.h"
#include "dataanimals.h"

Form_2_1::Form_2_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_2_1)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    //setGeometry(QRect(600, 100, 900, 700));

    ui->groupBox_2->setStyleSheet("QGroupBox {"
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




    Table_Form_2_1 *tf_2_1 = new Table_Form_2_1(this);

    ui->horizontalLayout_2->addWidget(tf_2_1);

    m_qlist_model = new QStringListModel();
    QStringList list;
    list<<(QString("Доение - неудачные доения ")+"(3)");
    list<<(QString("Календарь - обзор всех коров ")+"(7)");
    list<<(QString("Копии всех образцов ")+"(9)");

    m_qlist_model->setStringList(list);

    //ui->listView->setModel(m_qlist_model);
    //ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);

    ui->progressBar->setStyleSheet("QProgressBar {"
                                   "background-color: black;"
                                   "border: 3px solid white;"
                                   "text-align: center;"
                                   "color: white"
                                   "}"
                                   "QProgressBar::chunk {"
                                   "background-color:#05B8CC;}");
    ui->progressBar->setOrientation(Qt::Vertical);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(80);
    ui->progressBar->resize(50,200);

    {

    ui->tableWidget->setColumnWidth(0, 200);
    ui->tableWidget->setColumnWidth(1, 200);
    ui->tableWidget->insertRow( ui->tableWidget->rowCount() );

    int i=0;
    for(QString mark:list)
    {

    QLabel *lb = new QLabel;
    //MainTextEdit->setFontItalic(ItalyStyle->isChecked());
    //lb->setFont(QFont::StyleNormal);
    lb->setStyleSheet("border-radius: 0px; border-bottom-style: solid; border-bottom-color: red; border-bottom-width: 1px; padding: 4 20000 4 10;");

    //lb->setGeometry(QRect(10, 0, 30, 30));
    lb->setMinimumSize(QSize(30, 30));
    lb->setMaximumSize(QSize(100, 16777215));
    lb->setPixmap(QPixmap(QString::fromUtf8(":/images/logo")));
    //lb->setText(mark);

    //ui->tableWidget->setItem( i, 1,  new QTableWidgetItem( query->value("animal_No").toString() ));
    //ui->tableWidget->setItem( i, 1,  new QTableWidgetItem( lb ));
    ui->tableWidget->setCellWidget(i, 0, lb);
    ui->tableWidget->insertRow( ui->tableWidget->rowCount() );

    QLabel *lb_icon = new QLabel;

    //lb->setGeometry(QRect(10, 0, 30, 30));
    lb_icon->setMinimumSize(QSize(30, 30));
    lb_icon->setMaximumSize(QSize(30, 16777215));
    lb_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/write.png")));
    lb_icon->setText("");

    //ui->tableWidget->setItem( i, 1,  new QTableWidgetItem( query->value("animal_No").toString() ));
    //ui->tableWidget->setItem( i, 1,  new QTableWidgetItem( lb ));
    ui->tableWidget->setCellWidget(i, 1, lb_icon);
    ui->tableWidget->insertRow( ui->tableWidget->rowCount() );

    i++;

    }
    }




}

Form_2_1::~Form_2_1()
{
    delete ui;
}
