#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include <QFileSystemModel>
#include <QListView>
#include <QBoxLayout>
#include "mtoolbutton.h"
#include <QStringListModel>
#include "extensionswidget.h"
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
public:
    QModelIndexList selectedDirsIndexes();
signals:
    void widgetHidden(QWidget *);
    void dirAdded();
    void dirsRemoved();
    void dirsCleaned();
    void messageSent(const QString &,int);
private slots:
    void onChTyBtn();
    void onAddDirBtnClicked();
    void onRmvDirBtnClicked();
    void onCommitBtnClicked();
public slots:
    void informUser(const QString &,int timeOut = 0);
//    void setDirModel()
};
#endif // MAINWIDGET_H
