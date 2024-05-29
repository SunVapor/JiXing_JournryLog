#ifndef UI_ITINERARY_H
#define UI_ITINERARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Itinerary
{
public:
    QTableWidget *tableWidget;
    QPushButton *addButton;
    QPushButton *modifyButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *Itinerary)
    {
        if (Itinerary->objectName().isEmpty())
            Itinerary->setObjectName(QString::fromUtf8("Itinerary"));
        Itinerary->resize(400, 300);
        tableWidget = new QTableWidget(Itinerary);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 380, 200));
        addButton = new QPushButton(Itinerary);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(10, 220, 80, 30));
        modifyButton = new QPushButton(Itinerary);
        modifyButton->setObjectName(QString::fromUtf8("modifyButton"));
        modifyButton->setGeometry(QRect(100, 220, 80, 30));
        deleteButton = new QPushButton(Itinerary);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(190, 220, 80, 30));

        retranslateUi(Itinerary);

        QMetaObject::connectSlotsByName(Itinerary);
    } // setupUi

    void retranslateUi(QWidget *Itinerary)
    {
        Itinerary->setWindowTitle(QApplication::translate("Itinerary", "Itinerary", nullptr));
        addButton->setText(QApplication::translate("Itinerary", "Add", nullptr));
        modifyButton->setText(QApplication::translate("Itinerary", "Modify", nullptr));
        deleteButton->setText(QApplication::translate("Itinerary", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
class Itinerary: public Ui_Itinerary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITINERARY_H

