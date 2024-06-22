#ifndef TABLE_FORM_2_1_H
#define TABLE_FORM_2_1_H

#include <QWidget>

namespace Ui {
class Table_Form_2_1;
}

class Table_Form_2_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Table_Form_2_1(QWidget *parent = nullptr);
    ~Table_Form_2_1();
    void createButton();

private:
    Ui::Table_Form_2_1 *ui;
};

#endif // TABLE_FORM_2_1_H
