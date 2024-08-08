#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "car.h"
#include "carcard.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void AddCarCard(Car *carObject);

private:
    Ui::MainWindow *ui;
    std::vector<CarCard*> *m_cardVector;
};
#endif // MAINWINDOW_H
