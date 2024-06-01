#include "budgetwidget.h"
#include "ui_budgetwidget.h"
#include <QInputDialog>
#include <QMessageBox>
#include <algorithm>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "budget.h"
#include "getcost.h"

BudgetWidget::BudgetWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BudgetWidget)
{
    ui->setupUi(this);
    QFont Font("等线", 10, QFont::Normal);
    ui->Record->setFont(Font);
    QFont titlefont("得意黑",22,QFont::Bold);
    ui->title->setFont(titlefont);
    budget = 1000;
    typecosts.insert("餐饮",0.0);
    typecosts.insert("住宿",0.0);
    ui->progressBar->setValue(0);
}

BudgetWidget::~BudgetWidget()
{
    delete ui;
}

void BudgetWidget::on_newType_clicked()
{
    // 弹出对话框，获取新的开销种类名称
    bool ok;
    QString type = QInputDialog::getText(this, tr("新开销种类"),tr("开销种类:"), QLineEdit::Normal,"", &ok);
    if (ok && !type.isEmpty()) {
        typecosts.insert(type,0.0);
        updateCharts();
    }
}


void BudgetWidget::on_deleteType_clicked()
{
    // 弹出对话框，让用户选择要删除的开销种类
    bool ok;
    QStringList types;
    for(auto it = typecosts.begin();it!=typecosts.end();++it) {
        types << it.key();
    }
    QString type = QInputDialog::getItem(this, tr("删除开销种类"), tr("选择种类:"), types, 0, false, &ok);
    if (ok && !type.isEmpty()) {
        // 可能还需要删除与该类型相关的所有记录
        auto it = std::remove_if(costs.begin(), costs.end(), [&type](const Cost &cost) {
            return cost.type == type;
        });
        costs.erase(it, costs.end());
        typecosts.remove(type);
        updateCharts(); // 更新图表
    }
}


void BudgetWidget::on_newCost_clicked()
{
    getCost* getcost = new getCost(this,typecosts);
    getcost->setModal(true);
    connect(getcost, &getCost::costDataCollected, this, &BudgetWidget::handleCost);
    getcost->show();
}

void BudgetWidget::handleCost(const QString & _content, double _money, const QString& _type, const QDate & _date)
{
    auto it = typecosts.find(_type);
    if (it != typecosts.end()) {
        it.value() += _money;
        Cost tmp(_content, _type,_date,_money);
        costs.push_back(tmp);
        updateCosts();
        updateCharts();
    } else {
        // 键不存在，it 等于 typecosts.end()
        QMessageBox::warning(this, "错误", "开销类型不存在");
    }
}


void BudgetWidget::on_deleteCost_clicked()
{
    int row = ui->Record->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "错误", "请先选中一项开销");
        return;
    }
    if(row >= costs.size())
    {
        QMessageBox::warning(this, "错误", "开销不存在");
        return;
    }

    auto it = typecosts.find(costs.at(row).type);
    if (it != typecosts.end()){
        it.value() -= costs.at(row).money;
    } else {
        QMessageBox::warning(this, "错误", "开销不存在");
        return;
    }
    costs.removeAt(row);
    updateCosts();
    updateCharts();
}


void BudgetWidget::on_changeBudget_clicked()
{
    double newbudget = QInputDialog::getDouble(this,"更新预算","请输入新的预算",0,0);
    if(newbudget > 0){
        budget = newbudget;
        updateCosts();
        updateCharts();
    } else {
        QMessageBox::warning(this,"错误","请输入大于零的预算");
    }
}

void BudgetWidget::updateCosts()
{
    ui->Record->clear(); // 首先清除当前的所有项
    for (auto it = costs.begin();it!=costs.end();++it) {
        ui->Record->addItem("  " + it->content +
                            "\n\n    金额： " + QString::number(it->money,'f',2) +
                            "\n    种类： " + it->type +
                            "\n    日期： " + it->date.toString("yyyy-MM-dd") + "\n");
    }
}

void BudgetWidget::updateCharts()
{
    double total = 0;
    for(auto it=typecosts.begin();it!=typecosts.end();++it)
    {
        total += it.value();
    }
    ui->totalcost->display(total);
    ui->budget->display(budget);

    int percent = total/budget*100;
    ui->progressBar->setValue(percent);
    if(percent<=60){
        ui->progressBar->setStyleSheet("color: green;");
    } else if(percent<=85) {
        ui->progressBar->setStyleSheet("color: orange;");
    } else {
        ui->progressBar->setStyleSheet("color: red;");
    }

    QLayoutItem* item;
    while ((item = ui->PieChartShow->takeAt(0)) != nullptr) {
        // 如果item是一个widget，移除并删除
        if (QWidget* widget = item->widget()) {
            widget->hide();
            delete widget;
        }
        // 删除布局项目
        delete item;
    }
    QPieSeries *series = new QPieSeries();
    // 遍历QMap并添加到QPieSeries
    for(auto i=typecosts.begin();i!=typecosts.end();++i) {
        QPieSlice *slice = series->append(i.key(), i.value());
        slice->setLabelVisible(true); // 显示每个扇区的标签
    }
    // 创建一个QChart对象并添加系列
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("开销分布");
    chart->legend()->setVisible(true); // 显示图例
    chart->legend()->setAlignment(Qt::AlignBottom); // 图例对齐方式

    // 创建一个QChartView对象并设置QChart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing); // 抗锯齿渲染

    ui->PieChartShow->addWidget(chartView);
}
