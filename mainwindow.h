#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include "abstractchart.h"
#include "piechart.h"
#include "barchart.h"
#include "abstractstrategy.h"
#include "filedirectorystrategy.h"
#include "typestrategy.h"
#include "util.h"
#include "table.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    enum STRATEGY{
        TYPE_STRATEGY,
        FILE_DIRECTORY_STRATEGY
    };
    enum CHART{
        PIE_CHART,
        BAR_CHART
    };
    QList<QPair<QString, double>> calculation_;
    QString currentDir_;
    AbstractStrategy *strategy_ = nullptr;
    AbstractChart *chart_ = nullptr;
    Ui::MainWindow *ui_ = nullptr;
    QFileSystemModel *dirModel_ = nullptr;
    Table *table_ = nullptr;
    void drawCalculation();
    void printCalculation();
    void setDirectoryTree();
    void redrawChart(unsigned char);
    void redefineStrategy(unsigned char);
    void recalculateCurrentDir();
    void setTableView();
public slots:
    void redrawToBarChart();
    void redrawToPieChart();
    void redefineToTypeStrategy();
    void redefineToFileDirectoryStrategy();
    void changeDir(QModelIndex);
};

#endif // MAINWINDOW_H
