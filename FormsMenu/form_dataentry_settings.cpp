#include "form_dataentry_settings.h"
#include "ui_form_dataentry_settings.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "FormsMenu/dialog_form_dataentry_settings___post_during.h"
#include "json/json_w.h"

#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>
#include <QStringListModel>

#include "dataanimals.h"


//1. Навигатор: Ввод данных 2. Меню: Настройки

//1. Навигатор: Ввод данных 2. Меню: Настройки 3. Подменю: Кормления  4. Вкладка: Таблицы кормлени


Form_DataEntry_Settings::Form_DataEntry_Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_DataEntry_Settings)
    , actSaveExcel(QIcon(":/Resource/Images/xls.png"), PBSTR("Excel "), this)
    , actSaveExcelXML(QIcon(":/Resource/Images/xls.png"), PBSTR("Excel (XML)"), this)
    , actSaveWordXML(QIcon(":/Resource/Images/word.png"), PBSTR("Word (XML)"), this)
    , actSavePDF(QIcon(":/Resource/Images/pdf.png"), PBSTR("PDF "), this)
    , actSaveCSV(QIcon(":/Resource/Images/csv.png"), PBSTR("Text (CSV)"), this)
    , actSaveXML(QIcon(":/Resource/Images/xml.png"), PBSTR("XML "), this)
    , actSaveHTML(QIcon(":/Resource/Images/htm.png"), PBSTR("HTML "), this)

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




ui->tabWidget->setStyleSheet("QTabWidget"
"{"
"   background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
"}"

"QTabWidget:tab-bar"
"{"
"    alignment: center;"
"}"

"QTabBar:tab"
"{"
"   width: 210px;"
"   height: 30px;"
"}"

"QTabBar:selected"
"{"
"    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
"    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
"}"

"QTabBar:tab:!selected"
"{"
"    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
"}"


"QTabBar:tab:!selected:hover"
"{"
"    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
"    color.rgb(255,255,255);"
"}"
")");

    ui->tabWidget_2->setStyleSheet("QTabWidget"
                                 "{"
                                 "   background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabWidget:tab-bar"
                                                                                               "{"
                                                                                               "    alignment: center;"
                                                                                               "}"

                                                                                               "QTabBar:tab"
                                                                                               "{"
                                                                                               "   width: 210px;"
                                                                                               "   height: 30px;"
                                                                                               "}"

                                                                                               "QTabBar:selected"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabBar:tab:!selected"
                                                                                               "{"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"


                                                                                               "QTabBar:tab:!selected:hover"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb(255,255,255);"
                                                                                               "}"
                                                                                               ")");


    ui->tabWidget_3->setStyleSheet("QTabWidget"
                                 "{"
                                 "   background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabWidget:tab-bar"
                                                                                               "{"
                                                                                               "    alignment: center;"
                                                                                               "}"

                                                                                               "QTabBar:tab"
                                                                                               "{"
                                                                                               "   width: 270px;"
                                                                                               "   height: 30px;"
                                                                                               "}"

                                                                                               "QTabBar:selected"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabBar:tab:!selected"
                                                                                               "{"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"


                                                                                               "QTabBar:tab:!selected:hover"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb(255,255,255);"
                                                                                               "}"
                                                                                               ")");


    ui->tableWidget_feeding___feed_tables->setStyleSheet("QTabWidget"
                                 "{"
                                 "   background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabWidget:tab-bar"
                                                                                               "{"
                                                                                               "    alignment: center;"
                                                                                               "}"

                                                                                               "QTabBar:tab"
                                                                                               "{"
                                                                                               "   width: 210px;"
                                                                                               "   height: 30px;"
                                                                                               "}"

                                                                                               "QTabBar:selected"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabBar:tab:!selected"
                                                                                               "{"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"


                                                                                               "QTabBar:tab:!selected:hover"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb(255,255,255);"
                                                                                               "}"
                                                                                               ")");



    ui->pushButton->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );

    ui->pushButton_2->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_3->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_4->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_5->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_6->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_7->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    ui->treeView->setWindowTitle("Стадо");

    QStringListModel *m_qlist_model = new QStringListModel();
    QStringList list;
    list<<(QString("1) 100 production"));
    list<<(QString("2) 10 production"));
    list<<(QString("3) Стерильный"));
    list<<(QString("4) Нагрев "));
    list<<(QString("5) 20 production "));
    list<<(QString("6) 10 production "));
    list<<(QString("7) 40 production "));
    list<<(QString("8) 50 production "));
    list<<(QString("9) 80 production "));
    list<<(QString("10) 90 production "));

    m_qlist_model->setStringList(list);

    ui->treeView->setModel(m_qlist_model);
    ui->treeView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);

    create_feeding___feed_tables();

    for(int i=0;i<ui->tableWidget_during_milking->columnCount();i++)
    {
        if(i>=2&&i<=2+8)ui->tableWidget_during_milking->setColumnWidth(i, 50);
        else if(i>=(24-7))ui->tableWidget_during_milking->setColumnWidth(i, 50);
        else
        {
            ui->tableWidget_during_milking->setColumnWidth(i, 130);
        }
    }


    //addRandom__milking__general_milking();
    //GetData__milking__general_milking();

    if(DataSystems::Instance().db_generate_random)addRandom__milking__post_milking();
    GetData__milking__post_milking();

    GetData__During_milking();
    connect(ui->tableWidget_during_milking->horizontalHeader(), SIGNAL(sectionClicked (int)), this, SLOT(sectionClicked(int)));

    create_table_view();
    //create_tree_view();
    create_after_milking();

}

