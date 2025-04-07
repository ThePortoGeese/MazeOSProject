#ifndef MAZECLASS_H
#define MAZECLASS_H
#include <tuple>
#include <vector>
#include <QWidget>
#include <QObject>
#include <chrono>

namespace MazeEnums{
enum directions{
    left=0,
    up=1,
    right=0,
    down=1
};

enum obstacles{
    noObstacles=0,
    obstacle=1,
    entrance=2,
    exit=5,
};
}
class cell;

class mazeClass
{
public:

    mazeClass(int x,int y);

    virtual void connectionsPrint();

    virtual void createMaze();
    const std::vector<std::vector<cell>>& getMaze() const{
        return daMaze;
    }
    bool mazeChecker();
    std::tuple<int,int> getEntrancePos();

    virtual bool wallFollowerMazeSolver();
    virtual bool recursiveMazeSolver();
    virtual bool recursiveMazeSolver(const int& tX,const int& tY);
    virtual bool deadEndFillingMazeSolver();

    const int& x() {return X;}
    const int& y() {return Y;}

    void setX(int i){X=i;}
    void setY(int i){Y=i;}

    std::vector<cell*> correctPath;
protected:
    int X,Y;
    std::vector<std::vector<cell>> daMaze;
    virtual bool recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y, const bool &store = 1); //This is a recursive backtracker function
    virtual bool recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y,const int& tX, const int& tY); //This is also a recursive backtracker function
    virtual void recursiveDiggingFunction(int x, int y, std::vector<std::vector<bool> > &booleanGrid);
private:

};

class connection
{
public:
    cell* from;
    cell* to;
    int obstacle=1;

    connection(cell* fr,cell* t,int obs){
        from=fr;
        to=t;
        obstacle=obs;
    }
    connection(){
        from=nullptr;
        to=nullptr;
    }
};

class cell
{
public:
    std::vector<connection> connectionsTo;
    std::vector<connection*> connectionFrom;

    void setup(std::vector<std::vector<cell>>& cells,std::tuple<int,int> pos);
};

#endif // MAZECLASS_H
