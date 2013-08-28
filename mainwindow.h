#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QListView>
#include <QBoxLayout>
#include <QPushButton>
#include "mtoolbutton.h"
#include <QStringListModel>
#include "extensionswidget.h"
#include <QStackedWidget>
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private:
    QListView *dirsListView;
    QStringListModel *dirsModel;
    QHBoxLayout *mainLayout;
    QVBoxLayout *optionsLayout;
    MToolButton *addDirBtn;
    MToolButton *rmvDirBtn;
    MToolButton *commitBtn;
    MToolButton *chooseTypesBtn;
    QWidget *cWidget;
    ExtensionsWidget *extWidget;
    QStackedWidget *mainWidget;
signals:


public slots:
    void addNewDirs();
    void rmvSelDirs();
    void selFlExtns();
    void cleanSelDirs();
    void setDefaultCentralWidget();
};

#endif // MainWindow_H
