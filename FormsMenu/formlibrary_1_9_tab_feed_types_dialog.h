#ifndef FORMLIBRARY_1_9_TAB_FEED_TYPES_DIALOG_H
#define FORMLIBRARY_1_9_TAB_FEED_TYPES_DIALOG_H

#include <QDialog>

namespace Ui {
class formlibrary_1_9_tab_feed_types_dialog;
}

// диалог ввода
// 1. Навигатор: Ввод данных     2. Меню: Библиотеки               3. Подменю: Типы корма

class formlibrary_1_9_tab_feed_types_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit formlibrary_1_9_tab_feed_types_dialog(QWidget *parent = nullptr);
    ~formlibrary_1_9_tab_feed_types_dialog();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_feed_types_close_clicked();

    void on_pushButton_feed_types_save_clicked();

private:
    Ui::formlibrary_1_9_tab_feed_types_dialog *ui;
};

#endif // FORMLIBRARY_1_9_TAB_FEED_TYPES_DIALOG_H
