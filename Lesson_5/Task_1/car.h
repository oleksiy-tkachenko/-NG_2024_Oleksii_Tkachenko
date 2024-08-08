#ifndef CAR_H
#define CAR_H
#include <QString>

/*enum class CarTypes
{
    SUV,
    Hatchback,
    Crossover,
    Convertible,
    Sedan,
    SportsCar,
    Coupe,
    Minivan,
    StationWagon,
    PickupTruck
};*/

enum class EngineTypes
{
    Electric,
    Diesel,
    Gas,
    LastItem
};

enum class Colors
{
    Silver,
    Blue,
    Red,
    Black,
    White,
    Brown,
    LastItem
};

/*enum class CarBrands
{
    Ford,
    Wolkswagen,
    KIA,
    Porsche,
    Renault,
    BMW,
    Toyota
};*/

class Machine
{
public:
    Machine(int price, EngineTypes engineType);

    int GetPrice() const;
    EngineTypes GetEngineType() const;
    virtual QString GetName() const;
    virtual int GetTonnage() const;

    void SetPrice(int price);
    virtual void SetEngineType(EngineTypes engineType);

protected:
    EngineTypes m_engineType;
private:
    int m_price;
};

class Car : public Machine
{
public:
    Car(int price, EngineTypes engineType, Colors color, int seatAmount);

    Colors GetColor() const;
    int GetSeatAmount() const;
    QString GetName() const override;

    void SetColor(Colors color);
    void SetSeatAmount(int seatAmount);

protected:
    Colors m_color;
    int m_seatAmount;
};

class Truck : public Car
{
public:
    Truck(int price, EngineTypes engineType, Colors color, int seatAmount, int tonnage);

    int GetTonnage() const override;
    QString GetName() const override;

    void SetTonnage(int newTonnage);
    void SetEngineType(EngineTypes engineType) override;

private:
    int m_tonnage;
};

#endif // CAR_H
