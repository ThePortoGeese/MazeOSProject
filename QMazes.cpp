#include "qmazes.h"
#include <QDebug>
#include <iostream>
#include <stack>

namespace MazeFileCoding{
enum fileCoding{
    corner='c',
    obstacle='O',
    noObstacle='N',
    cell='C',
    entrance='e',
    exit='E',
    null='n'
};

}

QMazes::QMazes(int x,int y) : TwoDMaze(x,y){

}

//Reimplemented to show the connections as qt runs the app
void QMazes::connectionsPrint(){
    for(int i=0;i<(int)MazeStructure.size();i++){
        for(int y=0;y<(int)MazeStructure[0].size();y++){
            qDebug()<<"Cell At Coordinate:"<<i<<y;
            qDebug()<<"Memory adress:";
            qDebug()<<&MazeStructure[i][y];
            qDebug()<<"From Connections:";
            for(int k=0;k<(int)MazeStructure[i][y].connectionFrom.size();k++){
                if(MazeStructure[i][y].connectionFrom[k]==nullptr){
                    qDebug()<<"Null";
                }
                else {
                    qDebug()<<MazeStructure[i][y].connectionFrom[k]->from;
                    qDebug()<<"Obstacle: "<<MazeStructure[i][y].connectionFrom[k]->obstacle;
                }
            }
            qDebug()<<"To Connections:";
            for(int k=0;k<(int)MazeStructure[i][y].connectionsTo.size();k++){
                if(MazeStructure[i][y].connectionsTo[k].to==nullptr){
                    if(MazeStructure[i][y].connectionsTo[k].obstacle==exit) qDebug()<<"Exit";
                    else if(MazeStructure[i][y].connectionsTo[k].obstacle==entrance) qDebug()<<"Entrance";
                    else qDebug()<<"Null";
                }
                else {
                    qDebug()<<MazeStructure[i][y].connectionsTo[k].to;
                    qDebug()<<"Obstacle: "<<MazeStructure[i][y].connectionsTo[k].obstacle;
                }
            }
        }
    }
}

void QMazes::createMaze(){
    TwoDMaze::createMaze();
    userGenerated=0;
    nameGenerator();
}

bool QMazes::recursiveMazeSolver(){
    if(TwoDMaze::recursiveMazeSolver()){
        std::reverse(tempPath.begin(),tempPath.end());
        std::reverse(correctPath.begin(),correctPath.end());
        return 1;
    }else{
        emit timeOut();
        return 0;
    }
}

bool QMazes::recursiveMazeSolver(const int& tX,const int& tY){
    if(TwoDMaze::recursiveMazeSolver(tX,tY)){

        return 1;
    }else{
        emit couldntReach();
        return 0;
    }
}

