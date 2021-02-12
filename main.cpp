#include <QCoreApplication>
#include <QStringList>
#include <QString>
#include <QList>
#include <QPair>
#include <iostream>
#include "abstractstrategy.h"
#include "filedirectorystrategy.h"
#include "typestrategy.h"

QList<QPair<QString, QString>> doubleToString(
        const QList<QPair<QString, double>> &list, double k,
        double minimal, QString units)
{
    QString lessThanMinimal = QString::number(k*minimal)
                              + units + QString(">");
    QList<QPair<QString, QString>> result;
    bool isSmallerThenMinimal;
    for(const auto &p : list){
        isSmallerThenMinimal = p.second < minimal;
        if (isSmallerThenMinimal){
            result.append(qMakePair(p.first,
                                    lessThanMinimal));
        } else {
            result.append(qMakePair(p.first,
                                    QString::number(k*p.second, 'f', 2)
                                    + units + QString(" ")));
        }
    }
    return result;
}


QStringList listToTable(const QList<QPair<QString, QString>> &list,
                           const QString &nameOfFirstColumn,
                           const QString &nameOfSecondColumn)
{
    unsigned char n = nameOfFirstColumn.size();
    QString space = " ";
    QStringList result;
    result.append(nameOfFirstColumn + space + nameOfSecondColumn);
    for(const auto &p : list)
            result.append(space.repeated(n - p.second.size())
                          + p.second + space + p.first);
    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AbstractStrategy *strategy = new FileDirectoryStrategy;
    QStringList output =
        listToTable(doubleToString(
                        strategy->calculate("E:\\p\\Kema\\third"),
                                   100.0, 0.0001, QString("%")),
                    QString("RELATIVE SIZE"), QString("NAME"));
    for(const auto &line : output)
        std::cout << line.toStdString() << std::endl;
    std::cout << std::endl;
    strategy = new TypeStrategy;
    output =
        listToTable(doubleToString(
                        strategy->calculate("E:\\p\\Kema\\third"),
                                   100.0, 0.0001, QString("%")),
                    QString("RELATIVE SIZE"), QString("NAME"));
    for(const auto &line : output)
        std::cout << line.toStdString() << std::endl;
    return a.exec();
}
