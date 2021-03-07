#ifndef QOBSERVERTABLE_H
#define QOBSERVERTABLE_H
#include <QAbstractTableModel>
#include <QList>
#include <QPair>
#include <QString>
#include <QVariant>

//TODO переделать под этот проект.
class Table : public QAbstractTableModel
{
private:
    enum COLUMNS{
        SIZE_COLUMN,
        NAME_COLUMN,
        NUMBER_OF_COLUMNS
    };
    QList<QPair<QString, QString>> files_;
public:
    Table();
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    bool removeRows(int row, int count, const QModelIndex &index) override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    void replace(const QList<QPair<QString, QString> > &l);
};

#endif // QOBSERVERTABLE_H
