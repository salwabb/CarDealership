#include "Car.h"
#include "OldCar.h"
#include <iostream>
using namespace std;

OldCar::OldCar()
{
	mileage = 1000;
}

OldCar::OldCar(string num, string ma, string mo, int yr, double cost, string cat, string clr, int miles) :
	Car(num, ma, mo, yr, cost, cat, clr)
{
	if (miles >= 0)
		mileage = miles;
	else
		mileage = 1000;
}

void OldCar::setCar(string num, string ma, string mo, int yr, double cost, string cat, string clr, int miles)
{
	Car::setCar(num, ma, mo, yr, cost, cat, clr);
	if (miles >= 0)
		mileage = miles;
	else
		mileage = 1000;
}

int OldCar::getMileage()
{
	return mileage;
}

void OldCar::print()
{
	Car::print();
	cout << "\t\t" << mileage << endl;
}

bool compareOld(OldCar car1, OldCar car2)
{
	if (car1.getMake() != car2.getMake())
		return car1.getMake() < car2.getMake();
	else
		return car1.getModel() < car2.getModel();
}