#include "adminpanel.h"
#include "ui_adminpanel.h"
#include "db/connectdb.h"
#include "ui_adminpanel.h"
#include "modelbuilder.h"
#include "Debug/logger.h"


AdminPanel::AdminPanel(QWidget *parent) : QWidget(parent), ui(new Ui::AdminPanel)
{
    ui->setupUi(this);

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

    ui->groupBox_6->setStyleSheet("QGroupBox {"
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

    this->setWindowTitle("Таблица данных");
    str = "";
    tabNum = 0;
    searchEdit = new QLineEdit;
    addBtn = new QPushButton(tr("Добавить"));
    updateBtn = new QPushButton(tr("Обновить таблицу"));
    deleteBtn = new QPushButton(tr("Удалить строчку"));

    creatCornerBtn();

    connectDb(database);
    initUI();
    resize(900, 600);

    connect(addBtn, SIGNAL(clicked(bool)), this, SLOT(addBtnClicked()));
    connect(updateBtn, SIGNAL(clicked(bool)), this, SLOT(updateBtnClicked()));
    connect(deleteBtn, SIGNAL(clicked(bool)), this, SLOT(deleteBtnClicked()));
    connect(searchEdit,SIGNAL(textChanged(QString)), this, SLOT(getSearchText()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(setCurTabIndex()));

    connect(ui->treeView->selectionModel(),SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)),
            this, SLOT(selectTreeItem(const QItemSelection&,const QItemSelection&)));

    //connect(ui->treeView->selectionModel(), &AdminPanel::signalMenu, this, &AdminPanel::slotMenu);

}


void AdminPanel::slotMenu(QString val)
{
    qDebug()<<"value tree item: "<<val;
    return;
}

int cnt =0;
void AdminPanel::selectTreeItem(const QItemSelection &selected, const QItemSelection &deselected)
{
    cnt++;
    qDebug()<<" key tree item: "<<cnt;
    //QModelIndexList indices =  qDebug()<<selected.at(0).indexes();
    QModelIndexList indices =  selected.at(0).indexes();
    QModelIndex signalIndex = indices[0];
    //qDebug()<<signalIndex.data(0);
    QVariant qv = signalIndex.data(0);
    //QString val = qv.toString();
    QString val = qv.toStringList()[0];
    qDebug()<<"val = "<<val;

    logger::WriteMsg("sent signal From Widget_menu to MainWindow: "+val.toStdString());
    initUI(val);
}



AdminPanel::~AdminPanel()
{
    delete ui;
    if(m_pStuManager!=nullptr)delete m_pStuManager;
    database.close();
    qDebug() << "Database closeed!";
}

void AdminPanel::refresh()
{
    if (0 == tabNum) m_pStuManager->showTable(str);
    //else if (1 == tabNum) m_pTeaManager->showTable(str);
}

void AdminPanel::addBtnClicked()
{
    if (0 == tabNum) m_pStuManager->addRow();
    //else if (1 == tabNum) m_pTeaManager->addRow();
}

void AdminPanel::updateBtnClicked()
{
    if (0 == tabNum) m_pStuManager->updateTable();
    //else if (1 == tabNum) m_pTeaManager->updateTable();
}

void AdminPanel::deleteBtnClicked()
{
    if (0 == tabNum) m_pStuManager->deleteRows();
    //else if (1 == tabNum) m_pTeaManager->deleteRows();
}

void AdminPanel::setCurTabIndex()
{
    tabNum = ui->tabWidget->currentIndex();
    refresh();
}

void AdminPanel::getSearchText()
{
    str = searchEdit->text().trimmed();
    refresh();
    //    qDebug() << QString("str = %1").arg(str);
    //    qDebug() << tabNum;
}

void AdminPanel::initUI(QString nameTab)
{
    //    if(m_pStuManager!=nullptr)
    //    {
    //        delete m_pStuManager;
    //        m_pStuManager = nullptr;
    //    }
    m_pStuManager = new stuManager(nameTab);
    QByteArray ba = m_pStuManager->NameTab().toLocal8Bit();
    const char *c_str2 = ba.data();
    if(ui->tabWidget->count()>0)ui->tabWidget->removeTab(0);
    ui->tabWidget->addTab(m_pStuManager, tr(c_str2));// +QString::fromStdString("Таблица данных Farm").toStdString()));
    //ui->tabWidget->addTab(m_pTeaManager, tr("Teacher"));
}

void AdminPanel::creatCornerBtn()
{
    searchEdit->setPlaceholderText(tr("Search by name"));
    searchEdit->setFixedSize(200, 20);

    //QWidget *cornerWidget = new QWidget;
    //QHBoxLayout *hLayout = new QHBoxLayout;
    ui->horizontalLayout->addWidget(searchEdit);
    ui->horizontalLayout->addSpacing(170);
    //hLayout->addStrut(170);
    ui->horizontalLayout->addWidget(addBtn);
    ui->horizontalLayout->addWidget(updateBtn);
    ui->horizontalLayout->addWidget(deleteBtn);

    //    ui->horizontalLayout->addWidget(searchEdit);
    //    ui->horizontalLayout->addSpacing(130);
    //        //hLayout->addStrut(170);
    //    ui->horizontalLayout->addWidget(addBtn);
    //    ui->horizontalLayout->addWidget(updateBtn);
    //    ui->horizontalLayout->addWidget(deleteBtn);

    //cornerWidget->setLayout(hLayout);
    //ui->tabWidget->setCornerWidget(cornerWidget, Qt::TopRightCorner);
}

