#ifndef TICKETPURCHASEWINDOW_H
#define TICKETPURCHASEWINDOW_H

#include <QDialog>
#include <QValidator>

#include "apperror.h"
#include "citylistmodel.h"
#include "hotellistmodel.h"
#include "tickettablemodel.h"
#include "ticketdurationlistmodel.h"

namespace Ui {
class TicketPurchaseWindow;
}

class TicketPurchaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TicketPurchaseWindow(QWidget *parent = nullptr);
    ~TicketPurchaseWindow();

    void init();

private slots:
    void onFindButtonClicked();
    void onBuyButtonClicked();
    void onCancelButtonClicked();
    void onResetFiltersButtonClicked();
    void destinationCityBoxChanged();
    void showTicketInfo(const QModelIndex &index);
    void setTotalPrice();

signals:
    void back();

private:
    Ui::TicketPurchaseWindow *ui;

    void initModels();
    void initUi();
    void setUiSettings();
    void createAndSetModels();

    void handleAppError(const AppError &ex);
    bool hasSelection();
    bool confirmPurchase();
    QMap<QString, QString> createFilter();

    QSharedPointer<QValidator> price_validator;
    QSharedPointer<TicketTableModel> ticket_table_model;
    QSharedPointer<CityListModel> departure_city_list_model;
    QSharedPointer<CityListModel> destination_city_list_model;
    QSharedPointer<HotelListModel> hotel_list_model;
    QSharedPointer<TicketDurationListModel> duration_list_model;
};

#endif // TICKETPURCHASEWINDOW_H
