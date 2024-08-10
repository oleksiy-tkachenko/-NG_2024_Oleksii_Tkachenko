#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "filter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Car Manager");
    m_cardVector = new std::vector<CarCard*>;
    Car *newCar = new Car(5000, EngineTypes::Electric, Colors::Silver, 4);
    Car *newCar1 = new Car(8000, EngineTypes::Diesel, Colors::Blue, 2);
    AddCarCard(newCar);
    AddCarCard(newCar1);
    AddCarCard(new Car(1000,EngineTypes::Electric,Colors::Red, 5));
    AddCarCard(new Car(30000, EngineTypes::Gas, Colors::White, 3));
    AddCarCard(new Car(80000, EngineTypes::Gas, Colors::Red, 1));
    AddCarCard(new Truck(15000, EngineTypes::Gas, Colors::Black, 6, 300));
    AddCarCard(new Truck(10000, EngineTypes::Diesel, Colors::Brown, 10, 500));

    //Trying to see "validator" in use
    AddCarCard(new Truck(7000, EngineTypes::Electric, Colors::Brown, 8, 100));

    Filter *filter = new Filter(*m_cardVector, ui->centralwidget);

    //making sliders and spinbox synchronized
    connect (ui->seatSlider, &QAbstractSlider::valueChanged, ui->seatSpinBox, &QSpinBox::setValue);
    connect (ui->seatSpinBox, &QSpinBox::valueChanged, ui->seatSlider, &QAbstractSlider::setValue);
    connect (ui->tonnageSlider, &QAbstractSlider::valueChanged, ui->tonnageSpinBox, &QSpinBox::setValue);
    connect (ui->tonnageSpinBox, &QSpinBox::valueChanged, ui->tonnageSlider, &QAbstractSlider::setValue);
    connect (ui->lessThanPriceSlider, &QAbstractSlider::valueChanged, ui->lessThanPriceSpinBox, &QSpinBox::setValue);
    connect (ui->lessThanPriceSpinBox, &QSpinBox::valueChanged, ui->lessThanPriceSlider, &QAbstractSlider::setValue);
    connect (ui->moreThanPriceSlider, &QAbstractSlider::valueChanged, ui->moreThanPriceSpinBox, &QSpinBox::setValue);
    connect (ui->moreThanPriceSpinBox, &QSpinBox::valueChanged, ui->moreThanPriceSlider, &QAbstractSlider::setValue);

    //updating filter numbers with sliders(and spinboxes)
    connect (ui->tonnageSlider, &QAbstractSlider::valueChanged, filter, &Filter::SetTonnageMin);
    connect (ui->lessThanPriceSlider, &QAbstractSlider::valueChanged, filter, &Filter::SetPriceMax);
    connect (ui->moreThanPriceSlider, &QAbstractSlider::valueChanged, filter, &Filter::SetPriceMin);
    connect (ui->seatSlider, &QAbstractSlider::valueChanged, filter, &Filter::SetSeatAmount);

    //checkbox with bool values connection
    connect (ui->tonnageFilter, &QCheckBox::checkStateChanged, filter, &Filter::SetTonnageFilter);
    connect (ui->colorFilter, &QCheckBox::checkStateChanged, filter, &Filter::SetColorFilter);
    connect (ui->silverCheck, &QCheckBox::checkStateChanged, filter, &Filter::SetSilver);
    connect (ui->blueCheck, &QCheckBox::checkStateChanged, filter, &Filter::SetBlue);
    connect (ui->redCheck, &QCheckBox::checkStateChanged, filter, &Filter::SetRed);
    connect (ui->blackCheck, &QCheckBox::checkStateChanged, filter, &Filter::SetBlack);
    connect (ui->whiteCheck, &QCheckBox::checkStateChanged, filter, &Filter::SetWhite);
    connect (ui->brownCheck, &QCheckBox::checkStateChanged, filter, &Filter::SetBrown);
    connect (ui->engineFilter, &QCheckBox::checkStateChanged, filter, &Filter::SetEngineTypeFilter);
    connect (ui->dieselCheck, &QCheckBox::checkStateChanged, filter, &Filter::SetDieselEngine);
    connect (ui->gasCheck, &QCheckBox::checkStateChanged, filter, &Filter::SetGasEngine);
    connect (ui->electricCheck, &QCheckBox::checkStateChanged, filter, &Filter::SetElectricEngine);
    connect (ui->priceFilter, &QCheckBox::checkStateChanged, filter, &Filter::SetPriceFilter);
    connect (ui->seatFilter, &QCheckBox::checkStateChanged, filter, &Filter::SetSeatAmountFilter);

    //checkbox connections that make filtered items appear/disappear
    //back if you disable/enable some type of filters
    connect (ui->tonnageFilter, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->colorFilter, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->silverCheck, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->blueCheck, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->redCheck, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->blackCheck, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->whiteCheck, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->brownCheck, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->engineFilter, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->dieselCheck, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->gasCheck, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->electricCheck, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->priceFilter, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);
    connect (ui->seatFilter, &QCheckBox::checkStateChanged, filter, &Filter::FilterCards);

    //slider filter connections
    connect (ui->tonnageSlider, &QAbstractSlider::valueChanged, filter, &Filter::FilterCards);
    connect (ui->lessThanPriceSlider, &QAbstractSlider::valueChanged, filter, &Filter::FilterCards);
    connect (ui->moreThanPriceSlider, &QAbstractSlider::valueChanged, filter, &Filter::FilterCards);
    connect (ui->seatSlider, &QAbstractSlider::valueChanged, filter, &Filter::FilterCards);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_cardVector;
}

void MainWindow::AddCarCard(Car *carObject)
{
    CarCard *newCard = new CarCard(carObject);
    ui->cardTable->addWidget(newCard, m_cardVector->size()/3, m_cardVector->size() % 3);
    m_cardVector->push_back(newCard);
}
