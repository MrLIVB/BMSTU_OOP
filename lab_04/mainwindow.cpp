#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(200, 300);
    layout = new QVBoxLayout;
    ui->centralwidget->setLayout(layout);
    layout->addWidget(elevator.getWidget());
}

MainWindow::~MainWindow()
{
    delete ui;
}

