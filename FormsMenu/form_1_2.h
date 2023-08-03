#ifndef FORM_1_2_H
#define FORM_1_2_H

#include <QWidget>
#include <QStringListModel>
#include <QItemSelection>


namespace Ui {
class Form_1_2;
}

class Form_1_2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form_1_2(QWidget *parent = 0);
    ~Form_1_2();

private slots:
    void SelectionChanged(const QItemSelection& selection);

private:
    Ui::Form_1_2 *ui;
    QStringListModel *m_qlist_model;
};

#endif // FORM_1_2_H
