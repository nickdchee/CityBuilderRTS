#pragma once
#include "Structure.h"
#include <memory>

class Factory : public Structure
{
public:
	Factory(ofVec3f _pos);
	~Factory();
	bool isFull() override;
	StructureType getType() override;
	int getPPP() override;

	static const int goldCost = 100;
	static const int buildingMaterialCost = 150;

	int getMaxPeople() override;
	bool isUpgradable() override;
	void upgrade() override;

private:
	int maxPeople = 20;
	int maxProduct = 2;
	bool upgradable = false;
};

