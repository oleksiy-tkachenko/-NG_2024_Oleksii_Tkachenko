#include "filter.h"


Filter::Filter(std::vector<CarCard*> &cardVector, QObject *parent) : QObject(parent)
{
    m_cardVector = &cardVector;
}

void Filter::FilterCards(int _)
{
    for(int vectorPosition = 0;vectorPosition < m_cardVector->size();vectorPosition++)
    {
        CarCard* currentCarCard = m_cardVector->at(vectorPosition);
        Car* currentCarObject = currentCarCard->GetCarObject();
        if(m_tonnageFilter)
        {
            if(currentCarObject->GetTonnage() < m_tonnageMin)
            {
                currentCarCard->hide();
                continue;
            }
        }
        if(m_colorFilter)
        {
            if(!m_colors[int(currentCarObject->GetColor())])
            {
                currentCarCard->hide();
                continue;
            }
        }
        if(m_engineTypeFilter)
        {
            if(!m_engineTypes[int(currentCarObject->GetEngineType())])
            {
                currentCarCard->hide();
                continue;
            }
        }
        if(m_priceFilter)
        {
            int currentPrice = currentCarObject->GetPrice();
            if(m_priceMin > currentPrice || currentPrice > m_priceMax)
            {
                currentCarCard->hide();
                continue;
            }
        }
        if(m_seatFilter)
        {
            if(currentCarObject->GetSeatAmount() != m_seatAmount){
                currentCarCard->hide();
                continue;
            }
        }
        currentCarCard->show();

    }
}

void Filter::SetTonnageFilter(bool isActive)
{
    m_tonnageFilter = isActive;
}
void Filter::SetTonnageMin(int tonnageMin)
{
    m_tonnageMin = tonnageMin;
}

void Filter::SetColorFilter(bool isActive)
{
    m_colorFilter = isActive;
}
void Filter::SetSilver(bool isActive)
{
    m_colors[int(Colors::Silver)] = isActive;
}
void Filter::SetBlue(bool isActive)
{
    m_colors[int(Colors::Blue)] = isActive;
}
void Filter::SetRed(bool isActive)
{
    m_colors[int(Colors::Red)] = isActive;
}
void Filter::SetBlack(bool isActive){
    m_colors[int(Colors::Black)] = isActive;
}
void Filter::SetWhite(bool isActive)
{
    m_colors[int(Colors::White)] = isActive;
}
void Filter::SetBrown(bool isActive)
{
    m_colors[int(Colors::Brown)] = isActive;
}

void Filter::SetEngineTypeFilter(bool isActive)
{
    m_engineTypeFilter = isActive;
}
void Filter::SetDieselEngine(bool isActive)
{
    m_engineTypes[int(EngineTypes::Diesel)] = isActive;
}
void Filter::SetGasEngine(bool isActive)
{
    m_engineTypes[int(EngineTypes::Gas)] = isActive;
}
void Filter::SetElectricEngine(bool isActive)
{
    m_engineTypes[int(EngineTypes::Electric)] = isActive;
}

void Filter::SetPriceFilter(bool isActive)
{
    m_priceFilter = isActive;
}
void Filter::SetPriceMin(int priceMin)
{
    m_priceMin = priceMin;
}
void Filter::SetPriceMax(int priceMax)
{
    m_priceMax = priceMax;
}

void Filter::SetSeatAmountFilter(bool isActive)
{
    m_seatFilter = isActive;
}
void Filter::SetSeatAmount(int seatAmount)
{
    m_seatAmount = seatAmount;
}
