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
    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    if (!shape) {
        return false;
    }

    shape->setFillColor(sf::Color::Green);
    shape2 = new sf::CircleShape(80, 80);
    if (!shape2) {
        return false;
    }
    shape2->setFillColor(sf::Color::Cyan);
    shape2->setOutlineThickness(20);
    shape2->setOutlineColor(sf::Color::Red);
    shape2->setPosition(200.0f, 200.0f);

    Triangulo = m_shapeFactory.createShape(ShapeType::TRIANGLE);
    if (!Triangulo) {
        ERROR("BaseApp", "initialize", "Error on triangulo creation");
        return false;
    }

    return true;
}


//Funcion que se actualiza por frame - Declaracion

void
BaseApp::update() {
}

//Funcion de re nderizado - Declaracion

void 
BaseApp::render() {
    m_window->clear();
    m_window->draw(*Triangulo);
    m_window->display();
}

//Funcion de liberacion de memoria - Declaracion

void 
BaseApp::cleanup() {
    m_window->destroy();
    delete m_window;
    delete shape;
    delete shape2;
    delete Triangulo;
}

