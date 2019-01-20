#include "Apartment.h"



Apartment::Apartment(ofVec3f _pos)
{
	type = Structure::APARTMENT;
	model = std::shared_ptr<ofxAssimpModelLoader>(new ofxAssimpModelLoader());
	model->loadModel("ApartmentTile.fbx");
	model->setScaleNormalization(false);
	model->setRotation(0, 180, 1, 0, 0);
	model->setPosition(_pos.x, _pos.y, _pos.z);
}


Apartment::~Apartment()
{
}

bool Apartment::isFull()
{
	return (people >= 200);
}

Structure::StructureType Apartment::getType()
{
	return type;
}

int Apartment::getPPP()
{
	return maxProduct;
}

bool Apartment::isUpgradable()
{
	return upgradable;
}

int Apartment::getMaxPeople()
{
	return maxPeople;
}
