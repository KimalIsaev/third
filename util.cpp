#include "util.h"

QList<QPair<QString, QString>> util::doubleToString(
        const QList<QPair<QString, double>> &list, double k,
        double minimal, QString units)
{
    QString lessThanMinimal = QString::number(k*minimal)
                              + units + QString(">");
    QList<QPair<QString, QString>> result;
    bool isSmallerThenMinimal, isZero;
    for(const auto &p : list){
        isSmallerThenMinimal = p.second < minimal;
        isZero = p.second == 0.0;
        if (isSmallerThenMinimal and !isZero){
            result.append(qMakePair(lessThanMinimal,
                                    p.first));
        } else {
            result.append(qMakePair(QString::number(k*p.second, 'f', 2)
                                    + units + QString(" "),
                                     p.first));
        }
    }
    return result;
}


