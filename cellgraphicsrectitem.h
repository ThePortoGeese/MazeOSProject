#ifndef CellGraphicsRectItem_H
#define CellGraphicsRectItem_H

#include <abstractgraphicsrectitem.h>

class CellGraphicsRectItem : public AbstractGraphicsRectItem
{
    Q_OBJECT
public:
    explicit CellGraphicsRectItem(qreal x,qreal y,QGraphicsItem *parent = nullptr) : AbstractGraphicsRectItem(x,y,parent){
    }

    QRectF boundingRect() const override;

    CellGraphicsRectItem():AbstractGraphicsRectItem(){};

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
private:
    bool clicked=0;
signals:
    void solveToEvent(CellGraphicsRectItem*);
    void clearCells();
};

#endif // CellGraphicsRectItem_H
