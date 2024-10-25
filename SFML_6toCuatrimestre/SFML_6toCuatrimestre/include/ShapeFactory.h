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

	ShapeFactory(ShapeType shapetype) : 
		m_shape(nullptr), m_shapeType(ShapeType::EMPTY), Component(ComponentType::SHAPE) 
	{}

	sf::Shape*
	createShape(ShapeType shapeType);

	/*
	* @brief Actualiza el componente de malla
	* @param deltaTime Tl tiempo transcurrido desde la ultima actualizacion
	*/
	void
	update(float deltaTime) override {}

	/*
	* @brief Renderiza el componente de malla
	* @param window Contexto del dispositivo para operaciones graficas
	*/
	void
	render(Window window)override {}

	/**
	* @brief Establece la posición de la forma.
	* @param x Coordenada X.
	* @param y Coordenada Y.
	*/
	void
	setPosition(float x, float y);

	/**
	* @brief Establece la posición de la forma.
	* @param position Vector con la nueva posición.
	*/
	void
	setPosition(const sf::Vector2f& position);

	/**
	* @brief Establece el color de relleno de la forma.
	* @param color Color de relleno.
	*/
	void
	setFillColor(const sf::Color& color);

	/*
	Funcion antigua de Seek

	void
	Seek(const sf::Vector2f& targetPosition, float speed, float deltaTime, float range);*/

	/**
	* @brief Establece la rotación de la forma.
	* @param angle Ángulo de rotación.
	*/
	void
	setRotation(float angle);

	/**
	* @brief Establece la escala de la forma.
	* @param scl Vector con la nueva escala.
	*/
	void
	setScale(const sf::Vector2f& scl);

	/**
	* @brief Mueve el triángulo a lo largo de los puntos especificados.
	* @param points Vector de posiciones objetivo.
	* @param targetIndex Índice del punto objetivo actual.
	* @param speed Velocidad del movimiento.
	* @param deltaTime Tiempo transcurrido desde la última actualización.
	*/
	void
		MoveTriangle(const std::vector<sf::Vector2f>& points, int& targetIndex, float speed, float deltaTime);

	/**
	* @brief Obtiene la forma actual.
	* @return Puntero a la forma.
	*/
	sf::Shape*
	getShape()
	{
		return m_shape;
	}

private:
	sf::Shape* m_shape;
	ShapeType m_shapeType;
};