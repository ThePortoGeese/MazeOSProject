#ifndef QMAZESCONVERSION_H
#define QMAZESCONVERSION_H
#include "GraphicsViews/previewmazeview.h"
#include "qmazes.h"

class QMazesConversionMethods
{
public:

    static QMazes* convertFromView(PreviewMazeView* preview ){
        QMazes* convertedMaze= new QMazes(preview->Y(),preview->X());

        qDebug()<<preview->X();
        qDebug()<<preview->Y();
        for(const auto&k:preview->getHWalls()){
            for(int i=0;i<k.second.size();i++){
                if(i==0){
                    if(k.second[0]->getEntrance()){
                        convertedMaze->MazeStructure[k.first][0].connectionFrom[QMazes::left]=new connection(nullptr,&convertedMaze->MazeStructure[k.first][0],QMazes::entrance);
                    }

                    else if(k.second[0]->getExit()){
                        convertedMaze->MazeStructure[k.first][0].connectionFrom[QMazes::left]=new connection(nullptr,&convertedMaze->MazeStructure[k.first][0],QMazes::exit);
                    }
                }
                else if(i==preview->X()){
                    if(k.second[i]->getExit()){
                        convertedMaze->MazeStructure[k.first][i-1].connectionsTo[QMazes::right] = connection(&convertedMaze->MazeStructure[k.first][i],nullptr,QMazes::exit);
                    }
                    else if(k.second[i]->getEntrance()){
                        convertedMaze->MazeStructure[k.first][i-1].connectionsTo[QMazes::right] = connection(&convertedMaze->MazeStructure[k.first][i],nullptr,QMazes::entrance);
                    }
                }
                else if(k.second[i]->Brush()==cellB)
                {
                    convertedMaze->MazeStructure[k.first][i-1].connectionsTo[QMazes::right].obstacle=QMazes::noObstacles;
                }

            }
        }

        for(auto&k:preview->getVWalls()){
            if(k.first==0){
                for(int i=0;i<preview->getVWalls().at(0).size();i++){
                    if(k.second[i]->getEntrance()){
                        convertedMaze->MazeStructure[0][i].connectionFrom[QMazes::up]=new connection(nullptr,&convertedMaze->MazeStructure[0][i],QMazes::entrance);
                    }

                    else if(k.second[i]->getExit()){
                        convertedMaze->MazeStructure[0][i].connectionFrom[QMazes::up]=new connection(nullptr,&convertedMaze->MazeStructure[0][i],QMazes::exit);
                    }
                }
            }
            else if(k.first==preview->Y()){
                for(int i=0;i<k.second.size();i++){

                    if(k.second[i]->getExit()){
                        convertedMaze->MazeStructure[k.first-1][i].connectionsTo[QMazes::down] = connection(&convertedMaze->MazeStructure[k.first][i],nullptr,QMazes::exit);
                    }
                    else if(k.second[i]->getEntrance()){
                        convertedMaze->MazeStructure[k.first-1][i].connectionsTo[QMazes::down] = connection(&convertedMaze->MazeStructure[k.first][i],nullptr,QMazes::entrance);
                    }
                }
            }
            else{
                for(int i=0;i<k.second.size();i++){
                    if(k.second[i]->Brush()==cellB){
                        convertedMaze->MazeStructure[k.first-1][i].connectionsTo[QMazes::down].obstacle=QMazes::noObstacles;
                    }
                }
            }
        }
        convertedMaze->connectionsPrint();
        return convertedMaze;
    }

    static void convertPreviewFromQMazes(const QMazes* maze,PreviewMazeView* preview){
        preview->newMaze();
        preview->incrementCellsH(maze->MazeStructure[0].size()-2);
        preview->incrementCellsV(maze->MazeStructure.size()-2);

        for(unsigned long long i=0;i<maze->getMaze().size();i++){
            for(unsigned long long j=0;j<maze->getMaze()[i].size();j++){
                if(i==0){
                    if(maze->getMaze()[0][j].connectionFrom[QMazes::up]!=nullptr){
                        if(maze->getMaze()[0][j].connectionFrom[QMazes::up]->obstacle==QMazes::entrance){
                            preview->vWalls[0][j]->setBrush(Qt::green);
                            preview->vWalls[0][j]->setEntrance(1);
                            preview->addEntrance();
                        } else if(maze->getMaze()[0][j].connectionFrom[QMazes::up]->obstacle==QMazes::exit){
                            preview->vWalls[0][j]->setBrush(Qt::red);
                            preview->vWalls[0][j]->setExit(1);
                            preview->addExit();
                        }
                    }
                }

                if(j==0){
                    if(maze->getMaze()[i][0].connectionFrom[QMazes::left]!=nullptr){
                        if(maze->getMaze()[i][0].connectionFrom[QMazes::left]->obstacle==QMazes::entrance){
                            preview->hWalls[i][0]->setBrush(Qt::green);
                            preview->hWalls[i][0]->setEntrance(1);
                            preview->addEntrance();
                        } else if(maze->getMaze()[i][0].connectionFrom[QMazes::left]->obstacle==QMazes::exit){
                            preview->hWalls[i][0]->setBrush(Qt::red);
                            preview->hWalls[i][0]->setExit(1);
                            preview->addExit();
                        }
                    }
                }

                if(maze->getMaze()[i][j].connectionsTo[QMazes::right].obstacle==QMazes::noObstacles){
                    preview->hWalls[i][j+1]->setBrush(cellB);
                }
                else if(maze->getMaze()[i][j].connectionsTo[QMazes::right].obstacle==QMazes::exit){
                    preview->hWalls[i][j+1]->setBrush(Qt::red);
                    preview->hWalls[i][j+1]->setExit(1);
                    preview->addExit();
                }
                else if(maze->getMaze()[i][j].connectionsTo[QMazes::right].obstacle==QMazes::entrance){
                    preview->hWalls[i][j+1]->setBrush(Qt::green);
                    preview->hWalls[i][j+1]->setEntrance(1);
                    preview->addEntrance();
                }

                if(maze->getMaze()[i][j].connectionsTo[QMazes::down].obstacle==QMazes::noObstacles){
                    preview->vWalls[i+1][j]->setBrush(cellB);
                }
                else if(maze->getMaze()[i][j].connectionsTo[QMazes::down].obstacle==QMazes::exit){
                    preview->vWalls[i+1][j]->setBrush(Qt::red);
                    preview->vWalls[i+1][j]->setExit(1);
                    preview->addExit();
                }
                else if(maze->getMaze()[i][j].connectionsTo[QMazes::down].obstacle==QMazes::entrance){
                    preview->vWalls[i+1][j]->setBrush(Qt::green);
                    preview->vWalls[i+1][j]->setEntrance(1);
                    preview->addEntrance();
                }
            }
        }
        preview->fitInView(preview->sceneRect());
    }
};

#endif // QMAZESCONVERSION_H
