#ifndef EMPTYADAPTER_H
#define EMPTYADAPTER_H

#include "abstractadapter.h"

class EmptyAdapter : public AbstractAdapter
{
public:
    EmptyAdapter();
    void setData(const QList<QPair<QString, double>> &) override;
    ~EmptyAdapter();
};

#endif // EMPTYADAPTER_H
