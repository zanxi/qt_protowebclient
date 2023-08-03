#include "checkboxitemdelegate.h"

CheckBoxItemDelegate::CheckBoxItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *CheckBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Create the combobox and populate it
    auto checkbox = new QCheckBox(parent);
    checkbox->setCheckState(Qt::CheckState::Unchecked);
    return checkbox;
}


void CheckBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    auto checkbox = qobject_cast<QCheckBox *>(editor);
    Q_ASSERT(checkbox);

    const bool currentValue = index.data(Qt::EditRole).toBool();
    //const int cbIndex = checkbox->findText(currentText);
    checkbox->setCheckState((currentValue)?(Qt::CheckState::Checked):(Qt::CheckState::Unchecked));
}


void CheckBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QCheckBox *checkbox = qobject_cast<QCheckBox *>(editor);
    Q_ASSERT(checkbox);
    model->setData(index, QString(checkbox->checkState()), Qt::EditRole);
}
