#ifndef DIALOG_FORM_DATAENTRY_SETTINGS___POST_DURING_H
#define DIALOG_FORM_DATAENTRY_SETTINGS___POST_DURING_H

#include <QDialog>

namespace Ui {
class Dialog_form_dataentry_settings___post_during;
}

class Dialog_form_dataentry_settings___post_during : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_form_dataentry_settings___post_during(QWidget *parent = nullptr);
    ~Dialog_form_dataentry_settings___post_during();

private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::Dialog_form_dataentry_settings___post_during *ui;
};

#endif // DIALOG_FORM_DATAENTRY_SETTINGS___POST_DURING_H
