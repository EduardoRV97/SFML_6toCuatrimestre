#pragma once
#include "Prerrequisitos.h"
#include "Component.h"
#include "Window.h"

class
	Transform : public Component{
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

	void
	setPosition(const sf::Vector2f& _position) {
		position = _position;
	}
	
	void
	setRotation(const sf::Vector2f& _rotation) {
		rotation = _rotation;
	}
	
	void
	setScale(const sf::Vector2f& _scale) {
		scale = _scale;
	}

	sf::Vector2f& 
	getPosition() {
		return position;
	}
	
	sf::Vector2f&
	getRotation() {
		return rotation;
	}
	
	sf::Vector2f& 
	getScale() {
		return scale;
	}

private:
	sf::Vector2f position; // Posicion del objeto
	sf::Vector2f rotation; // Rotacion del objeto
	sf::Vector2f scale; // Escala del objeto
};
