#include "mitemmodel.h"
#include <QMessageBox>
MItemModel::MItemModel(QObject *parent) :
    QStandardItemModel(parent)
{
}
void MItemModel::OnItemChange(QStandardItem *itm){
}
