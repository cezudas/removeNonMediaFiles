#include "extitem.h"

ExtItem::ExtItem(const QIcon &icon, const QString &text):QStandardItem(icon,text){
    setCheckable(true);
    setCheckState(Qt::Checked);
}
ExtItem::ExtItem(const QString &text):QStandardItem(text){
    setCheckable(true);
    setCheckState(Qt::Checked);
}
