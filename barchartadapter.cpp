#include "barchartadapter.h"

BarChartAdapter::BarChartAdapter()
{
    chart_ = new QtCharts::QChart();
    widget_ = new QtCharts::QChartView(chart_);
}

BarChartAdapter::~BarChartAdapter(){}

void BarChartAdapter::setData(const QList<QPair<QString, double>>& data)
{
    chart_->removeAllSeries();
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries(chart_);
    QtCharts::QBarSet *set;
    for (const auto &d : data){
        set = new QtCharts::QBarSet(d.first);
        *set << d.second;
        series->append(set);
    }
    chart_->addSeries(series);
    chart_->createDefaultAxes();
}

