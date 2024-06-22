// xlsx

#include <QtGlobal>
#include <QObject>
#include <QString>
#include <QVector>
#include <QList>

#include "src/xlsx/header/xlsxglobal.h"
#include "src/xlsx/header/xlsxcell.h"
#include "src/xlsx/header/xlsxcelllocation.h"

QT_BEGIN_NAMESPACE_XLSX

CellLocation::CellLocation()
{
    col = -1;
    row = -1;

    cell.clear();
}

QT_END_NAMESPACE_XLSX
