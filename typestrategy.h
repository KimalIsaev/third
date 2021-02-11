#ifndef FILESTRATEGY_H
#define FILESTRATEGY_H
#include <QString>
#include <QList>
#include <QFileInfo>
#include <QPair>
#include <QMap>
#include <QDirIterator>
#include "abstractstrategy.h"


class TypeStrategy : public AbstractStrategy
{
public:
    QList<QPair<QString, double>> calculate(const QString &);
    TypeStrategy();
private:
    unsigned long long typeMap(const QString &,
                               QMap<QString, unsigned long long> &);
    void addSizeToMap(QMap<QString, unsigned long long> &map,
                      const QString &fileType,
                      unsigned long long size);
};

#endif // FILESTRATEGY_H
