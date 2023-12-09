#ifndef FORM_1_1_H
#define FORM_1_1_H

#include <QWidget>
#include <QStringListModel>

namespace Ui {
class Form_1_1;
}

class Form_1_1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form_1_1(QWidget *parent = 0);
    ~Form_1_1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form_1_1 *ui;
    QStringListModel *m_qlist_model_country, *m_qlist_model_culture,  *m_qlist_model_lang,  *m_qlist_list_devices;
    void GetRegisterData();
    void SaveRegisterData();
};

#endif // FORM_1_1_H
