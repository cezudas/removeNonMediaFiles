#include "extensionswidget.h"
ExtensionsWidget::ExtensionsWidget(QWidget *parent) :
    QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    filesView = new QTreeView(this);
    model = new MItemModel(this);
    audioTypes = new QStandardItem(QIcon(":/gui/Icons/audio-icon.png"),"Audio");
    videoTypes = new QStandardItem(QIcon(":/gui/Icons/video-icon.png"),"Video");
    audioTypes->setEditable(false);audioTypes->setCheckable(true);audioTypes->setCheckState(Qt::Checked);
    videoTypes->setEditable(false);videoTypes->setCheckable(true);videoTypes->setCheckState(Qt::Checked);
    QStringList mLabelStringList;
    mLabelStringList.append("Media files");
    model->setHorizontalHeaderLabels(mLabelStringList);
    model->appendRow(audioTypes);
    model->appendRow(videoTypes);
    filesView->setModel(model);
    mainLayout->addWidget(filesView);
    btnLayout = new QHBoxLayout;
    mainLayout->addLayout(btnLayout);
    QIcon cancelIcon(":/gui/Icons/Cancel-icon.png");
    QString cancelText("revert changes");
    QIcon acceptIcon(":/gui/Icons/confirm-icon.png");
    QString acceptText("apply changes");
    cancelBtn = new MToolButton(cancelIcon,cancelText);
    acceptBtn = new MToolButton(acceptIcon,acceptText);
    btnLayout->addWidget(cancelBtn);
    btnLayout->addWidget(acceptBtn);
    cancelBtn->setToolTip(cancelBtn->text());
    acceptBtn->setToolTip(acceptBtn->text());
    QStringList aExts = QString(".mp3,.ogg,.arm,.flac,.wma").split(",");
    QStringList vExts = QString(".mkv,.avi,.mpeg4,.wmv").split(",");
    foreach(QString aExt,aExts){
        QStandardItem *itm = new QStandardItem(aExt);
        itm->setCheckable(true);itm->setEditable(false);itm->setCheckState(Qt::Checked);
        audioTypes->appendRow(itm);
    }
    foreach(QString vExt,vExts){
        QStandardItem *itm = new QStandardItem(vExt);
        itm->setCheckable(true);itm->setEditable(false);itm->setCheckState(Qt::Checked);
        videoTypes->appendRow(itm);
    }
}
void ExtensionsWidget::discardChanges(){
    emit widgetHidden();
}
void ExtensionsWidget::applyChanges(){

}
