#pragma once
#include "Prerrequisitos.h"
#include "Window.h"
#include "ShapeFactory.h"
#include "Actor.h"

class
	BaseApp {
public:
	BaseApp() = default;
	~BaseApp() = default;

    // Funcion que corre el programa en main
    int
        run();

    // Funcion de inicializacion
    bool
        initialize();

    // Funcion que se actualiza por frame
    void
        update();

    // Funcion de renderizado
    void
        render();

    //Funcion de liberacion de memoria
    void
        cleanup();

private:
  sf::Clock clock;
  sf::Time deltaTime;

  Window* m_window;
  EngineUtilities::TSharedPointer<Actor> Triangle;
  EngineUtilities::TSharedPointer<Actor> Circle;
};
