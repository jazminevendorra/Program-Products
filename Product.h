/*

Implementation file for classes

*/
#pragma once

//Header
#include <iostream>
#include <exception>
#include <iomanip>
#include <string>

using namespace std;

class Product
{
protected:
	string name;
	double price;
public:
	// Constructor
	Product()
	{
		name = "";
		price = 0.0;
	}
	Product(string n, double prc)
	{
		name = n;
		price = prc;

	}
	// Virtual function
	virtual void dispProduct() = 0;
};

class Book : public Product
{
private:
	string author;
	string publisher;
public:
	Book(string n, string a, string pub, double prc)
	{
		name = n;
		price = prc;
		author = a;
		publisher = pub;
	}
	virtual void dispProduct()
	{
		cout << "\nBook information: \n"
			<< "\tTitle: " << name
			<< "\n\tAuthor: " << author
			<< "\n\tPublisher: " << publisher
			<< "\n\tPrice: $" << price << endl;
	}
};


class Ratings 
{
protected:
	double IMDb;
	int rottenTomatoes;
public:
	//Constructor
	Ratings()
	{
		IMDb = 0;
		rottenTomatoes = 0;
	}
	//Accessors
	double getIMDb()
	{
		return IMDb;
	}
	int getRottenTomatoes()
	{
		return rottenTomatoes;
	}
	// Mutators
	void setIMDb(double ir)
	{
		if (ir > 0.0 && ir < 11.0)
		{
			IMDb = ir;
		}
		else
		{
			string invalidIr = "Invalid IMDb rating ...";
			throw invalidIr;

		}

	}
	void setRottenTomatoes(int tr)
	{
		if (tr >= 0 && tr <= 100)
		{
			rottenTomatoes = tr;
		}
		else
		{
			string invalidTr = "Invalid Rotten Tomatoes rating ...";
			throw invalidTr;
			
		}
	}
};


class Movie : public Product
{
protected:
	int year;
	Ratings rating;
public:
	// Constructor
	Movie(string n, double prc, int y, double ir, int tr)
	{
		if (y < 0)
		{
			throw exception("Invalid Year");
		}
		else 
		{
			try
			{
				name = n;
				price = prc;
				year = y;
				rating.setIMDb(ir);
				rating.setRottenTomatoes(tr);
			}
			catch (const std::exception&)
			{
				throw;
			}

		}
	}

		
	virtual void dispProduct()
	{
		cout << "\nMovie information: \n"
			<< "\tTitle: " << name
			<< "\n\tYear: " << year
			<< "\n\tPrice: $" << price
			<< "\n\tRatings: "
			<< "\n\t\tRotten Tomatoes: " << rating.getRottenTomatoes()
			<< "\n\t\tIMDb: " << rating.getIMDb() << endl;
	}
};
