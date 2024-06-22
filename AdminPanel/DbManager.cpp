#include "DbManager.h"
#include "ui_DbManager.h"

#include "Debug/logger.h"
#include "../dataanimals.h"
#include "db/SqlDataBase.h"

#include <QSqlTableModel>
#include <QStandardItemModel>

#include "csv/csvfile.h"

DbManager::DbManager(QString nameTab, QWidget *parent) : QWidget(parent), ui(new Ui::DbManager)
{
    ui->setupUi(this);

    this->nameTab = nameTab;
    //model = new QStandardItemModel();

    if (!createConnection())return;

    //DataSystems::Instance().clear();
//    ui->lineEdit_number_delete_row->setReadOnly(true);
//    ui->lineEdit_number_insert_row->setReadOnly(true);
//    m_searchHighLight = new SearchHighLight(ui->textEdit_log->document());
    //logger::WriteLog(" --------- Initialize application <<<VIM>>> -------------");

    QSqlDatabase db = QSqlDatabase::database("connect_model");
    model = nullptr;
    model = new QSqlTableModel(nullptr,db);

    on_pushButton_update_table_clicked();

    QHeaderView *hv = ui->tableView->horizontalHeader();
    hv->setSortIndicatorShown(true);
    hv->sectionsClickable();
    connect(hv, SIGNAL(sectionClicked(int)), ui->tableView, SLOT(sortByColumn(int)));

    connect(ui->tableView->model(), SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(onDataChanged(QModelIndex,QModelIndex)), Qt::DirectConnection);
}

bool DbManager::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL","connect_model");
    db.setHostName("192.168.1.3");
    db.setDatabaseName("vim3");
    db.setUserName("postgres");
    db.setPassword("000");
    db.setPort(5432);
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
                              qApp->tr("Unable to establish a database connection.\n"
                                       "This example needs SQLite support. Please read "
                                       "the Qt SQL driver documentation for information how "
                                       "to build it.\n\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    return true;
}


void DbManager::on_pushButton_update_table_clicked()
    {
    //GetVariablesAndType(nameTab);
    //QSqlQueryModel model;
    //model.setQuery("SELECT * FROM employee");
    //int salary = model.record(4).value("salary").toInt();

    ui->tableView->setModel(nullptr);

    model->setTable(nameTab);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //QString qStr = QSqlTableModel::sele ::selectStatement();
    //qStr += " LIMIT 100";
    //model->sele

    model->setFilter(QString(" 1=1 ORDER BY "+primaryKey+" ASC"));

    if(!nameTab.contains("dataservice"))
    {
        //model->setFilter(QString(" "+primaryKey+">2 AND "+primaryKey+"<8 ORDER BY "+primaryKey+" ASC"));
    }
    //else model->setFilter(QString(" id>1 AND id<7 ORDER BY id  ASC"));

    model->select();
    ui->tableView->setModel(model);
    for(int i=0;i<ui->tableView->model()->columnCount();i++)ui->tableView->setColumnWidth(i, 100);

    GetLastId();


}


/*

void MainWindow::CreateTableWidget()
{
    std::map<int, std::vector<std::string>> rows_ = csvfile::Read_TabMap("RIndication");

    QString sql =  QString::fromStdString(SqlDataBase::SelectTable("RIndication"));
    logger::WriteMsg("SELECT: -------------------" + sql.toStdString());

    QSqlQuery* query = DataSystems::Instance().db->sql_exec2(sql);

    //int IdResume = query->value(0).toInt();
    //QString NameResume = query->value(1).toString();
    //QString ComentResume = query.value(2).toString();
    //QString Resume = query.value(3).toString();



    QStringList NameColumns;
    int i=0;
    //NameColumns<<" ";
    //QList<QString> allColumns = { "1", "2", "3", "4", "5", "6", "7", "8" };
    foreach (std::string cols, rows_[0])
    {
        //qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
        //i++;
        NameColumns<<QString::fromStdString(cols);
        logger::WriteMsg("select column:" + cols);
    }

    ui->tableWidget->clear();

    ui->tableWidget->setColumnCount( rows_[0].size() );
    ui->tableWidget->setRowCount( rowCounter );

    //ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
    ui->tableWidget->setVerticalHeaderItem(0, new QTableWidgetItem("Название"));
    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    i=0;
    while(query->next())
    {
        for(int j=0; j<rows_[0].size();j++)
        {
            //auto check = new QCheckBox();
            //check->setCheckState(((rand()%2==1)?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked)));
            //ui->tableWidget->setCellWidget(i, 0,  check);

            ui->tableWidget->setItem( i, j,  new QTableWidgetItem(query->value(j).toString()));
            //ui->tableWidget->setItem( i, 2,  new QTableWidgetItem(QString::number(rand()%444)));
        }
        i++;
    }
}
/**/


