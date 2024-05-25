#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;
// 行程清单类
class Itinerary {
public:
    struct Trip {
        string time;
        string place;
        string note;
    };

private:
    string listName;  // 清单名称
    vector<Trip> trips;  // 行程列表

public:
    // 创建清单：设置清单名称
    void createList(const string& name) {
        listName = name;
    }

    // 重命名清单：修改清单名称
    void renameList(const string& name) {
        listName = name;
    }

    // 删除清单：清空清单名称和行程列表
    void deleteList() {
        listName.clear();
        trips.clear();
    }

    // 增加行程：向行程列表中添加一个新的行程
    void addTrip(const Trip& trip) {
        trips.push_back(trip);
    }

    // 修改行程：修改行程列表中的某个行程
    void modifyTrip(int index, const Trip& trip) {
        if (index >= 0 && index < int(trips.size())) {
            trips[index] = trip;
        }
    }

    // 删除行程：从行程列表中删除某个行程
    void deleteTrip(int index) {
        if (index >= 0 && index < int(trips.size())) {
            trips.erase(trips.begin() + index);
        }
    }

    // 输出行程：返回当前的行程列表
    vector<Trip> outputTrips() {
        return trips;
    }

    // 行程内部按时间顺序进行排序
    void sortTripsByTime() {
        sort(trips.begin(), trips.end(), [](const Trip& a, const Trip& b) {
            return a.time < b.time;
        });
    }
};

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
    void createList(const string& name) {
        listName = name;
    }

    // 重命名清单：修改清单名称
    void renameList(const string& name) {
        listName = name;
    }

    // 删除清单：清空清单名称和预算列表
    void deleteList() {
        listName.clear();
        budgets.clear();
    }

    // 增加预算：向预算列表中添加一个新的预算
    void addBudget(const Budget& budget) {
        budgets.push_back(budget);
    }

    // 修改预算：修改预算列表中的某个预算
    void modifyBudget(int index, const Budget& budget) {
        if (index >= 0 && index < int(budgets.size())) {
            budgets[index] = budget;
        }
    }

    // 删除预算：从预算列表中删除某个预算
    void deleteBudget(int index) {
        if (index >= 0 && index < int(budgets.size())) {
            budgets.erase(budgets.begin() + index);
        }
    }

    // 输出预算：返回当前的预算列表
    vector<Budget> outputBudgets() {
        return budgets;
    }

    // 统计各类别的预算百分比
    map<Category, double> getCategoryPercentage() {
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
};

// 物品清单类
class ItemList {
public:
    struct Item {
        string name;
        bool isPacked;
    };

private:
    string listName;  // 清单名称
    vector<Item> items;  // 物品列表

public:
    // 创建清单：设置清单名称
    void createList(const string& name) {
        listName = name;
    }

    // 重命名清单：修改清单名称
    void renameList(const string& name) {
        listName = name;
    }

    // 删除清单：清空清单名称和物品列表
    void deleteList() {
        listName.clear();
        items.clear();
    }

    // 增加物品：向物品列表中添加一个新的物品
    void addItem(const Item& item) {
        items.push_back(item);
    }

    // 修改物品：修改物品列表中的某个物品
    void modifyItem(int index, const Item& item) {
        if (index >= 0 && index < int(items.size())) {
            items[index] = item;
        }
    }

    // 删除物品：从物品列表中删除某个物品
    void deleteItem(int index) {
        if (index >= 0 && index < int(items.size())) {
            items.erase(items.begin() + index);
        }
    }

    // 输出物品：返回当前的物品列表
    vector<Item> outputItems() {
        return items;
    }

    // 设置某个物品的打包状态
    void setItemPacked(int index, bool isPacked) {
        if (index >= 0 && index < int(items.size())) {
            items[index].isPacked = isPacked;
        }
    }
};

// 日记本类
class Journal {
public:
    struct Entry {
        string date;
        string content;
    };

private:
    string journalName;  // 日记本名称
    vector<Entry> entries;  // 日记条目列表

public:
    // 创建日记本：设置日记本名称
    void createJournal(const string& name) {
        journalName = name;
    }

    // 重命名日记本：修改日记本名称
    void renameJournal(const string& name) {
        journalName = name;
    }

    // 删除日记本：清空日记本名称和日记条目列表
    void deleteJournal() {
        journalName.clear();
        entries.clear();
    }

    // 增加日记条目：向日记条目列表中添加一个新的条目
    void addEntry(const Entry& entry) {
        entries.push_back(entry);
    }

    // 修改日记条目：修改日记条目列表中的某个条目
    void modifyEntry(int index, const Entry& entry) {
        if (index >= 0 && index < int(entries.size())) {
            entries[index] = entry;
        }
    }

    // 删除日记条目：从日记条目列表中删除某个条目
    void deleteEntry(int index) {
        if (index >= 0 && index < int(entries.size())) {
            entries.erase(entries.begin() + index);
        }
    }

    // 输出日记条目：返回当前的日记条目列表
    vector<Entry> outputEntries() {
        return entries;
    }
};