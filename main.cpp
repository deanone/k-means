#include "Kmeans.h"

std::string getExecutablePath() 
{
    char result[ PATH_MAX ];
    ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
    return std::string( result, (count > 0) ? count : 0 );
}

std::string getExecutablePathAndMatchItWithFilename(std::string filename)
{
    std::string execPath = getExecutablePath();
    size_t found = execPath.find_last_of("/");
    execPath = execPath.substr(0, found);
    std::stringstream ss;
    ss << execPath << "/" << filename;
    return ss.str();
}

int main()
{
	std::string datasetFilename = "generateData/data.txt";
    datasetFilename = getExecutablePathAndMatchItWithFilename(datasetFilename);

	std::string propertiesFilename = "properties/kmeans.properties";
    propertiesFilename = getExecutablePathAndMatchItWithFilename(propertiesFilename);

	std::string centroidsFilename = "results/centroids.txt";
	std::string allocationFilename1 = "results/allocation_1.txt";
	std::string allocationFilename2 = "results/allocation_2.txt";
	//Kmeans k(datasetFilename, propertiesFilename);
    Kmeans k(datasetFilename, 2, 2, 1000, 1);
    clock_t tStart = clock();
	k.runKmeans();
	k.createPointIDClusterIDAllocation();
	k.createClusterIDPointsOfClusterIDsAllocation();
	k.writeCentroidsToFile(getExecutablePathAndMatchItWithFilename(centroidsFilename));
	k.writeClusterIDPointsOfClusterIDsAllocationToFile(getExecutablePathAndMatchItWithFilename(allocationFilename1));
	k.writePointIDClusterIDAllocationToFile(getExecutablePathAndMatchItWithFilename(allocationFilename2));
    //std::cout << "Silhouette: " << k.calculateSilhouette() << "\n";
    std::cout << "Elapsed time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " seconds.\n";

    return 0;
}