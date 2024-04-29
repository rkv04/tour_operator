#include "addcitywindow.h"
#include "ui_addcitywindow.h"

#include "app.h"

AddCityWindow::AddCityWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCityWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(App::APPLICATION_NAME);
    connect(this->ui->addButton, SIGNAL(clicked(bool)), this, SLOT(onAddButtonClicked()));

}

AddCityWindow::~AddCityWindow()
{
    delete ui;
}

void AddCityWindow::onAddButtonClicked() {
    QSharedPointer<City> city = QSharedPointer<City>(new City());
    city->title = this->ui->titleEdit->text();
    city->climate = this->ui->climateEdit->toPlainText();
    emit this->cityCreated(city);
    this->close();
}
