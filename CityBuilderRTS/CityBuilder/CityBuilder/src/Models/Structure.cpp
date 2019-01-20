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
