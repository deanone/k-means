#ifndef POINT_H
#define POINT_H

#include "DataTypes.h"

class Point
{
	int ID;			
	DoubleVector v; 

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
	 * @param _ID the ID of the point.
	 */
	void setID(int _ID);

	/*!
	 * Getter of the ID of the point. 
	 * @return the ID of the point.
	 */
	int getID();

	/*! 
	 * Adds a value to the internal vector of the point.
	 * @param value the value to be added. 
	 */
	void addValue(double val);
	
	/*! 
	 * Getter of the size of the internal vector of the point.
	 * @return the size of the internal vector.
	 */
	size_t size();
	
	/*! 
	 * Updates a specific value of the internal vector of the point.
     * @param index the index of the value to be updated.
     * @param the new value.
	 */
	void changeValue(int index, double val);
	
	/*! 
	 * Getter of a pointer to the internal vector of the point.
	 * @return a pointer to the internal vector of the point.
	 */
	DoubleVector* values();

	/*!
     * + operator overloading function.
     * @param p a reference to the rhs point.
     * @return a new point as the sum.
	 */
	Point operator+(const Point &p);
	
	/*!
     * = operator overloading function.
     * @param p a reference to the rhs point.
     * @return a point to be assigned to the lhs.
	 */
	Point operator=(const Point &p);
	
	/*!
     * == operator overloading function.
     * @param p a reference to the rhs Point.
     * @return true if the points are equal, false otherwise.
	 */
	bool operator==(const Point &p);
	
	/*!
     * < operator overloading function.
     * @param p a reference to the rhs Point.
     * @return true if the lhs point is less than the rhs point, false otherwise.
	 */
	bool operator<(const Point &p);
	
	/*!
     * / operator overloading function (Point object with integer).
     * @param m the integer by which all the values of the internal vector of the point are divided.
	 * @return a point as the result of the division of the input point with the integer.
	 */
	Point operator/(int m);

	/*!
     * () Returns the value of the internal vector of the point that corresponds to the given index.
     * @param index the index of the value to be returned.
     * @return the value of the point indexed by the input index.
	 */
	double operator()(size_t index);
	
	/*! 
	 * Prints the values of the point in console.
	 */
	void printValuesToConsole(); 
	
	/*!
	 * Writes the values of the point in a file.
	 */
	void writeValuesToFile(std::ostream &out); 
};

#endif	// POINT_H