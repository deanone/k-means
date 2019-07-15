#include "Kmeans.h"

std::string getExecutablePath() 
{
    char result[ PATH_MAX ];
    ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
    return std::string( result, (count > 0) ? count : 0 );
}

std::string getExecutablePathAndMatchItWithFilename(std::string filename)
{
    std::string sep;
    sep = "/";
    std::string execPath = getExecutablePath();
    std::string ffname = filename;
    if (ffname.substr(0,1).compare(sep) == 0)
            ffname = ffname.substr(1, ffname.size());
    size_t found = execPath.find_last_of(sep);
    execPath = execPath.substr(0,found);
    int GoUp = 0;
    while (ffname.substr(0,2).compare("..") == 0)
    {
        ffname = ffname.substr(3,ffname.size());
        GoUp++;
    }
    for (int i = 0; i < GoUp; i++)
    {
        size_t found = execPath.find_last_of(sep);
        execPath = execPath.substr(0,found);
    }
    std::stringstream ss;
    ss << execPath << sep << ffname;
    return ss.str();
}

int main()
{
    
	std::string datasetFilename = "data.txt";
    datasetFilename = getExecutablePathAndMatchItWithFilename(datasetFilename);

	std::string propertiesFilename = "kmeans.properties";
    propertiesFilename = getExecutablePathAndMatchItWithFilename(propertiesFilename);

	std::string centroidsFilename = "Centroids.txt";
	std::string allocationFilename1 = "Allocation1.txt";
	std::string allocationFilename2 = "Allocation2.txt";
	//Kmeans k(datasetFilename, propertiesFilename);
    Kmeans k(datasetFilename, 2, 2, 1000, 1);
    clock_t tStart = clock();
	k.runKmeans();
	//k.createPointIDClusterIDAllocation();
	//k.createClusterIDPointsOfClusterIDsAllocation();
	//k.writeCentroidsToFile(getExecutablePathAndMatchItWithFilename(centroidsFilename));
	//k.writeClusterIDPointsOfClusterIDsAllocationToFile(getExecutablePathAndMatchItWithFilename(allocationFilename1));
	//k.writePointIDClusterIDAllocationToFile(getExecutablePathAndMatchItWithFilename(allocationFilename2));
    //std::cout << "Silhouette: " << k.calculateSilhouette() << "\n";
    std::cout << "Elapsed time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC << " seconds.\n";
}