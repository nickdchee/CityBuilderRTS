#include "Tile.h"

Tile::Tile(int x, int y, ofVec3f pos, BaseType type, float size) : position(pos), type(type), size(size), x(x), y(y)
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
		baseModel->loadModel("MountainTile.fbx");
		break;
	}
	flatland.loadModel("flatland.fbx");
	flatland.setScaleNormalization(false);
	flatland.setRotation(0, 180, 1, 0, 0);
	flatland.setPosition(position.x, position.y, position.z);

	baseModel->setScaleNormalization(false);
	baseModel->setRotation(0, 180, 1, 0, 0);
	baseModel->setPosition(position.x, position.y, position.z);


	constructionModel.loadModel("ConstructionTile.fbx");
	constructionModel.setScaleNormalization(false);
	constructionModel.setRotation(0, 180, 1, 0, 0);
	constructionModel.setPosition(position.x, position.y, position.z);
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
	case Structure::FARM:
		structure = std::shared_ptr<Structure>(new Farm(position));
		break;
	case Structure::OFFICE:
		structure = std::shared_ptr<Structure>(new Office(position));
		break;
	}
	timer = 4 * 60; // 4 seconds roughly
	inConstruction = true;
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


void Tile::draw()
{
	if (isOccupied())
	{
		if (inConstruction)
		{
			--timer;
			constructionModel.drawFaces();
		}
		else {
			structure->getModel()->drawFaces();
		}
		if (timer <= 0) { inConstruction = false; }
	}
	switch (type)
	{
	case MOUNTAIN :
		baseModel->drawFaces();
		flatland.drawFaces();
		break;
	case FLATLAND :
		baseModel->drawFaces();
		break;
	}
}

int Tile::getX()
{
	return x;
}

int Tile::getY()
{
	return y;
}
