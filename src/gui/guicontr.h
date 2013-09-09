#ifndef GUICONTR_H
#define GUICONTR_H

#include <QObject>
#include "mainwidget.h"
#include "extensionswidget.h"
#include "mainwindow.h"
#include <QStackedWidget>
//#include <QString>
class GuiContr : public QObject
{
    Q_OBJECT
public:
    explicit GuiContr(MainWindow *mWindow,MainWidget *mWidget,ExtensionsWidget *eWidget,QObject *parent = 0);
private:
    MainWindow *mainWindow;
    MainWidget *mainWidget;
    ExtensionsWidget *extensionWidget;
signals:
    void centralWidgetChanged(QWidget *);
public slots:
    void unSetCentralWidget(QWidget *);

private slots:
    void showMessage(const QString &,int);
};

#endif // GUICONTR_H
