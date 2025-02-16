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
    QWidget *pgNew;
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
    QWidget *pgLabView;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnSolveMaze;
    QSpacerItem *horizontalSpacer_4;
    mazeView *graphicsView;
    QSpacerItem *horizontalSpacer_5;
    QLabel *lblMazeName;
    CustomVideoWidget *pgCredits;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblImage;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnGenerate;
    QPushButton *btnResolve;

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
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::HelpFaq));
        btnSummary->setIcon(icon);
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
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 974, 646));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        stackedWidget->addWidget(pgMenu);
        pgNew = new QWidget();
        pgNew->setObjectName("pgNew");
        gridLayout_3 = new QGridLayout(pgNew);
        gridLayout_3->setObjectName("gridLayout_3");
        lblGenerate = new QLabel(pgNew);
        lblGenerate->setObjectName("lblGenerate");
        QPalette palette2;
        QBrush brush12(QColor(176, 190, 197, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush12);
        lblGenerate->setPalette(palette2);
        QFont font;
        font.setPointSize(32);
        lblGenerate->setFont(font);
        lblGenerate->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        gridLayout_3->addWidget(lblGenerate, 0, 0, 1, 1);

        btnGenerateMaze = new QPushButton(pgNew);
        btnGenerateMaze->setObjectName("btnGenerateMaze");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnGenerateMaze->sizePolicy().hasHeightForWidth());
        btnGenerateMaze->setSizePolicy(sizePolicy1);
        btnGenerateMaze->setMinimumSize(QSize(200, 60));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush13(QColor(0, 168, 232, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush13);
        QBrush brush14(QColor(93, 210, 255, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush14);
        QBrush brush15(QColor(46, 189, 243, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        QBrush brush16(QColor(0, 84, 116, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush16);
        QBrush brush17(QColor(0, 112, 155, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush18(QColor(127, 211, 243, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette3.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush19(QColor(0, 84, 116, 127));
        brush19.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        QBrush brush20(QColor(47, 198, 255, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Disabled, QPalette::Accent, brush20);
        btnGenerateMaze->setPalette(palette3);
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

        frame_3 = new QFrame(pgNew);
        frame_3->setObjectName("frame_3");
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(0, 100));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush21(QColor(19, 30, 44, 255));
        brush21.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush21);
        QBrush brush22(QColor(28, 45, 66, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush22);
        QBrush brush23(QColor(23, 37, 55, 255));
        brush23.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush23);
        QBrush brush24(QColor(9, 15, 22, 255));
        brush24.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush24);
        QBrush brush25(QColor(13, 20, 29, 255));
        brush25.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush25);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush21);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush21);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush24);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette4.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush21);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush22);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush23);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush24);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush25);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush21);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush21);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush24);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush24);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush21);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush22);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush23);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush24);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush25);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush24);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush24);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush21);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush21);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush21);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush26(QColor(9, 15, 22, 127));
        brush26.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        QBrush brush27(QColor(13, 21, 31, 255));
        brush27.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Disabled, QPalette::Accent, brush27);
        frame_3->setPalette(palette4);
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_5 = new QGridLayout(frame_3);
        gridLayout_5->setObjectName("gridLayout_5");
        label_3 = new QLabel(frame_3);
        label_3->setObjectName("label_3");
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        label_3->setPalette(palette5);
        QFont font2;
        font2.setPointSize(11);
        label_3->setFont(font2);

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        lblSlidY = new QLabel(frame_3);
        lblSlidY->setObjectName("lblSlidY");
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        lblSlidY->setPalette(palette6);
        lblSlidY->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_5->addWidget(lblSlidY, 0, 2, 1, 1);

        slidY = new QSlider(frame_3);
        slidY->setObjectName("slidY");
        slidY->setMinimum(2);
        slidY->setMaximum(128);
        slidY->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_5->addWidget(slidY, 1, 0, 1, 3);


        gridLayout_3->addWidget(frame_3, 4, 0, 1, 2);

        frame_2 = new QFrame(pgNew);
        frame_2->setObjectName("frame_2");
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(0, 100));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush21);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush22);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush23);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush24);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush25);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush21);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush21);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush24);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette7.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush21);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush22);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush23);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush24);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush25);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush21);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush21);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush24);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush24);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush21);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush22);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush23);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush24);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush25);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush24);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush24);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush21);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush21);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush21);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::Accent, brush27);
        frame_2->setPalette(palette7);
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setObjectName("gridLayout_4");
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        label_2->setPalette(palette8);
        label_2->setFont(font2);

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        lblSlidX = new QLabel(frame_2);
        lblSlidX->setObjectName("lblSlidX");
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        lblSlidX->setPalette(palette9);
        lblSlidX->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        gridLayout_4->addWidget(lblSlidX, 0, 2, 1, 1);

        slidX = new QSlider(frame_2);
        slidX->setObjectName("slidX");
        slidX->setMinimum(2);
        slidX->setMaximum(128);
        slidX->setOrientation(Qt::Orientation::Horizontal);

        gridLayout_4->addWidget(slidX, 1, 0, 1, 3);


        gridLayout_3->addWidget(frame_2, 2, 0, 1, 2);

        stackedWidget->addWidget(pgNew);
        pgLabView = new QWidget();
        pgLabView->setObjectName("pgLabView");
        gridLayout_6 = new QGridLayout(pgLabView);
        gridLayout_6->setObjectName("gridLayout_6");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        btnSolveMaze = new QPushButton(pgLabView);
        btnSolveMaze->setObjectName("btnSolveMaze");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnSolveMaze->sizePolicy().hasHeightForWidth());
        btnSolveMaze->setSizePolicy(sizePolicy2);
        btnSolveMaze->setMinimumSize(QSize(0, 60));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush14);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush16);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush21);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette10.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush21);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::Accent, brush20);
        btnSolveMaze->setPalette(palette10);
        QFont font3;
        font3.setPointSize(16);
        btnSolveMaze->setFont(font3);

        horizontalLayout_4->addWidget(btnSolveMaze);


        gridLayout_6->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 2, 2, 1, 1);

        graphicsView = new mazeView(pgLabView);
        graphicsView->setObjectName("graphicsView");

        gridLayout_6->addWidget(graphicsView, 1, 0, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 2, 1, 1, 1);

        lblMazeName = new QLabel(pgLabView);
        lblMazeName->setObjectName("lblMazeName");
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush12);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush12);
        lblMazeName->setPalette(palette11);
        lblMazeName->setFont(font);

        gridLayout_6->addWidget(lblMazeName, 0, 0, 1, 2);

        stackedWidget->addWidget(pgLabView);
        pgCredits = new CustomVideoWidget();
        pgCredits->setObjectName("pgCredits");
        stackedWidget->addWidget(pgCredits);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 3);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 2);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setMaximumSize(QSize(16777215, 100));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush21);
        palette12.setBrush(QPalette::Active, QPalette::Light, brush22);
        palette12.setBrush(QPalette::Active, QPalette::Midlight, brush23);
        palette12.setBrush(QPalette::Active, QPalette::Dark, brush24);
        palette12.setBrush(QPalette::Active, QPalette::Mid, brush25);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush21);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush21);
        palette12.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush24);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette12.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush21);
        palette12.setBrush(QPalette::Inactive, QPalette::Light, brush22);
        palette12.setBrush(QPalette::Inactive, QPalette::Midlight, brush23);
        palette12.setBrush(QPalette::Inactive, QPalette::Dark, brush24);
        palette12.setBrush(QPalette::Inactive, QPalette::Mid, brush25);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush21);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush21);
        palette12.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush24);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush24);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush21);
        palette12.setBrush(QPalette::Disabled, QPalette::Light, brush22);
        palette12.setBrush(QPalette::Disabled, QPalette::Midlight, brush23);
        palette12.setBrush(QPalette::Disabled, QPalette::Dark, brush24);
        palette12.setBrush(QPalette::Disabled, QPalette::Mid, brush25);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush24);
        palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush24);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush21);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush21);
        palette12.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush21);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::Accent, brush27);
        frame->setPalette(palette12);
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
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btnGenerate->sizePolicy().hasHeightForWidth());
        btnGenerate->setSizePolicy(sizePolicy4);
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette13.setBrush(QPalette::Active, QPalette::Light, brush14);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette13.setBrush(QPalette::Active, QPalette::Dark, brush16);
        palette13.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
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
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
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
        btnGenerate->setPalette(palette13);
        btnGenerate->setFont(font1);

        horizontalLayout->addWidget(btnGenerate);

        btnResolve = new QPushButton(frame);
        btnResolve->setObjectName("btnResolve");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btnResolve->sizePolicy().hasHeightForWidth());
        btnResolve->setSizePolicy(sizePolicy5);
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush13);
        palette14.setBrush(QPalette::Active, QPalette::Light, brush14);
        palette14.setBrush(QPalette::Active, QPalette::Midlight, brush15);
        palette14.setBrush(QPalette::Active, QPalette::Dark, brush16);
        palette14.setBrush(QPalette::Active, QPalette::Mid, brush17);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette14.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette14.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush18);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush11);
