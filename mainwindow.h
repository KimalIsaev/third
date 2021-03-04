#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "abstractstrategy.h"
#include "filedirectorystrategy.h"
#include "typestrategy.h"
#include "util.h"


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
    Ui::MainWindow *ui_ = nullptr;
    QList<QPair<QString, double>> calculation_;
};

#endif // MAINWINDOW_H
