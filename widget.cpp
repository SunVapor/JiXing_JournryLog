#include "widget.h"
#include "getdate.h"
#include "travel.h"
#include <QDateTime>
#include <QFont>
#include <QInputDialog>
#include <QMessageBox>
#include "./ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("纪行");
    QFont font("得意黑",22,QFont::Bold);
    ui->title->setFont(font);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_newPlan_clicked()
{
    bool ok;
    QString title = QInputDialog::getText(this, "新旅行计划", "旅行计划标题:", QLineEdit::Normal, "", &ok);
    if (ok && !title.isEmpty()) {
        Plan newPlan(title);
        plans.push_back(newPlan);
        updatePlan();
    }
}

void Widget::on_deletePlan_clicked()
{
    int row = ui->TripPlan->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "错误", "请先选中一项旅行计划");
        return;
    }
    if (row >= 0 && row < plans.size()) {
        ui->Schedule->clear();
        if (plans.size()==1)
            plans.clear();
        else
            plans.erase(plans.begin() + row);
        updatePlan(); // 更新 UI 列表
    }
    // 这里会崩溃可能是因为vector存放东西后对象的大小发生变化。尝试使用指针而非直接存储。
    return;
}

void Widget::updatePlan() {
    ui->TripPlan->clear(); // 首先清除当前的所有项
    for (const auto& plan : plans) {
        ui->TripPlan->addItem("\n    " + plan.title + "\n");
    }
}


void Widget::on_newSchedule_clicked()
{
    int row = ui->TripPlan->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "错误", "请先选中一项旅行计划");
        return;
    }

    GetDate* getdate = new GetDate(this);
    getdate->setModal(true);
    connect(getdate, &GetDate::dateDataCollected, this, &Widget::handleSchedule);
    getdate->show();
}

void Widget::handleSchedule(const QString &str, const QDate &date, const QTime &time)
{
    int row = ui->TripPlan->currentRow();
    if (row >= 0 && row < plans.size()) {

        QDateTime datetime = QDateTime(date,time);
        Schedule newSchedule(str,datetime);
        plans[row].schedules.push_back(newSchedule);
        updateScheduleList();
    }
}

void Widget::on_deleteSchedule_clicked()
{
    int planRow = ui->TripPlan->currentRow();
    int scheduleRow = ui->Schedule->currentRow();
    if (planRow >= 0 && planRow < plans.size() && scheduleRow >= 0 && scheduleRow < plans[planRow].schedules.size()) {
        plans[planRow].schedules.erase(plans[planRow].schedules.begin() + scheduleRow);
        updateScheduleList();
    }
}

void Widget::on_TripPlan_currentRowChanged(int currentRow)
{
    updateScheduleList();
}


void Widget::updateScheduleList() {
    ui->Schedule->clear();
    int row = ui->TripPlan->currentRow();
    plans[row].sortSchedule();
    if (row >= 0 && row < plans.size()) {
        for (const auto &schedule : plans[row].schedules) {
            ui->Schedule->addItem("    " + schedule.location + "\n    " + schedule.time.toString("yyyy-MM-dd hh:mm"));
        }
    }
}


