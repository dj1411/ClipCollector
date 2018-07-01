#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    QRect rect = QApplication::desktop()->screenGeometry();
    w.setGeometry(rect.width() - 300, rect.height() - 400, 300, 400);

    return a.exec();
}