#endif
        palette14.setBrush(QPalette::Active, QPalette::Accent, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush13);
        palette14.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette14.setBrush(QPalette::Inactive, QPalette::Midlight, brush15);
        palette14.setBrush(QPalette::Inactive, QPalette::Dark, brush16);
        palette14.setBrush(QPalette::Inactive, QPalette::Mid, brush17);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette14.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush18);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::Accent, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush16);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush13);
        palette14.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette14.setBrush(QPalette::Disabled, QPalette::Midlight, brush15);
        palette14.setBrush(QPalette::Disabled, QPalette::Dark, brush16);
        palette14.setBrush(QPalette::Disabled, QPalette::Mid, brush17);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush16);
        palette14.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush16);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        palette14.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush13);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush19);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::Accent, brush20);
        btnResolve->setPalette(palette14);
        btnResolve->setFont(font3);

        horizontalLayout->addWidget(btnResolve);


        horizontalLayout_2->addLayout(horizontalLayout);


        gridLayout->addWidget(frame, 0, 0, 1, 2);

        menuWindow->setCentralWidget(centralwidget);

        retranslateUi(menuWindow);

        QMetaObject::connectSlotsByName(menuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *menuWindow)
    {
        menuWindow->setWindowTitle(QCoreApplication::translate("menuWindow", "MainWindow", nullptr));
        btnCredits->setText(QCoreApplication::translate("menuWindow", "Cr\303\251ditos", nullptr));
        btnSummary->setText(QString());
        lblGenerate->setText(QCoreApplication::translate("menuWindow", "Gerar Novo Labirinto", nullptr));
        btnGenerateMaze->setText(QCoreApplication::translate("menuWindow", "Gerar Labirinto", nullptr));
        label_3->setText(QCoreApplication::translate("menuWindow", "Altura", nullptr));
        lblSlidY->setText(QCoreApplication::translate("menuWindow", "(2)", nullptr));
        label_2->setText(QCoreApplication::translate("menuWindow", "Largura", nullptr));
        lblSlidX->setText(QCoreApplication::translate("menuWindow", "(2)", nullptr));
        btnSolveMaze->setText(QCoreApplication::translate("menuWindow", "Resolver o Labirinto", nullptr));
        lblMazeName->setText(QCoreApplication::translate("menuWindow", "TextLabel", nullptr));
        lblImage->setText(QString());
        btnGenerate->setText(QCoreApplication::translate("menuWindow", "Cria\303\247\303\243o do Labirinto", nullptr));
        btnResolve->setText(QCoreApplication::translate("menuWindow", "Resolu\303\247\303\243o do Labirinto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menuWindow: public Ui_menuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
