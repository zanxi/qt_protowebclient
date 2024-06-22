#ifndef FORMLIBRARY_1_9_TAB_DISEASES_DIALOG_H
#define FORMLIBRARY_1_9_TAB_DISEASES_DIALOG_H

#include <QWidget>

namespace Ui {
class formlibrary_1_9_tab_diseases_dialog;
}

class formlibrary_1_9_tab_diseases_dialog : public QWidget
{
    Q_OBJECT

public:
    explicit formlibrary_1_9_tab_diseases_dialog(QWidget *parent = nullptr);
    ~formlibrary_1_9_tab_diseases_dialog();

private:
    Ui::formlibrary_1_9_tab_diseases_dialog *ui;
};

#endif // FORMLIBRARY_1_9_TAB_DISEASES_DIALOG_H
