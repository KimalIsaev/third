#ifndef TABLEADAPTER_H
#define TABLEADAPTER_H

#include "abstractadapter.h"
#include "table.h"
#include <QTableView>
#include <QHeaderView>

class TableAdapter : public AbstractAdapter
{
private:
    Table table_;
    QTableView *tableView_;
    QList<QPair<QString, QString>> doubleToString(
            const QList<QPair<QString, double>> &list,
            double k = 100.0,
            double minimal = 0.0001,
            QString units = QString("%"));

public:
    TableAdapter();
    ~TableAdapter();
    void setData(const QList<QPair<QString, double>>&);
};

#endif // TABLEADAPTER_H
