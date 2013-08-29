#include <QtGui/QApplication>
#include "Gui/mainwindow.h"
#include "Gui/mainwidget.h"
#include "Gui/extensionswidget.h"
#include <QStackedWidget>
int main(int argc, char **args){
    QApplication a(argc,args);
    MainWidget *mainWidget = new MainWidget;
    ExtensionsWidget *extensionWidget = new ExtensionsWidget;
    QStackedWidget *placeHolderWidget = new QStackedWidget;
    placeHolderWidget->addWidget(mainWidget);
    placeHolderWidget->addWidget(extensionWidget);
    MainWindow mDiag(placeHolderWidget);
    mDiag.setMinimumHeight(500);
    mDiag.setWindowIcon(QIcon(":/icons/Music-icon.png"));
    mDiag.show();
    return a.exec();
}

