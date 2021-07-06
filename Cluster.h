#ifndef CLUSTER_H
#define CLUSTER_H

#include "Point.h"

class Cluster
{
	int ID; 

public:
	std::vector<Point*> pointsOfCluster; 
	Point center; 

public:
	/*! 
	 * Constructor.
	 */
	Cluster(Point c, int id);
	
	/*!
	 * Destructor.
	 */
	~Cluster();

	/*! 
	 * Sets the ID of the Cluster.
	 * @param ID the ID of the Cluster.
	 */
	void setID(int ID);		
	
	/*!
	 * Returns the ID of the Cluster.
	 * @return the ID of the Cluster.
	 */
	int getID() const;
	
	/*! 
	 * Sets the center of the Cluster.
	 * @param center the center (i.e., a Point object) of the Cluster.
	 */
	void setCenter(Point &center);
	
	/*!
	 * Returns the center of the Cluster.
	 * @return the center (i.e., a Point object) of the Cluster.
	 */
	Point getCenter();

	/*! 
	 * Adds Points to the Cluster.
	 * @param p a Point to be added.
	 */
	void setPointsToCluster(Point *p);
	
	/*! 
	 * Returns the number of points in the Cluster.
	 * @return the number of points in the Cluster.
	 */
	size_t getNumOfPointsInCluster();
	
	/*! 
	 * Returns a Point of the Cluster for a specific index.
	 * @param index the index of the Point to be returned.
	 */
	Point* getPointOfCluster(size_t index);
	
	/*!
	 * Deletes all points of the Cluster.
	 */
	void clearPointsOfCluster();
	
	/*!
	 * == operator overloading function.
	 * @param c a reference to the rhs Cluster.
	 */
	bool operator==(Cluster &c);
	
	/*!
	 * < operator overloading function.
	 * @param c a reference to the rhs Cluster.
	 */
	bool operator<(Cluster &c);

	/*!
	 * Prints the centroid of the Cluster to console.
	 */
	void printCentroidInConsole();
	
	/*!
	 * Prints the ids of the points of Cluster to console.
	 */
	void printAllocationInConsole();
	
	/*!
	 * Writes the centroid of the Cluster to file.
	 * @param out the stream handle of the output file.
	 */
	void writeCentroidToFile(std::ostream &out);
	
	/*!
	 * Writes the ids of the points of Cluster to file.
	 * @param out the stream handle of the output file.
	 */
	void writeAllocationToFile(std::ostream &out);
};

#endif	//	CLUSTER_H