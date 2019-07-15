#ifndef Point_H
#define Point_H

#include "DataTypes.h"

class Point
{
	/*! ID of the point. */
	int ID;			
	/*! Values of the point. */
	DoubleVector values; 

public:
	/*! Constructor. */
	Point();
	/*! Destructor. */
	~Point();

	/*! Sets the ID of the point. */
	void setID(int ID);
	/* Returns the ID of the point. */
	int getID();

	/*! Add value to the values vector of the point. */
	void addValue(double value);
	/*! Get a value from the values vector of the point, for a specific index. */
	double getValue(int index);
	/*! Get the size of the values vector of the point. */
	int getValuesSize();
	/*! Change a value of the values vector of the point, at a specific index. */
	void changeValue(int index, double newValue);
	/*! Get a pointer to the values vector of the point. */
	DoubleVector* getValues();

	/*! Overloaded operators functions. */
	Point operator+(const Point &p);
	Point operator=(const Point &p);
	bool operator==(const Point &p);
	bool operator<(const Point &p);
	Point operator/(int m);
	
	/*! prints the values of the point in console. */
	void printValuesToConsole(); 
	/*! prints the values of the point in a file. */
	void writeValuesToFile(std::ostream &out); 

};

#endif