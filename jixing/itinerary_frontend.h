#ifndef ITINERARY_FRONTEND_H
#define ITINERARY_FRONTEND_H

#include <QWidget>
#include <QTableWidget>
#include "itinerary.h"

namespace Ui {
class Itinerary;
}

class ItineraryWidget : public QWidget {
    Q_OBJECT

public:
    explicit ItineraryWidget(QWidget *parent = nullptr);
    ~ItineraryWidget();

private slots:
    void addTrip();
    void modifyTrip();
    void deleteTrip();

private:
    Ui::Itinerary *ui;
    Itinerary itinerary; // 后端的Itinerary对象
    void updateTable(); // 更新表格内容
};
#endif // ITINERARY_FRONTEND_H
