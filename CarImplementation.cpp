#include <iostream>
#include <string>
#include "Car.h"
using namespace std;


Car::Car()
{
	VIN = "AA111";
	make = "FORD";
	model = "EDGE";
	year = 2017;
	price = 15000.00;
	category = "NEW";
	color = "WHITE";
}

Car::Car(string num, string ma, string mo, int yr, double cost, string cat, string clr)
{
	VIN = num;
	make = ma;
	model = mo;
	if (yr >= 1990 && yr <= 2019)
		year = yr;
	else
		year = 2017;
	if (cost >= 0)
		price = cost;
	else
		price = 15000.00;
	category = cat;
	color = clr;
}

void Car::setCar(string num, string ma, string mo, int yr, double cost, string cat, string clr)
{
	VIN = num;
	make = ma;
	model = mo;
	if (yr >= 1990 && yr <= 2019)
		year = yr;
	else
		year = 2017;
	if (cost >= 0)
		price = cost;
	else
		price = 15000.00;
	category = cat;
	color = clr;
}

string Car::getVIN()
{
	return VIN;
}

string Car::getMake()
{
	return make;
}

string Car::getModel()
{
	return model;
}

int Car::getYear()
{
	return year;
}

double Car::getPrice()
{
	return price;
}

string Car::getColor()
{
	return color;
}

string Car::getCategory()
{
	return category;
}

void Car::print()
{
	if (make.length() <= 7)
	{
		cout << make << "\t\t" << model
			<< "\t" << VIN << "\t" << year
			<< "\t$" << price << "\t" << color
			<< "\t" << category;
	}
	else
	{
		cout << make << "\t" << model
			<< "\t" << VIN << "\t" << year
			<< "\t$" << price << "\t" << color
			<< "\t" << category;
	}
}