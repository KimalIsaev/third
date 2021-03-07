#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
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
    QList<QPair<QString, double>> calculation_;
    QString currentDir_;
    AbstractStrategy *strategy_ = nullptr;
    Ui::MainWindow *ui_ = nullptr;
    QFileSystemModel *dirModel_ = nullptr;
    Table *table_ = nullptr;
    QString defaultDir = QString("..");
    void printCalculation();
    void setDirectoryTree();
    void redefineStrategy(unsigned char);
    void recalculateCurrentDir();
    void setTableView();
public slots:
    void redefineToTypeStrategy();
    void redefineToFileDirectoryStrategy();
    void changeDir(QModelIndex);
};

#endif // MAINWINDOW_H
