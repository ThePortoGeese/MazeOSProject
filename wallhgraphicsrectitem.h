#ifndef WALLHGRAPHICSRECTITEM_H
#define WALLHGRAPHICSRECTITEM_H
#include "abstractgraphicsrectitem.h"

class WallHGraphicsRectItem : public AbstractGraphicsRectItem
{
public:
    explicit WallHGraphicsRectItem(qreal x,qreal y,QGraphicsItem *parent = nullptr) : AbstractGraphicsRectItem(x,y,parent){};

    WallHGraphicsRectItem() : AbstractGraphicsRectItem(){};

    QRectF boundingRect() const override  {
        return QRectF(0,0,1,4);
    }
};

#endif // WALLHGRAPHICSRECTITEM_H
