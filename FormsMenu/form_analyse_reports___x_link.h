#ifndef FORM_ANALYSE_REPORTS___X_LINK_H
#define FORM_ANALYSE_REPORTS___X_LINK_H

#include <QWidget>
#include <QStandardItemModel>

#include <QStandardItemModel>
#include <QMenu>
#include <QAction>
#include <QPrinter>
#include <QPrintPreviewDialog>

#include "zf_itemview/zf_table_view.h"


#include "Src/pbs/pbsfileutil.h"
#include "Src/pbs/pbstools.h"
#include "Src/pbsmodelexporter.h"
#include "src/pbstableprinter.h"


#include "dataanimals.h"
#include "Debug/logger.h"

namespace Ui {
class form_analyse_reports___X_Link;
}

class form_analyse_reports___X_Link : public QWidget
{
    Q_OBJECT

public:
    explicit form_analyse_reports___X_Link(QWidget *parent = nullptr);
    ~form_analyse_reports___X_Link();

    void create_table_view();

private:
    Ui::form_analyse_reports___X_Link *ui;

    QStandardItemModel _table_model;
    zf::TableView *_table_view = nullptr;

    //const int COL_COUNT = 10*3;
    const int COL_COUNT = 17;
    const int ROW_COUNT = 1;


    void configureHeader2(zf::HeaderItem *parent);
    void ThisStyle(QString color_h);

    void GetData();

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

#endif // FORM_ANALYSE_REPORTS___X_LINK_H
