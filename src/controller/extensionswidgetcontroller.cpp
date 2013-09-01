#include "extensionswidgetcontroller.h"
ExtensionsWidgetController::ExtensionsWidgetController(ExtensionsWidget *eWidget, QStringListModel *fModel, QObject *parent):
    QObject(parent)
{
    extensionWidget = eWidget;
    fileExtModel = fModel;
}
