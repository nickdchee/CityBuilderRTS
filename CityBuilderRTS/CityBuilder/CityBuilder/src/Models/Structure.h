#pragma once
#include <memory>
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class Structure
{
public:

	enum StructureType {
		NONE,
		FACTORY,
		APARTMENT
	};

	Structure();
	~Structure();

	StructureType getType();
	std::shared_ptr<ofxAssimpModelLoader> getModel();

protected:
	float size;
	StructureType type;
	std::shared_ptr<ofxAssimpModelLoader> model;
};

