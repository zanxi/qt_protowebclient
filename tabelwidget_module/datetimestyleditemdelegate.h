#ifndef DATETIMESTYLEDITEMDELEGATE_H
#define DATETIMESTYLEDITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QDateTime>

class DateTimeStyledItemDelegate: public QStyledItemDelegate {
    Q_OBJECT
public:
    DateTimeStyledItemDelegate(QObject * parent = 0):
        QStyledItemDelegate(parent)
    { }
    // ^^^ I have given the delegate class a constructor to ensure object ownership is captured.

    QString displayText(const QVariant &value, const QLocale &locale) const {
        if (value.type() == QVariant::Date) {
            return value.toDate().toString("...");
        }
        return QStyledItemDelegate::displayText(value, locale);
    }
};

#endif // DATETIMESTYLEDITEMDELEGATE_H
