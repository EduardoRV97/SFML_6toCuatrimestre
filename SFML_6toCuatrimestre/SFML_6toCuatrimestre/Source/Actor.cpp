#include "Actor.h"

Actor::Actor(std::string actorName)
{
	// Setup Actor Name
	m_name = actorName;
	// Setup Shape
	EngineUtilities::TSharedPointer<ShapeFactory> shape = EngineUtilities::MakeShared<ShapeFactory>();
	addComponent(shape);
	// Setup Transform
	// Setup Sprite

}
