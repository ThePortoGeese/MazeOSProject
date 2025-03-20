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
}

bool NameDialog::validateStringForFile(const QString& fileName){
    static const QString invalidChars = "<>:\"/\\|?*"; // Windows restricted characters
    static const QStringList profaneWords = {
        "merda", "porra", "caralho", "fdp", "foda", "puta", "cabrão","cabrao","estupido","merdoso", "estúpido", "burro",
        "shit", "fuck", "bitch", "asshole", "bastard", "crap", "damn", "cunt", "motherfucker","nigger"
    };

    if (fileName.isEmpty()) {
        QMessageBox::critical(this,"Inválido.","Nome não pode ser vazio.");
        return false;
    }
    for (const QChar &ch : fileName) {
        if (invalidChars.contains(ch)) {
            QMessageBox::critical(this,"Inválido.","Nome não pode ser vazio nem conter caracteres especiais ([\\/:*?\"<>|]).");
            return false; // Caractere inválido encontrado
        }
    }

    for (const QString &word : profaneWords) {
        if (fileName.toLower().contains(word, Qt::CaseInsensitive)) {
            QMessageBox::critical(this,"Inválido.","Nome não pode conter profanidade.");
            return false; // Palavra proibida encontrada
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
