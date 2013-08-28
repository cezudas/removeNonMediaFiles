#ifndef MainWindow_H
#define MainWindow_H
#include <QMainWindow>
#include <QStackedWidget>
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QStackedWidget *cWidget,QWidget *parent = 0);
};
#endif // MainWindow_H
