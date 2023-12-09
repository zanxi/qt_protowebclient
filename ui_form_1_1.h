/********************************************************************************
** Form generated from reading UI file 'form_1_1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_1_1_H
#define UI_FORM_1_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_1_1
{
public:
    QHBoxLayout *horizontalLayout_14;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_FarmDepart;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_counrty;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_lang;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *comboBox_culture;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_Index;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_street;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_street_number;
    QLineEdit *lineEdit_street_number;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLineEdit *lineEdit_zip_code;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *lineEdit_city;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *lineEdit_telephone;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLineEdit *lineEdit_owner_name;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QLineEdit *lineEdit_login;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_13;
    QComboBox *comboBox_list_devices;
    QPushButton *pushButton;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;

    void setupUi(QWidget *Form_1_1)
    {
        if (Form_1_1->objectName().isEmpty())
            Form_1_1->setObjectName(QString::fromUtf8("Form_1_1"));
        Form_1_1->resize(1067, 663);
        horizontalLayout_14 = new QHBoxLayout(Form_1_1);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        tabWidget = new QTabWidget(Form_1_1);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget\n"
"{\n"
"   background-color:rgb(0,255,128);\n"
"}\n"
"\n"
"QTabWidget:tab-bar\n"
"{\n"
"    alignment: center;\n"
"}\n"
"\n"
"QTabBar:tab\n"
"{\n"
"   width: 210px;   \n"
"   height: 30px;\n"
"}\n"
"\n"
"QTabBar:selected\n"
"{\n"
"    background-color:rgb(0,255,128);\n"
"    color.rgb(0,255,128);\n"
"}\n"
"\n"
"\n"
"QTabBar:tab:!selected\n"
"{     \n"
"    color.rgb(0,255,128);\n"
"}\n"
"\n"
"\n"
"QTabBar:tab:!selected:hover\n"
"{ \n"
"    background-color:rgb(0,255,128);\n"
"    color.rgb(255,255,255);\n"
"}\n"
"\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 276, 482));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_FarmDepart = new QLineEdit(groupBox_2);
        lineEdit_FarmDepart->setObjectName(QString::fromUtf8("lineEdit_FarmDepart"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_FarmDepart->sizePolicy().hasHeightForWidth());
        lineEdit_FarmDepart->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_FarmDepart);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_counrty = new QComboBox(groupBox_2);
        comboBox_counrty->setObjectName(QString::fromUtf8("comboBox_counrty"));

        horizontalLayout_2->addWidget(comboBox_counrty);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBox_lang = new QComboBox(groupBox_2);
        comboBox_lang->setObjectName(QString::fromUtf8("comboBox_lang"));

        horizontalLayout_3->addWidget(comboBox_lang);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        comboBox_culture = new QComboBox(groupBox_2);
        comboBox_culture->setObjectName(QString::fromUtf8("comboBox_culture"));

        horizontalLayout_4->addWidget(comboBox_culture);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_Index = new QLineEdit(groupBox_2);
        lineEdit_Index->setObjectName(QString::fromUtf8("lineEdit_Index"));
        sizePolicy.setHeightForWidth(lineEdit_Index->sizePolicy().hasHeightForWidth());
        lineEdit_Index->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(lineEdit_Index);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_street = new QLineEdit(groupBox_2);
        lineEdit_street->setObjectName(QString::fromUtf8("lineEdit_street"));
        sizePolicy.setHeightForWidth(lineEdit_street->sizePolicy().hasHeightForWidth());
        lineEdit_street->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(lineEdit_street);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_street_number = new QLabel(groupBox_2);
        label_street_number->setObjectName(QString::fromUtf8("label_street_number"));

        horizontalLayout_7->addWidget(label_street_number);

        lineEdit_street_number = new QLineEdit(groupBox_2);
        lineEdit_street_number->setObjectName(QString::fromUtf8("lineEdit_street_number"));
        sizePolicy.setHeightForWidth(lineEdit_street_number->sizePolicy().hasHeightForWidth());
        lineEdit_street_number->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(lineEdit_street_number);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        lineEdit_zip_code = new QLineEdit(groupBox_2);
        lineEdit_zip_code->setObjectName(QString::fromUtf8("lineEdit_zip_code"));
        sizePolicy.setHeightForWidth(lineEdit_zip_code->sizePolicy().hasHeightForWidth());
        lineEdit_zip_code->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(lineEdit_zip_code);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_9->addWidget(label_7);

        lineEdit_city = new QLineEdit(groupBox_2);
        lineEdit_city->setObjectName(QString::fromUtf8("lineEdit_city"));

        horizontalLayout_9->addWidget(lineEdit_city);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        lineEdit_telephone = new QLineEdit(groupBox_2);
        lineEdit_telephone->setObjectName(QString::fromUtf8("lineEdit_telephone"));

        horizontalLayout_10->addWidget(lineEdit_telephone);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_11->addWidget(label_10);

        lineEdit_owner_name = new QLineEdit(groupBox_2);
        lineEdit_owner_name->setObjectName(QString::fromUtf8("lineEdit_owner_name"));

        horizontalLayout_11->addWidget(lineEdit_owner_name);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_12->addWidget(label_11);

        lineEdit_login = new QLineEdit(groupBox_2);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        horizontalLayout_12->addWidget(lineEdit_login);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_13->addWidget(label_12);

        lineEdit_password = new QLineEdit(groupBox_2);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        horizontalLayout_13->addWidget(lineEdit_password);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_15->addWidget(label_13);

        comboBox_list_devices = new QComboBox(groupBox_2);
        comboBox_list_devices->setObjectName(QString::fromUtf8("comboBox_list_devices"));

        horizontalLayout_15->addWidget(comboBox_list_devices);


        verticalLayout->addLayout(horizontalLayout_15);


        verticalLayout_2->addWidget(groupBox_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());

        horizontalLayout_14->addWidget(tabWidget);


        retranslateUi(Form_1_1);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form_1_1);
    } // setupUi

    void retranslateUi(QWidget *Form_1_1)
    {
        Form_1_1->setWindowTitle(QApplication::translate("Form_1_1", "Form", nullptr));
        groupBox_2->setTitle(QApplication::translate("Form_1_1", "Farm", nullptr));
        label->setText(QApplication::translate("Form_1_1", "\320\230\320\274\321\217 \320\277\320\276\320\264\321\200\320\260\320\267\320\264\320\265\320\273\320\265\320\275\320\270\321\217:", nullptr));
        label_2->setText(QApplication::translate("Form_1_1", "\320\241\321\202\321\200\320\260\320\275\320\260:", nullptr));
        label_3->setText(QApplication::translate("Form_1_1", "\320\257\320\267\321\213\320\272:", nullptr));
        label_4->setText(QApplication::translate("Form_1_1", "\320\232\321\203\320\273\321\214\321\202\321\203\321\200\320\260:", nullptr));
        label_5->setText(QApplication::translate("Form_1_1", "\320\230\320\275\320\264\320\265\320\272\321\201:", nullptr));
        label_6->setText(QApplication::translate("Form_1_1", "\320\243\320\273\320\270\321\206\320\260:", nullptr));
        label_street_number->setText(QApplication::translate("Form_1_1", "\320\235\320\276\320\274\320\265\321\200:", nullptr));
        label_8->setText(QApplication::translate("Form_1_1", "\320\230\320\275\320\264\320\265\320\272\321\201:", nullptr));
        label_7->setText(QApplication::translate("Form_1_1", "\320\223\320\276\321\200\320\276\320\264:", nullptr));
        label_9->setText(QApplication::translate("Form_1_1", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275:", nullptr));
        label_10->setText(QApplication::translate("Form_1_1", "\320\244\320\230\320\236 \320\222\320\273\320\260\320\264\320\265\320\273\321\214\321\206\320\260", nullptr));
        label_11->setText(QApplication::translate("Form_1_1", "Login:", nullptr));
        label_12->setText(QApplication::translate("Form_1_1", "Password", nullptr));
        label_13->setText(QApplication::translate("Form_1_1", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276:", nullptr));
        pushButton->setText(QApplication::translate("Form_1_1", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 \321\204\320\265\321\200\320\274\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Form_1_1", "Farm", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Form_1_1", "\320\241\321\202\320\260\320\264\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Form_1_1", "\320\236\320\261\320\273\320\260\321\201\321\202\320\270 \320\277\321\200\320\265\320\261\321\213\320\262\320\260\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Form_1_1", "\320\244\321\203\320\275\320\272\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\321\213\320\265 \320\275\320\260\321\201\321\202 \321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_1_1: public Ui_Form_1_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_1_1_H
