#pragma once
#include "Prerrequisitos.h"
#include "Window.h"
#include "Actor.h"

/**
 * @class BaseApp
 * @brief Clase base para la aplicaci�n.
 *
 * La clase BaseApp controla el ciclo principal de la aplicaci�n, manejando
 * la inicializaci�n, actualizaci�n, renderizado y limpieza. Mantiene la
 * aplicaci�n en funcionamiento mientras la ventana est� abierta.
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
  * @brief Actualiza el movimiento del c�rculo.
  * @param deltaTime Tiempo transcurrido desde la �ltima actualizaci�n.
  * @param circle Puntero compartido al actor c�rculo.
  */
  void
  updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle);

private:
  Window* m_window; ///< Puntero a la ventana de la aplicaci�n.
  EngineUtilities::TSharedPointer<Actor> Triangle; ///< Puntero compartido al Actor del tri�ngulo.
  EngineUtilities::TSharedPointer<Actor> Circle; ///< Puntero compartido al Actor del c�rculo.
  EngineUtilities::TSharedPointer<Actor> Track;

  int currentWaypoint = 0; ///< �ndice del punto de recorrido actual.

  std::vector<sf::Vector2f> waypoints = {
      {100.0f, 100.0f},
      {600.0f, 100.0f},
      {600.0f, 600.0f},
      {100.0f, 600.0f}
  }; ///< Lista de puntos de recorrido (waypoints).
};
