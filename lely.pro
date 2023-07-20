QT       += core gui sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AdminPanel/mainwidget.cpp \
    AdminPanel/stumanager.cpp \
    Debug/data.cpp \
    Debug/datetime.cpp \
    Debug/logger.cpp \
    FormsMenu/form_1_1.cpp \
    FormsMenu/form_1_2.cpp \
    FormsMenu/form_1_2_general.cpp \
    FormsMenu/form_tabview.cpp \
    connectiondialog.cpp \
    db/database.cpp \
    db/dialogwindow.cpp \
    form_2_1.cpp \
    form_z_1.cpp \
    formtemplate.cpp \
    main.cpp \
    mainwindow.cpp \
    modelbuilder.cpp \
    widget_form.cpp \
    widget_menu.cpp

HEADERS += \
    AdminPanel/mainwidget.h \
    AdminPanel/stumanager.h \
    AdminPanel/ui_mainwidget.h \
    AdminPanel/ui_stumanager.h \
    Debug/data.h \
    Debug/datetime.h \
    Debug/logger.h \
    FormsMenu/form_1_1.h \
    FormsMenu/form_1_2.h \
    FormsMenu/form_1_2_general.h \
    FormsMenu/form_tabview.h \
    connectiondialog.h \
    db/connectdb.h \
    db/database.h \
    db/dialogwindow.h \
    form_2_1.h \
    form_z_1.h \
    formtemplate.h \
    mainwindow.h \
    modelbuilder.h \
    widget_form.h \
    widget_menu.h

FORMS += \
    AdminPanel/mainwidget.ui \
    AdminPanel/stumanager.ui \
    FormsMenu/form_1_1.ui \
    FormsMenu/form_1_2.ui \
    FormsMenu/form_1_2_general.ui \
    FormsMenu/form_tabview.ui \
    connectiondialog.ui \
    form_2_1.ui \
    form_z_1.ui \
    mainwindow.ui \
    widget_form.ui \
    widget_menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc
