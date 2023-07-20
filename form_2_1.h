#ifndef FORM_2_1_H
#define FORM_2_1_H

#include <QWidget>

namespace Ui {
class Form_2_1;
}

class Form_2_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form_2_1(QWidget *parent = nullptr);
    ~Form_2_1();

private:
    Ui::Form_2_1 *ui;
};

#endif // FORM_2_1_H
