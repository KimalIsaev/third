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
    ~AbstractAdapter();
    QWidget *getWidget();
    virtual void setData(const QList<QPair<QString, double>>&);
};

#endif // ABSTRACTADAPTER_H
