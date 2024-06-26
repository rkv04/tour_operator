#ifndef HOTELLISTMODEL_H
#define HOTELLISTMODEL_H

#include <QAbstractListModel>

#include "hotel.h"

class HotelListModel : public QAbstractListModel
{
public:

    enum Roles {
        HotelPtrRole = Qt::UserRole,
        HotelIdRole = Qt::UserRole + 1
    };

    explicit HotelListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role) const override;
    int rowCount(const QModelIndex &parent) const override;
    void setHotelList(const QVector<QSharedPointer<Hotel>> &hotels);
    void addHotelIfNotExists(const QSharedPointer<Hotel> &hotel);

private:
    QVector<QSharedPointer<Hotel>> hotels;
};

#endif // HOTELLISTMODEL_H
