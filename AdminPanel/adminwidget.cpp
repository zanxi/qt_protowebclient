#include "AdminWidget.h"
#include "db/connectdb.h"
#include "ui_adminwidget.h"

#include "modelbuilder.h"

#include "Debug/logger.h"

AdminWidget::AdminWidget(QWidget *parent) : QWidget(parent), ui(new Ui::mainWidget)
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

    //connect(ui->treeView->selectionModel(), &AdminWidget::signalMenu, this, &AdminWidget::slotMenu);

}


void AdminWidget::slotMenu(QString val)
{
    //ui->verticalLayout_2.de;
    //logger::WriteMsg("sent signal From Widget_menu to MainWindow: "+val.toStdString());

    qDebug()<<"value tree item: "<<val;
    return;


//    QLayoutItem *child = ui->verticalLayout_2->takeAt(0);
//    //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)

//    if(!child) {return;}
//    QWidget* w = child->widget();

//    delete child;
//    if(!w) {return;}
//    ui->verticalLayout_2->removeWidget(w);
//    delete w;
    //child = ui->verticalLayout_2->takeAt(0);

    //************************************************************

//    if(!CollectionAction.contains(val)){
//        CollectionAction.insert(val, new QWidget(this));
//        logger::WriteMsg("Action button <<<TREE ITEM>>> treeview: "+val.toStdString());
//    }

//    QWidget *fm;
//    if(val.contains("Глобальные установки фермы"))
//        {
//        fm = new Form_1_1;
//    }
//    else if(val.contains("Дневная запись"))
//        {
//        fm = new Form_1_2;
//    }
//    else if(val.contains("Группы"))
//        {
//        fm = new Form_1_2_General;
//    }
//    else
//    {
//        //fm = new Form_1_2_General;
//        fm = new Form_Z_1;
//    }
//    ui->verticalLayout_2->addWidget(fm);

}


int cnt =0;
void AdminWidget::selectTreeItem(const QItemSelection &selected, const QItemSelection &deselected)
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
    //show();
    //logger::WriteMsg("Action button treeview: "+val.toStdString());

//    if(!CollectionAction.contains(val)){
//        CollectionAction.insert(val, new QWidget(this));
//        logger::WriteMsg("Action button <<<TREE ITEM>>> treeview: "+val.toStdString());
//    }

    //emit signalMenu(val);



    //indices[0].child(0,0)

    //QTreeView::selec  ::selectionChanged(selected, deselected);
    //    if (!m_blockSelectionEvent) {
    //        QModelIndex signalIndex;
    //        QModelIndexList indices = ui->treeView->SelectItems();
    //        if (indices.size() > 0) {
    //            signalIndex = indices[0];
    //        }
    //        emit markerSelected(signalIndex);
    //    }
}



AdminWidget::~AdminWidget()
{
    delete ui;
    if(m_pStuManager!=nullptr)delete m_pStuManager;
    database.close();
    qDebug() << "Database closeed!";
}

void AdminWidget::refresh()
{
    if (0 == tabNum) m_pStuManager->showTable(str);
    //else if (1 == tabNum) m_pTeaManager->showTable(str);
}

void AdminWidget::addBtnClicked()
{
     if (0 == tabNum) m_pStuManager->addRow();
     //else if (1 == tabNum) m_pTeaManager->addRow();
}

void AdminWidget::updateBtnClicked()
{
    if (0 == tabNum) m_pStuManager->updateTable();
    //else if (1 == tabNum) m_pTeaManager->updateTable();
}

void AdminWidget::deleteBtnClicked()
{
    if (0 == tabNum) m_pStuManager->deleteRows();
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
//    qDebug() << QString("str = %1").arg(str);
//    qDebug() << tabNum;
}

void AdminWidget::initUI(QString nameTab)
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

void AdminWidget::creatCornerBtn()
{
    searchEdit->setPlaceholderText(tr("Search by name"));
    searchEdit->setFixedSize(200, 20);

    QWidget *cornerWidget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout;
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

