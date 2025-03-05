#include "mazenamedialog.h"
#include "qmessagebox.h"
#include "ui_mazenamedialog.h"

MazeNameDialog::MazeNameDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MazeNameDialog)
{
    ui->setupUi(this);

    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(changeLblLimit(QString)));
}

MazeNameDialog::~MazeNameDialog()
{
    delete ui;
}

void MazeNameDialog::changeLblLimit(const QString& str){
    ui->lblTxtLimit->setText("("+QString::number(str.length())+"/32)");
}


void MazeNameDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->lineEdit->text()!=""){
        QString str=ui->lineEdit->text();
        emit mazeName(str);
        accept();
        finished(QDialog::Accepted);
    }
    else {
        QMessageBox::critical(this,"Inválido.","Nome não pode ser vazio!");
    }
}

