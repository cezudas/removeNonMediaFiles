#ifndef EXTENSIONSWIDGETCONTROLLER_H
#define EXTENSIONSWIDGETCONTROLLER_H

#include <QObject>
#include "../gui/extensionswidget.h"
#include <QStringListModel>
class ExtensionsWidgetController : public QObject
{
    Q_OBJECT
public:
    explicit ExtensionsWidgetController(ExtensionsWidget *eWidget,QStringListModel *fModel,QObject *parent = 0);
private:
    ExtensionsWidget *extensionWidget;
    QStringListModel *fileExtModel;
signals:
public slots:   
};

#endif // EXTENSIONSWIDGETCONTROLLER_H
