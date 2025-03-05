#ifndef QMAZES_H
#define QMAZES_H
#include "mazeclass.h"
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
    friend class QMazesConversionMethods;
    Q_OBJECT
public:

    QMazes(int x,int y);

    void connectionsPrint() override;

    const QString& getName(){
        return name;
    }

    void createMaze() override;

    static QMazes* convertFromFile(QFile* file);

    void nameGenerator();

    std::vector<temporaryPathHolder*> tempPath;

    void saveAsFile(QString fileName);
signals:
    void cellTriggered(int x,int y,int connectionNumber);
    void mazeSolved();
private:
    bool recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y,const bool& store) override;
    bool recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y,const int& tX,const int& tY) override;
    QString name="";
    bool userGenerated=1;
public slots:
    void setName(QString& str){
        name=str;
    }

};
#endif // QMAZES_H
