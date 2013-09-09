#ifndef FILEERASER_H
#define FILEERASER_H
#include <QStringListModel>
#include "../model/extitmmodel.h"
#include <QList>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QStringList>
class FileEraser
{
public:
    FileEraser(QStringListModel *,QStandardItemModel *);
private:
    QStringListModel *dirModel;
    QStandardItemModel *fileExtModel;
    QStringList getCheckedExts();
    bool isMediaFile(QString,QStringList);
public:
    void erase();
};
#endif // FILEERASER_H
