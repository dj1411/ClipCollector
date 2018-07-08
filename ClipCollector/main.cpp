#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget w;
    w.setWindowState(Qt::WindowMinimized); /* start the application minimized */
    w.show();

    return a.exec();
}
