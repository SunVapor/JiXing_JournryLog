#include <vector>
#include <string>

using namespace std;

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
    void createList(const string& name);

    // 重命名清单：修改清单名称
    void renameList(const string& name);

    // 删除清单：清空清单名称和物品列表
    void deleteList();

    // 增加物品：向物品列表中添加一个新的物品
    void addItem(const Item& item);

    // 修改物品：修改物品列表中的某个物品
    void modifyItem(int index, const Item& item);

    // 删除物品：从物品列表中删除某个物品
    void deleteItem(int index);

    // 输出物品：返回当前的物品列表
    vector<Item> outputItems();

    // 设置某个物品的打包状态
    void setItemPacked(int index, bool isPacked);
};