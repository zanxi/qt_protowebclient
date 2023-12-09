/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *actionDB_connection;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_title;
    QLabel *label_icon;
    QLabel *label_title;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_title_2;
    QHBoxLayout *horizontalLayout_3;
    QMenuBar *menubar;
    QMenu *menuSettings;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        actionDB_connection = new QAction(MainWindow);
        actionDB_connection->setObjectName(QString::fromUtf8("actionDB_connection"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_title = new QWidget(centralwidget);
        widget_title->setObjectName(QString::fromUtf8("widget_title"));
        widget_title->setMinimumSize(QSize(0, 33));
        widget_title->setMaximumSize(QSize(16777215, 33));
        label_icon = new QLabel(widget_title);
        label_icon->setObjectName(QString::fromUtf8("label_icon"));
        label_icon->setGeometry(QRect(10, 0, 30, 30));
        label_icon->setMinimumSize(QSize(30, 30));
        label_icon->setMaximumSize(QSize(30, 16777215));
        label_icon->setPixmap(QPixmap(QString::fromUtf8(":/images/logo")));
        label_title = new QLabel(widget_title);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setGeometry(QRect(60, 10, 461, 16));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_title->sizePolicy().hasHeightForWidth());
        label_title->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(widget_title);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        widget_title_2 = new QWidget(centralwidget);
        widget_title_2->setObjectName(QString::fromUtf8("widget_title_2"));
        widget_title_2->setMinimumSize(QSize(0, 33));
        widget_title_2->setMaximumSize(QSize(16777215, 33));
        horizontalLayout_3 = new QHBoxLayout(widget_title_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);

        verticalLayout_3->addWidget(widget_title_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menu->menuAction());
        menuSettings->addAction(action);
        menu->addAction(actionDB_connection);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        actionDB_connection->setText(QApplication::translate("MainWindow", "DB:connection", nullptr));
        label_icon->setText(QString());
        label_title->setText(QApplication::translate("MainWindow", "\320\244\320\265\320\264\320\265\321\200\320\260\320\273\321\214\320\275\321\213\320\271 \320\275\320\260\321\203\321\207\320\275\321\213\320\271 \320\260\320\263\321\200\320\276\320\270\320\275\320\266\320\265\320\275\320\265\321\200\320\275\321\213\320\271 \321\206\320\265\320\275\321\202\321\200 \320\222\320\230\320\234", nullptr));
        menuSettings->setTitle(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
