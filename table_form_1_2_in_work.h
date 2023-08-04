#ifndef TABLE_FORM_1_2_IN_WORK_H
#define TABLE_FORM_1_2_IN_WORK_H

#include <QWidget>

namespace Ui {
class table_form_1_2_in_work;
}

class table_form_1_2_in_work : public QWidget
{
    Q_OBJECT

public:
    explicit table_form_1_2_in_work(QWidget *parent = nullptr);
    ~table_form_1_2_in_work();

private:
    Ui::table_form_1_2_in_work *ui;
};

#endif // TABLE_FORM_1_2_IN_WORK_H
