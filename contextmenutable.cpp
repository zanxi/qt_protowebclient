#include "contextmenutable.h"

ContextMenuTable::ContextMenuTable(QWidget *parent):
    QWidget(parent)
    , actSaveExcel(QIcon(":/Resource/Images/xls.png"), PBSTR("Excel "), this)
    , actSaveExcelXML(QIcon(":/Resource/Images/xls.png"), PBSTR("Excel (XML)"), this)
    , actSaveWordXML(QIcon(":/Resource/Images/word.png"), PBSTR("Word (XML)"), this)
    , actSavePDF(QIcon(":/Resource/Images/pdf.png"), PBSTR("PDF "), this)
    , actSaveCSV(QIcon(":/Resource/Images/csv.png"), PBSTR("Text (CSV)"), this)
    , actSaveXML(QIcon(":/Resource/Images/xml.png"), PBSTR("XML "), this)
    , actSaveHTML(QIcon(":/Resource/Images/htm.png"), PBSTR("HTML "), this)
    , actFilter(QIcon(":/Resource/Images/filter.png"), PBSTR("HTML "), this)

{

}
