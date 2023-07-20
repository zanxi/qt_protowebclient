#ifndef WIDGET_MENU_H
#define WIDGET_MENU_H

#include <QWidget>
#include "modelbuilder.h"

namespace Ui {
class Widget_menu;
}

class Widget_menu : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_menu(QWidget *parent = nullptr);
    ~Widget_menu();

public slots:
    void selectTreeItem(const QItemSelection&, const QItemSelection&);
    void slot(QString a);

signals:
    void signalMenu(QString a);


private:
    Ui::Widget_menu *ui;
      const QString file_path = ":/menu/menu.xml";
    //const QString file_path = "qrc:/resources/menu/menu.xml";
    //const QString file_path = "./menu.xml";
    ModelBuilder *model_builder;
    bool stop_selection = false;
    QHash<QString, QWidget*> CollectionAction;
};

#endif // WIDGET_MENU_H
