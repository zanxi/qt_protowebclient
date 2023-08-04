#include "form_1_2.h"
#include "ui_form_1_2.h"

#include "table_form_1_2.h"
#include "table_form_1_2_batch_transfer.h"

#include "table_form_1_2_in_work.h"
#include "table_form_1_2_otel.h"

#include <QDebug>

Form_1_2::Form_1_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_1_2)
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
                                  "background-color:#14B143;"
                                  "padding: 4 20000 4 10;"
                                  "}");



    m_qlist_model = new QStringListModel();
    QStringList list;
    list<<(QString("Карта коровы ")+"(3)");
    list<<(QString("Перемещения ")+"(7)");
    list<<(QString("Отел ")+"(9)");
    list<<(QString("Нагрев ")+"(12)");
    list<<(QString("Осеменение ")+"(19)");
    list<<(QString("Проверка на беременность ")+"(29)");
    list<<(QString("Прервать калве ")+"(39)");
    list<<(QString("Сушка ")+"(14)");
    list<<(QString("Молочная сепарация ")+"(18)");
    list<<(QString("Состояние ")+"(59)");
    list<<(QString("Напоминание ")+"(9)");
    list<<(QString("Настройки молока ")+"(69)");
    list<<(QString("Фиксированная подача ")+"(79)");
    list<<(QString("Маршрутизация ")+"(89)");
    list<<(QString("Пакетная базовая ")+"(99)");
    list<<(QString("Пакетный перевод ")+"(43)");
    list<<(QString("Состояние партии ")+"(9)");
    list<<(QString("Напоминание ")+"(9)");
    list<<(QString("Настройки молока ")+"(9)");

    m_qlist_model->setStringList(list);

    ui->listView->setModel(m_qlist_model);
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);

    Table_Form_1_2 *tf_1_2 = new Table_Form_1_2(this);
    ui->horizontalLayout->addWidget(tf_1_2);
    connect(ui->listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(SelectionChanged(QItemSelection)));
}

void Form_1_2::SelectionChanged(const QItemSelection& selection)
{
    QModelIndex index = selection.indexes().first();
    QString listCheck = index.data(Qt::DisplayRole).toString();

    if(listCheck.contains("Пакетная базовая"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            Table_Form_1_2 *tf_1_2 = new Table_Form_1_2(this);
            ui->horizontalLayout->addWidget(tf_1_2);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        Table_Form_1_2 *tf_1_2 = new Table_Form_1_2(this);
        ui->horizontalLayout->addWidget(tf_1_2);

    }
    else  if (listCheck.contains("Пакетный перевод"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            Table_Form_1_2_batch_transfer *tf_1_2 = new Table_Form_1_2_batch_transfer(this);
            ui->horizontalLayout->addWidget(tf_1_2);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        Table_Form_1_2_batch_transfer *tf_1_2_bf = new Table_Form_1_2_batch_transfer(this);
        ui->horizontalLayout->addWidget(tf_1_2_bf);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    else  if (listCheck.contains("Отел"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            table_form_1_2_otel *tf_1_2 = new table_form_1_2_otel(this);
            ui->horizontalLayout->addWidget(tf_1_2);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        table_form_1_2_otel *tf_1_2_bf = new table_form_1_2_otel(this);
        ui->horizontalLayout->addWidget(tf_1_2_bf);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }

    else
    {

        if(ui->horizontalLayout->count()<1) return;
        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        table_form_1_2_in_work *tf_1_2_in = new table_form_1_2_in_work(this);
        ui->horizontalLayout->addWidget(tf_1_2_in);

    }

}

Form_1_2::~Form_1_2()
{
    delete ui;
}

