#ifndef THREEDMAZE_H
#define THREEDMAZE_H
#include "basemaze.h"
#include <tuple>
#include <vector>
#include <QWidget>
#include <QObject>

class ThreeDMaze : public BaseMaze
{
public:
    enum directions{
        left=0,
        up=1,
        above = 2,
        right=0,
        down=1,
        below = 2
    };

    ThreeDMaze(int x,int y, int z);

    virtual void connectionsPrint() override;

    virtual void createMaze() override;

    const std::vector<std::vector<std::vector<cell>>>& getMaze() const{
        return MazeStructure;
    }

    bool mazeChecker() override;
    std::array<int,3> getEntrancePos();

    virtual bool wallFollowerMazeSolver() override = 0;
    virtual bool recursiveMazeSolver() override;
    virtual bool recursiveMazeSolver(const int& tX,const int& tY,const int& tZ);
    virtual bool deadEndFillingMazeSolver() override = 0;   //I'm lazy, i DID not implement this algorithm in 3D, if ya really want it, do it yourself

    cell& getCell(int x, int y, int z) override {
        return MazeStructure[z][y][x];
    }

    int getWidth() const override {
        return MazeStructure[0][0].size();
    };
    int getHeight() const override {
        return MazeStructure[0].size();
    }
    int getDepth() const override {
        return MazeStructure.size();
    };
protected:
    std::vector<std::vector<std::vector<cell>>> MazeStructure;
    virtual bool recursiveSolvingFunction(std::vector<std::vector<std::vector<bool>>>& booleanGrid, const int z, const int i, const int y, const bool &store = 1); //This is a recursive backtracker function
    virtual bool recursiveSolvingFunction(std::vector<std::vector<std::vector<bool>>>& booleanGrid, const int z, const int j, const int i,const int& tX,const int& tY, const int& tZ);
    virtual void recursiveDiggingFunction(int z, int x, int y, std::vector<std::vector<std::vector<bool>>> &booleanGrid);
private:

};
#endif // THREEDMAZE_H
