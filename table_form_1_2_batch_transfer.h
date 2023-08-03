#ifndef TABLE_FORM_1_2_BATCH_TRANSFER_H
#define TABLE_FORM_1_2_BATCH_TRANSFER_H

#include <QWidget>

namespace Ui {
class Table_Form_1_2_batch_transfer;
}

class Table_Form_1_2_batch_transfer : public QWidget
{
    Q_OBJECT

public:
    explicit Table_Form_1_2_batch_transfer(QWidget *parent = nullptr);
    ~Table_Form_1_2_batch_transfer();

private:
    Ui::Table_Form_1_2_batch_transfer *ui;
};

#endif // TABLE_FORM_1_2_BATCH_TRANSFER_H
