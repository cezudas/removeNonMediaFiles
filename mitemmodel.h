#ifndef MITEMMODEL_H
#define MITEMMODEL_H

#include <QStandardItemModel>

class MItemModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit MItemModel(QObject *parent = 0);
    
signals:
    
public slots:
    void OnItemChange(QStandardItem*);
};

#endif // MITEMMODEL_H
