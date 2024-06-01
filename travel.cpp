#include "travel.h"
#include <QString>
#include <QDateTime>
#include <algorithm>

Schedule::Schedule(const QString& addr,QDateTime& datetime)
{
    location = addr;
    time = datetime;
}

bool Schedule::operator<(const Schedule& o)
{
    return time < o.time;
}

Plan::Plan(const QString& name){
    title = name;
}

void Plan::sortSchedule()
{
    sort(schedules.begin(),schedules.end());
}

