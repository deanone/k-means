#include "Kmeans.h"
#include "PropertiesParser.h"
#include "MathematicalFunctions.h"

bool less_f(const IntIntPair& pair_a,const IntIntPair& pair_b)
{
	return pair_a.second<pair_b.second;	
}

Kmeans::Kmeans(std::string datasetFilename, std::string propertiesFileName)
{
	PropertiesParser* propertiesParser = new PropertiesParser(propertiesFileName);
	this->dimension = propertiesParser->getPropertyAsIntOrDefaultTo("dimension", 4);
	this->k = propertiesParser->getPropertyAsIntOrDefaultTo("k", 200);
	this->numOfIterations = propertiesParser->getPropertyAsIntOrDefaultTo("numOfIterations", 1000);
	this->distanceMetric = propertiesParser->getPropertyAsIntOrDefaultTo("distanceMetric",1);
	delete propertiesParser;
	std::string dataline;
	std::ifstream in;
	in.open(datasetFilename.c_str(), std::ios::in);
	if (in.is_open())
	{
		while (std::getline(in, dataline))
		{ 
			std::stringstream ss(dataline);
			std::string item;
			StringVector items;
			while (getline(ss, item, ','))
			{
				items.push_back(item);
			}
			int ID = std::stoi(items[0]);
			Point point;
			point.setID(ID);
			for (size_t i = 1; i < items.size(); ++i)
			{
				point.addValue(std::stod(items[i]));
			}
			items.clear();
			points.push_back(point);
		}
		in.close();
	}
	else
	{
		std::cout << "Cannot open file.\n";
	}
}

Kmeans::Kmeans(std::string datasetFilename, int d, int numOfClusters, int numIt, int distMetric):
dimension(d), k(numOfClusters), numOfIterations(numIt), distanceMetric(distMetric)
{
	std::string dataline;
	std::ifstream in;
	in.open(datasetFilename.c_str(), std::ios::in);
	if (in.is_open())
	{
		while (std::getline(in, dataline))
		{ 
			std::stringstream ss(dataline);
			std::string item;
			StringVector items;
			while (getline(ss, item, ','))
			{
				items.push_back(item);
			}
			int ID = std::stoi(items[0]);
			Point point;
			point.setID(ID);
			for (size_t i = 1; i < items.size(); ++i)
			{
				point.addValue(std::stod(items[i]));
			}
			items.clear();
			points.push_back(point);
		}
		in.close();
	}
	else
	{
		std::cout << "Cannot open file.\n";
	}

}

Kmeans::~Kmeans()
{
	if (points.size() > 0)
	{
		points.clear();
	}
	if (initialClusters.size() > 0)
	{
		initialClusters.clear();
	}
	if (finalClusters.size() > 0)
	{
		finalClusters.clear();
	}
	if (pointIDClusterIDAllocation.size() > 0)
	{
		pointIDClusterIDAllocation.clear();
	}
	if (clusterIDPointsOfClusterIDsAllocation.size() > 0)
	{
		clusterIDPointsOfClusterIDsAllocation.clear();
	}
}

void Kmeans::setDimension(int dimension)
{
	this->dimension = dimension;
}

int Kmeans::getDimension() const
{
	return dimension;
}

void Kmeans::setK(int k)
{
	this->k = k;
}

int Kmeans::getK() const
{
	return k;
}

void Kmeans::setInitialClustersRandomly()
{
	int index;
	srand (time(NULL)); 
	for (int i = 0; i < k; ++i)
	{
		index = rand() % points.size();
		Cluster cl(points[index/*i*/], i);
		initialClusters.push_back(cl);	
	}
}

void Kmeans::setInitialClustersByInitialPoints()
{
	for (int i = 0; i < k; ++i)
	{
		Cluster cl(points[i], i);
		initialClusters.push_back(cl);	
	}
}

void Kmeans::setPointsToClusters()
{
	double dist = 0.0;
	double minDist = 100000000.0;
	int minID;
	for (size_t i = 0; i < points.size(); ++i)
	{
		for (size_t j = 0; j < initialClusters.size(); ++j)
		{
			Point center = initialClusters[j].getCenter();
			switch (distanceMetric)
			{
				case 1:
					dist = mf::euclideanDistance(points[i], center);
					break;
				case 2:
					dist = mf::euclideanDistanceSquared(points[i], center);
					break;
				case 3:
					dist = mf::manhattanDistance(points[i], center);
					break;
				case 4:
					dist = mf::chebyshevDistance(points[i], center);
					break;
				case 5:
					dist = mf::brayCurtisDistance(points[i], center);
					break;
				case 6:
					dist = mf::canberraDistance(points[i], center);
					break;
				case 7:
					dist = mf::cosineSimilarity(points[i], center);
					break;
				case 8:
					dist = mf::pearsonCorrelation(points[i], center);
					break;
			}
			if (dist < minDist)
			{
				minDist = dist;
				minID = j;
			}
		}
		initialClusters[minID].setPointsToCluster(&points[i]);
		minDist = 100000000.0;
	}
}

