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
    mitemmodel.cpp \
    gui/mtoolbutton.cpp \
    controller/mainwidgetcontroller.cpp \
    src/repo/dirrepo.cpp \
    src/repo/extrepo.cpp

HEADERS += \
    gui/extensionswidget.h \
    gui/mainwidget.h \
    gui/mainwindow.h \
    mitemmodel.h \
    gui/mtoolbutton.h \
    controller/mainwidgetcontroller.h \
    src/repo/dirrepo.h \
    src/repo/extrepo.h
