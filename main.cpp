#include "mainwindow.h"
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

    QFont font = QApplication::font();
    QFont fontSmall = font;
    font.setPointSize(10);
    QApplication::setFont(font);

    QPixmap pixmap("./images/vim.png");
    QSplashScreen splash(pixmap);
    splash.show();
    splash.setFont(fontSmall);
    splash.showMessage(QObject::tr("Initializing VIM"),
                       Qt::AlignLeft | Qt::AlignTop, Qt::black);  //This line represents the alignment of text, color and position

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    QTranslator myappTranslator;
    myappTranslator.load("HadronResonanceGas_" + QLocale::system().name());
    a.installTranslator(&myappTranslator);



    //std::ios_base::sync_with_stdio(false);

    MainWindow w;
    //AdminWidget *w = new AdminWidget();

    w.show();
    splash.finish(&w);



    return a.exec();
}
