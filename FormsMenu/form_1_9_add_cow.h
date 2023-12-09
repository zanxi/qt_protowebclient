#ifndef FORM_1_9_ADD_COW_H
#define FORM_1_9_ADD_COW_H

#include <QWidget>
#include <QDialog>
#include <QButtonGroup>

// 1. Навигатор: Ввод данных  2. Меню: Дневная запись      3. Подменю: Карты коров

namespace Ui {
class Form_1_9_add_cow;
}

class Form_1_9_add_cow : public QDialog
{
    Q_OBJECT

public:
    explicit Form_1_9_add_cow(QWidget *parent = nullptr);
    ~Form_1_9_add_cow();

private slots:
    void operatingModeButtonsToggled_YN(int, bool);
    void operatingModeButtonsClicked_YN(int);
    void operatingModeButtonsToggled_MW(int, bool);
    void operatingModeButtonsClicked_MW(int);
    void operatingModeButtonsToggled_Local(int, bool);
    void operatingModeButtonsClicked_Local(int);

    void on_pushButton_save_clicked();

private:
    Ui::Form_1_9_add_cow *ui;



    QButtonGroup *operatingModeGroup_YN;
    typedef enum {
        AC_YES,
        AC_NO
    }operatingModeTypes_YN;

    QButtonGroup *operatingModeGroup_MW;
    typedef enum {
        AC_M,
        AC_W
    }operatingModeTypes_MW;

    QButtonGroup *operatingModeGroup_use_as_sire;
    typedef enum {
        AC_use,
        AC_unuse
    }operatingModeTypes_use_as_sire;

    QButtonGroup *operatingModeGroup_Local;
    typedef enum {
        AC_1,
        AC_2,
        AC_3
    }operatingModeTypes_Local;
};

#endif // FORM_1_9_ADD_COW_H
