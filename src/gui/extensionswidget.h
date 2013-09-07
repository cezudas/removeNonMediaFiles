#ifndef EXTENSIONSWIDGET_H
#define EXTENSIONSWIDGET_H
#include <QWidget>
#include <QTreeView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QBoxLayout>
#include "../model/extitmmodel.h"
#include "../model/extitem.h"
#include "mtoolbutton.h"
class ExtensionsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ExtensionsWidget(QWidget *parent = 0);
private:
    QTreeView *filesView;
    QVBoxLayout *mainLayout;
    QHBoxLayout *btnLayout;
    MToolButton *cancelBtn,*acceptBtn;
signals:
    void widgetHidden(QWidget *);
public slots:
    void onCancelBtnClicked();
    void onAcceptBtnClicked();
    void setFilesViewModel(ExtItmModel *model);
    void expandFilesView();
};
#endif // EXTENSIONSWIDGET_H
