#ifndef TABLE_FORM_1_2_BATCH_TRANSFER_H
#define TABLE_FORM_1_2_BATCH_TRANSFER_H


#include <QButtonGroup>
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

private slots:
    void operatingModeButtonsToggled(int, bool);
    void operatingModeButtonsClicked(int);


    void on_comboBox_2_activated(int index);

    void on_comboBox_activated(int index);

    void on_comboBox_3_activated(int index);

    void on_pushButton_clicked();



private:
    Ui::Table_Form_1_2_batch_transfer *ui;

    QButtonGroup *operatingModeGroup;
    typedef enum {
        OM_Start,
        OM_Transfer
    }operatingModeTypes;
};

#endif // TABLE_FORM_1_2_BATCH_TRANSFER_H
