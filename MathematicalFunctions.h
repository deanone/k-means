#ifndef MF_H
#define MF_H

#include "Point.h"

namespace mf
{
	size_t minSize(Point &p, Point &q);
	double euclideanDistance(Point &p, Point &q);
	double euclideanDistanceSquared(Point &p, Point &q);
	double manhattanDistance(Point &p, Point &q);
	double chebyshevDistance(Point &p, Point &q);
	double brayCurtisDistance(Point &p, Point &q);
	double canberraDistance(Point &p, Point &q);
	double cosineSimilarity(Point &p, Point &q);
	double mean(Point &p);
	double stDev(Point &p);
	double pearsonCorrelation(Point &p, Point &q);
	double dot(Point &p, Point &q);
}

#endif	//	MF_H