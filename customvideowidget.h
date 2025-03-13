#ifndef CUSTOMVIDEOWIDGET_H
#define CUSTOMVIDEOWIDGET_H

#include "QtMultimedia/QMediaPlayer"
#include <QVideoWidget>
#include "qevent.h"

class CustomVideoWidget : public QVideoWidget
{
public:
    CustomVideoWidget(QWidget* parent=nullptr) : QVideoWidget(parent){};
    void setPlayer(QMediaPlayer* p){
        player=p;
    }

private:


    void mousePressEvent(QMouseEvent *event)override;
    void keyPressEvent(QKeyEvent *event) override;

    QMediaPlayer* player=nullptr;
};

#endif // CUSTOMVIDEOWIDGET_H
