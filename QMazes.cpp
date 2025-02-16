#include "qmazes.h"
#include <QDebug>

double n;

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
    if(daMaze.size()*daMaze[0].size()>20000){
        n=1;
    }
    else if(daMaze.size()*daMaze[0].size()>2500){
        n=2;
    } else if(daMaze.size()*daMaze[0].size()>1000){
        n=3;
    } else if(daMaze.size()*daMaze[0].size()>500){
        n=4;
    } else n=5;
    nameGenerator();
}



bool QMazes::recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y) {
    if (i<0||i>=(int)daMaze.size()||y<0||y>=(int)daMaze[0].size()||booleanGrid[i][y]) {
        return false;
    }
    QTime dieTime= QTime::currentTime().addMSecs(std::ceil(n));
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    //qDebug()<<"Path to: "<<i<< " "<<y;
    for(int k=0;k<(int)daMaze[i][y].connectionsTo.size();k++){
        if (daMaze[i][y].connectionsTo[k].obstacle==5) {
            tempCorrectPath.push_back(new temporaryCorrectPathHolder(i,y,2+k));
            emit cellTriggered(i,y,k+2);
            emit mazeSolved();
            //qDebug()<<"Found solution at: "<<i<<" "<<y;
            return true;
        }

    }
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
                    tempCorrectPath.push_back(new temporaryCorrectPathHolder(i,y,0));
                    return true;
                }
            }
            break;
        case 2:
            if(daMaze[i][y].connectionFrom[1]!=nullptr&&daMaze[i][y].connectionFrom[1]->obstacle==0){
                emit cellTriggered(i,y,1);
                if(recursiveSolver(booleanGrid, i-1, y)) {
                    correctPath.push_back(&daMaze[i][y]);
                    tempCorrectPath.push_back(new temporaryCorrectPathHolder(i,y,1));
                    return true;
                }
            }
            break;
        case 3:
            if(daMaze[i][y].connectionsTo[0].to!=nullptr&&daMaze[i][y].connectionsTo[0].obstacle==0){
                emit cellTriggered(i,y,2);
                if(recursiveSolver(booleanGrid, i, y +1)) {
                    correctPath.push_back(&daMaze[i][y]);
                    tempCorrectPath.push_back(new temporaryCorrectPathHolder(i,y,2));
                    return true;}
            }
            break;
        case 4:
            if(daMaze[i][y].connectionsTo[1].to!=nullptr&&daMaze[i][y].connectionsTo[1].obstacle==0){
                emit cellTriggered(i,y,3);
                if(recursiveSolver(booleanGrid, i+1, y)) {
                    correctPath.push_back(&daMaze[i][y]);
                    tempCorrectPath.push_back(new temporaryCorrectPathHolder(i,y,3));
                    return true;}
            }
            break;
        }

    }
    booleanGrid[i][y] = false;

    return false;
}

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
