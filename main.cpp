#include "Kmeans.h"
#include "GenericFunc.h"

int main()
{
    // data to cluster
	std::string datasetFilename = "generateData/data.txt";
    datasetFilename = gf::getExecutablePathAndMatchItWithFilename(datasetFilename);

    // k-means configuration parameters (e.g., number of clusters)
	std::string propertiesFilename = "properties/kmeans.properties";
    propertiesFilename = gf::getExecutablePathAndMatchItWithFilename(propertiesFilename);

    // files to store the results of the algorithm
	std::string centroidsFilename = "results/centroids.txt";
	std::string allocationFilename1 = "results/allocation_1.txt";
	std::string allocationFilename2 = "results/allocation_2.txt";
	
    // new Kmeans object
    Kmeans k(datasetFilename, 2, 2, 1000, 1);
    
    // measure elaspsed time only for the clustering routine (i.e., not including the time for saving results)
    clock_t start = clock();
    k.runKmeans();
    clock_t end = clock();
    double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
	std::cout << "Elapsed time for running the k-means routine: " << elapsedTime << " seconds.\n";

    // save clustering results
    k.createPointIDClusterIDAllocation();
	k.createClusterIDPointsOfClusterIDsAllocation();
	k.writeCentroidsToFile(gf::getExecutablePathAndMatchItWithFilename(centroidsFilename));
	k.writeClusterIDPointsOfClusterIDsAllocationToFile(gf::getExecutablePathAndMatchItWithFilename(allocationFilename1));
	k.writePointIDClusterIDAllocationToFile(gf::getExecutablePathAndMatchItWithFilename(allocationFilename2));
    //std::cout << "Silhouette: " << k.calculateSilhouette() << "\n";

    return 0;
}