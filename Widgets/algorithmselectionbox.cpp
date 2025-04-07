#include "algorithmselectionbox.h"
#include "ui_algorithmselectionbox.h"

AlgorithmSelectionBox::AlgorithmSelectionBox(QString algTitle,QString algDescPath,QWidget *parent)
    : QGroupBox(parent)
    , ui(new Ui::AlgorithmSelectionBox)
{
    ui->setupUi(this);
    setTitle(algTitle);
    ui->txtBrowser->setSource(QUrl(algDescPath));
    ui->txtBrowser->setStyleSheet("QTextBrowser{background-color : rgba(255,0,0,0%); color : white;}\
                                   QTextBrowser:disabled{color : rgba(255,255,255,50%);}");
}

AlgorithmSelectionBox::~AlgorithmSelectionBox()
{
    delete ui;
}

void AlgorithmSelectionBox::mousePressEvent(QMouseEvent *event){
        if(!clicked){
            clicked=1;
            emit algorithmSelectionChanged(this);
            return;
        }

        clicked=0;
        emit algorithmSelectionChanged(nullptr);

        QWidget::mousePressEvent(event);
}

void AlgorithmSelectionBox::enterEvent(QEnterEvent* e){

    emit algorithmSelectionHoverEntered(this);
    QWidget::enterEvent(e);
}

void AlgorithmSelectionBox::leaveEvent(QEvent* e){
    emit algorithmSelectionHoverLeave();
    QWidget::leaveEvent(e);
}
