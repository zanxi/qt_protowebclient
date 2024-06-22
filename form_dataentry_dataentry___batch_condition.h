#ifndef FORM_DATAENTRY_DATAENTRY___BATCH_CONDITION_H
#define FORM_DATAENTRY_DATAENTRY___BATCH_CONDITION_H

#include <QWidget>

namespace Ui {
class form_dataentry_dataentry___batch_condition;
}

class form_dataentry_dataentry___batch_condition : public QWidget
{
    Q_OBJECT

public:
    explicit form_dataentry_dataentry___batch_condition(QWidget *parent = nullptr);
    ~form_dataentry_dataentry___batch_condition();

private:
    Ui::form_dataentry_dataentry___batch_condition *ui;
    void GetData();
};

#endif // FORM_DATAENTRY_DATAENTRY___BATCH_CONDITION_H
