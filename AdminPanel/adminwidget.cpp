#include "AdminWidget.h"
#include "db/connectdb.h"
#include "ui_adminwidget.h"

#include "modelbuilder.h"

#include "Debug/logger.h"
#include "dataanimals.h"

#include <QFileDialog>

AdminWidget::AdminWidget(QWidget *parent) : QWidget(parent), ui(new Ui::mainWidget)
{
    ui->setupUi(this);

    //ui->groupBox_db_sqlite->setDisabled(false);
    //ui->groupBox_db_pg->setDisabled(true);
    //ui->checkBox->setText("SQLite база данных");
    //ui->checkBox->setCheckState(Qt::CheckState::Unchecked);

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:#14B143;"
                                "padding: 4 20000 4 10;"
                                "}");



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

    ui->groupBox_4->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:#14B143;"
                                  "padding: 4 20000 4 10;"
                                  "}");

    ui->groupBox_5->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:#14B143;"
                                  "padding: 4 20000 4 10;"
                                  "}");

    ui->groupBox_db_pg->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:#14B143;"
                                  "padding: 4 20000 4 10;"
                                  "}");

    ui->groupBox_db_sqlite->setStyleSheet("QGroupBox {"
                                      "background-color: white;"
                                      "}"
                                      "QGroupBox::title {"
                                      "color: white;"
                                      "background-color:#14B143;"
                                      "padding: 4 20000 4 10;"
                                      "}");

    ui->groupBox_7->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:#14B143;"
                                  "padding: 4 20000 4 10;"
                                  "}");



    //setWindowTitle("VIM MENU");
    //setWindowIcon(QIcon(":/menu/icon.png"));
    model_builder = new ModelBuilder(file_path);
    ui->treeView->setModel(model_builder->GetTreeModel());
    //ui->treeView->verticalHeader()->hi

    this->setWindowTitle("Administrator panel perfomance");
    str = "";
    tabNum = 0;
    searchEdit = new QLineEdit;
    addBtn = new QPushButton(tr("Добавить"));
    updateBtn = new QPushButton(tr("Обновить таблицу"));
    deleteBtn = new QPushButton(tr("Удалить строчку"));

    creatCornerBtn();

    initUI();
    resize(900, 600);

    //ui->pushButton->setDisabled(false);
    //ui->pushButton_2->setDisabled(true);

    connect(addBtn, SIGNAL(clicked(bool)), this, SLOT(addBtnClicked()));
    connect(updateBtn, SIGNAL(clicked(bool)), this, SLOT(updateBtnClicked()));
    connect(deleteBtn, SIGNAL(clicked(bool)), this, SLOT(deleteBtnClicked()));
    connect(searchEdit,SIGNAL(textChanged(QString)), this, SLOT(getSearchText()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(setCurTabIndex()));

    connect(ui->treeView->selectionModel(),SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)),
            this, SLOT(selectTreeItem(const QItemSelection&,const QItemSelection&)));


    if(ui->checkBox->checkState())
    {
        ui->groupBox_db_sqlite->setDisabled(false);
        ui->groupBox_db_pg->setDisabled(true);
        ui->checkBox->setText("SQLite база данных");

        DataSystems::Instance().db_check=DB_check::SQLITE;
    }
    else
    {
        ui->groupBox_db_sqlite->setDisabled(true);
        ui->groupBox_db_pg->setDisabled(false);
        ui->checkBox->setText("PostgreSQL база данных");

        DataSystems::Instance().db_check=DB_check::PGSQL;
    }

    //connect(ui->treeView->selectionModel(), &AdminWidget::signalMenu, this, &AdminWidget::slotMenu);

}


void AdminWidget::slotMenu(QString val)
{

    qDebug()<<"value tree item: "<<val;
    return;

}


int cnt =0;
void AdminWidget::selectTreeItem(const QItemSelection &selected, const QItemSelection &deselected)
{
    cnt++;
    qDebug()<<" key tree item: "<<cnt;
    //QModelIndexList indices =  qDebug()<<selected.at(0).indexes();
    QModelIndexList indices =  selected.at(0).indexes();
    QModelIndex signalIndex = indices[0];    
    QVariant qv = signalIndex.data(0);    
    QString val = qv.toStringList()[0];
    qDebug()<<"val = "<<val;

    logger::WriteMsg("sent signal From Widget_menu to MainWindow: "+val.toStdString());
    initUI(val);

}



