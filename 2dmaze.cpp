#include "2dmaze.h"
#include <iostream>
#include <stack>
TwoDMaze::TwoDMaze(int y,int x) {
    MazeStructure.resize(y,std::vector<cell>(x,cell()));
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            MazeStructure[i][j].setup(MazeStructure,std::make_tuple(i,j));
        }
    }
}

//Debugging Function that verifies if the Maze was created correctly
void TwoDMaze::connectionsPrint(){
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

void TwoDMaze::createMaze(){
    int entranceX;
    int entranceY;
    srand(time(0));

    //For this to be a cell connected to the outside, at least one of the position parameters needs to be 0 or param.size()-1
    //To simplify and try to amplify distance between entrance and exits, I made it so entrances could only be in connectionsFrom
    //And exits in ConnectionsTo
    //This ONLY applies to randomly generated mazes

    switch(rand()%2){

    //Deciding if I want to randomly chose the column or the line
    case 0:
        //Randomly choose X
        entranceY=0;
        entranceX=rand()%MazeStructure.size();
        break;
    case 1:
        //Randomly choose X
        entranceX=0;
        entranceY=rand()%MazeStructure[0].size();
        break;
    }
    int exitX = -1;
    int exitY = -1;
    do{
        switch(rand()%2){

        //Deciding if I want to randomly chose the column or the line
        case 0:
            //Randomly choose X
            exitY=MazeStructure[0].size()-1;
            exitX=rand()%MazeStructure.size();
            break;
        case 1:
            //Randomly choose X
            exitX=MazeStructure.size()-1;
            exitY=rand()%MazeStructure[0].size();
            break;
        }
    } while(entranceY==exitY&&entranceX==exitX);
    for(int i=0;i<(int)MazeStructure[entranceX][entranceY].connectionFrom.size();i++){
        if(MazeStructure[entranceX][entranceY].connectionFrom[i]==nullptr){
            connection* outsideConnection=new connection();
            outsideConnection->to=&MazeStructure[entranceX][entranceY];
            outsideConnection->from=nullptr;
            outsideConnection->obstacle=entrance;
            MazeStructure[entranceX][entranceY].connectionFrom[i]=outsideConnection;
            break;
        }
    }

    for(int i=0;i<(int)MazeStructure[exitX][exitY].connectionsTo.size();i++){
        if(MazeStructure[exitX][exitY].connectionsTo[i].to==nullptr){
            MazeStructure[exitX][exitY].connectionsTo[i].obstacle=exit;
            break;
        }
    }
    //std::cout<<"Entrance X and Y: "<<entranceX<<" "<<entranceY<<'\n';
    //std::cout<<"Exit X and Y: "<<exitX<<" "<<exitY<<'\n';
    //connectionsPrint();
    std::vector<std::vector<bool>> booleanGrid(this->getHeight(), std::vector<bool>(this->getWidth(), false));
    this->recursiveDiggingFunction(entranceY,entranceX,booleanGrid);
}

void TwoDMaze::recursiveDiggingFunction(int y,int x, std::vector<std::vector<bool>>& booleanGrid){
    if(y<0||y>=this->getHeight()||x<0||x>=this->getWidth()) return;
    booleanGrid[y][x] = true;
    std::array<int,4> nums{1,2,3,4};
    for(int k=0;k<(int)MazeStructure[y][x].connectionsTo.size();k++){
        if(MazeStructure[y][x].connectionsTo[k].obstacle==exit){
            return;
        }
    }

    std::random_shuffle(nums.begin(),nums.end());

    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(MazeStructure[y][x].connectionFrom[left]!=nullptr&&MazeStructure[y][x].connectionFrom[left]->obstacle!=2){
                if(!booleanGrid[y][x-1]){
                    MazeStructure[y][x].connectionFrom[left]->obstacle=noObstacles;
                    recursiveDiggingFunction(y , x-1,booleanGrid);
                }
            }
            break;
        case 2:
            if(MazeStructure[y][x].connectionFrom[up]!=nullptr&&MazeStructure[y][x].connectionFrom[up]->obstacle!=2){
                if(!booleanGrid[y-1][x]){
                    MazeStructure[y][x].connectionFrom[up]->obstacle=noObstacles;
                    recursiveDiggingFunction(y-1, x,booleanGrid);
                }
            }
            break;
        case 3:
            if(MazeStructure[y][x].connectionsTo[right].to!=nullptr){
                if(!booleanGrid[y][x+1]){
                    MazeStructure[y][x].connectionsTo[right].obstacle=noObstacles;
                    recursiveDiggingFunction( y, x+1,booleanGrid);
                }
            }
            break;
        case 4:
            if(MazeStructure[y][x].connectionsTo[down].to!=nullptr){
                if(!booleanGrid[y+1][x]){
                    MazeStructure[y][x].connectionsTo[down].obstacle=noObstacles;
                    recursiveDiggingFunction(y+1, x,booleanGrid);
                }
            }
            break;
        }

    }

    return;
}