bool QMazes::recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y,const bool& store) {
    if (i<0||i>=(int)MazeStructure.size()||y<0||y>=(int)MazeStructure[0].size()||booleanGrid[i][y]) {
        return false;
    }
    for(int k=0;k<(int)MazeStructure[i][y].connectionsTo.size();k++){
        if (MazeStructure[i][y].connectionsTo[k].obstacle==exit) {
            emit cellTriggered(i,y,-1);
            if(store){
                correctPath.push_back(&MazeStructure[i][y]);
                tempPath.push_back(new temporaryPathHolder(i,y,-1));
            }
            //qDebug()<<"Found solution at: "<<i<<" "<<y;
            return true;
        }
    }

    for(int k=0;k<(int)MazeStructure[i][y].connectionFrom.size();k++){
        if (MazeStructure[i][y].connectionFrom[k] && MazeStructure[i][y].connectionFrom[k]->obstacle==exit) {
            emit cellTriggered(i,y,-1);
            if(store){
                correctPath.push_back(&MazeStructure[i][y]);
                tempPath.push_back(new temporaryPathHolder(i,y,-1));
            }
            //qDebug()<<"Found solution at: "<<i<<" "<<y<<'\n';
            return true;
        }
    }

    QTime dieTime= QTime::currentTime().addMSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    std::array<int,4> nums{1,2,3,4};

    booleanGrid[i][y] = true;
    std::random_shuffle(nums.begin(),nums.end());
    correctPath.push_back(&MazeStructure[i][y]);
    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(MazeStructure[i][y].connectionFrom[0]!=nullptr&&MazeStructure[i][y].connectionFrom[0]->obstacle==0){
                emit cellTriggered(i,y,0);
                if(recursiveSolvingFunction(booleanGrid, i, y-1,store)) {
                    if(store){
                        correctPath.push_back(&MazeStructure[i][y]);
                        tempPath.push_back(new temporaryPathHolder(i,y,0));
                    }
                    return true;
                }
            }
            break;
        case 2:
            if(MazeStructure[i][y].connectionFrom[1]!=nullptr&&MazeStructure[i][y].connectionFrom[1]->obstacle==0){
                emit cellTriggered(i,y,1);
                if(recursiveSolvingFunction(booleanGrid, i-1, y,store)) {
                    if(store){
                        correctPath.push_back(&MazeStructure[i][y]);
                        tempPath.push_back(new temporaryPathHolder(i,y,1));
                    }
                    return true;
                }
            }
            break;
        case 3:
            if(MazeStructure[i][y].connectionsTo[0].to!=nullptr&&MazeStructure[i][y].connectionsTo[0].obstacle==0){
                emit cellTriggered(i,y,2);
                if(recursiveSolvingFunction(booleanGrid, i, y +1,store)) {
                    if(store){
                        correctPath.push_back(&MazeStructure[i][y]);
                        tempPath.push_back(new temporaryPathHolder(i,y,2));
                    }
                    return true;}
            }
            break;
        case 4:
            if(MazeStructure[i][y].connectionsTo[1].to!=nullptr&&MazeStructure[i][y].connectionsTo[1].obstacle==0){
                emit cellTriggered(i,y,3);
                if(recursiveSolvingFunction(booleanGrid, i+1, y,store)) {
                    if(store){
                        correctPath.push_back(&MazeStructure[i][y]);
                        tempPath.push_back(new temporaryPathHolder(i,y,3));
                    }
                    return true;
                }
            }
            break;
        }

    }

    return false;
}



bool QMazes::recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int j, const int& tX, const int& tY) {
    if(i==tY&&j==tX){
        tempPath.push_back(new temporaryPathHolder(i,j,-1));
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
            if(MazeStructure[i][j].connectionFrom[0]!=nullptr&&MazeStructure[i][j].connectionFrom[0]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j-1,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,j,0));
                    return true;
                }
            }
            break;
        case 2:
            if(MazeStructure[i][j].connectionFrom[1]!=nullptr&&MazeStructure[i][j].connectionFrom[1]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i-1, j,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,j,1));
                    return true;
                }
            }
            break;
        case 3:
            if(MazeStructure[i][j].connectionsTo[0].to!=nullptr&&MazeStructure[i][j].connectionsTo[0].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j +1,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,j,2));
                    return true;}
            }
            break;
        case 4:
            if(MazeStructure[i][j].connectionsTo[1].to!=nullptr&&MazeStructure[i][j].connectionsTo[1].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i+1, j,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,j,3));
                    return true;}
            }
            break;
        }

    }

    return false;
}

//Random Name Generator (Basic but it works)

void QMazes::nameGenerator(){
    QFile fileName(":/labNames/resources/firstName.txt");
    QString firstName;
    if(fileName.exists()&&fileName.open(QFile::ReadOnly)){
        QTextStream out(&fileName);

        int n=std::rand()%31;
        int count=0;
        do{
            if(n==count){
                firstName=out.readLine();
                break;
            } else {
                out.readLine();
            }
            count+=1;
        } while(!out.atEnd());

        fileName.close();
    }
    QFile fileAdj(":/labNames/resources/secondName.txt");
    QString secondName;
    if(fileAdj.exists()&&fileAdj.open(QFile::ReadOnly)){
        QTextStream out(&fileAdj);

        int n=std::rand()%35;
        int count=0;
        do{
            if(n==count){
                secondName=out.readLine();
                break;
            } else {
                out.readLine();
            }
            count+=1;
        } while(!out.atEnd());

        fileAdj.close();
    }

    name=firstName+" "+secondName;
}

