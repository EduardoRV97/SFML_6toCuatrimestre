#pragma once
#include "Prerrequisitos.h"

class
ShapeFactory
{
public:
	ShapeFactory() = default;
	~ShapeFactory() = default;

	sf::Shape*
		createShape(ShapeType shapeType);
};