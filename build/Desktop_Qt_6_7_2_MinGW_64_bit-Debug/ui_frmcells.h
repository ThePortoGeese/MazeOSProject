/********************************************************************************
** Form generated from reading UI file 'frmcells.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCELLS_H
#define UI_FRMCELLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_frmCells
{
public:

    void setupUi(QFrame *frmCells)
    {
        if (frmCells->objectName().isEmpty())
            frmCells->setObjectName("frmCells");
        frmCells->resize(355, 330);

        retranslateUi(frmCells);

        QMetaObject::connectSlotsByName(frmCells);
    } // setupUi

    void retranslateUi(QFrame *frmCells)
    {
        frmCells->setWindowTitle(QCoreApplication::translate("frmCells", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmCells: public Ui_frmCells {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCELLS_H
