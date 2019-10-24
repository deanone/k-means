#ifndef KMEANS_H
#define KMEANS_H

#include "Point.h"
#include "Cluster.h"

class Kmeans
{
	/*! 
	 * Number of dimensions.
	 */
	int	dimension;
	
	/*! 
	 * Number of clusters.
	 */
	int k;

	/* 
	 * Maximum number of iterations for the convergence of the algorithm.
	 */
	int numOfIterations;

	/*!
	 * The type of used distance metric.
	 */
	int distanceMetric;		
public:
	/*! 
	 * The data points (full dataset) to be clustered.
	 */
	std::vector<Point> points;

	/*! 
	 * Initial clusters.
	 */
	std::vector<Cluster> initialClusters;
	
	/*! 
	 * Current clusters.
	 */
	std::vector<Cluster> finalClusters;

	std::vector<IntIntPair> sizes;
	IntIntMap pointIDClusterIDAllocation;
	IntIntVectorMap clusterIDPointsOfClusterIDsAllocation;

public:
	/*! Constructor - the parameters of the algorithm are given as arguments. */
	Kmeans(std::string datasetFilename, std::string propertiesFileName);
	
	/*!
     * Constructor.
     */
	Kmeans(std::string datasetFilename, int d, int numOfClusters, int numIt, int distMetric);	
	
	/*!
     * Destructor.
     */
	~Kmeans();				

	/*! 
	 * Setter of the dimension of the points of the dataset.
	 * @param dimension the features dimension (i.e. number of features).
	 */
	void setDimension(int dimension);

	/*! 
	 * Getter of the dimension of the points of the dataset.
	 * @return the features dimension.
	 */
	int getDimension();

	/*! 
	 * Setter of the number of clusters.
	 * @param k the number of clusters.
	 */
	void setK(int k);

	/*! 
	 * Getter of the number of clusters.
	 * @return the number of clusters.
	 */
	int getK();

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
	 * Calculates the silhouette metric. (https://en.wikipedia.org/wiki/Silhouette_(clustering))
	 * @return the value of the silhouette metric.
	 */
	double calculateSilhouette();

	/*! 
	 * Calculates within cluster sum of squares (WCSS).
	 * @return the value of WCSS.
 	 */
	double calculateWCSS(); 

	/* 
	 * !Calculates the Davies-Bouldin index. (http://en.wikipedia.org/wiki/Davies%E2%80%93Bouldin_index)
	 * @return the value of Davies-Bouldin index.
	 */
	double calculateDaviesBouldinIndex();
};

#endif