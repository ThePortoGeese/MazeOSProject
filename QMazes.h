#ifndef QMAZES_H
#define QMAZES_H
#include "mazeclass.h"
#include <QTCore>
#include <vector>
#include <QWidget>
#include <QObject>


class temporaryCorrectPathHolder {
public:
    int x;
    int y;
    int k;
    temporaryCorrectPathHolder(int a,int b,int c){
        x=a;
        y=b;
        k=c;
    }
};

class QMazes : public QObject, public mazeClass
{
    Q_OBJECT

public:

    QMazes(int x,int y) : mazeClass(x,y){}

    void connectionsPrint() override;

    const QString& getName(){
        return name;
    }

    void createMaze() override;

    void nameGenerator();

    std::vector<cell*> correctPath;

    std::vector<temporaryCorrectPathHolder*> tempCorrectPath;

signals:
    void cellTriggered(int x,int y,int connectionNumber);
    void mazeSolved();
private:
    bool recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y) override;
    QString name;
};

#endif // QMAZES_H
