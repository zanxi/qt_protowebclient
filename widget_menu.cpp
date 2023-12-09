#include "widget_menu.h"
#include "ui_widget_menu.h"
#include "debug/logger.h"

#include <QTreeView>
#include "dataanimals.h"

Widget_menu::Widget_menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_menu)
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



    setWindowTitle("VIM MENU");
    setWindowIcon(QIcon(":/menu/icon.png"));
    model_builder = new ModelBuilder(file_path);
    ui->treeView->setModel(model_builder->GetTreeModel());
    //ui->treeView->verticalHeader()->hi

    ui->treeView->expandAll();
    //ui->treeView->setEnabled();



    connect(ui->treeView->selectionModel(),SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)),
            this, SLOT(selectTreeItem(const QItemSelection&,const QItemSelection&)));

}


void Widget_menu::selectTreeItem(const QItemSelection &selected, const QItemSelection &deselected)
{
    //QModelIndexList indices =  qDebug()<<selected.at(0).indexes();
    QModelIndexList indices =  selected.at(0).indexes();
    QModelIndex signalIndex = indices[0];    
    QVariant qv = signalIndex.data(0);    
    QString val = qv.toStringList()[0];    
    if(!CollectionAction.contains(val)){
        CollectionAction.insert(val, new QWidget(this));
        logger::WriteMsg("Action button <<<TREE ITEM>>> treeview: "+val.toStdString());
    }
    emit signalMenu(val);
}

void Widget_menu::slot(QString a){
    logger::WriteMsg("sent signal From MainWindow to Widget_menu");
    // ui->treeView
}

Widget_menu::~Widget_menu()
{
    delete ui;
}
