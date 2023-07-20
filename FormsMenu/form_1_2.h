#ifndef FORM_1_2_H
#define FORM_1_2_H

#include <QWidget>

namespace Ui {
class Form_1_2;
}

class Form_1_2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form_1_2(QWidget *parent = 0);
    ~Form_1_2();

private:
    Ui::Form_1_2 *ui;
};

#endif // FORM_1_2_H
