#ifndef HOTELSERVICE_H
#define HOTELSERVICE_H

#include <QSharedPointer>
#include <QSqlQuery>
#include <QSqlRecord>
#include "hotel.h"

class HotelService
{
public:
    HotelService();
    QVector<QSharedPointer<Hotel>> getHotelList();
    int addHotel(const QSharedPointer<Hotel> &hotel);
private:
    int getIdLastAddedHotel();
    QVector<QSharedPointer<Hotel>> getHotelListByQuery(QSqlQuery &query);
    QSharedPointer<Hotel> createHotelByRow(const QSqlRecord &record);
};

#endif // HOTELSERVICE_H