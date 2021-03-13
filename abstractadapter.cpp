#include "abstractadapter.h"

AbstractAdapter::AbstractAdapter(){}

AbstractAdapter::~AbstractAdapter()
{
    delete widget_;
}

QWidget *AbstractAdapter::getWidget()
{
    return widget_;
}
