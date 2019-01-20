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
