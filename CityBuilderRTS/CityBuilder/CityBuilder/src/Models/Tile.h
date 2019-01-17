#pragma once
#include "ofMain.h"
#include "Structure.h"
#include <memory>
#include "ofxAssimpModelLoader.h"
#include "ofxIntersection.h"

class Tile
{
public:

	enum BaseType{
		FLATLAND, MOUNTAIN
	};

	Tile(ofVec3f pos, BaseType type, float size = 200);
	~Tile() = default;

	std::shared_ptr<ofxAssimpModelLoader> getBaseModel();


	std::shared_ptr<IsPlane> boundingPlane = nullptr; // bounding plane for collisions

	std::shared_ptr<IsTriangle> boundingTriangle = nullptr; // bounding plane for collisions

private:
	ofVec3f position; // position of the tile
	float size; // size/width of the tile (n x n)
	BaseType type; 

	// base model (flatland, mountain, etc)
	// removed when a structure is built, added when a structure is destroyed
	std::shared_ptr<ofxAssimpModelLoader> baseModel;
	std::shared_ptr<Structure> structure = nullptr; // if this is nullptr, then it is not occupied
};