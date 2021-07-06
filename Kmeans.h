#ifndef KMEANS_H
#define KMEANS_H

#include "Point.h"
#include "Cluster.h"

class Kmeans
{
	/*! number of dimensions. */
	int	dimension;
	
	/*! number of clusters. */
	int k;

	/* maximum number of iterations for the convergence of the algorithm. */
	int numOfIterations;

	/*! the type of used distance metric. */
	int distanceMetric;		
public:
	/*! the data points (full dataset) to be clustered. */
	std::vector<Point> points;

	/*! initial clusters. */
	std::vector<Cluster> initialClusters;
	
	/*! current clusters. */
	std::vector<Cluster> finalClusters;

	std::vector<IntIntPair> sizes;
	IntIntMap pointIDClusterIDAllocation;
	IntIntVectorMap clusterIDPointsOfClusterIDsAllocation;

public:
	/*!
	 * Constructor 1.
	 */
	Kmeans(std::string datasetFilename, std::string propertiesFileName);
	
	/*!
     * Constructor 2.
     */
	Kmeans(std::string datasetFilename, int d, int numOfClusters, int numIt, int distMetric);	
	
	/*!
     * Destructor.
     */
	~Kmeans();				

	/*! 
	 * Sets the dimension of the points of the dataset.
	 * @param dimension the features dimension (i.e. number of features).
	 */
	void setDimension(int dimension);

	/*! 
	 * Returns the dimension of the points of the dataset.
	 * @return the features dimension.
	 */
	int getDimension() const;

	/*! 
	 * Sets the number of clusters.
	 * @param k the number of clusters.
	 */
	void setK(int k);

	/*! 
	 * Returns the number of clusters.
	 * @return the number of clusters.
	 */
	int getK() const;

	/*! 
	 * Assigns points to clusters.
	 */
	void setPointsToClusters();

	/*! 
	 * Creates the initial clusters by choosing k random points from the dataset.
	 */		
	void setInitialClustersRandomly();

	/*! 
	 * Creates the initial clusters by choosing the first k points from the dataset.
	 */
	void setInitialClustersByInitialPoints();

	/*! 
	 * Generates current clusters.
	 */
	void setFinalClusters();

	/*! 
	 * Makes the final clusters of the iteration n - 1, initial clusters for the iteration n.
	 */
	void initialize();

	/*! 
	 * Checks if the algorithm converged.
	 * @return true if the algorithm converged, false otherwise.
	 */
	bool isOver();

	/*! 
	 * Runs the k-means routine.
	 */
	void runKmeans();

	void writeCentroidsToFile(std::string centroidsFilename);
	void createPointIDClusterIDAllocation();
	void createClusterIDPointsOfClusterIDsAllocation();
	void writeClusterIDPointsOfClusterIDsAllocationToFile(std::string allocationFilename1);
	void writePointIDClusterIDAllocationToFile(std::string allocationFilename2);


	/*! Cluster validity metrics */
	
	/*! 
	 * Computes the silhouette metric.
	 * https://en.wikipedia.org/wiki/Silhouette_(clustering)
	 * @return the value of the silhouette metric.
	 */
	double calculateSilhouette();

	/*! 
	 * Computes within cluster sum of squares (WCSS).
	 * @return the value of WCSS.
 	 */
	double calculateWCSS(); 

	/*! 
	 * Computes the Davies-Bouldin index.
	 * http://en.wikipedia.org/wiki/Davies%E2%80%93Bouldin_index
	 * @return the value of Davies-Bouldin index.
	 */
	double calculateDaviesBouldinIndex();
};

#endif //	KMEANS_H