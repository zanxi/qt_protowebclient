#ifndef CHECKBOXITEMDELEGATE_H
#define CHECKBOXITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QCheckBox>

class CheckBoxItemDelegate: public QStyledItemDelegate
    {
        Q_OBJECT
        public:
        explicit CheckBoxItemDelegate(QObject *parent = nullptr);

        QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
        void setEditorData(QWidget *editor, const QModelIndex &index) const override;
        void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    };

#endif // CHECKBOXITEMDELEGATE_H
