#include "Tile.h"

Tile::Tile(ofVec3f pos, BaseType type, float size) : position(pos), type(type), size(size)
{
	boundingPlane = std::shared_ptr<IsFinitePlane>(new IsFinitePlane());
	boundingPlane->set(position + 1, size);

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

std::shared_ptr<IsFinitePlane> Tile::getBoundingPlane()
{
	return boundingPlane;
}

void Tile::placeStructure(Structure::StructureType _type)
{
	switch (_type)
	{
	case Structure::APARTMENT :
		structure = std::shared_ptr<Structure>(new Apartment(position));
		break;
	case Structure::FACTORY:
		structure = std::shared_ptr<Structure>(new Factory(position));
		break;
	}
}

bool Tile::isOccupied()
{
	return (structure != nullptr);
}

Structure::StructureType Tile::getOccupyingType()
{
	return structure->getType();
}

std::shared_ptr<Structure> Tile::getStructure()
{
	return structure;
}

Tile::BaseType Tile::getType()
{
	return type;
}
