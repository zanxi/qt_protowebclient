#ifndef FORM_1_9_INSEMENATION_H
#define FORM_1_9_INSEMENATION_H

#include <QDialog>

namespace Ui {
class Form_1_9_insemenation;
}

// 1. Навигатор: Ввод данных 2. Меню: Дневная запись           3. Подменю: Осеменение

class Form_1_9_insemenation : public QDialog
{
    Q_OBJECT

public:
    explicit Form_1_9_insemenation(QWidget *parent = nullptr);
    explicit Form_1_9_insemenation(const QString &checkAnimals, QWidget *parent = nullptr);
    ~Form_1_9_insemenation();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Form_1_9_insemenation *ui;
    void create();

    bool check_insert_or_update = false; // вставить - false; обновить - true
    void SetData();
    bool status = true;
};

#endif // FORM_1_9_INSEMENATION_H
