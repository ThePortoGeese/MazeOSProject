#ifndef QMAZES_H
#define QMAZES_H
#include "2dmaze.h"
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

class QMazes : public QObject, public TwoDMaze
{
    friend class QMazesConversionMethods;
    Q_OBJECT
public:

    QMazes(int y,int x);

    void connectionsPrint() override;

    const QString& getName(){
        return name;
    }

    bool recursiveMazeSolver() override;
    bool recursiveMazeSolver(const int& tX,const int& tY) override;
    void createMaze() override;

    static QMazes* convertFromFile(QFile* file);

    void nameGenerator();
    void notUserGenerated(){
        userGenerated=0;
    }
    std::vector<temporaryPathHolder*> tempPath;

    const bool& getUserGeneratedStatus(){
        return userGenerated;
    }
    bool wallFollowerMazeSolver() override ;
    bool deadEndFillingMazeSolver() override;
    void saveAsFile(QString fileName);

    void setEvaluated(bool b){
        evaluated=b;
    }
    const bool& getEvaluated(){
        return evaluated;
    }
signals:
    void cellTriggered(int x,int y,int connectionNumber);
    void mazeSolved();
    void timeOut();
    void couldntReach();
private:

    bool evaluated=0;
    bool recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y,const bool& store = 1) override;
    bool recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y,const int& tX,const int& tY) override;
    QString name="";
    bool userGenerated=1;
private Q_SLOTS:
    void emitCellTriggeredSignal(int x, int y, int connectionNumber){
        emit cellTriggered(x,y,connectionNumber);
    }
public slots:
    void setName(QString& str){
        name=str;
    }
};
#endif // QMAZES_H
