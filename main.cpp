#include "main_digitalfarm.h"
#include "AdminPanel/AdminWidget.h"

#include <QApplication>
#include <QtCore/QTextCodec>
#include <QFile>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8")); //изменения
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); //изменения
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")); //изменения

    QApplication a(argc, argv);

    QFile file(":/style/app");
    bool ret = file.open(QFile::ReadOnly);
    if (ret) {
        //qApp->setStyleSheet(file.readAll());
        file.close();
    }

    //***************** Запуск эмблемы ВИМ перед запуском приложения ****************************//
    QFont font = QApplication::font();
    QFont fontSmall = font;
    font.setPointSize(10);
    QApplication::setFont(font);

    QPixmap pixmap(":/images/vim.png");
    QSplashScreen splash(pixmap);
    splash.show();
    splash.setFont(fontSmall);
    splash.showMessage(QObject::tr("Initializing VIM"),
                       Qt::AlignLeft | Qt::AlignTop, Qt::black);  //This line represents the alignment of text, color and position

    //***************** END Запуск эмблемы ВИМ перед запуском приложения ****************************//

    //***************** Установка шрифта ****************************//

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    QTranslator myappTranslator;
    myappTranslator.load("VIM_" + QLocale::system().name());
    a.installTranslator(&myappTranslator);

    //***************** END Установка шрифта ****************************//



    //std::ios_base::sync_with_stdio(false);

    //***************** Запуск основного приложения прототипа lely ****************************//

    Main_DigitalFarm main_DigitalFarm;
    //AdminWidget *w = new AdminWidget();

    main_DigitalFarm.show();
    splash.finish(&main_DigitalFarm);

    //***************** End Запуск основного приложения прототипа lely ****************************//



    return a.exec();
}
