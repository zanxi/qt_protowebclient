#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QWidget>

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QWidget
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

private:
    Ui::AdminPanel *ui;
};

#endif // ADMINPANEL_H
