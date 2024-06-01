#ifndef GETCOST_H
#define GETCOST_H

#include <QDialog>
#include <QDateTime>
#include <QString>
#include <QMap>

namespace Ui {
class getCost;
}

class getCost : public QDialog
{
    Q_OBJECT

public:
    explicit getCost(QWidget *parent, QMap<QString,double>&);
    ~getCost();
    Ui::getCost *ui;

signals:
    void costDataCollected(const QString &, double, const QString&, const QDate &); // 定义一个信号

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


};

#endif // GETCOST_H
