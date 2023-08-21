#include "table_form_1_2.h"
#include "ui_table_form_1_2.h"

#include "tabelwidget_module/comboboxitemdelegate.h"
#include "tabelwidget_module/spinboxitemdelegate.h"
#include "tabelwidget_module/checkboxitemdelegate.h"

#include "json/json_w.h"

#include <QLineEdit>
#include <QCompleter>
#include <QStringList>


Table_Form_1_2::Table_Form_1_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table_Form_1_2)
{
    ui->setupUi(this);


    ui->groupBox_2->setStyleSheet("QGroupBox {"
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




    auto comboBoxDelegate = new ComboBoxItemDelegate(ui->tableWidget);
    auto spinBoxDelegate = new SpinBoxItemDelegate(ui->tableWidget);
    auto checkBoxDelegate = new CheckBoxItemDelegate(ui->tableWidget);

    QList<QString> allColumns = json_w::form_table2("table_form_1_2.json");

    QStringList NameColumns;
    NameColumns<<" ";
    foreach (QString key, allColumns)
    {
        //NameColumns.append(allColumns[key]);
        NameColumns<<key;
    }

    ui->tableWidget->setColumnCount( allColumns.count()+1 );
    ui->tableWidget->setRowCount( 30 );
    ui->tableWidget->setItemDelegateForColumn(0, spinBoxDelegate);

    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->hideColumn(0);

    //QStringList wordList;
    //wordList << "alpha" << "omega" << "omega2" << "omega3" <<"omicron" << "zeta";

    for(int i=0;i<30;i++)
    {
        //for(int j=0;j<allColumns.count();j++)
        {
            auto check = new QCheckBox();
            check->setCheckState(((rand()%2==1)?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked)));
            ui->tableWidget->setCellWidget(i, 0,  check);

            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem(QString::number(rand()%2222)));

            QLineEdit *lineEdit = new QLineEdit();
            //QCompleter *completer = new QCompleter(wordList);
            //completer->setCaseSensitivity(Qt::CaseInsensitive);
            lineEdit->installEventFilter(this);
            //lineEdit->setCompleter(completer);
            lineEdit->setText("3213");
            //ui->tableWidget->setCellWidget(i,i,lineEdit);
            ui->tableWidget->setCellWidget(i,2,lineEdit);

            ui->tableWidget->setItem( i, 3,  new QTableWidgetItem(QString::number(rand()%2222)));
        }
    }


    QObject::connect(ui->tableWidget, &QTableWidget::clicked,
                     ui->tableWidget, [=](const QModelIndex& index) {
                         qDebug() << "In slot";
                         ui->tableWidget->setCurrentIndex(index);
                         //qDebug() << "Calling edit() "+index.data().toString();
                         ui->tableWidget->edit(index);

                         int row = ui->tableWidget->currentRow();
                         int col = ui->tableWidget->currentColumn();
                         qDebug() << "Called edit(): "+index.data().toString()+" | " + QString::number(row);
                         //QString label = ui->tableWidget->verticalHeaderItem(row)->text();
                         QString parameter = ui->tableWidget->horizontalHeaderItem(col)->text();
                         QString value = index.data().toString();
                         //qDebug() << "Called edit(): "+index.data().toString()+" | " + QString::number(row) +" | " + label;

                         QString sql="UPDATE " + tab + " SET "+parameter+" = '"+value;

                         //ui->textEdit->append("("+QString::number(row)+", "+QString::number(col) +") -- Called edit(): "+index.data().toString()+" | " + QString::number(col) +" | " + label);
                     });

}

Table_Form_1_2::~Table_Form_1_2()
{
    delete ui;
}
