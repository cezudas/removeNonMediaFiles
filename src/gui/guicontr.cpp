#include "guicontr.h"
#include <QStatusBar>
GuiContr::GuiContr(MainWindow *mWindow, MainWidget *mWidget, ExtensionsWidget *eWidget, QObject *parent) :
    QObject(parent)
{
    mainWindow = mWindow;
    mainWidget = mWidget;
    extensionWidget = eWidget;
    //connect(mainWidget,SIGNAL(widgetHidden(QWidget*)),this,SLOT(unSetCentralWidget(QWidget*)));
    connect(mainWidget,SIGNAL(messageSent(QString,int)),this,SLOT(showMessage(QString,int)));
//    connect(mainWidget,SIGNAL(dirAdded()),this,SLOT(clearMessage()));
//    connect(mainWidget,SIGNAL(dirsRemoved()),this,SLOT(clearMessage()));
}
void GuiContr::unSetCentralWidget(QWidget *qw){
    QStackedWidget *placeHolderWidget = (QStackedWidget *)(mainWindow->centralWidget());
    if(placeHolderWidget->currentWidget() == qw){
        placeHolderWidget->removeWidget(qw);
        placeHolderWidget->addWidget(qw);
    }
}
void GuiContr::showMessage(const QString &m,int timeOut){
    mainWindow->statusBar()->showMessage(m,timeOut);
}
