#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <algorithm>
#include "frmcells.h"
#include <QMainWindow>
#include <iostream>
#include <windows.h>
namespace Ui {
class simulationWindow;
}


class simulationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit simulationWindow(QWidget *parent = nullptr);
    ~simulationWindow();
    std::vector<std::vector<int>> maze;
    bool recursiveFunction(std::vector<std::vector<bool>>& booleanGrid, const int i, const int y);
    void mazeSolver(const int& ix,const int& iy);
    std::vector<std::vector <frmCells*>> frameVector;
private slots:
    void on_pushButton_clicked();

private:
    Ui::simulationWindow *ui;
};

#endif // SIMULATIONWINDOW_H
