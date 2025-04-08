#ifndef BASEMAZE_H
#define BASEMAZE_H
#include <tuple>
#include <vector>
#include <QWidget>
#include <QObject>

class cell;

class BaseMaze
{


protected:
    enum obstacles{
        noObstacles=0,
        obstacle=1,
        entrance=2,
        exit=5,
    };
    virtual void connectionsPrint() = 0;
    virtual void createMaze() = 0;
    virtual bool mazeChecker() = 0;
    virtual bool wallFollowerMazeSolver() = 0;
    virtual bool recursiveMazeSolver() = 0;
    virtual bool deadEndFillingMazeSolver() = 0;
    std::vector<cell*> correctPath;
    virtual ~BaseMaze() = default;
    virtual cell& getCell(int x, int y, int z = 0) = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
    virtual int getDepth() const = 0;
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

//This division between connectionsTo and From is only done to optimize memory usage
//It does complicate things but, it's better optimized this way

class cell
{
public:
    std::vector<connection> connectionsTo;
    std::vector<connection*> connectionFrom;

    void setup(std::vector<std::vector<cell>>& cells,std::tuple<int,int> pos);
    void setup(std::vector<std::vector<std::vector<cell>>>& cells,std::array<int,3> pos);
};

#endif // BASEMAZE_H
