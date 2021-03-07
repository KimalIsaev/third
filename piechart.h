#ifndef PIECHART_H
#define PIECHART_H

#include "abstractchart.h"

class PieChart : public AbstractChart
{
public:
    PieChart();
    ~PieChart();
    QChart *listToChart(const QList<QPair<QString, double>> &);
};

#endif // PIECHART_H
