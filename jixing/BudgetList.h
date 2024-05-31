#ifndef BUDGETLIST_H
#define BUDGETLIST_H

#include <vector>
#include <string>
#include <map>

using namespace std;

// 预算清单类
class BudgetList {
public:
    enum Category {
        Food,
        Accommodation,
        Tickets,
        /*...*/
    };

    struct Budget {
        Category category;
        double amount;
    };

private:
    string listName;  // 清单名称
    vector<Budget> budgets;  // 预算列表

public:
    // 创建清单：设置清单名称
    void createList(const string& name);

    // 重命名清单：修改清单名称
    void renameList(const string& name);

    // 删除清单：清空清单名称和预算列表
    void deleteList();

    // 增加预算：向预算列表中添加一个新的预算
    void addBudget(const Budget& budget);

    // 修改预算：修改预算列表中的某个预算
    void modifyBudget(int index, const Budget& budget);

    // 删除预算：从预算列表中删除某个预算
    void deleteBudget(int index);

    // 输出预算：返回当前的预算列表
    vector<Budget> outputBudgets();

    // 统计各类别的预算百分比
    map<Category, double> getCategoryPercentage();
};

#endif // BUDGETLIST_H
