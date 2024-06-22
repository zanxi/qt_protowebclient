#include "formlibrary_1_9_tab_diseases_dialog.h"
#include "ui_formlibrary_1_9_tab_diseases_dialog.h"

formlibrary_1_9_tab_diseases_dialog::formlibrary_1_9_tab_diseases_dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::formlibrary_1_9_tab_diseases_dialog)
{
    ui->setupUi(this);
}

formlibrary_1_9_tab_diseases_dialog::~formlibrary_1_9_tab_diseases_dialog()
{
    delete ui;
}