bool QMazes::wallFollowerMazeSolver() {

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
                emit cellTriggered(std::get<0>(indices),std::get<1>(indices),-1);
                correctPath.push_back(currentCell);
                tempPath.push_back(new temporaryPathHolder(std::get<0>(indices),std::get<1>(indices),-1));
                return true; // Solução encontrada!
            }
        }

        for (int conn = 0; (int)currentCell->connectionFrom.size()>conn;conn++) {
            if (currentCell->connectionFrom[conn] && currentCell->connectionFrom[conn]->obstacle == exit) {
                emit cellTriggered(std::get<0>(indices),std::get<1>(indices),-1);
                correctPath.push_back(currentCell);
                tempPath.push_back(new temporaryPathHolder(std::get<0>(indices),std::get<1>(indices),-1));
                return true; // Solução encontrada!
            }
        }
    }
    while (true) {
        QTime dieTime= QTime::currentTime().addMSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
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

        // Turns Back, which means this was a dead end
        if (!nextCell) {
            direction = static_cast<MoveDir>((direction + 2) % 4);
            if (direction <= UP) { // Esquerda/Cima -> connectionFrom
                nextCell = currentCell->connectionFrom[direction] ? currentCell->connectionFrom[direction]->from : nullptr;
            } else { // Direita/Baixo -> connectionsTo
                nextCell = currentCell->connectionsTo[direction - 2].to ? currentCell->connectionsTo[direction - 2].to : nullptr;
            }

        }
        emit cellTriggered(std::get<0>(indices),std::get<1>(indices),direction);
        // Se encontrou um próximo passo, avança
        if (nextCell) {
            correctPath.push_back(currentCell);
            tempPath.push_back(new temporaryPathHolder(std::get<0>(indices),std::get<1>(indices),direction));
            currentCell = nextCell;

            if (direction == LEFT) {
                std::get<1>(indices)--; // Move para a esquerda (diminuindo a coluna)
            } else if (direction == UP) {
                std::get<0>(indices)--; // Move para cima (diminuindo a linha)
            } else if (direction == RIGHT) {
                std::get<1>(indices)++; // Move para a esquerda (diminuindo a coluna)
            } else if (direction == DOWN) {
                std::get<0>(indices)++; // Move para cima (diminuindo a linha)
            }

            // Verifica se chegou à saída
            for (int conn = 0; (int)currentCell->connectionsTo.size()>conn;conn++) {
                if (currentCell->connectionsTo[conn].obstacle == exit) {
                    emit cellTriggered(std::get<0>(indices),std::get<1>(indices),-1);
                    correctPath.push_back(currentCell);
                    tempPath.push_back(new temporaryPathHolder(std::get<0>(indices),std::get<1>(indices),-1));
                    return true; // Solução encontrada!
                }
            }

            for (int conn = 0; (int)currentCell->connectionFrom.size()>conn;conn++) {
                if (currentCell->connectionFrom[conn] && currentCell->connectionFrom[conn]->obstacle == exit) {
                    emit cellTriggered(std::get<0>(indices),std::get<1>(indices),-1);
                    correctPath.push_back(currentCell);
                    tempPath.push_back(new temporaryPathHolder(std::get<0>(indices),std::get<1>(indices),-1));
                    return true; // Solução encontrada!
                }
            }


        } else {
            break; // Nenhuma saída encontrada
        }
    }
}

bool QMazes::deadEndFillingMazeSolver(){
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
            QTime dieTime= QTime::currentTime().addMSecs(1);
            while (QTime::currentTime() < dieTime)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

            booleanGrid[i][j]=1;

            //Goes left, decrements column
            if(currentCell->connectionFrom[left] && currentCell->connectionFrom[left]->obstacle == noObstacles && !booleanGrid[i][j-1]){
                emit cellTriggered(i,j,0);
                currentCell =  &MazeStructure[i][--j];
            }

            //Goes up, decrements line
            else if(currentCell->connectionFrom[up] && currentCell->connectionFrom[up]->obstacle == noObstacles && !booleanGrid[i-1][j]){
                emit cellTriggered(i,j,1);
                currentCell =  &MazeStructure[--i][j];
            }

            //Goes right, increments column
            else if(currentCell->connectionsTo[right].to && currentCell->connectionsTo[right].obstacle == noObstacles && !booleanGrid[i][j+1]){
                emit cellTriggered(i,j,2);
                currentCell =  &MazeStructure[i][++j];
            }

            //Goes down, increments line
            else if(currentCell->connectionsTo[down].to && currentCell->connectionsTo[down].obstacle == noObstacles && !booleanGrid[i+1][j]){
                emit cellTriggered(i,j,3);
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
        std::reverse(tempPath.begin(),tempPath.end());
        return true;
    } else {
        emit timeOut();
        return false;
    }
}

