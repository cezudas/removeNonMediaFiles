RESOURCES += \
    GuiResources.qrc
INCLUDEPATH += \
        resources \
        src
DEPENDPATH += \
        resources \
        src
SOURCES += \
    main.cpp \
    gui/extensionswidget.cpp \
    gui/mainwidget.cpp \
    gui/mainwindow.cpp \
    gui/mtoolbutton.cpp \
    controller/mainwidgetcontroller.cpp \
    src/domain/fileeraser.cpp \
    src/gui/guicontr.cpp \
    src/controller/extensionswidgetcontroller.cpp \
    src/model/extitmmodel.cpp \
    src/model/extitem.cpp

HEADERS += \
    gui/extensionswidget.h \
    gui/mainwidget.h \
    gui/mainwindow.h \
    gui/mtoolbutton.h \
    controller/mainwidgetcontroller.h \
    src/domain/fileeraser.h \
    src/gui/guicontr.h \
    src/controller/extensionswidgetcontroller.h \
    src/model/extitmmodel.h \
    src/model/extitem.h
