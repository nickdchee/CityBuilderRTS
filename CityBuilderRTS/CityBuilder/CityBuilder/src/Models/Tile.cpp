#include "Tile.h"

Tile::Tile(ofVec3f pos, BaseType type, float size) : position(pos), type(type), size(size)
{
	boundingPlane = std::shared_ptr<ofPlanePrimitive>(new ofPlanePrimitive());
	boundingPlane->set(size, size);
	boundingPlane->setPosition(position);
	boundingPlane->rotate(90, boundingPlane->getXAxis());


	baseModel = std::shared_ptr<ofxAssimpModelLoader>(new ofxAssimpModelLoader());
	switch (type)
	{
	case FLATLAND : 
		baseModel->loadModel("flatland.fbx");
		break;
	case MOUNTAIN :
		baseModel->loadModel("mountain.fbx");
		break;
	}
	baseModel->setScaleNormalization(false);
	baseModel->setRotation(0, 180, 1, 0, 0);
	baseModel->setPosition(position.x, position.y, position.z);
}

std::shared_ptr<ofxAssimpModelLoader> Tile::getBaseModel()
{
	return baseModel;
}
