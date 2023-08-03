#include "form_1_2.h"
#include "ui_form_1_2.h"

#include "table_form_1_2.h"
#include "table_form_1_2_batch_transfer.h"

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

    ui->groupBox_3->setStyleSheet("QGroupBox {"
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



    m_qlist_model = new QStringListModel();
    QStringList list;
    list.append(QString("Карта коровы ")+"(3)");
    list.append(QString("Перемещения ")+"(7)");
    list.append(QString("Отел ")+"(9)");
    list.append(QString("Нагрев ")+"(12)");
    list.append(QString("Осеменение ")+"(19)");
    list.append(QString("Проверка на беременность ")+"(29)");
    list.append(QString("Прервать калве ")+"(39)");
    list.append(QString("Сушка ")+"(14)");
    list.append(QString("Молочная сепарация ")+"(18)");
    list.append(QString("Состояние ")+"(59)");
    list.append(QString("Напоминание ")+"(9)");
    list.append(QString("Настройки молока ")+"(69)");
    list.append(QString("Фиксированная подача ")+"(79)");
    list.append(QString("Маршрутизация ")+"(89)");
    list.append(QString("Пакетная базовая ")+"(99)");
    list.append(QString("Пакетный перевод ")+"(43)");
    list.append(QString("Состояние партии ")+"(9)");
    list.append(QString("Напоминание ")+"(9)");
    list.append(QString("Настройки молока ")+"(9)");

    m_qlist_model->setStringList(list);

    ui->listView->setModel(m_qlist_model);
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);

    Table_Form_1_2 *tf_1_2 = new Table_Form_1_2(this);
    ui->horizontalLayout_2->addWidget(tf_1_2);
    connect(ui->listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(SelectionChanged(QItemSelection)));
}

void Form_1_2::SelectionChanged(const QItemSelection& selection)
{
    QModelIndex index = selection.indexes().first();
    QString listCheck = index.data(Qt::DisplayRole).toString();

    if(listCheck.contains("Пакетная базовая"))
    {
        /*
        for (int i = 0; i < ui->horizontalLayout_2->count();)
        {
            QLayoutItem *item = ui->horizontalLayout_2->itemAt(0);
            if (item->layout() != nullptr)     // Check whether item contains a layout
                delete ui->horizontalLayout_2->takeAt(0);  // Delete item with layout on it
            else i++;
        }
        /**/

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

        if(ui->horizontalLayout_2->count()<1)
        {
            Table_Form_1_2 *tf_1_2 = new Table_Form_1_2(this);
            ui->horizontalLayout_2->addWidget(tf_1_2);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout_2->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout_2->removeWidget(w);
        delete w;

        Table_Form_1_2 *tf_1_2 = new Table_Form_1_2(this);
        ui->horizontalLayout_2->addWidget(tf_1_2);

    }
    else  if (listCheck.contains("Пакетный перевод"))
    {
        if(ui->horizontalLayout_2->count()<1)
        {
            Table_Form_1_2 *tf_1_2 = new Table_Form_1_2(this);
            ui->horizontalLayout_2->addWidget(tf_1_2);
            return;
        }
        QLayoutItem *child = ui->horizontalLayout_2->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout_2->removeWidget(w);
        delete w;

        Table_Form_1_2_batch_transfer *tf_1_2_bf = new Table_Form_1_2_batch_transfer(this);
        ui->horizontalLayout_2->addWidget(tf_1_2_bf);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }
    else
    {
//        for (int i = 0; i < ui->horizontalLayout_2->count();)
//        {
//            QLayoutItem *item = ui->horizontalLayout_2->itemAt(i);
//            if (item->layout() != nullptr)     // Check whether item contains a layout
//                delete ui->horizontalLayout_2->takeAt(i);  // Delete item with layout on it
//            else i++;
//        }

        if(ui->horizontalLayout_2->count()<1) return;
        QLayoutItem *child = ui->horizontalLayout_2->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout_2->removeWidget(w);
        delete w;
    }

}

Form_1_2::~Form_1_2()
{
    delete ui;
}

