#include <QtGui/QApplication>
#include "gui/mainwindow.h"
#include "gui/mainwidget.h"
#include "gui/extensionswidget.h"
#include "domain/fileeraser.h"
#include "gui/guicontr.h"
#include "domain/fileeraser.h"
#include "controller/extensionswidgetcontroller.h"
#include "controller/mainwidgetcontroller.h"
#include <QStackedWidget>
#include <QStringListModel>
int main(int argc, char **args){
    QApplication a(argc,args);
    MainWidget *mainWidget = new MainWidget;
    QStringListModel dirModel;
    QStringListModel fileExtModel;
    FileEraser fileEraser(&dirModel,&fileExtModel);
    ExtensionsWidget *extensionWidget = new ExtensionsWidget;
    QStackedWidget *placeHolderWidget = new QStackedWidget;
    ExtensionsWidgetController eWController(extensionWidget,&fileExtModel);
    MainWidgetController mWController(mainWidget,&dirModel,&fileEraser);
    MainWindow mDiag(placeHolderWidget);
    GuiContr guiContr(&mDiag,mainWidget,extensionWidget);
    placeHolderWidget->addWidget(mainWidget);
    placeHolderWidget->addWidget(extensionWidget);
    QObject::connect(mainWidget,SIGNAL(widgetHidden(QWidget*)),&guiContr,SLOT(unSetCentralWidget(QWidget*)));
    QObject::connect(extensionWidget,SIGNAL(widgetHidden(QWidget*)),&guiContr,SLOT(unSetCentralWidget(QWidget*)));
    mDiag.setMinimumHeight(500);
    mDiag.setWindowIcon(QIcon(":/gui/icons/Music-icon.png"));
    mDiag.show();
    return a.exec();
}

