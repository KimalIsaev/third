#include "barchartadapter.h"

BarChart::BarChart()
{
    chart_ = new QtCharts::QChart();
    widget_ = new QtCharts::QChartView(chart_);
}

BarChart::~BarChart(){}

void BarChart::setData(const QList<QPair<QString, double>>& data)
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

