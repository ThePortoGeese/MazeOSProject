#include "mazeclass.h"
#include <iostream>
#include <stack>
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
            if(daMaze[y][x].connectionFrom[MazeEnums::left]!=nullptr&&daMaze[y][x].connectionFrom[MazeEnums::left]->obstacle!=2){
                if(!booleanGrid[y][x-1]){
                    daMaze[y][x].connectionFrom[MazeEnums::left]->obstacle=MazeEnums::noObstacles;
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
            if(daMaze[y][x].connectionsTo[MazeEnums::right].to!=nullptr){
                if(!booleanGrid[y][x+1]){
                    daMaze[y][x].connectionsTo[MazeEnums::right].obstacle=MazeEnums::noObstacles;
                    recursiveDiggingFunction( x+1, y,booleanGrid);
                }
            }
            break;
        case 4:
            if(daMaze[y][x].connectionsTo[MazeEnums::down].to!=nullptr){
                if(!booleanGrid[y+1][x]){
                    daMaze[y][x].connectionsTo[MazeEnums::down].obstacle=MazeEnums::noObstacles;
                    recursiveDiggingFunction(x, y+1,booleanGrid);
                }
            }
            break;
        }

    }

    return;
}

std::tuple<int,int> mazeClass::getEntrancePos(){
    int ix=-1,iy=-1;
    for(int i=0;i<(int)daMaze.size();i++){
        for(int k=0;k<(int)daMaze[i][0].connectionFrom.size();k++){
            if(daMaze[i][0].connectionFrom[k]!=nullptr){
                if(daMaze[i][0].connectionFrom[k]->obstacle==MazeEnums::entrance){
                    ix=i;
                    iy=0;
                }
            }
        }
        for(int k=0;k<(int)daMaze[i][daMaze[0].size()-1].connectionsTo.size();k++){
            if(daMaze[i][daMaze[0].size()-1].connectionsTo[k].obstacle==MazeEnums::entrance){
                    ix=i;
                    iy=daMaze[0].size()-1;
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

            for(int k=0;k<(int)daMaze[daMaze.size()-1][i].connectionsTo.size();k++){
                if(daMaze[daMaze.size()-1][i].connectionsTo[k].obstacle==MazeEnums::entrance){
                    ix=daMaze.size()-1;
                    iy=i;
                }
            }
        }
    }

    return std::tuple<int,int>(ix,iy);
}

bool mazeClass::recursiveMazeSolver() {
    std::vector<std::vector<bool>> booleanGrid(daMaze.size(), std::vector<bool>(daMaze[0].size(), false));
    std::tuple<int,int> a = getEntrancePos();

    //std::cout<<"Ix value: "<<ix<< " Iy value: "<<iy<<'\n';
    startOfSolver = std::chrono::system_clock::now();
    if(recursiveSolvingFunction(booleanGrid, std::get<0>(a), std::get<1>(a),1)){
        std::reverse(correctPath.begin(),correctPath.end());
        return 1;
    } else {
        return 0;
    }
}

bool mazeClass::recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int j, const bool& store) {
    if(std::chrono::system_clock::now()-startOfSolver>std::chrono::milliseconds((long)(X*Y*1.7))){
        return false;
    }

    if (i<0||i>=(int)daMaze.size()||j<0||j>=(int)daMaze[0].size()||booleanGrid[i][j]) {
        return false;
    }
    //std::cout<<"Path to: "<<i<< " "<<y<<'\n';
    for(int k=0;k<(int)daMaze[i][j].connectionsTo.size();k++){
        if (daMaze[i][j].connectionsTo[k].obstacle==MazeEnums::exit) {
            if(store)correctPath.push_back(&daMaze[i][j]);
            //std::cout<<"Found solution at: "<<i<<" "<<y<<'\n';
            return true;
        }
    }

    for(int k=0;k<(int)daMaze[i][j].connectionFrom.size();k++){
        if (daMaze[i][j].connectionFrom[k] && daMaze[i][j].connectionFrom[k]->obstacle==MazeEnums::exit) {
            if(store)correctPath.push_back(&daMaze[i][j]);
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
            if(daMaze[i][j].connectionFrom[0]!=nullptr&&daMaze[i][j].connectionFrom[0]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j-1,store)) {
                    if(store)correctPath.push_back(&daMaze[i][j]);
                    return true;
                }
            }
            break;
        case 2:
            if(daMaze[i][j].connectionFrom[1]!=nullptr&&daMaze[i][j].connectionFrom[1]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i-1, j,store)) {
                    if(store)correctPath.push_back(&daMaze[i][j]);
                    return true;
                }
            }
            break;
        case 3:
            if(daMaze[i][j].connectionsTo[0].to!=nullptr&&daMaze[i][j].connectionsTo[0].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j +1,store)) {
                    if(store)correctPath.push_back(&daMaze[i][j]);
                    return true;}
            }
            break;
        case 4:
            if(daMaze[i][j].connectionsTo[1].to!=nullptr&&daMaze[i][j].connectionsTo[1].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i+1, j,store)) {
                    if(store)correctPath.push_back(&daMaze[i][j]);
                    return true;}
            }
            break;
        }
        if(std::chrono::system_clock::now()-startOfSolver>std::chrono::milliseconds((long)(X*Y*1.25))){
            return false;
        }
    }

    return false;
}


