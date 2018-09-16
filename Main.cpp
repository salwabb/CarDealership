#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include "Car.h"
#include "NewCar.h"
#include "OldCar.h"
using namespace std;

// Formatting output for new cars
void oldCarOutput(vector<OldCar> &oldv)
{
	int count = 1;
	sort(oldv.begin(), oldv.end(), compareOld); // sorting cars based on make
	cout << "\t\t\t\t**OLD CARS**" << endl 
		<< "\tMAKE \t\tMODEL \tVIN \tYEAR \tPRICE \tCOLOR \tCATEGORY \tMILEAGE" << endl
		<< "-------------------------------------------------------------"
		<<	"---------------------------" << endl;
	for (int i = 0; i < oldv.size(); i++)
	{
		cout << "Car " << count << ":\t";
		oldv[i].print();
		count++;
	}
}

// Formatting output for old cars
void newCarOutput(vector<NewCar> &newv)
{
	int count = 1;
	sort(newv.begin(), newv.end(), compareNew); // sortig cars based on make
	cout << "\t\t\t\t**NEW CARS**" << endl 
		<<  "\tMAKE \t\tMODEL \tVIN \tYEAR \tPRICE \tCOLOR \tCATEGORY \tWARRANTY" << endl
		<< "----------------------------------------------------------"
		<< "------------------------------" << endl;
	for (int i = 0; i < newv.size(); i++)
	{
		cout << "Car " << count << ":\t";
		newv[i].print();
		count++;
	}
}

// Function to output the menu
void showMenu()
{
	cout << endl << "*****WELCOME TO SALWA'S CAR DEALERSHIP*****" << endl
		<< "Please select an option: " << endl
		<< "1. Search Inventory" << endl
		<< "2. Sell/Lease Cars" << endl
		<< "3. Return a Leased Car" << endl
		<< "4. Add Cars to Inventory" << endl
		<< "5. Show Inventory" << endl
		<< "6. Get Cars within a Price Range" << endl
		<< "7. Exit" << endl;
}

// Function to search the inventory using the make, model, or category
void searchInventory(vector<NewCar> &ncar, vector<OldCar> &ocar)
{
	string str;
	vector<NewCar> tempCarN; // temp vector to store the new cars found
	vector<OldCar> tempCarO; // temp vector to store the old cars found
	int countO = 0; // counter to check if any old cars were found
	int countN = 0; // counter to check if any new cars were found

	cout << "Please enter the make, model, or category of the car you are searching for: ";
	cin >> str;
	cin.ignore(100, '\n');
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}

	// Checking for old cars with the option the user asked for
	for (int i = 0; i < ocar.size(); i++)
	{
		if (ocar[i].getMake() == str || ocar[i].getCategory() == str || ocar[i].getModel() == str)
		{
			tempCarO.push_back(ocar[i]);
			countO++;
		}
	}

	// Checking for new cars with the option the user asked for
	for (int i = 0; i < ncar.size(); i++)
	{
		if (ncar[i].getMake() == str || ncar[i].getCategory() == str || ncar[i].getModel() == str)
		{
			tempCarN.push_back(ncar[i]);
			countN++;
		}
	}

	// Ouputting the cars that were found or if no cars were found
	if (countN == 0 && str != "OLD")
		cout << "No new cars with this option have been found." << endl;
	else if (countN >= 1)
		newCarOutput(tempCarN); // Calling the formatted print function for new cars
	if (countO == 0 && str!= "NEW")
		cout << "No old cars with this option have been found." << endl;
	else if (countO >= 1)
		oldCarOutput(tempCarO); // Calling the formatted print function for old cars
}

