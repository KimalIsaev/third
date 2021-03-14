#ifndef ADAPTERCOLLECTION_H
#define ADAPTERCOLLECTION_H

#include <QWidget>
#include "abstractadapter.h"
#include "tableadapter.h"
#include "piechartadapter.h"
#include "barchartadapter.h"



class AdapterCollection
{
    AbstractAdapter **array_;
    int currentAdapter_;
    QList<QPair<QString, double>> buffData_;
    void updateCurrentAdapter();
public:
    AdapterCollection();
    ~AdapterCollection();
    void setAdapter(int);
    void setData(const QList<QPair<QString, double>>& data);
    QWidget *getWidget();
    enum ADAPTER_NUMBER{
        TABLE,
        BAR_CHART,
        PIE_CHART,
        NUMBER_OF_ADAPTERS
    };
};

#endif // ADAPTERCOLLECTION_H
