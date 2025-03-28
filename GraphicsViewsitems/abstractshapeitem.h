#ifndef ABSTRACTSHAPEITEM_H
#define ABSTRACTSHAPEITEM_H

#include "qbrush.h"
#include <QGraphicsItem>

class AbstractShapeItem : public QGraphicsItem
{
public:
    AbstractShapeItem(QGraphicsItem* parent=nullptr) : QGraphicsItem(parent){}
    void setBrush(QBrush br){
        brush = br;
        update();
    }

    void setToDefaultBrush(){
        brush = QColor(5,30,60);
        update();
    }
protected:
    QBrush brush = QColor(5,30,60);
};

#endif // ABSTRACTSHAPEITEM_H
