#include "barchart.h"

BarChart::BarChart()
{
    widget_ = new QtCharts::QChartView(&chart);
}

BarChart::~BarChart(){}

void BarChart::setData(const QList<QPair<QString, double>>& data)
{
    chart.removeAllSeries();
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries(&chart);
    QtCharts::QBarSet *set;
    for (const auto &d : data){
        set = new QtCharts::QBarSet(d.first);
        *set << d.second;
        series->append(set);
    }
    chart.addSeries(series);
    chart.createDefaultAxes();
}

