#ifndef AUTORIZATIONDIALOG_H
#define AUTORIZATIONDIALOG_H

#include <QDialog>

namespace Ui {
class AutorizationDialog;
}

class AutorizationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AutorizationDialog(QWidget *parent = nullptr);
    ~AutorizationDialog();

private slots:
    void on_pushButton_exit_clicked();
    void on_pushButton_logon_clicked();
    void on_comboBox_db_activated(int index);
    void on_checkBox_stateChanged(int arg1);
    void on_lineEdit_login_textChanged(const QString &arg1);

private:
    Ui::AutorizationDialog *ui;

    void GetAutorization();

    QList<QList<QString>> spisok_users= {
        {"127.0.0.1", "vim3", "5433", "postgres", "000"},
        {"127.0.0.1", "vim3", "5433", "vim", "000"},
        {"127.0.0.1", "vim3", "5433", "zanxi", "000"},
        {"192.168.0.3", "vim3", "5432", "postgres", "000"},
        {"192.168.0.3", "vim3", "5432", "vim", "000"},
        {"192.168.0.3", "vim3", "5432", "zanxi", "000"}
    };
};

#endif // AUTORIZATIONDIALOG_H
