#ifndef CellGraphicsRectItem_H
#define CellGraphicsRectItem_H

#include "abstractgraphicsrectitem.h"

class CellGraphicsRectItem : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit CellGraphicsRectItem(qreal x,qreal y,QGraphicsItem *parent = nullptr) : QGraphicsObject(parent){
        setAcceptTouchEvents(1);
        setAcceptHoverEvents(1);

        prepareGeometryChange();
        this->setPos(x,y);
    }

    QRectF boundingRect() const override{
        return QRectF(0,0,4,4);
    }

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget) override{
        Q_UNUSED(option);
        Q_UNUSED(widget);
        painter->setBrush(brush);
        painter->setPen(Qt::NoPen);
        painter->drawRect(boundingRect());
    }

    const QBrush& Brush(){
        return brush;
    }
    void setBrush(QBrush br){
        brush=br;
        update();
    }

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
private:
    bool clicked=0;
    QBrush brush = QBrush(backGround);
signals:
    void solveToEvent(CellGraphicsRectItem*);
    void clearCells();

};

#endif // CellGraphicsRectItem_H
