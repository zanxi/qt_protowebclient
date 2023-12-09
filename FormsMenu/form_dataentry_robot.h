#ifndef FORM_DATAENTRY_ROBOT_H
#define FORM_DATAENTRY_ROBOT_H

#include <QWidget>
#include <QDialog>
#include <QTableWidget>
#include <QSqlQuery>
#include <QTimer>

namespace Ui {
class form_dataentry_Robot;
}

class form_dataentry_Robot :  public QWidget
{
    Q_OBJECT

public:
    explicit form_dataentry_Robot(QWidget *parent = nullptr);
    ~form_dataentry_Robot();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_select_clicked();

    void on_pushButton_delete_clicked();

    void on_comboBox_id_activated(int index);

    void GetData();

    void on_comboBox_id_textActivated(const QString &arg1);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_comboBox_id_editTextChanged(const QString &arg1);

    void on_pushButton_view_param_clicked();

private:
    Ui::form_dataentry_Robot *ui;

    int selectRow=-1;
    int selectRowOld=-1;

    QString searchText="";
    QString checkId="";
    QTimer *mTimer;

    void tabwidget_insert_add_column(QSqlQuery *query, QTableWidget *tab, QString nameColumn, int numRow, int numColumn);
    void GetData(QString str);
    void GetData_search(QString str);
    void GetData_search2(QString str);
    void addRandom();

};

#endif // FORM_DATAENTRY_ROBOT_H
