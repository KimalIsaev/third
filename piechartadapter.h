#ifndef PIECHARTADAPTER_H
#define PIECHARTADAPTER_H

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

#endif // PIECHARTADAPTER_H
