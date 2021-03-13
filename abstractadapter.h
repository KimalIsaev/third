#ifndef ABSTRACTADAPTER_H
#define ABSTRACTADAPTER_H
#include <QWidget>
#include <QAbstractItemModel>

class abstractadapter
{
    QWidget *widget;
public:
    abstractadapter();
    ~abstractadapter();
    QWidget *getWidget();
    virtual void setData(const QList<QPair<QString, double>>&);
};

#endif // ABSTRACTADAPTER_H
