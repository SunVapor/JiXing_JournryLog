#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDateTime>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QInputDialog>
#include "travel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;

    std::vector<Plan> plans;

    void updatePlan();
    void addSchedule(const QString &, const QString &);
    void handleSchedule(const QString&, const QDate&, const QTime &);
    void updateScheduleList();

private slots:
    void on_newPlan_clicked();

    void on_deletePlan_clicked();

    void on_newSchedule_clicked();

    void on_deleteSchedule_clicked();

    void on_TripPlan_currentRowChanged(int currentRow);
};
#endif // WIDGET_H
