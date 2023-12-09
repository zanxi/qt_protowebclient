/********************************************************************************
** Form generated from reading UI file 'DbManager.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMANAGER_H
#define UI_DBMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stuManager
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *stuManager)
    {
        if (stuManager->objectName().isEmpty())
            stuManager->setObjectName(QString::fromUtf8("stuManager"));
        stuManager->resize(427, 292);
        gridLayout = new QGridLayout(stuManager);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(stuManager);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(stuManager);

        QMetaObject::connectSlotsByName(stuManager);
    } // setupUi

    void retranslateUi(QWidget *stuManager)
    {
        stuManager->setWindowTitle(QApplication::translate("stuManager", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stuManager: public Ui_stuManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMANAGER_H
