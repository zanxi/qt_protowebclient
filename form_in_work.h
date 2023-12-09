#ifndef FORM_IN_WORK_H
#define FORM_IN_WORK_H

#include <QWidget>

namespace Ui {
class Form_in_work;
}

class Form_in_work : public QWidget
{
    Q_OBJECT

public:
    explicit Form_in_work(QWidget *parent = nullptr);
    explicit Form_in_work(QByteArray ba, QWidget *parent = nullptr);
    ~Form_in_work();

private:
    Ui::Form_in_work *ui;
};

#endif // FORM_IN_WORK_H
