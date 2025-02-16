#ifndef MAZES_H
#define MAZES_H
#include <QTCore>
#include <string>
#include <tuple>
#include <vector>
#include <QWidget>
#include <QObject>
class cell;

class temporaryCorrectPathHolder;

class mazes : public QObject
{
    Q_OBJECT

public:

    mazes(int x,int y);

    static void connectionsPrint(const std::vector<std::vector<cell>>& maze);

    void createMaze();
    const std::vector<std::vector<cell>>& getMaze(){
        return daMaze;
    }

    void mazeSolver();

    const QString& getName(){
        return name;
    }

    const int& x() {return X;}
    const int& y() {return Y;}

    void setX(int i){X=i;}
    void setY(int i){Y=i;}

    void nameGenerator();

    std::vector<cell*> correctPath;

    std::vector<temporaryCorrectPathHolder*> tempCorrectPath;

signals:
    void cellTriggered(int x,int y,int connectionNumber);
    void mazeSolved();
private:
    int X,Y;
    std::vector<std::vector<cell>> daMaze;
    bool recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y);
    void recursiveDiggingFunction(int x, int y, std::vector<std::vector<bool> > &booleanGrid);
    QString name;

};

class connection
{
public:
    cell* from;
    cell* to;
    int obstacle=1;
};

class cell
{
public:
    std::vector<connection> connectionsTo;
    std::vector<connection*> connectionFrom;

    void setup(std::vector<std::vector<cell>>& cells,std::tuple<int,int> pos);
};

class temporaryCorrectPathHolder{
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
#endif // MAZES_H
