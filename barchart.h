#ifndef BARCHART_H
#define BARCHART_H

#include "abstractchart.h"
#include <QBarSeries>
#include <QBarSet>

class BarChart : public AbstractChart
{
public:
    BarChart();
    ~BarChart();
    QtCharts::QChart *listToChart(const QList<QPair<QString, double>> &);
};

#endif // BARCHART_H
