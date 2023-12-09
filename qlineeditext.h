#ifndef QLINEEDITEXT_H
#define QLINEEDITEXT_H

#include <QLineEdit>

class QLineEditExt : public QLineEdit
{
public:
    QLineEditExt(QWidget *parent = nullptr);
    //void setText(QString text){ setText(text); };

    int col,row;
};

#endif // QLINEEDITEXT_H
