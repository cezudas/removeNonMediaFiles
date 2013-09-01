#include "mainwidgetcontroller.h"
#include <QFileDialog>
MainWidgetController::MainWidgetController(MainWidget *mWidget, QStringListModel *dModel, FileEraser *fEraser, QObject *parent) :
    QObject(parent)
{
    mainWidget = mWidget;
    dirModel = dModel;
    fileEraser = fEraser;
    connect(mainWidget,SIGNAL(dirAdded()),this,SLOT(onDirAdded()));
    connect(mainWidget,SIGNAL(dirsRemoved()),this,SLOT(onDirsRemoved()));
    connect(mainWidget,SIGNAL(dirsCleaned()),this,SLOT(onDirsCleaned()));

}
void MainWidgetController::onDirAdded(){
    QString selDir = QFileDialog::getExistingDirectory(mainWidget,"","",QFileDialog::ShowDirsOnly);
    if(!selDir.isNull()){
        QStringList currentList = dirModel->stringList();
        if(currentList.contains(selDir))
        {
            mainWidget->informUser("One directory can't be selected more than once",5000);
            return;
        }
        QStringList subDirs;
        foreach(QString dir,currentList){
            if(selDir.contains(dir) == true)
            {
                QString statusText = QString("The last selected directory: %1 is a subdirectory of the previously selected %2").arg(selDir).arg(dir);
                mainWidget->informUser(statusText,5000);
                return;
            }
            if(dir.contains(selDir))
                subDirs.append(dir);
        }
        if(subDirs.count() > 0)
        {
            QString statusText = QString("The last selected directory: %1 is the parent folder of the folowing previously selected dirs: ").arg(selDir);
            statusText.append(subDirs.join(","));
            mainWidget->informUser(statusText,5000);
            return;
        }
        currentList.append(selDir);
        dirModel->setStringList(currentList);
    }
    else
        mainWidget->informUser("Directory selection aborted",3000);
}
void MainWidgetController::onDirsRemoved(){
    QModelIndexList selIndexes = mainWidget->selectedDirsIndexes();
    if (selIndexes.count() == 0)
    {
        mainWidget->informUser("No directory selected",10000);
        return;
    }
    foreach(QModelIndex selIndex,selIndexes){
        dirModel->removeRows(selIndex.row(),1);
    }
}
void MainWidgetController::onDirsCleaned(){

}

