#include "guicontr.h"
#include <QStatusBar>
GuiContr::GuiContr(MainWindow *mWindow, MainWidget *mWidget, ExtensionsWidget *eWidget, QObject *parent) :
    QObject(parent)
{
    mainWindow = mWindow;
    mainWidget = mWidget;
    extensionWidget = eWidget;
    connect(mainWidget,SIGNAL(messageSent(QString,int)),this,SLOT(showMessage(QString,int)));

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
