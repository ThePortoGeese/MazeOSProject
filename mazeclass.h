#ifndef MAZECLASS_H
#define MAZECLASS_H
#include <tuple>
#include <vector>
#include <QWidget>
#include <QObject>
class cell;

class mazeClass
{
public:

    mazeClass(int x,int y);

    virtual void connectionsPrint();

    virtual void createMaze();
    const std::vector<std::vector<cell>>& getMaze(){
        return daMaze;
    }

    void mazeSolver();

    const int& x() {return X;}
    const int& y() {return Y;}

    void setX(int i){X=i;}
    void setY(int i){Y=i;}

    std::vector<cell*> correctPath;
protected:
    int X,Y;
    std::vector<std::vector<cell>> daMaze;
    virtual bool recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y);
    virtual void recursiveDiggingFunction(int x, int y, std::vector<std::vector<bool> > &booleanGrid);
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

#endif // MAZECLASS_H
