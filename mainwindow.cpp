#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"
#include "budgetwidget.h"
#include "luggagewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 创建旅行计划界面
    setWindowTitle("纪行");
    QWidget* travel = new Widget();
    ui->stackedWidget->addWidget(travel);

    // 创建预算管理界面
    QWidget* budget = new BudgetWidget();
    ui->stackedWidget->addWidget(budget);

    // 创建行李清单界面
    QWidget* luggage = new LuggageWidget();
    ui->stackedWidget->addWidget(luggage);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_travelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);  // 切换到旅行计划界面
}


void MainWindow::on_budgetButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_luggageButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

