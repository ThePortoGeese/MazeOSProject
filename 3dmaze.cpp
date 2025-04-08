#include "3dmaze.h"
#include <iostream>
#include <stack>
ThreeDMaze::ThreeDMaze(int x,int y,int z) {
    MazeStructure.resize(z,std::vector<std::vector<cell>>(y,std::vector<cell>(x,cell())));
    for(int k=0;k<getDepth();k++){
        for(int i=0;i<getHeight();i++){
            for(int j=0;j<getWidth();j++){
                MazeStructure[k][i][j].setup(MazeStructure,std::array<int,3>{ k , i , j});
            }
        }
    }
}

//Debugging Function that verifies if the Maze was created correctly
void ThreeDMaze::connectionsPrint(){
    for(int k=0;k<getDepth();k++){
        for(int i=0;i<(int)getHeight();i++){
            for(int y=0;y<(int)getWidth();y++){
                std::cout<<"\nCell At Coordinate:"<<i<<y<<'\n';
                std::cout<<"Memory adress:\n";
                std::cout<<&getMaze()[i][y];
                std::cout<<"From Connections:\n";
                for(int k=0;k<(int)getMaze()[k][i][y].connectionFrom.size();k++){
                    if(getMaze()[k][i][y].connectionFrom[k]==nullptr){
                        std::cout<<"Null\n";
                    }
                    else {
                        std::cout<<getMaze()[k][i][y].connectionFrom[k]->from;
                        std::cout<<"Obstacle: "<<getMaze()[k][i][y].connectionFrom[k]->obstacle<<'\n';
                    }
                }
                std::cout<<"To Connections:";
                for(int k=0;k<(int)getMaze()[k][i][y].connectionsTo.size();k++){
                    if(getMaze()[k][i][y].connectionsTo[k].to==nullptr){
                        std::cout<<"Null\n";
                    }
                    else {
                        std::cout<<getMaze()[k][i][y].connectionsTo[k].to;
                        std::cout<<"Obstacle: "<<getMaze()[k][i][y].connectionsTo[k].obstacle<<'\n';
                    }
                }
            }
        }
    }
}
void cell::setup(std::vector<std::vector<std::vector<cell>>>& cells,std::array<int,3> pos){
    //Determining if the cell has connections to it
    {
        //Pos array is stored like this: Depth, Height, Width (z,y,x)


        if(std::get<2>(pos)>=1) cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][(int)std::get<2>(pos)].connectionFrom.push_back(&cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][((int)std::get<2>(pos))-1].connectionsTo[ThreeDMaze::left]);
        else cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][(int)std::get<2>(pos)].connectionFrom.push_back(nullptr);

        if(std::get<1>(pos)>=1) cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][(int)std::get<2>(pos)].connectionFrom.push_back(&cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)-1][((int)std::get<2>(pos))].connectionsTo[ThreeDMaze::up]);
        else cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][(int)std::get<2>(pos)].connectionFrom.push_back(nullptr);

        if(std::get<0>(pos)>=1) cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][(int)std::get<2>(pos)].connectionFrom.push_back(&cells[(int)std::get<0>(pos)-1][(int)std::get<1>(pos)][((int)std::get<2>(pos))].connectionsTo[ThreeDMaze::above]);
        else cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][(int)std::get<2>(pos)].connectionFrom.push_back(nullptr);

    }

    {
        //HORIZONTAL CONNECTION
        connection a;
        if(std::get<2>(pos)<(int)cells[0][0].size()-1){
            a.from=&cells[(int)std::get<0>(pos)][((int)std::get<1>(pos))][((int)std::get<2>(pos))];
            a.to=&cells[(int)std::get<0>(pos)][((int)std::get<1>(pos))+1][((int)std::get<2>(pos))];
        } else {
            a.from=nullptr;
            a.to=nullptr;
        }
        cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][(int)std::get<2>(pos)].connectionsTo.push_back(a);
        //VERTICAL CONNECTION
        connection b;
        if(std::get<1>(pos)<(int)cells[0].size()-1){
            b.from=&cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][((int)std::get<2>(pos))];
            b.to=&cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)+1][((int)std::get<2>(pos))];
        } else {
            b.from=nullptr;
            b.to=nullptr;
        }
        cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][(int)std::get<2>(pos)].connectionsTo.push_back(b);
        //DEPTH CONNECTION
        connection c;
        if(std::get<0>(pos)<(int)cells.size()-1){
            c.from=&cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][((int)std::get<2>(pos))];
            c.to=&cells[(int)std::get<0>(pos)+1][(int)std::get<1>(pos)][((int)std::get<2>(pos))];
        } else {
            c.from=nullptr;
            c.to=nullptr;
        }
        cells[(int)std::get<0>(pos)][(int)std::get<1>(pos)][(int)std::get<2>(pos)].connectionsTo.push_back(b);
    }
}

