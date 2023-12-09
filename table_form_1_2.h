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

    QString tab;

private slots:
    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::Table_Form_1_2 *ui;

    int selectRow=-1;
    int selectRowOld=-1;

};

#endif // TABLE_FORM_1_2_H