// общее доение - general milk
void Form_DataEntry_Settings::create_tree_view()
{
    _tree_model.setColumnCount(tree_COL_COUNT);
    //for (int row = 0; row < tree_ROW_COUNT; row++) {
        {
        QList<QStandardItem*> items;
            items<<new QStandardItem(QString("Herd"))
              << new QStandardItem(QString("2"))
              << new QStandardItem(QString("MilkTank1"))
              << new QStandardItem(QString("M4Use"))
              << new QStandardItem(QString("All milkings"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("8"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("Нет"))
            ;
//        for (int col = 0; col < tree_COL_COUNT; col++) {
//            items << new QStandardItem(QString("Row %1, Column %2").arg(row + 1).arg(col + 1));
//        }
        _tree_model.invisibleRootItem()->appendRow(items);

        for (int c_row = 0; c_row < 2; c_row++)
        {
            QList<QStandardItem*> c_items;
            c_items << new QStandardItem(QString(" "))
              << new QStandardItem(QString("2"))
              << new QStandardItem(QString("MilkTank1"))
              << new QStandardItem(QString("M4Use"))
              << new QStandardItem(QString("All milkings"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("8"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("Нет"))
            ;
//            for (int col = 0; col < tree_COL_COUNT; col++) {
//                c_items << new QStandardItem(QString("Child row %1, Column %2").arg(c_row + 1).arg(col + 1));
//            }
            items.constFirst()->appendRow(c_items);

//            for (int c_row1 = 0; c_row1 < 10; c_row1++) {
//                QList<QStandardItem*> c_items1;
//                for (int col = 0; col < tree_COL_COUNT; col++) {
//                    c_items1 << new QStandardItem(QString("Child row %1, Column %2").arg(c_row1 + 1).arg(col + 1));
//                }
//                c_items.constFirst()->appendRow(c_items1);
//            }
        }
        }
    //}

        {
        QList<QStandardItem*> items;
            items<<new QStandardItem(QString("1) Milking A"))
              << new QStandardItem(QString("2"))
              << new QStandardItem(QString("MilkTank1"))
              << new QStandardItem(QString("M4Use"))
              << new QStandardItem(QString("All milkings"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("8"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("Нет"))
            ;
//        for (int col = 0; col < tree_COL_COUNT; col++) {
//            items << new QStandardItem(QString("Row %1, Column %2").arg(row + 1).arg(col + 1));
//        }
        _tree_model.invisibleRootItem()->appendRow(items);

        for (int c_row = 0; c_row < 2; c_row++)
        {
            QList<QStandardItem*> c_items;
            c_items << new QStandardItem(QString(" "))
              << new QStandardItem(QString("2"))
              << new QStandardItem(QString("MilkTank1"))
              << new QStandardItem(QString("M4Use"))
              << new QStandardItem(QString("All milkings"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("8"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("Нет"))
            ;
//            for (int col = 0; col < tree_COL_COUNT; col++) {
//                c_items << new QStandardItem(QString("Child row %1, Column %2").arg(c_row + 1).arg(col + 1));
//            }
            items.constFirst()->appendRow(c_items);

//            for (int c_row1 = 0; c_row1 < 10; c_row1++) {
//                QList<QStandardItem*> c_items1;
//                for (int col = 0; col < tree_COL_COUNT; col++) {
//                    c_items1 << new QStandardItem(QString("Child row %1, Column %2").arg(c_row1 + 1).arg(col + 1));
//                }
//                c_items.constFirst()->appendRow(c_items1);
//            }
        }
        }
    //}


        {
        QList<QStandardItem*> items;
            items<<new QStandardItem(QString("2) Milking B"))
              << new QStandardItem(QString("2"))
              << new QStandardItem(QString("MilkTank1"))
              << new QStandardItem(QString("M4Use"))
              << new QStandardItem(QString("All milkings"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("8"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("Нет"))
            ;
//        for (int col = 0; col < tree_COL_COUNT; col++) {
//            items << new QStandardItem(QString("Row %1, Column %2").arg(row + 1).arg(col + 1));
//        }
        _tree_model.invisibleRootItem()->appendRow(items);

        for (int c_row = 0; c_row < 2; c_row++)
        {
            QList<QStandardItem*> c_items;
            c_items << new QStandardItem(QString(" "))
              << new QStandardItem(QString("2"))
              << new QStandardItem(QString("MilkTank1"))
              << new QStandardItem(QString("M4Use"))
              << new QStandardItem(QString("All milkings"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("8"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("Нет"))
            ;
//            for (int col = 0; col < tree_COL_COUNT; col++) {
//                c_items << new QStandardItem(QString("Child row %1, Column %2").arg(c_row + 1).arg(col + 1));
//            }
            items.constFirst()->appendRow(c_items);

//            for (int c_row1 = 0; c_row1 < 10; c_row1++) {
//                QList<QStandardItem*> c_items1;
//                for (int col = 0; col < tree_COL_COUNT; col++) {
//                    c_items1 << new QStandardItem(QString("Child row %1, Column %2").arg(c_row1 + 1).arg(col + 1));
//                }
//                c_items.constFirst()->appendRow(c_items1);
//            }
        }
        }
    //}

        {
        QList<QStandardItem*> items;
            items<<new QStandardItem(QString("3) Heifers "))
              << new QStandardItem(QString("2"))
              << new QStandardItem(QString("MilkTank1"))
              << new QStandardItem(QString("M4Use"))
              << new QStandardItem(QString("All milkings"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("8"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("Нет"))
            ;
//        for (int col = 0; col < tree_COL_COUNT; col++) {
//            items << new QStandardItem(QString("Row %1, Column %2").arg(row + 1).arg(col + 1));
//        }
        _tree_model.invisibleRootItem()->appendRow(items);

        for (int c_row = 0; c_row < 2; c_row++)
        {
            QList<QStandardItem*> c_items;
            c_items << new QStandardItem(QString(" "))
              << new QStandardItem(QString("2"))
              << new QStandardItem(QString("MilkTank1"))
              << new QStandardItem(QString("M4Use"))
              << new QStandardItem(QString("All milkings"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Да"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("8"))
              << new QStandardItem(QString(""))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("Нет"))
            ;
//            for (int col = 0; col < tree_COL_COUNT; col++) {
//                c_items << new QStandardItem(QString("Child row %1, Column %2").arg(c_row + 1).arg(col + 1));
//            }
            items.constFirst()->appendRow(c_items);

//            for (int c_row1 = 0; c_row1 < 10; c_row1++) {
//                QList<QStandardItem*> c_items1;
//                for (int col = 0; col < tree_COL_COUNT; col++) {
//                    c_items1 << new QStandardItem(QString("Child row %1, Column %2").arg(c_row1 + 1).arg(col + 1));
//                }
//                c_items.constFirst()->appendRow(c_items1);
//            }
        }
        }
    //}



    _tree_view = new zf::TreeView;
    _tree_view->setModel(&_tree_model);
    configureHeader2_tree(_tree_view->rootHeaderItem());

    ui->verticalLayout_gen_milk->addWidget(_tree_view);

}

void Form_DataEntry_Settings::configureHeader2_tree(zf::HeaderItem *parent)
{
    {
        QString h_name = QString("Check");
        zf::HeaderItem *item =  parent->append(h_name);
        item->append("Поиск");
    }

    {
        QString h_name = QString("Молозиво");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append(" ");
    }

    {
        QString h_name = QString("Место лактации");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append(" ");
    }
    {
        QString h_name = QString("Место сепарации молока");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append(" ");
    }
    {
        QString h_name = QString("Молозиво Место лактации");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append(" ");
    }
    {
        QString h_name = QString("Способ взятия проб");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append(" ");
    }

    {
        QString h_name = QString("Молочные титьки");
        zf::HeaderItem *item =  parent->append(h_name);
        item->append("lf");
        item->append("lr");
        item->append("rf");
        item->append("rr");
    }
    {
        QString h_name = QString("Молочные соски(Да/Нет)");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
    {
        QString h_name = QString("Сброс положения сосков после сухостойности(Да/Нет)");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
    {
        QString h_name = QString("Период перемещения(Да/Нет)");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
    {
        QString h_name = QString("лактация под управлением(Да/Нет)");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
    {
        QString h_name = QString("Оптимальный период взятия(часы)");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
    {
        QString h_name = QString("Позиции сосков известный(Да/Нет)");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
    {
        QString h_name = QString("Коррекция времени");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
    {
        QString h_name = QString("Альтернативный способ взятия(Да/Нет)");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
}


void Form_DataEntry_Settings::create_after_milking()
{
    //_tree_model_after_milking.setRowCount(tree_ROW_after_milking_COUNT);
    _tree_model_after_milking.setColumnCount(tree_COL_after_milking_COUNT);
    //_tree_model_after_milking.setColumnCount(tree_COL_after_milking_COUNT);
    //for (int row = 0; row < tree_ROW_COUNT; row++) {
    {
        QList<QStandardItem*> items;
        items<<new QStandardItem(QString("Herd"))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("1"))
              << new QStandardItem(QString("0.1"))
              << new QStandardItem(QString("0.1"))
              << new QStandardItem(QString("0.1"))
              << new QStandardItem(QString("0.1"))
              << new QStandardItem(QString("Нет"))
              << new QStandardItem(QString("Steam lalywash"))
              << new QStandardItem(QString("Нет"))
            ;
        //        for (int col = 0; col < tree_COL_COUNT; col++) {
        //            items << new QStandardItem(QString("Row %1, Column %2").arg(row + 1).arg(col + 1));
        //        }
        _tree_model_after_milking.invisibleRootItem()->appendRow(items);
        QList<QStandardItem*> c_items;
        for (int c_row = 0; c_row < 22; c_row++)
        {

            c_items << new QStandardItem(QString(" "))
                    << new QStandardItem(QString("1"))
                    << new QStandardItem(QString("1"))
                    << new QStandardItem(QString("1"))
                    << new QStandardItem(QString("1"))
                    << new QStandardItem(QString("0.1"))
                    << new QStandardItem(QString("0.1"))
                    << new QStandardItem(QString("0.1"))
                    << new QStandardItem(QString("0.1"))
                    << new QStandardItem(QString("Нет"))
                    << new QStandardItem(QString("Steam lalywash"))
                    << new QStandardItem(QString("Нет"))
            ;
            items.constFirst()->appendRow(c_items);
        }
    }

    _tree_view_after_milking = new zf::TreeView;
    _tree_view_after_milking->setModel(&_tree_model_after_milking);
    configureHeader2_tree_after_milking(_tree_view_after_milking->rootHeaderItem());

    //_tree_view_after_milking->setCellCheckColumn();
    //ui->tableWidget_post_milking->addWidget(_tree_view_after_milking);
    ui->verticalLayout_post_milk->addWidget(_tree_view_after_milking);

}

void Form_DataEntry_Settings::configureHeader2_tree_after_milking(zf::HeaderItem *parent)
{
    {
        QString h_name = QString(" ");
        zf::HeaderItem *item =  parent->append(h_name);
        item->append("Поиск");
    }

    {
        QString h_name = QString("Number of treatments");
        zf::HeaderItem *item =  parent->append(h_name);
        item->append("lf");
        item->append("lr");
        item->append("rf");
        item->append("rr");
    }

    {
        QString h_name = QString("Duraion per treatments(sec)");
        zf::HeaderItem *item =  parent->append(h_name);
        item->append("lf");
        item->append("lr");
        item->append("rf");
        item->append("rr");
    }

    {
        QString h_name = QString("Sampling(Yes/No)");
        zf::HeaderItem *item =  parent->append(h_name);
    }

    {
        QString h_name = QString("Clean milk equipment");
        zf::HeaderItem *item =  parent->append(h_name);
    }

    {
        QString h_name = QString("Priority feeding(Yes/No)");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
}



void Form_DataEntry_Settings::sectionClicked(int idx)
{

    //if (idx == 0);
    //if(ui->tableWidget_during_milking->selectColumn(idx));
    qDebug()<<"idx: "<<idx;
    if(idx==13)
    {
        Dialog_form_dataentry_settings___post_during tf(this);
        if(!(tf.exec()==QDialog::Accepted))
        {
            //QMessageBox::information(this,"Спасибо","Сухостойность");
        }

    }
    return;
    qDebug()<<ui->tableWidget_during_milking->takeVerticalHeaderItem(idx)->text();
    if(ui->tableWidget_during_milking->takeVerticalHeaderItem(idx)->text().contains("образец"))
    {
        Dialog_form_dataentry_settings___post_during tf(this);
        if(!(tf.exec()==QDialog::Accepted))
        {
            //QMessageBox::information(this,"Спасибо","Сухостойность");
        }

    }
        //sort_table("select name,reiting,dat,comment from `Default` ORDER BY `name`;");

}

void Form_DataEntry_Settings::create_feeding___feed_tables()
{
    ui->tableWidget_feeding___feed_tables->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableWidget_feeding___feed_tables->clear();
    //auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

    //QMap<QString, QString> allColumns = json_w::form_table("table_form_1_2_bf.json");
    //QList<QString> allColumns = json_w::form_table2("table_form_1_9_series.json");

    QStringList NameColumns;
    NameColumns<<" "<<"Добавочный корм";
    //int i=0;


    ui->tableWidget_feeding___feed_tables->setColumnCount( 2 );
    for(int i=0;i<2;i++)ui->tableWidget_feeding___feed_tables->setColumnWidth(i, 250);

    ui->tableWidget_feeding___feed_tables->setRowCount( 10 );

    ui->tableWidget_feeding___feed_tables->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
    ui->tableWidget_feeding___feed_tables->setHorizontalHeaderLabels( NameColumns );
    //ui->tableWidget_feeding___feed_tables->horizontalHeader()->setStretchLastSection(true);

    //ui->tableWidget_feeding___feed_tables->hideColumn(0);

    for(int i=0;i<3;i++)
    {
        QTableWidgetItem *widgetitem =  new QTableWidgetItem("feed "+QString::number(i*10));
        //if(i==5)widgetitem->setBackground(Qt::gray);
        //else widgetitem->setBackground(Qt::green);
         ui->tableWidget_feeding___feed_tables->setItem( i, 0,  new QTableWidgetItem("feed "+QString::number(i*10)));
        if(i==5)ui->tableWidget_feeding___feed_tables->item(i,0)->setBackground( Qt::gray);


            QPushButton *pushButton_show_all = new QPushButton();
            pushButton_show_all->installEventFilter(this);
            pushButton_show_all->setText("Показать");
            ui->tableWidget_feeding___feed_tables->setCellWidget(i,1,pushButton_show_all);

            //ui->tableWidget->setItem( i, 3,  new QTableWidgetItem(QDate().currentDate().toString()));
    }    
}


void Form_DataEntry_Settings::create_feeding___access_milk()
{

}




Form_DataEntry_Settings::~Form_DataEntry_Settings()
{
    delete ui;
}

void Form_DataEntry_Settings::on_pushButton_clicked()
{
    QMessageBox::information(this,"Спасибо","Сохранеы данные");    
}


void Form_DataEntry_Settings::addRandom__milking__general_milking()
{
    for(int i=0;i<1;i++)
    {

            DataSystems::I().dataentry_settings____milking__general_milking__colostrum_day = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_destination = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__separation_milk_destination = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_lf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_lr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_rf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_rr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__reset_teat_coordinates_aftre_dry = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__training_period = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__milk_under_supervision = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__optimal_sampling_period = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__teat_position_known = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__correction_time = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__general_milking__alternative_connection_method = QString::number(rand()%100);

            QScopedPointer<DataBase> db_func(new DataBase());
            if(db_func->StatusOpen())
            {
                QString tab = "dataentry_settings____milking__general_milking";
                db_func->insert_add(tab, "colostrum_day", DataSystems::I().dataentry_settings____milking__general_milking__colostrum_day);
                db_func->insert_add(tab, "milk_destination", DataSystems::I().dataentry_settings____milking__general_milking__milk_destination);
                db_func->insert_add(tab, "separation_milk_destination", DataSystems::I().dataentry_settings____milking__general_milking__separation_milk_destination);
                db_func->insert_add(tab, "milk_teat_lf", DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_lf);
                db_func->insert_add(tab, "milk_teat_lr", DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_lr);
                db_func->insert_add(tab, "milk_teat_rf", DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_rf);
                db_func->insert_add(tab, "milk_teat_rr", DataSystems::I().dataentry_settings____milking__general_milking__milk_teat_rr);
                db_func->insert_add(tab, "reset_teat_coordinates_aftre_dry", DataSystems::I().dataentry_settings____milking__general_milking__reset_teat_coordinates_aftre_dry);
                db_func->insert_add(tab, "training_period", DataSystems::I().dataentry_settings____milking__general_milking__training_period);
                db_func->insert_add(tab, "milk_under_supervision", DataSystems::I().dataentry_settings____milking__general_milking__milk_under_supervision);
                db_func->insert_add(tab, "optimal_sampling_period", DataSystems::I().dataentry_settings____milking__general_milking__optimal_sampling_period);
                db_func->insert_add(tab, "teat_position_known", DataSystems::I().dataentry_settings____milking__general_milking__teat_position_known);
                db_func->insert_add(tab, "correction_time", DataSystems::I().dataentry_settings____milking__general_milking__correction_time);
                QString sql_insert = db_func->insert_add(tab, "alternative_connection_method", DataSystems::I().dataentry_settings____milking__general_milking__alternative_connection_method);

                //"----------" + "')";
                db_func->sql_exec(sql_insert, "add milking__general_milking");
            }
    }

}

void Form_DataEntry_Settings::GetData__milking__general_milking()
{
//    ui->tableWidget_during_milking->clear();
//    QString tab = "dataentry_settings____milking__general_milking";

//    QScopedPointer<DataBase> db_func(new DataBase());
//    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
//    if(db_func->StatusOpen())
//    {
//            QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
//            QSqlQuery* query = db_func->sql_exec2(sql);
//            if(query->size()<1)return;
//            int i=0;

//            auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget_general_milking);
//            ui->tableWidget_general_milking->setRowCount( 1 );
//            ui->tableWidget_general_milking->setHorizontalHeaderItem(0, new QTableWidgetItem("Общее доение"));

//            for(int i=0;i<ui->tableWidget_general_milking->columnCount();i++)ui->tableWidget_general_milking->setColumnWidth(i, 150);
//            //ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
//            //ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
//            //ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);

//            i=0;
//            while(query->next())
//            {
//                QCheckBox *checkbox = new QCheckBox();
//                checkbox->installEventFilter(this);
//                checkbox->setText("");
//                checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
//                ui->tableWidget_general_milking->setCellWidget(i,0,checkbox);

//                ui->tableWidget_general_milking->setItem( i, 1,  new QTableWidgetItem( query->value("colostrum_day").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 2,  new QTableWidgetItem( query->value("milk_destination").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 3,  new QTableWidgetItem( query->value("separation_milk_destination").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 4,  new QTableWidgetItem( query->value("milk_teat_lf").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 5,  new QTableWidgetItem( query->value("milk_teat_lr").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 6,  new QTableWidgetItem( query->value("milk_teat_rf").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 7,  new QTableWidgetItem( query->value("milk_teat_rr").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 8,  new QTableWidgetItem( query->value("reset_teat_coordinates_aftre_dry").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 9,  new QTableWidgetItem( query->value("training_period").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 10,  new QTableWidgetItem( query->value("milk_under_supervision").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 11,  new QTableWidgetItem( query->value("optimal_sampling_period").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 12,  new QTableWidgetItem( query->value("teat_position_known").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 13,  new QTableWidgetItem( query->value("correction_time").toString() ));
//                ui->tableWidget_general_milking->setItem( i, 14,  new QTableWidgetItem( query->value("alternative_connection_method").toString() ));

//                ui->tableWidget_general_milking->insertRow( ui->tableWidget_general_milking->rowCount() );
//                i++;
//            }
//    }


    /**/

}

void Form_DataEntry_Settings::GetData__During_milking()
{
//    //ui->tableWidget_during_milking->col->clear();
//    QString tab = "dataentry_settings____milking__general_milking";

//    //QScopedPointer<DataBase> db_func(new DataBase());
//    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
//    //if(db_func->StatusOpen())
//    {
//            QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
//            //QSqlQuery* query = db_func->sql_exec2(sql);
//            //if(query->size()<1)return;
//            int i=0;

//            auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget_general_milking);

//            //ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
//            //ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
//            //ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);

//            ui->tableWidget_during_milking->insertRow( ui->tableWidget_during_milking->rowCount() );


//            i=0;
//            //while(query->next())
//            for(i=0;i<4;i++)
//            {
//                QCheckBox *checkbox = new QCheckBox();
//                checkbox->installEventFilter(this);
//                checkbox->setText("");
//                checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
//                //ui->tableWidget_general_milking->setCellWidget(i,0,checkbox);
//                ui->tableWidget_during_milking->setItem( i, 0,  new QTableWidgetItem( QString(" ") ));

//                //ui->tableWidget_during_milking->setItem( i, 1,  new QTableWidgetItem( query->value("colostrum_day").toString() ));
//                ui->tableWidget_during_milking->setItem( i, 1,  new QTableWidgetItem( QString::number((rand()%43/71.0))));
//                ui->tableWidget_during_milking->setItem( i, 2,  new QTableWidgetItem( QString::number((rand()%43)) ));
//                ui->tableWidget_during_milking->setItem( i, 3,  new QTableWidgetItem( QString::number((rand()%43)) ));
//                ui->tableWidget_during_milking->setItem( i, 4,  new QTableWidgetItem( QString::number((rand()%43)) ));
//                ui->tableWidget_during_milking->setItem( i, 5,  new QTableWidgetItem( QString::number((rand()%43)) ));
//                ui->tableWidget_during_milking->setItem( i, 6,  new QTableWidgetItem( QString::number((rand()%73)) ));
//                ui->tableWidget_during_milking->setItem( i, 7,  new QTableWidgetItem( QString::number((rand()%73)) ));
//                ui->tableWidget_during_milking->setItem( i, 8,  new QTableWidgetItem( QString::number((rand()%73)) ));
//                ui->tableWidget_during_milking->setItem( i, 9,  new QTableWidgetItem( QString::number((rand()%73)) ));
//                ui->tableWidget_during_milking->setItem( i, 10,  new QTableWidgetItem( QString((rand()%3==2)?"Left-Right":"Left") ));
//                ui->tableWidget_during_milking->setItem( i, 11,  new QTableWidgetItem( QString((rand()%3==2)?"Quick take off":"Quick take on") ));
//                ui->tableWidget_during_milking->setItem( i, 12,  new QTableWidgetItem( QString((rand()%3==2)?"Yes":"NO") ));
//                ui->tableWidget_during_milking->setItem( i, 13,  new QTableWidgetItem( QString((rand()%3==2)?"once day":"all day") ));
//                ui->tableWidget_during_milking->setItem( i, 14,  new QTableWidgetItem( QString((rand()%3==2)?"Yes":"NO") ));
//                ui->tableWidget_during_milking->setItem( i, 15,  new QTableWidgetItem( QString((rand()%3==2)?"Yes":"NO") ));
//                ui->tableWidget_during_milking->setItem( i, 16,  new QTableWidgetItem( QString::number((rand()%4)) ));
//                ui->tableWidget_during_milking->setItem( i, 17,  new QTableWidgetItem( QString((rand()%3==2)?"Yes":"NO") ));
//                ui->tableWidget_during_milking->setItem( i, 18,  new QTableWidgetItem( QString((rand()%3==2)?"Yes":"NO") ));
//                ui->tableWidget_during_milking->setItem( i, 19,  new QTableWidgetItem( QString((rand()%3==2)?"Yes":"NO") ));
//                ui->tableWidget_during_milking->setItem( i, 20,  new QTableWidgetItem( QString((rand()%3==2)?"Yes":"NO") ));
//                ui->tableWidget_during_milking->setItem( i, 21,  new QTableWidgetItem( QString((rand()%3==2)?"Yes":"NO") ));
//                ui->tableWidget_during_milking->setItem( i, 22,  new QTableWidgetItem( QString((rand()%3==2)?"Yes":"NO") ));
//                ui->tableWidget_during_milking->setItem( i, 23,  new QTableWidgetItem( QString((rand()%3==2)?"Yes":"NO") ));
//                ui->tableWidget_during_milking->setItem( i, 24,  new QTableWidgetItem( QString((rand()%3==2)?"Yes":"NO") ));

//                ui->tableWidget_during_milking->insertRow( ui->tableWidget_during_milking->rowCount() );
//                //i++;
//            }
//    }


    /**/

}


void Form_DataEntry_Settings::addRandom__milking__post_milking()
{
    for(int i=0;i<3;i++)
    {
            DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_lf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_lr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_rf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_rr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_lf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_lr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_rf = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_rr = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__clean_milk_equipment = QString::number(rand()%100);
            DataSystems::I().dataentry_settings____milking__post_milking__priority_feeding = QString::number(rand()%100);

            QScopedPointer<DataBase> db_func(new DataBase());
            if(db_func->StatusOpen())
            {
                QString tab = "dataentry_settings____milking__post_milking";
                db_func->insert_add(tab, "number_of_treatments_lf", DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_lf);
                db_func->insert_add(tab, "number_of_treatments_lr", DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_lr);
                db_func->insert_add(tab, "number_of_treatments_rf", DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_rf);
                db_func->insert_add(tab, "number_of_treatments_rr", DataSystems::I().dataentry_settings____milking__post_milking__number_of_treatments_rr);
                db_func->insert_add(tab, "duration_per_treatment_lf", DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_lf);
                db_func->insert_add(tab, "duration_per_treatment_lr", DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_lr);
                db_func->insert_add(tab, "duration_per_treatment_rf", DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_rf);
                db_func->insert_add(tab, "duration_per_treatment_rr", DataSystems::I().dataentry_settings____milking__post_milking__duration_per_treatment_rr);
                db_func->insert_add(tab, "sampling", DataSystems::I().dataentry_settings____milking__post_milking__sampling);
                db_func->insert_add(tab, "clean_milk_equipment", DataSystems::I().dataentry_settings____milking__post_milking__clean_milk_equipment);
                QString sql_insert = db_func->insert_add(tab, "priority_feeding", DataSystems::I().dataentry_settings____milking__post_milking__priority_feeding);

                //"----------" + "')";
                db_func->sql_exec(sql_insert, "add milking__post_milking");
            }
    }
}

void Form_DataEntry_Settings::GetData__milking__post_milking()
{
//    ui->tableWidget_post_milking->clear();
//    QString tab = "dataentry_settings____milking__post_milking";

//    QScopedPointer<DataBase> db_func(new DataBase());
//    if(db_func->StatusOpen())
//    {
//            QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
//            QSqlQuery* query = db_func->sql_exec2(sql);
//            if(query->size()<1)return;
//            int i=0;

//            auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget_general_milking);
//            ui->tableWidget_post_milking->setRowCount( 1 );
//            ui->tableWidget_post_milking->setHorizontalHeaderItem(0, new QTableWidgetItem("Общее доение"));

//            for(int i=0;i<ui->tableWidget_post_milking->columnCount();i++)ui->tableWidget_general_milking->setColumnWidth(i, 150);
//            //ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
//            //ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
//            //ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);

//            i=0;
//            while(query->next())
//            {
//                QCheckBox *checkbox = new QCheckBox();
//                checkbox->installEventFilter(this);
//                checkbox->setText("");
//                checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
//                ui->tableWidget_post_milking->setCellWidget(i,0,checkbox);

//                ui->tableWidget_post_milking->setItem( i, 1,  new QTableWidgetItem( query->value("number_of_treatments_lf").toString() ));
//                ui->tableWidget_post_milking->setItem( i, 2,  new QTableWidgetItem( query->value("number_of_treatments_lr").toString() ));
//                ui->tableWidget_post_milking->setItem( i, 3,  new QTableWidgetItem( query->value("number_of_treatments_rf").toString() ));
//                ui->tableWidget_post_milking->setItem( i, 4,  new QTableWidgetItem( query->value("number_of_treatments_rr").toString() ));
//                ui->tableWidget_post_milking->setItem( i, 5,  new QTableWidgetItem( query->value("duration_per_treatment_lf").toString() ));
//                ui->tableWidget_post_milking->setItem( i, 6,  new QTableWidgetItem( query->value("duration_per_treatment_lr").toString() ));
//                ui->tableWidget_post_milking->setItem( i, 7,  new QTableWidgetItem( query->value("duration_per_treatment_rf").toString() ));
//                ui->tableWidget_post_milking->setItem( i, 8,  new QTableWidgetItem( query->value("duration_per_treatment_rr").toString() ));
//                ui->tableWidget_post_milking->setItem( i, 9,  new QTableWidgetItem( query->value("sampling").toString() ));
//                ui->tableWidget_post_milking->setItem( i, 10,  new QTableWidgetItem( query->value("clean_milk_equipment").toString() ));
//                ui->tableWidget_post_milking->setItem( i, 11,  new QTableWidgetItem( query->value("priority_feeding").toString() ));

//                ui->tableWidget_general_milking->insertRow( ui->tableWidget_general_milking->rowCount() );
//                i++;
//            }
//    }
    /**/
}


void Form_DataEntry_Settings::create_table_view()
{
    //    _table_model.setColumnCount(COL_COUNT);
    //    _table_model.setRowCount(ROW_COUNT);
    //    for(int row = 0; row < ROW_COUNT;row++)
    //    {
    //       for(int col = 0; col < COL_COUNT; col++)
    //        {
    //            _table_model.setData(_table_model.index(row,col),
    //                         QString::number(row)+QString("|")+QString::number(col),
    //                                Qt::EditRole);
    //        }
    //    }



    //logger::WriteLog("GetData()");
    //ui->textEdit->setText(DataSystems::Instance().log);

    //void MainWindow::GetData()
    {
            //ui->tableWidget->clear();


            logger::WriteLog("GetData()");
            //ui->textEdit->setText(DataSystems::Instance().log);

            QScopedPointer<DataBase> db_func(new DataBase());
            if(db_func->StatusOpen())
            {
                QString tab = "analyse_reports___x_link";
                QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
                QSqlQuery* query = db_func->sql_exec2(sql);
                qDebug()<<"koll-vo records: "<<query->size()<<" | "<<sql;
                if(query->size()<1)return;

                //        QStringList NameColumns;
                //        int i=0;
                //        foreach (QString cols, allColumns)
                //        {
                //            qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
                //            i++;
                //            NameColumns<<cols;
                //        }

                //        ui->tableWidget->setColumnCount( allColumns.count() );


                //        ui->tableWidget->setRowCount( 1 );
                //        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Параметры робота"));
                //        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );

                QList<QString> columns = {
                    "check",
                    "cow_number",
                    "robot_No",
                    "group_No",
                    "LF_condition",
                    "LF_colour_code",
                    "LR_condition",
                    "LR_colour_code",
                    "RF_condition",
                    "RF_colour_code",
                    "RR_condition,",
                    "RR_colour_code",
                    "day_pregnance",
                    "lactation_day",
                    "lactation_No",
                    "quad_dev",
                    "dev_day"
                };

                //        for(int i=0;i<NameColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

                logger::WriteLog("READING ... GetData()");
                //ui->textEdit->setText(DataSystems::Instance().log);

                _table_model.setColumnCount(COL_COUNT);
                _table_model.setRowCount(query->size());
                //for(int row = 0; row < ROW_COUNT;row++)
                int i=0;
                while(query->next())
                {
                    for(int j = 0; j < COL_COUNT; j++)
                    {
                        _table_model.setData(_table_model.index(i,j),
                                             query->value(columns[j]).toString(),
                                             Qt::EditRole);
                    }
                    //_table_model.appendRow();
                    i++;
                }

                i=0;
                //while(query->next())
                {

                    for(int j=0;j<columns.count();j++)
                    {
                        //QTableWidgetItem *item = new QTableWidgetItem(query->value(columns[j]).toString());
                        //item->setTextAlignment(Qt::AlignHCenter);
                        //  ui->tableWidget->setItem( i, j,  item);
                        qDebug()<<"j: "<<j;
                    }
                    //ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
                    i++;
                }
            }
            else
            {
                logger::WriteLog("ERROR READING ... GetData() ????????????????????? ");
                //ui->textEdit->setText(DataSystems::Instance().log);
            }
    }


    _table_view = new zf::TableView;
    _table_view->setAutoResizeRowsHeight(false);
    _table_view->setSortingEnabled(true);
    _table_view->setModel(&_table_model);

    configureHeader2(_table_view->horizontalRootHeaderItem());

    QString text = "";

    ui->verticalLayout_gen_milk->addWidget(_table_view);

    //ui->tblInventory->model()->data(ui->tblInventory->model()->index(0,2)).toString()
    for(int i=0; i<_table_view->model()->rowCount();i++)
    {
            //qDebug()<<i<<",2)"<<_table_view->model()->data(_table_view->model()->index(i,2)).toString();
            text += QString::number(i)+",2)"+_table_view->model()->data(_table_view->model()->index(i,2)).toString() + "    -----   ";
            text += QString::number(i)+",3)"+_table_view->model()->data(_table_view->model()->index(i,3)).toString() + "\n";
    }

    createPopupMenu_();
    connect(_table_view, SIGNAL(onCreatePopupMenu(QMenu *)), SLOT(onCreateFooterMenu(QMenu *)));

    connect(&actSaveExcel, &QAction::triggered, this, &Form_DataEntry_Settings::onActSaveExcel);
    connect(&actSaveExcelXML, &QAction::triggered, this, &Form_DataEntry_Settings::onActSaveExcelXML);
    connect(&actSaveWordXML, &QAction::triggered, this, &Form_DataEntry_Settings::onActSaveWordXML);
    connect(&actSavePDF, &QAction::triggered, this, &Form_DataEntry_Settings::onActSavePDF);
    connect(&actSaveCSV, &QAction::triggered, this, &Form_DataEntry_Settings::onActSaveCSV);
    connect(&actSaveXML, &QAction::triggered, this, &Form_DataEntry_Settings::onActSaveXML);
    connect(&actSaveHTML, &QAction::triggered, this, &Form_DataEntry_Settings::onActSaveHTML);

    connect(&actSendToPrinter, &QAction::triggered, this, &Form_DataEntry_Settings::onActSendToPrinter);

    connect(_table_view->horizontalHeader(), SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showCustomContextMenu(const QPoint&)));

    //ui->textEdit->setText(text);
}

void Form_DataEntry_Settings::configureHeader2(zf::HeaderItem *parent)
{
    {
            QString h_name = QString("Check");
            zf::HeaderItem *item =  parent->append(h_name);
            //item->append(" ");
    }

    {
            QString h_name = QString("Номер коровы");
            zf::HeaderItem *item =  parent->append(h_name);
            //item->append(" ");
    }

    {
            QString h_name = QString("Номер робота");
            zf::HeaderItem *item =  parent->append(h_name);
            //item->append(" ");
    }
    {
            QString h_name = QString("Номер группы");
            zf::HeaderItem *item =  parent->append(h_name);
            //item->append(" ");
    }
    {
            QString h_name = QString("LF");
            zf::HeaderItem *item =  parent->append(h_name);
            item->append("Условие");
            item->append("Цветовой код");
    }
    {
            QString h_name = QString("RF");
            zf::HeaderItem *item =  parent->append(h_name);
            item->append("Условие");
            item->append("Цветовой код");
    }
    {
            QString h_name = QString("RF");
            zf::HeaderItem *item =  parent->append(h_name);
            item->append("Условие");
            item->append("Цветовой код");
    }
    {
            QString h_name = QString("RR");
            zf::HeaderItem *item =  parent->append(h_name);
            item->append("Условие");
            item->append("Цветовой код");
    }
    {
            QString h_name = QString("Дни беременности");
            zf::HeaderItem *item =  parent->append(h_name);
            //item->append("");
    }
    {
            QString h_name = QString("Дни лактации");
            zf::HeaderItem *item =  parent->append(h_name);
            //item->append("");
    }
    {
            QString h_name = QString("Номер лактации");
            zf::HeaderItem *item =  parent->append(h_name);
            //item->append("");
    }
    {
            QString h_name = QString("qqq");
            zf::HeaderItem *item =  parent->append(h_name);
            //item->append("");
    }
    {
            QString h_name = QString("qqr");
            zf::HeaderItem *item =  parent->append(h_name);
            //item->append("");
    }
}




void Form_DataEntry_Settings::showCustomContextMenu(const QPoint &p)
{
    QPoint mP = mapToGlobal(p);

    //int iCol = _table_view->horizontalHeader()->logicalIndexAt(p),
    //  iSort = _table_view->horizontalHeader()->sortIndicatorSection();

    //actSortAsc.setChecked(iCol == iSort && _table_view->horizontalHeader()->sortIndicatorOrder() == Qt::AscendingOrder);
    //actSortDesc.setChecked(iCol == iSort && _table_view->horizontalHeader()->sortIndicatorOrder() == Qt::DescendingOrder);

    popupMenu.popup(mP);
}

void Form_DataEntry_Settings::onActSaveExcelXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
            QFile f(sName);
            f.open(QIODevice::ReadWrite);
            PBSTableViewExcelXMLExporter e(_table_view, &f, this);
            e.execute();
            f.close();
    }
}

void Form_DataEntry_Settings::onActSaveWordXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
            QFile f(sName);
            f.open(QIODevice::ReadWrite);
            PBSTableViewWordXMLExporter e(_table_view, &f, this);
            e.execute();
            f.close();
    }
}

void Form_DataEntry_Settings::onActSaveCSV()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
            QFile f(sName);
            f.open(QIODevice::ReadWrite);
            PBSTableViewCSVExporter e(_table_view, &f, this);
            e.execute();
            f.close();
    }
}

void Form_DataEntry_Settings::onActSaveHTML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
            QFile f(sName);
            f.open(QIODevice::ReadWrite);
            PBSTableViewHTMLExporter e(_table_view, &f, this);
            e.execute();
            f.close();
    }
}

void Form_DataEntry_Settings::onActSaveExcel()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
            PBSTableViewXLSXExporter e(_table_view, sName, this);
            e.execute();
    }
}

void Form_DataEntry_Settings::onActSaveXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
            QFile f(sName);
            f.open(QIODevice::ReadWrite);
            PBSTableViewXMLExporter e(_table_view, &f, this);
            e.execute();
            f.close();
    }
}

void Form_DataEntry_Settings::onActSavePDF()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
            PBSTableViewPDFExporter e(_table_view, sName, this);
            e.execute();
    }
}

void Form_DataEntry_Settings::onActSendToPrinter()
{
    QPrinter printer(QPrinter::ScreenResolution);
    printer.setPaperSize(QPrinter::A4);
    printer.setFullPage(false);

    printer.setOrientation(QPrinter::Portrait);
    printer.setPageMargins(0, 0, 0, 0, QPrinter::Unit::Millimeter);
    printer.setResolution(96); // QApplication::screens().at(0)->logicalDotsPerInch());

    QPrintPreviewDialog d(&printer, reinterpret_cast<QWidget*>(parent()));
    d.setWindowFlags(Qt::Window | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);

    connect(&d, SIGNAL(paintRequested(QPrinter *)), this, SLOT(print(QPrinter *)));

    d.exec();
}

void Form_DataEntry_Settings::print(QPrinter *prn)
{
    QPainter painter;

    painter.begin(prn);

    PBSTablePrinter p(&painter, _table_view, this);
    p.setPrinter(prn);

    p.setHeadersFont(_table_view->horizontalHeader()->font());
    p.setContentFont(font());

    p.execute();
}



void Form_DataEntry_Settings::onCreateFooterMenu(QMenu *m)
{
    emit onCreatePopupMenu(FooterMenu, m);
}

void Form_DataEntry_Settings::createPopupMenu_()
{
    popupMenu.clear();
    popupMenu.addAction(&actSortAsc);
    popupMenu.addAction(&actSortDesc);
    popupMenu.addSeparator();
    popupMenu.addAction(&actFooter);
    popupMenu.addAction(&actFilter);
    popupMenu.addSeparator();
    popupMenu.addAction(&actSendToPrinter);
    popupMenu.addSeparator();
    popupMenu.addAction(&actStretchColumn);
    popupMenu.addAction(&actStretchColumnAll);
    popupMenu.addAction(&actStretch);

    popupMenu.addSeparator();
    //QMenu *saveAsMenu = popupMenu.addMenu(QIcon(":/Resource/Images/save.png"), ("Преобразовать в  ..."));
    QMenu *saveAsMenu = popupMenu.addMenu(PBSTR("Transpose -> (EXCEL)Преобразовать в  ..."));
    saveAsMenu->addAction(&actSaveExcel);
    saveAsMenu->addAction(&actSaveExcelXML);
    saveAsMenu->addAction(&actSaveWordXML);
    //saveAsMenu->addSeparator();
    saveAsMenu->addAction(&actSavePDF);
    saveAsMenu->addAction(&actSaveCSV);
    saveAsMenu->addAction(&actSaveXML);
    saveAsMenu->addAction(&actSaveHTML);

    //popupMenu.addSeparator();
    //popupMenu.addAction(&actSaveLayout);

    emit onCreatePopupMenu(HeaderMenu, &popupMenu);
}

