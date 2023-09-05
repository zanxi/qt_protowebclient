#include "form_2_1.h"
#include "ui_form_2_1.h"

#include "FormsMenu/table_form_2_1.h"

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
                                "background-color:#14B143;"
                                "padding: 4 20000 4 10;"
                                "}");

    ui->groupBox_3->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:#14B143;"
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

    ui->listView->setModel(m_qlist_model);
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);

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

}

Form_2_1::~Form_2_1()
{
    delete ui;
}