bool mazeClass::recursiveMazeSolver(const int& tX,const int& tY) {
    if(correctPath.size()!=0) {
        correctPath.clear();
    }
    std::vector<std::vector<bool>> booleanGrid(daMaze.size(), std::vector<bool>(daMaze[0].size(), false));
    std::tuple<int,int> a = getEntrancePos();

    //std::cout<<"Ix value: "<<ix<< " Iy value: "<<iy<<'\n';
    startOfSolver = std::chrono::system_clock::now();
    if(recursiveSolvingFunction(booleanGrid, std::get<0>(a), std::get<1>(a),tX,tY)){
        return true;
    } else {
        return false;
    }
}

//Overload of solver operation to find path to cell at (tX, tY)
bool mazeClass::recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int j,const int& tX,const int& tY) {
    if(i==tY&&j==tX){
        //Do whatever you wanna do with this path here
        return true;
    }

    if(std::chrono::system_clock::now()-startOfSolver>std::chrono::milliseconds((long)(X*Y*1.25))){
        return false;
    }

    if (i<0||i>=(int)daMaze.size()||j<0||j>=(int)daMaze[0].size()||booleanGrid[i][j]) {
        return false;
    }

    std::array<int,4> nums{1,2,3,4};

    booleanGrid[i][j] = true;
    std::random_shuffle(nums.begin(),nums.end());
    correctPath.push_back(&daMaze[i][j]);
    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(daMaze[i][j].connectionFrom[0]!=nullptr&&daMaze[i][j].connectionFrom[0]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j-1,tX,tY)) {
                    //Do whatever you wanna do with this path here
                    return true;
                }
            }
            break;
        case 2:
            if(daMaze[i][j].connectionFrom[1]!=nullptr&&daMaze[i][j].connectionFrom[1]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i-1, j,tX,tY)) {
                    //Do whatever you wanna do with this path here
                    return true;
                }
            }
            break;
        case 3:
            if(daMaze[i][j].connectionsTo[0].to!=nullptr&&daMaze[i][j].connectionsTo[0].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j +1,tX,tY)) {
                    //Do whatever you wanna do with this path here
                    return true;}
            }
            break;
        case 4:
            if(daMaze[i][j].connectionsTo[1].to!=nullptr&&daMaze[i][j].connectionsTo[1].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i+1, j,tX,tY)) {
                    //Do whatever you wanna do with this path here
                    return true;}
            }
            break;
        }
        if(std::chrono::system_clock::now()-startOfSolver>std::chrono::milliseconds((long)(X*Y*1.25))){
            return false;
        }
    }

    return false;
}

