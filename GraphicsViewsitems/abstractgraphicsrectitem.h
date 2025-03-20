#ifndef AbstractGraphicsRectItem_H
#define AbstractGraphicsRectItem_H
#include "qpainter.h"
#include <QGraphicsObject>
static const QBrush cellB(QColor(0,0,0));
static const QBrush backGround(QColor(111, 183, 214));
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

    //Need to Rework this
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override{
        if(brush==cellB) {
            emit removedEntrance();
            emit removedExit();
            setBrush(backGround);
        }
        else {
             setBrush(cellB);
             emit addedEntrance(this);
             emit addedExit(this);
        }

        QGraphicsObject::mousePressEvent(event);
    }
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option);
        Q_UNUSED(widget);
        painter->setBrush(brush);
        painter->setPen(Qt::NoPen);
        painter->drawRect(boundingRect());
    }

    void setOuter(){
        outerWall=1;
    }
    const bool& getOuter(){
        return outerWall;
    }
signals:
    void addedEntrance(AbstractGraphicsRectItem*);
    void addedExit(AbstractGraphicsRectItem*);

    void removedEntrance();
    void removedExit();
protected:
    bool outerWall=0;
    QBrush brush = QBrush(backGround);

};

#endif // AbstractGraphicsRectItem_H
