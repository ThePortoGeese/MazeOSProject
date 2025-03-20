#ifndef QLABELWITHPRESSSIGNAL_H
#define QLABELWITHPRESSSIGNAL_H

#include <QLabel>

class QLabelWithPressSignal : public QLabel
{
    Q_OBJECT
public:
    QLabelWithPressSignal(QWidget* parent=nullptr) : QLabel(parent){}

    void mousePressEvent(QMouseEvent* e) override{
        emit mousePressed();
    }
signals:
    void mousePressed();
};

#endif // QLABELWITHPRESSSIGNAL_H
