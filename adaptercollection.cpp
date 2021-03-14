#include "adaptercollection.h"

AdapterCollection::AdapterCollection()
{
    array_ = new AbstractAdapter*[NUMBER_OF_ADAPTERS];
    array_[TABLE] = new TableAdapter;
    array_[PIE_CHART] = new PieChartAdapter;
    array_[BAR_CHART] = new BarChartAdapter;
}

bool AdapterCollection::setAdapter(int i)
{
    if (i!=currentAdapter_){
        currentAdapter_ = i;
        updateCurrentAdapter();
        return true;
    }
    return false;
}

void AdapterCollection::setData(const QList<QPair<QString, double>> &data)
{
    buffData_ = data;
    updateCurrentAdapter();
}

void AdapterCollection::updateCurrentAdapter()
{
    array_[currentAdapter_]->setData(buffData_);
}

QWidget *AdapterCollection::getWidget()
{
    return array_[currentAdapter_]->getWidget();
}

AdapterCollection::~AdapterCollection()
{
    for(int i=0; i<NUMBER_OF_ADAPTERS; i++) delete array_[i];
    delete[] array_;
}
