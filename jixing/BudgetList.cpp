#include "BudgetList.h"
#include <numeric>

using namespace std;

    void BudgetList::createList(const string& name) {
        listName = name;
    }

    void BudgetList::renameList(const string& name) {
        listName = name;
    }

    void BudgetList::deleteList() {
        listName.clear();
        budgets.clear();
    }

    void BudgetList::addBudget(const Budget& budget) {
        budgets.push_back(budget);
    }

    void BudgetList::modifyBudget(int index, const Budget& budget) {
        if (index >= 0 && index < budgets.size()) {
            budgets[index] = budget;
        }
    }

    void BudgetList::deleteBudget(int index) {
        if (index >= 0 && index < budgets.size()) {
            budgets.erase(budgets.begin() + index);
        }
    }

    vector<BudgetList::Budget> BudgetList::outputBudgets() {
        return budgets;
    }

    map<BudgetList::Category, double> BudgetList::getCategoryPercentage() {
        double totalAmount = accumulate(budgets.begin(), budgets.end(), 0.0,
                                             [](double sum, const Budget& budget) {
                                                 return sum + budget.amount;
                                             });
        map<Category, double> percentages;
        for (const Budget& budget : budgets) {
            percentages[budget.category] += budget.amount / totalAmount;
        }
        return percentages;
    }