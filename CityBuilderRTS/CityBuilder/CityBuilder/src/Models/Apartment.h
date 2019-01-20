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
	bool isUpgradable() override;
	int getMaxPeople() override;
private:
	int maxPeople = 80;
	int maxProduct = -1; // not used for apartment
	int upgradable = false;
};

