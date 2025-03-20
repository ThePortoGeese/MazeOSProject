#ifndef NAMEDIALOG_H
#define NAMEDIALOG_H


#include "qabstractbutton.h"
#include <QDialog>

namespace Ui {
class NameDialog;
}

class NameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NameDialog(QWidget *parent = nullptr,const QString& lblText="E qual é o nome da tua criação?");
    ~NameDialog();
    QString getName();
private slots:
    void changeLblLimit(const QString& str);

    void on_buttonBox_clicked(QAbstractButton *button);
    bool validateStringForFile(const QString&);
    void closeEvent(QCloseEvent *e) override;
private:
    Ui::NameDialog *ui;
};

#endif // NAMEDIALOG_H
