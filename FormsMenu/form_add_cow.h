#ifndef FORM_ADD_COW_H
#define FORM_ADD_COW_H

#include <QWidget>
#include <QButtonGroup>
#include <QDialog>

namespace Ui {
class Form_add_cow;
}

class Form_add_cow : public QDialog
{
    Q_OBJECT

public:
    explicit Form_add_cow(QWidget *parent = nullptr);
    explicit Form_add_cow(const QString &data, QWidget *parent = nullptr);
    ~Form_add_cow();

    void SetData();
    bool checkStatus(){ return status; }  // сохранены true; не сохранены - false

private slots:
    void operatingModeButtonsToggled_YN(int, bool);
    void operatingModeButtonsClicked_YN(int);
    void operatingModeButtonsToggled_MW(int, bool);
    void operatingModeButtonsClicked_MW(int);
    void operatingModeButtonsToggled_Local(int, bool);
    void operatingModeButtonsClicked_Local(int);

    void on_pushButton_save_clicked();

    void on_pushButton_close_clicked();

private:

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


private:
    Ui::Form_add_cow *ui;

    bool status = false; // не сохранять данные - false; сохранить - true
    bool check_insert_or_update = false; // вставить - false; обновить - true

};

#endif // FORM_ADD_COW_H
