#include "BaseApp.h"
#include "Transform.h"
#include "ShapeFactory.h"
#include "NotificationService.h"
#include "ResourceManager.h"

BaseApp::~BaseApp() {
  NotificationService& notifier = NotificationService::getInstance();
  notifier.saveMessagesToFile("LogData.txt");
}

/**
 * Ejecuta la aplicación base.
 */
int
BaseApp::run() {
  NotificationService& notifier = NotificationService::getInstance();

  if (!initialize()) {
    notifier.addMessage(ConsoleErrorType::ERROR, "Initializes result on a false statemente, check method validations");
    notifier.saveMessagesToFile("LogData.txt");
    ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
  }
  else {
    notifier.addMessage(ConsoleErrorType::INFO, "All programs were initialized correctly");
  }

  m_GUI.init();

  while (m_window->isOpen()) {
    m_window->handleEvents();
    update();
    render();
  }

  cleanup();
  return 0;
}

/**
 * Inicializa la aplicación base.
 */
bool
BaseApp::initialize() {
  // Obtener managers
  NotificationService& notifier = NotificationService::getInstance();
  ResourceManager& resourceMan = ResourceManager::getInstance();

  m_window = new Window(1920, 1080, "SFML_6toCuatrimestre");
  if (!m_window) {
    ERROR("BaseApp", "initialize", "Error on window creation, var is null");
    return false;
  }

  // Actor de Circuito
  Track = EngineUtilities::MakeShared<Actor>("Track");
  if (!Track.isNull()) {
    Track->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);

    // Establecer posición, rotación y escala desde Transform
    Track->getComponent<Transform>()->setTransform(sf::Vector2f(0.0f, 0.0f),
      sf::Vector2f(0.0f, 0.0f),
      sf::Vector2f(11.0f, 12.0f));

    // Cargar la textura para el actor Track
    if (!resourceMan.loadTexture("circuit", "png")) {
      notifier.addMessage(ConsoleErrorType::ERROR, "Cant load texture");
    }

    // Obtenemos la textura Carga
    EngineUtilities::TSharedPointer<Texture> trackTexture = resourceMan.getTexture("circuit");
    if (trackTexture) {
      Track->getComponent<ShapeFactory>()->getShape()->setTexture(&trackTexture->getTexture());
    }
    m_actors.push_back(Track);
  }

  // Actor de Círculo
  Circle = EngineUtilities::MakeShared<Actor>("Circle");
  if (!Circle.isNull()) {
    Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
    //Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);

    // Establecer posición, rotación y escala desde Transform
    Circle->getComponent<Transform>()->setTransform(sf::Vector2f(200.0f, 200.0f),
      sf::Vector2f(0.0f, 0.0f),
      sf::Vector2f(1.0f, 1.0f));

    // Cargar la textura para el actor Track
    if (!resourceMan.loadTexture("tile000", "png")) {
      notifier.addMessage(ConsoleErrorType::ERROR, "Cant load texture");
    }

    // Obtenemos la textura Carga
    EngineUtilities::TSharedPointer<Texture> circleTexture = resourceMan.getTexture("tile000");
    if (circleTexture) {
      Circle->getComponent<ShapeFactory>()->getShape()->setTexture(&circleTexture->getTexture());
    }

    m_actors.push_back(Circle);
  }

  return true;
}

/**
 * Actualiza el estado de la aplicación.
 */
void
BaseApp::update() {
  m_window->update();

  // Posición del ratón
  sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->GetWindow());
  sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

  // Actualizar los actores
  for (auto& actor : m_actors) {
    if (!actor.isNull()) {
      actor->update(m_window->deltaTime.asSeconds());
      if (actor->getName() == "Circle") {
        updateMovement(m_window->deltaTime.asSeconds(), actor);
      }
    }
  }
}

/**
 * Renderiza los elementos de la aplicación.
 */
void
BaseApp::render() {
  // Obtener Managers
  NotificationService& notifier = NotificationService::getInstance();

  m_window->clear();

  // Update the actors
  for (auto& actor : m_actors) {
    if (!actor.isNull()) {
      actor->render(*m_window);
    }
  }

  // Mostrar el render en ImGui
  m_window->renderToTexture();  // Finaliza el render a la textura
  m_window->showInImGui();      // Muestra la textura en ImGui
  m_GUI.barMenu();
  m_GUI.console(notifier.getNotifications());
  m_GUI.outliner(m_actors);
  m_GUI.placeActors(m_actors);  // Mostrar ventana para colocar actores
  m_GUI.inspector(m_actors);    // Mostrar ventana del inspector
  m_window->render();
  m_window->display();
}

/**
 * Libera los recursos y realiza limpieza.
 */
void
BaseApp::cleanup() {
  m_window->destroy();
  delete m_window;
}

/**
 * Actualiza el movimiento del círculo.
 */
void
BaseApp::updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle) {
  // Verificar si el Circle es nulo
  if (!circle || circle.isNull()) {
    return;
  }

  // Obtener el componente Transform
  auto transform = circle->getComponent<Transform>();
  if (transform.isNull()) {
    return;
  }

  // Posición actual del destino (punto de recorrido)
  sf::Vector2f targetPos = waypoints[currentWaypoint];

  // Llamar al Seek del Transform
  transform->Seek(targetPos, 200.0f, deltaTime, 10.0f);

  // Obtener la posición actual del actor desde Transform
  sf::Vector2f currentPos = transform->getPosition();

  // Comprobar si el actor ha alcanzado el destino (o está cerca)
  float distanceToTarget = std::sqrt(
    std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

  if (distanceToTarget < 10.0f) {
    // Umbral para considerar que ha llegado
    currentWaypoint = (currentWaypoint + 1) % waypoints.size(); // Ciclar a través de los puntos
  }
}

