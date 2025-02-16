#include "menuwindow.h"
#include "mazes.h"
#include <QApplication>
#include <map>
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menuWindow w;
    w.show();

    return a.exec();
}
