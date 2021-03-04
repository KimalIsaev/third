#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    ui_->tableView->verticalHeader()->setVisible(false);
}


MainWindow::~MainWindow()
{
    delete ui_;
}
