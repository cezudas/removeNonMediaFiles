#include "mtoolbutton.h"
MToolButton::MToolButton(const QIcon& icon, const QString &txt, QSize size, QWidget *parent):QToolButton(parent){
    setIcon(icon);
    setText(txt);
    setIconSize(size);
}
