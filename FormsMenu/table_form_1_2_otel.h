#ifndef TABLE_FORM_1_2_OTEL_H
#define TABLE_FORM_1_2_OTEL_H

#include <QWidget>
#include <QTableWidget>
#include <QSqlQuery>
#include <QTimer>

namespace Ui {
class table_form_1_2_otel;
}

class table_form_1_2_otel : public QWidget
{
    Q_OBJECT

public:
    explicit table_form_1_2_otel(QWidget *parent = nullptr);
    ~table_form_1_2_otel();

    bool checkStatus(){ return status; }  // сохранены true; не сохранены - false

private slots:
    void on_comboBox_activated(int index);
    void on_pushButton_add_cow_clicked();
    void on_pushButton_select_cow_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_addRandom_clicked();
    void GetData();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::table_form_1_2_otel *ui;
    int selectRow=-1;
    int selectRowOld=-1;
    QString checkAnimals;
    QString searchText="";

    QTimer *mTimer;

    void GetData_search(const QString &str);
    void tabwidget_insert_add_column(QSqlQuery *quer, QTableWidget *tab, const QString &nameColumn,  int numRow,  int num);
    void GetData(const QString &str);
    void addRandom();

    bool status = false; // не сохранять данные - false; сохранить - true


};

#endif // TABLE_FORM_1_2_OTEL_H
