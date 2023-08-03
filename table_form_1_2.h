#ifndef TABLE_FORM_1_2_H
#define TABLE_FORM_1_2_H

#include <QWidget>

namespace Ui {
class Table_Form_1_2;
}

class Table_Form_1_2 : public QWidget
{
    Q_OBJECT

public:
    explicit Table_Form_1_2(QWidget *parent = nullptr);
    ~Table_Form_1_2();

private:
    Ui::Table_Form_1_2 *ui;
};

#endif // TABLE_FORM_1_2_H
