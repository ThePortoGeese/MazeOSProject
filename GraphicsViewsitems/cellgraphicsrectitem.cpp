#include "cellgraphicsrectitem.h"

void CellGraphicsRectItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    clicked=1;
    emit solveToEvent(this);
}

void CellGraphicsRectItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event){
    if(this->clicked){
        clicked=0;
        emit clearCells();
    }
    QGraphicsObject::hoverLeaveEvent(event);
}
