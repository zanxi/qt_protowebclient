/********************************************************************************
** Form generated from reading UI file 'autorizationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTORIZATIONDIALOG_H
#define UI_AUTORIZATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AutorizationDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QComboBox *comboBox_db;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_host;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_name_db;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_Port;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_login;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_logon;

    void setupUi(QDialog *AutorizationDialog)
    {
        if (AutorizationDialog->objectName().isEmpty())
            AutorizationDialog->setObjectName(QString::fromUtf8("AutorizationDialog"));
        AutorizationDialog->resize(349, 288);
        verticalLayout_2 = new QVBoxLayout(AutorizationDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(AutorizationDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        comboBox_db = new QComboBox(groupBox);
        comboBox_db->setObjectName(QString::fromUtf8("comboBox_db"));

        horizontalLayout_6->addWidget(comboBox_db);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_host = new QLineEdit(groupBox);
        lineEdit_host->setObjectName(QString::fromUtf8("lineEdit_host"));

        horizontalLayout->addWidget(lineEdit_host);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_name_db = new QLineEdit(groupBox);
        lineEdit_name_db->setObjectName(QString::fromUtf8("lineEdit_name_db"));

        horizontalLayout_2->addWidget(lineEdit_name_db);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        lineEdit_Port = new QLineEdit(groupBox);
        lineEdit_Port->setObjectName(QString::fromUtf8("lineEdit_Port"));

        horizontalLayout_7->addWidget(lineEdit_Port);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_login = new QLineEdit(groupBox);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        horizontalLayout_3->addWidget(lineEdit_login);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        horizontalLayout_4->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setCheckable(true);
        checkBox->setChecked(true);

        horizontalLayout_8->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_exit = new QPushButton(groupBox);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        horizontalLayout_5->addWidget(pushButton_exit);

        pushButton_logon = new QPushButton(groupBox);
        pushButton_logon->setObjectName(QString::fromUtf8("pushButton_logon"));

        horizontalLayout_5->addWidget(pushButton_logon);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(AutorizationDialog);

        QMetaObject::connectSlotsByName(AutorizationDialog);
    } // setupUi

    void retranslateUi(QDialog *AutorizationDialog)
    {
        AutorizationDialog->setWindowTitle(QApplication::translate("AutorizationDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("AutorizationDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\262\321\205\320\276\320\264\320\260 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203:", nullptr));
        label_5->setText(QApplication::translate("AutorizationDialog", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205: ", nullptr));
        label->setText(QApplication::translate("AutorizationDialog", "\320\220\320\264\321\200\320\265\321\201 \320\262 \321\201\320\265\321\202\320\270: ", nullptr));
        lineEdit_host->setText(QApplication::translate("AutorizationDialog", "192.168.1.2", nullptr));
        label_2->setText(QApplication::translate("AutorizationDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205: ", nullptr));
        lineEdit_name_db->setText(QApplication::translate("AutorizationDialog", "vim3", nullptr));
        label_6->setText(QApplication::translate("AutorizationDialog", "\320\237\320\276\321\200\321\202:", nullptr));
        label_3->setText(QApplication::translate("AutorizationDialog", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217: ", nullptr));
        lineEdit_login->setText(QApplication::translate("AutorizationDialog", "postgres", nullptr));
        label_4->setText(QApplication::translate("AutorizationDialog", "\320\237\320\260\321\200\320\276\320\273\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217: ", nullptr));
        lineEdit_password->setText(QApplication::translate("AutorizationDialog", "000", nullptr));
        checkBox->setText(QApplication::translate("AutorizationDialog", "\320\237\320\265\321\200\320\265\321\201\320\276\320\267\320\264\320\260\321\202\321\214 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        pushButton_exit->setText(QApplication::translate("AutorizationDialog", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \321\201\320\270\321\201\321\202\320\265\320\274\321\213", nullptr));
        pushButton_logon->setText(QApplication::translate("AutorizationDialog", "\320\222\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AutorizationDialog: public Ui_AutorizationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTORIZATIONDIALOG_H
