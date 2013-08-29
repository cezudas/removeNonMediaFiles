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
    Gui/extensionswidget.cpp \
    Gui/mainwidget.cpp \
    Gui/mainwindow.cpp \
    mitemmodel.cpp \
    Gui/mtoolbutton.cpp

HEADERS += \
    Gui/extensionswidget.h \
    Gui/mainwidget.h \
    Gui/mainwindow.h \
    mitemmodel.h \
    Gui/mtoolbutton.h
