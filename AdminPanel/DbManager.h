#ifndef DbManager_H
#define DbManager_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

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
    void addRow();
    void updateTable();
    void deleteRows();

    void Select();

    QString NameTab(){
        return nameTab;
    }
    QString nameTab = "RVisitTab";

public slots:
    void onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);

private:

    Ui::DbManager *ui;
    QString curStr;
    QSqlTableModel *modelDB ;


};

#endif // DbManager_H

