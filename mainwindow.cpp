#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    strategy_ = new TypeStrategy();
    firstEverWidget_ = buffWidget_ = ui_->widget;

    setDirectoryTree();
}

void MainWindow::setDirectoryTree(){
    dirModel_ = new QFileSystemModel(this);
    dirModel_->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel_->setRootPath(QDir::homePath());
    ui_->treeView->setModel(dirModel_);
}

void MainWindow::changeDir(QModelIndex index)
{
    currentDir_ = dirModel_->filePath(index);
    recalculateCurrentDir();
}

void MainWindow::recalculateCurrentDir()
{
    adapterCollection_.setData(strategy_->calculate(currentDir_));
}

void MainWindow::redefineStrategy(int strategyType){
    delete strategy_;
    switch(strategyType) {
        case TYPE_STRATEGY:
            strategy_ = new TypeStrategy();
        break;
        case FILE_DIRECTORY_STRATEGY:
            strategy_ = new FileDirectoryStrategy();
        break;
    }
    recalculateCurrentDir();
}

void MainWindow::redefineToTypeStrategy(){
    redefineStrategy(TYPE_STRATEGY);
}

void MainWindow::redefineToFileDirectoryStrategy(){
    redefineStrategy(FILE_DIRECTORY_STRATEGY);
}

void MainWindow::redraw(int adapterType)
{
    bool changed = adapterCollection_.setAdapter(adapterType);
    if (changed) {
        QLayoutItem *temp = ui_->layout->replaceWidget(buffWidget_, adapterCollection_.getWidget());
        buffWidget_->setParent(nullptr);
        buffWidget_ = adapterCollection_.getWidget();
        delete temp;
    }
}

void MainWindow::redrawToBarChart()
{
    redraw(AdapterCollection::BAR_CHART);
}

void MainWindow::redrawToPieChart()
{
    redraw(AdapterCollection::PIE_CHART);
}
void MainWindow::redrawToTable()
{
    redraw(AdapterCollection::TABLE);
}

MainWindow::~MainWindow()
{
    delete ui_;
    delete strategy_;
    delete dirModel_;
    delete firstEverWidget_;
}
