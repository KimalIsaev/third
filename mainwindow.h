#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include "abstractstrategy.h"
#include "filedirectorystrategy.h"
#include "typestrategy.h"
#include "adaptercollection.h"

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
    QWidget *buffWidget_;
    QWidget *firstEverWidget_;
    AdapterCollection adapterCollection_;
    QString currentDir_;
    AbstractStrategy *strategy_ = nullptr;
    Ui::MainWindow *ui_ = nullptr;
    QFileSystemModel *dirModel_ = nullptr;
    bool selected_ = false;

    void setDirectoryTree();
    void redraw(int);
    void redefineStrategy(int);
    void recalculateCurrentDir();
public slots:
    void redrawToTable();
    void redrawToBarChart();
    void redrawToPieChart();
    void redefineToTypeStrategy();
    void redefineToFileDirectoryStrategy();
    void changeDir(QModelIndex);
};

#endif // MAINWINDOW_H
