#ifndef QMAZESCONVERSION_H
#define QMAZESCONVERSION_H
#include "GraphicsViews/previewmazeview.h"
#include "qmazes.h"

class QMazesConversionMethods
{
public:

    static QMazes* convertFromView(PreviewMazeView* preview ){
        QMazes* convertedMaze= new QMazes(preview->X(),preview->Y());

        //qDebug()<<preview->X();
        //qDebug()<<preview->Y();
        for(const auto&k:preview->getHWalls()){
            for(int i=0;i<k.second.size();i++){
                if(i==0){
                    if(k.second[0]->getEntrance()){
                        convertedMaze->daMaze[k.first][0].connectionFrom[MazeEnums::left]=new connection(nullptr,&convertedMaze->daMaze[k.first][0],MazeEnums::entrance);
                    }

                    else if(k.second[0]->getExit()){
                        convertedMaze->daMaze[k.first][0].connectionFrom[MazeEnums::left]=new connection(nullptr,&convertedMaze->daMaze[k.first][0],MazeEnums::exit);
                    }
                }
                else if(i==preview->X()){
                    if(k.second[i]->getExit()){
                        convertedMaze->daMaze[k.first][i-1].connectionsTo[MazeEnums::right] = connection(&convertedMaze->daMaze[k.first][i],nullptr,MazeEnums::exit);
                    }
                    else if(k.second[i]->getEntrance()){
                        convertedMaze->daMaze[k.first][i-1].connectionsTo[MazeEnums::right] = connection(&convertedMaze->daMaze[k.first][i],nullptr,MazeEnums::entrance);
                    }
                }
                else if(k.second[i]->Brush()==cellB)
                {
                    convertedMaze->daMaze[k.first][i-1].connectionsTo[MazeEnums::right].obstacle=MazeEnums::noObstacles;
                }

            }
        }

        for(auto&k:preview->getVWalls()){
            if(k.first==0){
                for(int i=0;i<preview->getVWalls().at(0).size();i++){
                    if(k.second[i]->getEntrance()){
                        convertedMaze->daMaze[0][i].connectionFrom[MazeEnums::up]=new connection(nullptr,&convertedMaze->daMaze[0][i],MazeEnums::entrance);
                    }

                    else if(k.second[i]->getExit()){
                        convertedMaze->daMaze[0][i].connectionFrom[MazeEnums::up]=new connection(nullptr,&convertedMaze->daMaze[0][i],MazeEnums::exit);
                    }
                }
            }
            else if(k.first==preview->Y()){
                for(int i=0;i<k.second.size();i++){

                    if(k.second[i]->getExit()){
                        convertedMaze->daMaze[k.first-1][i].connectionsTo[MazeEnums::down] = connection(&convertedMaze->daMaze[k.first][i],nullptr,MazeEnums::exit);
                    }
                    else if(k.second[i]->getEntrance()){
                        convertedMaze->daMaze[k.first-1][i].connectionsTo[MazeEnums::down] = connection(&convertedMaze->daMaze[k.first][i],nullptr,MazeEnums::entrance);
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
        //convertedMaze->connectionsPrint();
        return convertedMaze;
    }

    static void convertPreviewFromQMazes(const QMazes* maze,PreviewMazeView* preview){
        preview->newMaze();
        preview->incrementCellsH(maze->daMaze[0].size()-2);
        preview->incrementCellsV(maze->daMaze.size()-2);

        for(unsigned long long i=0;i<maze->getMaze().size();i++){
            for(unsigned long long j=0;j<maze->getMaze()[i].size();j++){
                if(i==0){
                    if(maze->getMaze()[0][j].connectionFrom[MazeEnums::up]!=nullptr){
                        if(maze->getMaze()[0][j].connectionFrom[MazeEnums::up]->obstacle==MazeEnums::entrance){
                            preview->vWalls[0][j]->setBrush(Qt::green);
                            preview->vWalls[0][j]->setEntrance(1);
                            preview->addEntrance();
                        } else if(maze->getMaze()[0][j].connectionFrom[MazeEnums::up]->obstacle==MazeEnums::exit){
                            preview->vWalls[0][j]->setBrush(Qt::red);
                            preview->vWalls[0][j]->setExit(1);
                            preview->addExit();
                        }
                    }
                }

                if(j==0){
                    if(maze->getMaze()[i][0].connectionFrom[MazeEnums::left]!=nullptr){
                        if(maze->getMaze()[i][0].connectionFrom[MazeEnums::left]->obstacle==MazeEnums::entrance){
                            preview->hWalls[i][0]->setBrush(Qt::green);
                            preview->hWalls[i][0]->setEntrance(1);
                            preview->addEntrance();
                        } else if(maze->getMaze()[i][0].connectionFrom[MazeEnums::left]->obstacle==MazeEnums::exit){
                            preview->hWalls[i][0]->setBrush(Qt::red);
                            preview->hWalls[i][0]->setExit(1);
                            preview->addExit();
                        }
                    }
                }

                if(maze->getMaze()[i][j].connectionsTo[MazeEnums::right].obstacle==MazeEnums::noObstacles){
                    preview->hWalls[i][j+1]->setBrush(cellB);
                }
                else if(maze->getMaze()[i][j].connectionsTo[MazeEnums::right].obstacle==MazeEnums::exit){
                    preview->hWalls[i][j+1]->setBrush(Qt::red);
                    preview->hWalls[i][j+1]->setExit(1);
                    preview->addExit();
                }
                else if(maze->getMaze()[i][j].connectionsTo[MazeEnums::right].obstacle==MazeEnums::entrance){
                    preview->hWalls[i][j+1]->setBrush(Qt::green);
                    preview->hWalls[i][j+1]->setEntrance(1);
                    preview->addEntrance();
                }

                if(maze->getMaze()[i][j].connectionsTo[MazeEnums::down].obstacle==MazeEnums::noObstacles){
                    preview->vWalls[i+1][j]->setBrush(cellB);
                }
                else if(maze->getMaze()[i][j].connectionsTo[MazeEnums::down].obstacle==MazeEnums::exit){
                    preview->vWalls[i+1][j]->setBrush(Qt::red);
                    preview->vWalls[i+1][j]->setExit(1);
                    preview->addExit();
                }
                else if(maze->getMaze()[i][j].connectionsTo[MazeEnums::down].obstacle==MazeEnums::entrance){
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
