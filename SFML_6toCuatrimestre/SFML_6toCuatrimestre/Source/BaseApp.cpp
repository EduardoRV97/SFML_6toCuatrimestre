#include "BaseApp.h"

//Funcion que corre el programa en main - Declaracion

int
BaseApp::run() {
  if (!initialize()){
    ERROR("BaseApp", "run", "Initializa result on a false statement chech method validation");
  }
  initialize();
  while (m_window->isOpen()){
    m_window->handleEvents();
    deltaTime = clock.restart();
    update();
    render();
  }

    cleanup();
    return 0;
}

// Funcion de inicializacion - Declaracion

bool 
BaseApp::initialize() {
  m_window = new Window(800, 600, "AllenEngine");
  if (!m_window){
    ERROR("BaseApp", "initialize", "Error on window creation, var is null");
    return false;
  }
  // Circle Actor
  Circle = EngineUtilities::MakeShared<Actor>("Circle");
  if (!Circle.isNull()){
    Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
    Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);

    // Establecer Posicion, Rotacion y Escala desde el Transform
    Circle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
    Circle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
    Circle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));
  }

  // Triangle Actor
  Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
  if (!Triangle.isNull()){
    Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
    Triangle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
    Triangle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
    Triangle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));
  }
    return true;
}


//Funcion que se actualiza por frame - Declaracion

void
BaseApp::update() {
  // Mouse Position
  sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->GetWindow());
  sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
    static_cast<float>(mousePosition.y));

  if (!Triangle.isNull()) {
    Triangle->update(deltaTime.asSeconds());
  }

  if (!Circle.isNull())
  {
    Circle->update(deltaTime.asSeconds());
    Circle->getComponent<ShapeFactory>()->Seek(
    mousePosF,
    200.0f,
    deltaTime.asSeconds(),
    50.0f);
  }
}

//Funcion de re nderizado - Declaracion

void 
BaseApp::render() {
    m_window->clear();
    if (!Triangle.isNull()) {
      Triangle->render(*m_window);
    }
    if (!Circle.isNull()){
      Circle->render(*m_window);
    }
    m_window->display();
}

//Funcion de liberacion de memoria - Declaracion

void 
BaseApp::cleanup() {
    m_window->destroy();
    delete m_window;
}

