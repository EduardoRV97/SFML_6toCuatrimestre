#pragma once
#include "Prerrequisitos.h"
#include "Window.h"
#include "Actor.h"

/**
 * @class BaseApp
 * @brief Clase base para la aplicación.
 *
 * La clase BaseApp controla el ciclo principal de la aplicación, manejando
 * la inicialización, actualización, renderizado y limpieza. Mantiene la
 * aplicación en funcionamiento mientras la ventana esté abierta.
 */

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

  /**
  * @brief Actualiza el movimiento del círculo.
  * @param deltaTime Tiempo transcurrido desde la última actualización.
  * @param circle Puntero compartido al actor círculo.
  */
  void
  updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle);

private:
  Window* m_window; ///< Puntero a la ventana de la aplicación.
  EngineUtilities::TSharedPointer<Actor> Triangle; ///< Puntero compartido al Actor del triángulo.
  EngineUtilities::TSharedPointer<Actor> Circle; ///< Puntero compartido al Actor del círculo.
  EngineUtilities::TSharedPointer<Actor> Track;

  int currentWaypoint = 0; ///< Índice del punto de recorrido actual.

  std::vector<sf::Vector2f> waypoints = {
      {100.0f, 100.0f},
      {600.0f, 100.0f},
      {600.0f, 600.0f},
      {100.0f, 600.0f}
  }; ///< Lista de puntos de recorrido (waypoints).
};
