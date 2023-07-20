#ifndef FORM_1_1_H
#define FORM_1_1_H

#include <QWidget>

namespace Ui {
class Form_1_1;
}

class Form_1_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form_1_1(QWidget *parent = 0);
    ~Form_1_1();

private:
    Ui::Form_1_1 *ui;
};

#endif // FORM_1_1_H