void Kmeans::setFinalClusters()
{
	int n;
	for (int i = 0; i < k; ++i)
	{
		Point new_centroid;
		new_centroid.setID(i);
		for (int l = 0; l < dimension; ++l)
		{
			new_centroid.addValue(0.0);
		}
		n = initialClusters[i].getNumOfPointsInCluster();
		if( n != 0)
		{
			for (int j = 0; j < n; ++j)
			{
				new_centroid = new_centroid + (*(initialClusters[i].getPointOfCluster(j)));
			}
			new_centroid = new_centroid / n;
			Cluster cl(new_centroid, i);
			for (int m = 0; m < n; ++m)
			{
				cl.setPointsToCluster(initialClusters[i].getPointOfCluster(m));
			}
			finalClusters.push_back(cl);
		}
		else
		{
			finalClusters.push_back(initialClusters[i]);	
		}
	}
}

bool Kmeans::isOver()
{
	for (int i = 0; i < k; ++i)
	{
		if (!(initialClusters[i].getCenter() == finalClusters[i].getCenter()))
		{
			return false;
		}
	}
	return true;
}

void Kmeans::initialize()
{
	initialClusters.clear();
	for (int i = 0; i < k; ++i)
	{
		finalClusters[i].clearPointsOfCluster();
		initialClusters.push_back(finalClusters[i]);
	}
	finalClusters.clear();
}

void Kmeans::runKmeans()
{
	// First iteration
	int it = 1;
	//setInitialClustersRandomly();
	setInitialClustersByInitialPoints();
	setPointsToClusters();
	setFinalClusters();

	// Next iterations
	while ((!isOver()) && (it <= numOfIterations))
	{
		it++;		
		initialize();
		setPointsToClusters();
		setFinalClusters();
	}
}

void Kmeans::writeCentroidsToFile(std::string centroidsFilename)
{
	std::ofstream out(centroidsFilename.c_str());
	for (size_t i = 0; i < finalClusters.size(); ++i)
	{
		finalClusters[i].writeCentroidToFile(out);
		out << "\n";
	}
	out.close();
}

void Kmeans::createPointIDClusterIDAllocation()
{
	for (size_t i = 0; i < finalClusters.size(); ++i)
	{
		for (size_t j = 0; j < finalClusters[i].getNumOfPointsInCluster(); ++j)
		{
			pointIDClusterIDAllocation.insert(std::make_pair(finalClusters[i].getPointOfCluster(j)->getID(), finalClusters[i].getID())); // (PointID,ClusterID)
		}
	}
}

void Kmeans::createClusterIDPointsOfClusterIDsAllocation()
{
	for (size_t i = 0; i < finalClusters.size(); ++i)
	{
		IntVector pointsOfClusterIDs;
		for (int j = 0; j < finalClusters[i].getNumOfPointsInCluster(); ++j)
		{
			pointsOfClusterIDs.push_back(finalClusters[i].getPointOfCluster(j)->getID());
		}
		clusterIDPointsOfClusterIDsAllocation.insert(std::make_pair(finalClusters[i].getID(), pointsOfClusterIDs));
		pointsOfClusterIDs.clear();
	}
}

void Kmeans::writeClusterIDPointsOfClusterIDsAllocationToFile(std::string allocationFilename1)
{
	std::ofstream out;
	out.open(allocationFilename1.c_str());
	for (auto it = clusterIDPointsOfClusterIDsAllocation.begin(); it != clusterIDPointsOfClusterIDsAllocation.end(); ++it)
	{
		int clusterID = it->first;
		IntVector pointsOfClusterIDs = it->second;
		out << clusterID;
		for (size_t i = 0 ; i < pointsOfClusterIDs.size() ; i++)
		{
			out << " " << pointsOfClusterIDs[i];
		}
		out << "\n";
		pointsOfClusterIDs.clear();
	} 	
	out.close();
}

void Kmeans::writePointIDClusterIDAllocationToFile(std::string allocationFilename2)
{
	std::ofstream out;
	out.open(allocationFilename2.c_str());
	for (auto it = pointIDClusterIDAllocation.begin(); it != pointIDClusterIDAllocation.end(); ++it)
	{
		int pointID = it->first;
		int clusterID = it->second;
		out << pointID << " " << clusterID << "\n";
	}
	out.close();
}

