#include "simulationwindow.h"
#include "frmcells.h"
#include "ui_simulationwindow.h"
#include <iostream>
#include <QTime>
#include <QThread>
#include <QMessageBox>
#include <QElapsedTimer>
int ix=-1,iy=-1;
int n;
int emptyCells = 0;
QElapsedTimer runTime;

simulationWindow::simulationWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::simulationWindow)
{
    maze={
        {1, -1,  0,  0, -1,  0,  0,  0,  0, -1, -1, -1,  0,  0, -1},
        {0, -1, -1,  0, -1, -1, -1,  0, -1, -1,  0,  0,  0, -1,  0},
        {0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0, -1, -1, -1,  0},
        {0, -1, -1, -1, -1,  0, -1, -1, -1, -1,  0,  0,  0,  0,  0},
        {0,  0,  0,  0, -1,  0,  0,  0,  0, -1, -1, -1, -1, -1,  0},
        {0, -1, -1,  0, -1, -1, -1, -1,  0,  0,  0,  0,  0, -1,  0},
        {0,  0, -1,  0,  0,  0,  0, -1, -1, -1, -1, -1,  0, -1,  0},
        {-1, 0, -1, -1, -1, -1,  0,  0,  0,  0,  0,  0,  0, -1,  0},
        {0,  0,  0,  0,  0, -1, -1, -1, -1, -1, -1,  0, -1, -1,  0},
        {0, -1, -1, -1,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0},
        {0,  0,  0, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1,  0, -1},
        {-1, -1,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  -1,  0,  0},
        {0,  0,  0, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1,  0},
        {0, -1,  -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1,  2}
    };
    ui->setupUi(this);
    n=5;
    for(int i=0;i<(int)this->maze.size()+2;i++){
        frmCells* a =new frmCells;
        a->setStyleSheet("background-color: rgba(255, 0, 0, 1);");
        ui->labLayout->addWidget(a,0,i);
    }
    for(int i=0;i<(int)this->maze.size();i++){
        std::vector <frmCells*> placeholderVector;
        for(int y=0;y<(int)this->maze[0].size();y++){
            frmCells* a =new frmCells;

            if(maze[i][y]==0){
                a->setStyleSheet("background-color: rgba(255, 255, 0, 0);");
                a->cellOpacity=0;
                emptyCells++;
            } else if(maze[i][y]==1){
                a->setStyleSheet("background-color: rgba(0, 0 ,255, 1);");
                ix=i;
                iy=y;
                emptyCells++;
            } else if(maze[i][y]==-1){
                a->setStyleSheet("background-color: rgba(255, 0, 0, 1);");
            } else if(maze[i][y]==2){
                a->setStyleSheet("background-color: rgba(0, 255, 0, 1);");
                emptyCells++;
            }

            ui->labLayout->addWidget(a,i+1,y+1);
            placeholderVector.push_back(a);
        }
        frameVector.push_back(placeholderVector);
    }
    for(int i=0;i<(int)this->maze.size()+2;i++){
        frmCells* a =new frmCells;
        a->setStyleSheet("background-color: rgba(255, 0, 0, 1);");
        ui->labLayout->addWidget(a,maze.size()+1,i);
    }
    for(int i=1;i<(int)this->maze.size()+1;i++){
        frmCells* a =new frmCells;
        a->setStyleSheet("background-color: rgba(255, 0, 0, 1);");
        ui->labLayout->addWidget(a,i,0);
    }
    for(int i=1;i<(int)this->maze.size()+1;i++){
        frmCells* a =new frmCells;
        a->setStyleSheet("background-color: rgba(255, 0, 0, 1);");
        ui->labLayout->addWidget(a,i,this->maze.size()+1);
    }
}

simulationWindow::~simulationWindow()
{
    for(int i=0;i<(int)this->maze.size();i++){
        for(int y=0;y<(int)this->maze[0].size();y++){
            delete frameVector[i][y];
        }
    }
    frameVector.erase(frameVector.begin(),frameVector.end());
    delete ui;
}

void simulationWindow::on_pushButton_clicked()
{
    runTime.start();
    mazeSolver(ix,iy);
    ui->pushButton->setEnabled(0);
}

bool simulationWindow::recursiveFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y) {
    if (i<0||i>=this->maze.size()||y<0||y>=maze[0].size()||booleanGrid[i][y]||this->maze[i][y]==-1) {
        return false;
    }
    std::vector<int> nums={1,2,3,4};
    if (this->maze[i][y] == 2) {
        if(n==5){
            QMessageBox msgBox;
            msgBox.setText("Encontrei uma solução!");
            msgBox.setInformativeText("Tempo demorado: "+QString::number((float)runTime.elapsed()/1000)+"s.");
            n=1;
            msgBox.exec();
            return true;
        }
    }
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    booleanGrid[i][y] = true;
    std::random_shuffle(nums.begin(),nums.end());

    if(frameVector[i][y]->cellOpacity<100) frameVector[i][y]->cellOpacity+=70;
    frameVector[i][y]->setStyleSheet("background-color: rgba(255, 255, 0, "+QString::number(frameVector[i][y]->cellOpacity)+");");
    for(int k=0;k<4;k++){
        switch(nums[k]){
        case 1:
            if(recursiveFunction(booleanGrid, i - 1, y)) return true;
            else break;
        case 2:
            if(recursiveFunction(booleanGrid, i + 1, y)) return true;
            else break;
        case 3:
            if(recursiveFunction(booleanGrid, i, y - 1)) return true;
            else break;
        case 4:
            if(recursiveFunction(booleanGrid, i, y + 1)) return true;
            else break;
        }
    }
    booleanGrid[i][y] = false;

    return false;
}

void simulationWindow::mazeSolver(const int& ix,const int& iy) {
    std::vector<std::vector<bool>> booleanGrid(maze.size(), std::vector<bool>(maze[0].size(), false));
    recursiveFunction(booleanGrid, ix, iy);
}