// Function to sell or lease cars
void sellLeaseCars(vector<NewCar> &ncar, vector<OldCar> &ocar)
{
	int option;
	string strSell;
	string strLease;
	string inpStr = "Input is not of the correct data type.\nReturning to main menu.";
	bool foundSell = false; // variable to check if cars with that VIN are in the inventory to sell
	bool foundLease = false; // check if cars with that VIN are in the inventory to lease
	int count = 0; // check if user is trying to lease an old car
	try
	{
		cout << "Please choose an option: " << endl
			<< "1. Sell Car" << endl
			<< "2. Lease Car" << endl;
		cin >> option;
		cin.ignore(100, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			throw inpStr;
		}
		else if (option < 1 || option > 2) // Checking if option is invalid
			throw option;
		else if (option == 1)
		{
			cout << "Please enter the VIN number of the car you wish to sell: ";
			cin >> strSell;
			cin.ignore(100, '\n');
			
			for (int i = 0; i < strSell.length(); i++)
			{
				strSell[i] = toupper(strSell[i]); // changing to uppercase
			}

			// Deleting the car which is being sold if it is found in the old car vector
			for (vector<OldCar>::iterator it = ocar.begin(); it != ocar.end(); ++it)
			{
				if (it->getVIN() == strSell)
				{
					ocar.erase(it);
					foundSell = true;
					cout << "The car with the VIN number " << strSell << 
						" has been sold and removed from the inventory" << endl;
					break;
				}
			}
			// Deleting the car which is being sold if it is found in the new car vector
			for (vector<NewCar>::iterator it = ncar.begin(); it != ncar.end(); ++it)
			{
				if (it->getVIN() == strSell)
				{
					ncar.erase(it);
					foundSell = true;
					cout << "The car with the VIN number " << strSell << 
						" has been sold and removed from the inventory" << endl;
					break;
				}
			}
			// Outputting to the user if a car with that VIN is not found
			if (foundSell == false)
			{
				cout << "No car has been found with that VIN number" << endl;
			}
		}
		else if (option == 2)
		{
			cout << "Please enter the VIN number of the car you wish to lease: ";
			cin >> strLease;
			cin.ignore(100, '\n');

			for (int i = 0; i < strLease.length(); i++)
			{
				strLease[i] = toupper(strLease[i]); // changing to upper case
			}

		// Deleting the car which is being leased if it is found in the old car vector
		for (vector<OldCar>::iterator it = ocar.begin(); it != ocar.end(); ++it)
		{
			if (it->getVIN() == strLease)
			{
				ocar.erase(it);
				foundLease = true;
				cout << "The car with the VIN number " << strLease <<
					" has been leased and removed from the inventory" << endl;
				break;
			}
		}
		// Deleting the car which is being leased if it is found in the new car vector
		for (vector<NewCar>::iterator it = ncar.begin(); it != ncar.end(); ++it)
		{
			if (it->getVIN() == strLease)
			{
				ncar.erase(it);
				foundLease = true;
				cout << "The car with the VIN number " << strLease <<
					" has been leased and removed from the inventory" << endl;
				break;
			}
		}
		// Outputting to the user if a new car with that VIN is not found because we cannot lease old cars
		if (foundLease == false)
		{
			cout << "No car has been found with that VIN number" << endl;
		}
		}
	}
	catch (int)
	{
		cout << "Invalid Option.\nReturning to main menu." << endl;
	}
	catch (string s)
	{
		cout << s << endl;
	}
}

// Function to return leased cars
void returnLease(vector<OldCar> &ocar)
{
	// Declaring variables and asking user to input the car information
	string VIN, make, model, color;
	string inpStr = "Input is not of the correct data type.\nReturning to main menu.";
	int year, price, mileage;
	try
	{
		cout << "Vin: ";
		cin >> VIN;
		cin.ignore(100, '\n');
		for (int i = 0; i < VIN.length(); i++)
		{
			VIN[i] = toupper(VIN[i]); // Converting to uppercase
		}
		cout << "Make: ";
		cin >> make;
		cin.ignore(100, '\n');
		for (int i = 0; i < make.length(); i++)
		{
			make[i] = toupper(make[i]); // Converting to uppercase
		}
		cout << "Model: ";
		cin >> model;
		cin.ignore(100, '\n');
		for (int i = 0; i < model.length(); i++)
		{
			model[i] = toupper(model[i]);
		}
		cout << "Color: ";
		cin >> color;
		cin.ignore(100, '\n');
		for (int i = 0; i < color.length(); i++)
		{
			color[i] = toupper(color[i]);
		}
		cout << "Year: ";
		cin >> year;
		cin.ignore(100, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			throw inpStr;
		}
		cout << "Price: ";
		cin >> price;
		cin.ignore(100, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			throw inpStr;
		}
		cout << "Mileage: ";
		cin >> mileage;
		cin.ignore(100, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			throw inpStr;
		}

		// Adding the car to the old car vector
		OldCar returnedCar;
		returnedCar.setCar(VIN, make, model, year, price, "OLD", color, mileage);
		ocar.push_back(returnedCar);

		cout << "The car has been added to the inventory" << endl;
	}
	catch (string s)
	{
		cout << s << endl;
	}
}

