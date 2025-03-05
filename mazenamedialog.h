#ifndef MAZENAMEDIALOG_H
#define MAZENAMEDIALOG_H


#include "qabstractbutton.h"
#include <QDialog>

namespace Ui {
class MazeNameDialog;
}

class MazeNameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MazeNameDialog(QWidget *parent = nullptr);
    ~MazeNameDialog();
signals:
    void mazeName(QString& name);
private slots:
    void changeLblLimit(const QString& str);

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::MazeNameDialog *ui;
};

#endif // MAZENAMEDIALOG_H
