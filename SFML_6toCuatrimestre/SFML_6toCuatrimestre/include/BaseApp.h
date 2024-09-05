#pragma once
#include "Prerrequisitos.h"

class
	BaseApp {
public:
	BaseApp() = default;
	~BaseApp() = default;

    // Funcion que corre el programa en main
    void
        run();

    // Funcion de inicializacion
    void
        initialize();

    // Funcion de manejo de datos
    void
        handleEvents();

    // Funcion que se actualiza por frame
    void
        update();

    // Funcion de renderizado
    void
        render();

    //Funcion de liberacion de memoria
    void
        cleanup();

private:

    //Variables Globales
	sf::RectangleShape* shape;
    sf::CircleShape* shape2;
};
