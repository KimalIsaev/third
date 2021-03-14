#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    chart_ = new PieChartAdapter();
    strategy_ = new TypeStrategy();
    table_ = new Table();
    setTableView();
    setDirectoryTree();
}

void MainWindow::drawCalculation(){
    ui_->chartView->setChart(chart_->listToChart(calculation_));
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

void MainWindow::printCalculation(){
    table_->replace(util::doubleToString(calculation_));
}

void MainWindow::setTableView(){
    ui_->tableView->verticalHeader()->setVisible(false);
    ui_->tableView->setModel(table_);
    ui_->tableView->setColumnWidth(0,60);
    ui_->tableView->setColumnWidth(1,600);
}

void MainWindow::recalculateCurrentDir()
{
    calculation_ = strategy_->calculate(currentDir_);
    printCalculation();
    drawCalculation();
}

void MainWindow::redefineStrategy(unsigned char strategyType){
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

void MainWindow::redrawChart(unsigned char chartType){
    delete chart_;
    switch(chartType) {
        case BAR_CHART:
            chart_ = new BarChartAdapter();
        break;
        case PIE_CHART:
            chart_ = new PieChartAdapter();
        break;
    }
    drawCalculation();
}

void MainWindow::redrawToBarChart(){
    redrawChart(BAR_CHART);
}

void MainWindow::redrawToPieChart(){
    redrawChart(PIE_CHART);
}


MainWindow::~MainWindow()
{
    delete chart_;
    delete ui_;
    delete table_;
    delete strategy_;
    delete dirModel_;
}
