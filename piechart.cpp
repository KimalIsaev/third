#include "piechart.h"

PieChart::PieChart(){}

PieChart::~PieChart(){}

QtCharts::QChart *PieChart::listToChart(const QList<QPair<QString, double>> &list)
{
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->setTitle("Pie chart");
    QtCharts::QPieSeries *series = new QtCharts::QPieSeries(chart);
    bool firstTime = true;
    QtCharts::QPieSlice *slice;
    for (const auto &data : list) {
        slice = series->append(data.first, data.second);
        if (firstTime){
            slice->setLabelVisible();
            slice->setExploded();
        }
    }
    series->setHorizontalPosition(0.5);
    series->setVerticalPosition(0.5);
    chart->addSeries(series);
    return chart;
}
