#ifndef BUDGETLIST_FRONTEND_H
#define BUDGETLIST_FRONTEND_H

#include <QWidget>
#include "BudgetList.h"

namespace Ui {
class BudgetList;
}

class BudgetListWidget : public QWidget {
    Q_OBJECT

public:
    explicit BudgetListWidget(QWidget *parent = nullptr);
    ~BudgetListWidget();

private slots:
    void addBudget();
    void modifyBudget();
    void deleteBudget();

private:
    Ui::BudgetList *ui;
    BudgetList budgetList; // 后端的 BudgetList 对象
    void updateTable(); // 更新表格内容
};

#endif // BUDGETLIST_FRONTEND_H
