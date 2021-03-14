#include "tableadapter.h"

TableAdapter::TableAdapter()
{
    widget_ = tableView_ = new QTableView();
    tableView_->verticalHeader()->setVisible(false);
    tableView_->setModel(&table_);
    tableView_->setColumnWidth(0,60);
    tableView_->setColumnWidth(1,600);
}

void TableAdapter::setData(const QList<QPair<QString, double> > &data)
{
    table_.replace(doubleToString(data));
}

QList<QPair<QString, QString>> TableAdapter::doubleToString(
        const QList<QPair<QString, double>> &list, double k,
        double minimal, QString units)
{
    QString lessThanMinimal = QString::number(k*minimal)
                              + units + QString(">");
    QList<QPair<QString, QString>> result;
    bool isSmallerThenMinimal, isZero;
    for(const auto &p : list){
        isSmallerThenMinimal = p.second < minimal;
        isZero = p.second == 0.0;
        if (isSmallerThenMinimal and !isZero){
            result.append(qMakePair(lessThanMinimal,
                                    p.first));
        } else {
            result.append(qMakePair(QString::number(k*p.second, 'f', 2)
                                    + units + QString(" "),
                                     p.first));
        }
    }
    return result;
}


