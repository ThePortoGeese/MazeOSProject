#include "namedialog.h"
#include "qevent.h"
#include "qmessagebox.h"
#include "ui_namedialog.h"

NameDialog::NameDialog(QWidget *parent,const QString& lblText)
    : QDialog(parent)
    , ui(new Ui::NameDialog)
{
    ui->setupUi(this);
    ui->lblInsertName->setText(lblText);
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(changeLblLimit(QString)));
}

NameDialog::~NameDialog()
{
    delete ui;
}

void NameDialog::changeLblLimit(const QString& str){
    ui->lblTxtLimit->setText("("+QString::number(str.length())+"/32)");
}

QString NameDialog::getName(){
    return ui->lineEdit->text();
}

void NameDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(validateStringForFile(ui->lineEdit->text())){
        QString str=ui->lineEdit->text();
        accept();
        setResult(QDialog::Accepted);
        emit finished(QDialog::Accepted);
    }
    else {
        QMessageBox::critical(this,"Inválido.","Nome não pode ser vazio nem conter caracteres especiais ([\\/:*?\"<>|]).");
    }
}

bool NameDialog::validateStringForFile(const QString& fileName){
    static const QString invalidChars = "<>:\"/\\|?*"; // Windows restricted characters
    if(fileName.isEmpty()) return false;
    for (const QChar &ch : fileName) {
        if (invalidChars.contains(ch)) {
                return false; // Invalid character found
        }
    }

    return true; // All characters are valid
}

void NameDialog::closeEvent(QCloseEvent *e){
    if(!(result()==QDialog::Accepted)){
        setResult(QDialog::Rejected);
        emit finished(QDialog::Rejected);
    }
    e->accept();
}
