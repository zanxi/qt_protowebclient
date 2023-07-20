#include "stumanager.h"
#include "ui_stumanager.h"

#include "Debug/logger.h"

stuManager::stuManager(QString nameTab, QWidget *parent) : QWidget(parent), ui(new Ui::stuManager)
{
    ui->setupUi(this);

    this->nameTab = nameTab;
    curStr = "";
    model = new QSqlTableModel;
    showTable(nameTab);


    QHeaderView *hv = ui->tableView->horizontalHeader();
    hv->setSortIndicatorShown(true);
    hv->sectionsClickable();
    connect(hv, SIGNAL(sectionClicked(int)), ui->tableView, SLOT(sortByColumn(int)));
}

stuManager::~stuManager()
{
    delete ui;
}

void stuManager::showTable(QString str)
{
    curStr = str;
    //model->setTable("RTransmitBuffer");
    model->setTable(nameTab);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if(!curStr.isEmpty()) model->setFilter(tr("name like '%%1%'").arg(curStr));
    model->select();
    ui->tableView->setModel(model);
//    ui->tableView->setAlternatingRowColors(true);
//    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    qDebug() << "showTable()";
}

void stuManager::addRow()
{
    int rowNum = model->rowCount();
    model->insertRow(rowNum);
//    model->setData(model->index(rowNum, 0), 0);
//    qDebug() << "addrow";
}

void stuManager::updateTable()
{
    model->submitAll();
    showTable("");
}

void stuManager::deleteRows()
{
    QItemSelectionModel *selections = ui->tableView->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();

    foreach (QModelIndex index, selected)
    {
        int curRow = index.row();
        model->removeRow(curRow);

    }

    if (!selected.isEmpty())
    {
        int btnClick = QMessageBox::warning(this, tr("delete"), tr("no delete？"),\
                                     QMessageBox::Yes, QMessageBox::No);

       if(QMessageBox::Yes == btnClick)
       {
            model->submitAll();
       }
       else if (QMessageBox::No == btnClick)
       {
            model->revertAll();
       }
    }
    else
    {
       QMessageBox::information(this, tr("info"), tr("No row selected!"),\
                                                  QMessageBox::Ok);
    }

    showTable("");
}
