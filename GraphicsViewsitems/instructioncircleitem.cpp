#include "instructioncircleitem.h"
#include "qpainter.h"

InstructionCircleItem::InstructionCircleItem(int n, QPointF pos, InstructionCircleItem* circle) :
    nInstruction(n),
    previousCircle(circle)
{
    setPos(pos);
}

void InstructionCircleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    /*if(previousCircle !=nullptr){
        painter->drawLine();
    }*/
    painter->setPen(Qt::NoPen);

    painter->setBrush(brush);

    painter->drawEllipse(ellipseRect());

    painter->setPen(textPen);
    QTextOption opt;

    opt.setAlignment(Qt::AlignHCenter);
    painter->drawText(textRect(),getInstructionText(),opt);
    painter->setPen(nPen);
    painter->drawText(ellipseRect().x()+ellipseRect().width()/2-painter->font().pointSizeF()/2,ellipseRect().y()+ellipseRect().height()/2+painter->font().pointSizeF()/2,QString::number(nInstruction));

}
