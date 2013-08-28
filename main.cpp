#include <QtGui/QApplication>
#include "mainwindow.h"
int main(int argc, char **args){
    QApplication a(argc,args);
    MainWindow mDiag;
    mDiag.setMinimumHeight(500);
    mDiag.setWindowIcon(QIcon(":/files/icon/Music-icon.png"));
    mDiag.show();
    return a.exec();
}
