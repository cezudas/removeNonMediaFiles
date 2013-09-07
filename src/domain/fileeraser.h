#ifndef FILEERASER_H
#define FILEERASER_H
#include <QStringListModel>
#include "../model/extitmmodel.h"
class FileEraser
{
public:
    FileEraser(QStringListModel *,ExtItmModel *);
private:
    QStringListModel *dirModel;
    ExtItmModel *fileExtModel;
};
#endif // FILEERASER_H
