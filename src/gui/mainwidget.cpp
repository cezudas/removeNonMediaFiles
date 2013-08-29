#include "mainwidget.h"
#include <QPixmap>
#include <QIcon>
#include <QFileDialog>
#include <QStatusBar>
#include <QModelIndexList>
#include <QFileSystemModel>
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    QIcon addBIcon(":/gui/Icons/add-icon.png");
    QIcon rmvBIcon(":/gui/Icons/remove-icon.png");
    QIcon commitBIcon(":/gui/Icons/confirm-icon.png");
    QIcon chooseBIcon(":/gui/Icons/Type-icon.png");

    QString addBText("Add directories");
    QString rmvBText("Remove selected directories");
    QString commitBText("Physically remove non-media files from selected dirs");
    QString chooseBText("Choose the extensions for your media files");

    addDirBtn = new MToolButton(addBIcon,addBText);
    rmvDirBtn = new MToolButton(rmvBIcon,rmvBText);
    commitBtn = new MToolButton(commitBIcon,commitBText);
    chooseTypesBtn = new MToolButton(chooseBIcon,chooseBText);

    addDirBtn -> setToolTip(addDirBtn->text());
    rmvDirBtn -> setToolTip(rmvDirBtn->text());
    commitBtn -> setToolTip(commitBtn->text());
    chooseTypesBtn -> setToolTip(chooseTypesBtn->text());

    dirsListView = new QListView;
    dirsListView->setSelectionMode(QAbstractItemView::MultiSelection);
    dirsModel = new QStringListModel(this);
    QStringList lst;
    dirsModel->setStringList(lst);
    dirsListView ->setModel(dirsModel);
    mainLayout = new QHBoxLayout;
    optionsLayout = new QVBoxLayout;
    this->setLayout(mainLayout);
    mainLayout->addWidget(dirsListView);
    mainLayout->addLayout(optionsLayout);
    optionsLayout->addWidget(addDirBtn);
    optionsLayout->addWidget(rmvDirBtn);
    optionsLayout->addWidget(chooseTypesBtn);
    optionsLayout->addWidget(commitBtn);



}
void MainWidget::onRmvBtnClick(){
/*
    QModelIndexList selIndexes = dirsListView->selectionModel()->selectedIndexes();
    if (selIndexes.count() == 0)
    {
        this->statusBar()->showMessage("No directory selected",10000);
        return;
    }
    foreach(QModelIndex selIndex,selIndexes){
        dirsModel->removeRows(selIndex.row(),1);
    }*/
}
void MainWidget::onCmmtBtnClick(){
}

void MainWidget::onAddBtnClick(){
    /*
    this->statusBar()->clearMessage();
    QString selDir = QFileDialog::getExistingDirectory(this,"","",QFileDialog::ShowDirsOnly);
    if(!selDir.isNull()){
        QStringList currentList = dirsModel->stringList();
        if(currentList.contains(selDir))
        {
            this->statusBar()->showMessage("One directory can't be selected more than once",10000);
            return;
        }
        QStringList subDirs;
        foreach(QString dir,currentList){
            if(selDir.contains(dir) == true)
            {
                QString statusText = QString("The last selected directory: %1 is a subdirectory of the previously selected %2").arg(selDir).arg(dir);
                this->statusBar()->showMessage(statusText,10000);
                return;
            }
            if(dir.contains(selDir))
                subDirs.append(dir);
        }
        if(subDirs.count() > 0)
        {
            QString statusText = QString("The last selected directory: %1 is the parent folder of the folowing previously selected dirs: ").arg(selDir);
            statusText.append(subDirs.join(","));
            this->statusBar()->showMessage(statusText);
            return;
        }
        currentList.append(selDir);
        dirsModel->setStringList(currentList);
    }
    else
        this->statusBar()->showMessage("Directory selection aborted",3000);*/
}


