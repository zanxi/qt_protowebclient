#ifndef FORM_1_2_H
#define FORM_1_2_H

#include <QWidget>
#include <QStringListModel>
#include <QItemSelection>
#include <QTimer>

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

public slots:
    void UpdateList();
    void UpdateList2();

private:
    Ui::Form_1_2 *ui;
    QStringListModel *m_qlist_model;
    QTimer *mTimer;

    int GetDataCounter();
    int GetData(QString tab);
    //void UpdateList();
};

#endif // FORM_1_2_H
