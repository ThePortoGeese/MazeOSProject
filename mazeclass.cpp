#include "mazeclass.h"
#include <iostream>
mazeClass::mazeClass(int x,int y) {
    daMaze.resize(y,std::vector<cell>(x,cell()));
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            daMaze[i][j].setup(daMaze,std::make_tuple(i,j));
        }
    }
    setX(x);
    setY(y);
}

//Debugging Function that verifies if the Maze was created correctly
void mazeClass::connectionsPrint(){
    for(int i=0;i<(int)getMaze().size();i++){
        for(int y=0;y<(int)getMaze()[0].size();y++){
            std::cout<<"\nCell At Coordinate:"<<i<<y<<'\n';
            std::cout<<"Memory adress:\n";
            std::cout<<&getMaze()[i][y];
            std::cout<<"From Connections:\n";
            for(int k=0;k<(int)getMaze()[i][y].connectionFrom.size();k++){
                if(getMaze()[i][y].connectionFrom[k]==nullptr){
                    std::cout<<"Null\n";
                }
                else {
                    std::cout<<getMaze()[i][y].connectionFrom[k]->from;
                    std::cout<<"Obstacle: "<<getMaze()[i][y].connectionFrom[k]->obstacle<<'\n';
                }
            }
            std::cout<<"To Connections:";
            for(int k=0;k<(int)getMaze()[i][y].connectionsTo.size();k++){
                if(getMaze()[i][y].connectionsTo[k].to==nullptr){
                    std::cout<<"Null\n";
                }
                else {
                    std::cout<<getMaze()[i][y].connectionsTo[k].to;
                    std::cout<<"Obstacle: "<<getMaze()[i][y].connectionsTo[k].obstacle<<'\n';
                }
            }
        }
    }
}
void cell::setup(std::vector<std::vector<cell>>& cells,std::tuple<int,int> pos){
    //Determining if the cell has connections to it
    {

        if(std::get<1>(pos)>=1) cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)].connectionFrom.push_back(&cells[(int)std::get<0>(pos)][((int)std::get<1>(pos))-1].connectionsTo[0]);
        else cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)].connectionFrom.push_back(nullptr);

        if(std::get<0>(pos)>=1) cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)].connectionFrom.push_back(&cells[(int)std::get<0>(pos)-1][((int)std::get<1>(pos))].connectionsTo[1]);
        else cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)].connectionFrom.push_back(nullptr);


    }

    {
        //HORIZONTAL CONNECTION
        connection a;
        if(std::get<1>(pos)<(int)cells[0].size()-1){
            a.from=&cells[(int)std::get<0>(pos)][((int)std::get<1>(pos))];
            a.to=&cells[(int)std::get<0>(pos)][((int)std::get<1>(pos))+1];
        } else {
            a.from=nullptr;
            a.to=nullptr;
        }
        cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)].connectionsTo.push_back(a);
        //VERTICAL CONNECTION
        connection b;
        if(std::get<0>(pos)<(int)cells.size()-1){
            b.from=&cells[(int)std::get<0>(pos)][((int)std::get<1>(pos))];
            b.to=&cells[(int)std::get<0>(pos)+1][((int)std::get<1>(pos))];
        } else {
            b.from=nullptr;
            b.to=nullptr;
        }
        cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)].connectionsTo.push_back(b);
    }
}

void mazeClass::createMaze(){
    int entranceX;
    int entranceY;
    srand(time(0));
    switch(rand()%2){

    //Deciding if I want to randomly chose the column or the line
    case 0:
        //Randomly choose X
        entranceY=0;
        entranceX=rand()%daMaze.size();
        break;
    case 1:
        //Randomly choose X
        entranceX=0;
        entranceY=rand()%daMaze[0].size();
        break;
    }
    int exitX;
    int exitY;
    do{
        switch(rand()%2){

        //Deciding if I want to randomly chose the column or the line
        case 0:
            //Randomly choose X
            exitY=daMaze[0].size()-1;
            exitX=rand()%daMaze.size();
            break;
        case 1:
            //Randomly choose X
            exitX=daMaze.size()-1;
            exitY=rand()%daMaze[0].size();
            break;
        }
    } while(entranceY==exitY&&entranceX==exitX);
    for(int i=0;i<(int)daMaze[entranceX][entranceY].connectionFrom.size();i++){
        if(daMaze[entranceX][entranceY].connectionFrom[i]==nullptr){
            connection* outsideConnection=new connection();
            outsideConnection->to=&daMaze[entranceX][entranceY];
            outsideConnection->from=nullptr;
            outsideConnection->obstacle=MazeEnums::entrance;
            daMaze[entranceX][entranceY].connectionFrom[i]=outsideConnection;
            break;
        }
    }

    for(int i=0;i<(int)daMaze[exitX][exitY].connectionsTo.size();i++){
        if(daMaze[exitX][exitY].connectionsTo[i].to==nullptr){
            daMaze[exitX][exitY].connectionsTo[i].obstacle=MazeEnums::exit;
            break;
        }
    }
    //std::cout<<"Entrance X and Y: "<<entranceX<<" "<<entranceY<<'\n';
    //std::cout<<"Exit X and Y: "<<exitX<<" "<<exitY<<'\n';
    //connectionsPrint();
    std::vector<std::vector<bool>> booleanGrid(this->y(), std::vector<bool>(this->x(), false));
    this->recursiveDiggingFunction(entranceX,entranceY,booleanGrid);
}

