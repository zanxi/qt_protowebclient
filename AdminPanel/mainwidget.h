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
#include <QLabel>
//#include "stumanager.h"


#include "modelbuilder.h"

namespace Ui
{
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = 0);
    ~mainWidget();

public:
signals:
    void signalMenu(QString a);

public slots:
    void slotMenu(QString);



private slots:
    void addBtnClicked();
    void updateBtnClicked();
    void deleteBtnClicked();
    void setCurTabIndex();
    void getSearchText();

    void selectTreeItem(const QItemSelection &selected, const QItemSelection &deselected);

private:
    Ui::mainWidget *ui;
    QString str;
    int tabNum;

    QLineEdit *searchEdit;
//    QPushButton *refreshBtn;
    QLabel *qLabel;
    QPushButton *addBtn;
    QPushButton *updateBtn;
    QPushButton *deleteBtn;
    stuManager *m_pStuManager;

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
