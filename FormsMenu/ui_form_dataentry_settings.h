/********************************************************************************
** Form generated from reading UI file 'form_dataentry_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_DATAENTRY_SETTINGS_H
#define UI_FORM_DATAENTRY_SETTINGS_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_DataEntry_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_lactation;
    QWidget *tab_milk;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget_3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_14;
    QTableWidget *tableWidget_general_milking;
    QWidget *tab_7;
    QWidget *tab_8;
    QWidget *tab_9;
    QVBoxLayout *verticalLayout_15;
    QTableWidget *tableWidget_post_milking;
    QWidget *tab_10;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_13;
    QTreeView *treeView;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *lineEdit_10;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_10;
    QLineEdit *lineEdit_11;
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *lineEdit_12;
    QLabel *label_9;
    QLineEdit *lineEdit_14;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *lineEdit_13;
    QLabel *label_10;
    QLineEdit *lineEdit_15;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *tab_11;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_feeding___feed_tables;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_transition;
    QWidget *tab;

    void setupUi(QWidget *Form_DataEntry_Settings)
    {
        if (Form_DataEntry_Settings->objectName().isEmpty())
            Form_DataEntry_Settings->setObjectName(QString::fromUtf8("Form_DataEntry_Settings"));
        Form_DataEntry_Settings->resize(1260, 1039);
        verticalLayout = new QVBoxLayout(Form_DataEntry_Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(Form_DataEntry_Settings);
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
        tab_lactation = new QWidget();
        tab_lactation->setObjectName(QString::fromUtf8("tab_lactation"));
        tabWidget->addTab(tab_lactation, QString());
        tab_milk = new QWidget();
        tab_milk->setObjectName(QString::fromUtf8("tab_milk"));
        verticalLayout_4 = new QVBoxLayout(tab_milk);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        tabWidget_3 = new QTabWidget(tab_milk);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_14 = new QVBoxLayout(tab_2);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        tableWidget_general_milking = new QTableWidget(tab_2);
        if (tableWidget_general_milking->columnCount() < 18)
            tableWidget_general_milking->setColumnCount(18);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_general_milking->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        tableWidget_general_milking->setObjectName(QString::fromUtf8("tableWidget_general_milking"));

        verticalLayout_14->addWidget(tableWidget_general_milking);

        tabWidget_3->addTab(tab_2, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tabWidget_3->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        tabWidget_3->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        verticalLayout_15 = new QVBoxLayout(tab_9);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        tableWidget_post_milking = new QTableWidget(tab_9);
        if (tableWidget_post_milking->columnCount() < 12)
            tableWidget_post_milking->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(6, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(7, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(8, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(9, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(10, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_post_milking->setHorizontalHeaderItem(11, __qtablewidgetitem29);
        tableWidget_post_milking->setObjectName(QString::fromUtf8("tableWidget_post_milking"));

        verticalLayout_15->addWidget(tableWidget_post_milking);

        tabWidget_3->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        verticalLayout_12 = new QVBoxLayout(tab_10);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        groupBox = new QGroupBox(tab_10);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(300, 16777215));
        verticalLayout_13 = new QVBoxLayout(groupBox);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        treeView = new QTreeView(groupBox);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout_13->addWidget(treeView);


        horizontalLayout_6->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab_10);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_11 = new QVBoxLayout(groupBox_2);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_5->addWidget(label);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_5->addWidget(label_2);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_6->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_6->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_6->addWidget(lineEdit_3);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_7->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(groupBox_2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout_7->addWidget(lineEdit_5);

        lineEdit_6 = new QLineEdit(groupBox_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        verticalLayout_7->addWidget(lineEdit_6);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        lineEdit_7 = new QLineEdit(groupBox_2);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        verticalLayout_8->addWidget(lineEdit_7);

        lineEdit_8 = new QLineEdit(groupBox_2);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        verticalLayout_8->addWidget(lineEdit_8);

        lineEdit_9 = new QLineEdit(groupBox_2);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        verticalLayout_8->addWidget(lineEdit_9);


        horizontalLayout->addLayout(verticalLayout_8);


        verticalLayout_11->addLayout(horizontalLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        lineEdit_10 = new QLineEdit(groupBox_2);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        verticalLayout_9->addWidget(lineEdit_10);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_9->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        lineEdit_11 = new QLineEdit(groupBox_2);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        verticalLayout_10->addWidget(lineEdit_11);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_10->addWidget(label_5);


        horizontalLayout_2->addLayout(verticalLayout_10);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);


        horizontalLayout_7->addLayout(horizontalLayout_2);


        verticalLayout_11->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        lineEdit_12 = new QLineEdit(groupBox_2);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));

        horizontalLayout_3->addWidget(lineEdit_12);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));

        horizontalLayout_3->addWidget(label_9);

        lineEdit_14 = new QLineEdit(groupBox_2);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));

        horizontalLayout_3->addWidget(lineEdit_14);


        verticalLayout_11->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_4->addWidget(label_8);

        lineEdit_13 = new QLineEdit(groupBox_2);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));

        horizontalLayout_4->addWidget(lineEdit_13);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";"));

        horizontalLayout_4->addWidget(label_10);

        lineEdit_15 = new QLineEdit(groupBox_2);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));

        horizontalLayout_4->addWidget(lineEdit_15);


        verticalLayout_11->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer);


        horizontalLayout_6->addWidget(groupBox_2);


        verticalLayout_12->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(tab_10);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_5->addWidget(pushButton_2);

        pushButton = new QPushButton(tab_10);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_5->addWidget(pushButton);


        verticalLayout_12->addLayout(horizontalLayout_5);

        tabWidget_3->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        tabWidget_3->addTab(tab_11, QString());

        verticalLayout_4->addWidget(tabWidget_3);

        tabWidget->addTab(tab_milk, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget_2 = new QTabWidget(tab_3);
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
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_3 = new QVBoxLayout(tab_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidget_feeding___feed_tables = new QTableWidget(tab_4);
        tableWidget_feeding___feed_tables->setObjectName(QString::fromUtf8("tableWidget_feeding___feed_tables"));

        verticalLayout_3->addWidget(tableWidget_feeding___feed_tables);

        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget_2->addTab(tab_6, QString());

        verticalLayout_2->addWidget(tabWidget_2);

        tabWidget->addTab(tab_3, QString());
        tab_transition = new QWidget();
        tab_transition->setObjectName(QString::fromUtf8("tab_transition"));
        tabWidget->addTab(tab_transition, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(Form_DataEntry_Settings);

        tabWidget->setCurrentIndex(1);
        tabWidget_3->setCurrentIndex(3);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form_DataEntry_Settings);
    } // setupUi

    void retranslateUi(QWidget *Form_DataEntry_Settings)
    {
        Form_DataEntry_Settings->setWindowTitle(QApplication::translate("Form_DataEntry_Settings", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_lactation), QApplication::translate("Form_DataEntry_Settings", "\320\233\320\260\320\272\321\202\320\260\321\206\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_general_milking->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("Form_DataEntry_Settings", "\320\234\320\276\320\273\320\276\320\267\320\270\320\262\320\276(\320\264\320\275\320\270)", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_general_milking->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("Form_DataEntry_Settings", "\320\234\320\265\321\201\321\202\320\276 \320\273\320\260\320\272\321\202\320\260\321\206\320\270\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_general_milking->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("Form_DataEntry_Settings", "\320\234\320\265\321\201\321\202\320\276 \321\201\320\265\320\277\320\260\321\200\320\260\321\206\320\270\320\270 \320\274\320\276\320\273\320\276\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_general_milking->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("Form_DataEntry_Settings", "\320\234\320\276\320\273\320\276\320\267\320\270\320\262\320\276 \320\274\320\265\321\201\321\202\320\260 \320\273\320\260\320\272\321\202\320\260\321\206\320\270\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_general_milking->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QApplication::translate("Form_DataEntry_Settings", "\320\241\320\277\320\276\321\201\320\276\320\261 \320\262\320\267\321\217\321\202\320\270\321\217 \320\277\321\200\320\276\320\261", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_general_milking->horizontalHeaderItem(6);
        ___qtablewidgetitem5->setText(QApplication::translate("Form_DataEntry_Settings", "lf", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_general_milking->horizontalHeaderItem(7);
        ___qtablewidgetitem6->setText(QApplication::translate("Form_DataEntry_Settings", "lr", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_general_milking->horizontalHeaderItem(8);
        ___qtablewidgetitem7->setText(QApplication::translate("Form_DataEntry_Settings", "rf", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_general_milking->horizontalHeaderItem(9);
        ___qtablewidgetitem8->setText(QApplication::translate("Form_DataEntry_Settings", "rr", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_general_milking->horizontalHeaderItem(10);
        ___qtablewidgetitem9->setText(QApplication::translate("Form_DataEntry_Settings", "\320\234\320\276\320\273\320\276\321\207\320\275\321\213\320\265 \321\201\320\276\321\201\320\272\320\270(\320\264\320\260/\320\275\320\265\321\202)", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_general_milking->horizontalHeaderItem(11);
        ___qtablewidgetitem10->setText(QApplication::translate("Form_DataEntry_Settings", "\320\241\320\261\321\200\320\276\321\201 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \321\201\320\276\321\201\320\272\320\276\320\262 \320\277\320\276\321\201\320\273\320\265 \321\201\321\203\321\205\320\276\321\201\321\202\320\276\320\271\320\275\320\276\321\201\321\202\320\270(\320\264\320\260/\320\275\320\265\321\202)", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_general_milking->horizontalHeaderItem(12);
        ___qtablewidgetitem11->setText(QApplication::translate("Form_DataEntry_Settings", "\320\237\320\265\321\200\320\270\320\276\320\264 \320\277\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\321\217(\320\264\320\260/\320\275\320\265\321\202)", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_general_milking->horizontalHeaderItem(13);
        ___qtablewidgetitem12->setText(QApplication::translate("Form_DataEntry_Settings", "\320\233\320\260\320\272\321\202\320\260\321\206\320\270\321\217 \320\277\320\276\320\264 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265\320\274(\320\264\320\260/\320\275\320\265\321\202)", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_general_milking->horizontalHeaderItem(14);
        ___qtablewidgetitem13->setText(QApplication::translate("Form_DataEntry_Settings", "\320\236\320\277\321\202\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\277\320\265\321\200\320\270\320\276\320\264 \320\262\320\267\321\217\321\202\320\270\321\217(\321\207\320\260\321\201\321\213)", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_general_milking->horizontalHeaderItem(15);
        ___qtablewidgetitem14->setText(QApplication::translate("Form_DataEntry_Settings", "\320\237\320\276\320\267\320\270\321\206\320\270\320\270 \321\201\320\276\321\201\320\272\320\276\320\262 \320\270\320\267\320\262\320\265\321\201\321\202\320\275\321\213(\320\264\320\260/\320\275\320\265\321\202)", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_general_milking->horizontalHeaderItem(16);
        ___qtablewidgetitem15->setText(QApplication::translate("Form_DataEntry_Settings", "\320\232\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_general_milking->horizontalHeaderItem(17);
        ___qtablewidgetitem16->setText(QApplication::translate("Form_DataEntry_Settings", "\320\220\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\271 \321\201\320\277\320\276\321\201\320\276\320\261 \321\201\320\262\321\217\320\267\320\270(\320\264\320\260/\320\275\320\265\321\202)", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_2), QApplication::translate("Form_DataEntry_Settings", "\320\236\320\261\321\211\320\265\320\265 \320\264\320\276\320\265\320\275\320\270\320\265", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("Form_DataEntry_Settings", "\320\224\320\276 \320\264\320\276\320\265\320\275\320\270\321\217", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("Form_DataEntry_Settings", "\320\222\320\276 \320\262\321\200\320\265\320\274\321\217 \320\264\320\276\320\265\320\275\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_post_milking->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("Form_DataEntry_Settings", "lf_1", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_post_milking->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("Form_DataEntry_Settings", "lr_1", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_post_milking->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QApplication::translate("Form_DataEntry_Settings", "rf_1", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_post_milking->horizontalHeaderItem(4);
        ___qtablewidgetitem20->setText(QApplication::translate("Form_DataEntry_Settings", "rr_1", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_post_milking->horizontalHeaderItem(5);
        ___qtablewidgetitem21->setText(QApplication::translate("Form_DataEntry_Settings", "lf_2", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_post_milking->horizontalHeaderItem(6);
        ___qtablewidgetitem22->setText(QApplication::translate("Form_DataEntry_Settings", "lr_2", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_post_milking->horizontalHeaderItem(7);
        ___qtablewidgetitem23->setText(QApplication::translate("Form_DataEntry_Settings", "rf_2", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_post_milking->horizontalHeaderItem(8);
        ___qtablewidgetitem24->setText(QApplication::translate("Form_DataEntry_Settings", "rr_2", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_post_milking->horizontalHeaderItem(9);
        ___qtablewidgetitem25->setText(QApplication::translate("Form_DataEntry_Settings", "\320\241\320\277\320\276\321\201\320\276\320\261(\320\264\320\260/\320\275\320\265\321\202)", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_post_milking->horizontalHeaderItem(10);
        ___qtablewidgetitem26->setText(QApplication::translate("Form_DataEntry_Settings", "\320\247\320\270\321\201\321\202\320\276\320\265 \320\274\320\276\320\273\320\276\321\207\320\275\320\276\320\265 \320\276\320\261\320\276\321\200\321\203\320\264\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_post_milking->horizontalHeaderItem(11);
        ___qtablewidgetitem27->setText(QApplication::translate("Form_DataEntry_Settings", "\320\237\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202\320\275\320\276\320\265 \320\272\320\276\321\200\320\274\320\273\320\265\320\275\320\270\320\265(\320\264\320\260/\320\275\320\265\321\202)", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_9), QApplication::translate("Form_DataEntry_Settings", "\320\237\320\276\321\201\320\273\320\265 \320\264\320\276\320\265\320\275\320\270\321\217", nullptr));
        groupBox->setTitle(QApplication::translate("Form_DataEntry_Settings", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        groupBox_2->setTitle(QApplication::translate("Form_DataEntry_Settings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        label->setText(QApplication::translate("Form_DataEntry_Settings", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\272\320\276\320\273\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\264\320\276\320\265\320\275\320\270\320\271:", nullptr));
        label_2->setText(QApplication::translate("Form_DataEntry_Settings", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\276\320\266\320\270\320\264\320\260\320\265\320\274\321\213\320\271 \320\275\320\260\320\264\320\276\320\271 \320\267\320\260 \320\264\320\276\320\265\320\275\320\270\320\265: ", nullptr));
        label_3->setText(QApplication::translate("Form_DataEntry_Settings", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\264\320\276\320\265\320\275\320\270\320\271:", nullptr));
        label_4->setText(QApplication::translate("Form_DataEntry_Settings", "\320\224\320\275\320\270 \320\277\320\276\321\201\320\273\320\265 \320\276\321\202\320\265\320\273\320\260:", nullptr));
        label_5->setText(QApplication::translate("Form_DataEntry_Settings", "\320\224\320\275\320\270 \320\264\320\276 \321\201\321\203\321\205\320\276\321\201\321\202\320\276\320\271\320\275\320\276\321\201\321\202\320\270:", nullptr));
        label_6->setText(QApplication::translate("Form_DataEntry_Settings", "\320\241\321\203\321\205\320\276\321\201\321\202\320\276\320\271\320\275\320\276\321\201\321\202\321\214:", nullptr));
        label_7->setText(QApplication::translate("Form_DataEntry_Settings", "\320\235\320\265 \320\264\320\276\320\270\321\202\321\214 \321\201/\320\264\320\276:", nullptr));
        label_9->setText(QApplication::translate("Form_DataEntry_Settings", "-", nullptr));
        label_8->setText(QApplication::translate("Form_DataEntry_Settings", "\320\235\320\265 \320\264\320\276\320\270\321\202\321\214 c/\320\264\320\276:", nullptr));
        label_10->setText(QApplication::translate("Form_DataEntry_Settings", "-", nullptr));
        pushButton_2->setText(QApplication::translate("Form_DataEntry_Settings", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton->setText(QApplication::translate("Form_DataEntry_Settings", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_10), QApplication::translate("Form_DataEntry_Settings", "\320\224\320\276\321\201\321\202\321\203\320\277 \320\272 \320\274\320\276\320\273\320\276\320\272\321\203", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_11), QApplication::translate("Form_DataEntry_Settings", "\320\241\320\270\320\263\320\275\320\260\320\273 \320\264\320\273\321\217 \320\277\321\200\320\270\320\262\320\273\320\265\321\207\320\265\320\275\320\270\321\217 \320\262\320\275\320\270\320\274\320\260\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_milk), QApplication::translate("Form_DataEntry_Settings", "\320\224\320\276\320\265\320\275\320\270\320\265", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("Form_DataEntry_Settings", "\320\242\320\260\320\261\320\273\320\270\321\206\321\213 \320\272\320\276\321\200\320\274\320\273\320\265\320\275\320\270\321\217", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("Form_DataEntry_Settings", "\320\242\320\270\320\277\321\213 \320\272\320\276\321\200\320\274\320\276\320\262", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("Form_DataEntry_Settings", "\320\222\320\275\320\270\320\274\320\260\320\275\320\270\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Form_DataEntry_Settings", "\320\232\320\276\321\200\320\274\320\273\320\265\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_transition), QApplication::translate("Form_DataEntry_Settings", "\320\227\320\260\320\264\320\260\321\207\320\270 \320\274\320\260\321\200\321\210\321\200\321\203\321\202\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Form_DataEntry_Settings", "DLM; \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_DataEntry_Settings: public Ui_Form_DataEntry_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_DATAENTRY_SETTINGS_H
