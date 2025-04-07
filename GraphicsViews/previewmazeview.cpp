#include "previewmazeview.h"




PreviewMazeView::PreviewMazeView(QWidget* parent) : QGraphicsView(parent){
    setAlignment(Qt::AlignTop | Qt::AlignLeft);
    setScene(new QGraphicsScene);
    scene()->setBackgroundBrush(backGround);
    setMouseTracking(0);
}

void PreviewMazeView::newMaze(){

    while(!undoStack.empty()){
        undoStack.pop();
    }

    savedStatus=0;
    setScene(new QGraphicsScene);
    scene()->setBackgroundBrush(backGround);
    x=2;
    y=2;
    entrance=0;
    exit=0;

    hWalls.clear();
    vWalls.clear();

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            CellGraphicsRectItem* rect;
            rect =new CellGraphicsRectItem(j*4+(j+1)*1,i*4+(i+1)*1);

            scene()->addItem(rect);
            rect->setBrush(cellB);
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++){
            WallHGraphicsRectItem* rect=new WallHGraphicsRectItem(j*5,i*5+1);
            switch(j){
            case 0:
                connect(rect,SIGNAL(addedEntrance(AbstractGraphicsRectItem*)),this,SLOT(addEntrance(AbstractGraphicsRectItem*)));
                connect(rect,SIGNAL(removedEntrance()),this,SLOT(removeEntrance()));
                rect->setOuter();
                break;
            case 2:
                connect(rect,SIGNAL(addedExit(AbstractGraphicsRectItem*)),this,SLOT(addExit(AbstractGraphicsRectItem*)));
                connect(rect,SIGNAL(removedExit()),this,SLOT(removeExit()));
                rect->setOuter();
                break;
            }
            scene()->addItem(rect);
            hWalls[i].push_back(rect);
        }
    }

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++){
            WallVGraphicsRectItem* rect=new WallVGraphicsRectItem(i*5+1,j*5);
            switch(j){
            case 0:
                connect(rect,SIGNAL(addedEntrance(AbstractGraphicsRectItem*)),this,SLOT(addEntrance(AbstractGraphicsRectItem*)));
                connect(rect,SIGNAL(removedEntrance()),this,SLOT(removeEntrance()));
                rect->setOuter();
                break;
            case 2:
                connect(rect,SIGNAL(addedExit(AbstractGraphicsRectItem*)),this,SLOT(addExit(AbstractGraphicsRectItem*)));
                connect(rect,SIGNAL(removedExit()),this,SLOT(removeExit()));
                rect->setOuter();
                break;
            }
            scene()->addItem(rect);
            vWalls[j].push_back(rect);
        }
    }
    setSceneRect(0,0,10.8,10.8);
    savedStatus=0;
}

void PreviewMazeView::incrementCellsH(int h){
    if(x<128) {emit updateSaveIndicator();savedStatus=0;}
    for(int j=0;j<h;j++){
        //It's hard to explain how I figured the exact coordinates for each piece but I needed to grab a paper to visualise it
        if(x<=128){
            x+=1;
            //Addint top vertical exit
            {
                auto rect =new WallVGraphicsRectItem((x-1)*4+(x)*1,0);
                connect(rect,SIGNAL(addedEntrance(AbstractGraphicsRectItem*)),this,SLOT(addEntrance(AbstractGraphicsRectItem*)));
                connect(rect,SIGNAL(removedEntrance()),this,SLOT(removeEntrance()));
                scene()->addItem(rect);
                vWalls[0].push_back(rect);
                rect->setOuter();
            }
            //Adding Cells
            for(int i=0;i<y;i++){
                CellGraphicsRectItem* rect;
                rect =new CellGraphicsRectItem((x-1)*4+(x)*1,i*4+(i+1)*1);

                scene()->addItem(rect);
                rect->setBrush(cellB);
            }

            //New Hrorizontal Walls
            for(int i=0;i<y;i++){
                WallHGraphicsRectItem* rect=new WallHGraphicsRectItem((x-1)*4+(x-1),(i)*4+(i+1)*1);
                scene()->addItem(rect);
                //Making it so the last wall in this vector is a possible exit
                hWalls[i].insert(x-1,rect);
                /*qDebug()<<"Name: "<<i;
                qDebug()<<hWalls[i].size()<<" "<<x;
                qDebug()<<i<<" "<<y;*/
                hWalls[i][x]->setPos(hWalls[i][x]->x()+5,hWalls[i][x]->y());
            }

            //Vertical Walls
            for(int i=0;i<y-1;i++){
                WallVGraphicsRectItem* rect=new WallVGraphicsRectItem((x-1)*4+(x),(i+1)*4+(i+1)*1);
                scene()->addItem(rect);
                vWalls[i+1].push_back(rect);
            }
            //Adding bottom vertical exit
            {
                auto rect =new WallVGraphicsRectItem((x-1)*4+(x)*1,y*5);
                connect(rect,SIGNAL(addedExit(AbstractGraphicsRectItem*)),this,SLOT(addExit(AbstractGraphicsRectItem*)));
                connect(rect,SIGNAL(removedExit()),this,SLOT(removeExit()));
                scene()->addItem(rect);
                vWalls[y].push_back(rect);
                rect->setOuter();
            }

            setSceneRect(0, 0, sceneRect().width()+5,sceneRect().height());
        }
        fitInView(sceneRect());
    }
}

