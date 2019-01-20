#include "Structure.h"



Structure::Structure()
{
}


Structure::~Structure()
{
}

Structure::StructureType Structure::getType()
{
	return type;
}

std::shared_ptr<ofxAssimpModelLoader> Structure::getModel()
{
	return model;
}

int Structure::getNumberOfPeople()
{
	return people;
}

void Structure::addResident()
{
	++people;
}

void Structure::removeResident()
{
	--people;
}

bool Structure::isEmpty()
{
	return (people <= 0);
}

