#ifndef MF_H
#define MF_H

#include "Point.h"

namespace mf
{
	/*! Functions for calculating classic distance metrics between points. */
	double findEuclideanDistanceOfPoints(Point &p1, Point &p2);
	double findEuclideanSquaredDistanceOfPoints(Point &p1, Point &p2); //Euclidean distance without sqrt
	double findManhattanDistanceOfPoints(Point &p1, Point &p2);
	double findChebysevDistanceOfPoints(Point &p1, Point &p2);	
	// double dotProduct(Point &p1, Point &p2);
	double findCosineSimilarityOfPoints(Point &p1, Point &p2);
	double meanOfPoint(Point &p);
	double stDevOfPoint(Point &p);
	double findPearsonCorrelationOfPoints(Point &p1, Point &p2);
	double findBrayCurtisDistanceOfPoints(Point &p1, Point &p2);
	double findCanberraDistanceOfPoints(Point &p1, Point &p2);
}

#endif