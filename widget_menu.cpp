#include "widget_menu.h"
#include "ui_widget_menu.h"
#include "debug/logger.h"

#include <QTreeView>

Widget_menu::Widget_menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_menu)
{
    ui->setupUi(this);

    setWindowTitle("VIM MENU");
    setWindowIcon(QIcon(":/menu/icon.png"));
    model_builder = new ModelBuilder(file_path);
    ui->treeView->setModel(model_builder->GetTreeModel());
    //ui->treeView->verticalHeader()->hi

    connect(ui->treeView->selectionModel(),SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)),
            this, SLOT(selectTreeItem(const QItemSelection&,const QItemSelection&)));

}


void Widget_menu::selectTreeItem(const QItemSelection &selected, const QItemSelection &deselected)
{
    //QModelIndexList indices =  qDebug()<<selected.at(0).indexes();
    QModelIndexList indices =  selected.at(0).indexes();
    QModelIndex signalIndex = indices[0];
    //qDebug()<<signalIndex.data(0);
    QVariant qv = signalIndex.data(0);
    //QString val = qv.toString();
    QString val = qv.toStringList()[0];
    //qDebug()<<"val = "<<val;
    //logger::WriteMsg("Action button treeview: "+val.toStdString());

    if(!CollectionAction.contains(val)){
        CollectionAction.insert(val, new QWidget(this));
        logger::WriteMsg("Action button <<<TREE ITEM>>> treeview: "+val.toStdString());
    }

    emit signalMenu(val);



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

void Widget_menu::slot(QString a){
    logger::WriteMsg("sent signal From MainWindow to Widget_menu");
    // ui->treeView
}

Widget_menu::~Widget_menu()
{
    delete ui;
}
