/********************************************************************************
** Form generated from reading UI file 'cell_check_and_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELL_CHECK_AND_EDIT_H
#define UI_CELL_CHECK_AND_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cell_check_and_edit
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QLineEdit *lineEdit;

    void setupUi(QWidget *cell_check_and_edit)
    {
        if (cell_check_and_edit->objectName().isEmpty())
            cell_check_and_edit->setObjectName(QString::fromUtf8("cell_check_and_edit"));
        cell_check_and_edit->resize(189, 40);
        cell_check_and_edit->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(cell_check_and_edit);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox = new QCheckBox(cell_check_and_edit);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMinimumSize(QSize(0, 20));

        horizontalLayout->addWidget(checkBox);

        lineEdit = new QLineEdit(cell_check_and_edit);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 20));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(cell_check_and_edit);

        QMetaObject::connectSlotsByName(cell_check_and_edit);
    } // setupUi

    void retranslateUi(QWidget *cell_check_and_edit)
    {
        cell_check_and_edit->setWindowTitle(QApplication::translate("cell_check_and_edit", "Form", nullptr));
        checkBox->setText(QApplication::translate("cell_check_and_edit", "Fixed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cell_check_and_edit: public Ui_cell_check_and_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELL_CHECK_AND_EDIT_H
