#ifndef CONTEXTMENUTABLE_H
#define CONTEXTMENUTABLE_H


#include <QWidget>
#include <QStandardItemModel>

#include <QStandardItemModel>
#include <QMenu>
#include <QAction>
#include <QPrinter>
#include <QPrintPreviewDialog>

#include "Src/pbs/pbsfileutil.h"
#include "Src/pbs/pbstools.h"
#include "Src/pbsmodelexporter.h"
#include "src/pbstableprinter.h"

#include "dataanimals.h"
#include "Debug/logger.h"

class ContextMenuTable : public QWidget
{
public:
   explicit ContextMenuTable(QWidget *parent = nullptr);

protected:
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

    virtual void createPopupMenu_()=0;

    virtual void onActSaveExcel()=0;
    virtual void onActSaveExcelXML()=0;
    virtual void onActSaveWordXML()=0;
    virtual void onActSaveXML()=0;
    virtual void onActSavePDF()=0;
    virtual void onActSaveCSV()=0;
    virtual void onActSaveHTML()=0;
    virtual void onActSendToPrinter()=0;



protected:
  signals:
    void onCreatePopupMenu(MenuTypes, QMenu *);

public slots:
    //void onActSaveExcel();
   virtual void onCreateFooterMenu(QMenu *m)=0;
   virtual void showCustomContextMenu(const QPoint &p)=0;
   virtual void print(QPrinter *)=0;



};

#endif // CONTEXTMENUTABLE_H