bool mazeClass::wallFollowerMazeSolver() {

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
    cell* currentCell = &daMaze[std::get<0>(indices)][std::get<1>(indices)];
    startOfSolver = std::chrono::system_clock::now();
    while (true) {

        if(std::chrono::system_clock::now()-startOfSolver>std::chrono::milliseconds((long)(X*Y*2))){
            return false;
        }

        cell *nextCell = nullptr;

        // The Program tries to turn left first
        MoveDir leftDir = static_cast<MoveDir>((direction + 3) % 4);

        if (leftDir <= UP) { //Since half of the connections are stored in different places, I need to do this
            if (currentCell->connectionFrom[leftDir] && currentCell->connectionFrom[leftDir]->obstacle == MazeEnums::noObstacles) {
                direction = leftDir;
                nextCell = currentCell->connectionFrom[leftDir]->from;
            }
        } else { // Conexões para direita e baixo estão em connectionsTo
            if (currentCell->connectionsTo[leftDir - 2].to && currentCell->connectionsTo[leftDir - 2].obstacle == MazeEnums::noObstacles) {
                direction = leftDir;
                nextCell = currentCell->connectionsTo[leftDir - 2].to;
            }
        }

        // Tries to continue moving
        if (!nextCell) {
            if (direction <= UP) { // Same as thing as before
                if (currentCell->connectionFrom[direction] && currentCell->connectionFrom[direction]->obstacle == MazeEnums::noObstacles) {
                    nextCell = currentCell->connectionFrom[direction]->from;
                }
            } else { // Same thing as before
                if (currentCell->connectionsTo[direction - 2].to && currentCell->connectionsTo[direction - 2].obstacle == MazeEnums::noObstacles) {
                    nextCell = currentCell->connectionsTo[direction - 2].to;
                }
            }
        }

        // Tries to turn right
        if (!nextCell) {
            MoveDir rightDir = static_cast<MoveDir>((direction + 1) % 4);
            if (rightDir <= UP) {
                if (currentCell->connectionFrom[rightDir] && currentCell->connectionFrom[rightDir]->obstacle == MazeEnums::noObstacles) {
                    direction = rightDir;
                    nextCell = currentCell->connectionFrom[rightDir]->from;
                }
            } else {
                if (currentCell->connectionsTo[rightDir - 2].to && currentCell->connectionsTo[rightDir - 2].obstacle == MazeEnums::noObstacles) {
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
                if (conn.obstacle == MazeEnums::exit) {
                    correctPath.push_back(currentCell);
                    return true; // Solução encontrada!
                }
            }

            for (const auto &conn : currentCell->connectionFrom) {
                if (conn && conn->obstacle == MazeEnums::exit) {
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
            break; // Nenhuma saída encontrada
        }
    }
}


//To avoid altering the consintuecy of the Maze like the other functions, I needed to create a copy of the Maze
//(you could make a bool vector however I fear I would mess up the logic and this would also allow it to be applied in 2d+ labyrinths)
bool mazeClass::deadEndFillingMazeSolver(){
    //Step 1: Find all the cells with one exit and store them

    std::stack<std::tuple<int,int>> oneExitStack;
    for(int i=0;i<(int)daMaze.size();i++){
        for(int j=0;j<(int)daMaze[0].size();j++){
            int countOfNoObstacles=0;
            cell* currentCell = &daMaze[i][j];
            for(size_t k=0;k<currentCell->connectionFrom.size();k++){
                if(currentCell->connectionFrom[k] && !(currentCell->connectionFrom[k]->obstacle==MazeEnums::obstacle)){
                    countOfNoObstacles++;
                }
            }
            for(size_t k=0;k<currentCell->connectionsTo.size();k++){
                if(!(currentCell->connectionsTo[k].obstacle==MazeEnums::obstacle) ){
                    countOfNoObstacles++;
                }
            }

            if(countOfNoObstacles==1){
                oneExitStack.push(std::make_tuple(i,j));
            }
        }
    }

    //Step 2: Apply the algorithm to each one
    std::vector<std::vector<bool>> booleanGrid(daMaze.size(), std::vector<bool>(daMaze[0].size(), false));

    //While the stack is not empty meaning while there are still cells with only one exit (Dead ends)

    while(!oneExitStack.empty()){
        int i=std::get<0>(oneExitStack.top());
        int j=std::get<1>(oneExitStack.top());
        auto currentCell = &daMaze[i][j];
        int countOfNoObstacles = 1;

        while(countOfNoObstacles==1){
            booleanGrid[i][j]=1;

            //Since I have to alter a 2d boolean grid with -1s and +1s, I didnt want to make a thingy with MOD

            //An alternative to this 2dd boolean grid for labyrinths of further dimensions could just be making a copy of the maze structure itself
            //And block off exits until only one path remains. I didnt do this bbecause I wanted this to run on a very low end PC and wanted to avoid copying
            //The data structure

            //Goes left, decrements column
            if(currentCell->connectionFrom[MazeEnums::left] && currentCell->connectionFrom[MazeEnums::left]->obstacle == MazeEnums::noObstacles && !booleanGrid[i][j-1]){
                currentCell =  &daMaze[i][--j];
            }

            //Goes up, decrements line
            else if(currentCell->connectionFrom[MazeEnums::up] && currentCell->connectionFrom[MazeEnums::up]->obstacle == MazeEnums::noObstacles && !booleanGrid[i-1][j]){
                currentCell =  &daMaze[--i][j];
            }

            //Goes right, increments column
            else if(currentCell->connectionsTo[MazeEnums::right].to && currentCell->connectionsTo[MazeEnums::right].obstacle == MazeEnums::noObstacles && !booleanGrid[i][j+1]){
                currentCell =  &daMaze[i][++j];
            }

            //Goes down, increments line
            else if(currentCell->connectionsTo[MazeEnums::down].to && currentCell->connectionsTo[MazeEnums::down].obstacle == MazeEnums::noObstacles && !booleanGrid[i+1][j]){
                currentCell =  &daMaze[++i][j];
            }
            countOfNoObstacles=0;
            //checks how many obstacles are there
            for(int k=0;k<2;k++){
                if (currentCell->connectionFrom[k] && !(currentCell->connectionFrom[k]->obstacle == MazeEnums::obstacle)){
                    if(currentCell->connectionFrom[k]->obstacle==MazeEnums::entrance || currentCell->connectionFrom[k]->obstacle==MazeEnums::exit)countOfNoObstacles++;
                    else if(!booleanGrid[i-k%2][j-(k+1)%2]) countOfNoObstacles++;
                }

                if (currentCell->connectionsTo[k].to && !(currentCell->connectionsTo[k].obstacle == MazeEnums::obstacle)){
                    if(!booleanGrid[i+k%2][j+(k+1)%2]) countOfNoObstacles++;
                }
            }
        }
        oneExitStack.pop();
    }

    //Step 3: Walk through the formed path

    auto indexes = getEntrancePos();
    startOfSolver = std::chrono::system_clock::now();

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
bool mazeClass::mazeChecker() {
    std::vector<std::vector<bool>> booleanGrid(daMaze.size(), std::vector<bool>(daMaze[0].size(), false));
    std::tuple<int,int> indices = getEntrancePos();

    startOfSolver = std::chrono::system_clock::now();

    if(mazeClass::recursiveSolvingFunction(booleanGrid, std::get<0>(indices), std::get<1>(indices),0)){
        return true;
    } else {
        return false;
    }
}

