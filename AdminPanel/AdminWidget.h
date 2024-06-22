#ifndef mainWidget_H
#define mainWidget_H

#include <QWidget>
//#include <QSql>
#include <QDebug>
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QString>
#include "DbManager.h"
//#include "teamanager.h"

#include "modelbuilder.h"

namespace Ui
{
class mainWidget;
}

class AdminWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWidget(QWidget *parent = 0);
    ~AdminWidget();

public:
signals:
    void signalMenu(QString a);

public slots:
    void slotMenu(QString);



private slots:
    void addBtnClicked();
    void updateBtnClicked();
    void deleteBtnClicked_row();
    void deleteBtnClicked_allrow();
    void setCurTabIndex();
    void getSearchText();

    void selectTreeItem(const QItemSelection &selected, const QItemSelection &deselected);

    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::mainWidget *ui;
    QString str;
    int tabNum;

    QLineEdit *searchEdit;
//    QPushButton *refreshBtn;
    QPushButton *addBtn;
    QPushButton *updateBtn;
    QPushButton *deleteBtn_allrow;
    QPushButton *deleteBtn_row;
    DbManager *m_pDbManager;
    //teaManager *m_pTeaManager;
    void initUI(QString nameTab= "RFeedSettings");
    void refresh();

    ModelBuilder *model_builder;
    //const QString file_path = "./db.xml";
    //const QString file_path = "D:/_2023_/_Src__94__/sqlwidget2/db.xml";
    const QString file_path = "./db.xml";

    //"D:/_2023_/_Src__94__/sqlwidget2/styles/"

    void creatCornerBtn();

//    void connectDb();
//    void createTables();

protected:
    QSqlDatabase database;
};

#endif // mainWidget_H
