#include <vector>
#include <string>

using namespace std;

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
    void createJournal(const string& name);

    // 重命名日记本：修改日记本名称
    void renameJournal(const string& name);

    // 删除日记本：清空日记本名称和日记条目列表
    void deleteJournal();

    // 增加日记条目：向日记条目列表中添加一个新的条目
    void addEntry(const Entry& entry);

    // 修改日记条目：修改日记条目列表中的某个条目
    void modifyEntry(int index, const Entry& entry);

    // 删除日记条目：从日记条目列表中删除某个条目
    void deleteEntry(int index);

    // 输出日记条目：返回当前的日记条目列表
    vector<Entry> outputEntries();
};