#include <iostream>
#include "Car.h"
using namespace std;

class OldCar : public Car
{
	friend bool compareOld(OldCar car1, OldCar car2); // Used for the sorting algorithm for the vector
	int mileage;

public:
	OldCar(); // Default constructor
	OldCar(string, string, string, int, double, string, string, int); // Constructor with parameters
	void setCar(string, string, string, int, double, string, string, int); // Overloading car set function and adding mileage
	int getMileage(); // return mileage
	void print(); // Overriding print function from car class
};
