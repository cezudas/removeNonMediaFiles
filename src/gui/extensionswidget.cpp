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
    QIcon cancelIcon(":/gui/icons/Cancel-icon.png");
    QString cancelText("revert changes");
    QIcon acceptIcon(":/gui/icons/confirm-icon.png");
    QString acceptText("apply changes");
    cancelBtn = new MToolButton(cancelIcon,cancelText);
    acceptBtn = new MToolButton(acceptIcon,acceptText);
    btnLayout->addWidget(cancelBtn);
    btnLayout->addWidget(acceptBtn);
    cancelBtn->setToolTip(cancelBtn->text());
    acceptBtn->setToolTip(acceptBtn->text());
    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(onCancelBtnClicked()));
    connect(acceptBtn,SIGNAL(clicked()),this,SLOT(onAcceptBtnClicked()));
}
void ExtensionsWidget::onCancelBtnClicked(){
    emit widgetHidden(this);
}
void ExtensionsWidget::onAcceptBtnClicked(){
    emit widgetHidden(this);
}
void ExtensionsWidget::setFilesViewModel(ExtItmModel *model){
    filesView->setModel(model);
}
void ExtensionsWidget::expandFilesView(){
    filesView->expandAll();
}
