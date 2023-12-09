#ifndef FORM_DATAENTRY_ROUTING_6_6_1_ADD_DIALOG_H
#define FORM_DATAENTRY_ROUTING_6_6_1_ADD_DIALOG_H

#include <QDialog>

namespace Ui {
class form_dataentry_routing_6_6_1_add_Dialog;
}

class form_dataentry_routing_6_6_1_add_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit form_dataentry_routing_6_6_1_add_Dialog(QWidget *parent = nullptr);
    explicit form_dataentry_routing_6_6_1_add_Dialog(QString checkAnimals, QWidget *parent = nullptr);
    ~form_dataentry_routing_6_6_1_add_Dialog();

private:
    Ui::form_dataentry_routing_6_6_1_add_Dialog *ui;
};

#endif // FORM_DATAENTRY_ROUTING_6_6_1_ADD_DIALOG_H
