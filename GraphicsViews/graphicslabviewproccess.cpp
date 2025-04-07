#include "graphicslabviewproccess.h"

GraphicsLabViewProccess::GraphicsLabViewProccess(QWidget* parent) : QGraphicsView(parent){

}

void GraphicsLabViewProccess::setNBalls(int nBalls){
    if(nBalls%2){
        InstructionCircleItem* middleCircle = new InstructionCircleItem((nBalls/2+1),QPointF(0-65,0-25));

        for(int i=1;i<nBalls/2+1;i++){
            circles.push_back(new InstructionCircleItem(i,QPointF(middleCircle->pos().x()-100*i,middleCircle->pos().y())));
            circles.push_back(new InstructionCircleItem(nBalls/2+1+i,QPointF(middleCircle->pos().x()+100*(i),middleCircle->pos().y())));
        }

        circles.insert(circles.begin()+nBalls/2,middleCircle);

        for(int i=1;i<nBalls;i++){
            circles[i]->setPreviousCircle(circles[i-1]);
        }

        setScene(new QGraphicsScene);
        for(int i=nBalls-1;i>=0;i--) {scene()->addItem(circles[i]);}
    }
}

void GraphicsLabViewProccess::setNCircleActive(int n){
    if(n<0||n>=(int)circles.size()) return ;
    circles[n]->setNPen(QPen(Qt::black));
    circles[n]->setTextPen(QPen(Qt::white));
    circles[n]->setBrush(Qt::white);
}

void GraphicsLabViewProccess::setBallsInactive(){
    for(int i=0;i<(int)circles.size();i++){
        circles[i]->setToDefaultNPen();
        circles[i]->setToDefaultTextPen();
        circles[i]->setToDefaultBrush();
    }
}
