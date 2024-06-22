#include "customdelegate.h"

#include <QApplication>
#include "dataanimals.h"

#include "Debug/logger.h"

CustomDelegate::CustomDelegate(QObject *parent):QItemDelegate(parent)
{

}

CustomDelegate::CustomDelegate(int _actionColumn, QObject *parent):QItemDelegate(parent)
{
    actionColumn = _actionColumn;
}


void CustomDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QItemDelegate::paint(painter, option, index);

    if(index.column() == 12)
    {
        QStyleOptionButton button;
//        /this->initStyleOption(&button);


        //button.sty;
        button.rect = QRect(
            option.rect.left()+1,
            option.rect.top()+1,
            option.rect.width()-2,
            option.rect.height()-2
            );

        //button->setBackgroundRole(QPalette::Base);
        //button->setAutoFillBackground(true);

        //button.features = QStyleOptionButton::ic;
        //button.text = "delete pixel";
        //button.state = QStyle::State_Enabled;

        //button->setAttribute(Qt::WA_TransparentForMouseEvents, true);

        button.iconSize=QSize(15,15);
        //button.icon = QIcon(":/icons/res/edit__.png");
        //button.icon = QIcon::fromTheme("dialog-information", QIcon(":/icons/res/edit__.png"));
        //button.icon = QIcon::fromTheme("dialog-information", QIcon(":/icons/res/graphic__.png"));
        //button.icon = QIcon::fromTheme("dialog-information", QIcon(":/icons/res/delete__.png"));

        QPixmap pix = QPixmap(DataSystems::Instance().icons[icons_i::edit2_i]);
        //logger::WriteMsg("icons: "+ DataSystems::Instance().icons[icons_i::edit2_i].toStdString());

        //QPixmap::fromImage(":/icons/res/delete__.png");
        //button.icon = QIcon::fromTheme("dialog-information", QIcon(":/icons/res/delete__.png"));
        button.icon.addPixmap(pix,QIcon::Normal);

        //QApplication::style()->drawControl(QStyle::CE_PushButtonLabel, &button, painter);
        QApplication::style()->drawControl(QStyle::CE_PushButtonLabel, &button, painter);
    }

}


bool CustomDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if(event->type() == QEvent::MouseButtonRelease && index.column() == actionColumn)
    {
        emit signalClicked(index);
    }
    else{
        QItemDelegate::editorEvent(event, model, option, index);
    }
    return true;
}
