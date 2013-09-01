#ifndef MAINWIDGETCONTROLLER_H
#define MAINWIDGETCONTROLLER_H

#include <QObject>
#include <QStringListModel>
#include "../domain/fileeraser.h"
#include "../gui/mainwidget.h"
class MainWidgetController : public QObject
{
    Q_OBJECT
public:
    explicit MainWidgetController(MainWidget *mWidget,QStringListModel *dModel,FileEraser *fEraser,QObject *parent = 0);
private:
    QStringListModel *dirModel;
    MainWidget *mainWidget;
    FileEraser *fileEraser;
signals:
public slots:
    void onDirAdded();
    void onDirsRemoved();
    void onDirsCleaned();
};

#endif // MAINWIDGETCONTROLLER_H
