QT       += core gui sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AdminPanel/DbManager.cpp \
    AdminPanel/adminwidget.cpp \
    Debug/data.cpp \
    Debug/datetime.cpp \
    Debug/logger.cpp \
    FormsMenu/form_1_1.cpp \
    FormsMenu/form_1_2.cpp \
    FormsMenu/form_1_2_general.cpp \
    FormsMenu/table_form_1_2_otel.cpp \
    FormsMenu/table_form_2_1.cpp \
    connectiondialog.cpp \
    csv/csvfile.cpp \
    dataanimals.cpp \
    db/GenerateDB.cpp \
    db/SqlDataBase.cpp \
    db/database.cpp \
    db/dialogwindow.cpp \
    form_2_1.cpp \
    form_in_work.cpp \
    formtemplate.cpp \
    json/json_w.cpp \
    main.cpp \
    mainwindow.cpp \
    modelbuilder.cpp \
    tabelwidget_module/checkboxitemdelegate.cpp \
    tabelwidget_module/comboboxitemdelegate.cpp \
    tabelwidget_module/datetimestyleditemdelegate.cpp \
    tabelwidget_module/spinboxitemdelegate.cpp \
    table_form_1_2.cpp \
    table_form_1_2_batch_transfer.cpp \
    table_form_1_2_in_work.cpp \
    utils/Utils.cpp \
    widget_form.cpp \
    widget_menu.cpp

HEADERS += \
    AdminPanel/DbManager.h \
    AdminPanel/adminwidget.h \
    AdminPanel/ui_AdminWidget.h \
    AdminPanel/ui_DbManager.h \
    AdminPanel/ui_mainwidget.h \
    Debug/data.h \
    Debug/datetime.h \
    Debug/logger.h \
    FormsMenu/form_1_1.h \
    FormsMenu/form_1_2.h \
    FormsMenu/form_1_2_general.h \
    FormsMenu/table_form_1_2_otel.h \
    FormsMenu/table_form_2_1.h \
    FormsMenu/ui_table_form_2_1.h \
    connectiondialog.h \
    csv/csvfile.h \
    dataanimals.h \
    db/GenerateDB.h \
    db/SqlDataBase.h \
    db/database.h \
    db/dialogwindow.h \
    form_2_1.h \
    form_in_work.h \
    formtemplate.h \
    json/json_w.h \
    mainwindow.h \
    modelbuilder.h \
    tabelwidget_module/checkboxitemdelegate.h \
    tabelwidget_module/comboboxitemdelegate.h \
    tabelwidget_module/datetimestyleditemdelegate.h \
    tabelwidget_module/spinboxitemdelegate.h \
    table_form_1_2.h \
    table_form_1_2_batch_transfer.h \
    table_form_1_2_in_work.h \
    utils/Utils.h \
    widget_form.h \
    widget_menu.h

FORMS += \
    AdminPanel/DbManager.ui \
    AdminPanel/adminwidget.ui \
    FormsMenu/form_1_1.ui \
    FormsMenu/form_1_2.ui \
    FormsMenu/form_1_2_general.ui \
    FormsMenu/table_form_1_2_otel.ui \
    FormsMenu/table_form_2_1.ui \
    connectiondialog.ui \
    form_2_1.ui \
    form_in_work.ui \
    mainwindow.ui \
    table_form_1_2.ui \
    table_form_1_2_batch_transfer.ui \
    table_form_1_2_in_work.ui \
    widget_form.ui \
    widget_menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc
