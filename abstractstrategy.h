#ifndef ABSTRACTSTRATEGY_H
#define ABSTRACTSTRATEGY_H
#include <QString>
#include <QList>
#include <fileinformation.h>
class AbstractStrategy
{
public:
    explicit AbstractStrategy();
    virtual ~AbstractStrategy();
    virtual QList<FileInformation> Explore (const QString &) = 0;
};

#endif // ABSTRACTSTRATEGY_H
