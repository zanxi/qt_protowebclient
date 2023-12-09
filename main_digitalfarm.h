#ifndef Main_pro_lely_H
#define Main_pro_lely_H

#include <QMainWindow>
#include "widget_form.h"
#include "widget_menu.h"

#include "AdminPanel/adminwidget.h"
#include "./Autorization/autorizationdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Main_DigitalFarm : public QMainWindow
{
    Q_OBJECT

public:
    Main_DigitalFarm(QWidget *parent = nullptr);
    ~Main_DigitalFarm();


signals:
void signal(QString);

public slots:
void slotMenu(QString);
void InitDBautorization();


private slots:
void on_action_triggered();

private:
    Ui::MainWindow *ui;

    Widget_Form *w_f;
    Widget_menu *w_m;

    AdminWidget *admin2;
    //AutorizationDialog *autorization;

    void create();
    void SaveAutorizartion();
    void GetLastId();
    void GetUserId();

    QHash<QString, QWidget*> CollectionAction;

};
#endif // Main_pro_lely_H
