#include "BaseApp.h"

//Funcion que corre el programa en main - Declaracion

int
BaseApp::run() {
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

void 
BaseApp::initialize() {
    m_window = new Window(800, 600, "AllenEngine");
    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    shape->setFillColor(sf::Color::Green);
    shape2 = new sf::CircleShape(300, 300);
    shape2->setFillColor(sf::Color::Cyan);
    shape2->setOutlineThickness(20);
    shape2->setOutlineColor(sf::Color::Red);
}


//Funcion que se actualiza por frame - Declaracion

void
BaseApp::update() {
}

//Funcion de re nderizado - Declaracion

void 
BaseApp::render() {
    m_window->clear();
    m_window->draw(*shape);
    m_window->draw(*shape2);
    m_window->display();
}

//Funcion de liberacion de memoria - Declaracion

void 
BaseApp::cleanup() {
    m_window->destroy();
    delete m_window;
    delete shape;
    delete shape2;
}

