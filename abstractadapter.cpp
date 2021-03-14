#include "abstractadapter.h"

AbstractAdapter::AbstractAdapter(){}

AbstractAdapter::~AbstractAdapter(){}

QWidget *AbstractAdapter::getWidget()
{
    return widget_;
}