void ThreeDMaze::createMaze(){
    int entranceX = 0;
    int entranceY = 0;
    int entranceZ = 0;

    srand(time(0));
    switch(rand()%3){

    //For this to be a cell connected to the outside, at least one of the position parameters needs to be 0 or param.size()-1
    //To simplify and try to amplify distance between entrance and exits, I made it so entrances could only be in connectionsFrom
    //And exits in ConnectionsTo
    //This ONLY applies to randomly generated mazes

    //Deciding if I want to randomly chose the column or the line or the depth
    case 0:
        //Randomly choose Height
        switch(rand()%2){
        case 0:
            entranceX=rand()%MazeStructure[0][0].size();
            break;
        case 1:
            entranceZ=rand()%MazeStructure.size();
            break;
        }
        entranceY=rand()%MazeStructure[0].size();
        break;
    case 1:
        //Randomly choose Width
        switch(rand()%2){
        case 0:
            entranceY=rand()%MazeStructure[0].size();
            break;
        case 1:
            entranceZ=rand()%MazeStructure.size();
            break;
        }
        entranceX=rand()%MazeStructure[0][0].size();
        break;
    case 2:
        //Randomly choose Depth
        switch(rand()%2){
        case 0:
            entranceX=rand()%MazeStructure[0][0].size();
            break;
        case 1:
            entranceY=rand()%MazeStructure[0].size();
            break;
        }
        entranceZ=rand()%MazeStructure.size();
        break;
    }
    int exitZ = MazeStructure.size()-1;;
    int exitY = exitZ=MazeStructure[0].size()-1;;
    int exitX = exitZ=MazeStructure[0][0].size()-1;;
    do{
        switch(rand()%3){

        //Deciding if I want to randomly chose the column or the line
        case 0:
            //Randomly choose X
            switch(rand()%3){
            case 0:
                exitY = rand()%MazeStructure[0].size();
                break;
            case 1:
                exitZ=rand()%MazeStructure.size();
                break;
            }
            exitX=rand()%MazeStructure[0][0].size();
            break;
        case 1:
            //Randomly choose Y
            switch(rand()%3){
            case 0:
                exitZ = rand()%MazeStructure.size();
                break;
            case 1:
                exitX=rand()%MazeStructure[0][0].size();
                break;
            }
            exitY=rand()%MazeStructure[0].size();
            break;
        case 2:
            //Randomly choose Z
            switch(rand()%3){
            case 0:
                exitY = rand()%MazeStructure[0].size();
                break;
            case 1:
                exitX=rand()%MazeStructure[0][0].size();
                break;
            }

            exitZ=rand()%MazeStructure.size();
            break;

        }
    } while(entranceY==exitY&&entranceX==exitX && entranceZ != exitZ);
    for(int i=0;i<(int)MazeStructure[entranceZ][entranceY][entranceX].connectionFrom.size();i++){
        if(MazeStructure[entranceZ][entranceY][entranceX].connectionFrom[i]==nullptr){
            connection* outsideConnection=new connection();
            outsideConnection->to=&MazeStructure[entranceZ][entranceY][entranceX];
            outsideConnection->from=nullptr;
            outsideConnection->obstacle=entrance;
            MazeStructure[entranceZ][entranceY][entranceX].connectionFrom[i]=outsideConnection;
            break;
        }
    }

    for(int i=0;i<(int)MazeStructure[exitZ][exitY][exitX].connectionsTo.size();i++){
        if(MazeStructure[exitZ][exitY][exitX].connectionsTo[i].to==nullptr){
            MazeStructure[exitZ][exitY][exitX].connectionsTo[i].obstacle=exit;
            break;
        }
    }
    //std::cout<<"Entrance X and Y: "<<entranceX<<" "<<entranceY<<'\n';
    //std::cout<<"Exit X and Y: "<<exitX<<" "<<exitY<<'\n';
    //connectionsPrint();
    std::vector<std::vector<std::vector<bool>>> booleanGrid(getDepth(),std::vector<std::vector<bool>>(this->getHeight(), std::vector<bool>(this->getWidth(), false)));
    this->recursiveDiggingFunction(entranceZ,entranceY,entranceX,booleanGrid);
}

