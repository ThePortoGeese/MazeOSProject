/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customvideowidget.h>
#include <mazeview.h>
#include "crementbuttons.h"
#include "previewmazeview.h"

QT_BEGIN_NAMESPACE

class Ui_menuWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *btnCredits;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnSummary;
    QStackedWidget *stackedWidget;
    QWidget *pgMenu;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *pgNewUser;
    QGridLayout *gridLayout_7;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *grpTools;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnNewUserMaze;
    QPushButton *btnUserOpenMaze;
    QPushButton *btnUserSave;
    CrementButtons *btnUserExpandH;
    CrementButtons *btnUserExpandV;
    CrementButtons *btnUserContractH;
    CrementButtons *btnUserContractV;
    PreviewMazeView *graphicsMazePreview;
    QSpacerItem *horizontalSpacer_6;
    QWidget *pgNewRandom;
    QGridLayout *gridLayout_3;
    QLabel *lblGenerate;
    QPushButton *btnGenerateMaze;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame_3;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QLabel *lblSlidY;
    QSlider *slidY;
    QFrame *frame_2;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLabel *lblSlidX;
    QSlider *slidX;
    QWidget *pgLabProcess;
    QGridLayout *gridLayout_6;
    QStackedWidget *stackedWidgetLabView;
    QWidget *pgSelectFIle;
    QWidget *pgSelectAlgorithm;
    QWidget *pgLabViewProccess;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lblMazeName;
    QLabel *lblStatus;
    QSpacerItem *horizontalSpacer_7;
    mazeView *graphicsView;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnSolveMaze;
    CustomVideoWidget *pgCredits;
    QWidget *pgLeaderboard;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblImage;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGenerate;
    QPushButton *btnResolve;
    QPushButton *btnLeaderBoards;

    void setupUi(QMainWindow *menuWindow)
    {
        if (menuWindow->objectName().isEmpty())
            menuWindow->setObjectName("menuWindow");
        menuWindow->resize(1000, 800);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(2, 13, 26, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(3, 19, 39, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(2, 16, 32, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(1, 6, 13, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(1, 9, 17, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 127));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush9(QColor(1, 6, 13, 127));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        QBrush brush10(QColor(1, 9, 18, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush10);
        menuWindow->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/others/resources/appLogo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        menuWindow->setWindowIcon(icon);
        centralwidget = new QWidget(menuWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(12, 12, 12, 12);
        btnCredits = new QPushButton(centralwidget);
        btnCredits->setObjectName("btnCredits");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnCredits->sizePolicy().hasHeightForWidth());
        btnCredits->setSizePolicy(sizePolicy);
        btnCredits->setFlat(true);

        gridLayout_2->addWidget(btnCredits, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        btnSummary = new QPushButton(centralwidget);
        btnSummary->setObjectName("btnSummary");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentPageSetup));
        btnSummary->setIcon(icon1);
        btnSummary->setFlat(true);

        gridLayout_2->addWidget(btnSummary, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette1.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush11(QColor(0, 0, 0, 127));
        brush11.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::Accent, brush6);
        stackedWidget->setPalette(palette1);
        pgMenu = new QWidget();
        pgMenu->setObjectName("pgMenu");
        verticalLayout = new QVBoxLayout(pgMenu);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(pgMenu);
        scrollArea->setObjectName("scrollArea");
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette2.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::Accent, brush10);
        scrollArea->setPalette(palette2);
        scrollArea->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea->setFrameShadow(QFrame::Shadow::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 976, 648));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        stackedWidget->addWidget(pgMenu);
        pgNewUser = new QWidget();
        pgNewUser->setObjectName("pgNewUser");
        gridLayout_7 = new QGridLayout(pgNewUser);
        gridLayout_7->setObjectName("gridLayout_7");
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_7->addItem(verticalSpacer_5, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_7->addItem(verticalSpacer_4, 2, 1, 1, 1);

        grpTools = new QGroupBox(pgNewUser);
        grpTools->setObjectName("grpTools");
        verticalLayout_2 = new QVBoxLayout(grpTools);
        verticalLayout_2->setObjectName("verticalLayout_2");
        btnNewUserMaze = new QPushButton(grpTools);
        btnNewUserMaze->setObjectName("btnNewUserMaze");
        sizePolicy.setHeightForWidth(btnNewUserMaze->sizePolicy().hasHeightForWidth());
        btnNewUserMaze->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btnNewUserMaze);

        btnUserOpenMaze = new QPushButton(grpTools);
        btnUserOpenMaze->setObjectName("btnUserOpenMaze");
        sizePolicy.setHeightForWidth(btnUserOpenMaze->sizePolicy().hasHeightForWidth());
        btnUserOpenMaze->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btnUserOpenMaze);

        btnUserSave = new QPushButton(grpTools);
        btnUserSave->setObjectName("btnUserSave");
        sizePolicy.setHeightForWidth(btnUserSave->sizePolicy().hasHeightForWidth());
        btnUserSave->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btnUserSave);

        btnUserExpandH = new CrementButtons(grpTools);
        btnUserExpandH->setObjectName("btnUserExpandH");
        sizePolicy.setHeightForWidth(btnUserExpandH->sizePolicy().hasHeightForWidth());
        btnUserExpandH->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btnUserExpandH);

        btnUserExpandV = new CrementButtons(grpTools);
        btnUserExpandV->setObjectName("btnUserExpandV");
        sizePolicy.setHeightForWidth(btnUserExpandV->sizePolicy().hasHeightForWidth());
        btnUserExpandV->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btnUserExpandV);

        btnUserContractH = new CrementButtons(grpTools);
        btnUserContractH->setObjectName("btnUserContractH");
        sizePolicy.setHeightForWidth(btnUserContractH->sizePolicy().hasHeightForWidth());
        btnUserContractH->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btnUserContractH);

        btnUserContractV = new CrementButtons(grpTools);
        btnUserContractV->setObjectName("btnUserContractV");
        sizePolicy.setHeightForWidth(btnUserContractV->sizePolicy().hasHeightForWidth());
        btnUserContractV->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btnUserContractV);

        btnUserExpandV->raise();
        btnNewUserMaze->raise();
        btnUserOpenMaze->raise();
        btnUserSave->raise();
        btnUserExpandH->raise();
        btnUserContractH->raise();
        btnUserContractV->raise();

        gridLayout_7->addWidget(grpTools, 1, 0, 1, 1);

        graphicsMazePreview = new PreviewMazeView(pgNewUser);
        graphicsMazePreview->setObjectName("graphicsMazePreview");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsMazePreview->sizePolicy().hasHeightForWidth());
        graphicsMazePreview->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(graphicsMazePreview, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(95, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        stackedWidget->addWidget(pgNewUser);
        pgNewRandom = new QWidget();
        pgNewRandom->setObjectName("pgNewRandom");
        gridLayout_3 = new QGridLayout(pgNewRandom);
        gridLayout_3->setObjectName("gridLayout_3");
        lblGenerate = new QLabel(pgNewRandom);
        lblGenerate->setObjectName("lblGenerate");
        QPalette palette3;
        QBrush brush12(QColor(176, 190, 197, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush12);
        lblGenerate->setPalette(palette3);
        QFont font;
        font.setPointSize(32);
        lblGenerate->setFont(font);
        lblGenerate->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        gridLayout_3->addWidget(lblGenerate, 0, 0, 1, 1);

        btnGenerateMaze = new QPushButton(pgNewRandom);
        btnGenerateMaze->setObjectName("btnGenerateMaze");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnGenerateMaze->sizePolicy().hasHeightForWidth());
        btnGenerateMaze->setSizePolicy(sizePolicy2);
        btnGenerateMaze->setMinimumSize(QSize(200, 60));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush13(QColor(0, 168, 232, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush13);
        QBrush brush14(QColor(93, 210, 255, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush14);
        QBrush brush15(QColor(46, 189, 243, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        QBrush brush16(QColor(0, 84, 116, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush16);
        QBrush brush17(QColor(0, 112, 155, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush18(QColor(127, 211, 243, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette4.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush19(QColor(0, 84, 116, 127));
        brush19.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        QBrush brush20(QColor(47, 198, 255, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Disabled, QPalette::Accent, brush20);
        btnGenerateMaze->setPalette(palette4);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Yu Gothic UI")});
        font1.setPointSize(16);
        btnGenerateMaze->setFont(font1);

        gridLayout_3->addWidget(btnGenerateMaze, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 5, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_3->addItem(verticalSpacer_3, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 6, 1, 1, 1);

        frame_3 = new QFrame(pgNewRandom);
        frame_3->setObjectName("frame_3");
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(0, 100));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush21(QColor(19, 30, 44, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush21);
        QBrush brush22(QColor(28, 45, 66, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush22);
        QBrush brush23(QColor(23, 37, 55, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush23);
        QBrush brush24(QColor(9, 15, 22, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush24);
        QBrush brush25(QColor(13, 20, 29, 255));
        brush25.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush25);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush21);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush21);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush24);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette5.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush21);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush22);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush23);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush24);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush25);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush21);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush21);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush24);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush24);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush21);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush22);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush23);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush24);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush25);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush24);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush24);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush21);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush21);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush21);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush26(QColor(9, 15, 22, 127));
        brush26.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        QBrush brush27(QColor(13, 21, 31, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Disabled, QPalette::Accent, brush27);
        frame_3->setPalette(palette5);
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_5 = new QGridLayout(frame_3);
        gridLayout_5->setObjectName("gridLayout_5");
        label_3 = new QLabel(frame_3);
        label_3->setObjectName("label_3");
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        label_3->setPalette(palette6);
        QFont font2;
        font2.setPointSize(11);
        label_3->setFont(font2);

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        lblSlidY = new QLabel(frame_3);
        lblSlidY->setObjectName("lblSlidY");
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        lblSlidY->setPalette(palette7);
        lblSlidY->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_5->addWidget(lblSlidY, 0, 2, 1, 1);

        slidY = new QSlider(frame_3);
        slidY->setObjectName("slidY");
        slidY->setMinimum(2);
        slidY->setMaximum(128);
        slidY->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_5->addWidget(slidY, 1, 0, 1, 3);


        gridLayout_3->addWidget(frame_3, 4, 0, 1, 2);

        frame_2 = new QFrame(pgNewRandom);
        frame_2->setObjectName("frame_2");
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(0, 100));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush21);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush22);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush23);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush24);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush25);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush21);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush21);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush24);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette8.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush21);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush22);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush23);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush24);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush25);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush21);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush21);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush24);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush24);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush21);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush22);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush23);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush24);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush25);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush24);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush24);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush21);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush21);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush21);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::Accent, brush27);
        frame_2->setPalette(palette8);
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setObjectName("gridLayout_4");
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        label_2->setPalette(palette9);
        label_2->setFont(font2);

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        lblSlidX = new QLabel(frame_2);
        lblSlidX->setObjectName("lblSlidX");
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        lblSlidX->setPalette(palette10);
        lblSlidX->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(lblSlidX, 0, 2, 1, 1);

        slidX = new QSlider(frame_2);
        slidX->setObjectName("slidX");
        slidX->setMinimum(2);
        slidX->setMaximum(128);
        slidX->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_4->addWidget(slidX, 1, 0, 1, 3);


        gridLayout_3->addWidget(frame_2, 2, 0, 1, 2);

        stackedWidget->addWidget(pgNewRandom);
        pgLabProcess = new QWidget();
        pgLabProcess->setObjectName("pgLabProcess");
        gridLayout_6 = new QGridLayout(pgLabProcess);
        gridLayout_6->setObjectName("gridLayout_6");
        stackedWidgetLabView = new QStackedWidget(pgLabProcess);
        stackedWidgetLabView->setObjectName("stackedWidgetLabView");
        pgSelectFIle = new QWidget();
        pgSelectFIle->setObjectName("pgSelectFIle");
        stackedWidgetLabView->addWidget(pgSelectFIle);
        pgSelectAlgorithm = new QWidget();
        pgSelectAlgorithm->setObjectName("pgSelectAlgorithm");
        stackedWidgetLabView->addWidget(pgSelectAlgorithm);
        pgLabViewProccess = new QWidget();
        pgLabViewProccess->setObjectName("pgLabViewProccess");
        gridLayout_8 = new QGridLayout(pgLabViewProccess);
        gridLayout_8->setObjectName("gridLayout_8");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");

        gridLayout_8->addLayout(horizontalLayout_5, 0, 0, 2, 3);

        lblMazeName = new QLabel(pgLabViewProccess);
        lblMazeName->setObjectName("lblMazeName");
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        lblMazeName->setPalette(palette11);
        lblMazeName->setFont(font);

        gridLayout_8->addWidget(lblMazeName, 1, 1, 1, 2);

        lblStatus = new QLabel(pgLabViewProccess);
        lblStatus->setObjectName("lblStatus");
        QPalette palette12;
        QBrush brush28(QColor(255, 79, 0, 255));
        brush28.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush28);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush28);
        QBrush brush29(QColor(253, 78, 0, 255));
        brush29.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Active, QPalette::BrightText, brush29);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush28);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush28);
        palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush29);
        palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush29);
        lblStatus->setPalette(palette12);
        QFont font3;
        font3.setPointSize(16);
        lblStatus->setFont(font3);
        lblStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_8->addWidget(lblStatus, 1, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_7, 2, 1, 1, 1);

        graphicsView = new mazeView(pgLabViewProccess);
        graphicsView->setObjectName("graphicsView");

        gridLayout_8->addWidget(graphicsView, 2, 2, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_5, 2, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(433, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_4, 3, 3, 1, 1);

        btnSolveMaze = new QPushButton(pgLabViewProccess);
        btnSolveMaze->setObjectName("btnSolveMaze");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnSolveMaze->sizePolicy().hasHeightForWidth());
        btnSolveMaze->setSizePolicy(sizePolicy3);
        btnSolveMaze->setMinimumSize(QSize(0, 60));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette13.setBrush(QPalette::Active, QPalette::Light, brush14);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette13.setBrush(QPalette::Active, QPalette::Dark, brush16);
        palette13.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette13.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush21);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette13.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette13.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette13.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette13.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette13.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush21);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette13.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette13.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette13.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette13.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette13.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette13.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::Accent, brush20);
        btnSolveMaze->setPalette(palette13);
        btnSolveMaze->setFont(font3);

        gridLayout_8->addWidget(btnSolveMaze, 3, 1, 1, 1);

        stackedWidgetLabView->addWidget(pgLabViewProccess);

        gridLayout_6->addWidget(stackedWidgetLabView, 0, 0, 1, 1);

        stackedWidget->addWidget(pgLabProcess);
        pgCredits = new CustomVideoWidget();
        pgCredits->setObjectName("pgCredits");
        stackedWidget->addWidget(pgCredits);
        pgLeaderboard = new QWidget();
        pgLeaderboard->setObjectName("pgLeaderboard");
        stackedWidget->addWidget(pgLeaderboard);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 3);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 2);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy4);
        frame->setMaximumSize(QSize(16777215, 100));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush21);
        palette14.setBrush(QPalette::Active, QPalette::Light, brush22);
        palette14.setBrush(QPalette::Active, QPalette::Midlight, brush23);
        palette14.setBrush(QPalette::Active, QPalette::Dark, brush24);
        palette14.setBrush(QPalette::Active, QPalette::Mid, brush25);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush);
        palette14.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush21);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush21);
        palette14.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush24);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette14.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush21);
        palette14.setBrush(QPalette::Inactive, QPalette::Light, brush22);
        palette14.setBrush(QPalette::Inactive, QPalette::Midlight, brush23);
        palette14.setBrush(QPalette::Inactive, QPalette::Dark, brush24);
        palette14.setBrush(QPalette::Inactive, QPalette::Mid, brush25);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush21);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush21);
        palette14.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush24);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush24);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush21);
        palette14.setBrush(QPalette::Disabled, QPalette::Light, brush22);
        palette14.setBrush(QPalette::Disabled, QPalette::Midlight, brush23);
        palette14.setBrush(QPalette::Disabled, QPalette::Dark, brush24);
        palette14.setBrush(QPalette::Disabled, QPalette::Mid, brush25);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush24);
        palette14.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush24);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush21);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush21);
        palette14.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush21);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::Accent, brush27);
        frame->setPalette(palette14);
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Plain);
        frame->setLineWidth(0);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(20, -1, -1, -1);
        lblImage = new QLabel(frame);
        lblImage->setObjectName("lblImage");
        lblImage->setMinimumSize(QSize(60, 60));
        lblImage->setMaximumSize(QSize(60, 60));
        lblImage->setScaledContents(true);

        horizontalLayout_2->addWidget(lblImage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(6, 6, 6, 6);
        btnGenerate = new QPushButton(frame);
        btnGenerate->setObjectName("btnGenerate");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btnGenerate->sizePolicy().hasHeightForWidth());
        btnGenerate->setSizePolicy(sizePolicy5);
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette15.setBrush(QPalette::Active, QPalette::Light, brush14);
        palette15.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette15.setBrush(QPalette::Active, QPalette::Dark, brush16);
        palette15.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette15.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette15.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette15.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette15.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette15.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette15.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette15.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette15.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette15.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette15.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette15.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette15.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette15.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette15.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette15.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette15.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette15.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::Accent, brush20);
        btnGenerate->setPalette(palette15);
        btnGenerate->setFont(font1);

        horizontalLayout->addWidget(btnGenerate);

        btnResolve = new QPushButton(frame);
        btnResolve->setObjectName("btnResolve");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(btnResolve->sizePolicy().hasHeightForWidth());
        btnResolve->setSizePolicy(sizePolicy6);
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette16.setBrush(QPalette::Active, QPalette::Light, brush14);
        palette16.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette16.setBrush(QPalette::Active, QPalette::Dark, brush16);
        palette16.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette16.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette16.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette16.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette16.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette16.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette16.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette16.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette16.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette16.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette16.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette16.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette16.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette16.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette16.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette16.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette16.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette16.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::Accent, brush20);
        btnResolve->setPalette(palette16);
        btnResolve->setFont(font3);

        horizontalLayout->addWidget(btnResolve);

        btnLeaderBoards = new QPushButton(frame);
        btnLeaderBoards->setObjectName("btnLeaderBoards");
        sizePolicy.setHeightForWidth(btnLeaderBoards->sizePolicy().hasHeightForWidth());
        btnLeaderBoards->setSizePolicy(sizePolicy);
        btnLeaderBoards->setMinimumSize(QSize(74, 0));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette17.setBrush(QPalette::Active, QPalette::Light, brush14);
        palette17.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette17.setBrush(QPalette::Active, QPalette::Dark, brush16);
        palette17.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette17.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette17.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette17.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette17.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette17.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette17.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette17.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette17.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette17.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette17.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette17.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette17.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette17.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette17.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette17.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette17.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette17.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette17.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        palette17.setBrush(QPalette::Disabled, QPalette::Accent, brush20);
        btnLeaderBoards->setPalette(palette17);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/others/resources/trophyIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnLeaderBoards->setIcon(icon2);
        btnLeaderBoards->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(btnLeaderBoards);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout->addWidget(frame, 0, 0, 1, 2);

        menuWindow->setCentralWidget(centralwidget);

        retranslateUi(menuWindow);

        QMetaObject::connectSlotsByName(menuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *menuWindow)
    {
        menuWindow->setWindowTitle(QCoreApplication::translate("menuWindow", "MazeSolver_v1.0", nullptr));
        btnCredits->setText(QCoreApplication::translate("menuWindow", "Cr\303\251ditos", nullptr));
        btnSummary->setText(QString());
        grpTools->setTitle(QString());
        btnNewUserMaze->setText(QCoreApplication::translate("menuWindow", "New", nullptr));
        btnUserOpenMaze->setText(QCoreApplication::translate("menuWindow", "Open", nullptr));
        btnUserSave->setText(QCoreApplication::translate("menuWindow", "Save", nullptr));
        btnUserExpandH->setText(QCoreApplication::translate("menuWindow", "Expand H", nullptr));
        btnUserExpandV->setText(QCoreApplication::translate("menuWindow", "Expand V", nullptr));
        btnUserContractH->setText(QCoreApplication::translate("menuWindow", "Contract H", nullptr));
        btnUserContractV->setText(QCoreApplication::translate("menuWindow", "Contract V", nullptr));
        lblGenerate->setText(QCoreApplication::translate("menuWindow", "Gerar Novo Labirinto", nullptr));
        btnGenerateMaze->setText(QCoreApplication::translate("menuWindow", "Gerar Labirinto", nullptr));
        label_3->setText(QCoreApplication::translate("menuWindow", "Altura", nullptr));
        lblSlidY->setText(QCoreApplication::translate("menuWindow", "(2)", nullptr));
        label_2->setText(QCoreApplication::translate("menuWindow", "Largura", nullptr));
        lblSlidX->setText(QCoreApplication::translate("menuWindow", "(2)", nullptr));
        lblMazeName->setText(QCoreApplication::translate("menuWindow", "TextLabel", nullptr));
        lblStatus->setText(QCoreApplication::translate("menuWindow", "ESTADO:\n"
"Idle", nullptr));
        btnSolveMaze->setText(QCoreApplication::translate("menuWindow", "Resolver o Labirinto", nullptr));
        lblImage->setText(QString());
        btnGenerate->setText(QCoreApplication::translate("menuWindow", "Cria\303\247\303\243o do Labirinto", nullptr));
        btnResolve->setText(QCoreApplication::translate("menuWindow", "Resolu\303\247\303\243o do Labirinto", nullptr));
        btnLeaderBoards->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menuWindow: public Ui_menuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
