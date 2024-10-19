#pragma once
#include "Prerrequisitos.h"
#include "Entity.h"
#include "ShapeFactory.h"
class
Actor : Entity
{
public:
	/**
	* @brief Constructor por defecto
	*/
	Actor() = default;
	Actor(std::string actorName);

	/**
	* @brief Destructor virtual
	*/
	virtual
	~Actor() = default;

	/**
	* @brief Actualizar el actor
	* @param deltaTime Define las actualizaciones por segundo
	*/
	void
	update(float deltaTime) override;

	/**
	* @brief Renderiza el actor
	* @param windowm Contexto del disposotivo para opareciones graficas
	*/
	void 
	render(Window& window) override;

	/**
	* @brief Destruye el actor y libera los recursos asociados
	*/

	void
	destroy();

	/**
	* @brief Obtiene un componente especifico del actor
	* @tparam T Tipo del componente que se va a obtener
	* @return Puntero compartido al componente, o nullptr si no se encuenta
	*/
	template<typename T>
	EngineUtilities::TSharedPointer<T>
	getComponent();

private:
	std::string m_name = "Actor;"; ///< Nombre del actor
};

/**
* El proposito de esta funcion es buscar y devolver un componente especifico de un actor
* utilizando el tipo d componente especificado como argumento de la plantilla
* Si el componente no se encuentra, la funcion devueve nullptr
*/

template<typename T>
inline EngineUtilities::TSharedPointer<T>
Actor::getComponent() {
	for (auto& component : componentes) {
		EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
		if (specificComponent) {
			return specificComponent;
		}
	}
	// Devuelve un TSharedPointer vac�o si no se encuentra el componente
	return EngineUtilities::TSharedPointer<T>();
}

