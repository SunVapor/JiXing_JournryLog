#ifndef BUDGETWIDGET_H
#define BUDGETWIDGET_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include "budget.h"

namespace Ui {
class BudgetWidget;
}

class BudgetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BudgetWidget(QWidget *parent = nullptr);
    ~BudgetWidget();

private slots:
    void on_newType_clicked();

    void on_deleteType_clicked();

    void on_newCost_clicked();

    void handleCost(const QString &, double, const QString&, const QDate &);

    void on_deleteCost_clicked();

    void on_changeBudget_clicked();

    void updateCharts();

    void updateCosts();

private:
    Ui::BudgetWidget *ui;
    QVector<Cost> costs;
    double budget;

public:
    QMap<QString,double> typecosts;
};

#endif // BUDGETWIDGET_H
