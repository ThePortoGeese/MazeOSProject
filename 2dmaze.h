#ifndef TWODMAZE_H
#define TWODMAZE_H
#include "basemaze.h"
#include <tuple>
#include <vector>
#include <QWidget>
#include <QObject>


class TwoDMaze : public BaseMaze
{
public:
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

    TwoDMaze(int x,int y);

    virtual void connectionsPrint() override;

    virtual void createMaze() override;

    const std::vector<std::vector<cell>>& getMaze() const{
        return MazeStructure;
    }

    bool mazeChecker() override;
    std::tuple<int,int> getEntrancePos();

    virtual bool wallFollowerMazeSolver() override;
    virtual bool recursiveMazeSolver() override;
    virtual bool recursiveMazeSolver(const int& tX,const int& tY);
    virtual bool deadEndFillingMazeSolver() override;

    virtual cell& getCell(int x, int y, int z = 0) override {
        return MazeStructure[x][y];
    }

    int getWidth() const override {
        return MazeStructure[0].size();
    };
    int getHeight() const override {
        return MazeStructure.size();
    }
    int getDepth() const override {
        return -1;
    };
protected:
    std::vector<std::vector<cell>> MazeStructure;
    virtual bool recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y, const bool &store = 1); //This is a recursive backtracker function
    virtual bool recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y,const int& tX, const int& tY); //This is also a recursive backtracker function
    virtual void recursiveDiggingFunction(int x, int y, std::vector<std::vector<bool> > &booleanGrid);
private:

};
#endif // 2DMAZE_H
