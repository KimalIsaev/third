#ifndef ABSTRACTADAPTER_H
#define ABSTRACTADAPTER_H
#include <QWidget>
#include <QAbstractItemModel>

class AbstractAdapter
{
protected:
    QWidget *widget_;
public:
    AbstractAdapter();
    virtual ~AbstractAdapter();
    QWidget *getWidget();
    virtual void setData(const QList<QPair<QString, double>>&)=0;
};

#endif // ABSTRACTADAPTER_H