void ThreeDMaze::recursiveDiggingFunction(int z,int y,int x, std::vector<std::vector<std::vector<bool>>>& booleanGrid){
    if(y<0||y>=this->getHeight()||x<0||x>=this->getWidth()) return;
    booleanGrid[z][y][x] = true;
    std::array<int,6> nums{1,2,3,4,5,6};
    for(int k=0;k<(int)getCell(x,y,z).connectionsTo.size();k++){
        if(getCell(x,y,z).connectionsTo[k].obstacle==exit){
            return;
        }
    }

    std::random_shuffle(nums.begin(),nums.end());

    //Tries to dig through all directions

    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(getCell(x,y,z).connectionFrom[left]!=nullptr&&getCell(x,y,z).connectionFrom[left]->obstacle!=2){
                if(!booleanGrid[z][y][x-1]){
                    getCell(x,y,z).connectionFrom[left]->obstacle=noObstacles;
                    recursiveDiggingFunction(z,x-1 , y,booleanGrid);
                }
            }
            break;
        case 2:
            if(getCell(x,y,z).connectionFrom[up]!=nullptr&&getCell(x,y,z).connectionFrom[up]->obstacle!=2){
                if(!booleanGrid[z][y-1][x]){
                    getCell(x,y,z).connectionFrom[up]->obstacle=noObstacles;
                    recursiveDiggingFunction(z,x, y-1,booleanGrid);
                }
            }
            break;
        case 3:
            if(getCell(x,y,z).connectionFrom[above]!=nullptr&&getCell(x,y,z).connectionFrom[above]->obstacle!=2){
                if(!booleanGrid[z-1][y][x]){
                    getCell(x,y,z).connectionFrom[above]->obstacle=noObstacles;
                    recursiveDiggingFunction(z-1,x, y,booleanGrid);
                }
            }
            break;
        case 4:
            if(getCell(x,y,z).connectionsTo[right].to!=nullptr){
                if(!booleanGrid[z][y][x+1]){
                    getCell(x,y,z).connectionsTo[right].obstacle=noObstacles;
                    recursiveDiggingFunction(z,x+1, y,booleanGrid);
                }
            }
            break;
        case 5:
            if(getCell(x,y,z).connectionsTo[down].to!=nullptr){
                if(!booleanGrid[z][y+1][x]){
                    getCell(x,y,z).connectionsTo[down].obstacle=noObstacles;
                    recursiveDiggingFunction(z,x, y+1,booleanGrid);
                }
            }
            break;

        case 6:
            if(getCell(x,y,z).connectionsTo[below].to!=nullptr){
                if(!booleanGrid[z+1][y][x]){
                    getCell(x,y,z).connectionsTo[below].obstacle=noObstacles;
                    recursiveDiggingFunction(z+1,x, y,booleanGrid);
                }
            }
            break;
        }
    }

    return;
}

