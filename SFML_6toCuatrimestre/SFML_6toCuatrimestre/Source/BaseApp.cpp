#include "BaseApp.h"

//Funcion que corre el programa en main - Declaracion

int
BaseApp::run() {
    if (!initialize())
    {
        ERROR("BaseApp", "run", "Initializa result on a false statement chech method validation");
    }
    initialize();
    while (m_window->isOpen())
    {
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
BaseApp::initialize() 
{
    m_window = new Window(720, 480, "AllenEngine");
    if (!m_window)
    {
        ERROR("BaseApp", "initialize", "Error on window creation, var is null");
        return false;
    }
    
    // Circle Actor
    Circle = EngineUtilities::MakeShared<Actor>("Circle");
    if (!Circle.isNull())
    {
      Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
      Circle->getComponent<ShapeFactory>()->setPosition(200.0f, 200.0f);
      Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);
    }

    //Triangle Actor
    Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
    if(!Triangle.isNull()) {
        Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
        Triangle->getComponent<ShapeFactory>()->setPosition(120.0f, 120.0f);
    }

    return true;
}

//Funcion que se actualiza por frame - Declaracion

void
BaseApp::update() 
{
  // Mouse Position
  sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
  sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
    static_cast<float>(mousePosition.y));

  if (!Circle.isNull())
  {
    Circle->getComponent<ShapeFactory>()->Seek(mousePosF,
      200.0f,
      deltaTime.asSeconds(),
      50.0f);
  }

  //Programa triangulo se mueve

  sf::Vector2f punto1(static_cast<float>(180.0f),
    static_cast<float>(120.0f));
  sf::Vector2f punto2(static_cast<float>(240.0f),
    static_cast<float>(230.0f));
  sf::Vector2f punto3(static_cast<float>(190.0f),
    static_cast<float>(200.0f));
  sf::Vector2f punto4(static_cast<float>(150.0f),
    static_cast<float>(150.0f));
  sf::Vector2f punto5(static_cast<float>(170.0f),
    static_cast<float>(170.0f));

  if (!Triangle.isNull())
  {
    Triangle->getComponent<ShapeFactory>()->puntosMover(punto1, punto2, punto3, punto4, punto5, 100.0f, deltaTime.asSeconds());
  }
}

//Funcion de re nderizado - Declaracion

void 
BaseApp::render() {
    m_window->clear();
    Triangle->render(*m_window);
    Circle->render(*m_window);
    m_window->display();
}

//Funcion de liberacion de memoria - Declaracion

void 
BaseApp::cleanup() {
    m_window->destroy();
    delete m_window;
}

