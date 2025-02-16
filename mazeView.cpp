#include "mazeview.h"
#include "QGraphicsRectItem"
double squareSizeWidth;
double squareSizeHeight;

static const QBrush cellB(QColor(0,0,0));
static const QBrush backGround(QColor(0,255,255));

void deleteScene(QGraphicsScene* deleteScene){
    if(deleteScene!=nullptr){
    qDeleteAll(deleteScene->items());
    deleteScene->clear();
    }
}

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
    cells.resize(currentMaze->getMaze().size(), std::vector<QGraphicsRectItem*>(currentMaze->getMaze()[0].size()));
    for(int i=0;i<(int)currentMaze->getMaze().size();i++){
        for(int y=0;y<(int)currentMaze->getMaze()[0].size();y++){
            cells[i][y]=scene()->addRect(0,0,squareSizeWidth,squareSizeHeight,Qt::NoPen,cellB);
            cells[i][y]->setPos(y*squareSizeWidth+(y+1)*squareSizeWidth/4,i*squareSizeHeight+(i+1)*squareSizeHeight/4);
        }
    }

    for(int i=0;i<(int)currentMaze->getMaze().size();i++){
        for(int y=0;y<(int)currentMaze->getMaze()[0].size();y++){
            if(currentMaze->getMaze()[i][y].connectionFrom[0]!=nullptr){
                if(currentMaze->getMaze()[i][y].connectionFrom[0]->obstacle==0){
                    QGraphicsRectItem* a=scene()->addRect(0,0,std::ceil(squareSizeWidth/4),squareSizeHeight,Qt::NoPen,cellB);
                    a->setPos(cells[i][y]->scenePos().x()-squareSizeWidth/4,cells[i][y]->scenePos().y());
                }
                else if(currentMaze->getMaze()[i][y].connectionFrom[0]->obstacle==2){
                    qDebug()<<i<<" "<<y;

                    QGraphicsRectItem* a=scene()->addRect(0,0,std::ceil(squareSizeWidth/4),squareSizeHeight,Qt::NoPen,cellB);
                    a->setPos(0,cells[i][y]->scenePos().y());
                }
            }
            if(currentMaze->getMaze()[i][y].connectionFrom[1]!=nullptr){
                if(currentMaze->getMaze()[i][y].connectionFrom[1]->obstacle==0){

                    QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,std::ceil(squareSizeHeight/4),Qt::NoPen,cellB);
                    a->setPos(cells[i][y]->scenePos().x(),cells[i][y]->scenePos().y()-squareSizeHeight/4);
                }
                else if(currentMaze->getMaze()[i][y].connectionFrom[1]->obstacle==2){
                    qDebug()<<i<<" "<<y;

                    QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,std::ceil(squareSizeHeight/4),Qt::NoPen,cellB);
                    a->setPos(cells[i][y]->scenePos().x(),0);
                }
            }
            if(currentMaze->getMaze()[i][y].connectionsTo[0].to!=nullptr){
                if(currentMaze->getMaze()[i][y].connectionsTo[0].obstacle==0){
                    QGraphicsRectItem* a=scene()->addRect(0,0,std::ceil(squareSizeWidth/4),squareSizeHeight,Qt::NoPen,cellB);
                    a->setPos(cells[i][y]->scenePos().x()+squareSizeWidth,cells[i][y]->scenePos().y());
                }
            }
            else if(currentMaze->getMaze()[i][y].connectionsTo[0].obstacle==5){
                QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,squareSizeHeight,Qt::NoPen,cellB);
                a->setPos(cells[i][y]->scenePos().x()+squareSizeWidth,cells[i][y]->scenePos().y());
            }
            if(currentMaze->getMaze()[i][y].connectionsTo[1].to!=nullptr){
                if(currentMaze->getMaze()[i][y].connectionsTo[1].obstacle==0){
                    QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,std::ceil(squareSizeHeight/4),Qt::NoPen,cellB);
                    a->setPos(cells[i][y]->scenePos().x(),cells[i][y]->scenePos().y()+squareSizeHeight);
                }
            }
            else if(currentMaze->getMaze()[i][y].connectionsTo[1].obstacle==5){
                QGraphicsRectItem* a=scene()->addRect(0,0,squareSizeWidth,squareSizeHeight,Qt::NoPen,cellB);
                a->setPos(cells[i][y]->scenePos().x(),cells[i][y]->scenePos().y()+squareSizeHeight);
            }

        }
    }
    scene()->setSceneRect(0, 0, squareSizeWidth*currentMaze->getMaze()[0].size()+(squareSizeWidth*currentMaze->getMaze()[0].size())/4,  squareSizeHeight*currentMaze->getMaze().size()+(squareSizeHeight*currentMaze->getMaze().size()+1)/4);
    worker.join();
}

void mazeView::clearCells(){
    for(auto i : scene()->items()){
        ((QGraphicsRectItem*)i)->setBrush(cellB);
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