std::tuple<int,int> TwoDMaze::getEntrancePos(){
    int ix=-1,iy=-1;

    for(int i=0;i<getHeight();i++){
        for(int k=0;k<getWidth();k++){
            if(i==0||k==0){
                for(int l=0;l<(int)MazeStructure[i][k].connectionFrom.size();l++){
                    if(MazeStructure[i][k].connectionFrom[l] && MazeStructure[i][k].connectionFrom[l]->obstacle==entrance){
                        iy=i;
                        ix = k;
                        return std::tuple<int,int>(iy,ix);
                    }
                }
            } else if(i==getHeight()-1||k==getDepth()-1){
                for(int l=0;l<(int)MazeStructure[i][k].connectionsTo.size();l++){
                    if(MazeStructure[i][k].connectionsTo[l].obstacle==entrance){
                        iy=i;
                        ix=k;
                        return std::tuple<int,int>(iy,ix);
                    }
                }
            }
        }
    }

    return std::tuple<int,int>(iy,ix);
}

bool TwoDMaze::recursiveMazeSolver() {
    std::vector<std::vector<bool>> booleanGrid(MazeStructure.size(), std::vector<bool>(MazeStructure[0].size(), false));
    std::tuple<int,int> a = getEntrancePos();

    //std::cout<<"Ix value: "<<ix<< " Iy value: "<<iy<<'\n';

    if(recursiveSolvingFunction(booleanGrid, std::get<0>(a), std::get<1>(a),1)){
        std::reverse(correctPath.begin(),correctPath.end());
        return 1;
    } else {
        return 0;
    }
}

bool TwoDMaze::recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int j, const bool& store) {
    if (i<0||i>=(int)MazeStructure.size()||j<0||j>=(int)MazeStructure[0].size()||booleanGrid[i][j]) {
        return false;
    }
    //std::cout<<"Path to: "<<i<< " "<<y<<'\n';
    for(int k=0;k<(int)MazeStructure[i][j].connectionsTo.size();k++){
        if (MazeStructure[i][j].connectionsTo[k].obstacle==exit) {
            if(store)correctPath.push_back(&MazeStructure[i][j]);
            //std::cout<<"Found solution at: "<<i<<" "<<y<<'\n';
            return true;
        }
    }

    for(int k=0;k<(int)MazeStructure[i][j].connectionFrom.size();k++){
        if (MazeStructure[i][j].connectionFrom[k] && MazeStructure[i][j].connectionFrom[k]->obstacle==exit) {
            if(store)correctPath.push_back(&MazeStructure[i][j]);
            //std::cout<<"Found solution at: "<<i<<" "<<y<<'\n';
            return true;
        }
    }

    std::array<int,4> nums{1,2,3,4};

    booleanGrid[i][j] = true;
    std::random_shuffle(nums.begin(),nums.end());
    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(MazeStructure[i][j].connectionFrom[left]!=nullptr&&MazeStructure[i][j].connectionFrom[left]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j-1,store)) {
                    if(store)correctPath.push_back(&MazeStructure[i][j]);
                    return true;
                }
            }
            break;
        case 2:
            if(MazeStructure[i][j].connectionFrom[up]!=nullptr&&MazeStructure[i][j].connectionFrom[up]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i-1, j,store)) {
                    if(store)correctPath.push_back(&MazeStructure[i][j]);
                    return true;
                }
            }
            break;
        case 3:
            if(MazeStructure[i][j].connectionsTo[right].to!=nullptr&&MazeStructure[i][j].connectionsTo[right].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j +1,store)) {
                    if(store)correctPath.push_back(&MazeStructure[i][j]);
                    return true;}
            }
            break;
        case 4:
            if(MazeStructure[i][j].connectionsTo[down].to!=nullptr&&MazeStructure[i][j].connectionsTo[down].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i+1, j,store)) {
                    if(store)correctPath.push_back(&MazeStructure[i][j]);
                    return true;}
            }
            break;
        }
    }

    return false;
}


