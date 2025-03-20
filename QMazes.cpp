#include "qmazes.h"
#include <QDebug>
#include <iostream>

namespace QMazeEnums{
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

QMazes::QMazes(int x,int y) : mazeClass(x,y){

}

//Reimplemented to show the connections as qt runs the app
void QMazes::connectionsPrint(){
    for(int i=0;i<(int)daMaze.size();i++){
        for(int y=0;y<(int)daMaze[0].size();y++){
            qDebug()<<"Cell At Coordinate:"<<i<<y;
            qDebug()<<"Memory adress:";
            qDebug()<<&daMaze[i][y];
            qDebug()<<"From Connections:";
            for(int k=0;k<(int)daMaze[i][y].connectionFrom.size();k++){
                if(daMaze[i][y].connectionFrom[k]==nullptr){
                    qDebug()<<"Null";
                }
                else {
                    qDebug()<<daMaze[i][y].connectionFrom[k]->from;
                    qDebug()<<"Obstacle: "<<daMaze[i][y].connectionFrom[k]->obstacle;
                }
            }
            qDebug()<<"To Connections:";
            for(int k=0;k<(int)daMaze[i][y].connectionsTo.size();k++){
                if(daMaze[i][y].connectionsTo[k].to==nullptr){
                    if(daMaze[i][y].connectionsTo[k].obstacle==MazeEnums::exit) qDebug()<<"Exit";
                    else qDebug()<<"Null";
                }
                else {
                    qDebug()<<daMaze[i][y].connectionsTo[k].to;
                    qDebug()<<"Obstacle: "<<daMaze[i][y].connectionsTo[k].obstacle;
                }
            }
        }
    }
}

void QMazes::createMaze(){
    mazeClass::createMaze();
    userGenerated=0;
    nameGenerator();
}

bool QMazes::recursiveMazeSolver(){
    runtimeTime.start();
    if(mazeClass::recursiveMazeSolver()){
        std::reverse(tempPath.begin(),tempPath.end());
        return 1;
    }else{
        emit timeOut();
        return 0;
    }
}

bool QMazes::recursiveMazeSolver(const int& tX,const int& tY){
    runtimeTime.start();
    if(mazeClass::recursiveMazeSolver(tX,tY)){

        return 1;
    }else{
        emit timeOut();
        return 0;
    }
}

bool QMazes::recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y,const bool& store) {
    if(runtimeTime.elapsed() > X*Y*3){
        return false;
    }

    if (i<0||i>=(int)daMaze.size()||y<0||y>=(int)daMaze[0].size()||booleanGrid[i][y]) {
        return false;
    }
    for(int k=0;k<(int)daMaze[i][y].connectionsTo.size();k++){
        if (daMaze[i][y].connectionsTo[k].obstacle==5) {
            emit cellTriggered(i,y,2+k);
            if(store){
                correctPath.push_back(&daMaze[i][y]);
                tempPath.push_back(new temporaryPathHolder(i,y,2+k));
                std::reverse(tempPath.begin(),tempPath.end());
            }
            //qDebug()<<"Found solution at: "<<i<<" "<<y;
            return true;
        }
    }

    QTime dieTime= QTime::currentTime().addMSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    std::array<int,4> nums{1,2,3,4};

    booleanGrid[i][y] = true;
    std::random_shuffle(nums.begin(),nums.end());
    correctPath.push_back(&daMaze[i][y]);
    for(int k=0;k<4;k++){
        if(runtimeTime.elapsed() > X*Y*3){
            return false;
        }
        switch(nums[k]){
        case 1:
            if(daMaze[i][y].connectionFrom[0]!=nullptr&&daMaze[i][y].connectionFrom[0]->obstacle==0){
                emit cellTriggered(i,y,0);
                if(recursiveSolvingFunction(booleanGrid, i, y-1,store)) {
                    if(store){
                        correctPath.push_back(&daMaze[i][y]);
                        tempPath.push_back(new temporaryPathHolder(i,y,0));
                    }
                    return true;
                }
            }
            break;
        case 2:
            if(daMaze[i][y].connectionFrom[1]!=nullptr&&daMaze[i][y].connectionFrom[1]->obstacle==0){
                emit cellTriggered(i,y,1);
                if(recursiveSolvingFunction(booleanGrid, i-1, y,store)) {
                    if(store){
                        correctPath.push_back(&daMaze[i][y]);
                        tempPath.push_back(new temporaryPathHolder(i,y,1));
                    }
                    return true;
                }
            }
            break;
        case 3:
            if(daMaze[i][y].connectionsTo[0].to!=nullptr&&daMaze[i][y].connectionsTo[0].obstacle==0){
                emit cellTriggered(i,y,2);
                if(recursiveSolvingFunction(booleanGrid, i, y +1,store)) {
                    if(store){
                        correctPath.push_back(&daMaze[i][y]);
                        tempPath.push_back(new temporaryPathHolder(i,y,2));
                    }
                    return true;}
            }
            break;
        case 4:
            if(daMaze[i][y].connectionsTo[1].to!=nullptr&&daMaze[i][y].connectionsTo[1].obstacle==0){
                emit cellTriggered(i,y,3);
                if(recursiveSolvingFunction(booleanGrid, i+1, y,store)) {
                    if(store){
                        correctPath.push_back(&daMaze[i][y]);
                        tempPath.push_back(new temporaryPathHolder(i,y,3));
                    }
                    return true;
                }
            }
            break;
        }

    }
    booleanGrid[i][y] = false;

    return false;
}



