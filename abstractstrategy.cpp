#include "abstractstrategy.h"


unsigned long long AbstractStrategy::symLinkSize(const QFileInfo &fileInfo)
{
    QFile fileOpen(fileInfo.absoluteFilePath());
    fileOpen.open(QIODevice::ReadOnly);
    unsigned long long fileSize = fileOpen.size();
    fileOpen.close();
    return fileSize;
}
