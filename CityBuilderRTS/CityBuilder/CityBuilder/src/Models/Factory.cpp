#include "Factory.h"


Factory::Factory(ofVec3f _pos)
{
	type = Structure::FACTORY;
	model = std::shared_ptr<ofxAssimpModelLoader>(new ofxAssimpModelLoader());
	model->loadModel("Factory.fbx");
	model->setScaleNormalization(false);
	model->setRotation(0, 180, 1, 0, 0);
	model->setPosition(_pos.x, _pos.y, _pos.z);
}


Factory::~Factory()
{
}

bool Factory::isFull()
{
	return (people >= 20);
}

Structure::StructureType Factory::getType()
{
	return type;
}

int Factory::getPPP()
{
	return maxProduct;
}

int Factory::getMaxPeople()
{
	return maxPeople;
}

bool Factory::isUpgradable()
{
	return upgradable;
}

void Factory::upgrade()
{
	upgradable = false;
	maxProduct += 4;
}

