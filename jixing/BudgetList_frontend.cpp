#include "budgetlist_frontend.h"
#include "ui_budgetlist.h" // 确保包含生成的头文件
#include <QInputDialog>
#include <QMessageBox>

BudgetListWidget::BudgetListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BudgetList) // 创建 UI 对象
{
    ui->setupUi(this); // 设置 UI

    // 设置表格列数和列标题
    ui->tableWidget->setColumnCount(2);
    QStringList headers;
    headers << "Category" << "Amount";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // 显式连接信号和槽函数
    connect(ui->addButton, &QPushButton::clicked, this, &BudgetListWidget::addBudget);
    connect(ui->modifyButton, &QPushButton::clicked, this, &BudgetListWidget::modifyBudget);
    connect(ui->deleteButton, &QPushButton::clicked, this, &BudgetListWidget::deleteBudget);

    updateTable(); // 初始化时更新表格内容
}

BudgetListWidget::~BudgetListWidget() {
    delete ui; // 析构函数中删除 UI 指针，释放内存
}

void BudgetListWidget::addBudget() {
    // 获取用户输入
    bool ok;
    QString category = QInputDialog::getItem(this, "Add Budget", "Category:",
                                             {"Food", "Accommodation", "Tickets", /* ...其他类别 */}, 0, false, &ok);
    double amount = QInputDialog::getDouble(this, "Add Budget", "Amount:", 0, 0, 100000, 2, &ok);

    if (ok && !category.isEmpty()) {
        BudgetList::Budget budget = {static_cast<BudgetList::Category>(category.toInt()), amount};
        budgetList.addBudget(budget); // 调用后端方法添加预算
        updateTable(); // 更新表格内容
    }
}

void BudgetListWidget::modifyBudget() {
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        // 获取用户输入
        bool ok;
        QString category = QInputDialog::getItem(this, "Modify Budget", "Category:",
                                                 {"Food", "Accommodation", "Tickets", /* ...其他类别 */}, 0, false, &ok);
        double amount = QInputDialog::getDouble(this, "Modify Budget", "Amount:",
                                                ui->tableWidget->item(row, 1)->text().toDouble(), 0, 100000, 2, &ok);

        if (ok && !category.isEmpty()) {
            BudgetList::Budget budget = {static_cast<BudgetList::Category>(category.toInt()), amount};
            budgetList.modifyBudget(row, budget); // 调用后端方法修改预算
            updateTable(); // 更新表格内容
        }
    } else {
        QMessageBox::warning(this, "Warning", "Please select a budget to modify."); // 未选择预算项时显示警告
    }
}

void BudgetListWidget::deleteBudget() {
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        budgetList.deleteBudget(row); // 调用后端方法删除预算
        updateTable(); // 更新表格内容
    } else {
        QMessageBox::warning(this, "Warning", "Please select a budget to delete."); // 未选择预算项时显示警告
    }
}

void BudgetListWidget::updateTable() {
    ui->tableWidget->setRowCount(0); // 清空表格
    auto budgets = budgetList.outputBudgets(); // 获取当前预算列表
    for (const auto& budget : budgets) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row); // 添加新行
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(static_cast<int>(budget.category))));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(budget.amount, 'f', 2)));
    }
}
