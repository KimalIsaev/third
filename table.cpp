#include "table.h"
Table::Table(){}

void Table::replace(const QList<QPair<QString,QString>> &l){
    removeRows(0, files_.size(), QModelIndex());
    size_t n = l.size();
    insertRows(0, n, QModelIndex());

    beginInsertRows(QModelIndex(), 0, n-1);
    files_ = l;
    endInsertRows();
    emit dataChanged(QAbstractItemModel::createIndex(n-1, SIZE_COLUMN),
                     QAbstractItemModel::createIndex(n-1, NAME_COLUMN),
                     {Qt::DisplayRole});
}

bool Table::removeRows(int row, int count, const QModelIndex& index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), row, row+count-1);
    for (int i=row+count-1; i >=row ; i--) {
        files_.removeAt(i);
    }
    endRemoveRows();
    return true;
}

QVariant Table::data(const QModelIndex& index, int role) const{
    if (role == Qt::DisplayRole){
        int column = index.column();
        int row = index.row();

        if (column == SIZE_COLUMN)
            return files_[row].first;
        else if (column == NAME_COLUMN)
            return files_[row].second;
        else return QVariant();
    } else return QVariant();
}

QVariant Table::headerData(int section, Qt::Orientation orientation,
                                   int role) const{
    if (role == Qt::DisplayRole){
        if (Qt::Vertical == orientation) {
            return section;
        }else{
            if (section == SIZE_COLUMN) {
                return "SIZE% ";
            }else if (section == NAME_COLUMN){
                return "NAME ";
            }else return QVariant();
        }
    } else if (role == Qt::TextAlignmentRole) {
        return Qt::AlignLeft;
    } else return QVariant();
}

int Table::rowCount(const QModelIndex&) const{
    return files_.size();
}

int Table::columnCount(const QModelIndex&) const{
    return NUMBER_OF_COLUMNS;
}
