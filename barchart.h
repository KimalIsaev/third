#ifndef BARCHART_H
#define BARCHART_H

#include "abstractadapter.h"
#include <QChartView>
#include <QChart>
#include <QBarSeries>
#include <QBarSet>

class BarChart : public AbstractAdapter
{
    QtCharts::QChart chart;
    QtCharts::QChart *listToChart(const QList<QPair<QString, double>> &);
public:
    BarChart();
    ~BarChart();
    void setData(const QList<QPair<QString, double>>&);

};

#endif // BARCHART_H
