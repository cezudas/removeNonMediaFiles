#ifndef FILEERASER_H
#define FILEERASER_H
#include <QStringListModel>
class FileEraser
{
public:
    FileEraser(QStringListModel *,QStringListModel *);
private:
    QStringListModel *dirModel,*fileExtModel;
};
#endif // FILEERASER_H
