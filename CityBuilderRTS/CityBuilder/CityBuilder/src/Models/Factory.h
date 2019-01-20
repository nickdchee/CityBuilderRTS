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

private:
	int maxPeople = 20;
	int maxProduct = 2;
};

