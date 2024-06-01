#include "getdate.h"
#include "ui_getdate.h"

GetDate::GetDate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GetDate)
{
    ui->setupUi(this);
    setWindowTitle("新建日程");
    ui->timeEdit->setDateTime(QDateTime::currentDateTime().toLocalTime());
    ui->dateEdit->setDateTime(QDateTime::currentDateTime().toLocalTime());
}

GetDate::~GetDate()
{
    delete ui;
}

void GetDate::on_buttonBox_accepted()
{
    QString str = ui->lineEdit->text(); // 假设lineEdit是获取QLineEdit文本的途径
    QDate date = ui->dateEdit->date();  // 同上，针对QDateEdit
    QTime time = ui->timeEdit->time();  // 同上，针对QTimeEdit
    emit dateDataCollected(str, date, time); // 发射信号
    this->close();       // 先关闭对话框
    this->deleteLater(); // 然后安排删除
}


void GetDate::on_buttonBox_rejected()
{
    this->close();       // 先关闭对话框
    this->deleteLater(); // 然后安排删除
}

