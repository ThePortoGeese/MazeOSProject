#include "menuwindow.h"
#include "namedialog.h"
#include "ui_menuwindow.h"

enum stackedWidgetPages{
    pgMenu,
    pgNewUser,
    pgNewRandom,
    pgLabViewProccess,
    pgCredits,
    pgLeaderboard,
    pgSelectFile=0,
    pgSelectAlgorithm=1,
    pgLabView=2,
};

QMazes* currentMazeCreator=nullptr;

QMazes* currentMazeView=nullptr;

//General Functions

    menuWindow::menuWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::menuWindow)
    {

        ui->setupUi(this);

        ui->lblImage->setPixmap(QPixmap(":/others/resources/appLogo.png"));

        connect(ui->graphicsView,SIGNAL(chartPathToCell(int,int)),this,SLOT(chartPathToCell(int,int)));
        connect(ui->graphicsView,SIGNAL(updateStatusText()),this,SLOT(updateStatusText()));

        //Connects the buttons in the Maze Creator
        connect(ui->btnUserExpandH,SIGNAL(crementFunctionality(int)),ui->graphicsMazePreview,SLOT(incrementCellsH(int)));
        connect(ui->btnUserExpandV,SIGNAL(crementFunctionality(int)),ui->graphicsMazePreview,SLOT(incrementCellsV(int)));
        connect(ui->btnUserContractH,SIGNAL(crementFunctionality(int)),ui->graphicsMazePreview,SLOT(decrementCellsH(int)));
        connect(ui->btnUserContractV,SIGNAL(crementFunctionality(int)),ui->graphicsMazePreview,SLOT(decrementCellsV(int)));
        //Connects the functions that change the save indicator
        connect(ui->graphicsMazePreview,SIGNAL(updateSaveIndicator()),this,SLOT(updateSaveIndicator()));

        //Stuff Related to the algorithm choosing thingies
        AlgorithmSelectionBox* recursive = new AlgorithmSelectionBox("Algoritmo Recursivo","qrc:/others/resources/recursiveDescription.txt",ui->scrlAreaSelectAlgorithm);
        ui->scrlAreaSelectAlgorithmContents->layout()->addWidget(recursive);
        AlgorithmSelectionBox* other = new AlgorithmSelectionBox("\"Abraça Paredes\"","qrc:/others/resources/wallfollowerDesciption.txt",ui->scrlAreaSelectAlgorithm);
        ui->scrlAreaSelectAlgorithmContents->layout()->addWidget(other);
        AlgorithmSelectionBox* other1 = new AlgorithmSelectionBox("Preenchedor de Becos","qrc:/others/resources/deadEndFillingDescription.txt",ui->scrlAreaSelectAlgorithm);
        ui->scrlAreaSelectAlgorithmContents->layout()->addWidget(other1);
        for(int i=0;i<ui->scrlAreaSelectAlgorithmContents->children().size();i++){
            AlgorithmSelectionBox* box=dynamic_cast<AlgorithmSelectionBox*>(ui->scrlAreaSelectAlgorithmContents->children()[i]);
            if(box!=nullptr){
                connect(box,SIGNAL(algorithmSelectionHoverEntered(AlgorithmSelectionBox*)),this,SLOT(algorithmSelectionHoverEnter(AlgorithmSelectionBox*)));
                connect(box,SIGNAL(algorithmSelectionHoverLeave()),this,SLOT(algorithmSelectionHoverLeave()));
                connect(box,SIGNAL(algorithmSelectionChanged(AlgorithmSelectionBox*)),this,SLOT(changeAlgorithmSelection(AlgorithmSelectionBox*)));
                box->setStyleSheet("\
                    QGroupBox {\
                        color: rgb(255, 255, 255);\
                        border-width: 2px;\
                        border-style: solid;\
                        background-color : rgba(4, 26, 52,50%);\
                        border-color: rgb(255, 255, 255);\
                        padding-top: 15px;\
                        margin-top: 5px;\
                    }\
                    QGroupBox:disabled {\
                        color: rgba(255, 255, 255,50%);\
                        background-color : rgba(4, 26, 52,0%);\
                        border-width: 0.5px;\
                    }\
                    QGroupBox::title {\
                        subcontrol-origin: margin;\
                        subcontrol-position: top center; \
                        margin-left: 3px;\
                        margin-right: 3px;\
                    }");
            }
        }

        if(!(QDir((QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+QStringLiteral("/MazeOS"))).exists())){
            QDir((QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation))).mkdir("MazeOS");
            QDir((QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation))+"/MazeOS").mkdir("userMazes");
        }

        setLeaderboard();
        ui->tblLeaderboard->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tblLeaderboard->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        QFont font=ui->tblLeaderboard->font();
        font.setBold(1);
        font.setPointSize(18);
        ui->tblLeaderboard->horizontalHeader()->setFont(font);
        {
            QFont txtFont = ui->lblGenerate->font();
            txtFont.setBold(1);
            txtFont.setPointSize(48);
            QLabel* lbl = new QLabel("LABIRINTOS");
            lbl->setFont(txtFont);
            ((QGridLayout*)ui->scrlAreaMenuContents->layout())->addWidget(lbl,0,0,1,5,Qt::AlignHCenter);
            lbl->setStyleSheet("background-color: rgba(0, 0, 0, 100); color: white;");
            lbl->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
        }
        connect(ui->lblImage,SIGNAL(mousePressed()),this,SLOT(appLogoClick()));

        ui->graphicsLabProccessView->setNBalls(3);

    }

    menuWindow::~menuWindow()
    {
        delete ui;
    }

    void menuWindow::closeEvent(QCloseEvent *e){
        if(ui->stackedWidget->currentIndex()==pgNewUser&&(!ui->graphicsMazePreview->getSavedStatus())){
            if(!areYouSureModal()){
                e->ignore();
                return;
            }
        }


        saveLeaderboard();
        QWidget::closeEvent(e);
    }

    void menuWindow::resizeEvent(QResizeEvent* event){
        if(ui->stackedWidget->currentIndex()==pgLabViewProccess){ {
                if(ui->graphicsView->scene()!=nullptr) ui->graphicsView->fitInView(ui->graphicsView->scene()->sceneRect());}
        }
        else if(ui->stackedWidget->currentIndex()==pgNewUser){ if(ui->graphicsMazePreview->scene()!=nullptr) {
                ui->graphicsMazePreview->fitInView(ui->graphicsMazePreview->scene()->sceneRect());}
        }
        QWidget::resizeEvent(event);
    }

    void menuWindow::keyPressEvent(QKeyEvent* event)
    {
        if (event->modifiers() == Qt::ControlModifier && ui->stackedWidget->currentIndex()==pgNewUser)
        {
            switch(event->key()){
            case Qt::Key_Z:
                ui->graphicsMazePreview->undoActions();
                break;
            case Qt::Key_N:
                on_btnNewUserMaze_clicked();
                break;
            case Qt::Key_S:
                on_btnUserSave_clicked();
                break;
            case Qt::Key_O:
                on_btnUserOpenMaze_clicked();
                break;
            case Qt::Key_1:
                on_btnAddWall_clicked();
                break;
            case Qt::Key_2:
                on_btnRemoveWall_clicked();
                break;
            }
        }
    }
