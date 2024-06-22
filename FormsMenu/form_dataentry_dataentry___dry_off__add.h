#ifndef FORM_DATAENTRY_DATAENTRY___DRY_OFF__ADD_H
#define FORM_DATAENTRY_DATAENTRY___DRY_OFF__ADD_H

#include <QDialog>

namespace Ui {
class form_dataentry_dataentry___dry_off__add;
}

class form_dataentry_dataentry___dry_off__add : public QDialog
{
    Q_OBJECT

public:
    explicit form_dataentry_dataentry___dry_off__add(QWidget *parent = nullptr);
    explicit form_dataentry_dataentry___dry_off__add(const QString &checkAnimals, QWidget *parent = nullptr);
    ~form_dataentry_dataentry___dry_off__add();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::form_dataentry_dataentry___dry_off__add *ui;
    void create();

    bool check_insert_or_update = false; // вставить - false; обновить - true
    void SetData();
    bool status = true;
};

#endif // FORM_DATAENTRY_DATAENTRY___DRY_OFF__ADD_H
