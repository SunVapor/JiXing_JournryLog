#ifndef TRAVEL_H
#define TRAVEL_H

#include <QString>
#include <QDateTime>
#include <vector>

class Schedule {
public:
    QString location;
    QDateTime time;
    Schedule(const QString&,QDateTime&);
    bool operator<(const Schedule&);
};

class Plan {
public:
    QString title;
    std::vector<Schedule> schedules;
    Plan(const QString&);
    void sortSchedule();
};


#endif // TRAVEL_H
