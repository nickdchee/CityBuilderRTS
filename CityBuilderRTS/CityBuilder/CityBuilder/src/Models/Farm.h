#pragma once
#include "Structure.h"
#include <memory>

class Farm : public Structure
{
public:
	Farm(ofVec3f _pos);
	~Farm();
	bool isFull() override;
	StructureType getType() override;
	int getPPP() override;

	static const int goldCost = 100;
	static const int buildingMaterialCost = 100;

private:
	int maxPeople = 20;
	int maxProduct = 5;
};

