#ifndef WIDGET_FORM_H
#define WIDGET_FORM_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>

namespace Ui {
class Widget_Form;
}

class Widget_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Form(QWidget *parent = nullptr);
    ~Widget_Form();

    void populatedDataItem();

public slots:
    void addnew();
    void remove();
    void save();


private:
    Ui::Widget_Form *ui;
    QSqlTableModel *model;
    QSqlDatabase db;

    bool initDatabase();
    void closeDatabase();


};

#endif // WIDGET_FORM_H