void QMazes::saveAsFile(QString fileName){
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/MazeOS/userMazes/"+fileName+".maz");

    if(file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate)){
        QTextStream out(&file);
        //qDebug()<<file.fileName();
        out<<name<<'\n';

        for(int i=0;i<2*getHeight()+1;i++){
            for(int j=0;j<2*getWidth()+1;j++){
                if(i%2==0&&j%2==0){
                    //These are always corners (I got this from personal observation of my sketches of this)
                    out<<char(MazeFileCoding::corner);
                    continue;
                }

                if(i%2!=0&&j%2!=0){
                    //Contarily, these are always cells
                    out<<char(MazeFileCoding::cell);
                    continue;
                }
                if(i==0){
                    if(MazeStructure[0][(j-1)/2].connectionFrom[up]==nullptr){
                        out<<char(MazeFileCoding::null);
                        continue;
                    }

                    else if(MazeStructure[0][(j-1)/2].connectionFrom[up]->obstacle==exit){
                        out<<char(MazeFileCoding::exit);
                        continue;
                    }

                    out<<char(MazeFileCoding::entrance);
                    continue;
                }
                if(j==0){
                    if(MazeStructure[(i-1)/2][0].connectionFrom[left]==nullptr){
                        out<<char(MazeFileCoding::null);
                        continue;
                    }

                    else if(MazeStructure[(i-1)/2][0].connectionFrom[left]->obstacle==exit){
                        out<<char(MazeFileCoding::exit);
                        continue;
                    }

                    out<<char(MazeFileCoding::entrance);
                    continue;
                }
                if(i%2!=0){ //Since i represents lines, is odd and I've checked corners, null connections and cells,
                            // this can only be a Horizontal Connection since they "occupy" the same i (line) as cells (graphically speaking)

                    //If we are in the last row
                    if(j==2*getWidth()){
                        if(MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[right].obstacle==entrance){

                            out<<char(MazeFileCoding::entrance);
                            continue;
                        }

                        else if(MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[right].obstacle==exit){
                            out<<char(MazeFileCoding::exit);
                            continue;
                        }

                        out<<char(MazeFileCoding::null);
                        continue;

                    }

                    else if(MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[right].obstacle==obstacle){
                        out<<char(MazeFileCoding::obstacle);
                        continue;
                    }

                    else out<<char(MazeFileCoding::noObstacle);
                }
                else if(j%2!=0){ //Since j represents columns, is odd and I've checked corners, null connections and cells,
                    // this can only be a vertica lConnection since they "occupy" the same j (column) as cells (graphically speaking)


                    //this activates on the last line
                    if(i==2*getHeight()){
                        if(MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[down].obstacle==entrance){
                            out<<char(MazeFileCoding::entrance);
                            continue;
                        }
                        else if(MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[down].obstacle==exit){
                            out<<char(MazeFileCoding::exit);
                            continue;
                        }

                        out<<char(MazeFileCoding::null);
                        continue;
                    }

                    else if(MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[down].obstacle==obstacle){
                        out<<char(MazeFileCoding::obstacle);
                        continue;
                    }

                    else out<<char(MazeFileCoding::noObstacle);
                    continue;
                }
            }
            out<<'\n';
        }
        if(evaluated){
            out<<"EVALUATED";
        }
        file.close();
        return;
    }

    qDebug()<<"File Not Opened!";
}

//Reverse of the other function

