#include "algorithmselectionbox.h"
#include "ui_algorithmselectionbox.h"

AlgorithmSelectionBox::AlgorithmSelectionBox(QString algTitle,QString algDescPath, QString videoFile,QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::AlgorithmSelectionBox)
{
    ui->setupUi(this);
    player=new QMediaPlayer;
    setTitle(algTitle);
    ui->widget->setPlayer(player);
    player->setSource(videoFile);
    ui->txtBrowser->setSource(QUrl(algDescPath));
    player->setVideoOutput(ui->widget);
    ui->widget->setAspectRatioMode(Qt::IgnoreAspectRatio);
}

AlgorithmSelectionBox::~AlgorithmSelectionBox()
{
    delete ui;
}

void AlgorithmSelectionBox::mousePressEvent(QMouseEvent *event){
    if(isEnabled()){
        if(!clicked){
            clicked=1;
            emit algorithmSelectionChanged(this);
            return;
        }

        clicked=0;
        emit algorithmSelectionChanged(nullptr);
    }
}

void AlgorithmSelectionBox::enterEvent(QEnterEvent* e){
    player->setPlaybackRate(1);
    player->play();
}

void AlgorithmSelectionBox::leaveEvent(QEvent* e){
    player->stop();
}
