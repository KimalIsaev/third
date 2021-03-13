#ifndef PIECHART_H
#define PIECHART_H

#include "abstractchart.h"
#include <QPieSeries>

class PieChart : public AbstractChart
{
public:
    PieChart();
    ~PieChart();
    QtCharts::QChart *listToChart(const QList<QPair<QString, double>> &);
};

#endif // PIECHART_H
