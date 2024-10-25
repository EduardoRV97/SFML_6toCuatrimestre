#include "BaseApp.h"
#include "Transform.h"
#include "ShapeFactory.h"

//Funcion que corre el programa en main - Declaracion

int
BaseApp::run() {
  if (!initialize()){
    ERROR("BaseApp", "run", "Initializa result on a false statement chech method validation");
  }

  while (m_window->isOpen()){
    m_window->handleEvents();
    update();
    render();
  }

    cleanup();
    return 0;
}

// Funcion de inicializacion - Declaracion

bool
BaseApp::initialize() {
  m_window = new Window(800, 600, "Galvan Engine");
  if (!m_window) {
    ERROR("BaseApp", "initialize", "Error on window creation, var is null");
    return false;
  }
  //Track Actor
  Track = EngineUtilities::MakeShared<Actor>("Track");

  // Actor de Círculo
  Circle = EngineUtilities::MakeShared<Actor>("Circle");
  if (!Circle.isNull()) {
    Track->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);
   // Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);

    // Establecer posición, rotación y escala desde Transform
    Track->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
    Track->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
    Track->getComponent<Transform>()->setScale(sf::Vector2f(5.0f, 5.0f));

    sf::Texture texture;
    if (!texture.loadFromFile("\SFML_6toCuatrimestre\bin\Goku.png")) {
      return -1; // MAneja Error de carga
    }
    Track->getComponent<ShapeFactory>()->getShape()->setTexture(&texture);
  }

  // Actor de Triángulo
  Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
  if (!Triangle.isNull()) {
    Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
    Triangle->getComponent<Transform>()->setPosition(sf::Vector2f(300.0f, 300.0f));
    Triangle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
    Triangle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));
  }
  
  return true;
}


//Funcion que se actualiza por frame - Declaracion

void
BaseApp::update() {
  // Uodsate window method
  m_window->update();

  // Posición del ratón
  sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->GetWindow());
  sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), 
    static_cast<float>(mousePosition.y));

  if (!Triangle.isNull()) {
    Triangle->update(m_window->deltaTime.asSeconds());
  }

  if (!Track.isNull()) {
    Track->update(m_window->deltaTime.asSeconds());
    updateMovement(m_window->deltaTime.asSeconds(), Track);
  }
} 


//Funcion de re nderizado - Declaracion

void 
BaseApp::render() {
    m_window->clear();
    if (!Triangle.isNull()) {
      Triangle->render(*m_window);
    }
    if (!Track.isNull()){
      Track->render(*m_window);
    }
    ImGui::Begin("Hola a todes");
    ImGui::Text("Este es un mensaje de prueba");
    ImGui::End();
    m_window->render();
    m_window->display();
}

//Funcion de liberacion de memoria - Declaracion

void 
BaseApp::cleanup() {
    m_window->destroy();
    delete m_window;
}

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
  float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

  if (distanceToTarget < 10.0f) {
    // Umbral para considerar que ha llegado
    currentWaypoint = (currentWaypoint + 1) % waypoints.size(); // Ciclar a través de los puntos
  }
}

