#ifndef H_Car
#define H_Car
#include <iostream>
using namespace std;

class Car
{
	string VIN, make, model, category, color;
	int year;
	double price;

public:
	Car(); // Default constructor
	Car(string, string, string, int, double, string, string); // Constructor with parameters
	void print(); // print function
	void setCar(string, string, string, int, double, string, string); // Set the data members of the car
	string getVIN(); // return Vin
	string getMake(); // return make
	string getModel(); // return model
	int getYear(); // return year
	double getPrice(); // return price
	string getCategory(); // return category
	string getColor(); // return color
	~Car() {}; // Destructor
	
};
#endif