void mazeClass::recursiveDiggingFunction(int x,int y, std::vector<std::vector<bool>>& booleanGrid){
    if(y<0||y>=this->y()||x<0||x>=this->x()) return;
    booleanGrid[y][x] = true;
    std::array<int,4> nums{1,2,3,4};
    for(int k=0;k<(int)daMaze[y][x].connectionsTo.size();k++){
        if(daMaze[y][x].connectionsTo[k].obstacle==MazeEnums::exit){
            return;
        }
    }

    std::random_shuffle(nums.begin(),nums.end());

    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(daMaze[y][x].connectionFrom[MazeEnums::right]!=nullptr&&daMaze[y][x].connectionFrom[MazeEnums::right]->obstacle!=2){
                if(!booleanGrid[y][x-1]){
                    daMaze[y][x].connectionFrom[MazeEnums::right]->obstacle=MazeEnums::noObstacles;
                    recursiveDiggingFunction(x-1 , y,booleanGrid);
                }
            }
            break;
        case 2:
            if(daMaze[y][x].connectionFrom[MazeEnums::up]!=nullptr&&daMaze[y][x].connectionFrom[MazeEnums::up]->obstacle!=2){
                if(!booleanGrid[y-1][x]){
                    daMaze[y][x].connectionFrom[MazeEnums::up]->obstacle=MazeEnums::noObstacles;
                    recursiveDiggingFunction(x, y-1,booleanGrid);
                }
            }
            break;
        case 3:
            if(daMaze[y][x].connectionsTo[MazeEnums::left].to!=nullptr){
                if(!booleanGrid[y][x+1]){
                    daMaze[y][x].connectionsTo[MazeEnums::left].obstacle=MazeEnums::noObstacles;
                    recursiveDiggingFunction( x+1, y,booleanGrid);
                }
            }
            break;
        case 4:
            if(daMaze[y][x].connectionsTo[MazeEnums::up].to!=nullptr){
                if(!booleanGrid[y+1][x]){
                    daMaze[y][x].connectionsTo[MazeEnums::up].obstacle=MazeEnums::noObstacles;
                    recursiveDiggingFunction(x, y+1,booleanGrid);
                }
            }
            break;
        }

    }

    return;
}



