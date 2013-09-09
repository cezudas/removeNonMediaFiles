#include "extensionswidgetcontroller.h"
#include <QStringList>
ExtensionsWidgetController::ExtensionsWidgetController(ExtensionsWidget *eWidget, ExtItmModel *fModel, QObject *parent):
    QObject(parent)
{
    extensionWidget = eWidget;
    fileExtModel = fModel;
    audioTypes = new ExtItem(QIcon(":/gui/icons/audio-icon.png"),"Audio");
    videoTypes = new ExtItem(QIcon(":/gui/icons/video-icon.png"),"Video");
    QStringList mLabelStringList;
    mLabelStringList.append("Media files");
    fileExtModel->setHorizontalHeaderLabels(mLabelStringList);
    QStandardItem *root = fileExtModel->invisibleRootItem();
    root->appendRow(audioTypes);
    root->appendRow(videoTypes);
    QStringList aExts = QString(".mp3,.ogg,.arm,.flac,.wma").split(",");
    QStringList vExts = QString(".mkv,.avi,.mpeg4,.wmv").split(",");
    foreach(QString aExt,aExts){
        ExtItem *itm = new ExtItem(aExt);
        audioTypes->appendRow(itm);
    }
    foreach(QString vExt,vExts){
        ExtItem *itm = new ExtItem(vExt);
        videoTypes->appendRow(itm);
    }
     extensionWidget->setFilesViewModel(fileExtModel);
     extensionWidget->expandFilesView();

}
