#ifndef FRMCELLS_H
#define FRMCELLS_H

#include <QFrame>

namespace Ui {
class frmCells;
}

class frmCells : public QFrame
{
    Q_OBJECT

public:
    explicit frmCells(QWidget *parent = nullptr);
    ~frmCells();

    int cellOpacity=0;

private:
    Ui::frmCells *ui;
};

#endif // FRMCELLS_H
