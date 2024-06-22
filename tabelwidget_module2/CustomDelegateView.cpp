#include "CustomDelegateView.h"
#include <QApplication>

#include "dataanimals.h"

CustomDelegateView::CustomDelegateView(QObject *parent) :
    QItemDelegate(parent)
{

}

void CustomDelegateView::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QItemDelegate::paint(painter, option, index);
    if(index.column() == 3) {
        QStyleOptionButton button;
        button.rect = QRect(option.rect.left()+1, option.rect.top()+1, option.rect.width() - 2, option.rect.height() - 2);
        button.features = QStyleOptionButton::None;
        button.text = "Удaлить точку";
        button.state = QStyle::State_Enabled;

        //button.rect = _option.rect;
        button.text.clear();
        button.icon = QIcon(DataSystems::Instance().icons[icons_i::edit_i]);
        //button.state = _option.state | QStyle::State_Enabled;

        //if (index == button) button.state |= QStyle::State_Sunken;

        //QApplication::style()->drawControl(QStyle::CE_PushButton, &button, _painter);

        QApplication::style()->drawControl(QStyle::CE_PushButtonLabel, &button, painter);
    }

}

bool CustomDelegateView::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if(event->type() == QEvent::MouseButtonRelease && index.column() == 3) {
        emit signalClicked(index);
    }
    else
        QItemDelegate::editorEvent(event, model, option,index);
    return true;
}
