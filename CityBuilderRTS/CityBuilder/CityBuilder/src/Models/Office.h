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

private:
	int maxPeople = 20;
	int maxProduct = 2;
};


