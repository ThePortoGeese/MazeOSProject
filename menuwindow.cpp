#include "menuwindow.h"

#include "ui_menuwindow.h"

QMediaPlayer* player=new QMediaPlayer;
QAudioOutput* output;
QMazes* currentMaze=nullptr;
QElapsedTimer* runtime=new QElapsedTimer;
menuWindow::menuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menuWindow)
{

    ui->setupUi(this);


    player->setVideoOutput(ui->pgCredits);
    player->setSource(QUrl("qrc:/others/resources/credits.mp4"));
    ui->pgCredits->setPlayer(player);
    ui->lblImage->setPixmap(QPixmap(":/others/resources/appLogo.png"));

    connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(endCredits(QMediaPlayer::MediaStatus)));
    connect(player,SIGNAL(playbackStateChanged(QMediaPlayer::PlaybackState)),this,SLOT(endCreditsAbruptly(QMediaPlayer::PlaybackState)));
    connect(ui->slidX,SIGNAL(valueChanged(int)),SLOT(updateSlideLbls()));
    connect(ui->slidY,SIGNAL(valueChanged(int)),SLOT(updateSlideLbls()));

}

menuWindow::~menuWindow()
{
    delete ui;
}


void menuWindow::on_btnCredits_clicked()
{
    output=new QAudioOutput;
    player->setAudioOutput(output);
    ui->stackedWidget->setCurrentIndex(3);
    ui->btnGenerate->setEnabled(0);
    ui->btnResolve->setEnabled(0);
    ui->btnCredits->setEnabled(0);
    ui->btnSummary->setEnabled(0);
    ui->pgCredits->setFocus();
    player->play();
}

void menuWindow::endCredits(QMediaPlayer::MediaStatus status){
    if(status==QMediaPlayer::EndOfMedia){
        ui->stackedWidget->setCurrentIndex(0);
        ui->btnGenerate->setEnabled(1);
        ui->btnResolve->setEnabled(1);
        ui->btnCredits->setEnabled(1);
        ui->btnSummary->setEnabled(1);
    }

}

void menuWindow::endCreditsAbruptly(QMediaPlayer::PlaybackState state){
    if(state==QMediaPlayer::StoppedState){
        ui->stackedWidget->setCurrentIndex(0);
        ui->btnGenerate->setEnabled(1);
        ui->btnResolve->setEnabled(1);
        ui->btnCredits->setEnabled(1);
        ui->btnSummary->setEnabled(1);
    }

}

void menuWindow::updateSlideLbls(){
    ui->lblSlidX->setText("("+QString::number(ui->slidX->value())+")");
    ui->lblSlidY->setText("("+QString::number(ui->slidY->value())+")");
}

void menuWindow::on_btnResolve_clicked()
{

    if(currentMaze==nullptr){ //skibidi modal dialogue
        return;
    }
    ui->graphicsView->drawMaze(currentMaze);
    ui->stackedWidget->setCurrentIndex(2);
    ui->lblMazeName->setText(currentMaze->getName());
    ui->graphicsView->fitInView(ui->graphicsView->sceneRect());
}
void menuWindow::on_btnGenerate_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void menuWindow::on_btnGenerateMaze_clicked()
{
    currentMaze=new QMazes(ui->slidX->value(),ui->slidY->value());
    currentMaze->createMaze();
    QMessageBox::information(this,"Info","Sucesso!");
    connect(currentMaze,SIGNAL(cellTriggered(int,int,int)),ui->graphicsView,SLOT(changeCellColour(int,int,int)));
}


void menuWindow::on_btnSolveMaze_clicked()
{
    runtime->start();
    currentMaze->mazeSolver();
    QMessageBox::information(this,"Informação","Demorei: "+QString::number((float)runtime->elapsed()/1000)+"s");
    ui->graphicsView->clearCells();
    for(int i=currentMaze->tempCorrectPath.size()-1;i>=0;i--){
        ui->graphicsView->changeCellColour(currentMaze->tempCorrectPath[i]->x,currentMaze->tempCorrectPath[i]->y,currentMaze->tempCorrectPath[i]->k,QColor(0, 200, 81));
        delete currentMaze->tempCorrectPath[i];
        QTime dieTime= QTime::currentTime().addMSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    currentMaze->tempCorrectPath.clear();
}

void menuWindow::resizeEvent(QResizeEvent* event){
    if(ui->stackedWidget->currentIndex()==2) ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect());
}


void menuWindow::on_btnSummary_clicked()
{
    informationPage* page=new informationPage;
    page->show();
}

