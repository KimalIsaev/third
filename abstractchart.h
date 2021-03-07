#ifndef ABSTRACTCHART_H
#define ABSTRACTCHART_H

#include <QString>
#include <QList>
#include <QPair>
#include "ui_mainwindow.h"

class AbstractChart
{
public:
    AbstractChart();
    virtual ~AbstractChart();
    virtual QChart *listToChart(const QList<QPair<QString, double>> &) = 0;
};

#endif // ABSTRACTCHART_H
