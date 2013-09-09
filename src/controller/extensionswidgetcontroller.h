#ifndef EXTENSIONSWIDGETCONTROLLER_H
#define EXTENSIONSWIDGETCONTROLLER_H

#include <QObject>
#include "../gui/extensionswidget.h"
#include <QStringListModel>
#include "../model/extitmmodel.h"
#include "../model/extitem.h"
#include <QStandardItem>
class ExtensionsWidgetController : public QObject
{
    Q_OBJECT
public:
    explicit ExtensionsWidgetController(ExtensionsWidget *eWidget,ExtItmModel *fModel,QObject *parent = 0);
private:
    ExtensionsWidget *extensionWidget;
    ExtItmModel *fileExtModel;
    ExtItem *audioTypes;
    ExtItem *videoTypes;
signals:
public slots:   

};

#endif // EXTENSIONSWIDGETCONTROLLER_H
