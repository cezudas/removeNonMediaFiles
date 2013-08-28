#include "mainwindow.h"
#include <QPixmap>
#include <QIcon>
#include <QFileDialog>
#include <QMessageBox>
#include <QWidget>
#include <QStatusBar>
#include <QModelIndexList>
#include <QFileSystemModel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    extWidget = new ExtensionsWidget(this);
    dirsListView = new QListView;
    dirsListView->setSelectionMode(QAbstractItemView::MultiSelection);
    dirsModel = new QStringListModel(this);
    QStringList lst;
    dirsModel->setStringList(lst);
    dirsListView ->setModel(dirsModel);
    QIcon addBIcon(":/files/icon/add-icon.png");
    QIcon rmvBIcon(":/files/icon/remove-icon.png");
    QIcon commitBIcon(":/files/icon/confirm-icon.png");
    QIcon chooseBIcon(":/files/icon/Type-icon.png");
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
    connect(addDirBtn,SIGNAL(clicked()),this,SLOT(addNewDirs()));
    connect(rmvDirBtn,SIGNAL(clicked()),this,SLOT(rmvSelDirs()));
    connect(commitBtn,SIGNAL(clicked()),this,SLOT(cleanSelDirs()));
    connect(chooseTypesBtn,SIGNAL(clicked()),this,SLOT(selFlExtns()));
    mainLayout = new QHBoxLayout;
    optionsLayout = new QVBoxLayout();
    mainLayout->addWidget(dirsListView);
    mainLayout->addLayout(optionsLayout);
    optionsLayout->addWidget(addDirBtn);
    optionsLayout->addWidget(rmvDirBtn);
    optionsLayout->addWidget(chooseTypesBtn);
    optionsLayout->addWidget(commitBtn);
    cWidget = new QWidget(this);
    cWidget->setLayout(mainLayout);
    mainWidget = new QStackedWidget;
    mainWidget->addWidget(cWidget);
    mainWidget->addWidget(extWidget);
    this->setCentralWidget(mainWidget);
    connect(extWidget,SIGNAL(hidden()),this,SLOT(setDefaultCentralWidget()));
}
void MainWindow::rmvSelDirs(){

    QModelIndexList selIndexes = dirsListView->selectionModel()->selectedIndexes();
    if (selIndexes.count() == 0)
    {
        this->statusBar()->showMessage("No directory selected",10000);
        return;
    }
    foreach(QModelIndex selIndex,selIndexes){
        dirsModel->removeRows(selIndex.row(),1);
    }
}
void MainWindow::cleanSelDirs(){
    QStringList toCleanDirs = dirsModel->stringList();
    QFileSystemModel model;
    foreach(QString dir,toCleanDirs){

        //model.setRootPath(dir);
        //
    }
}

void MainWindow::addNewDirs(){
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
        this->statusBar()->showMessage("Directory selection aborted",3000);
}
void MainWindow::selFlExtns(){
    this->mainWidget->setCurrentIndex(1);
}
void MainWindow::setDefaultCentralWidget(){
    this->mainWidget->setCurrentIndex(0);
}
