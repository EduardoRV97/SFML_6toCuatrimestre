#pragma once

class Window;

/*enum Component Type
*@brief Tipos de componentes disponbibles en el juego
* 
*/

enum ComponentType {
	NONE = 0,
	TRANSFORM = 1,
	SPRITE = 2,
	RENDERER = 3,
	PHYSICS = 4
};

/*
*@class Component
* @brief Clase base abstracta para todos los componentes
* 
* La clase component define la interfaz basica que tosdos los componentes
* deben implementar, permitiendo actualizar y renderizt el componente, asi como obtener su tipo
*/

class Component
{
public:

	/**@brief Constructor por defecto*/
	Component() = default;

	/**
	* @brief Constructor con tipo de componente.
	* @param type Tipo del componente
	*/
	Component(const ComponentType type) : m_type(type) {}

	/**
	* @brief destructor virtual
	*/
	virtual
	~Component() = default;


	/**@brief Metodo virutal puro para actualizar el componente
	* @param deltaTime El tiempo transcurrido desde la ultima actualizacion
	*/
	virtual void
	update(float deltaTime) = 0;

	/**@brief Metodo virtual puro par renderizar el componente
	* @param Window Contexto dl disposotivo para operacione graficas
	*/
	virtual void
	render(Window window) = 0;

	/**@brief Obtiene el tipo del componente
	* @return El tipo de componente
	*/
	ComponentType
	getType() const { return m_type; }


	protected:
		ComponentType m_type;

};