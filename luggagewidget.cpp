#include "luggagewidget.h"
#include "ui_luggagewidget.h"
#include <QString>
#include <QMessageBox>
#include <QInputDialog>
#include <QListWidget>
#include <QListWidgetItem>

LuggageWidget::LuggageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LuggageWidget)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0,"未完成");
    ui->tabWidget->setTabText(1,"已完成");
    ui->tabWidget->setCurrentWidget(ui->tab);
    QFont font("等线",11);
    ui->statusLabel->setFont(font);
    QFont titlefont("得意黑",22,QFont::Bold);
    ui->title->setFont(titlefont);
    ui->completedList->setFont(font);
    ui->uncompletedList->setFont(font);
    connect(ui->uncompletedList, &QListWidget::itemDoubleClicked, this, &LuggageWidget::moveToCompleted);
    connect(ui->completedList, &QListWidget::itemDoubleClicked, this, &LuggageWidget::moveToUncompleted);
    updateStatistics();
}

LuggageWidget::~LuggageWidget()
{
    delete ui;
}

void LuggageWidget::on_addLuggage_clicked()
{
    bool ok;
    QString luggage = QInputDialog::getText(this,"新增行李","请输入行李名称",QLineEdit::Normal,"",&ok);
    if(ok && !luggage.isEmpty()){
        QListWidgetItem *item = new QListWidgetItem(luggage);
        ui->uncompletedList->addItem(item);
        updateStatistics();
    } else if(ok){
        QMessageBox::warning(this,"错误","请输入名称");
    }
}


void LuggageWidget::on_deleteLuggage_clicked()
{
    QWidget *currentTab = ui->tabWidget->currentWidget();
    QListWidget *listWidget = nullptr;

    if (currentTab == ui->tab) {
        listWidget = ui->uncompletedList;
    } else if (currentTab == ui->tab_2) {
        listWidget = ui->completedList;
    }

    if (listWidget && listWidget->currentItem()) {
        delete listWidget->takeItem(listWidget->row(listWidget->currentItem()));
        updateStatistics();
        ui->statusLabel->setText("已删除！");
    } else {
        QMessageBox::warning(this,"错误","项目不存在");
    }
}

void LuggageWidget::moveToCompleted(QListWidgetItem *item) {
    ui->completedList->addItem(item->text());
    ui->uncompletedList->takeItem(ui->uncompletedList->row(item));
    updateStatistics();
    ui->statusLabel->setText("已移动至已完成！");
}

void LuggageWidget::moveToUncompleted(QListWidgetItem *item) {
    ui->uncompletedList->addItem(item->text());
    ui->completedList->takeItem(ui->completedList->row(item));
    updateStatistics();
    ui->statusLabel->setText("已移动至未完成！");
}

void LuggageWidget::updateStatistics() {
    int total = ui->uncompletedList->count() + ui->completedList->count();
    int completed = ui->completedList->count();
    ui->totalLabel->setText(QString("共有%1件行李").arg(total));
    ui->completedLabel->setText(QString("已完成%1件行李").arg(completed));
}
