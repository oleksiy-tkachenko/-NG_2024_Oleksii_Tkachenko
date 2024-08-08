#include "car.h"


Machine::Machine(int price, EngineTypes engineType)
{
    SetPrice(price);
    SetEngineType(engineType);
}

int Machine::GetPrice() const
{
    return m_price;
}
EngineTypes Machine::GetEngineType() const
{
    return m_engineType;
}
QString Machine::GetName() const
{
    return "Machine";
}
int Machine::GetTonnage() const
{
    return 0;
}

void Machine::SetPrice(int price)
{
    m_price = price;
}
void Machine::SetEngineType(EngineTypes engineType)
{
    m_engineType = engineType;
}


Car::Car(int price, EngineTypes engineType, Colors color, int seatAmount) : Machine(price, engineType)
{
    SetColor(color);
    SetSeatAmount(seatAmount);
}

Colors Car::GetColor() const
{
    return m_color;
}
int Car::GetSeatAmount() const
{
    return m_seatAmount;
}
QString Car::GetName() const
{
    return "Car";
}

void Car::SetSeatAmount(int seatAmount)
{
    m_seatAmount = seatAmount;
}
void Car::SetColor(Colors color)
{
    m_color = color;
}


Truck::Truck(int price, EngineTypes engineType, Colors color, int seatAmount, int tonnage) : Car(price, engineType, color, seatAmount)
{
    SetTonnage(tonnage);
    SetEngineType(engineType);
}

int Truck::GetTonnage() const
{
    return m_tonnage;
}
QString Truck::GetName() const
{
    return "Truck";
}

void Truck::SetTonnage(int tonnage)
{
    m_tonnage = tonnage;
}
void Truck::SetEngineType(EngineTypes engineType)
{
    if (engineType != EngineTypes::Diesel || engineType != EngineTypes::Gas){
        m_engineType = EngineTypes::Diesel;
        return;
    }
    m_engineType = engineType;
}
