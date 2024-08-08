#ifndef FILTER_H
#define FILTER_H

#include "car.h"
#include "carcard.h"
class Filter : public QObject
{
public:
    Filter(std::vector<CarCard*> &cardVector, QObject *parent);
public slots:
    void FilterCards(int _);
    void SetTonnageFilter(bool isActive);
    void SetTonnageMin(int tonnageMin);
    void SetColorFilter(bool isActive);
    void SetSilver(bool isActive);
    void SetBlue(bool isActive);
    void SetRed(bool isActive);
    void SetBlack(bool isActive);
    void SetWhite(bool isActive);
    void SetBrown(bool isActive);
    void SetEngineTypeFilter(bool isActive);
    void SetDieselEngine(bool isActive);
    void SetGasEngine(bool isActive);
    void SetElectricEngine(bool isActive);
    void SetPriceFilter(bool isActive);
    void SetPriceMax(int priceMax);
    void SetPriceMin(int priceMin);
    void SetSeatAmountFilter(bool isActive);
    void SetSeatAmount(int seatAmount);
private:
    bool m_tonnageFilter = false;
    int m_tonnageMin = 0;
    bool m_colorFilter = false;
    bool m_engineTypeFilter = false;
    bool m_priceFilter = false;
    int m_priceMax = 100000;
    int m_priceMin = 0;
    bool m_seatFilter = false;
    int m_seatAmount = 0;

    bool m_colors[int(Colors::LastItem)];
    bool m_engineTypes[int(EngineTypes::LastItem)];

    std::vector<CarCard*>* m_cardVector;
};

#endif // FILTER_H
