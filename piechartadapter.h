#ifndef PIECHARTADAPTER_H
#define PIECHARTADAPTER_H

#include "abstractadapter.h"
#include <QChartView>
#include <QChart>
#include <QPieSeries>

class PieChartAdapter : public AbstractAdapter
{
    QtCharts::QChart *chart_;
public:
    PieChartAdapter();
    ~PieChartAdapter();
    void setData(const QList<QPair<QString, double>>&);
};

#endif // PIECHARTADAPTER_H