void DbManager::onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight)
{    
    qDebug() << "In slot";

    QModelIndex mi = ui->tableView->currentIndex();
    //                         QModelIndex mi = ui->tableView->in;
    int col = mi.column();    
    QString parameter = ui->tableView->model()->headerData(col, Qt::Horizontal).toString();
    QString value = topLeft.data().toString();

    QString parameterID = ui->tableView->model()->headerData(0, Qt::Horizontal).toString();    
//    /return;

    int rowidx = ui->tableView->selectionModel()->currentIndex().row();
    {
            QScopedPointer<DataBase> db_func(new DataBase()); // инициализация соединения

             QString valueId = model->index(rowidx , 0).data().toString();
             QString sql2 = QString::fromStdString(SqlDataBase::UpdateValues(parameterID.toStdString(),valueId.toStdString(),{key_value_t(parameter.toStdString(),value.toStdString())}));
             qDebug() << "Data: "<<mi.data().toString()<<"; parameterID: "<<parameterID<<"; parameter: "<<parameter<<"; valuid: ";

             //db_func->sql_exec(sql2,"");

             QString sql="UPDATE " + nameTab + " SET "+parameter+" = '"+value+"'" +
                           " where " + parameterID + " = "+ ""+ valueId +"";
             qDebug()<<sql;
             db_func->sql_exec(sql,"");
    }
    showTable(nameTab);
}

/*
bool DbManager::sql_exec(QString sql_script, QString comment)
{
    QSqlDatabase db=QSqlDatabase::database(DataSystems::Instance().conn_name);
    QSqlQuery *query = new QSqlQuery(db);
    if(!query->exec(sql_script)) {
        logger::WriteMsg(
            QString("Error sql script: XXXXXXXXXXXXXXXXX "+
                    comment+
                    " --- "+
                    sql_script +
                    " ----> error ").toStdString());
        delete query;
        return false;
    }
    else
    {
        delete query;
        return true;
    }

}

QSqlQuery* DbManager::sql_exec2(QString sql_script, QString comment)
{
    QSqlDatabase db = QSqlDatabase::database(DataSystems::Instance().conn_name);
    QSqlQuery *query = new QSqlQuery(db);
    if(!query->exec(sql_script)) {
        logger::WriteMsg(
            QString("Error sql script: XXXXXXXXXXXXXXXXX "+
                    comment+
                    " --- "+
                    sql_script +
                    " ----> error ").toStdString());
        return nullptr;
    }
    else
    {
        return query;
    }
}

/**/

DbManager::~DbManager()
{
    delete ui;
}

void DbManager::CreateModel()
{
    std::map<int, std::vector<std::string>> rows_ = csvfile::Read_TabMap(nameTab.toStdString());

    QString sql =  QString::fromStdString(SqlDataBase::SelectTable("RIndication"));
    logger::WriteMsg("SELECT: -------------------" + sql.toStdString());

    QScopedPointer<DataBase> db_func(new DataBase()); // инициализация соединения
    QSqlQuery* query = db_func->sql_exec2("select * from "+ nameTab +";");

    //QStandardItemModel *model = new QStandardItemModel();

    int i=0;
    while(query->next())
    {
        QList<QStandardItem*> list;
        QString txt="";
        for(int j=0; j<rows_[0].size();j++)
        {
            QStandardItem *item = new QStandardItem(query->value(j).toString());
            txt+=query->value(j).toString()+" | ";
            list.push_back(item);
            //ui->tableWidget->setItem( i, 2,  new QTableWidgetItem(QString::number(rand()%444)));
        }
        logger::WriteMsg("!!!!!!!!!!!!!!!! " + nameTab.toStdString() +" !!!!!!!!!!!!!!!!!","datatable.txt");
        logger::WriteMsg(txt.toStdString(),"datatable.txt");
        //model->appendRow(list);
        i++;
    }
    //model->setTable(nameTab);

    // /////////////////////////
    QStringList NameColumns;
    int k=0;
    foreach (std::string cols, rows_[0])
    {
        NameColumns<<QString::fromStdString(cols);
        model->setHeaderData(k, Qt::Horizontal, cols.data());
        k++;
    };

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}



