#ifndef UTIL_H
#define UTIL_H
#include <QStringList>
#include <QString>
#include <QList>
#include <QPair>

namespace util {
    QList<QPair<QString, QString>> doubleToString(
            const QList<QPair<QString, double>> &list,
            double k = 100.0,
            double minimal = 0.0001,
            QString units = QString("%"));
}

#endif // UTIL_H
