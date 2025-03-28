#ifndef GRAPHICSLABVIEWPROCCESS_H
#define GRAPHICSLABVIEWPROCCESS_H
#include "GraphicsViewsitems/instructioncircleitem.h"
#include <QGraphicsView>

class GraphicsLabViewProccess : public QGraphicsView
{
public:
    GraphicsLabViewProccess(QWidget* parent=nullptr);

    void setNCircleActive(int n);
    void setNBalls(int nBalls);
    void setBallsInactive();
private:
    std::vector<InstructionCircleItem*> circles;
};

#endif // GRAPHICSLABVIEWPROCCESS_H
