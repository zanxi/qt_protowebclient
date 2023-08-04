/********************************************************************************
** Form generated from reading UI file 'adminwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIDGET_H
#define UI_ADMINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_13;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *userLabel_3;
    QLineEdit *lineEdit_db_sqlite_file;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *userLabel_2;
    QLineEdit *lineEdit_db_pg_login;
    QHBoxLayout *horizontalLayout_10;
    QLabel *passwordLabel_2;
    QLineEdit *lineEdit_db_pg_password;
    QHBoxLayout *horizontalLayout_11;
    QLabel *databaseLabel_2;
    QLineEdit *lineEdit_db_pg_name;
    QHBoxLayout *horizontalLayout_12;
    QLabel *hostLabel_2;
    QLineEdit *linerEdit_db_pg_host;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *textEdit;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_5;
    QHBoxLayout *horizontalLayout_14;
    QGroupBox *groupBox_9;
    QLabel *label;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_10;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *tab_6;
    QHBoxLayout *horizontalLayout_15;
    QGroupBox *groupBox_11;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->resize(975, 582);
        horizontalLayout_5 = new QHBoxLayout(mainWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox_4 = new QGroupBox(mainWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        tabWidget_2 = new QTabWidget(groupBox_4);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setStyleSheet(QString::fromUtf8("QTabWidget\n"
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
"   width: 150px;   \n"
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
"    color.rgb(0,255,128);\n"
"}\n"
"\n"
"\n"
""));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_13 = new QHBoxLayout(tab_2);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setEnabled(true);
        horizontalLayout_9 = new QHBoxLayout(groupBox_5);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(500, 0));
        verticalLayout_6 = new QVBoxLayout(groupBox_6);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        userLabel_3 = new QLabel(groupBox_6);
        userLabel_3->setObjectName(QString::fromUtf8("userLabel_3"));

        horizontalLayout_7->addWidget(userLabel_3);

        lineEdit_db_sqlite_file = new QLineEdit(groupBox_6);
        lineEdit_db_sqlite_file->setObjectName(QString::fromUtf8("lineEdit_db_sqlite_file"));

        horizontalLayout_7->addWidget(lineEdit_db_sqlite_file);


        verticalLayout_6->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 356, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        horizontalLayout_9->addWidget(groupBox_6);

        groupBox_8 = new QGroupBox(groupBox_5);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        verticalLayout_4 = new QVBoxLayout(groupBox_8);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        userLabel_2 = new QLabel(groupBox_8);
        userLabel_2->setObjectName(QString::fromUtf8("userLabel_2"));

        horizontalLayout_8->addWidget(userLabel_2);

        lineEdit_db_pg_login = new QLineEdit(groupBox_8);
        lineEdit_db_pg_login->setObjectName(QString::fromUtf8("lineEdit_db_pg_login"));

        horizontalLayout_8->addWidget(lineEdit_db_pg_login);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        passwordLabel_2 = new QLabel(groupBox_8);
        passwordLabel_2->setObjectName(QString::fromUtf8("passwordLabel_2"));

        horizontalLayout_10->addWidget(passwordLabel_2);

        lineEdit_db_pg_password = new QLineEdit(groupBox_8);
        lineEdit_db_pg_password->setObjectName(QString::fromUtf8("lineEdit_db_pg_password"));
        lineEdit_db_pg_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_10->addWidget(lineEdit_db_pg_password);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        databaseLabel_2 = new QLabel(groupBox_8);
        databaseLabel_2->setObjectName(QString::fromUtf8("databaseLabel_2"));

        horizontalLayout_11->addWidget(databaseLabel_2);

        lineEdit_db_pg_name = new QLineEdit(groupBox_8);
        lineEdit_db_pg_name->setObjectName(QString::fromUtf8("lineEdit_db_pg_name"));

        horizontalLayout_11->addWidget(lineEdit_db_pg_name);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        hostLabel_2 = new QLabel(groupBox_8);
        hostLabel_2->setObjectName(QString::fromUtf8("hostLabel_2"));

        horizontalLayout_12->addWidget(hostLabel_2);

        linerEdit_db_pg_host = new QLineEdit(groupBox_8);
        linerEdit_db_pg_host->setObjectName(QString::fromUtf8("linerEdit_db_pg_host"));

        horizontalLayout_12->addWidget(linerEdit_db_pg_host);


        verticalLayout_4->addLayout(horizontalLayout_12);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_9->addWidget(groupBox_8);


        horizontalLayout_13->addWidget(groupBox_5);

        tabWidget_2->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_6 = new QHBoxLayout(tab_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        verticalLayout_5 = new QVBoxLayout(groupBox_7);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        textEdit = new QTextEdit(groupBox_7);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_5->addWidget(textEdit);


        horizontalLayout_6->addWidget(groupBox_7);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        horizontalLayout_3 = new QHBoxLayout(tab_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeView = new QTreeView(groupBox);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setMaximumSize(QSize(30000, 16777215));

        verticalLayout->addWidget(treeView);


        horizontalLayout_3->addWidget(groupBox);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(tab_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget = new QTabWidget(groupBox_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());

        verticalLayout_3->addWidget(tabWidget);


        verticalLayout_2->addWidget(groupBox_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        horizontalLayout_14 = new QHBoxLayout(tab_5);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        groupBox_9 = new QGroupBox(tab_5);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        label = new QLabel(groupBox_9);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 26, 229, 16));
        lineEdit = new QLineEdit(groupBox_9);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 50, 133, 22));

        horizontalLayout_14->addWidget(groupBox_9);

        groupBox_10 = new QGroupBox(tab_5);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        label_2 = new QLabel(groupBox_10);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 30, 231, 16));
        lineEdit_2 = new QLineEdit(groupBox_10);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(30, 60, 231, 22));

        horizontalLayout_14->addWidget(groupBox_10);

        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        horizontalLayout_15 = new QHBoxLayout(tab_6);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        groupBox_11 = new QGroupBox(tab_6);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));

        horizontalLayout_15->addWidget(groupBox_11);

        tabWidget_2->addTab(tab_6, QString());

        verticalLayout_7->addWidget(tabWidget_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout_7->addLayout(horizontalLayout_4);


        horizontalLayout_5->addWidget(groupBox_4);


        retranslateUi(mainWidget);

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QApplication::translate("mainWidget", "mainWidget", nullptr));
        groupBox_4->setTitle(QApplication::translate("mainWidget", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
        groupBox_5->setTitle(QApplication::translate("mainWidget", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\262\321\217\320\267\320\270 \321\201 \320\261\320\260\320\267\320\276\320\271 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        groupBox_6->setTitle(QApplication::translate("mainWidget", "SQLite(\320\273\320\276\320\272\320\260\320\273\321\214\320\275\320\260\321\217)", nullptr));
        userLabel_3->setText(QApplication::translate("mainWidget", "\320\233\320\276\320\272\320\260\320\273\321\214\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", nullptr));
        lineEdit_db_sqlite_file->setText(QApplication::translate("mainWidget", "c:\\lely\\db-lely3.db", nullptr));
        lineEdit_db_sqlite_file->setPlaceholderText(QString());
        groupBox_8->setTitle(QApplication::translate("mainWidget", "PostgreSql(\321\203\320\264\320\260\320\273\320\265\320\275\320\275\321\213\320\271 \321\201\320\265\321\200\320\262\320\265\321\200)", nullptr));
        userLabel_2->setText(QApplication::translate("mainWidget", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        lineEdit_db_pg_login->setText(QApplication::translate("mainWidget", "postgres", nullptr));
        lineEdit_db_pg_login->setPlaceholderText(QString());
        passwordLabel_2->setText(QApplication::translate("mainWidget", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        lineEdit_db_pg_password->setInputMask(QString());
        lineEdit_db_pg_password->setText(QApplication::translate("mainWidget", "000", nullptr));
        lineEdit_db_pg_password->setPlaceholderText(QString());
        databaseLabel_2->setText(QApplication::translate("mainWidget", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205:", nullptr));
        lineEdit_db_pg_name->setText(QApplication::translate("mainWidget", "vim", nullptr));
        lineEdit_db_pg_name->setPlaceholderText(QString());
        hostLabel_2->setText(QApplication::translate("mainWidget", "IP Address:", nullptr));
        linerEdit_db_pg_host->setText(QApplication::translate("mainWidget", "192.168.124.135", nullptr));
        linerEdit_db_pg_host->setPlaceholderText(QApplication::translate("mainWidget", "localhost", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("mainWidget", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\262\321\217\320\267\320\270", nullptr));
        groupBox_7->setTitle(QApplication::translate("mainWidget", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265/\321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\277\321\203\320\275\320\272\321\202\320\276\320\262 \320\274\320\265\320\275\321\216(XML)", nullptr));
        textEdit->setDocumentTitle(QString());
        textEdit->setPlaceholderText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("mainWidget", "\320\234\320\265\320\275\321\216", nullptr));
        groupBox->setTitle(QApplication::translate("mainWidget", "\320\224\320\265\321\200\320\265\320\262\320\276 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        groupBox_3->setTitle(QApplication::translate("mainWidget", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265", nullptr));
        groupBox_2->setTitle(QApplication::translate("mainWidget", "\320\242\320\260\320\261\320\273\320\270\321\206\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("mainWidget", "Tab 1", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("mainWidget", "\320\220\320\264\320\274\320\270\320\275 \320\277\320\260\320\275\320\265\320\273\321\214 DB", nullptr));
        groupBox_9->setTitle(QApplication::translate("mainWidget", "MS Word", nullptr));
        label->setText(QApplication::translate("mainWidget", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\272 \321\210\320\260\320\261\320\273\320\276\320\275\321\203 Word \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260", nullptr));
        groupBox_10->setTitle(QApplication::translate("mainWidget", "MS Excel", nullptr));
        label_2->setText(QApplication::translate("mainWidget", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\272 \321\210\320\260\320\261\320\273\320\276\320\275\321\203 Excel \320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("mainWidget", "\320\236\321\202\321\207\320\265\321\202\321\213 Word/Excel", nullptr));
        groupBox_11->setTitle(QApplication::translate("mainWidget", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("mainWidget", "\320\223\321\200\320\260\321\204\320\270\320\272\320\270", nullptr));
        pushButton->setText(QApplication::translate("mainWidget", "\320\276\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        pushButton_2->setText(QApplication::translate("mainWidget", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
