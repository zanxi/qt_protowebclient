#ifndef FORM_Z_1_H
#define FORM_Z_1_H

#include <QWidget>

namespace Ui {
class Form_Z_1;
}

class Form_Z_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form_Z_1(QWidget *parent = nullptr);
    ~Form_Z_1();

private:
    Ui::Form_Z_1 *ui;
};

#endif // FORM_Z_1_H
