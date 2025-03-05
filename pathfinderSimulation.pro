QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT += multimedia multimediawidgets

SOURCES += \
    cellgraphicsrectitem.cpp \
    customvideowidget.cpp \
    informationpage.cpp \
    main.cpp \
    mazeView.cpp \
    mazeclass.cpp \
    mazenamedialog.cpp \
    menuwindow.cpp \
    previewmazeview.cpp \
    qmazes.cpp

HEADERS += \
    abstractgraphicsrectitem.h \
    cellgraphicsrectitem.h \
    crementbuttons.h \
    customvideowidget.h \
    informationpage.h \
    mazeclass.h \
    mazenamedialog.h \
    mazeview.h \
    menuwindow.h \
    previewmazeview.h \
    qmazes.h \
    qmazesconversionmethods.h \
    wallhgraphicsrectitem.h \
    wallvgraphicsrectitem.h

FORMS += \
    informationpage.ui \
    mazenamedialog.ui \
    menuwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    data.qrc
