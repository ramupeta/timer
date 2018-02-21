#include "mainwindow.h"
#include <QApplication>
#include<QScreen>
#include<QRect>
#include<QSize>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
        QScreen *sc=QGuiApplication::primaryScreen();
        QRect scgtry=sc->geometry();
        int ht=scgtry.height();
        int wd=scgtry.width();
        w.setFixedSize(wd,ht);

    w.show();

    return a.exec();
}
