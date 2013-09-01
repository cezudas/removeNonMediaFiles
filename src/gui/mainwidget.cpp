#include "mainwidget.h"
#include <QPixmap>
#include <QIcon>
#include <QStatusBar>
#include <QModelIndexList>
#include <QFileSystemModel>
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    QIcon addBIcon(":/gui/icons/add-icon.png");
    QIcon rmvBIcon(":/gui/icons/remove-icon.png");
    QIcon commitBIcon(":/gui/icons/confirm-icon.png");
    QIcon chooseBIcon(":/gui/icons/Type-icon.png");

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
    connect(chooseTypesBtn,SIGNAL(clicked()),this,SLOT(onChTyBtn()));
    connect(addDirBtn,SIGNAL(clicked()),this,SLOT(onAddDirBtnClicked()));
    connect(rmvDirBtn,SIGNAL(clicked()),this,SLOT(onRmvDirBtnClicked()));
    connect(commitBtn,SIGNAL(clicked()),this,SLOT(onCommitBtnClicked()));
}
QModelIndexList MainWidget::selectedDirsIndexes(){
    return dirsListView->selectionModel()->selectedIndexes();
}

void MainWidget::onChTyBtn(){
    emit widgetHidden(this);
}
void MainWidget::onAddDirBtnClicked(){
    emit dirAdded();
}
void MainWidget::onRmvDirBtnClicked(){
    emit dirsRemoved();
}
void MainWidget::onCommitBtnClicked(){
    emit dirsCleaned();
}
void MainWidget::informUser(const QString &m,int timeOut){
    emit messageSent(m,timeOut);
}