void DbManager::showTable(QString str)
{
    return;
    //model->sele
    //ui->tableView->model()->;

    //model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //if(!curStr.isEmpty()) modelDB->setFilter(tr("name like '%%1%'").arg(curStr));
    //model->select();
    model->select();

    return;

    model = nullptr;

    std::map<int, std::vector<std::string>> rows_ = csvfile::Read_TabMap(nameTab.toStdString());

    QString sql =  QString::fromStdString(SqlDataBase::SelectTable("RIndication"));
    logger::WriteMsg("SELECT: -------------------" + sql.toStdString());

    QScopedPointer<DataBase> db_func(new DataBase()); // инициализация соединения
    QSqlQuery* query = db_func->sql_exec2("select * from "+ nameTab +";");

    //QStandardItemModel *model = new QStandardItemModel();
//    model = new QStandardItemModel();

//    int i=0;
//    while(query->next())
//    {
//        QList<QStandardItem*> list;
//        QString txt="";
//        for(int j=0; j<rows_[0].size();j++)
//        {
//             QStandardItem *item = new QStandardItem(query->value(j).toString());
//             txt+=query->value(j).toString()+" | ";
//             list.push_back(item);
//             //ui->tableWidget->setItem( i, 2,  new QTableWidgetItem(QString::number(rand()%444)));
//        }
//        logger::WriteMsg("!!!!!!!!!!!!!!!! " + nameTab.toStdString() +" !!!!!!!!!!!!!!!!!","datatable.txt");
//        logger::WriteMsg(txt.toStdString(),"datatable.txt");
//        model->appendRow(list);
//        i++;
//    }
//    //model->setTable(nameTab);

//    // /////////////////////////
//    QStringList NameColumns;
//    int k=0;
//    foreach (std::string cols, rows_[0])
//    {
//        NameColumns<<QString::fromStdString(cols);
//        model->setHeaderData(k, Qt::Horizontal, cols.data());
//        k++;
//    };

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void DbManager::addRow()
{
    {
    QString sql = "INSERT INTO "+ nameTab +"("+ QString::fromStdString(DataSystems::Instance().mjpj[nameTab][2].key) +") VALUES (' ');";

        //logger::WriteMsg(sql.toStdString());

    QScopedPointer<DataBase> db(new DataBase());
    if(db->StatusOpen())
    {
        db->sql_exec(sql,"");
    }
    }

    showTable(nameTab);

}

void DbManager::GetLastId()
{
    QString parameterID = ui->tableView->model()->headerData(0, Qt::Horizontal).toString();
    QString sql = "SELECT " + parameterID + " FROM " + nameTab + "  ORDER BY " + parameterID + " DESC LIMIT 1;";
    QScopedPointer<DataBase> db_func(new DataBase());
    QSqlQuery* query = db_func->sql_exec2(sql);
    logger::WriteMsg("GetNameTables();");

    logger::WriteMsg(sql.toStdString());

    //while(query->next())
    {
    //ui->lineEdit_number_insert_row->setText("после " + query->value(0).toString() + " строки");
    }
}


void DbManager::GetVariablesAndType(QString tab)
{

    Variables.clear();

    std::map<int, std::vector<std::string>> rows_ = csvfile::Read_TabMap(tab.toStdString());
    QString sql =  "SELECT column_name, data_type FROM information_schema.columns WHERE table_name = '" + tab.toLower()  + "' ORDER BY ordinal_position;";
    // SELECT column_name, data_type FROM information_schema.columns WHERE table_name = '" + tab.toLower()  + "' ORDER BY ordinal_position;

    logger::WriteLog("sql vars: "+sql);
    //qDebug()<<"sql vars: "<<sql;
    QScopedPointer<DataBase> db_func(new DataBase());
    QSqlQuery* query = db_func->sql_exec2(sql);
    while(query->next())
    {
    QString var = query->value(0).toString();
    QString type = query->value(1).toString();
    Variables[var] = type;
    if (type.toLower().contains("bigint")) primaryKey = var;
    }

    /**/
}


void DbManager::Select()
{
    return;
    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {

    }
}

void DbManager::updateTable()
{    
    showTable(nameTab);
}

void DbManager::deleteAllRows()
{
    QString sql = "delete from " + nameTab +

                  " where " +
                  QString::fromStdString(DataSystems::Instance().mjpj[nameTab][0].key)+  // карта содержит имя таблицы и ее переменные - здесь указан primary key variable
                  " in (select " +
                  QString::fromStdString(DataSystems::Instance().mjpj[nameTab][0].key)+
                  " from "+ nameTab +")";

    //delete from list_for_delete where id in (select id from to_rm)

    {
        QScopedPointer<DataBase> db(new DataBase());
        if(db->StatusOpen())
        {
            db->sql_exec(sql,"");
        }
    }

    showTable(nameTab);
}

void DbManager::deleteRows()
{
    qDebug() << "In slot";

    QModelIndex mi = ui->tableView->currentIndex();
    //                         QModelIndex mi = ui->tableView->in;
    int col = mi.column();
    QString parameter = ui->tableView->model()->headerData(col, Qt::Horizontal).toString();
    QString value = mi.data().toString();

    QString parameterID = ui->tableView->model()->headerData(0, Qt::Horizontal).toString();
    int rowidx;
    {
       QScopedPointer<DataBase> db_func(new DataBase()); // инициализация соединения            
            int rowidx = ui->tableView->selectionModel()->currentIndex().row();
            int valueId = model->index(rowidx , 0).data().toInt();
            QString sql="DELETE FROM " + nameTab + " WHERE " + parameterID + " = "+ ""+ QString::number(valueId) +"";
            //delete from list_for_delete where id in (select id from to_rm)
            db_func->sql_exec(sql,"");
    }

    showTable(nameTab);

    QModelIndex mi2 = ui->tableView->model()->index(rowidx-1,0);
    if(mi2.isValid()){
        ui->tableView->selectRow(rowidx);
    }
}