//End og General Functions

//Functions about the above and below the stacked widgetbuttons

    void menuWindow::startLabViewProccess()
    {
        ui->btnResolve->setChecked(1);
        ui->btnLeaderBoards->setChecked(0);
        ui->btnGenerate->setChecked(0);
        ui->btnLeaderBoards->setIcon(QPixmap(":/buttonIcons/resources/trophyIcon.png"));

        if(!ui->graphicsMazePreview->getSavedStatus()&&ui->stackedWidget->currentIndex()==pgNewUser){
            if(!areYouSureModal()) {
                ui->btnResolve->setChecked(0);
                ui->btnGenerate->setChecked(1);
                return;
            }
        }

        ui->btnResolve->setChecked(1);
        ui->btnLeaderBoards->setChecked(0);
        ui->btnGenerate->setChecked(0);


        if(ui->stackedWidget->currentIndex()==pgNewUser) resetMazeCreator();
        else if (ui->stackedWidget->currentIndex()==pgLabViewProccess && ui->stackedWidgetLabView->currentIndex()==pgLabView){
            QGraphicsScene* scene = ui->graphicsView->scene();
            ui->graphicsView->setScene(new QGraphicsScene);
            ui->graphicsView->deleteScene(scene);
        }

        ui->stackedWidget->setCurrentIndex(pgLabViewProccess);
        ui->stackedWidgetLabView->setCurrentIndex(pgSelectFile);
        ui->lblSelectedFile->setText("");
        ui->btnSelectFileNext->setVisible(0);

        ui->graphicsLabProccessView->setBallsInactive();
        ui->graphicsLabProccessView->setNCircleActive(0);

    }
    void menuWindow::appLogoClick()
    {
        ui->btnResolve->setChecked(0);
        ui->btnLeaderBoards->setChecked(0);
        ui->btnGenerate->setChecked(0);
        ui->btnLeaderBoards->setIcon(QPixmap(":/buttonIcons/resources/trophyIcon.png"));

        if(!ui->graphicsMazePreview->getSavedStatus()&&ui->stackedWidget->currentIndex()==pgNewUser){
            if(!areYouSureModal()) {
                ui->btnResolve->setChecked(0);
                ui->btnGenerate->setChecked(1);
                return;
            }
        }

        ui->btnResolve->setChecked(0);
        ui->btnLeaderBoards->setChecked(0);
        ui->btnGenerate->setChecked(0);


        if(ui->stackedWidget->currentIndex()==pgNewUser) resetMazeCreator();
        else if (ui->stackedWidget->currentIndex()==pgLabViewProccess && ui->stackedWidgetLabView->currentIndex()==pgLabView){
            QGraphicsScene* scene = ui->graphicsView->scene();
            ui->graphicsView->setScene(new QGraphicsScene);
            ui->graphicsView->deleteScene(scene);
        }

        ui->stackedWidget->setCurrentIndex(pgMenu);
    }
    void menuWindow::on_btnGenerate_clicked()
    {
        ui->btnResolve->setChecked(0);
        ui->btnLeaderBoards->setChecked(0);
        ui->btnGenerate->setChecked(1);
        ui->btnLeaderBoards->setIcon(QPixmap(":/buttonIcons/resources/trophyIcon.png"));

        if(ui->stackedWidget->currentIndex()!=pgNewUser){
            ui->graphicsMazePreview->newMaze();
            ui->stackedWidget->setCurrentIndex(pgNewUser);
            ui->graphicsMazePreview->fitInView(ui->graphicsMazePreview->sceneRect());
            ui->btnAddWall->setChecked(0);
            ui->btnRemoveWall->setChecked(1);
            ui->graphicsMazePreview->setToggleBrush(PreviewMazeView::brushRemoveWalls);
        } else if (ui->stackedWidget->currentIndex()==pgLabViewProccess && ui->stackedWidgetLabView->currentIndex()==pgLabView){
            QGraphicsScene* scene = ui->graphicsView->scene();
            ui->graphicsView->setScene(new QGraphicsScene);
            ui->graphicsView->deleteScene(scene);
        }

    }

    void menuWindow::on_btnSummary_clicked()
    {
        informationPage* page=new informationPage;
        page->setWindowTitle("Querias um Relatório? Toma.");
        page->setWindowIcon(QPixmap(":/others/resources/appLogo.png"));
        page->show();
    }


    void menuWindow::on_btnLeaderBoards_clicked()
    {
        ui->btnResolve->setChecked(0);
        ui->btnLeaderBoards->setChecked(1);
        ui->btnGenerate->setChecked(0);
        ui->btnLeaderBoards->setIcon(QPixmap(":/buttonIcons/resources/trophyIconBlue.png"));
        if(!ui->graphicsMazePreview->getSavedStatus()&&ui->stackedWidget->currentIndex()==pgNewUser){
            if(!areYouSureModal()) {
                ui->btnLeaderBoards->setIcon(QPixmap(":/buttonIcons/resources/trophyIcon.png"));
                ui->btnLeaderBoards->setChecked(0);
                ui->btnGenerate->setChecked(1);
                return;
            }
        }

        ui->btnResolve->setChecked(0);
        ui->btnLeaderBoards->setChecked(1);
        ui->btnGenerate->setChecked(0);


        if(ui->stackedWidget->currentIndex()==pgNewUser) resetMazeCreator();
        else if (ui->stackedWidget->currentIndex()==pgLabViewProccess && ui->stackedWidgetLabView->currentIndex()==pgLabView){
            QGraphicsScene* scene = ui->graphicsView->scene();
            ui->graphicsView->setScene(new QGraphicsScene);
            ui->graphicsView->deleteScene(scene);
        }

        ui->stackedWidget->setCurrentIndex(pgLeaderboard);
    }

    void menuWindow::on_btnCredits_clicked()
    {
        ui->btnResolve->setChecked(0);
        ui->btnLeaderBoards->setChecked(0);
        ui->btnGenerate->setChecked(0);
        ui->btnLeaderBoards->setIcon(QPixmap(":/buttonIcons/resources/trophyIcon.png"));
        if(!ui->graphicsMazePreview->getSavedStatus()&&ui->stackedWidget->currentIndex()==pgNewUser){
            if(!areYouSureModal()) {
                ui->btnGenerateMaze->setChecked(1);
                return;
            }
        }



        if(ui->stackedWidget->currentIndex()==pgNewUser) resetMazeCreator();
        else if (ui->stackedWidget->currentIndex()==pgLabViewProccess && ui->stackedWidgetLabView->currentIndex()==pgLabView){
            QGraphicsScene* scene = ui->graphicsView->scene();
            ui->graphicsView->setScene(new QGraphicsScene);
            ui->graphicsView->deleteScene(scene);
        }

        ui->stackedWidget->setCurrentIndex(pgCredits);
    }

    //Convenience function, made because I was tired of adding the setEnabled for every new button in the menu in the
    //code for the credits
    void menuWindow::setMenuButtonsEnabled(bool enabled){
        ui->btnGenerate->setEnabled(enabled);
        ui->btnResolve->setEnabled(enabled);
        ui->btnCredits->setEnabled(enabled);
        ui->btnSummary->setEnabled(enabled);
        ui->btnLeaderBoards->setEnabled(enabled);
        ui->lblImage->setEnabled(enabled);
    }

