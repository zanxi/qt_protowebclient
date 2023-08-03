#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widget_form.h"
#include "widget_menu.h"

#include "AdminPanel/adminwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
void signal(QString);

public slots:
void slotMenu(QString);


private slots:
void on_action_triggered();

private:
    Ui::MainWindow *ui;

    Widget_Form *w_f;
    Widget_menu *w_m;

    AdminWidget *admin2;

    QHash<QString, QWidget*> CollectionAction;
};
#endif // MAINWINDOW_H
