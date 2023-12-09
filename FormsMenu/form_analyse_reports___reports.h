#ifndef FORM_ANALYSE_REPORTS___REPORTS_H
#define FORM_ANALYSE_REPORTS___REPORTS_H

#include <QWidget>

namespace Ui {
class Form_analyse_reports___reports;
}

class Form_analyse_reports___reports : public QWidget
{
    Q_OBJECT

public:
    explicit Form_analyse_reports___reports(QWidget *parent = nullptr);
    ~Form_analyse_reports___reports();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form_analyse_reports___reports *ui;
};

#endif // FORM_ANALYSE_REPORTS___REPORTS_H
