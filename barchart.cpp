#include "barchart.h"

BarChart::BarChart(){}

BarChart::~BarChart(){}

QtCharts::QChart *BarChart::listToChart(const QList<QPair<QString, double>> &list)
{
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->setTitle("Bar chart");
    QtCharts::QBarSeries *series = new QtCharts::QBarSeries(chart);
    QtCharts::QBarSet *set;
    for (const auto &data : list){
        set = new QtCharts::QBarSet(data.first);
        *set << data.second;
        series->append(set);
    }
    chart->addSeries(series);
    chart->createDefaultAxes();
    return chart;
}
