#ifndef FORM_DATAENTRY_SETTINGS_H
#define FORM_DATAENTRY_SETTINGS_H


#include <QWidget>
#include <QStandardItemModel>

#include <QStandardItemModel>
#include <QMenu>
#include <QAction>
#include <QPrinter>
#include <QPrintPreviewDialog>

#include "zf_itemview/zf_table_view.h"
#include "zf_itemview/zf_tree_view.h"

#include "Src/pbs/pbsfileutil.h"
#include "Src/pbs/pbstools.h"
#include "Src/pbsmodelexporter.h"
#include "src/pbstableprinter.h"


#include "dataanimals.h"
#include "Debug/logger.h"


namespace Ui {
class Form_DataEntry_Settings;
}

//1. Навигатор: Ввод данных 2. Меню: Настройки

class Form_DataEntry_Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Form_DataEntry_Settings(QWidget *parent = nullptr);
    ~Form_DataEntry_Settings();

private slots:
    void on_pushButton_clicked();
    void sectionClicked(int idx);

private:
    Ui::Form_DataEntry_Settings *ui;
    void create_feeding___feed_tables();
    void create_feeding___access_milk();


    void create_after_milking();
    void configureHeader2_tree_after_milking(zf::HeaderItem *parent);
    QStandardItemModel _tree_model_after_milking;
    zf::TreeView* _tree_view_after_milking = nullptr;

    const int tree_COL_after_milking_COUNT = 12;
    const int tree_ROW_after_milking_COUNT = 22;


    void create_tree_view();
    void configureHeader2_tree(zf::HeaderItem *parent);
    QStandardItemModel _tree_model;
    zf::TreeView* _tree_view = nullptr;
    const int tree_COL_COUNT = 18;
    const int tree_ROW_COUNT = 3;

    void addRandom__milking__general_milking();
    void GetData__milking__general_milking();

    void addRandom__milking__post_milking();
    void GetData__milking__post_milking();

    void GetData__During_milking();


    void create_table_view();
    void configureHeader2(zf::HeaderItem *parent);
    QStandardItemModel _table_model;
    zf::TableView *_table_view = nullptr;

    //const int COL_COUNT = 10*3;
    const int COL_COUNT = 17;
    const int ROW_COUNT = 1;


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



signals:
    void onCreatePopupMenu(MenuTypes, QMenu *);

public slots:
    //void onActSaveExcel();
    void onCreateFooterMenu(QMenu *m);
    void showCustomContextMenu(const QPoint &p);
    void print(QPrinter *);


};

#endif // FORM_DATAENTRY_SETTINGS_H
