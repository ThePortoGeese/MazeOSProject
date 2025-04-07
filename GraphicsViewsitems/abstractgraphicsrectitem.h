#ifndef AbstractGraphicsRectItem_H
#define AbstractGraphicsRectItem_H
#include "qpainter.h"
#include <QGraphicsObject>
static const QBrush cellB(QColor(0,0,0));
static const QBrush backGround(QColor(47, 108, 168));
static const QBrush correctPathColor(QColor(0, 200, 81));



class AbstractGraphicsRectItem : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit AbstractGraphicsRectItem(qreal x,qreal y,QGraphicsItem *parent = nullptr) : QGraphicsObject(parent){
        setAcceptTouchEvents(1);
        setAcceptHoverEvents(1);

        prepareGeometryChange();
        this->setPos(x,y);
    }

    AbstractGraphicsRectItem():QGraphicsObject(){};
    const QBrush& Brush(){
        return brush;
    }
    void setBrush(QBrush br){
        brush=br;
        update();
    }

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option);
        Q_UNUSED(widget);
        painter->setBrush(brush);


        if(entrance){
            painter->setBrush(Qt::green);

        } else if(exit){
            painter->setBrush(Qt::red);
        }

        painter->setPen(Qt::NoPen);
        painter->drawRect(boundingRect());
    }

    void setOuter(){
        outerWall=1;
    }
    const bool& getOuter(){
        return outerWall;
    }
    void setEntrance(bool b) {entrance=b;}

    void setExit(bool b) {exit=b;}
    const bool& getEntrance(){
        return entrance;
    }
    const bool& getExit(){
        return exit;
    }
signals:
    void addedEntrance(AbstractGraphicsRectItem*);
    void addedExit(AbstractGraphicsRectItem*);

    void removedEntrance();
    void removedExit();
protected:
    bool outerWall=0;
    bool entrance = 0;
    bool exit = 0;
    QBrush brush = QBrush(backGround);

};

#endif // AbstractGraphicsRectItem_H
