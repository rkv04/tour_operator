#include "city.h"

#include <QDebug>

City::City() {}

City::City(const int id, const QString &title, const QString &climate) {
    this->id = id;
    this->title = title;
    this->climate = climate;
}
