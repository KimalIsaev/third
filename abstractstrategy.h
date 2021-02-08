#ifndef ABSTRACTSTRATEGY_H
#define ABSTRACTSTRATEGY_H
#include <QString>
#include <QList>
#include <QFileInfo>
#include <QPair>
class AbstractStrategy
{
protected:
    unsigned long long symLinkSize(const QFileInfo &);
public:
    AbstractStrategy();
    virtual ~AbstractStrategy();
    virtual QList<QPair<QString, double>> calculate (const QString &) = 0;
};

#endif // ABSTRACTSTRATEGY_H
