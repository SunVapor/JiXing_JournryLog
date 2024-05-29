#include "itinerary_frontend.h"
#include "ui_itinerary.h" // 确保包含生成的头文件
#include <QInputDialog>
#include <QMessageBox>

ItineraryWidget::ItineraryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Itinerary) // 创建UI对象
{
    ui->setupUi(this); // 设置UI

    // 设置表格列数和列标题
    ui->tableWidget->setColumnCount(3);
    QStringList headers;
    headers << "Time" << "Place" << "Note";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // 显式连接信号和槽函数
    connect(ui->addButton, &QPushButton::clicked, this, &ItineraryWidget::addTrip);
    connect(ui->modifyButton, &QPushButton::clicked, this, &ItineraryWidget::modifyTrip);
    connect(ui->deleteButton, &QPushButton::clicked, this, &ItineraryWidget::deleteTrip);

    updateTable(); // 初始化时更新表格内容
}

ItineraryWidget::~ItineraryWidget() {
    delete ui; // 析构函数中删除UI指针，释放内存
}

void ItineraryWidget::addTrip() {
    // 获取用户输入
    QString time = QInputDialog::getText(this, "Add Trip", "Time:");
    QString place = QInputDialog::getText(this, "Add Trip", "Place:");
    QString note = QInputDialog::getText(this, "Add Trip", "Note:");

    if (!time.isEmpty() && !place.isEmpty()) {
        Itinerary::Trip trip = {time.toStdString(), place.toStdString(), note.toStdString()};
        itinerary.addTrip(trip); // 调用后端方法添加行程
        updateTable(); // 更新表格内容
    }
}

void ItineraryWidget::modifyTrip() {
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        // 获取用户输入
        QString time = QInputDialog::getText(this, "Modify Trip", "Time:", QLineEdit::Normal, ui->tableWidget->item(row, 0)->text());
        QString place = QInputDialog::getText(this, "Modify Trip", "Place:", QLineEdit::Normal, ui->tableWidget->item(row, 1)->text());
        QString note = QInputDialog::getText(this, "Modify Trip", "Note:", QLineEdit::Normal, ui->tableWidget->item(row, 2)->text());

        if (!time.isEmpty() && !place.isEmpty()) {
            Itinerary::Trip trip = {time.toStdString(), place.toStdString(), note.toStdString()};
            itinerary.modifyTrip(row, trip); // 调用后端方法修改行程
            updateTable(); // 更新表格内容
        }
    } else {
        QMessageBox::warning(this, "Warning", "Please select a trip to modify."); // 未选择行程时显示警告
    }
}

void ItineraryWidget::deleteTrip() {
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        itinerary.deleteTrip(row); // 调用后端方法删除行程
        updateTable(); // 更新表格内容
    } else {
        QMessageBox::warning(this, "Warning", "Please select a trip to delete."); // 未选择行程时显示警告
    }
}

void ItineraryWidget::updateTable() {
    ui->tableWidget->setRowCount(0); // 清空表格
    auto trips = itinerary.outputTrips(); // 获取当前行程列表
    for (const auto& trip : trips) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row); // 添加新行
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(trip.time)));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(trip.place)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(trip.note)));
    }
}
