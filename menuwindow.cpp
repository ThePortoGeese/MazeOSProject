#include "menuwindow.h"

#include "ui_menuwindow.h"

enum stackedWidgetPages{
    pgMenu,
    pgNewUser,
    pgNewRandom,
    pgLabView,
    pgCredits
};

QMediaPlayer* player=new QMediaPlayer;

QMazes* currentMaze=nullptr;

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
    connect(ui->graphicsView,SIGNAL(chartPathToCell(int,int)),this,SLOT(chartPathToCell(int,int)));
    connect(ui->graphicsView,SIGNAL(updateStatusText()),this,SLOT(updateStatusText()));

    connect(ui->btnUserExpandH,SIGNAL(crementFunctionality(int)),ui->graphicsMazePreview,SLOT(incrementCellsH(int)));
    connect(ui->btnUserExpandV,SIGNAL(crementFunctionality(int)),ui->graphicsMazePreview,SLOT(incrementCellsV(int)));
    connect(ui->btnUserContractH,SIGNAL(crementFunctionality(int)),ui->graphicsMazePreview,SLOT(decrementCellsH(int)));
    connect(ui->btnUserContractV,SIGNAL(crementFunctionality(int)),ui->graphicsMazePreview,SLOT(decrementCellsV(int)));
}

menuWindow::~menuWindow()
{
    delete ui;
}


void menuWindow::on_btnCredits_clicked()
{
    QAudioOutput* output;
    output=new QAudioOutput;
    player->setAudioOutput(output);
    ui->stackedWidget->setCurrentIndex(pgCredits);
    ui->btnGenerate->setEnabled(0);
    ui->btnResolve->setEnabled(0);
    ui->btnCredits->setEnabled(0);
    ui->btnSummary->setEnabled(0);
    ui->pgCredits->setFocus();
    player->play();
}

void menuWindow::endCredits(QMediaPlayer::MediaStatus status){
    if(status==QMediaPlayer::EndOfMedia){
        ui->stackedWidget->setCurrentIndex(pgMenu);
        ui->btnGenerate->setEnabled(1);
        ui->btnResolve->setEnabled(1);
        ui->btnCredits->setEnabled(1);
        ui->btnSummary->setEnabled(1);
        delete player->audioOutput();
    }
}

void menuWindow::endCreditsAbruptly(QMediaPlayer::PlaybackState state){
    if(state==QMediaPlayer::StoppedState){
        ui->stackedWidget->setCurrentIndex(pgMenu);
        ui->btnGenerate->setEnabled(1);
        ui->btnResolve->setEnabled(1);
        ui->btnCredits->setEnabled(1);
        ui->btnSummary->setEnabled(1);
        delete player->audioOutput();
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
    ui->stackedWidget->setCurrentIndex(pgLabView);
    ui->lblMazeName->setText(currentMaze->getName());
    ui->graphicsView->fitInView(ui->graphicsView->sceneRect());
}
void menuWindow::on_btnGenerate_clicked()
{
    ui->graphicsMazePreview->newMaze();
    ui->stackedWidget->setCurrentIndex(pgNewUser);
    ui->graphicsMazePreview->fitInView(ui->graphicsMazePreview->sceneRect());
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
    ui->graphicsView->clearCells();
    ui->btnGenerate->setEnabled(0);
    ui->btnResolve->setEnabled(0);
    ui->btnCredits->setEnabled(0);
    ui->btnSolveMaze->setEnabled(0);

    QElapsedTimer* runtime=new QElapsedTimer;
    runtime->start();
    ui->graphicsView->setBusy(1);
    ui->lblStatus->setText("ESTADO:\nA Resolver...");


    currentMaze->mazeSolver();
    QMessageBox::information(this,"Informação","Demorei: "+QString::number((float)runtime->elapsed()/1000)+"s");
    ui->graphicsView->setBusy(0);
    ui->graphicsView->clearCells();
    ui->lblStatus->setText("ESTADO:\nA Mostrar o Caminho Correto...");
    ui->graphicsView->scene()->update();
    for(int i=currentMaze->tempPath.size()-1;i>=0;i--){
        ui->graphicsView->changeCellColour(currentMaze->tempPath[i]->x,currentMaze->tempPath[i]->y,currentMaze->tempPath[i]->k,QColor(0, 200, 81));
        delete currentMaze->tempPath[i];
        QTime dieTime= QTime::currentTime().addMSecs(1);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }



    ui->btnGenerate->setEnabled(1);
    ui->btnResolve->setEnabled(1);
    ui->btnCredits->setEnabled(1);
    ui->btnSolveMaze->setEnabled(1);
    currentMaze->tempPath.clear();
    ui->lblStatus->setText("ESTADO:\nIdle");
    delete runtime;
}

void menuWindow::resizeEvent(QResizeEvent* event){
    if(ui->stackedWidget->currentIndex()==pgLabView) ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect());
    if(ui->stackedWidget->currentIndex()==pgNewUser) ui->graphicsMazePreview->fitInView(ui->graphicsMazePreview->scene()->sceneRect());
    QWidget::resizeEvent(event);
}


void menuWindow::on_btnSummary_clicked()
{
    informationPage* page=new informationPage;
    page->setWindowTitle("Querias um Relatório? Toma.");
    page->setWindowIcon(QPixmap(":/others/resources/appLogo.png"));
    page->show();
}


void menuWindow::chartPathToCell(const int& tX,const int& tY){
    //qDebug()<<tX<<" "<<tY;
    if(ui->btnSolveMaze->isEnabled()){
        ui->lblStatus->setText("ESTADO:\nA Mostrar Caminho para ("+QString::number(tX)+","+QString::number(tY)+")");
        currentMaze->mazeSolver(tX,tY);

        for(int i=currentMaze->tempPath.size()-1;i>=0;i--){
            ui->graphicsView->changeCellColour(currentMaze->tempPath[i]->x,currentMaze->tempPath[i]->y,currentMaze->tempPath[i]->k,QColor(250, 200, 81));
            delete currentMaze->tempPath[i];
        }
        currentMaze->tempPath.clear();
    }
}

void menuWindow::updateStatusText(){
    ui->lblStatus->setText("ESTADO:\nIdle");
}

void menuWindow::on_btnNewUserMaze_clicked()
{
    //Modal dialogue to save

    ui->graphicsMazePreview->newMaze();
    ui->graphicsMazePreview->fitInView(ui->graphicsMazePreview->sceneRect());
}

void menuWindow::on_btnUserOpenMaze_clicked()
{


}


void menuWindow::on_btnUserSave_clicked()
{
    if(!(ui->graphicsMazePreview->entranceExists()&&ui->graphicsMazePreview->exitExists())){
        QMessageBox::critical(this,"Inválido","Labirinto têm de ter uma entrada e uma saída");
        return;
    }
    delete currentMaze;
    QMessageBox::information(this,"Lag","Lagging");
    currentMaze=QMazes::convertFromView(ui->graphicsMazePreview);
    QMessageBox::information(this,"Skibidi","Done");
    //Save stuff
}

