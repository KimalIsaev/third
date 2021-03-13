#include "abstractadapter.h"

abstractadapter::abstractadapter(){}

abstractadapter::~abstractadapter()
{
    delete widget;
}

QWidget *abstractadapter::getWidget()
{
    return widget;
}
