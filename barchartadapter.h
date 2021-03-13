#ifndef BARCHARTADAPTER_H
#define BARCHARTADAPTER_H

#include "abstractadapter.h"
#include <QChartView>
#include <QChart>
#include <QBarSeries>
#include <QBarSet>

class BarChart : public AbstractAdapter
{
    QtCharts::QChart *chart_;
public:
    BarChart();
    ~BarChart();
    void setData(const QList<QPair<QString, double>>&);

};

#endif // BARCHARTADAPTER_H
