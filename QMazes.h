#ifndef QMAZES_H
#define QMAZES_H
#include "mazeclass.h"
#include "previewmazeview.h"
#include "qgraphicsscene.h"
#include <QTCore>
#include <vector>
#include <QWidget>
#include <QObject>


class temporaryPathHolder {
public:
    int x;
    int y;
    int k;
    temporaryPathHolder(int a,int b,int c){
        x=a;
        y=b;
        k=c;
    }
};

class QMazes : public QObject, public mazeClass
{
    Q_OBJECT

public:

    QMazes(int x,int y);

    void connectionsPrint() override;

    const QString& getName(){
        return name;
    }

    void createMaze() override;

    static QMazes* convertFromView(PreviewMazeView* mazeView);

    void nameGenerator();

    std::vector<cell*> correctPath;

    std::vector<temporaryPathHolder*> tempPath;

signals:
    void cellTriggered(int x,int y,int connectionNumber);
    void mazeSolved();
private:
    bool recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y) override;
    bool recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y,const int& tX,const int& tY) override;
    QString name;

};

#endif // QMAZES_H