bool TwoDMaze::recursiveMazeSolver(const int& tY,const int& tX) {
    if(correctPath.size()!=0) {
        correctPath.clear();
    }
    std::vector<std::vector<bool>> booleanGrid(MazeStructure.size(), std::vector<bool>(MazeStructure[0].size(), false));
    std::tuple<int,int> a = getEntrancePos();

    //std::cout<<"Ix value: "<<ix<< " Iy value: "<<iy<<'\n';

    if(recursiveSolvingFunction(booleanGrid, std::get<0>(a), std::get<1>(a),tY,tX)){
        return true;
    } else {
        return false;
    }
}

//Overload of solver operation to find path to cell at (tX, tY)
bool TwoDMaze::recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int j,const int& tY,const int& tX) {
    if(i==tY&&j==tX){
        //Do whatever you wanna do with this path here
        return true;
    }

    if (i<0||i>=(int)MazeStructure.size()||j<0||j>=(int)MazeStructure[0].size()||booleanGrid[i][j]) {
        return false;
    }

    std::array<int,4> nums{1,2,3,4};

    booleanGrid[i][j] = true;
    std::random_shuffle(nums.begin(),nums.end());
    correctPath.push_back(&MazeStructure[i][j]);
    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(MazeStructure[i][j].connectionFrom[left]!=nullptr&&MazeStructure[i][j].connectionFrom[left]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j-1,tY,tX)) {
                    //Do whatever you wanna do with this path here
                    return true;
                }
            }
            break;
        case 2:
            if(MazeStructure[i][j].connectionFrom[up]!=nullptr&&MazeStructure[i][j].connectionFrom[up]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i-1, j,tY,tX)) {
                    //Do whatever you wanna do with this path here
                    return true;
                }
            }
            break;
        case 3:
            if(MazeStructure[i][j].connectionsTo[right].to!=nullptr&&MazeStructure[i][j].connectionsTo[right].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j +1,tY,tX)) {
                    //Do whatever you wanna do with this path here
                    return true;}
            }
            break;
        case 4:
            if(MazeStructure[i][j].connectionsTo[down].to!=nullptr&&MazeStructure[i][j].connectionsTo[down].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i+1, j,tY,tX)) {
                    //Do whatever you wanna do with this path here
                    return true;}
            }
            break;
        }
    }

    return false;
}

