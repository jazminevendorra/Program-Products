/*
Jazmin Even Dorra

products.cpp

Driver program for the fillowing classes 
	- Products : Base class
		- Books : derived from Products
		- Movies : derived from Products and aggreagate from ratings
			- Ratings
*/

//Header files
#include <iostream>
#include <string>
#include <exception>
#include "Product.h"

using namespace std;

//Main
int main()
{
	// Constants & variables
	const int SIZE = 4;

	// Array of product pointers
	Product* products[SIZE];



	// Intro
	cout << "\nBooks and Movies ... \n";

	// Dynamically allocate books and movies
	try
	{
		// Allocate array members
		products[0] = new Book("El Ingenioso Hidalgo Don Quijote de la Mancha" , "Miguel de Cervantes Saavedra", 
			"Imprenta de Juan de la Cuesta", 12.25);
			
		// Allocate array members
		products[1] = new Book("Legend", "Marie Lu", "Putnam Juvenile", 7.53);
		
		// Allocate array members
		products[2] = new Movie("Indiana Jones: Raiders of the Lost Arc", 1.0 , 1981, 8.5, 96);

		// Allocate array members
		products[3] = new Movie("The Hobbit", 2.54, 2012, 7.8, 83);
		
		
	}
	catch (exception& e)
	{
		// to see what type of error there was
		cout << "Standard Error ..." << e.what() << endl;		//what is going to display what the error is as a string
	}

	// Step through array elements & display them
	for (int i = 0; i < SIZE; i++)
	{
		products[i]->dispProduct();
	}

	// Delete memory
	for (int i = 0; i < SIZE; i++)
	{
		delete products[i];
	}
	return 0;
}