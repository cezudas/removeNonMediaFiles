#include "extensionswidget.h"
ExtensionsWidget::ExtensionsWidget(QWidget *parent) :
    QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    filesView = new QTreeView(this);
    filesView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mainLayout->addWidget(filesView);
    btnLayout = new QHBoxLayout;
    mainLayout->addLayout(btnLayout);
    QIcon backIcon(":/gui/icons/back-icon.png");
    QString backText("done");
    backBtn = new MToolButton(backIcon,backText,QSize(56,56));
    btnLayout->addWidget(backBtn);
    backBtn->setToolTip(backBtn->text());
    connect(backBtn,SIGNAL(clicked()),this,SLOT(onBackBtnClicked()));
}
void ExtensionsWidget::onBackBtnClicked(){
    emit widgetHidden(this);
}
void ExtensionsWidget::setFilesViewModel(ExtItmModel *model){
    filesView->setModel(model);
}
void ExtensionsWidget::expandFilesView(){
    filesView->expandAll();
}
