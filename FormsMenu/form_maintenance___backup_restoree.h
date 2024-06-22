#ifndef FORM_MAINTENANCE___BACKUP_RESTOREE_H
#define FORM_MAINTENANCE___BACKUP_RESTOREE_H

#include <QWidget>

namespace Ui {
class Form_maintenance___backup_restoree;
}

class Form_maintenance___backup_restoree : public QWidget
{
    Q_OBJECT

public:
    explicit Form_maintenance___backup_restoree(QWidget *parent = nullptr);
    ~Form_maintenance___backup_restoree();

    void Db_backup(QString dump_sql);
    void Db_restore(QString dump_sql);

private slots:
    void on_pushButton_new_clicked();

    void on_pushButton_submit_clicked();

private:
    Ui::Form_maintenance___backup_restoree *ui;

    void GetData();    
    void GetData(const QString &str);
};

#endif // FORM_MAINTENANCE___BACKUP_RESTOREE_H
