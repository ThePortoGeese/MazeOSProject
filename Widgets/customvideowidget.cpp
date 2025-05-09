#include "customvideowidget.h"

void CustomVideoWidget::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Space&&event->isAutoRepeat()){
        if(this->player!=nullptr){
            player->setPlaybackRate(3.5);
        }
    }
    else if(event->key()==Qt::Key_Escape){
        if(this->player!=nullptr) player->stop();
    }
    else {
        if(this->player!=nullptr) player->setPlaybackRate(1);
    }
}

void CustomVideoWidget::mousePressEvent(QMouseEvent *event){
    event->setAccepted(0);
}
