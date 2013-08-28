#ifndef MTOOLBUTTON_H
#define MTOOLBUTTON_H

#include <QToolButton>

class MToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit MToolButton(const QIcon& icon,const QString &txt,QSize size = QSize(28,28),QWidget *parent = 0);
private:
protected:

signals:

    void hovered(MToolButton &);
    void unhovered(MToolButton &);
public slots:
    
};

#endif // MTOOLBUTTON_H
