#include "DbManager.h"
#include "ui_DbManager.h"

#include "Debug/logger.h"
#include "../dataanimals.h"
#include "db/SqlDataBase.h"

#include <QSqlTablemodel>

DbManager::DbManager(QString nameTab, QWidget *parent) : QWidget(parent), ui(new Ui::DbManager)
{
    ui->setupUi(this);

    modelDB = new QSqlTableModel(this,DataSystems::Instance().db->db);
    this->nameTab = nameTab;
    curStr = "";

    modelDB->setTable(nameTab);
    ui->tableView->setModel(modelDB);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->hideColumn(0);

    showTable(nameTab);
    qDebug()<<"table: "<<nameTab<<"\n";
    logger::WriteMsg(QString("table: " + nameTab + "\n").toStdString());


    QHeaderView *hv = ui->tableView->horizontalHeader();
    hv->setSortIndicatorShown(true);
    hv->sectionsClickable();
    connect(hv, SIGNAL(sectionClicked(int)), ui->tableView, SLOT(sortByColumn(int)));

    QObject::connect(ui->tableView, &QTableView::clicked,
                     ui->tableView, [=](const QModelIndex& index) {
                         qDebug() << "In slot";
                         ui->tableView->setCurrentIndex(index);
                         //qDebug() << "Calling edit() "+index.data().toString();
                         ui->tableView->edit(index);

                         QModelIndex mi = ui->tableView->currentIndex();
//                         QModelIndex mi = ui->tableView->in;
                         int col = mi.column();
                         //qDebug() << "Called edit(): "+index.data().toString()+" | " + QString::number(row);
                         //QString label = ui->tableView->verticalHeaderItem(row)->text();
                         QString parameter = ui->tableView->model()->headerData(col, Qt::Horizontal).toString();
                         QString parameterID = ui->tableView->model()->headerData(0, Qt::Horizontal).toString();
                         QString value = index.data().toString();
                         //qDebug() << "Called edit(): "+index.data().toString()+" | " + QString::number(row) +" | " + label;

                         //QItemSelectionModel *select = ui->tableView->selectionModel();
                         //QModelIndex miId = select->selectedColumns().at(0);

                         int rowidx = ui->tableView->selectionModel()->currentIndex().row();
                         QString value_w = modelDB->index(rowidx , 0).data().toString();

                         QString sql="UPDATE " + nameTab + " SET "+parameter+" = '"+value+"'" +
                                       " where " + parameterID + " = "+ "'"+ value_w +"'";
                         //qDebug()<<sql;
                         //DataSystems::Instance().db->sql_exec(sql,"");

                         //ui->textEdit->append("("+QString::number(row)+", "+QString::number(col) +") -- Called edit(): "+index.data().toString()+" | " + QString::number(col) +" | " + label);
                     });

    connect(ui->tableView->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChanged(const QModelIndex&, const QModelIndex&)));

}

void DbManager::onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight)
{
    qDebug() << "In slot";

    QModelIndex mi = ui->tableView->currentIndex();
    //                         QModelIndex mi = ui->tableView->in;
    int col = mi.column();
    //qDebug() << "Called edit(): "+index.data().toString()+" | " + QString::number(row);
    //QString label = ui->tableView->verticalHeaderItem(row)->text();
    QString parameter = ui->tableView->model()->headerData(col, Qt::Horizontal).toString();
    QString value = topLeft.data().toString();

    QString parameterID = ui->tableView->model()->headerData(0, Qt::Horizontal).toString();

    int rowidx = ui->tableView->selectionModel()->currentIndex().row();
    QString valueId = modelDB->index(rowidx , 0).data().toString();

    QString sql2=QString::fromStdString(SqlDataBase::UpdateValues(parameterID.toStdString(),valueId.toStdString(),{key_value_t(parameter.toStdString(),value.toStdString())}));
    DataSystems::Instance().db->sql_exec(sql2,"");

    QString sql="UPDATE " + nameTab + " SET "+parameter+" = '"+value+"'" +
                  " where " + parameterID + " = "+ "'"+ valueId +"'";
    qDebug()<<"sql2"<<sql;
    qDebug()<<"sql"<<sql;
    DataSystems::Instance().db->sql_exec(sql,"");
    qDebug() << bottomRight.data().toString() << "|" <<topLeft.data().toString();
}

