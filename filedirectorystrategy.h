#ifndef FILEDIRECTORYSTRATEGY_H
#define FILEDIRECTORYSTRATEGY_H
#include <QFileInfoList>
#include <QString>
#include <QList>
#include <QFileInfo>
#include <QPair>
#include <QDirIterator>
#include "abstractstrategy.h"

class FileDirectoryStrategy : public AbstractStrategy
{
public:
    QList<QPair<QString, double>> calculate(const QString &);
    FileDirectoryStrategy(){};
    ~FileDirectoryStrategy(){};
private:
    unsigned long long directorySize(const QFileInfo &);
    unsigned long long sizeFromFileInfo(const QFileInfo &);
    QFileInfoList dirFileInfoToEntries(const QFileInfo &dirInfo);
};

#endif // FILEDIRECTORYSTRATEGY_H