//End of overhead menu buttons

//Button For the Random Generated PAge
    void menuWindow::on_btnGenerateMaze_clicked()
    {
        currentMazeView=new QMazes(ui->slidX->value(),ui->slidY->value());
        currentMazeView->createMaze();
        QMessageBox::information(this,"Estado da Operação","Sucesso!");
        connect(currentMazeView,SIGNAL(cellTriggered(int,int,int)),ui->graphicsView,SLOT(changeCellColour(int,int,int)));
    }
//end of random generated page

//Functions Related to the LabViewProccess
    //Functions Related to the Select File Proccess

        void menuWindow::on_btnRandomMaze_clicked()
        {
            int opc=QMessageBox::question(this,"ATENÇÃO","Esta ação eliminará este labirinto do placar. Pretende prosseguir?");
            if(opc==QMessageBox::Yes) {
                std::thread worker;
                if(currentMazeView!=nullptr) {
                    QMazes* maz=currentMazeView;
                    currentMazeCreator=nullptr;
                    //Deallocate previous memory
                    std::thread deleteThread(deleteMaze,maz);
                    worker=std::move(deleteThread);
                }

                ui->lblSelectedFile->setText("");
                currentMazeView=new QMazes(64,64);
                currentMazeView->createMaze();
                currentMazeView->nameGenerator();
                currentMazeView->notUserGenerated();
                ui->btnSelectFileNext->setVisible(1);
                QMessageBox::information(this,"Sucesso.","Operação Concluída.");

                if(worker.joinable()) worker.join();
            }
        }

        void menuWindow::on_btnSelectFileForViewing_clicked()
        {
            QString fileName=QFileDialog::getOpenFileName(this, tr("Open Maze"),QString(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/MazeOS/userMazes"),tr("Mazes (*.maz)"));
            QFile file(fileName);

            if(!file.exists()||!file.fileName().contains(".maz")) {
                ui->btnSelectFileNext->setVisible(0);
                QMessageBox::critical(this,"Ficheiro Inválido","Ficheiro desconhecido/formato inválido.");
                ui->lblSelectedFile->setText("");
                return;
            }

            std::thread worker;
            if(currentMazeView!=nullptr) {
                QMazes* maz=currentMazeView;
                currentMazeCreator=nullptr;
                //Deallocate previous memory
                std::thread deleteThread(deleteMaze,maz);
                worker=std::move(deleteThread);
            }

            currentMazeView=QMazes::convertFromFile(&file);

            if(currentMazeView == nullptr){
                QMessageBox::critical(this,"Ficheiro Corrompido","Ficheiro foi alterado fora do Programa e portanto não pode ser lido.");
                ui->lblSelectedFile->setText("");
                return;
            }

            if(currentMazeView->getEvaluated()){
                QMessageBox::information(this,"Atenção","Este labirinto já foi avaliado e portanto não receberá pontuação.");
            }

            ui->btnSelectFileNext->setVisible(1);
            ui->lblSelectedFile->setText(currentMazeView->getName());
            if(worker.joinable()) worker.join();
        }


        void menuWindow::on_btnSelectFileNext_clicked()
        {
            connect(currentMazeView,SIGNAL(cellTriggered(int,int,int)),ui->graphicsView,SLOT(changeCellColour(int,int,int)));
            connect(currentMazeView,SIGNAL(timeOut()),this,SLOT(mazeSolvingTimeOut()));
            ui->stackedWidgetLabView->setCurrentIndex(pgSelectAlgorithm);
            ui->btnSelectAlgorithmNext->setVisible(0);
            ui->lblMazeName->setText(currentMazeView->getName());

            for(int i=0;i<ui->scrlAreaSelectAlgorithmContents->children().size();i++){
                AlgorithmSelectionBox* castBox=dynamic_cast<AlgorithmSelectionBox*>(ui->scrlAreaSelectAlgorithmContents->children()[i]);
                if(castBox==nullptr) continue;
                castBox->setClicked(0);
                castBox->setDisabled(0);
            }
            ui->graphicsLabProccessView->setNCircleActive(1);

        }

    //End of Functions related to the select file proccess

    //Functions Related to the selecting algorithm part

        void menuWindow::changeAlgorithmSelection(AlgorithmSelectionBox* box){
            for(int i=0;i<ui->scrlAreaSelectAlgorithmContents->children().size();i++){
                AlgorithmSelectionBox* castBox=dynamic_cast<AlgorithmSelectionBox*>(ui->scrlAreaSelectAlgorithmContents->children()[i]);
                if(castBox==nullptr) continue;
                if(box!=nullptr){
                    if(ui->scrlAreaSelectAlgorithmContents->children()[i]!=box) {
                        castBox->setClicked(0);
                        castBox->setDisabled(1);
                    }
                    else {
                        castBox->setClicked(1);
                        castBox->setEnabled(1);
                    }
                }
            }
            if(box!=nullptr) ui->btnSelectAlgorithmNext->setVisible(1);
            else {
                ui->btnSelectAlgorithmNext->setVisible(0);
            }
        }

        void menuWindow::algorithmSelectionHoverEnter(AlgorithmSelectionBox* box){
            bool anyClicked=0;
            for(int i=0;i<ui->scrlAreaSelectAlgorithmContents->children().size();i++){
                AlgorithmSelectionBox* castBox=dynamic_cast<AlgorithmSelectionBox*>(ui->scrlAreaSelectAlgorithmContents->children()[i]);
                if(castBox==nullptr) continue;
                if(castBox->isClicked()) anyClicked=1;
            }
            if(!anyClicked){
                for(int i=0;i<ui->scrlAreaSelectAlgorithmContents->children().size();i++){
                    AlgorithmSelectionBox* castBox=dynamic_cast<AlgorithmSelectionBox*>(ui->scrlAreaSelectAlgorithmContents->children()[i]);
                    if(castBox==nullptr) continue;

                    if(ui->scrlAreaSelectAlgorithmContents->children()[i]!=box) castBox->setDisabled(1);
                    else castBox->setDisabled(0);
                }
            }
        }

        void menuWindow::algorithmSelectionHoverLeave(){
            bool anyClicked=0;
            for(int i=0;i<ui->scrlAreaSelectAlgorithmContents->children().size();i++){
                AlgorithmSelectionBox* castBox=dynamic_cast<AlgorithmSelectionBox*>(ui->scrlAreaSelectAlgorithmContents->children()[i]);
                if(castBox==nullptr) continue;
                if(!castBox->isClicked()) castBox->setDisabled(1); else anyClicked=1;
            }
            if(!anyClicked){
                for(int i=0;i<ui->scrlAreaSelectAlgorithmContents->children().size();i++){
                    AlgorithmSelectionBox* castBox=dynamic_cast<AlgorithmSelectionBox*>(ui->scrlAreaSelectAlgorithmContents->children()[i]);
                    if(castBox==nullptr) continue;
                    castBox->setEnabled(1);
                }
            }
        }

        void menuWindow::on_btnSelectAlgorithmNext_clicked()
        {
            ui->stackedWidgetLabView->setCurrentIndex(pgLabView);
            ui->graphicsView->drawMaze(currentMazeView);
            ui->graphicsView->fitInView(ui->graphicsView->sceneRect());
            ui->btnSolveMaze->setEnabled(1);
            ui->graphicsLabProccessView->setNCircleActive(2);
        }


    //End of functions related to algorithm part

    //Functions Related to the actual viewing part of the proccess
        void menuWindow::on_btnSolveMaze_clicked()
        {
            ui->graphicsView->clearCells();
            setMenuButtonsEnabled(0);
            ui->btnSolveMaze->setEnabled(0);

            QElapsedTimer* runtime=new QElapsedTimer;
            runtime->start();
            ui->graphicsView->setBusy(1);
            ui->lblStatus->setText("ESTADO: A Resolver...");

            long score=-1;

            int selectedAlgorithm = -1;
            for(int i=0;i<ui->scrlAreaSelectAlgorithmContents->children().size();i++){
                AlgorithmSelectionBox* castBox=dynamic_cast<AlgorithmSelectionBox*>(ui->scrlAreaSelectAlgorithmContents->children()[i]);
                if(castBox==nullptr) continue;
                if(castBox->isClicked()) selectedAlgorithm=i;
            }
            bool success=1;
            switch(selectedAlgorithm){
            case 1:
                if(!currentMazeView->recursiveMazeSolver()) success=0;
                break;
            case 2:
                if(!currentMazeView->wallFollowerMazeSolver()) success=0;
                break;
            case 3:
                if(!currentMazeView->deadEndFillingMazeSolver()) success=0;
                break;
            }

            if(success){
                if(currentMazeView->getUserGeneratedStatus()&&(!currentMazeView->getEvaluated())){
                    score=(((currentMazeView->getWidth()*currentMazeView->getHeight())/2*0.2+runtime->elapsed()*0.80)*100);
                }

                QMessageBox::information(this,"Informação","Demorei: "+QString::number((float)runtime->elapsed()/1000)+"s\nPontuação: "+ (!(score<0) ? QString::number(score):"Não Aplicável"));


                updateLeaderboard(score);

                if(!(score<0)){
                    QMessageBox::information(this,"You've got Mail!","1 Mensagem Nova:\nDe: Computador\nPara: Utilizador desta aplicação\nConteúdo: "+ getHardnessRating(score));
                }
                ui->graphicsView->setBusy(0);
                ui->graphicsView->clearCells();
                ui->graphicsView->setBusy(1);
                ui->lblStatus->setText("ESTADO: A Mostrar o Caminho Correto...");
                ui->graphicsView->scene()->update();
                for(int i=0;i<(int)currentMazeView->tempPath.size();i++){
                    ui->graphicsView->changeCellColour(currentMazeView->tempPath[i]->x,currentMazeView->tempPath[i]->y,currentMazeView->tempPath[i]->k,QColor(0, 200, 81));
                    delete currentMazeView->tempPath[i];
                    QTime dieTime= QTime::currentTime().addMSecs(1);
                    while (QTime::currentTime() < dieTime)
                        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                }

                ui->graphicsView->setBusy(0);

                QString fileName = currentMazeView->getName();
                if(!(score<0)){
                    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/MazeOS/userMazes/"+fileName.replace(" ","")+".maz");
                    if(file.open(QIODevice::Append)){
                        QTextStream out(&file);
                        out<<"EVALUATED";
                        file.close();
                    }

                }
                currentMazeView->setEvaluated(1);
                setMenuButtonsEnabled(1);
                ui->btnSolveMaze->setEnabled(1);
                currentMazeView->tempPath.clear();
                ui->lblStatus->setText("ESTADO: Idle");
                delete runtime;
            }
            else {
                ui->graphicsView->setBusy(0);
                setMenuButtonsEnabled(1);
                ui->lblStatus->setText("ESTADO: Causaste-me uma hemorragia cerebral.");
                ui->graphicsView->clearCells();
            }
        }

        void menuWindow::mazeSolvingTimeOut(){
            QMessageBox::critical(this,"You've got Mail!","1 Mensagem Nova:\nDe: Computador\nPara: Utilizador desta aplicação\nConteúdo: Este labirinto é demasiado aberto e está-me a confundir todo! Por favor para.");
            ui->btnSolveMaze->setEnabled(0);
            ui->graphicsView->clearCells();
        }

        void menuWindow::chartPathToCell(const int& tX,const int& tY){
            //qDebug()<<tX<<" "<<tY;
            if(ui->btnSolveMaze->isEnabled()){
                ui->lblStatus->setText("ESTADO: A Mostrar Caminho para ("+QString::number(tX)+","+QString::number(tY)+")");
                currentMazeView->recursiveMazeSolver(tX,tY);

                for(int i=currentMazeView->tempPath.size()-1;i>=0;i--){
                    ui->graphicsView->changeCellColour(currentMazeView->tempPath[i]->x,currentMazeView->tempPath[i]->y,currentMazeView->tempPath[i]->k,QColor(250, 200, 81));
                    delete currentMazeView->tempPath[i];
                }
                currentMazeView->tempPath.clear();
            }

        }

        void menuWindow::updateStatusText(){
            ui->lblStatus->setText("ESTADO: Idle");
        }

        QString menuWindow::getHardnessRating(int score){
            QFile file(":/others/resources/hardnessRating.txt");

            if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
                QTextStream in(&file);
                for(;!in.atEnd();){
                    int minScore=(in.readLine()).toInt();
                    //qDebug()<<"minScore: "<<minScore;
                    if(score>minScore){
                        return in.readLine();
                    }
                    else in.readLine();
                }
            }

            return "Não consigo computar a tua genialidade!";
        }
    //End of Viewing Functions

//End of LabViewProccess functions



//Start of Maze Creator Fuctions

    void menuWindow::on_btnNewUserMaze_clicked()
    {
        //Modal dialogue to save
        if(!ui->graphicsMazePreview->getSavedStatus()){
            if(!areYouSureModal()) return;

        }
        resetMazeCreator();
        ui->graphicsMazePreview->newMaze();
        ui->graphicsMazePreview->fitInView(ui->graphicsMazePreview->sceneRect());

    }

    void menuWindow::on_btnUserOpenMaze_clicked()
    {
        if(ui->graphicsMazePreview->X()!=2||ui->graphicsMazePreview->Y()!=2){
            if(!areYouSureModal()) return;
        }
        QString fileName=QFileDialog::getOpenFileName(this, tr("Open Maze"),QString(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/MazeOS/userMazes"),tr("Mazes (*.maz)"));
        QFile file(fileName);

        if(!file.exists()||!file.fileName().contains(".maz")) {
            QMessageBox::critical(this,"Ficheiro Inválido","Ficheiro desconhecido/formato inválido.");
            return;
        }
        currentMazeCreator=QMazes::convertFromFile(&file);

        if(currentMazeCreator == nullptr){
            QMessageBox::critical(this,"Ficheiro Corrompido","Formato de ficheiro inválido.");
            return;
        }

        QMazesConversionMethods::convertPreviewFromQMazes(currentMazeCreator,ui->graphicsMazePreview);
        ui->lblMazeCreatorName->setText(currentMazeCreator->getName()+".maz");
        ui->graphicsMazePreview->setSavedStatus(1);
        QMessageBox::information(this,"Sucesso!","Operação Concluída");
        ui->lblSavedIndicator->setPixmap(QPixmap(":/others/resources/saveButtonCheck.png"));
    }

    void menuWindow::on_btnUserSave_clicked()
    {
        if(!(ui->graphicsMazePreview->entranceExists()&&ui->graphicsMazePreview->exitExists())){
            QMessageBox::critical(this,"Labirinto Inválido","Labirinto têm de ter uma entrada e uma saída");
            return;
        }

        if(ui->graphicsMazePreview->getSavedStatus()){ return;}
        ui->btnUserSave->setEnabled(0);
        QString mazeName;
        std::thread worker;
        if(currentMazeCreator!=nullptr) {
            mazeName=currentMazeCreator->getName();
            QMazes* maz=currentMazeCreator;
            currentMazeCreator=nullptr;
            //Deallocate previous memory
            std::thread deleteThread(deleteMaze,maz);
            worker=std::move(deleteThread);
        }

        currentMazeCreator=QMazesConversionMethods::convertFromView(ui->graphicsMazePreview);

        if(currentMazeCreator->mazeChecker()){
            if(mazeName==""){
                NameDialog popUp=NameDialog(this);
                int result=popUp.exec();
                if(result==QDialog::Rejected){
                    if (worker.joinable()) worker.join();
                    ui->btnUserSave->setEnabled(1);
                    return;
                }
                mazeName=popUp.getName();
                currentMazeCreator->setName(mazeName);
                ui->lblMazeCreatorName->setText(mazeName+".maz");
            } else {
                currentMazeCreator->setName(mazeName);
            }
            ui->graphicsMazePreview->setSavedStatus(1);
            currentMazeCreator->saveAsFile(mazeName.replace(" ",""));
            ui->lblSavedIndicator->setPixmap(QPixmap(":/others/resources/saveButtonCheck.png"));
        } else {
            QMessageBox::critical(this,"Labirinto Inválido","Têm de haver 1 caminho válido para a saída e o labirinto NÃO pode ser demasiado aberto.");
            if(!(mazeName=="")) currentMazeCreator->setName(mazeName);
        }
        if (worker.joinable()) worker.join();

        ui->btnUserSave->setEnabled(1);
    }

    void menuWindow::deleteMaze(QMazes* mazeToDelete){
        if(mazeToDelete!=nullptr) delete mazeToDelete;
    }

    bool menuWindow::areYouSureModal(){

            int opc=QMessageBox::question(this,"De Certeza?","Isto irá apagar o seu progresso...");
            if(opc==QMessageBox::Yes){
                return 1;
            } else return 0;
    }

    void menuWindow::resetMazeCreator(){
        ui->lblMazeCreatorName->setText("Sem Nome.maz");
        ui->graphicsMazePreview->deleteScene(ui->graphicsMazePreview->scene());
        ui->graphicsMazePreview->setScene(new QGraphicsScene);
        ui->lblSavedIndicator->setPixmap(QPixmap(":/others/resources/saveButtonX.png"));
        delete currentMazeCreator;
        currentMazeCreator=nullptr;
    }

    void menuWindow::updateSaveIndicator(){
        ui->lblSavedIndicator->setPixmap(QPixmap(":/others/resources/saveButtonX.png"));
    }

//End of MazeCreator Functions

//LeaderBoard Functions

    void menuWindow::saveLeaderboard(){
        QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/MazeOS/leaderboardData.txt");
        if(file.open(QIODevice::WriteOnly|QFile::Truncate)){
            QTextStream out(&file);
            for(int i=0;i<10;i++){
                if(ui->tblLeaderboard->model()->index(i,0).data().toInt()==0) break;
                out<<ui->tblLeaderboard->model()->index(i,0).data().toString()<<'\n';
                out<<ui->tblLeaderboard->model()->index(i,1).data().toString()<<'\n';
                out<<ui->tblLeaderboard->model()->index(i,2).data().toString()<<'\n';
            }
            file.close();
        }
    }

    void menuWindow::setLeaderboard(){
            QStandardItemModel* model = new QStandardItemModel(10,3,ui->tblLeaderboard);
            model->setHorizontalHeaderItem(0, new QStandardItem(QString("Pontuação")));
            model->setHorizontalHeaderItem(1, new QStandardItem(QString("Nome do Criador")));
            model->setHorizontalHeaderItem(2, new QStandardItem(QString("Nome do Labirinto")));
            QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"/MazeOS/leaderboardData.txt");
            if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
                QTextStream in(&file);
                for(int i=0;i<10;i++){
                    if(in.atEnd()){
                        model->setItem(i,0,new QStandardItem("0"));
                        model->setItem(i,1,new QStandardItem("Indefinido"));
                        model->setItem(i,2,new QStandardItem("Indefinido"));
                    }
                    else{
                        model->setItem(i,0,new QStandardItem(in.readLine()));
                        model->setItem(i,1,new QStandardItem(in.readLine()));
                        model->setItem(i,2,new QStandardItem(in.readLine()));
                    }
                }
                file.close();
            }
            ui->tblLeaderboard->setModel(model);
            ui->tblLeaderboard->resizeColumnsToContents();
            ui->tblLeaderboard->resizeRowsToContents();
    }

    void menuWindow::updateLeaderboard(int score){
        for(int i=0;i<10;i++){
            if(score>ui->tblLeaderboard->model()->index(i,0).data().toInt()){
                QString personName;
                do{
                    NameDialog popUp(this,"Indique o seu nome para inserção no placar");
                    popUp.setWindowTitle("Nova Pontuação Mais Alta!");
                    int opc=popUp.exec();
                    if(opc==QDialog::Accepted){
                        personName=popUp.getName();
                        break;
                    } else {
                        QMessageBox::information(this,"ATENÇÃO","Precisa de inserir o seu nome para lhe inserirmos no placar.");
                    }
                } while(true);
                QList<QStandardItem*> items;
                items.push_back(new QStandardItem(QString::number(score)));
                items.push_back(new QStandardItem(personName));
                items.push_back(new QStandardItem(currentMazeView->getName()));

                ((QStandardItemModel*)ui->tblLeaderboard->model())->insertRow(i,items);
                ((QStandardItemModel*)ui->tblLeaderboard->model())->removeRows(10,1);
                break;
            }
        }
    }

    void menuWindow::on_btnAddWall_clicked()
    {
        ui->btnRemoveWall->setChecked(0);
        ui->graphicsMazePreview->setToggleBrush(PreviewMazeView::brushAddWalls);
    }


    void menuWindow::on_btnRemoveWall_clicked()
    {
        ui->btnAddWall->setChecked(0);
        ui->graphicsMazePreview->setToggleBrush(PreviewMazeView::brushRemoveWalls);
    }

