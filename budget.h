#ifndef BUDGET_H
#define BUDGET_H

#include <QString>
#include <QDateTime>

class Cost
{
public:
    QString content;
    QString type;
    QDate date;
    double money;
    Cost(const QString&,const QString&,const QDate&,double);

};

#endif // BUDGET_H
