#include "MathematicalFunctions.h"

size_t mf::minSize(Point& p, Point& q)
{
	size_t s_p = p.size();
	size_t s_q = q.size();
	size_t s = s_p < s_q ? s_p : s_q;
	return s;
}

double mf::mean(Point& p)
{
	return std::accumulate(p.values()->begin(), p.values()->end(), 0.0) / (static_cast<double>(p.size()));
}

double mf::stDev(Point& p)
{
	double m, s;
	m = mean(p);
	double sq_sum = std::inner_product(p.values()->begin(), p.values()->end(), p.values()->begin(), 0.0);
	s = std::sqrt(std::abs(sq_sum / static_cast<double>(p.size()) - std::pow(m, 2.0)));
	return s;
}

double mf::euclideanDistance(Point& p, Point& q)
{
	double dist = 0.0;
	size_t s = minSize(p, q);
	for (size_t i = 0; i < s; ++i)
	{
		dist += std::pow(p(i) - q(i), 2.0);
	}
	dist = sqrt(dist);
	return dist;
}

double mf::euclideanDistanceSquared(Point& p, Point& q)
{
	return std::pow(euclideanDistance(p, q), 2.0);
}

double mf::manhattanDistance(Point& p, Point& q)
{
	double dist = 0.0;
	size_t s = minSize(p, q);
	for (size_t i = 0; i < s; ++i)
	{
		dist += std::fabs(p(i) - q(i));
	}
	return dist;
}

double mf::chebyshevDistance(Point& p, Point& q)
{
	double dist = -1.0;
	size_t s = minSize(p, q);
	for (int i = 0; i < s; ++i)
	{
		double tempDist = std::fabs(p(i) - q(i));
		if (tempDist > dist)
		{
			dist = tempDist;
		}
	}
	return dist;
}

double mf::brayCurtisDistance(Point& p, Point& q)
{
	double dist, sumDiff, sumAdd;
	dist = 0.0;sumDiff = 0.0;sumAdd = 0.0;
	size_t s = minSize(p, q);
	for (size_t i = 0; i < s; ++i)
	{
		sumDiff += std::fabs(p(i) - q(i));
		sumAdd += std::fabs(p(i) + q(i));
	}
	dist = sumDiff / sumAdd;
	return dist;
}

double mf::canberraDistance(Point& p, Point& q)
{
	double dist = 0.0;
	size_t s = minSize(p, q);
	for (size_t i = 0; i < s; ++i)
	{
		dist += std::fabs(p(i) - q(i)) / (std::fabs(p(i)) + std::fabs(q(i)));
	}
	return dist;
}

double mf::pearsonCorrelation(Point& p, Point& q)
{
	double mean_p, stDev_p, mean_q, stDev_q, tempMean, pearsonCorrelation;
	mean_p = mean(p);
	mean_q = mean(q);
	stDev_p = stDev(p);
	stDev_q = stDev(q);
	size_t s = minSize(p, q);
	tempMean = 0.0;
	for (size_t i = 0; i < s; ++i)
	{
		tempMean += ((p(i) - mean_p) * (q(i) - mean_q));
	}
	tempMean /= s;
	pearsonCorrelation = 1.0 - (tempMean / (stDev_p * stDev_q));
	return pearsonCorrelation;
}

double mf::cosineSimilarity(Point& p, Point& q)
{
	double dist, dotProduct, magnitudeVec1, magnitudeVec2;
	magnitudeVec1 = 0.0; magnitudeVec2 = 0.0;
	size_t s = minSize(p, q);
	dotProduct = std::inner_product(p.values()->begin(), q.values()->end(), q.values()->begin(), 0.0);
	for (size_t i = 0; i < s; ++i)
	{
		magnitudeVec1 += std::pow(p(i), 2.0);
		magnitudeVec2 += std::pow(q(i), 2.0);
	}
	magnitudeVec1 = std::sqrt(magnitudeVec1);
	magnitudeVec2 = std::sqrt(magnitudeVec2);
	dist = 1.0 - (dotProduct / (magnitudeVec1 * magnitudeVec2));
	return dist;
}

double mf::dot(Point& p, Point& q)
{
	size_t s = minSize(p, q);
	double res = 0.0;
	for (size_t i = 0; i < s; ++i)
	{
		res += (p(i) * q(i));
	}
	return res;
}