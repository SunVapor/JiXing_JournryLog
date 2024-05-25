#include <vector>
#include <string>

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
    void createList(const string& name);

    // 重命名清单：修改清单名称
    void renameList(const string& name);

    // 删除清单：清空清单名称和行程列表
    void deleteList();

    // 增加行程：向行程列表中添加一个新的行程
    void addTrip(const Trip& trip);

    // 修改行程：修改行程列表中的某个行程
    void modifyTrip(int index, const Trip& trip);

    // 删除行程：从行程列表中删除某个行程
    void deleteTrip(int index);

    // 输出行程：返回当前的行程列表
    vector<Trip> outputTrips();

    // 行程内部按时间顺序进行排序
    void sortTripsByTime();
};