QMazes* QMazes::convertFromFile(QFile* file){
    if(file->open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream in(file);
        QString mazeName=in.readLine();

        std::vector<QString> mazeLines;
        bool evaluated=0;

        if(in.atEnd()) return nullptr;

        do{
            QString inStr=in.readLine();
            if(inStr=="EVALUATED"){
                evaluated=1;
            } else if(mazeLines.size()>0){
                if(inStr.length() == mazeLines[0].size()){
                    mazeLines.push_back(inStr);
                } else {
                    return nullptr;
                }
            }
            else {
                if(inStr.size()%2==0) return nullptr;
                mazeLines.push_back(inStr);
            }
        } while(!in.atEnd());

        if(mazeLines.size()%2==0) return nullptr;

        QMazes* returnMaze=new QMazes((mazeLines[0].size()-1)/2,(mazeLines.size()-1)/2);
        returnMaze->setEvaluated(evaluated);

        for(int i=0;i<(int)mazeLines.size();i++){
            for(int j=0;j<mazeLines[i].size();j++){            

                if(i%2==0&&j%2==0){
                    //ignore corners
                    continue;
                }

                if((i%2!=0 && j%2!=0)){
                    //ignore cells
                    continue;
                }
                if(i==0){
                    if(mazeLines[0][j]==QChar(MazeFileCoding::entrance)){
                        returnMaze->MazeStructure[0][(j-1)/2].connectionFrom[up]=new connection(nullptr,&returnMaze->MazeStructure[0][(j-1)/2],entrance);
                        continue;
                    }

                    else if(mazeLines[0][j]==QChar(MazeFileCoding::exit)){
                        returnMaze->MazeStructure[0][(j-1)/2].connectionFrom[up]=new connection(nullptr,&returnMaze->MazeStructure[0][(j-1)/2],exit);
                        continue;
                    } else if(mazeLines[0][j]==QChar(MazeFileCoding::null)) continue;
                }
                if(j==0){
                    if(mazeLines[i][0]==QChar(MazeFileCoding::entrance)){
                        returnMaze->MazeStructure[(i-1)/2][0].connectionFrom[left]=new connection(nullptr,&returnMaze->MazeStructure[(i-1)/2][0],entrance);
                        continue;
                    }

                    else if(mazeLines[i][0]==QChar(MazeFileCoding::exit)){
                        returnMaze->MazeStructure[(i-1)/2][0].connectionFrom[left]=new connection(nullptr,&returnMaze->MazeStructure[(i-1)/2][0],exit);
                        continue;
                    }

                    else if(mazeLines[i][0]==QChar(MazeFileCoding::null)) continue;
                }
                if(i%2!=0){
                    if(j==(int)mazeLines[i].size()-1){
                        if(mazeLines[i][j]==QChar(MazeFileCoding::exit)){

                            returnMaze->MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[right].obstacle=exit;
                            continue;
                        }

                        else if(mazeLines[i][j]==QChar(MazeFileCoding::entrance)){

                            returnMaze->MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[right].obstacle=entrance;
                            continue;
                        }

                        else if(mazeLines[i][j]==QChar(MazeFileCoding::null)) continue;
                    }

                    else if(mazeLines[i][j]==QChar(MazeFileCoding::noObstacle)){
                        returnMaze->MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[right].obstacle=noObstacles;
                        continue;
                    }

                    else if(mazeLines[i][j]==QChar(MazeFileCoding::obstacle)){
                        continue;
                    }
                }
                else if(j%2!=0){ //Since j represents columns, is odd and I've checked corners, null connections and cells,
                    // this can only be a vertica lConnection since they "occupy" the same j (column) as cells (graphically speaking)


                    //this activates on the last line
                    if(i==(int)mazeLines.size()-1){
                        if(mazeLines[i][j]==QChar(MazeFileCoding::exit)){
                            returnMaze->MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[down].obstacle=exit;
                            continue;
                        }
                        else if(mazeLines[i][j]==QChar(MazeFileCoding::entrance)){
                            returnMaze->MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[down].obstacle=entrance;
                            continue;
                        }
                        else if(mazeLines[i][j]==QChar(MazeFileCoding::null)) continue;
                    }

                    else if(mazeLines[i][j]==QChar(MazeFileCoding::noObstacle)){
                        returnMaze->MazeStructure[(i-1)/2][(j-1)/2].connectionsTo[down].obstacle=noObstacles;
                        continue;
                    }

                    else if(mazeLines[i][j]==QChar(MazeFileCoding::obstacle)){
                        continue;
                    }
                }

                //qDebug()<<i<<" "<<j;
                delete returnMaze;
                //If this gets here, it means there were edits to the file. Meaning it is corrupted
                return nullptr;
            }
        }
        file->close();
        returnMaze->name=mazeName;
        //returnMaze->connectionsPrint();
        return returnMaze;
    }
    qDebug()<<"File Not Opened";
    return nullptr;
}
