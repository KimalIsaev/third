#ifndef PIECHART_H
#define PIECHART_H

#include "abstractadapter.h"
#include <QChartView>
#include <QChart>
#include <QPieSeries>

class PieChart : public AbstractAdapter
{
    QtCharts::QChart *chart_;
public:
    PieChart();
    ~PieChart();
    void setData(const QList<QPair<QString, double>>&);
};

#endif // PIECHART_H
