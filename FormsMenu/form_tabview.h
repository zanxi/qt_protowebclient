#ifndef FORM_TABVIEW_H
#define FORM_TABVIEW_H


#include <QWidget>

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableView>
#include <QHeaderView>
#include "./db/database.h"
#include "./db/dialogwindow.h"


namespace Ui {
class Form_tabview;
}

class Form_tabview : public QWidget
{
    Q_OBJECT

public:
    explicit Form_tabview(QString user,QString pwd, QString host, QString db_name, QWidget *parent = 0);
    ~Form_tabview();


public:
   DataBase   *db;                    //  объект нашего класса для бд
   QTableView *tableView;         //  обычный вид  QTableView
   QSqlTableModel  *model;      //   модель  QSqlTableModel
   DialogWindow dialog;
   bool forEdit = false;

   QString user,pwd,host,db_name;

   void setupSQLTableModel(QString tableName,   QStringList headers);        //  методы настройки  SQLTableModel   и  TableView
   void setupTableView();

   void insertRow(QString table);              //  методы добавления и изменения строк в БД
   void updateRow(QString table, QList<QString> columns);

private slots:
   QString table;
   void deleteRowSlot(int index);
   void onEditButtonClickedSlot();
   void onAddButtonClickedSlot();
   void onSaveButtonClickedSlot();




private:
    Ui::Form_tabview *ui;
};

#endif // FORM_TABVIEW_H
