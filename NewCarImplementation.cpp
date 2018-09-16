#include <iostream>
#include "Car.h"
#include "NewCar.h"
#include <string>
using namespace std;

NewCar::NewCar()
{
	warranty = "DEALER";
}

NewCar::NewCar(string num, string ma, string mo, int yr, double cost, string cat, string clr, string warr) :
	Car(num, ma, mo, yr, cost, cat, clr)
{
	warranty = warr;
}

void NewCar::setCar(string num, string ma, string mo, int yr, double cost, string cat, string clr, string warr)
{
	Car::setCar(num, ma, mo, yr, cost, cat, clr);
	warranty = warr;
}

string NewCar::getWarranty()
{
	return warranty;
}

void NewCar::print()
{
	Car::print();
	cout << "\t\t" << warranty << endl;
}

bool compareNew(NewCar car1, NewCar car2)
{
	if (car1.getMake() != car2.getMake())
		return car1.getMake() < car2.getMake();
	else
		return car1.getModel() < car2.getModel();
}