double Kmeans::calculateSilhouette()
{	
	DoubleVector silhouettes;
	for (size_t i = 0; i < points.size(); ++i)
	{
		double a_for_point, final_b_for_point, temp_b, silhouetteForPoint;
	//	std::cout << "Calculating the average dissimilarity of point " << points[i].getID() << " of all other data within the same cluster..." << "\n";
		a_for_point = 0;
		int clusterID = -1;
		auto it = pointIDClusterIDAllocation.find(points[i].getID());
		if (it != pointIDClusterIDAllocation.end())
		{
			clusterID = it->second;
		}

		for (int j = 0; j < finalClusters[clusterID].getNumOfPointsInCluster(); ++j)
		{
			Point* pointOfCluster = finalClusters[clusterID].getPointOfCluster(j);
			a_for_point += mf::euclideanDistance(points[i], *pointOfCluster);
		}
		a_for_point /= finalClusters[clusterID].getNumOfPointsInCluster();


	//	std::cout << "Calculating the lowest average dissimilarity of point " << points[i].getID() << " of all other data of all other clusters..." << "\n";
		DoubleVector b_for_point;
		for (size_t j = 0; j < finalClusters.size(); ++j)
		{
			if(finalClusters[j].getID() != clusterID)
			{
				temp_b = 0;
				for (int k = 0; k < finalClusters[j].getNumOfPointsInCluster(); ++k)
				{	
					Point* pointOfCluster = finalClusters[j].getPointOfCluster(k);
					temp_b += mf::euclideanDistance(points[i], *pointOfCluster);
				}
				temp_b /= finalClusters[j].pointsOfCluster.size();
				b_for_point.push_back(temp_b);
			}
		}
		final_b_for_point = *std::min_element(b_for_point.begin(), b_for_point.end());
		b_for_point.clear();

	//	std::cout << "Calculating the silhouette of point " << points[i].getID() <<"\n";
		silhouetteForPoint = (final_b_for_point - a_for_point)/std::max(a_for_point, final_b_for_point);
		silhouettes.push_back(silhouetteForPoint);
	}

	double silhouette = 0.0;
	for (size_t i = 0; i < silhouettes.size(); ++i)
	{
		silhouette += silhouettes[i];
	}
	silhouette /= (double)silhouettes.size();
	
	return silhouette;
}

double Kmeans::calculateWCSS()
{
	double withinClusterVariance = 0.0;
	for (size_t i = 0; i < finalClusters.size(); ++i)
	{
		for (int j = 0; j < finalClusters[i].getNumOfPointsInCluster(); ++j)
		{
			Point* pointOfCluster = finalClusters[i].getPointOfCluster(j);
			Point center = finalClusters[i].getCenter();
			withinClusterVariance += mf::euclideanDistance(*pointOfCluster, center);
		}
	}
	return withinClusterVariance;
}

double Kmeans::calculateDaviesBouldinIndex()
{
	double DaviesDoublinIndex = 0.0;
	DoubleVector AverageIntraClusterDistances;
	DoubleVector2D InterClusterDistances;
	for (size_t i = 0; i < finalClusters.size(); ++i)
	{
		double averageIntaClusterDistance = 0.0;
		for (int j = 0; j < finalClusters[i].getNumOfPointsInCluster(); ++j)
		{
			Point* pointOfCluster = finalClusters[i].getPointOfCluster(j);
			Point center = finalClusters[i].getCenter();
			averageIntaClusterDistance+= mf::euclideanDistance(*pointOfCluster, center);
		}
		averageIntaClusterDistance /= finalClusters[i].getNumOfPointsInCluster();
		AverageIntraClusterDistances.push_back(averageIntaClusterDistance);
	}

	for (size_t i = 0; i < finalClusters.size(); ++i)
	{
		DoubleVector temp;
		double interClusterDistance;
		Point center1 = finalClusters[i].getCenter();
		for (size_t j = 0; j < finalClusters.size(); ++j)
		{
			Point center2 = finalClusters[j].getCenter();
			interClusterDistance = mf::euclideanDistance(center1, center2);
			temp.push_back(interClusterDistance);
		}
		InterClusterDistances.push_back(temp);
	}

	for (size_t i = 0; i < finalClusters.size(); ++i)
	{
		double Di;
		double maxDi = -1.0;
		for (size_t j = 0; j < finalClusters.size(); ++j)
		{
			if (i != j)
			{
				Di = (AverageIntraClusterDistances[i]+AverageIntraClusterDistances[j]) / InterClusterDistances[i][j];
				if (Di > maxDi)
				{
					maxDi = Di;
				}
			}
		}
		DaviesDoublinIndex += maxDi;
	}
	DaviesDoublinIndex /= finalClusters.size();

	return DaviesDoublinIndex;
}