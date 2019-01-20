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
		APARTMENT,
		OFFICE,
		FARM
	};

	Structure();
	~Structure();

	virtual StructureType getType() = 0;
	std::shared_ptr<ofxAssimpModelLoader> getModel();
	int getNumberOfPeople();
	int* getNumberOfPeopleP();
	void addResident();
	void removeResident();
	virtual bool isFull() = 0;
	bool isEmpty();
	virtual int getPPP() = 0; // product per person
	int* getPPPP(); // product per person pointer (mouthfull!)
	virtual int getMaxPeople() = 0;

protected:
	float size;
	StructureType type = Structure::NONE;
	std::shared_ptr<ofxAssimpModelLoader> model;
	int people = 0;
	int maxProduct = 0;
};

