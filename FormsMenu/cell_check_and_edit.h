#ifndef CELL_CHECK_AND_EDIT_H
#define CELL_CHECK_AND_EDIT_H

#include <QWidget>

namespace Ui {
class cell_check_and_edit;
}

class cell_check_and_edit : public QWidget
{
    Q_OBJECT

public:
    explicit cell_check_and_edit(QWidget *parent = nullptr);
    ~cell_check_and_edit();

private:
    Ui::cell_check_and_edit *ui;
};

#endif // CELL_CHECK_AND_EDIT_H
