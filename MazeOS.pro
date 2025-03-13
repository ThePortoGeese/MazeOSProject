QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT += multimedia multimediawidgets

SOURCES += \
    algorithmselectionbox.cpp \
    cellgraphicsrectitem.cpp \
    customvideowidget.cpp \
    informationpage.cpp \
    main.cpp \
    mazeView.cpp \
    mazeclass.cpp \
    menuwindow.cpp \
    namedialog.cpp \
    previewmazeview.cpp \
    qmazes.cpp

HEADERS += \
    abstractgraphicsrectitem.h \
    algorithmselectionbox.h \
    cellgraphicsrectitem.h \
    crementbuttons.h \
    customvideowidget.h \
    informationpage.h \
    mazeclass.h \
    mazeview.h \
    menuwindow.h \
    namedialog.h \
    noclickqtxtbrowser.h \
    previewmazeview.h \
    qmazes.h \
    qmazesconversionmethods.h \
    wallhgraphicsrectitem.h \
    wallvgraphicsrectitem.h

FORMS += \
    algorithmselectionbox.ui \
    informationpage.ui \
    menuwindow.ui \
    namedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    data.qrc
