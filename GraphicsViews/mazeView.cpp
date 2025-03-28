#include "mazeview.h"

double squareSizeWidth;
double squareSizeHeight;

QGraphicsRectItem* corner;

mazeView::mazeView(QWidget* parent) : QGraphicsView::QGraphicsView(parent) {
    setAlignment(Qt::AlignTop | Qt::AlignLeft);

    //Setting Ze Background

    setBackgroundBrush(backGround);
};

void mazeView::drawMaze(QMazes* currentMaze){
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    cells.clear();

    QGraphicsScene* sceneToDelete=scene();

    std::thread worker(deleteScene,sceneToDelete);

    this->setScene(new QGraphicsScene());


    squareSizeHeight=4;
    squareSizeWidth=4;

    //Good practice to resize the vector before any operations
    cells.resize(currentMaze->getMaze().size(), std::vector<CellGraphicsRectItem*>(currentMaze->getMaze()[0].size()));
    for(int i=0;i<(int)currentMaze->getMaze().size();i++){
        for(int y=0;y<(int)currentMaze->getMaze()[0].size();y++){
            cells[i][y]=new CellGraphicsRectItem(y*squareSizeWidth+(y+1)*squareSizeWidth/4,i*squareSizeHeight+(i+1)*squareSizeHeight/4);
            scene()->addItem(cells[i][y]);
            cells[i][y]->setBrush(cellB);
            connect(cells[i][y],SIGNAL(solveToEvent(CellGraphicsRectItem*)),this,SLOT(findRectItemPosition(CellGraphicsRectItem*)));
            connect(cells[i][y],SIGNAL(clearCells()),this,SLOT(clearCells()));
        }
    }
    for(int i=0;i<(int)currentMaze->getMaze().size();i++){
        for(int y=0;y<(int)currentMaze->getMaze()[0].size();y++){
            if(currentMaze->getMaze()[i][y].connectionFrom[0]!=nullptr){
                if(currentMaze->getMaze()[i][y].connectionFrom[MazeEnums::left]->obstacle==MazeEnums::noObstacles){
                    QGraphicsRectItem* a=scene()->addRect(0,0,std::ceil(squareSizeWidth/4),squareSizeHeight,Qt::NoPen,cellB);
                    a->setPos(cells[i][y]->scenePos().x()-squareSizeWidth/4,cells[i][y]->scenePos().y());
                }
                else if(currentMaze->getMaze()[i][y].connectionFrom[MazeEnums::left]->obstacle==MazeEnums::entrance){
                    //qDebug()<<i<<" "<<y;

                    QGraphicsRectItem* a=scene()->addRect(0,0,std::ceil(squareSizeWidth/4),squareSizeHeight,Qt::NoPen,Qt::green);
                    a->setPos(0,cells[i][y]->scenePos().y());
                }
                else if(currentMaze->getMaze()[i][y].connectionFrom[MazeEnums::left]->obstacle==MazeEnums::exit){
                    //qDebug()<<i<<" "<<y;

                    QGraphicsRectItem* a=scene()->addRect(0,0,std::ceil(squareSizeWidth/4),squareSizeHeight,Qt::NoPen,Qt::red);
                    a->setPos(0,cells[i][y]->scenePos().y());
                }
            }
            if(currentMaze->getMaze()[i][y].connectionFrom[MazeEnums::up]!=nullptr){
                if(currentMaze->getMaze()[i][y].connectionFrom[1]->obstacle==MazeEnums::noObstacles){

                    QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,std::ceil(squareSizeHeight/4),Qt::NoPen,cellB);
                    a->setPos(cells[i][y]->scenePos().x(),cells[i][y]->scenePos().y()-squareSizeHeight/4);
                }
                else if(currentMaze->getMaze()[i][y].connectionFrom[MazeEnums::up]->obstacle==MazeEnums::entrance){
                    //qDebug()<<i<<" "<<y;

                    QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,std::ceil(squareSizeHeight/4),Qt::NoPen,Qt::green);
                    a->setPos(cells[i][y]->scenePos().x(),0);
                }
                else if(currentMaze->getMaze()[i][y].connectionFrom[MazeEnums::up]->obstacle==MazeEnums::exit){
                    //qDebug()<<i<<" "<<y;

                    QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,std::ceil(squareSizeHeight/4),Qt::NoPen,Qt::red);
                    a->setPos(cells[i][y]->scenePos().x(),0);
                }
            }
            if(currentMaze->getMaze()[i][y].connectionsTo[MazeEnums::right].to!=nullptr){
                if(currentMaze->getMaze()[i][y].connectionsTo[MazeEnums::right].obstacle==MazeEnums::noObstacles){
                    QGraphicsRectItem* a=scene()->addRect(0,0,std::ceil(squareSizeWidth/4),squareSizeHeight,Qt::NoPen,cellB);
                    a->setPos(cells[i][y]->scenePos().x()+squareSizeWidth,cells[i][y]->scenePos().y());
                }
            }
            else if(currentMaze->getMaze()[i][y].connectionsTo[MazeEnums::right].obstacle==MazeEnums::exit){
                QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,squareSizeHeight,Qt::NoPen,Qt::red);
                a->setPos(cells[i][y]->scenePos().x()+squareSizeWidth,cells[i][y]->scenePos().y());
            }
            else if(currentMaze->getMaze()[i][y].connectionsTo[MazeEnums::right].obstacle==MazeEnums::entrance){
                QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,squareSizeHeight,Qt::NoPen,Qt::green);
                a->setPos(cells[i][y]->scenePos().x()+squareSizeWidth,cells[i][y]->scenePos().y());
            }
            if(currentMaze->getMaze()[i][y].connectionsTo[MazeEnums::down].to!=nullptr){
                if(currentMaze->getMaze()[i][y].connectionsTo[MazeEnums::down].obstacle==MazeEnums::noObstacles){
                    QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,std::ceil(squareSizeHeight/4),Qt::NoPen,cellB);
                    a->setPos(cells[i][y]->scenePos().x(),cells[i][y]->scenePos().y()+squareSizeHeight);
                }
            }
            else if(currentMaze->getMaze()[i][y].connectionsTo[MazeEnums::down].obstacle==MazeEnums::exit){
                QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,squareSizeHeight,Qt::NoPen,Qt::red);
                a->setPos(cells[i][y]->scenePos().x(),cells[i][y]->scenePos().y()+squareSizeHeight);
            }
            else if(currentMaze->getMaze()[i][y].connectionsTo[MazeEnums::down].obstacle==MazeEnums::entrance){
                QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,squareSizeHeight,Qt::NoPen,Qt::green);
                a->setPos(cells[i][y]->scenePos().x(),cells[i][y]->scenePos().y()+squareSizeHeight);
            }

        }
    }
    scene()->setSceneRect(0, 0,5*currentMaze->x()+1,5*currentMaze->y()+1);

    worker.join();
}

