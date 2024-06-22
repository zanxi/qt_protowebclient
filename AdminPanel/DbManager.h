#ifndef DbManager_H
#define DbManager_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>

#include "./utils/Utils.h"

namespace Ui
{
class DbManager;
}

class DbManager : public QWidget
{
    Q_OBJECT

public:
    explicit DbManager(QString nameTab, QWidget *parent = 0);
    ~DbManager();
    void showTable(QString str);
    void CreateModel();
    void addRow();
    void updateTable();
    void deleteRows();
    void deleteAllRows();

    void Select();

    QString NameTab(){
        return nameTab;
    }
    QString nameTab = "RVisitTab";

public Q_SLOTS:
    void onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);

private:

    Ui::DbManager *ui;
    QString curStr;
    //QScopedPointer<QSqlTableModel> modelDB;
    //QSqlTableModel *modelDB2;
    //QStandardItemModel *modelDB;
    //QStandardItemModel *model;
    QSqlTableModel *model;

    //QSqlQuery* sql_exec2(QString sql_script, QString comment);
    //bool sql_exec(QString sql_script, QString comment);
    void on_pushButton_update_table_clicked();
    void GetLastId();
    //void CreateTableWidget();
    //void CreateTableWidgetVars();
    void GetVariablesAndType(QString tab);
    bool createConnection();
    //void create();
    //void SaveAutorizartion();
    //SearchHighLight* m_searchHighLight;

    map_db_sql Variables;
    QString primaryKey;


};

#endif // DbManager_H