bool QMazes::recursiveSolvingFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int j, const int& tX, const int& tY) {
    if(runtimeTime.elapsed() > X*Y*1.4){
        return false;
    }

    if(i==tY&&j==tX){
        tempPath.push_back(new temporaryPathHolder(i,j,-1));
        return true;
    }

    if (i<0||i>=(int)daMaze.size()||j<0||j>=(int)daMaze[0].size()||booleanGrid[i][j]) {
        return false;
    }

    std::array<int,4> nums{1,2,3,4};

    booleanGrid[i][j] = true;
    std::random_shuffle(nums.begin(),nums.end());
    correctPath.push_back(&daMaze[i][j]);
    for(int k=0;k<4;k++){
        if(runtimeTime.elapsed() > X*Y*1.4){
            return false;
        }
        switch(nums[k]){
        case 1:
            if(daMaze[i][j].connectionFrom[0]!=nullptr&&daMaze[i][j].connectionFrom[0]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j-1,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,j,0));
                    return true;
                }
            }
            break;
        case 2:
            if(daMaze[i][j].connectionFrom[1]!=nullptr&&daMaze[i][j].connectionFrom[1]->obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i-1, j,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,j,1));
                    return true;
                }
            }
            break;
        case 3:
            if(daMaze[i][j].connectionsTo[0].to!=nullptr&&daMaze[i][j].connectionsTo[0].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i, j +1,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,j,2));
                    return true;}
            }
            break;
        case 4:
            if(daMaze[i][j].connectionsTo[1].to!=nullptr&&daMaze[i][j].connectionsTo[1].obstacle==0){
                if(recursiveSolvingFunction(booleanGrid, i+1, j,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,j,3));
                    return true;}
            }
            break;
        }

    }
    booleanGrid[i][j] = false;

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
    cell* currentCell = &daMaze[std::get<0>(indices)][std::get<1>(indices)];
    runtimeTime.start();
    while (true) {

        if(runtimeTime.elapsed()>(X*Y)*5){
            emit timeOut();
            return 0;
        }


        QTime dieTime= QTime::currentTime().addMSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
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
            for (int conn = 0; currentCell->connectionsTo.size()>conn;conn++) {
                if (currentCell->connectionsTo[conn].obstacle == MazeEnums::exit) {
                    emit cellTriggered(std::get<0>(indices),std::get<1>(indices),2+conn);
                    correctPath.push_back(currentCell);
                    tempPath.push_back(new temporaryPathHolder(std::get<0>(indices),std::get<1>(indices),2+conn));
                    return true; // Solução encontrada!
                }
            }


        } else {
            break; // Nenhuma saída encontrada
        }
    }
}

