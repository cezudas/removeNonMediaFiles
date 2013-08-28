#include "mitemmodel.h"
#include <QMessageBox>
MItemModel::MItemModel(QObject *parent) :
    QStandardItemModel(parent)
{
}
void MItemModel::OnItemChange(QStandardItem *itm){
    int rcount = this->rowCount();
    //for(int i =0 ; i < rcount; i++)

    this->children();
   // QModelIndex idx = this->indexFromItem(itm);

}
