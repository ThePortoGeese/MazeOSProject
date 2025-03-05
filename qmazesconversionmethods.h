#ifndef QMAZESCONVERSION_H
#define QMAZESCONVERSION_H
#include "previewmazeview.h"
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
                    if(k.second[0]->Brush()==cellB){
                        convertedMaze->daMaze[k.first][0].connectionFrom[MazeEnums::left]=new connection(nullptr,&convertedMaze->daMaze[k.first][0],MazeEnums::entrance);
                    }
                }
                else if(i==preview->X()){
                    if(k.second[i]->Brush()==cellB){
                        convertedMaze->daMaze[k.first][i-1].connectionsTo[MazeEnums::right] = connection(&convertedMaze->daMaze[k.first][i],nullptr,MazeEnums::exit);
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
                    if(k.second[i]->Brush()==cellB){
                        convertedMaze->daMaze[0][i].connectionFrom[MazeEnums::up]=new connection(nullptr,&convertedMaze->daMaze[0][i],MazeEnums::entrance);
                        //Break here since there can only be entrances on this line and only one exists
                        break;
                    }
                }
            }
            else if(k.first==preview->Y()){
                for(int i=0;i<k.second.size();i++){
                    if(k.second[i]->Brush()==cellB){
                        convertedMaze->daMaze[k.first-1][i].connectionsTo[MazeEnums::down] = connection(&convertedMaze->daMaze[k.first][i],nullptr,MazeEnums::exit);
                        //Same for exits
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
                        preview->vWalls[0][j]->setBrush(cellB);
                        preview->addEntrance();
                    }
                }

                if(j==0){
                    if(maze->getMaze()[i][0].connectionFrom[MazeEnums::left]!=nullptr){
                        preview->hWalls[i][0]->setBrush(cellB);
                        preview->addEntrance();
                    }
                }

                if(maze->getMaze()[i][j].connectionsTo[MazeEnums::right].obstacle==MazeEnums::noObstacles){
                    preview->hWalls[i][j+1]->setBrush(cellB);
                }
                else if(maze->getMaze()[i][j].connectionsTo[MazeEnums::right].obstacle==MazeEnums::exit){
                    preview->hWalls[i][j+1]->setBrush(cellB);
                    preview->addExit();
                }

                if(maze->getMaze()[i][j].connectionsTo[MazeEnums::down].obstacle==MazeEnums::noObstacles){
                    preview->vWalls[i+1][j]->setBrush(cellB);
                }
                else if(maze->getMaze()[i][j].connectionsTo[MazeEnums::down].obstacle==MazeEnums::exit){
                    preview->vWalls[i+1][j]->setBrush(cellB);
                    preview->addExit();
                }
            }
        }
    }
};

#endif // QMAZESCONVERSION_H
