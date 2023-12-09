#ifndef FORMLIBRARY_1_9_TAB_SERIES_DIALOG_H
#define FORMLIBRARY_1_9_TAB_SERIES_DIALOG_H

#include <QDialog>

namespace Ui {
class formlibrary_1_9_tab_series_Dialog;
}

class formlibrary_1_9_tab_series_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit formlibrary_1_9_tab_series_Dialog(QWidget *parent = nullptr);
    ~formlibrary_1_9_tab_series_Dialog();

//private:
    Ui::formlibrary_1_9_tab_series_Dialog *ui;
private slots:
    void on_pushButton_input_clicked();


};

#endif // FORMLIBRARY_1_9_TAB_SERIES_DIALOG_H
