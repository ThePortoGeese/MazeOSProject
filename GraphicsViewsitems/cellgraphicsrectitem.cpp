#include "cellgraphicsrectitem.h"
#include <QGraphicsSceneMouseEvent>

void CellGraphicsRectItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        clicked=1;
        emit solveToEvent(this);
    }
}

void CellGraphicsRectItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event){
    if(this->clicked){
        clicked=0;
        emit clearCells();
    }
    QGraphicsObject::hoverLeaveEvent(event);
}
