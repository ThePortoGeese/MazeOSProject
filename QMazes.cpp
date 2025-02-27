#include "qmazes.h"
#include <QDebug>

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
    } else expectedMSToCompute=5;
}

//Reimplemented to show the connections as qt runs the app
void QMazes::connectionsPrint(){
    for(int i=0;i<(int)daMaze.size();i++){
        for(int y=0;y<(int)daMaze[0].size();y++){
            qDebug()<<"\nCell At Coordinate:"<<i<<y;
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
                    qDebug()<<"Null";
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

    nameGenerator();
}

bool QMazes::recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y) {

    if (i<0||i>=(int)daMaze.size()||y<0||y>=(int)daMaze[0].size()||booleanGrid[i][y]) {
        return false;
    }
    for(int k=0;k<(int)daMaze[i][y].connectionsTo.size();k++){
        if (daMaze[i][y].connectionsTo[k].obstacle==5) {
            correctPath.push_back(&daMaze[i][y]);
            tempPath.push_back(new temporaryPathHolder(i,y,2+k));
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
                if(recursiveSolver(booleanGrid, i, y-1)) {
                    correctPath.push_back(&daMaze[i][y]);
                    tempPath.push_back(new temporaryPathHolder(i,y,0));
                    return true;
                }
            }
            break;
        case 2:
            if(daMaze[i][y].connectionFrom[1]!=nullptr&&daMaze[i][y].connectionFrom[1]->obstacle==0){
                emit cellTriggered(i,y,1);
                if(recursiveSolver(booleanGrid, i-1, y)) {
                    correctPath.push_back(&daMaze[i][y]);
                    tempPath.push_back(new temporaryPathHolder(i,y,1));
                    return true;
                }
            }
            break;
        case 3:
            if(daMaze[i][y].connectionsTo[0].to!=nullptr&&daMaze[i][y].connectionsTo[0].obstacle==0){
                emit cellTriggered(i,y,2);
                if(recursiveSolver(booleanGrid, i, y +1)) {
                    correctPath.push_back(&daMaze[i][y]);
                    tempPath.push_back(new temporaryPathHolder(i,y,2));
                    return true;}
            }
            break;
        case 4:
            if(daMaze[i][y].connectionsTo[1].to!=nullptr&&daMaze[i][y].connectionsTo[1].obstacle==0){
                emit cellTriggered(i,y,3);
                if(recursiveSolver(booleanGrid, i+1, y)) {
                    correctPath.push_back(&daMaze[i][y]);
                    tempPath.push_back(new temporaryPathHolder(i,y,3));
                    return true;}
            }
            break;
        }

    }
    booleanGrid[i][y] = false;

    return false;
}

bool QMazes::recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y, const int& tX, const int& tY) {
    if(i==tX&&y==tY){
        tempPath.push_back(new temporaryPathHolder(i,y,-1));
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
                    tempPath.push_back(new temporaryPathHolder(i,y,0));
                    return true;
                }
            }
            break;
        case 2:
            if(daMaze[i][y].connectionFrom[1]!=nullptr&&daMaze[i][y].connectionFrom[1]->obstacle==0){
                if(recursiveSolver(booleanGrid, i-1, y,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,y,1));
                    return true;
                }
            }
            break;
        case 3:
            if(daMaze[i][y].connectionsTo[0].to!=nullptr&&daMaze[i][y].connectionsTo[0].obstacle==0){
                if(recursiveSolver(booleanGrid, i, y +1,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,y,2));
                    return true;}
            }
            break;
        case 4:
            if(daMaze[i][y].connectionsTo[1].to!=nullptr&&daMaze[i][y].connectionsTo[1].obstacle==0){
                if(recursiveSolver(booleanGrid, i+1, y,tX,tY)) {
                    tempPath.push_back(new temporaryPathHolder(i,y,3));
                    return true;}
            }
            break;
        }

    }
    booleanGrid[i][y] = false;

    return false;
}

//Random Name Generator (Basic but it works)

void QMazes::nameGenerator(){
    QFile fileName(":/labNames/resources/firstName.txt");
    QString firstName;
    if(fileName.exists()&&fileName.open(QFile::ReadOnly)){
        QTextStream out(&fileName);

        int expectedMSToCompute=std::rand()%31;
        int count=0;
        do{
            if(expectedMSToCompute==count){
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

        int expectedMSToCompute=std::rand()%35;
        int count=0;
        do{
            if(expectedMSToCompute==count){
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

QMazes* QMazes::convertFromView(PreviewMazeView* preview ){

    QMazes* convertedMaze= new QMazes(preview->X(),preview->Y());

    bool registeredEntrance=0;
    qDebug()<<preview->X();
    qDebug()<<preview->Y();
    for(const auto &k:preview->getHWalls()){
        if(k.second[0]->Brush()==cellB){
            convertedMaze->daMaze[k.first][0].connectionFrom[MazeEnums::right]=new connection(nullptr,&convertedMaze->daMaze[k.first][0],MazeEnums::entrance);
            registeredEntrance=1;
            break;
        }
    }

    bool registeredExit=0;
    for(const auto&k:preview->getHWalls()){

        for(int i=0;i<k.second.size();i++){
            if(i==0){
                if(k.second[i]->Brush()==cellB){
                    convertedMaze->daMaze[k.first][0].connectionFrom[MazeEnums::right]=new connection(nullptr,&convertedMaze->daMaze[k.first][0],MazeEnums::entrance);
                    registeredEntrance=1;
                    break;
                }
            }
            else if(i==k.second.size()-1){
                if(k.second[i]->Brush()==cellB){
                    convertedMaze->daMaze[k.first][i-1].connectionsTo[MazeEnums::right] = connection(&convertedMaze->daMaze[k.first][i],nullptr,MazeEnums::exit);
                    break;
                }
            }
            else if(k.second[i]->Brush()==cellB)
            {
                convertedMaze->daMaze[k.first][i-1].connectionsTo[MazeEnums::right].obstacle=MazeEnums::noObstacles;
            }

        }
    }

    for(auto&k:preview->getVWalls()){
        if(k.first==0&&!registeredEntrance){
            for(int i=0;i<preview->getVWalls().at(0).size();i++){
                if(k.second[i]->Brush()==cellB){
                    convertedMaze->daMaze[0][i].connectionFrom[MazeEnums::up]=new connection(nullptr,&convertedMaze->daMaze[0][i],MazeEnums::entrance);
                    break;
                }
            }
        }
        else if(k.first==preview->Y()&&!registeredExit){
            for(int i=0;i<k.second.size();i++){
                if(k.second[i]->Brush()==cellB){
                    convertedMaze->daMaze[k.first-1][i].connectionsTo[MazeEnums::down] = connection(&convertedMaze->daMaze[k.first][i],nullptr,MazeEnums::exit);
                    break;
                }
            }
        }
        else{
            for(int i=0;i<k.second.size();i++){
                if(k.second[i]->Brush()==cellB){
                    convertedMaze->daMaze[k.first-1][i].connectionsTo[MazeEnums::down].obstacle=MazeEnums::noObstacles;
                }
            }
        }
    }

    return convertedMaze;
}
