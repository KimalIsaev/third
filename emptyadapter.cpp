#include "emptyadapter.h"

EmptyAdapter::EmptyAdapter()
{
    widget_ = new QWidget();
}

void EmptyAdapter::setData(const QList<QPair<QString, double> > &data){}

EmptyAdapter::~EmptyAdapter(){}
