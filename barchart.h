#ifndef BARCHART_H
#define BARCHART_H

#include "abstractchart.h"

class BarChart : public AbstractChart
{
public:
    BarChart();
    ~BarChart();
    QChart *listToChart(const QList<QPair<QString, double>> &);
};

#endif // BARCHART_H
