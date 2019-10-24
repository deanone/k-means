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
	 * Setter of the ID of the cluster.
	 * @param _ID the ID of the cluster.
	 */
	void setID(int _ID);		
	
	/*!
	 * Getter of the ID of the cluster.
	 * @return the ID of the cluster.
	 */
	int getID();
	
	/*! 
	 * Setter of the center of the cluster.
	 * @param _center the center (i.e. a Point object) of the cluster.
	 */
	void setCenter(Point &_center);
	
	/*!
	 * Getter of the center of the cluster.
	 * @return the center (i.e. a Point object) of the cluster.
	 */
	Point getCenter();

	/*! 
	 * This function adds Points to the cluster.
	 * @param p a Point to be added.
	 */
	void setPointsToCluster(Point *p);
	
	/*! 
	 * Getter of the number of points in this cluster.
	 * @return the number of points in the cluster.
	 */
	size_t getNumOfPointsInCluster();
	
	/*! 
	 * Getter of a Point of the cluster for a specific index.
	 * @param index the index of the Point to be returned.
	 */
	Point* getPointOfCluster(size_t index);
	
	/*!
	 * Deletes all points of the cluster.
	 */
	void clearPointsOfCluster();
	
	/*!
	 * == operator overloading function.
	 * @param c a reference to the rhs cluster.
	 */
	bool operator==(Cluster &c);
	
	/*!
	 * < operator overloading function.
	 * @param c a reference to the rhs cluster.
	 */
	bool operator<(Cluster &c);

	/*!
	 * Prints the centroid of the cluster to console.
	 */
	void printCentroidInConsole();
	
	/*!
	 * Prints the ids of the points of cluster to console.
	 */
	void printAllocationInConsole();
	
	/*!
	 * Writes the centroid of the cluster to file.
	 * @param out the stream handle of the output file.
	 */
	void writeCentroidToFile(std::ostream &out);
	
	/*!
	 * Writes the ids of the points of cluster to file.
	 * @param out the stream handle of the output file.
	 */
	void writeAllocationToFile(std::ostream &out);
};

#endif	//	CLUSTER_H