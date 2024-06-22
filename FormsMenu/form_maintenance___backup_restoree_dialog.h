#ifndef FORM_MAINTENANCE___BACKUP_RESTOREE_DIALOG_H
#define FORM_MAINTENANCE___BACKUP_RESTOREE_DIALOG_H

#include <QDialog>

namespace Ui {
class form_maintenance___backup_restoree_Dialog;
}

class form_maintenance___backup_restoree_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit form_maintenance___backup_restoree_Dialog(QWidget *parent = nullptr);
    ~form_maintenance___backup_restoree_Dialog();

private slots:
    void on_pushButton_download_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::form_maintenance___backup_restoree_Dialog *ui;
};

#endif // FORM_MAINTENANCE___BACKUP_RESTOREE_DIALOG_H
