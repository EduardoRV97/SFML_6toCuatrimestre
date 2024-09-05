#include "BaseApp.h"

//Funcion que corre el programa en main - Declaracion

void BaseApp::run() {
    initialize();
    while (window->isOpen())
    {
        handleEvents();
        update();
        render();
    }
    cleanup();
}

// Funcion de inicializacion - Declaracion

void BaseApp::initialize() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "YIYI Engine");
    shape = new sf::RectangleShape(sf::Vector2f(200, 200));
    shape->setFillColor(sf::Color::Green);
    shape2 = new sf::CircleShape(300, 300);
    shape2->setFillColor(sf::Color::Cyan);
    shape2->setOutlineThickness(20);
    shape2->setOutlineColor(sf::Color::Red);
}

// Funcion de manejo de datos - Declaracion

void BaseApp::handleEvents() {

}

//Funcion que se actualiza por frame - Declaracion

void BaseApp::update() {

}

//Funcion de renderizado - Declaracion

void BaseApp::render() {
    window->clear();
    window->draw(*shape);
    window->draw(*shape2);
    window->display();
}

//Funcion de liberacion de memoria - Declaracion

void BaseApp::cleanup() {
    delete shape;
}

