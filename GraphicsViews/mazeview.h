#ifndef MAZEVIEW_H
#define MAZEVIEW_H
#include <qmazes.h>
#include <QGraphicsView>
#include <GraphicsViewsitems/cellgraphicsrectitem.h>
class mazeView : public QGraphicsView
{
    Q_OBJECT
public:
    mazeView(QWidget* parent=0);
    void drawMaze(QMazes* currentMaze);
    static void deleteScene(QGraphicsScene* deleteScene){
        if(deleteScene!=nullptr){
            qDeleteAll(deleteScene->items());
            deleteScene->clear();
        }
    }
    void setBusy(bool bus){
        busy=bus;
    }
private:
    std::vector<std::vector<CellGraphicsRectItem*>> cells;
    bool busy;
public slots:
    void clearCells();
    void changeCellColour(int x, int y, int conNb, QBrush brush=QColor(0, 201, 201));
    void findRectItemPosition(CellGraphicsRectItem* rect);
signals:
    void chartPathToCell(int x,int y);
    void updateStatusText();
};

#endif // MAZEVIEW_H
