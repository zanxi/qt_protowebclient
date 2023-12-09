#ifndef FORMLIBRARY_1_9_H
#define FORMLIBRARY_1_9_H

#include <QWidget>

namespace Ui {
class FormLibrary_1_9;
}

// 1. Навигатор: Ввод данных 2. Меню: Библиотеки

class FormLibrary_1_9 : public QWidget
{
    Q_OBJECT

public:
    explicit FormLibrary_1_9(QWidget *parent = nullptr);
    ~FormLibrary_1_9();

private slots:
    void on_pushButton_tab_series_add_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormLibrary_1_9 *ui;
    void create_series();
    void create_feed_types();
};

#endif // FORMLIBRARY_1_9_H
