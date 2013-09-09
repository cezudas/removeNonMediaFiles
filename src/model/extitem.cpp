#include "extitem.h"

ExtItem::ExtItem(const QIcon &icon, const QString &text):QStandardItem(icon,text){
}
ExtItem::ExtItem(const QString &text):QStandardItem(text){
    initialize();
}
void ExtItem::initialize(){
    setCheckable(true);
    setCheckState(Qt::Checked);
}
