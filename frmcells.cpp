#include "frmcells.h"
#include "ui_frmcells.h"

frmCells::frmCells(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::frmCells)
{
    ui->setupUi(this);
}

frmCells::~frmCells()
{
    delete ui;
}
