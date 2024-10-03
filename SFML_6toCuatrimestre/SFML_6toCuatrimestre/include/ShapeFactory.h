#pragma once
#include "Prerrequisitos.h"
#include "Component.h"
#include "Window.h"

class
ShapeFactory : public Component
{
public:
	ShapeFactory() = default;

	virtual
	~ShapeFactory() = default;

	ShapeFactory(ShapeType shapetype) : m_shape(nullptr), m_shapeType(ShapeType::EMPTY), Component(ComponentType::SHAPE) {}

	sf::Shape*
	createShape(ShapeType shapeType);

	/**
	* @brief Actualiza el componente de mala
	* @param Deltatime El tiempo transcurrido desde la ultima actualizacion
	*/

	void
	update(float deltaTime) override {}

	/**
	* @brief Renderiza el componente de malla
	* @param Windom Contexto del dispositivo para operaciones graficas
	*/

	void
	render(Window window)override {}

	void
	setPosition(float x, float y);

	void
	setPosition(const sf::Vector2f& position);

	void 
	setFillColor(const sf::Color& color);

	void
	Seek(const sf::Vector2f& targetPosition, float speed, float deltaTime, float range);

	sf::Shape*
	getShape()
	{
		return m_shape;
	}
	void
	puntosMover(const sf::Vector2f& punto1, 
		const sf::Vector2f& punto2, 
		const sf::Vector2f& punto3, 
		const sf::Vector2f& punto4, 
		const sf::Vector2f& punto5,
		float velocidad, 
		float deltaTime);

private:
	sf::Shape* m_shape;
	ShapeType m_shapeType;
	int m_currentPoint = 0;
};