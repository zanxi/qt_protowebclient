#ifndef FORM_LIST_COWS_H
#define FORM_LIST_COWS_H

#include <QWidget>

#include "utils/extendqtablewidget.h"

#include "db/asyncsql/asyncsqltablemodel.h"
#include "db/asyncsql/databaseconnection.h"
#include "db/asyncsql/asyncsqltablemodel.h"


namespace Ui {
class Form_List_Cows;
}

class Form_List_Cows : public QWidget
{
    Q_OBJECT

public:
    explicit Form_List_Cows(QWidget *parent = nullptr);    
    ~Form_List_Cows();

private slots:
    void on_pushButton_delete_clicked();

    void on_pushButton_select_clicked();

    void on_pushButton_add_clicked();

    void on_comboBox_numbers_activated(int index);

    void on_pushButton_delete_all_clicked();

    void on_pushButton_addrandom_clicked();

    void on_lineEdit_cow_textChanged(const QString &arg1);

private:
    Ui::Form_List_Cows *ui;
    void create();
    int selectRow=-1;
    int selectRowOld=-1;
    QString checkAnimals;

    void addRandom();
    void GetData();
    void GetData(const QString &str);

    AsyncSql::AsyncSqlTableModel *model;
    QString TableName;

};

#endif // FORM_LIST_COWS_H
