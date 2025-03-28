#ifndef INSTRUCTIONCIRCLEITEM_H
#define INSTRUCTIONCIRCLEITEM_H

#include "abstractshapeitem.h"
#include "qpen.h"
#include <QFile>

class InstructionCircleItem : public AbstractShapeItem
{
public:
    InstructionCircleItem();
    InstructionCircleItem(int n, QPointF pos, InstructionCircleItem* circle = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


    QRectF boundingRect() const override  {
        return QRectF(pos().x(),pos().y(),120,100);
    }

    QRectF ellipseRect() const{
        return QRectF(pos().x()+30,pos().y()+10,60,60);
    }

    QRectF textRect() const{
        return QRectF(pos().x(),pos().y()+75,120,35);
    }

    QString getInstructionText(){
        QFile file(":/others/resources/proccessinstructions.txt");

        if(file.open(QIODevice::ReadOnly)){
            QTextStream in(&file);

            while(!in.atEnd()){
                if(in.readLine().toInt()==nInstruction){
                    return in.readLine();
                } else in.readLine();
            }
        }
        qDebug()<<"Instructions File Unopened/No valid Instruction";
        return "";
    }
    void setPreviousCircle(InstructionCircleItem* ptr){
        previousCircle = ptr;
        update();
    }

    void setNPen(QPen p){
        nPen=p;
        update();
    }

    void setToDefaultNPen(){
        nPen=QPen(Qt::gray);
        update();
    }

    void setTextPen(QPen p){
        textPen=p;
        update();
    }

    void setToDefaultTextPen(){
        textPen=QPen(Qt::gray);
        update();
    }
private:
    int nInstruction;
    QString txtInstruction;
    InstructionCircleItem* previousCircle = nullptr;
    QPen nPen = QPen(Qt::gray);
    QPen textPen = QPen(Qt::gray);
};

#endif // INSTRUCTIONCIRCLEITEM_H
