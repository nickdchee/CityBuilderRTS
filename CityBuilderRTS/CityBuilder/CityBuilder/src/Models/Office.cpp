#include "Office.h"


Office::Office(ofVec3f _pos)
{
	type = Structure::OFFICE;
	model = std::shared_ptr<ofxAssimpModelLoader>(new ofxAssimpModelLoader());
	model->loadModel("OfficeTile.fbx");
	model->setScaleNormalization(false);
	model->setRotation(0, 180, 1, 0, 0);
	model->setPosition(_pos.x, _pos.y, _pos.z);
}


Office::~Office()
{
}

bool Office::isFull()
{
	return (people >= 20);
}

Structure::StructureType Office::getType()
{
	return type;
}

int Office::getPPP()
{
	return maxProduct;
}
