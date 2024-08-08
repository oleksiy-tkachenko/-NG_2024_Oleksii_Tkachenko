#ifndef CARCARD_H
#define CARCARD_H

#include "car.h"

#include <QWidget>

namespace Ui {
class CarCard;
}

class CarCard : public QWidget
{
    Q_OBJECT

public:
    explicit CarCard(Car *carObject, QWidget *parent = nullptr);
    ~CarCard();
    Car *GetCarObject() const;

private:
    Car *m_carObject;
    Ui::CarCard *ui;
};


#endif // CARCARD_H