std::array<int,3> ThreeDMaze::getEntrancePos(){
    int ix=-1,iy=-1, iz=-1;
    for(int z=0;z<getDepth();z++){
        for(int i=0;i<getHeight();i++){
            for(int k=0;k<(int)getWidth();k++){
                if(i==0||k==0||z==0){
                    for(int l=0;l<(int)MazeStructure[z][i][k].connectionFrom.size();l++){
                        if(MazeStructure[z][i][k].connectionFrom[l]->obstacle==entrance){
                            iy=i;
                            ix = k;
                            iz = z;
                        }
                    }
                } else if(i==getHeight()-1||k==getDepth()-1||z==getWidth()-1){
                    for(int l=0;l<(int)MazeStructure[z][i][k].connectionsTo.size();l++){
                        if(MazeStructure[z][i][k].connectionsTo[l].obstacle==entrance){
                            iy=i;
                            ix=k;
                            iz = z;
                        }
                    }
                }
            }
        }
    }
    return {iz,iy,ix};
}

bool ThreeDMaze::recursiveMazeSolver() {
    std::vector<std::vector<std::vector<bool>>> booleanGrid(getDepth(), std::vector<std::vector<bool>>(getHeight(),std::vector<bool>(getWidth(), false)));
    std::array<int,3> a = getEntrancePos();

    //std::cout<<"Ix value: "<<ix<< " Iy value: "<<iy<<'\n';

    if(recursiveSolvingFunction(booleanGrid, std::get<0>(a), std::get<1>(a),std::get<2>(a)),1){
        std::reverse(correctPath.begin(),correctPath.end());
        return 1;
    } else {
        return 0;
    }
}

bool ThreeDMaze::recursiveSolvingFunction(std::vector<std::vector<std::vector<bool>>>& booleanGrid, const int z, const int i, const int j, const bool& store) {

    if (i<0||i>=(int)getHeight()||j<0||j>=(int)getWidth()||z<0||z>=getDepth()||booleanGrid[z][i][j]) {
        return false;
    }
    //std::cout<<"Path to: "<<i<< " "<<y<<'\n';
    for(int k=0;k<(int)MazeStructure[z][i][j].connectionsTo.size();k++){
        if (MazeStructure[z][i][j].connectionsTo[k].obstacle==exit) {
            if(store)correctPath.push_back(&MazeStructure[z][i][j]);
            //std::cout<<"Found solution at: "<<i<<" "<<y<<'\n';
            return true;
        }
    }

    for(int k=0;k<(int)MazeStructure[z][i][j].connectionFrom.size();k++){
        if (MazeStructure[z][i][j].connectionFrom[k] && MazeStructure[z][i][j].connectionFrom[k]->obstacle==exit) {
            if(store)correctPath.push_back(&MazeStructure[z][i][j]);
            //std::cout<<"Found solution at: "<<i<<" "<<y<<'\n';
            return true;
        }
    }


    booleanGrid[z][i][j] = true;
    std::array<int,6> nums{1,2,3,4,5,6};

    for(int k=0;k<6;k++){
        switch(nums[k]){
        case 1:
            if(getCell(j,i,z).connectionFrom[left]!=nullptr&&getCell(j,i,z).connectionFrom[left]->obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z,i, j-1,store)) {
                    if(store)correctPath.push_back(&MazeStructure[z][i][j]);
                    return true;
                }
            }
            break;
        case 2:
            if(getCell(j,i,z).connectionFrom[up]!=nullptr&&getCell(j,i,z).connectionFrom[up]->obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z,i-1, j,store)) {
                    if(store)correctPath.push_back(&MazeStructure[z][i][j]);
                    return true;
                }
            }
            break;
        case 3:
            if(getCell(j,i,z).connectionFrom[above]!=nullptr&&getCell(j,i,z).connectionFrom[above]->obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z-1,i, j,store)) {
                    if(store)correctPath.push_back(&MazeStructure[z][i][j]);
                    return true;
                }
            }
            break;
        case 4:
            if(getCell(j,i,z).connectionsTo[right].to!=nullptr&&getCell(j,i,z).connectionsTo[right].obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z,i, j+1,store)) {
                    if(store)correctPath.push_back(&MazeStructure[z][i][j]);
                    return true;
                }
            }
            break;
        case 5:
            if(getCell(j,i,z).connectionsTo[down].to!=nullptr&&getCell(j,i,z).connectionsTo[down].obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z,i+1, j,store)) {
                    if(store)correctPath.push_back(&MazeStructure[z][i][j]);
                    return true;
                }
            }
            break;

        case 6:
            if(getCell(j,i,z).connectionsTo[below].to!=nullptr&&getCell(j,i,z).connectionsTo[below].obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z+1,i, j,store)) {
                    if(store)correctPath.push_back(&MazeStructure[z][i][j]);
                    return true;
                }
            }
            break;
        }
    }

    return false;
}


