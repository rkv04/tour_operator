#ifndef CITYLISTWINDOW_H
#define CITYLISTWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSharedPointer>

#include "addcitywindow.h"
#include "editcitywindow.h"
#include "citytablemodel.h"

namespace Ui {
class CityListWindow;
}

class CityListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CityListWindow(QWidget *parent = nullptr);
    ~CityListWindow();

    void init();

private slots:
    void onAddButtonClicked();
    void onDeleteButtonClicked();
    void addNewCity(const QSharedPointer<City> city);
    void onEditButtonClicked();
    void onFindButtonClicked();

private:
    Ui::CityListWindow *ui;
    QSharedPointer<CityTableModel> city_table_model;
    AddCityWindow *add_city_window;
    EditCityWindow *edit_city_window;
};

#endif // CITYLISTWINDOW_H
