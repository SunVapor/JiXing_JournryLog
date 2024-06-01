#include "budget.h"
#include <QString>

Cost::Cost(const QString& _content,const QString& _type,const QDate& _date,double _money)
{
    content = _content;
    type = _type;
    date = _date;
    money = _money;
}
