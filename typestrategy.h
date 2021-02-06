#ifndef FILESTRATEGY_H
#define FILESTRATEGY_H
#include <QFileInfo>
#include "abstractstrategy.h"

class TypeStrategy : public AbstractStrategy
{
public:
    QList<FileInformation> Explore (const QString &);
    TypeStrategy();
};

#endif // FILESTRATEGY_H
