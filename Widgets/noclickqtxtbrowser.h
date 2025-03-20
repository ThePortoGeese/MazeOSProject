#ifndef NOCLICKQTXTBROWSER_H
#define NOCLICKQTXTBROWSER_H

#include "qevent.h"
#include "qtextbrowser.h"

class NoClickQTxtBrowser : public QTextBrowser{
public:
    NoClickQTxtBrowser(QWidget* parent) : QTextBrowser(parent){};

    void mousePressEvent(QMouseEvent* e) override{
        e->setAccepted(0);
    }


};

#endif // NOCLICKQTXTBROWSER_H
