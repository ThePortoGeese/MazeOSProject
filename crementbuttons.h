#ifndef CREMENTBUTTONS_H
#define CREMENTBUTTONS_H

#include "qevent.h"
#include <QPushButton>

class CrementButtons : public QPushButton
{
    Q_OBJECT
public:
    CrementButtons():QPushButton(){};
    CrementButtons(QWidget* parent):QPushButton(parent){};

    void mousePressEvent(QMouseEvent *e) override
    {
        if (e->modifiers() == Qt::ShiftModifier) {
            emit crementFunctionality(10);
             QPushButton::mousePressEvent(e);
            return;
        }
        if (e->modifiers() == Qt::ControlModifier) {
            emit crementFunctionality(20);
             QPushButton::mousePressEvent(e);
            return;
        }
        emit crementFunctionality(1);
        QPushButton::mousePressEvent(e);
    }
signals:
    void crementFunctionality(int);
};

#endif // CREMENTBUTTONS_H
