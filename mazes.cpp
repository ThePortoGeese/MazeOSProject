#include "mazes.h"
#include <QDebug>



double n;

mazes::mazes(int x,int y) {
    daMaze.resize(x,std::vector<cell>(y,cell()));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            daMaze[i][j].setup(daMaze,std::make_tuple(i,j));
        }
    }
    setX(x);
    setY(y);
}

//Debugging Function that verifies if the Maze was created correctly
void mazes::connectionsPrint(const std::vector<std::vector<cell>> &maze){
    for(int i=0;i<(int)maze.size();i++){
        for(int y=0;y<(int)maze[0].size();y++){
            qDebug()<<"\nCell At Coordinate:"<<i<<y;
            qDebug()<<"Memory adress:";
            qDebug()<<&maze[i][y];
            qDebug()<<"From Connections:";
            for(int k=0;k<(int)maze[i][y].connectionFrom.size();k++){
                if(maze[i][y].connectionFrom[k]==nullptr){
                    qDebug()<<"Null";
                }
                else {
                    qDebug()<<maze[i][y].connectionFrom[k]->from;
                    qDebug()<<"Obstacle: "<<maze[i][y].connectionFrom[k]->obstacle;
                }
            }
            qDebug()<<"To Connections:";
            for(int k=0;k<(int)maze[i][y].connectionsTo.size();k++){
                if(maze[i][y].connectionsTo[k].to==nullptr){
                    qDebug()<<"Null";
                }
                else {
                    qDebug()<<maze[i][y].connectionsTo[k].to;
                    qDebug()<<"Obstacle: "<<maze[i][y].connectionsTo[k].obstacle;
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

void mazes::createMaze(){
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
            outsideConnection->obstacle=2;
            daMaze[entranceX][entranceY].connectionFrom[i]=outsideConnection;
            break;
        }
    }

    for(int i=0;i<(int)daMaze[exitX][exitY].connectionsTo.size();i++){
        if(daMaze[exitX][exitY].connectionsTo[i].to==nullptr){
            daMaze[exitX][exitY].connectionsTo[i].obstacle=5;
            break;
        }
    }
    //qDebug()<<"Entrance X and Y: "<<entranceX<<" "<<entranceY;
    //qDebug()<<"Exit X and Y: "<<exitX<<" "<<exitY;
    std::vector<std::vector<bool>> booleanGrid(this->x(), std::vector<bool>(this->y(), false));
    this->recursiveDiggingFunction(entranceX,entranceY,booleanGrid);
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

void mazes::recursiveDiggingFunction(int x,int y, std::vector<std::vector<bool>>& booleanGrid){
    if(y<0||y>=this->y()||x<0||x>=this->x()) return;
    booleanGrid[x][y] = true;
    std::array<int,4> nums{1,2,3,4};
    for(int k=0;k<(int)daMaze[x][y].connectionsTo.size();k++){
        if(daMaze[x][y].connectionsTo[k].obstacle==5){
            return;
        }
    }

    std::random_shuffle(nums.begin(),nums.end());

    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(daMaze[x][y].connectionFrom[0]!=nullptr&&daMaze[x][y].connectionFrom[0]->obstacle!=2){
                if(!booleanGrid[x][y-1]){
                    daMaze[x][y].connectionFrom[0]->obstacle=0;
                    recursiveDiggingFunction(x , y-1,booleanGrid);
                }
            }
            break;
        case 2:
            if(daMaze[x][y].connectionFrom[1]!=nullptr&&daMaze[x][y].connectionFrom[1]->obstacle!=2){
                if(!booleanGrid[x-1][y]){
                    daMaze[x][y].connectionFrom[1]->obstacle=0;
                    recursiveDiggingFunction( x - 1, y,booleanGrid);
                }
            }
            break;
        case 3:
            if(daMaze[x][y].connectionsTo[0].to!=nullptr){
                if(!booleanGrid[x][y+1]){
                    daMaze[x][y].connectionsTo[0].obstacle=0;
                    recursiveDiggingFunction( x, y+1,booleanGrid);
                }
            }
            break;
        case 4:
            if(daMaze[x][y].connectionsTo[1].to!=nullptr){
                if(!booleanGrid[x+1][y]){
                    daMaze[x][y].connectionsTo[1].obstacle=0;
                    recursiveDiggingFunction(x+1, y,booleanGrid);
                }
            }
            break;
        }

    }

    return;
}

bool mazes::recursiveSolver(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y) {
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

void mazes::mazeSolver() {
    std::vector<std::vector<bool>> booleanGrid(daMaze.size(), std::vector<bool>(daMaze[0].size(), false));
    int ix=-1,iy=-1;
        for(int i=0;i<(int)daMaze.size();i++){
            for(int k=0;k<(int)daMaze[i][0].connectionFrom.size();k++){
                if(daMaze[i][0].connectionFrom[k]!=nullptr){
                    if(daMaze[i][0].connectionFrom[k]->obstacle==2){
                        ix=i;
                        iy=0;
                        emit mazes::cellTriggered(ix,iy,k);
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
                            emit mazes::cellTriggered(ix,iy,k);
                        }
                    }
                }
            }
        }

        //qDebug()<<"Ix value: "<<ix<< " Iy value: "<<iy;

        if(recursiveSolver(booleanGrid, ix, iy)){

            //qDebug()<<"Returned True";
        } else ;//qDebug()<<"Returned Flase"

}

void mazes::nameGenerator(){
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
