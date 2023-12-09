/********************************************************************************
** Form generated from reading UI file 'form_1_2_general.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_1_2_GENERAL_H
#define UI_FORM_1_2_GENERAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_1_2_General
{
public:

    void setupUi(QWidget *Form_1_2_General)
    {
        if (Form_1_2_General->objectName().isEmpty())
            Form_1_2_General->setObjectName(QString::fromUtf8("Form_1_2_General"));
        Form_1_2_General->resize(744, 300);

        retranslateUi(Form_1_2_General);

        QMetaObject::connectSlotsByName(Form_1_2_General);
    } // setupUi

    void retranslateUi(QWidget *Form_1_2_General)
    {
        Form_1_2_General->setWindowTitle(QApplication::translate("Form_1_2_General", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_1_2_General: public Ui_Form_1_2_General {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_1_2_GENERAL_H
