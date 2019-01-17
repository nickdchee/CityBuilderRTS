#include "Tile.h"

Tile::Tile(ofVec3f pos, BaseType type, float size) : position(pos), type(type), size(size)
{
	boundingPlane = std::shared_ptr<IsPlane>(new IsPlane());
	boundingPlane->set(position, 
		ofPoint(position.x + size, position.y, position.z), 
		ofPoint(position.x, position.y, position.z + size));

	boundingTriangle = std::shared_ptr<IsTriangle>(new IsTriangle());
	boundingTriangle->set(position,
		ofPoint(position.x + size, position.y, position.z),
		ofPoint(position.x, position.y, position.z + size));

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
