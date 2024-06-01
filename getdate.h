#ifndef GETDATE_H
#define GETDATE_H

#include <QDialog>
#include <QString>
#include <QTime>
#include <QDate>

namespace Ui {
class GetDate;
}

class GetDate : public QDialog
{
    Q_OBJECT

public:
    explicit GetDate(QWidget *parent = nullptr);
    ~GetDate();

signals:
    void dateDataCollected(const QString &str, const QDate &date, const QTime &time); // 定义一个信号

public slots:
    void on_buttonBox_accepted();

private slots:
    void on_buttonBox_rejected();

private:
    Ui::GetDate *ui;
};

#endif // GETDATE_H
