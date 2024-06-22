#ifndef FORM_DATAENTRY_ROBOT_H
#define FORM_DATAENTRY_ROBOT_H

#include <QStandardItemModel>
#include <QMenu>
#include <QAction>
#include <QPrinter>


#include <QWidget>
#include <QDialog>
#include <QTableWidget>
#include <QSqlQuery>
#include <QTimer>
#include <QFile>

#include "utils/extendqtablewidget.h"

#include "db/asyncsql/asyncsqltablemodel.h"
#include "db/asyncsql/databaseconnection.h"
#include "db/asyncsql/asyncsqltablemodel.h"

#include "dataanimals.h"

namespace Ui {
class form_dataentry_Robot;
}

class form_dataentry_Robot :  public QWidget
{
    Q_OBJECT

public:
    explicit form_dataentry_Robot(QWidget *parent = nullptr);
    ~form_dataentry_Robot();

    void PhotoView_Dialog();
    void GetDataImage(QString id);
    void OutputLog(QString f);

public slots:
    //void onActSaveExcel();
    void onCreateFooterMenu(QMenu *m);
    void showCustomContextMenu(const QPoint &p);
    void print(QPrinter *);


private slots:

    void onBtnClicked(QModelIndex index);

    void on_tableWidget_cellEntered2(int row, int column);
    void on_pushButton_add_clicked();

    void on_pushButton_select_clicked();

    void on_pushButton_delete_clicked();

    void on_comboBox_id_activated(int index);

    void GetData();

    void on_comboBox_id_textActivated(const QString &arg1);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_comboBox_id_editTextChanged(const QString &arg1);

    void on_pushButton_view_param_clicked();

    void createButton();

private:
    Ui::form_dataentry_Robot *ui;

    int selectRow=-1;
    int selectRowOld=-1;

    QString searchText="";
    QString checkId="";
    QTimer *mTimer;

    void tabwidget_insert_add_column(QSqlQuery *query, QTableWidget *tab, const QString &nameColumn, int numRow, int numColumn);
    void GetData(const QString &str);
    void GetData_search(const QString &str);    
    void addRandom();

    QFile *newFile;
    QString fileName;  //имя файла
    //ExtendQTableWidget *tableWidget;

    AsyncSql::AsyncSqlTableModel *model;
    QString TableName;

    QMenu popupMenu;
    QAction actFooter,
        actFilter,
        actSortAsc,
        actSortDesc,
        actStretchColumn,
        actStretchColumnAll,
        actStretch,
        actSaveLayout,
        actSaveExcel,
        actSaveExcelXML,
        actSaveWordXML,
        actSaveXML,
        actSavePDF,
        actSaveCSV,
        actSaveHTML,
        actSendToPrinter;

    void createPopupMenu_();

    void onActSaveExcel();
    void onActSaveExcelXML();
    void onActSaveWordXML();
    void onActSaveXML();
    void onActSavePDF();
    void onActSaveCSV();
    void onActSaveHTML();
    void onActSendToPrinter();

    void create_table_view();

signals:
    void onCreatePopupMenu(MenuTypes, QMenu *);



};

#endif // FORM_DATAENTRY_ROBOT_H
