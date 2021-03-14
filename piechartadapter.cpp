#include "piechartadapter.h"

PieChartAdapter::PieChartAdapter()
{
    chart_ = new QtCharts::QChart();
    widget_ = new QtCharts::QChartView(chart_);
}

PieChartAdapter::~PieChartAdapter()
{
    delete widget_;
}

void PieChartAdapter::setData(const QList<QPair<QString, double>> &data)
{
    QtCharts::QPieSeries *series = new QtCharts::QPieSeries(chart_);
    bool firstTime = true;
    QtCharts::QPieSlice *slice;
    for (const auto &data : data) {
        slice = series->append(data.first, data.second);
        if (firstTime){
            slice->setLabelVisible();
            slice->setExploded();
        }
    }
    series->setHorizontalPosition(0.5);
    series->setVerticalPosition(0.5);
    chart_->addSeries(series);
}
