#include <iostream>
#include "Car.h"
using namespace std;

class NewCar : public Car
{
	friend bool compareNew(NewCar car1, NewCar car2); // Used in the vector sorting algorithm
	string warranty;

public:
	NewCar(); // Default constructor
	NewCar(string, string, string, int, double, string, string, string); // Constructor with parameters
	void setCar(string, string, string, int, double, string, string, string); // Overloading car set function and adding warranty
	string getWarranty(); // return warranty
	void print(); // Overriding print function from car class
};

