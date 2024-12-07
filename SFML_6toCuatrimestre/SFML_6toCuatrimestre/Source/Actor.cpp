#include "Actor.h"
#include "NotificationService.h"
#include "Prerrequisitos.h"
#include "ShapeFactory.h"
#include "Transform.h"


Actor::Actor(std::string actorName){

	NotificationService& notifier = NotificationService::getInstance();
	// Setup Actor Name
	m_name = actorName;
	// Setup Shape
	EngineUtilities::TSharedPointer<ShapeFactory> shape = EngineUtilities::MakeShared<ShapeFactory>();
	addComponent(shape);

	// Setup Transform
	EngineUtilities::TSharedPointer<Transform> transform = EngineUtilities::MakeShared<Transform>();
	addComponent(transform);
	// Setup Sprite
	notifier.Log("Actor named " + m_name + " was created.");
}

/**
 * @brief Actualiza el estado del actor.
 * @param deltaTime Tiempo transcurrido desde la última actualización.
 */

void 
Actor::update(float deltaTime) {
	auto transform = getComponent<Transform>();
	auto shape = getComponent<ShapeFactory>();

	if (transform && shape) {
		shape->setPosition(transform->getPosition());
		shape->setRotation(transform->getRotation().x);
		shape->setScale(transform->getScale());
	}
}

/**
 * @brief Renderiza los componentes del actor.
 * @param window Contexto de la ventana para operaciones gráficas.
 */

void 
Actor::render(Window& window) {
  for (unsigned int i = 0; i < componentes.size(); i++){
		if (componentes[i].dynamic_pointer_cast<ShapeFactory>()){
			window.draw(*componentes[i].dynamic_pointer_cast<ShapeFactory>()->getShape());

		}
	}
}

void 
Actor::destroy() {
}

