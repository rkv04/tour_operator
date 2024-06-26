#include "addhotelwindow.h"
#include "ui_addhotelwindow.h"
#include <QMessageBox>

#include "app.h"
#include "apperror.h"
#include "hotel.h"

AddHotelWindow::AddHotelWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddHotelWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(App::APPLICATION_NAME);
    connect(this->ui->addButton, SIGNAL(clicked(bool)), this, SLOT(onAddButtonClicked()));
    connect(this->ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(reject()));
    this->created_hotel = nullptr;
    this->city_list_model = QSharedPointer<CityListModel>(new CityListModel());
    this->category_model = QSharedPointer<HotelCategoryListModel>(new HotelCategoryListModel());
    this->ui->cityList->setModel(city_list_model.get());
    this->ui->cityList->setMaxVisibleItems(10);
    this->ui->hotelCategory->setModel(category_model.get());
    this->ui->hotelCategory->setMaxVisibleItems(10);
}

AddHotelWindow::~AddHotelWindow()
{
    delete ui;
}

void AddHotelWindow::init() {
    App *app = App::getInstance();
    QVector<QSharedPointer<City>> cities;
    try {
        cities = app->getCityList();
    }
    catch(const AppError &ex) {
        QMessageBox::critical(this, App::APPLICATION_NAME, ex.what());
        if (ex.isFatal()) {
            exit(-1);
        }
        return;
    }
    this->city_list_model->setCityList(cities);
}

void AddHotelWindow::onAddButtonClicked() {
    QSharedPointer<City> city = this->ui->cityList->currentData(CityListModel::CityPtrRole).value<QSharedPointer<City>>();
    int category = this->ui->hotelCategory->currentData(HotelCategoryListModel::CategoryRole).toInt();
    QString title = this->ui->titleEdit->text();
    QString address = this->ui->addressEdit->text();
    if (title.isEmpty() || address.isEmpty() || city == nullptr || category == -1) {
        QMessageBox::warning(this, App::APPLICATION_NAME, "Необходимо заполнить все поля формы");
        return;
    }
    this->created_hotel = QSharedPointer<Hotel>(new Hotel());
    this->created_hotel->title = title;
    this->created_hotel->address = address;
    this->created_hotel->category = category;
    this->created_hotel->city = city;
    QDialog::accept();
}

QSharedPointer<Hotel> AddHotelWindow::getCreatedHotel() {
    return this->created_hotel;
}