AdminWidget::~AdminWidget()
{
    delete ui;
    if(m_pDbManager!=nullptr)delete m_pDbManager;
    database.close();
    qDebug() << "Database closeed!";
}

void AdminWidget::refresh()
{
    if (0 == tabNum) m_pDbManager->showTable(str);
    //else if (1 == tabNum) m_pTeaManager->showTable(str);
}

void AdminWidget::addBtnClicked()
{
     if (0 == tabNum) m_pDbManager->addRow();
     //else if (1 == tabNum) m_pTeaManager->addRow();
}

void AdminWidget::updateBtnClicked()
{
    if (0 == tabNum) m_pDbManager->updateTable();
    //else if (1 == tabNum) m_pTeaManager->updateTable();
}

void AdminWidget::deleteBtnClicked()
{
    if (0 == tabNum) m_pDbManager->deleteRows();
    //else if (1 == tabNum) m_pTeaManager->deleteRows();
}

void AdminWidget::setCurTabIndex()
{
    tabNum = ui->tabWidget->currentIndex();
    refresh();
}

void AdminWidget::getSearchText()
{
    str = searchEdit->text().trimmed();
    refresh();
}

void AdminWidget::initUI(QString nameTab)
{
    m_pDbManager = new DbManager(nameTab);
    QByteArray ba = m_pDbManager->NameTab().toLocal8Bit();
    const char *c_str2 = ba.data();    
    if(ui->tabWidget->count()>0)ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(m_pDbManager, tr(c_str2));// +QString::fromStdString("Таблица данных Farm").toStdString()));
}

void AdminWidget::creatCornerBtn()
{
    searchEdit->setPlaceholderText(tr("Search by name"));
    searchEdit->setFixedSize(200, 20);

    ui->horizontalLayout->addWidget(searchEdit);
    ui->horizontalLayout->addSpacing(170);
    //hLayout->addStrut(170);
    ui->horizontalLayout->addWidget(addBtn);
    ui->horizontalLayout->addWidget(updateBtn);
    ui->horizontalLayout->addWidget(deleteBtn);


}


void AdminWidget::on_pushButton_2_clicked()
{
    if(DataSystems::Instance().db!=nullptr)DataSystems::Instance().db->closeDataBase();
    DataSystems::Instance().db = nullptr;

    DataSystems::Instance().db_host=ui->linerEdit_db_pg_host->text();
    DataSystems::Instance().db_name=ui->lineEdit_db_pg_name->text();
    DataSystems::Instance().db_login=ui->lineEdit_db_pg_login->text();
    DataSystems::Instance().db_password=ui->lineEdit_db_pg_password->text();

    DataSystems::Instance().db_sqlite_file=ui->lineEdit_db_sqlite_file->text();

        DataSystems::Instance().db = new DataBase();
        if(!DataSystems::Instance().db->Open())
        {
            DataSystems::Instance().db->closeDataBase();
        }


    this->close();
}


void AdminWidget::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->checkState())
    {
        ui->groupBox_db_sqlite->setDisabled(false);
        ui->groupBox_db_pg->setDisabled(true);
        ui->checkBox->setText("SQLite база данных");

        DataSystems::Instance().db_check=DB_check::SQLITE;
    }
    else
    {
        ui->groupBox_db_sqlite->setDisabled(true);
        ui->groupBox_db_pg->setDisabled(false);
        ui->checkBox->setText("PostgreSQL база данных");

        DataSystems::Instance().db_check=DB_check::PGSQL;
    }
}


void AdminWidget::on_pushButton_3_clicked()
{
    DataSystems::Instance().db_sqlite_file  = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::homePath());
    ui->lineEdit_db_sqlite_file->setText(DataSystems::Instance().db_sqlite_file);
}


void AdminWidget::on_pushButton_clicked()
{
    this->close();
}

