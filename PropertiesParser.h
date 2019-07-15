#ifndef PROPERTIES_PARSER_H
#define PROPERTIES_PARSER_H

#include "DataTypes.h"

class PropertiesParser
{
protected:
	/*!A map containing property names as keys and property values as values.*/
	std::map<std::string, std::string> PropMap;
public:
	PropertiesParser(std::string propertiesFilename);
	void addPropertiesFile(std::string propertiesFilename);
	bool propertyExists(std::string propertyName);
	std::string getPropertyAsString(std::string propertyName);
	int getPropertyAsInt(std::string propertyName);
	bool getPropertyAsBool(std::string propertyName);
	float getPropertyAsFloat(std::string propertyName);
	double getPropertyAsDouble(std::string propertyName);
	std::string getPropertyAsStringOrDefaultTo(std::string propertyName, std::string defaultPropertyValue);
	int getPropertyAsIntOrDefaultTo(std::string propertyName, int defaultPropertyValue);
	bool getPropertyAsBoolOrDefaultTo(std::string propertyName, bool defaultPropertyValue);
	float getPropertyAsFloatOrDefaultTo(std::string propertyName, float defaultPropertyValue);
	double getPropertyAsDoubleOrDefaultTo(std::string propertyName, double defaultPropertyValue);
};

#endif