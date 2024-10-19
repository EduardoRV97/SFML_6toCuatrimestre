#pragma once
#include "Prerrequisitos.h"
#include "Component.h"
#include "Window.h"

class
	Transform : public Component
{
public:
	Transform() : position(0.0f, 0.0f),
								rotation(0.0f, 0.0f),
								scale(1.0f, 1.0f),
								Component(ComponentType::TRANSFORM) {}

	virtual
	~Transform() = default;

	void
	update(float deltaTime) override {}

	void
	render(Window window) override {}

	void
	destroy();

private:
	sf::Vector2f position; // Posicion del objeto
	sf::Vector2f rotation; // Rotacion del objeto
	sf::Vector2f scale; // Escala del objeto
};