void PreviewMazeView::incrementCellsV(int h){
    if(y<128) {emit updateSaveIndicator();savedStatus=0;}
    for(int j=0;j<h;j++){
        if(y<=128){
            y+=1;
            //Addint first horizontal entrance
            {
                auto rect =new WallHGraphicsRectItem(0,(y-1)*5+1);
                connect(rect,SIGNAL(addedEntrance(AbstractGraphicsRectItem*)),this,SLOT(addEntrance(AbstractGraphicsRectItem*)));
                connect(rect,SIGNAL(removedEntrance()),this,SLOT(removeEntrance()));
                scene()->addItem(rect);
                hWalls[y-1].push_back(rect);
                rect->setOuter();
            }
            //Adding new Cells
            for(int i=0;i<x;i++){
                CellGraphicsRectItem* rect;
                rect =new CellGraphicsRectItem(i*5+1,(y-1)*5+1);

                scene()->addItem(rect);
                rect->setBrush(cellB);
            }

            //Adding new Horizontal Walls
            for(int i=0;i<x-1;i++){
                WallHGraphicsRectItem* rect=new WallHGraphicsRectItem((i+1)*5,(y-1)*5+1);
                scene()->addItem(rect);

                hWalls[y-1].push_back(rect);
            }
            vWalls[y]=vWalls[y-1];
            vWalls[y-1].clear();
            //Swapping vertical walls position
            for(int i=0;i<vWalls[y].size();i++){
                vWalls[y][i]->setPos(vWalls[y][i]->x(),vWalls[y][i]->y()+5);
            }
            //Adding new vertical walls
            for(int i=0;i<x;i++){
                WallVGraphicsRectItem* rect=new WallVGraphicsRectItem(i*5+1,((y-1)*5));
                scene()->addItem(rect);

                vWalls[y-1].push_back(rect);

            }

            //Adding bottom vertical exit
            {
                auto rect =new WallHGraphicsRectItem((x)*5,(y-1)*5+1);
                connect(rect,SIGNAL(addedExit(AbstractGraphicsRectItem*)),this,SLOT(addExit(AbstractGraphicsRectItem*)));
                connect(rect,SIGNAL(removedExit()),this,SLOT(removeExit()));
                scene()->addItem(rect);
                hWalls[y-1].push_back(rect);
                rect->setOuter();
            }

            /*for(int i=0;i<vWalls[0].size();i++){
                vWalls[y][i]->setPos(i*5+1,(y+1)*5);
            }*/


            setSceneRect(0, 0, sceneRect().width(), sceneRect().height()+5);
        }
        fitInView(sceneRect());
    }
    if(y+h>2) emit updateSaveIndicator();
}

void PreviewMazeView::decrementCellsH(int h){
    if(x>2) {emit updateSaveIndicator();savedStatus=0;}
    for(int i=0;i<h;i++){
        if(x==2) continue;
        //Removes all the cells
        for(int j=0;j<y;j++){
            auto cell=scene()->items(QPoint((x-1)*5+1,j*5+1))[0];
            scene()->removeItem(cell);
            delete cell;
        }
        for(int j=0;j<y;j++){
            //This deleted all horizontal walls from the last line
            scene()->removeItem(hWalls[j][x-1]);
            delete hWalls[j][x-1];
            hWalls[j][x-1]=hWalls[j][x];
            hWalls[j].removeAt(x);
            hWalls[j][x-1]->setPos(hWalls[j][x-1]->x()-5,hWalls[j][x-1]->y());
            //I still have to manually delete it cause I didn't use smart pointers (oops)
        }

        for(int j=0;j<y+1;j++){
            if(j==0){
                if(vWalls[j][x-1]->Brush()==cellB){
                    entrance=0;
                }
            } else if(j==y){
                if(vWalls[j][x-1]->Brush()==cellB){
                    exit=0;
                }
            }
            //This deleted all horizontal walls from the last line
            scene()->removeItem(vWalls[j][x-1]);
            delete vWalls[j][x-1];
            vWalls[j].removeAt(x-1);

            //I still have to manually delete it cause I didn't use smart pointers (oops)
        }

        setSceneRect(0,0,sceneRect().width()-5,sceneRect().height());
        x-=1;
    }
    fitInView(sceneRect());
}

