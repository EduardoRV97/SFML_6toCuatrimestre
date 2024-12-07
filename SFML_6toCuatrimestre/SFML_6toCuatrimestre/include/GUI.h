#pragma once
#include "Prerrequisitos.h"

class
Actor;

class
Window;

class
  GUI {
public:
  GUI() = default;
  ~GUI() = default;

  /**
   * Inicializa la ventan y sus recursos.
   */
  void
  init();

  /**
   * Actualiza la ventana por cada frame.
   */
  void
  update();

  /**
   * Renderiza el contenido de la ventana.
   */
  void
  render();

  /**
  * Destruye la ventana y libera los recursos.
  */
  void
  destroy();

  /**
  * Declara los estilos de la ventana.
  */
  void
  setupGUIStyle();

  void
  barMenu();

  /**
   * Muestra el outliner con la lista de actores.
   */
  void
  outliner(std::vector<EngineUtilities::TSharedPointer<Actor>> actors);

  /**
  * Muestra una consola con mensajes del programa.
  */
  void
  console(const std::map<ConsoleErrorType, std::vector<std::string>>& programMessages);

  /**
   * Permite colocar actores en la escena.
   */
  void
  placeActors(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors);

  /**
  * Muestra el inspector del actor seleccionado con sus componentes.
  */
  void
  inspector(std::vector<EngineUtilities::TSharedPointer<Actor>> actors);

  void
  vec2Control(const std::string& label,
    float* values,
    float resetValues = 0.0f,
    float columnWidth = 100.0f);

private:
  EngineUtilities::TSharedPointer<Actor> m_actors; ///< Actor seleccionado en el GUI.
  int selectedActorIndex = -1;
};
