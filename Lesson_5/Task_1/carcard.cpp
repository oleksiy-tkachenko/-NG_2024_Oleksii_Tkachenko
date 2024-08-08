#include "carcard.h"
#include "ui_carcard.h"

QString EngineTypeToString(EngineTypes type) {
    switch(type) {
    case EngineTypes::Diesel: return "Diesel";
    case EngineTypes::Gas: return "Gas";
    case EngineTypes::Electric: return "Electric";
    default: return "None";
    }
}

QString ColorToString(Colors color) {
    switch(color) {
    case Colors::Silver: return "Silver";
    case Colors::Blue: return "Blue";
    case Colors::Red: return "Red";
    case Colors::Black: return "Black";
    case Colors::White: return "White";
    case Colors::Brown: return "Brown";
    default: return "None";
    }
}

CarCard::CarCard(Car *carObject, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CarCard)
{
    ui->setupUi(this);
    m_carObject = carObject;

    //setting text to ui elements
    ui->labelCarName->setText(EngineTypeToString(carObject->GetEngineType()) + " " + carObject->GetName());
    ui->labelPrice->setText("$" + QString::number(carObject->GetPrice()));
    ui->labelSeatsNumber->setText("Number of seats: " + QString::number(carObject->GetSeatAmount()));
    ui->labelColor->setText("Color: " + ColorToString(carObject->GetColor()));
    //setting/hiding ui tonnage
    QLabel* tonnageLabel = ui->labelTonnage;
    int tonnage = carObject->GetTonnage();
    if(tonnage){tonnageLabel->setText("Tonnage: " + QString::number(tonnage));}
    else {tonnageLabel->hide();}
}

CarCard::~CarCard()
{
    delete ui;
}

Car *CarCard::GetCarObject() const
{
    return m_carObject;
}
