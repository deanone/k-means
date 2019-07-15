#include "MathematicalFunctions.h"

double mf::findEuclideanDistanceOfPoints(Point &p1, Point &p2)
{
	double dist = 0.0;
	int s1 = p1.getValuesSize();
	int s2 = p2.getValuesSize();
	int s = s1 < s2 ? s1 : s2;
	for (int i = 0 ; i < s ; i++)
		dist += std::pow(p1.getValue(i) - p2.getValue(i), 2.0);
	dist = sqrt(dist);
	return dist;
}

double mf::findEuclideanSquaredDistanceOfPoints(Point &p1, Point &p2)
{
	double dist = 0.0;
	int s1 = p1.getValuesSize();
	int s2 = p2.getValuesSize();
	int s = s1 < s2 ? s1 : s2;
	for (int i = 0 ; i < s ; i++)
		dist += std::pow(p1.getValue(i) - p2.getValue(i), 2.0);
	return dist;
}

double mf::findManhattanDistanceOfPoints(Point &p1, Point &p2)
{
	double dist = 0.0;
	int s1 = p1.getValuesSize();
	int s2 = p2.getValuesSize();
	int s = s1 < s2 ? s1 : s2;
	for (int i = 0 ; i < s ; i++)
		dist += std::fabs(p1.getValue(i) - p2.getValue(i));
	return dist;
}

double mf::findChebysevDistanceOfPoints(Point &p1, Point &p2)
{
	double dist = std::fabs(p1.getValue(0) - p2.getValue(0));
	int s1 = p1.getValuesSize();
	int s2 = p2.getValuesSize();
	int s = s1 < s2 ? s1 : s2;
	for (int i = 1 ; i < s ; i++)
	{
		double tempDist = std::fabs(p1.getValue(i) - p2.getValue(i));
		if(tempDist > dist) dist = tempDist;
	}
	return dist;
}

// double mf::dotProduct(Point &p1, Point &p2)
// {
// 	int s1 = p1.getValuesSize();
// 	int s2 = p2.getValuesSize();
// 	int s = s1 < s2 ? s1 : s2;
// 	double prod = 0.0;
// 	for (int i = 0 ; i < s ; i++)
// 		res += (p1.getValue(i) * p2.getValue(i));
// 	return res;
// }

double mf::findCosineSimilarityOfPoints(Point &p1, Point &p2)
{
	double dist, dotProduct, magnitudeVec1, magnitudeVec2;
	magnitudeVec1 = 0.0; magnitudeVec2 = 0.0;
	int s1 = p1.getValuesSize();
	int s2 = p2.getValuesSize();
	int s = s1 < s2 ? s1 : s2;
	dotProduct = std::inner_product(p1.getValues()->begin(), p1.getValues()->end(), p2.getValues()->begin(), 0.0);
	for (int i = 0 ; i < s ; i++)
	{
		magnitudeVec1 += std::pow(p1.getValue(i), 2.0);
		magnitudeVec2 += std::pow(p2.getValue(i), 2.0);
	}
	magnitudeVec1 = std::sqrt(magnitudeVec1);
	magnitudeVec2 = std::sqrt(magnitudeVec2);
	dist = 1.0 - (dotProduct / (magnitudeVec1 * magnitudeVec2));
	return dist;
}

double mf::meanOfPoint(Point &p)
{
	double sum = std::accumulate(p.getValues()->begin(), p.getValues()->end(), 0.0);
	return sum / (double)p.getValuesSize();
}

double mf::stDevOfPoint(Point &p)
{
	double m, s;
	m = meanOfPoint(p);
	double sq_sum = std::inner_product(p.getValues()->begin(), p.getValues()->end(), p.getValues()->begin(), 0.0);
	s = std::sqrt(std::abs(sq_sum / (double)p.getValuesSize() - std::pow(m, 2.0)));
	return s;
}

double mf::findPearsonCorrelationOfPoints(Point &p1, Point &p2)
{
	double mean1, stDev1, mean2, stDev2, tempMean, pearsonCorrelation;
	mean1 = meanOfPoint(p1);
	mean2 = meanOfPoint(p2);
	stDev1 = stDevOfPoint(p1);
	stDev2 = stDevOfPoint(p2);
	int s1 = p1.getValuesSize();
	int s2 = p2.getValuesSize();
	int s = s1 < s2 ? s1 : s2;
	tempMean = 0.0;
	for (int i = 0 ; i < s ; i++)
		tempMean += ((p1.getValue(i) - mean1) * (p2.getValue(i) - mean2));
	tempMean /= s;
	pearsonCorrelation = 1.0 - (tempMean / (stDev1 * stDev2));
	return pearsonCorrelation;
}

double mf::findBrayCurtisDistanceOfPoints(Point &p1, Point &p2)
{
	double dist, sum1, sum2;
	dist = 0.0;sum1 = 0.0;sum2 = 0.0;
	int s1 = p1.getValuesSize();
	int s2 = p2.getValuesSize();
	int s = s1 < s2 ? s1 : s2;
	for (int i = 0 ; i < s ; i++)
	{
		sum1 += std::fabs(p1.getValue(i) - p2.getValue(i));
		sum2 += std::fabs(p1.getValue(i) + p2.getValue(i));
	}
	dist = sum1 / sum2;
	return dist;
}

double mf::findCanberraDistanceOfPoints(Point &p1, Point &p2)
{
	double dist = 0.0;
	int s1 = p1.getValuesSize();
	int s2 = p2.getValuesSize();
	int s = s1 < s2 ? s1 : s2;
	for (int i = 0 ; i < s ; i++)
		dist += std::fabs(p1.getValue(i) - p2.getValue(i)) / (std::fabs(p1.getValue(i)) + std::abs(p2.getValue(i)));
	return dist;
}