void QMazes::saveAsFile(QString fileName){
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/MazeOS/userMazes/"+fileName+".maz");

    if(file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate)){
        QTextStream out(&file);
        //qDebug()<<file.fileName();
        out<<name<<'\n';

        for(int i=0;i<2*Y+1;i++){
            for(int j=0;j<2*X+1;j++){
                if(i%2==0&&j%2==0){
                    //These are always corners (I got this from personal observation of my sketches of this)
                    out<<char(QMazeEnums::corner);
                    continue;
                }

                if(i%2!=0&&j%2!=0){
                    //Contarily, these are always cells
                    out<<char(QMazeEnums::cell);
                    continue;
                }
                if(i==0){
                    if(daMaze[0][(j-1)/2].connectionFrom[MazeEnums::up]==nullptr){
                        out<<char(QMazeEnums::null);
                        continue;
                    }

                    //if I allow the user to do an exit in these, i must change this
                    out<<char(QMazeEnums::entrance);
                    continue;
                }
                if(j==0){
                    if(daMaze[(i-1)/2][0].connectionFrom[MazeEnums::left]==nullptr){
                        out<<char(QMazeEnums::null);
                        continue;
                    }
                    //if I allow the user to do an exit in these, i must change this
                    out<<char(QMazeEnums::entrance);
                    continue;
                }
                if(i%2!=0){ //Since i represents lines, is odd and I've checked corners, null connections and cells,
                            // this can only be a Horizontal Connection since they "occupy" the same i (line) as cells (graphically speaking)

                    //If we are in the last row
                    if(j==2*X){
                        if(daMaze[(i-1)/2][(j-1)/2].connectionsTo[MazeEnums::right].obstacle!=MazeEnums::exit){
                            out<<char(QMazeEnums::null);
                            continue;
                        }
                        out<<char(QMazeEnums::exit);
                        continue;
                    }

                    else if(daMaze[(i-1)/2][(j-1)/2].connectionsTo[MazeEnums::right].obstacle==MazeEnums::obstacle){
                        out<<char(QMazeEnums::obstacle);
                        continue;
                    }

                    else out<<char(QMazeEnums::noObstacle);
                }
                else if(j%2!=0){ //Since j represents columns, is odd and I've checked corners, null connections and cells,
                    // this can only be a vertica lConnection since they "occupy" the same j (column) as cells (graphically speaking)


                    //this activates on the last line
                    if(i==2*Y){
                        if(daMaze[(i-1)/2][(j-1)/2].connectionsTo[MazeEnums::down].obstacle!=MazeEnums::exit){
                            out<<char(QMazeEnums::null);
                            continue;
                        }
                        out<<char(QMazeEnums::exit);
                        continue;
                    }

                    else if(daMaze[(i-1)/2][(j-1)/2].connectionsTo[MazeEnums::down].obstacle==MazeEnums::obstacle){
                        out<<char(QMazeEnums::obstacle);
                        continue;
                    }

                    else out<<char(QMazeEnums::noObstacle);
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
        do{
            QString inStr=in.readLine();
            if(inStr=="EVALUATED"){
                evaluated=1;
            }
            else mazeLines.push_back(inStr);
        } while(!in.atEnd());

        QMazes* returnMaze=new QMazes((mazeLines[0].size()-1)/2,(mazeLines.size()-1)/2);
        returnMaze->setEvaluated(evaluated);

        for(int i=0;i<(int)mazeLines.size();i++){
            for(int j=0;j<mazeLines[i].size();j++){
                if(i%2==0&&j%2==0){
                    //ignore corners
                    continue;
                }

                if(i%2!=0&&j%2!=0){
                    //ignore cells
                    continue;
                }
                if(i==0){
                    if(mazeLines[0][j]==QChar(QMazeEnums::entrance)){
                        returnMaze->daMaze[0][(j-1)/2].connectionFrom[MazeEnums::up]=new connection(new cell,&returnMaze->daMaze[0][(j-1)/2],MazeEnums::entrance);
                        continue;
                    }
                }
                if(j==0){
                    if(mazeLines[i][0]==QChar(QMazeEnums::entrance)){
                        returnMaze->daMaze[(i-1)/2][0].connectionFrom[MazeEnums::left]=new connection(new cell,&returnMaze->daMaze[(i-1)/2][0],MazeEnums::entrance);
                        continue;
                    }
                }
                if(i%2!=0){
                    if(j==(int)mazeLines[i].size()-1){
                        if(mazeLines[i][j]==QChar(QMazeEnums::exit)){
                            returnMaze->daMaze[(i-1)/2][(j-1)/2].connectionsTo[MazeEnums::right].obstacle=MazeEnums::exit;
                            continue;
                        }
                    }

                    else if(mazeLines[i][j]==QChar(QMazeEnums::noObstacle)){
                        returnMaze->daMaze[(i-1)/2][(j-1)/2].connectionsTo[MazeEnums::right].obstacle=MazeEnums::noObstacles;
                        continue;
                    }

                }
                else if(j%2!=0){ //Since j represents columns, is odd and I've checked corners, null connections and cells,
                    // this can only be a vertica lConnection since they "occupy" the same j (column) as cells (graphically speaking)


                    //this activates on the last line
                    if(i==(int)mazeLines.size()-1){
                        if(mazeLines[i][j]==QChar(QMazeEnums::exit)){
                            returnMaze->daMaze[(i-1)/2][(j-1)/2].connectionsTo[MazeEnums::down].obstacle=MazeEnums::exit;
                            continue;
                        }
                    }

                    else if(mazeLines[i][j]==QChar(QMazeEnums::noObstacle)){
                        returnMaze->daMaze[(i-1)/2][(j-1)/2].connectionsTo[MazeEnums::down].obstacle=MazeEnums::noObstacles;
                        continue;
                    }
                }
            }
        }
        file->close();
        returnMaze->name=mazeName;
        return returnMaze;
    }
    qDebug()<<"File Not Opened";
    return nullptr;
}
