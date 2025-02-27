#ifndef WALLVGRAPHICSRECTITEM_H
#define WALLVGRAPHICSRECTITEM_H
#include "abstractgraphicsrectitem.h"

class WallVGraphicsRectItem : public AbstractGraphicsRectItem
{
public:
    explicit WallVGraphicsRectItem(qreal x,qreal y,QGraphicsItem *parent = nullptr) : AbstractGraphicsRectItem(x,y,parent){};

    WallVGraphicsRectItem() : AbstractGraphicsRectItem(){};

    QRectF boundingRect() const override  {
        return QRectF(0,0,4,1);
    }
};

#endif // WALLVGRAPHICSRECTITEM_H
