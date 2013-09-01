#ifndef EXTENSIONSWIDGET_H
#define EXTENSIONSWIDGET_H
#include <QWidget>
#include <QTreeView>
#include "mitemmodel.h"
#include <QStandardItem>
#include <QBoxLayout>
#include "mtoolbutton.h"
class ExtensionsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ExtensionsWidget(QWidget *parent = 0);
private:
    QTreeView *filesView;
    MItemModel *model;
    QStandardItem *audioTypes;
    QStandardItem *videoTypes;
    QVBoxLayout *mainLayout;
    QHBoxLayout *btnLayout;
    MToolButton *cancelBtn,*acceptBtn;
signals:
    void widgetHidden(QWidget *);
public slots:
    void onCancelBtnClicked();
    void onAcceptBtnClicked();
};
#endif // EXTENSIONSWIDGET_H
