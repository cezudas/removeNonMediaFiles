#include "fileeraser.h"
#include <QStringList>
#include <QFile>
#include <QDir>
FileEraser::FileEraser(QStringListModel *d, QStandardItemModel *f){
    dirModel = d;
    fileExtModel = f;
}
void FileEraser::erase(){
    QStringList ckExts = getCheckedExts();
    QStringList selDirs = dirModel->stringList();
    foreach(QString dirPath,selDirs)
    {
        QDir dir(dirPath);
        dir.setFilter(QDir::Files | QDir::NoSymLinks | QDir::Dirs);
        QFileInfoList list = dir.entryInfoList();
        for (int i = 0; i < list.size(); ++i) {
            QFileInfo fileInfo = list.at(i);
            if(fileInfo.isFile()){
                QString bName = fileInfo.absoluteFilePath();
                if(isMediaFile(bName,ckExts))
                    dir.remove(bName);
            }
        }
    }
}
bool FileEraser::isMediaFile(QString filePath, QStringList extList){
    foreach(QString ext,extList)
        if(filePath.endsWith(ext,Qt::CaseInsensitive))
            return true;
    return false;
}

QStringList FileEraser::getCheckedExts(){
    QStringList checkedExts;
    int noRows = fileExtModel->rowCount();
     for(int row = 0; row < noRows; ++row){
        QStandardItem * itm = fileExtModel->item(row);
        int itmNoRows = itm->rowCount();
        for(int itmrow = 0; itmrow < itmNoRows; ++ itmrow){
            QStandardItem *subitm = itm->child(itmrow);
            if(subitm->checkState() == Qt::Checked)
                checkedExts.append(subitm->text());
        }
     }
     return checkedExts;
}