void PreviewMazeView::decrementCellsV(int h){
    if(y>2) {emit updateSaveIndicator();savedStatus=0;}
    for(int i=0;i<h;i++){
        if(y==2) continue;
        //Removes all the cells
        for(int j=0;j<x;j++){
            auto cell=scene()->items(QPoint(j*5+1,(y-1)*5+1))[0];
            scene()->removeItem(cell);
            delete cell;
        }
        for(int j=0;j<x+1;j++){
            //This deleted all horizontal walls from the last line


            //Btw, hWalls always has y-1 lines of X columns, this is reversed for vWalls which has y lines of X-1 columns


            //I need to make these variables 0 or the program will think there's an entrance and exit to the maze when there isn't
            if(j==0){
                if(hWalls[y-1][j]->Brush()==cellB){
                    entrance=0;
                }
            } else if(j==0){
                if(hWalls[y-1][j]->Brush()==cellB){
                    exit=0;
                }
            }

            scene()->removeItem(hWalls[y-1][j]);
            delete hWalls[y-1][j];
            //I still have to manually delete it cause I didn't use smart pointers (oops)
        }
        hWalls[y-1].clear();

        for(int j=0;j<x;j++){
            //This deleted all vertical walls from the last line
            scene()->removeItem(vWalls[y-1][j]);
            delete vWalls[y-1][j];
            //I still have to manually delete it cause I didn't use smart pointers (oops)
        }
        vWalls[y-1].clear();
        vWalls[y-1]=vWalls[y];
        vWalls[y].clear();

        for(int j=0;j<x;j++){
            vWalls[y-1][j]->setPos(vWalls[y-1][j]->x(),vWalls[y-1][j]->y()-5);
        }

        setSceneRect(0,0,sceneRect().width(),sceneRect().height()-5);
        y-=1;
    }
    fitInView(sceneRect());
}

void PreviewMazeView::mouseMoveEvent(QMouseEvent *event){
    if (items(event->pos()).isEmpty() || event->buttons() != Qt::LeftButton) {
        QWidget::mouseMoveEvent(event);
        return;
    }

    auto *item = dynamic_cast<AbstractGraphicsRectItem*>(items(event->pos()).first());
    if (!item) {
        QWidget::mouseMoveEvent(event);
        return;
    }

    if (!dynamic_cast<WallHGraphicsRectItem*>(item) && !dynamic_cast<WallVGraphicsRectItem*>(item)) {
        QWidget::mouseMoveEvent(event);
        return;
    }

    if (!item->getOuter()) {
        if ((toggleBrush == brushRemoveWalls && item->Brush() == backGround) ||
            (toggleBrush == brushAddWalls && item->Brush() == cellB)) {
            undoStack.push(item);
        }

        item->setBrush(toggleBrush ? backGround : cellB);
    } else {
        if (!entranceExists() && toggleBrush == brushRemoveWalls) {
            undoStack.push(item);
            item->setEntrance(1);
            item->setBrush(cellB);
            entrance = 1;
        }
        else if (!exitExists() && toggleBrush == brushRemoveWalls) {
            if(item->getEntrance()) return;
            undoStack.push(item);
            item->setExit(1);
            item->setBrush(cellB);
            exit = 1;
        }
        else if ((item->Brush() == cellB || item->Brush() == Qt::green || item->Brush() == Qt::red) && toggleBrush == brushAddWalls) {
            undoStack.push(item);
            if (item->getEntrance()) {
                entrance = 0;
                item->setEntrance(0);
            }
            else if (item->getExit()) {
                exit = 0;
                item->setExit(0);
            }
            item->setBrush(backGround);
        }
    }

    savedStatus = 0;
    QWidget::mouseMoveEvent(event);
    emit updateSaveIndicator();
}

void PreviewMazeView::mousePressEvent(QMouseEvent *event){
    if(items(event->pos()).count()>0&&event->buttons()==Qt::LeftButton){
        while(!undoStack.empty()){
            undoStack.pop();
        }
    }
    QWidget::mousePressEvent(event);
}

void PreviewMazeView::undoActions(){
    while(!undoStack.empty()){
        if(undoStack.top()->getOuter()){
            if(undoStack.top()->getEntrance()){
                entrance=0;
                undoStack.top()->setEntrance(0);
            }
            else if(undoStack.top()->getExit()){
                exit=0;
                undoStack.top()->setExit(0);
            }
        }

        undoStack.top()->setBrush(undoStack.top()->Brush()==cellB?backGround : cellB);

        undoStack.pop();
    }
    emit updateSaveIndicator();
}
