#pragma once
#include "Structure.h"
#include <memory>

class Office : public Structure
{
public:
	Office(ofVec3f _pos);
	~Office();
	bool isFull() override;
	StructureType getType() override;
	int getPPP() override;

	static const int goldCost = 200;
	static const int buildingMaterialCost = 100;

	int getMaxPeople() override;
	bool isUpgradable() override;
	void upgrade() override;
private:
	int maxPeople = 20;
	int maxProduct = 2;
	bool upgradable = true;
};


