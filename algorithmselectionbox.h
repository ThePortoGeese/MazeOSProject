#ifndef ALGORITHMSELECTIONBOX_H
#define ALGORITHMSELECTIONBOX_H

#include "qmediaplayer.h"
#include <QGroupBox>

namespace Ui {
class AlgorithmSelectionBox;
}

class AlgorithmSelectionBox : public QGroupBox
{
    Q_OBJECT

public:
    AlgorithmSelectionBox(QWidget* parent=nullptr) : QGroupBox(parent){}
    explicit AlgorithmSelectionBox(QString algTitle, QString algDesc, QString videoFile, QWidget *parent = nullptr);
    ~AlgorithmSelectionBox();
    void mousePressEvent(QMouseEvent *event) override;
    const bool& isClicked(){
        return clicked;
    }
    void setClicked(bool b){
        clicked=b;
    }
    void enterEvent(QEnterEvent* e) override;
    void leaveEvent(QEvent* e) override;
signals:
    void algorithmSelectionChanged(AlgorithmSelectionBox*);

    void algorithmSelectionHoverEntered(AlgorithmSelectionBox*);
    void algorithmSelectionHoverLeave();
private:
    QMediaPlayer* player;
    Ui::AlgorithmSelectionBox *ui;
    bool clicked=0;
};

#endif // ALGORITHMSELECTIONBOX_H
