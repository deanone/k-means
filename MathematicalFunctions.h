#ifndef MF_H
#define MF_H

#include "Point.h"

namespace mf
{
	// misc
	/*! 
	 * Returns the minimum of the sizes of two Point objects.
	 * @return the minimum of the sizes.
	 */
	size_t minSize(Point& p, Point& q);

	/*! 
	 * Returns the mean value of a Point.
	 * @return the mean value.
	 */
	double mean(Point& p);

	/*! 
	 * Returns the standard deviation value of a Point.
	 * @return the standard deviation value.
	 */
	double stDev(Point& p);

	// distances

	/*! 
	 * Computes the Euclidean distance between two Point objects.
	 * https://en.wikipedia.org/wiki/Euclidean_distance
	 * @param p the first Point.
	 * @param q the second Point.
	 * @returnd the Euclidean distance. 
	 */
	double euclideanDistance(Point& p, Point& q);

	/*! 
	 * Computes the squared Euclidean distance between two Point objects.
	 * https://en.wikipedia.org/wiki/Euclidean_distance
	 * @param p the first Point.
	 * @param q the second Point.
	 * @returnd the squared Euclidean distance. 
	 */
	double euclideanDistanceSquared(Point& p, Point& q);

	/*! 
	 * Computes the Manhattan (or taxicab) distance between two Point objects.
	 * https://en.wikipedia.org/wiki/Taxicab_geometry
	 * @param p the first Point.
	 * @param q the second Point.
	 * @returnd the Manhattan distance. 
	 */
	double manhattanDistance(Point& p, Point& q);

	/*! 
	 * Computes the Chebyshev distance between two Point objects.
	 * https://en.wikipedia.org/wiki/Chebyshev_distance
	 * @param p the first Point.
	 * @param q the second Point.
	 * @returnd the Chebyshev distance. 
	 */
	double chebyshevDistance(Point& p, Point& q);

	/*! 
	 * Computes the Bray–Curtis distance between two Point objects.
	 * https://en.wikipedia.org/wiki/Bray%E2%80%93Curtis_dissimilarity
	 * @param p the first Point.
	 * @param q the second Point.
	 * @returnd the Bray–Curtis distance. 
	 */
	double brayCurtisDistance(Point& p, Point& q);

	/*! 
	 * Computes the Canberra distance between two Point objects.
	 * https://en.wikipedia.org/wiki/Canberra_distance
	 * @param p the first Point.
	 * @param q the second Point.
	 * @returnd the Canberra distance. 
	 */
	double canberraDistance(Point& p, Point& q);

	// correlations

	/*! 
	 * Computes the Pearson correlation coefficient between two Point objects.
	 * https://en.wikipedia.org/wiki/Pearson_correlation_coefficient
	 * @param p the first Point.
	 * @param q the second Point.
	 * @returnd the Pearson correlation coefficient. 
	 */
	double pearsonCorrelation(Point& p, Point& q);

	/*! 
	 * Computes the cosine similarity between two Point objects.
	 * https://en.wikipedia.org/wiki/Cosine_similarity
	 * @param p the first Point.
	 * @param q the second Point.
	 * @returnd the cosine similarity. 
	 */
	double cosineSimilarity(Point& p, Point& q);
	
	// dot product

	/*! 
	 * Computes the dot product between two Point objects.
	 * https://en.wikipedia.org/wiki/Dot_product
	 * @param p the first Point.
	 * @param q the second Point.
	 * @returnd the dot product. 
	 */
	double dot(Point& p, Point& q);
}

#endif	//	MF_H