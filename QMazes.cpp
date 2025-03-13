#include "qmazes.h"
#include <QDebug>

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


int expectedMSToCompute;

QMazes::QMazes(int x,int y) : mazeClass(x,y){
    if(daMaze.size()*daMaze[0].size()>20000){
        expectedMSToCompute=1;
    }
    else if(daMaze.size()*daMaze[0].size()>2500){
        expectedMSToCompute=2;
    } else if(daMaze.size()*daMaze[0].size()>1000){
        expectedMSToCompute=3;
    } else if(daMaze.size()*daMaze[0].size()>500){
        expectedMSToCompute=4;
    } else expectedMSToCompute=10;
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

bool QMazes::recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y,const bool& store) {
    if (i<0||i>=(int)daMaze.size()||y<0||y>=(int)daMaze[0].size()||booleanGrid[i][y]) {
        return false;
    }
    for(int k=0;k<(int)daMaze[i][y].connectionsTo.size();k++){
        if (daMaze[i][y].connectionsTo[k].obstacle==5) {
            emit cellTriggered(i,y,2+k);
            if(store){
            correctPath.push_back(&daMaze[i][y]);
            tempPath.push_back(new temporaryPathHolder(i,y,2+k));
            }
            //qDebug()<<"Found solution at: "<<i<<" "<<y;
            return true;
        }
    }

    QTime dieTime= QTime::currentTime().addMSecs(expectedMSToCompute);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    std::array<int,4> nums{1,2,3,4};

    booleanGrid[i][y] = true;
    std::random_shuffle(nums.begin(),nums.end());
    correctPath.push_back(&daMaze[i][y]);
    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(daMaze[i][y].connectionFrom[0]!=nullptr&&daMaze[i][y].connectionFrom[0]->obstacle==0){
                emit cellTriggered(i,y,0);
                if(recursiveSolver(booleanGrid, i, y-1,store)) {
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
                if(recursiveSolver(booleanGrid, i-1, y,store)) {
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
                if(recursiveSolver(booleanGrid, i, y +1,store)) {
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
                if(recursiveSolver(booleanGrid, i+1, y,store)) {
                    if(store){
                        correctPath.push_back(&daMaze[i][y]);
                        tempPath.push_back(new temporaryPathHolder(i,y,3));
                    }
                    return true;}
            }
            break;
        }

    }
    booleanGrid[i][y] = false;

    return false;
}

bool QMazes::recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int j, const int& tX, const int& tY) {
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
        switch(nums[k]){
        case 1:
            if(daMaze[i][j].connectionFrom[0]!=nullptr&&daMaze[i][j].connectionFrom[0]->obstacle==0){
                if(recursiveSolver(booleanGrid, i, j-1,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,j,0));
                    return true;
                }
            }
            break;
        case 2:
            if(daMaze[i][j].connectionFrom[1]!=nullptr&&daMaze[i][j].connectionFrom[1]->obstacle==0){
                if(recursiveSolver(booleanGrid, i-1, j,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,j,1));
                    return true;
                }
            }
            break;
        case 3:
            if(daMaze[i][j].connectionsTo[0].to!=nullptr&&daMaze[i][j].connectionsTo[0].obstacle==0){
                if(recursiveSolver(booleanGrid, i, j +1,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,j,2));
                    return true;}
            }
            break;
        case 4:
            if(daMaze[i][j].connectionsTo[1].to!=nullptr&&daMaze[i][j].connectionsTo[1].obstacle==0){
                if(recursiveSolver(booleanGrid, i+1, j,tX,tY)) {
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
        do{
            mazeLines.push_back(in.readLine());
        } while(!in.atEnd());

        QMazes* returnMaze=new QMazes((mazeLines[0].size()-1)/2,(mazeLines.size()-1)/2);

        for(int i=0;i<mazeLines.size();i++){
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
