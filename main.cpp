#include <QCoreApplication>
#include <QString>
#include <QList>
#include <QPair>
#include <iostream>
#include "abstractstrategy.h"
#include "filedirectorystrategy.h"

QList<QPair<QString, QString>> doubleToString(
        const QList<QPair<QString, double>> &list, double k,
        double minimal, QString units)
{
    QString lessThanMinimal = QString("<")
                              + QString::number(k*minimal)
                              + units;
    QList<QPair<QString, QString>> result;
    bool isSmallerThenMinimal;
    for(const auto &p : list){
        isSmallerThenMinimal = p.second < minimal;
        if (isSmallerThenMinimal){
            result.append(qMakePair(p.first,
                                    lessThanMinimal));
        } else {
            result.append(qMakePair(p.first,
                                    QString::number(k*p.second)+units));
        }
    }
    return result;
}


QList<QString> listToTable(const QList<QPair<QString, QString>> &list,
                           const QString &nameOfFirstColumn,
                           const QString &nameOfSecondColumn,
                           unsigned char numberOfTabsBetweenColumns)
{
    QString tabString;
    for (unsigned char i=0; i<numberOfTabsBetweenColumns; i++)
        tabString +=QString("\t");

    QList<QString> result;
    result.append(nameOfFirstColumn + tabString + nameOfSecondColumn);
    for(const auto &p : list)
            result.append(p.first + tabString + p.second);
    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    AbstractStrategy *strategy = new FileDirectoryStrategy;
    QList<QString> output =
        listToTable(doubleToString(
                        strategy->calculate("E:\\p\\Kema\\third"),
                                   100.0, 0.001, QString("%")),
                    QString("NAME"), QString("RELATIVE SIZE"), 3);
    for(const auto &line : output)
        std::cout << line.toStdString() << std::endl;
    return a.exec();
}
