#ifndef POINT_H
#define POINT_H

#include "DataTypes.h"

class Point
{
	int ID;			
	DoubleVector values; 

public:
	/*!
	 * Default Constructor.
	 */
	Point();

	/*!
	 * Destructor.
	 */
	~Point();

	/*! 
	 * Setter of the ID of the point.
	 * @param _ID the ID of the point
	 */
	void setID(int _ID);

	/*!
	 * Getter of the ID of the point. 
	 * @return the ID of the point.
	 */
	int getID();

	/*! 
	 * This function adds a value to the internal vector of the point.
	 * @param value the value to be added. 
	 */
	void addValue(double value);

	/*! 
	 * Getter of a value from internal vector of the point. 
	 * @param index the index of the value to be returned.
	 * @return the returned value.
	 */
	double getValue(int index);
	
	/*! 
	 * Getter of the size of the internal vector of the point.
	 * @return the size of the internal vector.
	 */
	int getValuesSize();
	
	/*! 
	 * This function updates a specific value of the internal vector of the point.
     * @param index the index of the value to be updated.
     * @param the new value.
	 */
	void changeValue(int index, double newValue);
	
	/*! 
	 * Getter of a pointer to the internal vector of the point.
	 * @return a pointer to the internal vector of the point.
	 */
	DoubleVector* getValues();

	/*!
     * + operator overloading function.
     * @param p a reference to the rhs Point.
	 */
	Point operator+(const Point &p);
	
	/*!
     * = operator overloading function.
     * @param p a reference to the rhs Point.
	 */
	Point operator=(const Point &p);
	
	/*!
     * == operator overloading function.
     * @param p a reference to the rhs Point.
	 */
	bool operator==(const Point &p);
	
	/*!
     * < operator overloading function.
     * @param p a reference to the rhs Point.
	 */
	bool operator<(const Point &p);
	
	/*!
     * / operator overloading function (Point object with integer).
     * @param the integer by which all the values of the internal vector of the point are divided.
	 */
	Point operator/(int m);
	
	/*! 
	 * This function prints the values of the point in console.
	 */
	void printValuesToConsole(); 
	
	/*!
	 * This function writes the values of the point in a file.
	 */
	void writeValuesToFile(std::ostream &out); 
};

#endif	// POINT_H