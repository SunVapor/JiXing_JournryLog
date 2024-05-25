#include "Journal.h"

using namespace std;

    void Journal::createJournal(const string& name) {
        journalName = name;
    }

    void Journal::renameJournal(const string& name) {
        journalName = name;
    }

    void Journal::deleteJournal() {
        journalName.clear();
        entries.clear();
    }

    void Journal::addEntry(const Entry& entry) {
        entries.push_back(entry);
    }

    void Journal::modifyEntry(int index, const Entry& entry) {
        if (index >= 0 && index < int(entries.size())) {
            entries[index] = entry;
        }
    }

    void Journal::deleteEntry(int index) {
        if (index >= 0 && index < int(entries.size())) {
            entries.erase(entries.begin() + index);
        }
    }

    vector<Journal::Entry> Journal::outputEntries() {
        return entries;
    }