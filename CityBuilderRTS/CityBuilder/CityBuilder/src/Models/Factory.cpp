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
