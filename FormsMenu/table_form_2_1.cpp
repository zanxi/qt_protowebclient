#include "table_form_2_1.h"
#include "ui_table_form_2_1.h"

#include "tabelwidget_module/comboboxitemdelegate.h"
#include "tabelwidget_module/spinboxitemdelegate.h"
#include "tabelwidget_module/checkboxitemdelegate.h"

#include "BuildData/json_w.h"


Table_Form_2_1::Table_Form_2_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table_Form_2_1)
{
    ui->setupUi(this);

    ui->tableWidget_lists_signals->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    ui->groupBox->setStyleSheet("QGroupBox {"
                            "background-color: white;"
                            "}"
                            "QGroupBox::title {"
                            "color: white;"
                            "background-color:#14B143;"
                            "padding: 4 20000 4 10;"
                            "}");


    auto comboBoxDelegate = new ComboBoxItemDelegate(ui->tableWidget_lists_signals);
    auto spinBoxDelegate = new SpinBoxItemDelegate(ui->tableWidget_lists_signals);
    auto checkBoxDelegate = new CheckBoxItemDelegate(ui->tableWidget_lists_signals);

    QMap<QString, QString> allColumns = json_w::form_table("table_form_2_1.json");
    //qDebug()<< " ||| " << allTabs.count() << " ||| " ;
    QString firstColumn = allColumns.keys().first();
    //QList<QString> tab = allTabs.value(firstTab);
    qDebug()<< " ||| " << firstColumn << " ||| " ;
    QStringList NameColumns;
    foreach (QString key, allColumns.keys())
    {
        //NameColumns.append(allColumns[key]);
        NameColumns.append(key);
    }

    ui->tableWidget_lists_signals->setColumnCount( allColumns.count() );
    ui->tableWidget_lists_signals->setRowCount( 10 );
    ui->tableWidget_lists_signals->setItemDelegateForColumn(0, spinBoxDelegate);
    ui->tableWidget_lists_signals->setItemDelegateForColumn(1, comboBoxDelegate);
    ui->tableWidget_lists_signals->setItemDelegateForColumn(2, spinBoxDelegate);
    ui->tableWidget_lists_signals->setItemDelegateForColumn(3, checkBoxDelegate);

    ui->tableWidget_lists_signals->setHorizontalHeaderLabels( NameColumns );
    ui->tableWidget_lists_signals->horizontalHeader()->setStretchLastSection(true);

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<allColumns.count();j++)
        {
            ui->tableWidget_lists_signals->setItem( i, j,  new QTableWidgetItem(QString::number(rand()%2222)));
            //tw->setItem( i, 1,  new QTableWidgetItem("one"));
            //tw->setItem( i, 2,  new QTableWidgetItem(QString::number(rand()%3333)));

            //auto check = new QCheckBox();
            //check->setCheckState(((rand()%2==1)?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked)));
            //tw->setCellWidget(i, 3,  check);
        }
    }

}

Table_Form_2_1::~Table_Form_2_1()
{
    delete ui;
}
