#ifndef LUGGAGEWIDGET_H
#define LUGGAGEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class LuggageWidget;
}

class LuggageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LuggageWidget(QWidget *parent = nullptr);
    ~LuggageWidget();

private slots:
    void on_addLuggage_clicked();

    void on_deleteLuggage_clicked();

    void moveToCompleted(QListWidgetItem *item);

    void moveToUncompleted(QListWidgetItem *item);

private:
    Ui::LuggageWidget *ui;

    void updateStatistics();
};

#endif // LUGGAGEWIDGET_H
