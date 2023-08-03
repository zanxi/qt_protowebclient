/********************************************************************************
** Form generated from reading UI file 'table_form_2_1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_FORM_2_1_H
#define UI_TABLE_FORM_2_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Table_Form_2_1
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget_lists_signals;

    void setupUi(QWidget *Form_2_1)
    {
        if (Form_2_1->objectName().isEmpty())
            Form_2_1->setObjectName(QString::fromUtf8("Form_2_1"));
        Form_2_1->resize(875, 200);
        Form_2_1->setMaximumSize(QSize(16777215, 200));
        verticalLayout = new QVBoxLayout(Form_2_1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Form_2_1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget_lists_signals = new QTableWidget(groupBox);
        tableWidget_lists_signals->setObjectName(QString::fromUtf8("tableWidget_lists_signals"));

        verticalLayout_2->addWidget(tableWidget_lists_signals);


        verticalLayout->addWidget(groupBox);


        retranslateUi(Form_2_1);

        QMetaObject::connectSlotsByName(Form_2_1);
    } // setupUi

    void retranslateUi(QWidget *Form_2_1)
    {
        Form_2_1->setWindowTitle(QApplication::translate("Form_2_1", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("Form_2_1", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\201\320\270\320\263\320\275\320\260\320\273\320\276\320\262 \320\264\320\273\321\217 \320\277\321\200\320\270\320\262\320\273\320\265\321\207\320\265\320\275\320\270\321\217 \320\262\320\275\320\270\320\274\320\260\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Table_Form_2_1: public Ui_Table_Form_2_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_FORM_2_1_H
