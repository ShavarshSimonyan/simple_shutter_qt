#include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include <QScreen>

#include "MainWindow.h"

#include <cstdlib>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::srand(0);

    MainWindow w;
    w.move(a.desktop()->screen()->rect().center() - w.rect().center());
    w.show();
    return a.exec();
}