// Funtion to add new or old cars to the inventory
void addCar(vector<NewCar> &ncar, vector<OldCar> &ocar)
{
	string cat, VIN, make, model, color, warranty;
	string wrongCat = "This is not a valid category.\nReturning to main menu.";
	string inpStr = "Input is not of the correct data type.\nReturning to main menu.";
	int year, price, mileage;
	try
	{
		cout << "Please enter the category of the car you are adding (NEW or OLD): ";
		cin >> cat;
		for (int i = 0; i < cat.length(); i++)
		{
			cat[i] = toupper(cat[i]); // Converting to uppercase
		}

		if (cat != "NEW" && cat != "OLD")
			throw wrongCat; // checking if category is wrong

		cout << "Vin: ";
		cin >> VIN;
		cin.ignore(100, '\n');
		for (int i = 0; i < VIN.length(); i++)
		{
			VIN[i] = toupper(VIN[i]); // Converting to uppercase
		}

		// Checking if the same car is already in the inventory
		for (int i = 0; i < ocar.size(); i++)
		{
			if (ocar[i].getVIN() == VIN)
				throw string("A car with that VIN is already in the inventory");
		}
		for (int i = 0; i < ncar.size(); i++)
		{
			if (ncar[i].getVIN() == VIN)
				throw string("A car with that VIN is already in the inventory");
		}
		cout << "Make: ";
		cin >> make;
		cin.ignore(100, '\n');
		for (int i = 0; i < make.length(); i++)
		{
			make[i] = toupper(make[i]); // Converting to uppercase
		}
		cout << "Model: ";
		cin >> model;
		cin.ignore(100, '\n');
		for (int i = 0; i < model.length(); i++)
		{
			model[i] = toupper(model[i]); // Converting to uppercase
		}
		cout << "Color: ";
		cin >> color;
		cin.ignore(100, '\n');
		for (int i = 0; i < color.length(); i++)
		{
			color[i] = toupper(color[i]); // Converting to uppercase
		}
		cout << "Year: ";
		cin >> year;
		cin.ignore(100, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			throw inpStr;
		}
		cout << "Price: ";
		cin >> price;
		cin.ignore(100, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			throw inpStr;
		}

		// Checking if the car is new to add warranty
		if (cat == "NEW")
		{
			cout << "Warranty: ";
			cin >> warranty;
			cin.ignore(100, '\n');
			for (int i = 0; i < warranty.length(); i++)
			{
				warranty[i] = toupper(warranty[i]);
			}
			NewCar addedCarN(VIN, make, model, year, price, "NEW", color, warranty);
			ncar.push_back(addedCarN);
			cout << "The new car has been added to the inventory" << endl;
		}
		// Checking if the car is old to add mileage
		else if (cat == "OLD")
		{
			cout << "Mileage: ";
			cin >> mileage;
			cin.ignore(100, '\n');
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				throw inpStr;
			}

			OldCar addedCarO(VIN, make, model, year, price, "OLD", color, mileage);
			ocar.push_back(addedCarO);
			cout << "The old car has been added to the inventory" << endl;
		}
	}
	catch (string s)
	{
		cout << s << endl;
	}
}

// Function to get cars within a given price range
void priceRange(vector<NewCar> &ncar, vector<OldCar> &ocar)
{
	double low, high, temp;
	string inpStr = "Input is not of the correct data type.\nReturning to main menu.";
	vector<NewCar> tempN; // temporary vector to store new cars
	vector<OldCar> tempO; // temporary vector to store old cars
	int countN = 0; // counter to check if any new cars were found
	int countO = 0; // counter to check if any old cars were found
	
	try
	{
		cout << "Please enter the lowest price you would like: ";
		cin >> low;
		cin.ignore(100, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			throw inpStr;
		}

		cout << "Please enter the highest price you would like: ";
		cin >> high;
		cin.ignore(100, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			throw inpStr;
		}
		
		// Swapping variables if user inputs higher price first
		if (low > high)
		{
			temp = low;
			low = high;
			high = temp;
		}

		// Chceking for new cars within that price range
		for (int i = 0; i < ncar.size(); i++)
		{
			if (low <= ncar[i].getPrice() && high >= ncar[i].getPrice())
			{
				tempN.push_back(ncar[i]);
				countN++;
			}
		}
		// Checking for old cars within that price range
		for (int i = 0; i < ocar.size(); i++)
		{
			if (low <= ocar[i].getPrice() && high >= ocar[i].getPrice())
			{
				tempO.push_back(ocar[i]);
				countO++;
			}
		}

		// Ouputting the cars that were found or if no cars were found
		if (countN == 0)
			cout << "No new cars have been found within this price range." << endl;
		else if (countN >= 1)
			newCarOutput(tempN); // Calling the formatted print function for new cars
		if (countO == 0)
			cout << "No old cars have beenn found within this price range." << endl;
		else if (countO >= 1)
			oldCarOutput(tempO); // Calling the formatted print function for old cars
	}
	catch (string s)
	{
		cout << s << endl;
	}
}

