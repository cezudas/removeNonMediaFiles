#include "mainwindow.h"
MainWindow::MainWindow(QStackedWidget *cWidget,QWidget *parent) :
    QMainWindow(parent)
{
    this->setCentralWidget(cWidget);
}

