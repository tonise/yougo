#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     Widget w;
    QDesktopWidget *pDesk=QApplication::desktop();

    w.move((pDesk->width() - w.width()) / 2,0);
    w.show();

    return a.exec();
}
