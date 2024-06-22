#include "basewindow.h"

#include "debug/logger.h"
#include "dataanimals.h"
#include "db/SqlDataBase.h"
#include "./json/json_w.h"

#include <memory>
#include <QScopedPointer>
#include <QApplication>

BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //***************** Инициализация ****************************//

    //***************** Установка белого цвета приложения и размеров ****************************//
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    //setGeometry(QRect(200, 100, 1600, 800));

    QRect r = QApplication::desktop()->screenGeometry();
    //this->resize(r.width(), r.height());
    setGeometry(QRect(200, 100, 200+4*r.width(), 100+2*r.height()));
    //***************** End Установка белого цвета приложения и размеров ****************************//

    // !!!!!!!!!!!!!!!! ВНИМАНИЕ - здесь важная часть установок проекта !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //***************** Осчистка логов отладки и дефолтная установка значений параметров системы (БД, наименований, таблиц) ****************************//
    logger::ClearLog();
    DataSystems::Instance().clear();
    //***************** End Осчистка логов отладки и дефолтная установка значений параметров системы (БД, наименований, таблиц) ****************************//

}

// *******************************************

BaseWindow::~BaseWindow()
{

}

void BaseWindow::keyPressEvent(QKeyEvent *event)
{
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    if (keyEvent->key() == Qt::Key_Enter) {
        //qDebug() << ("keyPressEvent: Enter received");
    }
    else if (keyEvent->key() == Qt::Key_A)
    {
        //qDebug() << ("keyPressEvent: A received");
    }
}

void BaseWindow::keyReleaseEvent(QKeyEvent *event)
{
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    if (keyEvent->key() == Qt::Key_Escape)
    {
        //qDebug() << ("keyReleaseEvent: Escape received");
        QMessageBox::information(this,"Спасибо","Вы вышли из программы <<<Цифровая ферма>>>");
        QApplication::closeAllWindows();
        QApplication::quit();
    }
}



