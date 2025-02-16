/********************************************************************************
** Form generated from reading UI file 'simulationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATIONWINDOW_H
#define UI_SIMULATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simulationWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QGridLayout *labLayout;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QMainWindow *simulationWindow)
    {
        if (simulationWindow->objectName().isEmpty())
            simulationWindow->setObjectName("simulationWindow");
        simulationWindow->resize(800, 600);
        centralwidget = new QWidget(simulationWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(10, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        labLayout = new QGridLayout();
        labLayout->setSpacing(0);
        labLayout->setObjectName("labLayout");

        gridLayout->addLayout(labLayout, 2, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        simulationWindow->setCentralWidget(centralwidget);

        retranslateUi(simulationWindow);

        QMetaObject::connectSlotsByName(simulationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *simulationWindow)
    {
        simulationWindow->setWindowTitle(QCoreApplication::translate("simulationWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("simulationWindow", "Labirinto", nullptr));
        pushButton->setText(QCoreApplication::translate("simulationWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class simulationWindow: public Ui_simulationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATIONWINDOW_H
