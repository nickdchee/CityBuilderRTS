#pragma once
#include "Structure.h"

class Apartment : public Structure
{
public:
	Apartment(ofVec3f _pos);
	~Apartment();
	bool isFull() override;
	StructureType getType() override;
	int getPPP() override;

	static const int goldCost = 50;
	static const int buildingMaterialCost = 100;
private:
	int maxPeople = 200;
	int maxProduct = -1; // not used for apartment
};

