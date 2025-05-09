QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT_MEDIA_BACKEND = gstreamer

QT += multimedia multimediawidgets
QT += multimedia multimediawidgets

SOURCES += \
    2dmaze.cpp \
    3dmaze.cpp \
    GraphicsViews/graphicslabviewproccess.cpp \
    GraphicsViewsitems/instructioncircleitem.cpp \
    Widgets/algorithmselectionbox.cpp \
    GraphicsViewsitems/cellgraphicsrectitem.cpp \
    Widgets/informationpage.cpp \
    main.cpp \
    GraphicsViews/mazeView.cpp \
    Widgets/menuwindow.cpp \
    Widgets/namedialog.cpp \
    GraphicsViews/previewmazeview.cpp \
    qmazes.cpp

HEADERS += \
    2dmaze.h \
    3dmaze.h \
    GraphicsViews/graphicslabviewproccess.h \
    GraphicsViewsitems/abstractgraphicsrectitem.h \
    GraphicsViewsitems/abstractshapeitem.h \
    GraphicsViewsitems/instructioncircleitem.h \
    Widgets/algorithmselectionbox.h \
    GraphicsViewsitems/cellgraphicsrectitem.h \
    Widgets/crementbuttons.h \
    Widgets/informationpage.h \
    GraphicsViews/mazeview.h \
    Widgets/menuwindow.h \
    Widgets/namedialog.h \
    Widgets/noclickqtxtbrowser.h \
    GraphicsViews/previewmazeview.h \
    Widgets/qlabelwithpresssignal.h \
    basemaze.h \
    qmazes.h \
    qmazesconversionmethods.h \
    GraphicsViewsitems/wallhgraphicsrectitem.h \
    GraphicsViewsitems/wallvgraphicsrectitem.h

FORMS += \
    Widgets/algorithmselectionbox.ui \
    Widgets/informationpage.ui \
    Widgets/menuwindow.ui \
    Widgets/namedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Widgets/data.qrc \
    Widgets/data.qrc \
    data.qrc