DbManager::~DbManager()
{
    modelDB->clear();
    modelDB=nullptr;
    delete ui;
}

void DbManager::showTable(QString str)
{
    logger::WriteMsg("Admin settings");
    logger::WriteMsg(QString("table: " + nameTab + "\n").toStdString());
    if(str=="") curStr = str;
    else curStr = "RTransmitBuffer";
    modelDB->setTable(nameTab);
    modelDB->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //if(!curStr.isEmpty()) modelDB->setFilter(tr("name like '%%1%'").arg(curStr));
    modelDB->select();

}

void DbManager::addRow()
{        
    int rowNum = modelDB->rowCount();
    modelDB->insertRow(rowNum);
}

void DbManager::Select()
{
    QSqlTableModel *model = new QSqlTableModel(this, DataSystems::Instance().db->db);
    model->setTable("employee");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Salary"));

    QTableView *view = new QTableView;
    view->setModel(model);
    view->hideColumn(0); // do not show the ID
    view->show();

    QSqlQueryModel sqlQuery;
    sqlQuery.setQuery("SELECT * FROM employee");
    //int salary = sqlQuery.record(4).value("salary").toInt();
}

void DbManager::updateTable()
{    

    //modelDB->select();
//    QmodelDBIndex index = modelDB->index(ui->tableView->current(),i);

    //modelDB->setTable(nameTab);
    //QMessageBox::information(this, tr("Cached Table"),tr("The database reported: %1").arg("Excellent: "+nameTab));
    //QSqlTablemodelDB *modelDB = qobject_cast<QSqlTablemodelDB *>(ui->tableView->modelDB());
    //modelDB->setTable(nameTab);
    //modelDB->database().transaction();
    //modelDB->select();

    //modelDB->Update()

    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->tableView->model());
    model->setData(modelDB->index(2, 2), 75000);

    //ui->tableView->model()->setData(modelDB->index(2, 2), 75000);
    ui->tableView->model()->submit();

    //if (modelDB->submitAll())
    {
      //  modelDB->database().commit();
//        QMessageBox::information(this, tr("Cached Table"),tr("The database reported: %1").arg("Excellent"));
    }
    //else
    {
        //modelDB->database().rollback();
        //QMessageBox::warning(this, tr("Cached Table"),tr("The database reported an error: %1").arg(modelDB->lastError().text()));
    }

    //modelDB->setTable(nameTab);
    //modelDB->setEditStrategy(QSqlTablemodelDB::OnManualSubmit);

    //modelDB->select();

    //modelDB->submitAll();
    showTable(nameTab);
    //logger::WriteLog("update database table: "+nameTab+" ------------ !!!!!!!!!!!!!!!!!!!!!!");
    logger::WriteMsg(QString("update database table: "+nameTab+" ------------ !!!!!!!!!!!!!!!!!!!!!!").toStdString());

    if(DataSystems::Instance().db->StatusOpen())
    {
        logger::WriteMsg(QString("DataBase open !!!!!!!!!!").toStdString());
    }
    else
    {
        logger::WriteMsg(QString("DataBase closed !!!!!!!!!!").toStdString());
    }
}

void DbManager::deleteRows()
{

    modelDB->setTable(nameTab);
    ui->tableView->setModel(modelDB);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QItemSelectionModel *selections = ui->tableView->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();

    foreach (QModelIndex index, selected)
    {
        int curRow = index.row();
        modelDB->removeRow(curRow);

    }

    if (!selected.isEmpty())
    {
        int btnClick = QMessageBox::warning(this, tr("delete"), tr("no delete？"),\
                                     QMessageBox::Yes, QMessageBox::No);

       if(QMessageBox::Yes == btnClick)
       {
            modelDB->submitAll();
       }
       else if (QMessageBox::No == btnClick)
       {
            modelDB->revertAll();
       }
    }
    else
    {
       QMessageBox::information(this, tr("info"), tr("No row selected!"),\
                                                  QMessageBox::Ok);
    }

    showTable("");
}