bool TwoDMaze::wallFollowerMazeSolver() {

    correctPath.clear();
    std::tuple<int,int> indices = getEntrancePos();

    //std::cout<<"Ix value: "<<ix<< " Iy value: "<<iy<<'\n';
    /*switch(rand()%2){

    //Chooses if it follows the Right or Left direction
    case 0:
        dir = 'R';
        break;
    case 1:
        dir = 'L';
        break;
    }*/
    enum MoveDir { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 };
    MoveDir direction = RIGHT;
    cell* currentCell = &MazeStructure[std::get<0>(indices)][std::get<1>(indices)];

    {
        for (int conn = 0; (int)currentCell->connectionsTo.size()>conn;conn++) {
            if (currentCell->connectionsTo[conn].obstacle == exit) {
                correctPath.push_back(currentCell);
                return true; // Solução encontrada!
            }
        }

        for (int conn = 0; (int)currentCell->connectionFrom.size()>conn;conn++) {
            if (currentCell->connectionFrom[conn] && currentCell->connectionFrom[conn]->obstacle == exit) {
                correctPath.push_back(currentCell);
                return true; // Solução encontrada!
            }
        }
    }

    while (true) {

        cell *nextCell = nullptr;

        // The Program tries to turn left first
        MoveDir leftDir = static_cast<MoveDir>((direction + 3) % 4);

        if (leftDir <= UP) { //Since half of the connections are stored in different places, I need to do this
            if (currentCell->connectionFrom[leftDir] && currentCell->connectionFrom[leftDir]->obstacle == noObstacles) {
                direction = leftDir;
                nextCell = currentCell->connectionFrom[leftDir]->from;
            }
        } else { // Conexões para direita e baixo estão em connectionsTo
            if (currentCell->connectionsTo[leftDir - 2].to && currentCell->connectionsTo[leftDir - 2].obstacle == noObstacles) {
                direction = leftDir;
                nextCell = currentCell->connectionsTo[leftDir - 2].to;
            }
        }

        // Tries to continue moving
        if (!nextCell) {
            if (direction <= UP) { // Same as thing as before
                if (currentCell->connectionFrom[direction] && currentCell->connectionFrom[direction]->obstacle == noObstacles) {
                    nextCell = currentCell->connectionFrom[direction]->from;
                }
            } else { // Same thing as before
                if (currentCell->connectionsTo[direction - 2].to && currentCell->connectionsTo[direction - 2].obstacle == noObstacles) {
                    nextCell = currentCell->connectionsTo[direction - 2].to;
                }
            }
        }

        // Tries to turn right
        if (!nextCell) {
            MoveDir rightDir = static_cast<MoveDir>((direction + 1) % 4);
            if (rightDir <= UP) {
                if (currentCell->connectionFrom[rightDir] && currentCell->connectionFrom[rightDir]->obstacle == noObstacles) {
                    direction = rightDir;
                    nextCell = currentCell->connectionFrom[rightDir]->from;
                }
            } else {
                if (currentCell->connectionsTo[rightDir - 2].to && currentCell->connectionsTo[rightDir - 2].obstacle == noObstacles) {
                    direction = rightDir;
                    nextCell = currentCell->connectionsTo[rightDir - 2].to;
                }
            }
        }

        // Turns Back, which means this was a dead end, therefore, I will mark it as true in the boolean grid
        if (!nextCell) {
            direction = static_cast<MoveDir>((direction + 2) % 4);
            if (direction <= UP) { // Esquerda/Cima -> connectionFrom
                nextCell = currentCell->connectionFrom[direction] ? currentCell->connectionFrom[direction]->from : nullptr;
            } else { // Direita/Baixo -> connectionsTo
                nextCell = currentCell->connectionsTo[direction - 2].to ? currentCell->connectionsTo[direction - 2].to : nullptr;
            }

        }

        // Se encontrou um próximo passo, avança
        if (nextCell) {
            correctPath.push_back(currentCell);
            //tempPathHolder.push_back(std::get<1>(indices),std::get<0>(indices),direction);
            currentCell = nextCell;

            // Verifica se chegou à saída
            for (const auto &conn : currentCell->connectionsTo) {
                if (conn.obstacle == exit) {
                    correctPath.push_back(currentCell);
                    return true; // Solução encontrada!
                }
            }

            for (const auto &conn : currentCell->connectionFrom) {
                if (conn && conn->obstacle == exit) {
                    correctPath.push_back(currentCell);
                    return true; // Solução encontrada!
                }
            }

            if (direction == LEFT) {
                std::get<1>(indices)--; // Move para a esquerda (diminuindo a coluna)
            } else if (direction == UP) {
                std::get<0>(indices)--; // Move para cima (diminuindo a linha)
            } else if (direction == RIGHT) {
                std::get<1>(indices)++; // Move para a esquerda (diminuindo a coluna)
            } else if (direction == DOWN) {
                std::get<0>(indices)++; // Move para cima (diminuindo a linha)
            }
        } else {
            return false;
            break; // Nenhuma saída encontrada
        }
    }
}


