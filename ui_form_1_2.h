/********************************************************************************
** Form generated from reading UI file 'form_1_2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_1_2_H
#define UI_FORM_1_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_1_2
{
public:
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QListView *listView;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *Form_1_2)
    {
        if (Form_1_2->objectName().isEmpty())
            Form_1_2->setObjectName(QString::fromUtf8("Form_1_2"));
        Form_1_2->resize(1201, 728);
        horizontalLayout_3 = new QHBoxLayout(Form_1_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(Form_1_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(300, 0));
        groupBox_2->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listView = new QListView(groupBox_2);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);


        horizontalLayout_3->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_3->addLayout(horizontalLayout);


        retranslateUi(Form_1_2);

        QMetaObject::connectSlotsByName(Form_1_2);
    } // setupUi

    void retranslateUi(QWidget *Form_1_2)
    {
        Form_1_2->setWindowTitle(QApplication::translate("Form_1_2", "Form", nullptr));
        groupBox_2->setTitle(QApplication::translate("Form_1_2", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\271:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_1_2: public Ui_Form_1_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_1_2_H
