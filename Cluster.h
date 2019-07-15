#ifndef CLUSTER_H
#define CLUSTER_H

#include "Point.h"

class Cluster
{
	/*! ID of the cluster. */
	int ID; 

public:
	/*! Points of the cluster. */
	std::vector<Point*> pointsOfCluster; 
	/*! Center of the cluster. */
	Point center; 

public:
	/*! Constructor. */
	Cluster(Point c, int id);
	/*! Destructor. */
	~Cluster();

	/*! Sets the ID of the cluster. */
	void setID(int ID);		
	/*! Returns the ID of the cluster. */
	int getID();
	/*! Sets the center of the cluster. */
	void setCenter(Point& center);
	/*! Returns center of the cluster. */
	Point getCenter();

	/*! Adds point to the set of the points consisting the cluster. */
	void setPointsToCluster(Point *p);
	/*! Returns the number of points in this cluster. */
	int getNumOfPointsInCluster();
	/*! Returns a point of the cluster for the specific index. */
	Point* getPointOfCluster(int index);
	/*! Delete points of cluster. */
	void clearPointsOfCluster();
	
	/*! Overloaded operators functions. */
	bool operator==(Cluster &c);
	bool operator<(Cluster &c);

	/*! Prints the centroid of the cluster to console. */
	void printCentroidInConsole();
	/*! Prints the ids of the points of cluster to console. */
	void printAllocationInConsole();
	/*! Writes the centroid of the cluster to file. */
	void writeCentroidToFile(std::ostream &out);
	/*! Writes the ids of the points of cluster to file */
	void writeAllocationToFile(std::ostream &out);
};

#endif