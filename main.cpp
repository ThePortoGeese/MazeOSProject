#include "Widgets/menuwindow.h"
#include "qmazes.h"
#include <QApplication>
#include <map>
#include <vector>
#include <QtPlugin>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menuWindow w;
    w.show();
    return a.exec();
}