bool mazeClass::recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y) {
    if (i<0||i>=(int)daMaze.size()||y<0||y>=(int)daMaze[0].size()||booleanGrid[i][y]) {
        return false;
    }
    //std::cout<<"Path to: "<<i<< " "<<y<<'\n';
    for(int k=0;k<(int)daMaze[i][y].connectionsTo.size();k++){
        if (daMaze[i][y].connectionsTo[k].obstacle==5) {
            correctPath.push_back(&daMaze[i][y]);
            //std::cout<<"Found solution at: "<<i<<" "<<y<<'\n';
            return true;
        }

    }
    std::array<int,4> nums{1,2,3,4};

    booleanGrid[i][y] = true;
    std::random_shuffle(nums.begin(),nums.end());

    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(daMaze[i][y].connectionFrom[0]!=nullptr&&daMaze[i][y].connectionFrom[0]->obstacle==0){
                if(recursiveSolver(booleanGrid, i, y-1)) {
                    correctPath.push_back(&daMaze[i][y]);
                    return true;
                }
            }
            break;
        case 2:
            if(daMaze[i][y].connectionFrom[1]!=nullptr&&daMaze[i][y].connectionFrom[1]->obstacle==0){
                if(recursiveSolver(booleanGrid, i-1, y)) {
                    correctPath.push_back(&daMaze[i][y]);
                    return true;
                }
            }
            break;
        case 3:
            if(daMaze[i][y].connectionsTo[0].to!=nullptr&&daMaze[i][y].connectionsTo[0].obstacle==0){
                if(recursiveSolver(booleanGrid, i, y +1)) {
                    correctPath.push_back(&daMaze[i][y]);
                    return true;}
            }
            break;
        case 4:
            if(daMaze[i][y].connectionsTo[1].to!=nullptr&&daMaze[i][y].connectionsTo[1].obstacle==0){
                if(recursiveSolver(booleanGrid, i+1, y)) {
                    correctPath.push_back(&daMaze[i][y]);
                    return true;}
            }
            break;
        }

    }
    booleanGrid[i][y] = false;

    return false;
}
//Overload of solver operation to find path to cell at (tX, tY)
bool mazeClass::recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y,const int& tX,const int& tY) {
    if(i==tX&&y==tY){
        //Do whatever you wanna do with this path here
        return true;
    }

    if (i<0||i>=(int)daMaze.size()||y<0||y>=(int)daMaze[0].size()||booleanGrid[i][y]) {
        return false;
    }

    std::array<int,4> nums{1,2,3,4};

    booleanGrid[i][y] = true;
    std::random_shuffle(nums.begin(),nums.end());
    correctPath.push_back(&daMaze[i][y]);
    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(daMaze[i][y].connectionFrom[0]!=nullptr&&daMaze[i][y].connectionFrom[0]->obstacle==0){
                if(recursiveSolver(booleanGrid, i, y-1,tX,tY)) {
                    //Do whatever you wanna do with this path here
                    return true;
                }
            }
            break;
        case 2:
            if(daMaze[i][y].connectionFrom[1]!=nullptr&&daMaze[i][y].connectionFrom[1]->obstacle==0){
                if(recursiveSolver(booleanGrid, i-1, y,tX,tY)) {
                    //Do whatever you wanna do with this path here
                    return true;
                }
            }
            break;
        case 3:
            if(daMaze[i][y].connectionsTo[0].to!=nullptr&&daMaze[i][y].connectionsTo[0].obstacle==0){
                if(recursiveSolver(booleanGrid, i, y +1,tX,tY)) {
                    //Do whatever you wanna do with this path here
                    return true;}
            }
            break;
        case 4:
            if(daMaze[i][y].connectionsTo[1].to!=nullptr&&daMaze[i][y].connectionsTo[1].obstacle==0){
                if(recursiveSolver(booleanGrid, i+1, y,tX,tY)) {
                    //Do whatever you wanna do with this path here
                    return true;}
            }
            break;
        }

    }
    booleanGrid[i][y] = false;

    return false;
}

void mazeClass::mazeSolver() {
    if(correctPath.size()==0){ //why solve it again, is he stoopid
        std::vector<std::vector<bool>> booleanGrid(daMaze.size(), std::vector<bool>(daMaze[0].size(), false));
        int ix=-1,iy=-1;
        for(int i=0;i<(int)daMaze.size();i++){
            for(int k=0;k<(int)daMaze[i][0].connectionFrom.size();k++){
                if(daMaze[i][0].connectionFrom[k]!=nullptr){
                    if(daMaze[i][0].connectionFrom[k]->obstacle==2){
                        ix=i;
                        iy=0;
                    }
                }
            }
        }
        if(iy==-1){
            for(int i=0;i<(int)daMaze[0].size();i++){
                for(int k=0;k<(int)daMaze[0][i].connectionFrom.size();k++){
                    if(daMaze[0][i].connectionFrom[k]!=nullptr){
                        if(daMaze[0][i].connectionFrom[k]->obstacle==2){
                            ix=0;
                            iy=i;
                        }
                    }
                }
            }
        }

        //std::cout<<"Ix value: "<<ix<< " Iy value: "<<iy<<'\n';

        if(recursiveSolver(booleanGrid, ix, iy)){
                //std::cout<<"Returned True\n";
        } else {
            //std::cout<<"Returned Flase\n"
        }
    }
}

void mazeClass::mazeSolver(const int& tX,const int& tY) {
    if(correctPath.size()==0){ //why solve it again, is he stoopid
        std::vector<std::vector<bool>> booleanGrid(daMaze.size(), std::vector<bool>(daMaze[0].size(), false));
        int ix=-1,iy=-1;
        for(int i=0;i<(int)daMaze.size();i++){
            for(int k=0;k<(int)daMaze[i][0].connectionFrom.size();k++){
                if(daMaze[i][0].connectionFrom[k]!=nullptr){
                    if(daMaze[i][0].connectionFrom[k]->obstacle==2){
                        ix=i;
                        iy=0;
                    }
                }
            }
        }
        if(iy==-1){
            for(int i=0;i<(int)daMaze[0].size();i++){
                for(int k=0;k<(int)daMaze[0][i].connectionFrom.size();k++){
                    if(daMaze[0][i].connectionFrom[k]!=nullptr){
                        if(daMaze[0][i].connectionFrom[k]->obstacle==2){
                            ix=0;
                            iy=i;
                        }
                    }
                }
            }
        }

        //std::cout<<"Ix value: "<<ix<< " Iy value: "<<iy<<'\n';

        if(recursiveSolver(booleanGrid, ix, iy,tX,tY)){
            //std::cout<<"Returned True\n";
        } else {
            //std::cout<<"Returned Flase\n"
        }
    }
}
