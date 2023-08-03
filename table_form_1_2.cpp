#include "table_form_1_2.h"
#include "ui_table_form_1_2.h"

#include "tabelwidget_module/comboboxitemdelegate.h"
#include "tabelwidget_module/spinboxitemdelegate.h"
#include "tabelwidget_module/checkboxitemdelegate.h"

#include "BuildData/json_w.h"

#include <QLineEdit>
#include <QCompleter>
#include <QStringList>


Table_Form_1_2::Table_Form_1_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table_Form_1_2)
{
    ui->setupUi(this);

    auto comboBoxDelegate = new ComboBoxItemDelegate(ui->tableWidget_lists_signals);
    auto spinBoxDelegate = new SpinBoxItemDelegate(ui->tableWidget_lists_signals);
    auto checkBoxDelegate = new CheckBoxItemDelegate(ui->tableWidget_lists_signals);

    QList<QString> allColumns = json_w::form_table2("table_form_1_2.json");

    QStringList NameColumns;
    NameColumns<<" ";
    foreach (QString key, allColumns)
    {
        //NameColumns.append(allColumns[key]);
        NameColumns<<key;
    }

    ui->tableWidget_lists_signals->setColumnCount( allColumns.count()+1 );
    ui->tableWidget_lists_signals->setRowCount( 30 );
    ui->tableWidget_lists_signals->setItemDelegateForColumn(0, spinBoxDelegate);

    ui->tableWidget_lists_signals->setHorizontalHeaderLabels( NameColumns );
    ui->tableWidget_lists_signals->horizontalHeader()->setStretchLastSection(true);

    //QStringList wordList;
    //wordList << "alpha" << "omega" << "omega2" << "omega3" <<"omicron" << "zeta";

    for(int i=0;i<30;i++)
    {
        //for(int j=0;j<allColumns.count();j++)
        {
            auto check = new QCheckBox();
            check->setCheckState(((rand()%2==1)?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked)));
            ui->tableWidget_lists_signals->setCellWidget(i, 0,  check);

            ui->tableWidget_lists_signals->setItem( i, 1,  new QTableWidgetItem(QString::number(rand()%2222)));

            QLineEdit *lineEdit = new QLineEdit();
            //QCompleter *completer = new QCompleter(wordList);
            //completer->setCaseSensitivity(Qt::CaseInsensitive);
            lineEdit->installEventFilter(this);
            //lineEdit->setCompleter(completer);
            lineEdit->setText("3213");
            //ui->tableWidget->setCellWidget(i,i,lineEdit);
            ui->tableWidget_lists_signals->setCellWidget(i,2,lineEdit);

            ui->tableWidget_lists_signals->setItem( i, 3,  new QTableWidgetItem(QString::number(rand()%2222)));
        }
    }
}

Table_Form_1_2::~Table_Form_1_2()
{
    delete ui;
}
