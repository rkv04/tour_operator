#ifndef HOTELCATEGORYLISTMODEL_H
#define HOTELCATEGORYLISTMODEL_H

#include <QAbstractListModel>

class HotelCategoryListModel : public QAbstractListModel
{
public:

    enum {
        CategoryRole = Qt::UserRole + 1
    };
    explicit HotelCategoryListModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    QString getCategoryByIndex(const int index);
private:
    struct Category {
        QString title;
        int value;
        Category(const QString &t, int v) : title(t), value(v){}
    };

    QVector<Category> categories;
};

#endif // HOTELCATEGORYLISTMODEL_H
