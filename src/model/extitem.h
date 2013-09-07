#ifndef EXTITEM_H
#define EXTITEM_H

#include <QStandardItem>
#include <QIcon>
#include <QString>
class ExtItem : public QStandardItem
{
public:
    ExtItem(const QIcon & icon, const QString & text);
    ExtItem(const QString & text);
};

#endif // EXTITEM_H
