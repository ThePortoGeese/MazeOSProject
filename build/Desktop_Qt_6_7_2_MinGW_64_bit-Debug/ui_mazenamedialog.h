/********************************************************************************
** Form generated from reading UI file 'mazenamedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAZENAMEDIALOG_H
#define UI_MAZENAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MazeNameDialog
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblInsertName;
    QLineEdit *lineEdit;
    QLabel *lblTxtLimit;
    QWidget *page_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MazeNameDialog)
    {
        if (MazeNameDialog->objectName().isEmpty())
            MazeNameDialog->setObjectName("MazeNameDialog");
        MazeNameDialog->resize(400, 129);
        gridLayout = new QGridLayout(MazeNameDialog);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(MazeNameDialog);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lblInsertName = new QLabel(page);
        lblInsertName->setObjectName("lblInsertName");
        QFont font;
        font.setPointSize(15);
        lblInsertName->setFont(font);

        verticalLayout_2->addWidget(lblInsertName);

        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMaxLength(32);

        verticalLayout_2->addWidget(lineEdit);

        lblTxtLimit = new QLabel(page);
        lblTxtLimit->setObjectName("lblTxtLimit");
        lblTxtLimit->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_2->addWidget(lblTxtLimit);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(MazeNameDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Apply);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(MazeNameDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MazeNameDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MazeNameDialog, qOverload<>(&QDialog::reject));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MazeNameDialog);
    } // setupUi

    void retranslateUi(QDialog *MazeNameDialog)
    {
        MazeNameDialog->setWindowTitle(QCoreApplication::translate("MazeNameDialog", "Precisamos de um Nome!", nullptr));
        lblInsertName->setText(QCoreApplication::translate("MazeNameDialog", "E qual \303\251 o nome da tua cria\303\247\303\243o?", nullptr));
        lblTxtLimit->setText(QCoreApplication::translate("MazeNameDialog", "(0/32)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MazeNameDialog: public Ui_MazeNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAZENAMEDIALOG_H
