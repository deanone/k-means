#ifndef KMEANS_H
#define KMEANS_H

#include "Point.h"
#include "Cluster.h"

class Kmeans
{
	/*! Number of dimensions. */
	int	dimension;
	/*! Number of clusters. */
	int k;		
	/* Maximum number of iterations for the convergence of the algorithm. */
	int numOfIterations;
	/*! The type of used distance metric. */
	int distanceMetric;		
public:
	/*! The data points (full dataset) to be clustered. */
	std::vector<Point> points;		
	/*! Initial clusters in data randomly chosen. */
	std::vector<Cluster> initialClusters;
	/*! Current clusters. */
	std::vector<Cluster> finalClusters;

	std::vector<IntIntPair> sizes;
	IntIntMap pointIDClusterIDAllocation;
	IntIntVectorMap clusterIDPointsOfClusterIDsAllocation;

public:
	/*! Constructor - the parameters of the algorithm are given as arguments. */
	Kmeans(std::string datasetFilename, std::string propertiesFileName);
	/*! Constructor 2. */
	Kmeans(std::string datasetFilename, int d, int numOfClusters, int numIt, int distMetric);	
	/*! Destructor. */
	~Kmeans();				

	/*! Sets the dimension of the points of the dataset. */
	void setDimension(int dimension);
	/*! Gets the dimension. */
	int getDimension();
	/*! Sets the number of clusters. */
	void setK(int k);
	/*! Gets the number of clusters. */
	int getK();

	/*! Assigns Points to Clusters. */
	void setPointsToClusters();
	/*! Creates the initial clusters by choosing k random Points from the dataset. */		
	void setInitialClustersRandomly();
	/*! Creates the initial clusters by choosing the first k Points from the dataset. */
	void setInitialClustersByInitialPoints();
	/*! Generates current clusters. */
	void setFinalClusters();
	/*! Makes the final clusters of the iteration n-1 initial clusters for the iteration n. */	
	void initialize();
	/*! Checks if the algorithm converged. */
	bool isOver();
	/*! Runs the k-means routine. */
	void runKmeans();
	void writeCentroidsToFile(std::string centroidsFilename);
	void createPointIDClusterIDAllocation();
	void createClusterIDPointsOfClusterIDsAllocation();
	void writeClusterIDPointsOfClusterIDsAllocationToFile(std::string allocationFilename1);
	void writePointIDClusterIDAllocationToFile(std::string allocationFilename2);


	/*! Cluster validity metrics */
	
	/*! Calculates the Silhouette metric. */
	/*! https://en.wikipedia.org/wiki/Silhouette_(clustering) */
	double calculateSilhouette();
	/*! Calculates Within Cluster Sum of Squares (WCSS). */
	double calculateWCSS(); 

	/*!Davies-Bouldin index for clustering results internal evaluation. */
	/*! http://en.wikipedia.org/wiki/Cluster_analysis */
	/*! http://en.wikipedia.org/wiki/Davies%E2%80%93Bouldin_index */
	double calculateDaviesBouldinIndex();
};

#endif