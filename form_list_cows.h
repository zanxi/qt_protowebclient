#ifndef FORM_LIST_COWS_H
#define FORM_LIST_COWS_H

#include <QStandardItemModel>
#include <QMenu>
#include <QAction>
#include <QPrinter>

#include <QWidget>

#include "dataanimals.h"

namespace Ui {
class Form_List_Cows;
}

class Form_List_Cows : public QWidget
{
    Q_OBJECT

public:
    explicit Form_List_Cows(QWidget *parent = nullptr);    
    ~Form_List_Cows();

    void ThisStyle(QString color_h);


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


public slots:
    //void onActSaveExcel();
    void onCreateFooterMenu(QMenu *m);
    void showCustomContextMenu(const QPoint &p);
    void print(QPrinter *);


};

#endif // FORM_LIST_COWS_H
