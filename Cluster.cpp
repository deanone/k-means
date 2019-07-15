#include "Cluster.h"

Cluster::Cluster(Point c, int id) : center(c), ID(id)
{
}

Cluster::~Cluster()
{
	if (pointsOfCluster.size() > 0)
		pointsOfCluster.clear();
}

void Cluster::setID(int ID)
{
	this->ID = ID;
}

int Cluster::getID()
{
	return ID;
}

void Cluster::setCenter(Point &center)
{
	this->center = center;
}

Point Cluster::getCenter()
{
	return center;
}

void Cluster::setPointsToCluster(Point *p)
{
	pointsOfCluster.push_back(p);
}

int Cluster::getNumOfPointsInCluster()
{
	return pointsOfCluster.size();
}

Point* Cluster::getPointOfCluster(int index)
{
	if (index >= 0 && index < pointsOfCluster.size())
		return pointsOfCluster[index];
}

void Cluster::clearPointsOfCluster()
{
	pointsOfCluster.clear();
}

bool Cluster::operator==(Cluster &c)
{
	if (center == c.center) return true;
	return false;
}

bool Cluster::operator<(Cluster &c)
{
	if (center < c.center) return true;
	return false;
}

void Cluster::printCentroidInConsole()
{
	std::cout << ID;
	center.printValuesToConsole();
}

void Cluster::printAllocationInConsole()
{
	for (int i = 0 ; i < pointsOfCluster.size() ; i++)
		std::cout << pointsOfCluster[i]->getID() << " " << ID << "\n";
}

void Cluster::writeCentroidToFile(std::ostream &out)
{
	out << ID;
	center.writeValuesToFile(out);
}

void Cluster::writeAllocationToFile(std::ostream &out)
{
	for (int i = 0 ; i < pointsOfCluster.size() ; i++)
		out << pointsOfCluster[i]->getID() << " " << ID << "\n";
}