void mazeView::clearCells(){
    if(!busy){
        emit updateStatusText();
        for(auto i : scene()->items()){
            auto it= dynamic_cast<QGraphicsRectItem*>(i);

            if(it!=nullptr) it->setBrush(cellB);
            else {
                auto ip = dynamic_cast<CellGraphicsRectItem*>(i);
                ip->setBrush(cellB);
            }
        }
    }
}
void mazeView::changeCellColour(int x,int y,int conNb,QBrush brush){
    cells[x][y]->setBrush(brush);

    QGraphicsRectItem* a;
    switch(conNb){
    case 0:
        a = (QGraphicsRectItem*)((scene()->items(QPoint(cells[x][y]->scenePos().x()-squareSizeWidth/8,cells[x][y]->scenePos().y()+1)))[0]);
        if(a!=nullptr){ a->setBrush(brush);}
        break;
    case 1:
        a = (QGraphicsRectItem*)((scene()->items(QPoint(cells[x][y]->scenePos().x()+1,cells[x][y]->scenePos().y()-squareSizeHeight/8)))[0]);
        if(a!=nullptr){ a->setBrush(brush);}
        break;
    case 2:
        a = (QGraphicsRectItem*)((scene()->items(QPoint(cells[x][y]->scenePos().x()+squareSizeWidth/8+squareSizeWidth,cells[x][y]->scenePos().y()+1)))[0]);
        if(a!=nullptr){ a->setBrush(brush);}

        break;
    case 3:
        a = (QGraphicsRectItem*)((scene()->items(QPoint(cells[x][y]->scenePos().x()+1,cells[x][y]->scenePos().y()+squareSizeHeight/8+squareSizeHeight)))[0]);
        if(a!=nullptr){ a->setBrush(brush);}
        break;
    }

}

void mazeView::findRectItemPosition(CellGraphicsRectItem *rect)
{
    for(int i=0;i<(int)cells.size();i++){
        auto k = std::find(cells[i].begin(),cells[i].end(),rect);
        if(k!=cells[i].end()){
            int d=std::distance(cells[i].begin(),k);
            emit chartPathToCell(d,i);
        }
    }
}

