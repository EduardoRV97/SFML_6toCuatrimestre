#pragma once
#include "Prerrequisitos.h"
#include "Component.h"

class Window;

class
Entity {
public:

	/**
	* @brief Destructor virtual
	*/

	virtual
	~Entity() = default;

	/**
	* @brief Metodo virtual puro para renderizar la entidad
	* @param Widnow Contexto del disposotivio para operaciones graficas
	*/
	virtual void
	render(Window& window) = 0;
	
	/**
	* @brief Metodo virtual puro para renderizar la entidad
	* @param Widnow Contexto del disposotivio para operaciones graficas
	*/
	virtual void
	update(float deltaTime) = 0;

	/**
	* @brief Agrega un component a la entidad
	* @tparam T tipo del componente, debe drivar de Component
	* @param component Puntero compartido al component que se va a agregar
	*/

	template<typename T>
	void
	addComponent(EngineUtilities::TSharedPointer<T> component) 
	{
		static_assert(std::is_base_of<Component, T>::value, "T must be drived from Component");
		components.push_back(component.template dynamic_pointer_cast<Component>());
	}

	/**
	* @brief Obtiene un componente de la Entidad
	* @tparam T Tipo del component que se va a obtene 0cxzr
	* @return Puntero compartido al componente, o nullptr si no se encuentra
	*/

	template<typename T>
	EngineUtilities::TSharedPointer<T>
		getComponent() 
	{
		for (auto& component : components) 
		{
			EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
			if (specificComponent) 
			{
				return specificComponent;
			}
		}
		return EngineUtilities::TSharedPointer<T>();
	}
protected:
	bool isActive;
	int id;
	
	std::vector<EngineUtilities::TSharedPointer<Component>> components;
};