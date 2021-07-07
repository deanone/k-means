#ifndef POINT_H
#define POINT_H

#include "DataTypes.h"

class Point
{
	int ID;			
	DoubleVector v; 

public:
	/*!
	 * Default constructor.
	 */
	Point();

	/*!
	 * Destructor.
	 */
	~Point();

	/*! 
	 * Sets the ID of the Point.
	 * @param ID the ID of the Point.
	 */
	void setID(int ID);

	/*!
	 * Returns the ID of the Point. 
	 * @return the ID of the Point.
	 */
	int getID() const;

	/*! 
	 * Adds a value to the internal vector of the Point.
	 * @param value the value to be added. 
	 */
	void addValue(double val);
	
	/*! 
	 * Returns the size of the internal vector of the Point.
	 * @return the size of the internal vector.
	 */
	size_t size();
	
	/*! 
	 * Updates a specific value of the internal vector of the Point.
     * @param index the index of the value to be updated.
     * @param the new value.
	 */
	void changeValue(int index, double val);
	
	/*! 
	 * Returns a pointer to the internal vector of the Point.
	 * @return a pointer to the internal vector of the Point.
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
	 * Prints the values of the Point in console.
	 */
	void printValuesToConsole(); 
	
	/*!
	 * Writes the values of the Point in a file.
	 */
	void writeValuesToFile(std::ostream &out); 
};

#endif	//	POINT_H