bool ThreeDMaze::recursiveMazeSolver(const int& tX,const int& tY, const int& tZ) {
    if(correctPath.size()!=0) {
        correctPath.clear();
    }
     std::vector<std::vector<std::vector<bool>>> booleanGrid(getDepth(), std::vector<std::vector<bool>>(getHeight(),std::vector<bool>(getWidth(), false)));
    std::array<int,3> a = getEntrancePos();

    //std::cout<<"Ix value: "<<ix<< " Iy value: "<<iy<<'\n';

    if(recursiveSolvingFunction(booleanGrid, std::get<0>(a), std::get<1>(a),std::get<2>(a),tX,tY,tZ)){
        return true;
    } else {
        return false;
    }
}

//Overload of solver operation to find path to cell at (tX, tY)
bool ThreeDMaze::recursiveSolvingFunction(std::vector<std::vector<std::vector<bool>>>& booleanGrid, const int z, const int j, const int i,const int& tX,const int& tY, const int& tZ) {
    if (i<0||i>=(int)getHeight()||j<0||j>=(int)getWidth()||z<0||z>=getDepth()||booleanGrid[z][i][j]) {
        return false;
    }
    //std::cout<<"Path to: "<<i<< " "<<y<<'\n';

    if(j==tY&&i==tX&&z==tZ){
        //Do whatever you wanna do with this path here
        return true;
    }


    booleanGrid[z][i][j] = true;
    std::array<int,6> nums{1,2,3,4,5,6};

    for(int k=0;k<6;k++){
        switch(nums[k]){
        case 1:
            if(getCell(j,i,z).connectionFrom[left]!=nullptr&&getCell(j,i,z).connectionFrom[left]->obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z,i, j-1,tX,tY,tZ)) {

                    return true;
                }
            }
            break;
        case 2:
            if(getCell(j,i,z).connectionFrom[up]!=nullptr&&getCell(j,i,z).connectionFrom[up]->obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z,i-1, j,tX,tY,tZ)) {

                    return true;
                }
            }
            break;
        case 3:
            if(getCell(j,i,z).connectionFrom[above]!=nullptr&&getCell(j,i,z).connectionFrom[above]->obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z-1,i, j,tX,tY,tZ)) {

                    return true;
                }
            }
            break;
        case 4:
            if(getCell(j,i,z).connectionsTo[right].to!=nullptr&&getCell(j,i,z).connectionsTo[right].obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z,i, j+1,tX,tY,tZ)) {

                    return true;
                }
            }
            break;
        case 5:
            if(getCell(j,i,z).connectionsTo[down].to!=nullptr&&getCell(j,i,z).connectionsTo[down].obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z,i+1, j)) {

                    return true;
                }
            }
            break;

        case 6:
            if(getCell(j,i,z).connectionsTo[below].to!=nullptr&&getCell(j,i,z).connectionsTo[below].obstacle==noObstacles){
                if(recursiveSolvingFunction(booleanGrid, z+1,i, j)) {

                    return true;
                }
            }
            break;
        }
    }

    return false;
}

//This function ONLY checks the maze, it does NOT store the correct path anywhere, could be useful
bool ThreeDMaze::mazeChecker() {
    std::vector<std::vector<std::vector<bool>>> booleanGrid(getDepth(), std::vector<std::vector<bool>>(getHeight(),std::vector<bool>(getWidth(), false)));
    std::array<int,3> a = getEntrancePos();

    //std::cout<<"Ix value: "<<ix<< " Iy value: "<<iy<<'\n';

    if(recursiveSolvingFunction(booleanGrid, std::get<0>(a), std::get<1>(a),std::get<2>(a)),0){
        std::reverse(correctPath.begin(),correctPath.end());
        return 1;
    } else {
        return 0;
    }
}

