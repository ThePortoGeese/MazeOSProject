#ifndef PREVIEWMAZEVIEW_H
#define PREVIEWMAZEVIEW_H
#include <QGraphicsView>
#include <stack>
#include <thread>
#include <vector>
#include <GraphicsViewsitems/wallhgraphicsrectitem.h>
#include <map>
#include <GraphicsViewsitems/wallvgraphicsrectitem.h>
#include "GraphicsViewsitems/cellgraphicsrectitem.h"
#include "qevent.h"

class PreviewMazeView : public QGraphicsView
{
    friend class QMazesConversionMethods;
    Q_OBJECT
public:
    PreviewMazeView(QWidget* parent=0);

    const std::map<int, QVector<WallHGraphicsRectItem*>>& getHWalls() {
        return hWalls;
    }

    const std::map<int, QVector<WallVGraphicsRectItem*>>& getVWalls() {
        return vWalls;
    }

    void newMaze();

    static void deleteScene(QGraphicsScene* deleteScene){
        if(deleteScene!=nullptr){
            qDeleteAll(deleteScene->items());
            deleteScene->clear();
        }
    }
    void setToggleBrush(const bool& boolean){
        toggleBrush=boolean;
    }
    bool entranceExists(){
        return entrance;
    }
    bool exitExists(){
        return exit;
    }
    enum toggleBrush{
        brushRemoveWalls,
        brushAddWalls
    };

    void mouseMoveEvent(QMouseEvent *event) override;
public slots:

    void incrementCellsH(int h);

    void incrementCellsV(int h);

    void decrementCellsH(int h);

    void decrementCellsV(int h);

    void addEntrance(AbstractGraphicsRectItem* a=nullptr){
        if(!entrance){
            entrance=1;
        } else{
            if(a!=nullptr) a->setBrush(backGround);
            emit errorCatched("Só pode haver uma entrada.");
        }
    }
    void addExit(AbstractGraphicsRectItem* a=nullptr){

        if(!exit){
            exit=1;
        } else{
            if(a!=nullptr) a->setBrush(backGround);
            emit errorCatched("Só pode haver uma saída.");
        }
    }
    void removeExit(){
        exit=0;
    }
    void removeEntrance(){
        entrance=0;
    }
    int X() {return x;}
    int Y(){return y;}

    void setSavedStatus(bool saved){
        savedStatus=saved;
    }
    const bool& getSavedStatus(){
        return savedStatus;
    }

    void undoActions();

    void mousePressEvent(QMouseEvent *event) override;
private:
    bool entrance,exit;
    std::map<int,QVector<WallHGraphicsRectItem*>> hWalls;
    std::map<int,QVector<WallVGraphicsRectItem*>> vWalls;
    int x=2,y=2;

    std::stack<AbstractGraphicsRectItem*> undoStack;

    bool savedStatus=0;
    //Since there are only 2 brushes, I just made it a bool value
    bool toggleBrush=brushRemoveWalls;

public slots:

signals:
    void errorCatched(QString errorLog);
    void updateSaveIndicator();

};

#endif // PREVIEWMAZEVIEW_H
