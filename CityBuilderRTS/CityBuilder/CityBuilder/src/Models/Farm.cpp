#include "Farm.h"


Farm::Farm(ofVec3f _pos)
{
	type = Structure::FARM;
	model = std::shared_ptr<ofxAssimpModelLoader>(new ofxAssimpModelLoader());
	model->loadModel("Farm.fbx");
	model->setScaleNormalization(false);
	model->setRotation(0, 180, 1, 0, 0);
	model->setPosition(_pos.x, _pos.y, _pos.z);
}


Farm::~Farm()
{
}

bool Farm::isFull()
{
	return (people >= 20);
}

Structure::StructureType Farm::getType()
{
	return type;
}

int Farm::getPPP()
{
	return maxProduct;
}

int Farm::getMaxPeople()
{
	return maxPeople;
}

bool Farm::isUpgradable()
{
	return upgradable;
}

void Farm::upgrade()
{
	upgradable = false;
	maxProduct += 4;
}
