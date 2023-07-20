#ifndef FORM_1_2_GENERAL_H
#define FORM_1_2_GENERAL_H

#include <QWidget>

namespace Ui {
class Form_1_2_General;
}

class Form_1_2_General : public QWidget
{
    Q_OBJECT

public:
    explicit Form_1_2_General(QWidget *parent = 0);
    ~Form_1_2_General();

private:
    Ui::Form_1_2_General *ui;
};

#endif // FORM_1_2_GENERAL_H
