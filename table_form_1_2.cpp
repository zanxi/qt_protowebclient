#include "table_form_1_2.h"
#include "ui_table_form_1_2.h"

#include "tabelwidget_module/comboboxitemdelegate.h"
#include "tabelwidget_module/spinboxitemdelegate.h"
#include "tabelwidget_module/checkboxitemdelegate.h"

#include "json/json_w.h"

#include <QLineEdit>
#include <QCompleter>
#include <QStringList>

#include "dataanimals.h"

//1.3 Быстрый ввод номеров респондента (бирки)
//1. Навигатор: Ввод данных  2. Меню: Дневная запись       3. Выбрать: Основные для партии

Table_Form_1_2::Table_Form_1_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table_Form_1_2)
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

    ui->pushButton->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );


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
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    //ui->tableWidget->hideColumn(0);
    for(int i=0;i<allColumns.count()+1;i++)ui->tableWidget->setColumnWidth(i, 150);

    //QStringList wordList;
    //wordList << "alpha" << "omega" << "omega2" << "omega3" <<"omicron" << "zeta";

    for(int i=0;i<3;i++)
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
            //ui->comboBox->addItem();

            QString val = QString::number(rand()%2222);

            ui->tableWidget->setItem( i, 3,  new QTableWidgetItem(val));
            ui->comboBox->addItem(val);
        }
    }

    on_comboBox_activated(0);

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

void Table_Form_1_2::on_comboBox_activated(int index)
{
    int i=0;
    selectRow=-1;
    //qDebug()<<"check: "<<ui->comboBox->currentText();
    //QString check = ui->comboBox->currentData(index).toString();
    QString check = ui->comboBox->currentText();
    for(i=0;i<ui->tableWidget->rowCount();i++)
    {
        QString val;
        QTableWidgetItem *item = ui->tableWidget->item(i,3);
        if (NULL != item) {
            val = item->text();
            if(check.contains(val))
            {
                selectRow = i;
                if(selectRowOld!=-1)ui->tableWidget->item(selectRowOld,3)->setBackground( Qt::white);
                ui->tableWidget->item(selectRow,3)->setBackground( Qt::gray);
                selectRowOld=selectRow;
                qDebug()<<"--- break: "<<"i: "<<i<<"; "<<val;
                break;
            }
            qDebug()<<"check: "<<check<<"; "<<"i: "<<i<<"; "<<val;
        }
    }



}


void Table_Form_1_2::on_pushButton_clicked()
{
    QMessageBox::information(this,"Спасибо","Сохранеы данные");
}

