#ifndef FORM_DATAENTRY_GROUPS_H
#define FORM_DATAENTRY_GROUPS_H

#include <QWidget>
#include <QItemSelection>

namespace Ui {
class form_dataentry_groups;
}

class form_dataentry_groups : public QWidget
{
    Q_OBJECT

public:
    explicit form_dataentry_groups(QWidget *parent = nullptr);
    ~form_dataentry_groups();

private slots:
    void SelectionChanged(const QItemSelection& selection);

private:
    Ui::form_dataentry_groups *ui;
};

#endif // FORM_DATAENTRY_GROUPS_H
