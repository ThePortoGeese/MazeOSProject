#ifndef MAZEVIEW_H
#define MAZEVIEW_H
#include <mazes.h>
#include <QGraphicsView>

const QColor color=Qt::red;

class mazeView : public QGraphicsView
{
    Q_OBJECT
public:
    mazeView(QWidget* parent=0);

    void drawMaze(mazes* currentMaze);

    void clearCells();
private:
    std::vector<std::vector<QGraphicsRectItem*>> cells;
public slots:
    void changeCellColour(int x, int y, int conNb, QBrush brush=QColor(0, 201, 201));
};

#endif // MAZEVIEW_H
