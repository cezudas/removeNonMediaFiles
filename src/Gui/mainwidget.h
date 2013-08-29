#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QFileSystemModel>
#include <QListView>
#include <QBoxLayout>
#include "Gui/mtoolbutton.h"
#include <QStringListModel>
#include "Gui/extensionswidget.h"
class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
private:
    QListView *dirsListView;
    QStringListModel *dirsModel;
    QHBoxLayout *mainLayout;
    QVBoxLayout *optionsLayout;
    MToolButton *addDirBtn;
    MToolButton *rmvDirBtn;
    MToolButton *commitBtn;
    MToolButton *chooseTypesBtn;
signals:
    void widgetHidden();
public slots:
    void onAddBtnClick();
    void onRmvBtnClick();
    void onCmmtBtnClick();
};

#endif // MAINWIDGET_H
