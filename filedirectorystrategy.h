#ifndef FILEDIRECTORYSTRATEGY_H
#define FILEDIRECTORYSTRATEGY_H
#include <QString>
#include <QList>
#include <QFileInfo>
#include <QPair>
#include <QDirIterator>
#include <algorithm>
#include "abstractstrategy.h"

class FileDirectoryStrategy : public AbstractStrategy
{
public:
    QList<QPair<QString, double>> calculate(const QString &);
    FileDirectoryStrategy();
private:
    unsigned long long directorySize(const QFileInfo &);
    unsigned long long sizeFromPath(const QString &);
};

#endif // FILEDIRECTORYSTRATEGY_H