int main()
{
	// Declaring variables
	int option = 1;
	string inpStr = "Input is not of the correct data type.";
	vector<NewCar> newCars;
	vector<OldCar> oldCars;
	
	// Storing the new cars
	newCars.push_back(NewCar("FA112", "FORD", "FUSION", 2016, 22610, "NEW", "BLACK", "FACTORY"));
	newCars.push_back(NewCar("AA113", "CHEVROLET", "MALIBU", 2013, 18700, "NEW", "SILVER", "DEALER"));
	newCars.push_back(NewCar("AG125", "AUDI", "A6", 2017, 47600, "NEW", "RED", "FACTORY"));
	newCars.push_back(NewCar("CA218", "FORD", "MUSTANG", 2016, 25180, "NEW", "GOLD", "FACTORY"));
	newCars.push_back(NewCar("EA178", "AUDI", "Q5", 2013, 30300, "NEW", "GREY", "DEALER"));
	newCars.push_back(NewCar("AB197", "CHEVROLET", "IMPALA", 2016, 26407, "NEW", "RED", "FACTORY"));
	newCars.push_back(NewCar("AD345", "MERCEDES", "S-CLASS", 2015, 93400, "NEW", "WHITE", "DEALER"));
	newCars.push_back(NewCar("SB879", "BMW", "X6", 2015, 62000, "NEW", "SILVER", "DEALER"));
	newCars.push_back(NewCar("MA900", "MERCEDES", "AMGC63", 2014, 59800, "NEW", "BLACK", "DEALER"));
	newCars.push_back(NewCar("GV652", "BMW", "Z4", 2017, 49700, "NEW", "BLUE", "FACTORY"));

	// Storing the old cars
	oldCars.push_back(OldCar("AA119", "FORD", "ESCAPE", 2011, 12100, "OLD", "GREY", 23078));
	oldCars.push_back(OldCar("BH863", "CHEVROLET", "MALIBU", 2009, 7840, "OLD", "BLACK", 32560));
	oldCars.push_back(OldCar("HT783", "FORD", "EDGE", 2011, 11230, "OLD", "WHITE", 21000));
	oldCars.push_back(OldCar("AG909", "MERCEDES", "S-CLASS", 2015, 54300, "OLD", "RED", 7890));
	oldCars.push_back(OldCar("FM761", "AUDI", "TT", 2012, 27050, "OLD", "GREY", 43040));
	oldCars.push_back(OldCar("BM822", "BMW", "X6", 2010, 38750, "OLD", "SILVER", 100209));
	oldCars.push_back(OldCar("GH870", "MERCEDES", "B-CLASS", 2014, 21680, "OLD", "BLUE", 32000));
	oldCars.push_back(OldCar("IA802", "AUDI", "A5", 2008, 17550, "OLD", "BLACK", 99800));
	oldCars.push_back(OldCar("PL024", "CHEVROLET", "CRUISE", 2007, 3650, "OLD", "BEIGE", 123480));
	oldCars.push_back(OldCar("BS305", "BMW", "M6", 2015, 93000, "OLD", "BROWN", 12065));
	
	// Outputting the new cars
	newCarOutput(newCars);
	cout << endl;

	// Outputting the old cars
	oldCarOutput(oldCars);
	cout << endl;

	while (option != 7) // Making sure the menu appears until exit option is chosen.
	{
		try

		{
			showMenu();
			cin >> option;
			cin.ignore(100, '\n');
			if (option < 1 || option > 7)
				throw option;
			else if (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				throw inpStr;
			}

			if (option == 1)
				searchInventory(newCars, oldCars);
			else if (option == 2)
				sellLeaseCars(newCars, oldCars);
			else if (option == 3)
				returnLease(oldCars);
			else if (option == 4)
				addCar(newCars, oldCars);
			else if (option == 5)
			{
				newCarOutput(newCars);
				cout << endl;
				oldCarOutput(oldCars);
				cout << endl;
			}
			else if (option == 6)
				priceRange(newCars, oldCars);
		}
		catch (int)
		{
			cout << "Invalid option." << endl;
		}
		catch (string s)
		{
			cout << s << endl;
		}
	}

	system("pause");
	return 0;
}