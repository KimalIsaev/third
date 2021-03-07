#include "barchart.h"

BarChart::BarChart(){}

BarChart::~BarChart(){}

QChart *BarChart::listToChart(const QList<QPair<QString, double>> &list)
{
    QChart *chart = new QChart();
    chart->setTitle("Bar chart");
    QBarSeries *series = new QBarSeries(chart);
    QBarSet *set;
    for (const auto &data : list){
        set = new QBarSet(data.first);
        *set << data.second;
        series->append(set);
    }
    chart->addSeries(series);
    chart->createDefaultAxes();
    return chart;
}
