#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include <QItemDelegate>

class CustomDelegate : public QItemDelegate
{
    Q_OBJECT
signals:
    QModelIndex signalClicked(QModelIndex index);
public:
    CustomDelegate(QObject *parent = 0);
    CustomDelegate(int _actionColumn, QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
    void setActionColumn(int _actionColumn){ actionColumn = _actionColumn; }
    int getActionColumn(){ return actionColumn; }

    int actionColumn=-1;
};

#endif // CUSTOMDELEGATE_H
