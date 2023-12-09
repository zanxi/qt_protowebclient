/********************************************************************************
** Form generated from reading UI file 'form_1_9_insemenation_s.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_1_9_INSEMENATION_S_H
#define UI_FORM_1_9_INSEMENATION_S_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_1_9_insemenation_s
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_numbers;
    QLineEdit *lineEdit;
    QPushButton *pushButton_add;
    QPushButton *pushButton_select;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *form_1_9_insemenation_s)
    {
        if (form_1_9_insemenation_s->objectName().isEmpty())
            form_1_9_insemenation_s->setObjectName(QString::fromUtf8("form_1_9_insemenation_s"));
        form_1_9_insemenation_s->resize(1088, 630);
        verticalLayout_3 = new QVBoxLayout(form_1_9_insemenation_s);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(form_1_9_insemenation_s);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox_numbers = new QComboBox(groupBox);
        comboBox_numbers->setObjectName(QString::fromUtf8("comboBox_numbers"));

        horizontalLayout->addWidget(comboBox_numbers);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton_add = new QPushButton(groupBox);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        horizontalLayout->addWidget(pushButton_add);

        pushButton_select = new QPushButton(groupBox);
        pushButton_select->setObjectName(QString::fromUtf8("pushButton_select"));

        horizontalLayout->addWidget(pushButton_select);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(form_1_9_insemenation_s);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(groupBox_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_3->addWidget(groupBox_2);


        retranslateUi(form_1_9_insemenation_s);

        QMetaObject::connectSlotsByName(form_1_9_insemenation_s);
    } // setupUi

    void retranslateUi(QWidget *form_1_9_insemenation_s)
    {
        form_1_9_insemenation_s->setWindowTitle(QApplication::translate("form_1_9_insemenation_s", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("form_1_9_insemenation_s", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\272\320\276\321\200\320\276\320\262\321\203", nullptr));
        pushButton_add->setText(QApplication::translate("form_1_9_insemenation_s", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_select->setText(QApplication::translate("form_1_9_insemenation_s", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        groupBox_2->setTitle(QApplication::translate("form_1_9_insemenation_s", "\320\236\321\201\320\265\320\274\320\265\320\275\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class form_1_9_insemenation_s: public Ui_form_1_9_insemenation_s {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_1_9_INSEMENATION_S_H
