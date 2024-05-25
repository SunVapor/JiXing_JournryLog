#include "ItemList.h"

using namespace std;

    // 创建清单：设置清单名称
    void ItemList::createList(const string& name) {
        listName = name;
    }

    // 重命名清单：修改清单名称
    void ItemList::renameList(const string& name) {
        listName = name;
    }

    // 删除清单：清空清单名称和物品列表
    void ItemList::deleteList() {
        listName.clear();
        items.clear();
    }

    // 增加物品：向物品列表中添加一个新的物品
    void ItemList::addItem(const Item& item) {
        items.push_back(item);
    }

    // 修改物品：修改物品列表中的某个物品
    void ItemList::modifyItem(int index, const Item& item) {
        if (index >= 0 && index < int(items.size())) {
            items[index] = item;
        }
    }

    // 删除物品：从物品列表中删除某个物品
    void ItemList::deleteItem(int index) {
        if (index >= 0 && index < int(items.size())) {
            items.erase(items.begin() + index);
        }
    }

    // 输出物品：返回当前的物品列表
    vector<ItemList::Item> ItemList::outputItems() {
        return items;
    }

    // 设置某个物品的打包状态
    void ItemList::setItemPacked(int index, bool isPacked) {
        if (index >= 0 && index < int(items.size())) {
            items[index].isPacked = isPacked;
        }
    }