//To avoid altering the consintuecy of the Maze like the other functions, I needed to create a copy of the Maze
//(you could make a bool vector however I fear I would mess up the logic and this would also allow it to be applied in 2d+ labyrinths)
bool TwoDMaze::deadEndFillingMazeSolver(){
    //Step 1: Find all the cells with one exit and store them

    std::stack<std::tuple<int,int>> oneExitStack;
    for(int i=0;i<(int)MazeStructure.size();i++){
        for(int j=0;j<(int)MazeStructure[0].size();j++){
            int countOfNoObstacles=0;
            cell* currentCell = &MazeStructure[i][j];
            for(size_t k=0;k<currentCell->connectionFrom.size();k++){
                if(currentCell->connectionFrom[k] && !(currentCell->connectionFrom[k]->obstacle==obstacle)){
                    countOfNoObstacles++;
                }
            }
            for(size_t k=0;k<currentCell->connectionsTo.size();k++){
                if(!(currentCell->connectionsTo[k].obstacle==obstacle) ){
                    countOfNoObstacles++;
                }
            }

            if(countOfNoObstacles==1){
                oneExitStack.push(std::make_tuple(i,j));
            }
        }
    }

    //Step 2: Apply the algorithm to each one
    std::vector<std::vector<bool>> booleanGrid(MazeStructure.size(), std::vector<bool>(MazeStructure[0].size(), false));

    //While the stack is not empty meaning while there are still cells with only one exit (Dead ends)

    while(!oneExitStack.empty()){
        int i=std::get<0>(oneExitStack.top());
        int j=std::get<1>(oneExitStack.top());
        auto currentCell = &MazeStructure[i][j];
        int countOfNoObstacles = 1;

        while(countOfNoObstacles==1){
            booleanGrid[i][j]=1;

            //Since I have to alter a 2d boolean grid with -1s and +1s, I didnt want to make a thingy with MOD

            //An alternative to this 2dd boolean grid for labyrinths of further dimensions could just be making a copy of the maze structure itself
            //And block off exits until only one path remains. I didnt do this bbecause I wanted this to run on a very low end PC and wanted to avoid copying
            //The data structure

            //Goes left, decrements column
            if(currentCell->connectionFrom[left] && currentCell->connectionFrom[left]->obstacle == noObstacles && !booleanGrid[i][j-1]){
                currentCell =  &MazeStructure[i][--j];
            }

            //Goes up, decrements line
            else if(currentCell->connectionFrom[up] && currentCell->connectionFrom[up]->obstacle == noObstacles && !booleanGrid[i-1][j]){
                currentCell =  &MazeStructure[--i][j];
            }

            //Goes right, increments column
            else if(currentCell->connectionsTo[right].to && currentCell->connectionsTo[right].obstacle == noObstacles && !booleanGrid[i][j+1]){
                currentCell =  &MazeStructure[i][++j];
            }

            //Goes down, increments line
            else if(currentCell->connectionsTo[down].to && currentCell->connectionsTo[down].obstacle == noObstacles && !booleanGrid[i+1][j]){
                currentCell =  &MazeStructure[++i][j];
            }
            countOfNoObstacles=0;
            //checks how many obstacles are there
            for(int k=0;k<2;k++){
                if (currentCell->connectionFrom[k] && !(currentCell->connectionFrom[k]->obstacle == obstacle)){
                    if(currentCell->connectionFrom[k]->obstacle==entrance || currentCell->connectionFrom[k]->obstacle==exit)countOfNoObstacles++;
                    else if(!booleanGrid[i-k%2][j-(k+1)%2]) countOfNoObstacles++;
                }

                if (currentCell->connectionsTo[k].to && !(currentCell->connectionsTo[k].obstacle == obstacle)){
                    if(!booleanGrid[i+k%2][j+(k+1)%2]) countOfNoObstacles++;
                } else if(currentCell->connectionsTo[k].obstacle==exit || currentCell->connectionsTo[k].obstacle==entrance) countOfNoObstacles++;
            }
        }
        oneExitStack.pop();
    }

    //Step 3: Walk through the formed path

    auto indexes = getEntrancePos();

    //I will just use the recursive algorithm to walk through the last path since all dead ends have been filled
    if(recursiveSolvingFunction(booleanGrid,std::get<0>(indexes),std::get<1>(indexes))){
        std::reverse(correctPath.begin(),correctPath.end());
        return true;
    } else {

        //TIMEOUT!!!!!!!!!
        return false;
    }
}

//This function ONLY checks the maze, it does NOT store the correct path anywhere, could be useful
bool TwoDMaze::mazeChecker() {
    std::vector<std::vector<bool>> booleanGrid(MazeStructure.size(), std::vector<bool>(MazeStructure[0].size(), false));
    std::tuple<int,int> indices = getEntrancePos();

    if(TwoDMaze::recursiveSolvingFunction(booleanGrid, std::get<0>(indices), std::get<1>(indices),0)){
        return true;
    } else {
        return false;
    }
}

