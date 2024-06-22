#ifndef FORM_DATAENTRY_DATAENTRY___BATCH_SAMPLING_H
#define FORM_DATAENTRY_DATAENTRY___BATCH_SAMPLING_H

#include <QWidget>

namespace Ui {
class form_dataentry_dataentry___Batch_Sampling;
}

class form_dataentry_dataentry___Batch_Sampling : public QWidget
{
    Q_OBJECT

public:
    explicit form_dataentry_dataentry___Batch_Sampling(QWidget *parent = nullptr);
    ~form_dataentry_dataentry___Batch_Sampling();

private slots:
    void on_pushButton_clear_clicked();

    void on_pushButton_clear_2_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::form_dataentry_dataentry___Batch_Sampling *ui;

    void GetData();
};

#endif // FORM_DATAENTRY_DATAENTRY___BATCH_SAMPLING_H
