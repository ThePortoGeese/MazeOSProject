QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QT += multimedia multimediawidgets

SOURCES += \
    GraphicsViews/graphicslabviewproccess.cpp \
    GraphicsViewsitems/instructioncircleitem.cpp \
    Widgets/algorithmselectionbox.cpp \
    GraphicsViewsitems/cellgraphicsrectitem.cpp \
    Widgets/customvideowidget.cpp \
    Widgets/informationpage.cpp \
    main.cpp \
    GraphicsViews/mazeView.cpp \
    mazeclass.cpp \
    Widgets/menuwindow.cpp \
    Widgets/namedialog.cpp \
    GraphicsViews/previewmazeview.cpp \
    qmazes.cpp

HEADERS += \
    GraphicsViews/graphicslabviewproccess.h \
    GraphicsViewsitems/abstractgraphicsrectitem.h \
    GraphicsViewsitems/abstractshapeitem.h \
    GraphicsViewsitems/instructioncircleitem.h \
    Widgets/algorithmselectionbox.h \
    GraphicsViewsitems/cellgraphicsrectitem.h \
    Widgets/crementbuttons.h \
    Widgets/customvideowidget.h \
    Widgets/informationpage.h \
    mazeclass.h \
    GraphicsViews/mazeview.h \
    Widgets/menuwindow.h \
    Widgets/namedialog.h \
    Widgets/noclickqtxtbrowser.h \
    GraphicsViews/previewmazeview.h \
    Widgets/qlabelwithpresssignal.h \
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
