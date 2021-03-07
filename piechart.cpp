#include "piechart.h"

PieChart::PieChart(){}

PieChart::~PieChart(){}

QChart *PieChart::listToChart(const QList<QPair<QString, double>> &list)
{
    QChart *chart = new QChart();
    chart->setTitle("Pie chart");
    QPieSeries *series = new QPieSeries(chart);
    bool firstTime = true;
    QPieSlice *slice;
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
