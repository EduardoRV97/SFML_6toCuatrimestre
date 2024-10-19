#pragma once
#include "Prerrequisitos.h"

class 
Window
{
public:
	Window() = default;
	Window(int width, int height, const std::string& title);
	~Window();

	// Funcion para manejo de datos
	void
	handleEvents();

	//Funcion que libera memoria en la ventana
	void
	clear();

	// Funcion que muestra datos en pantalla
	void
	display();

	// Funcion que revisa si una ventana se encuentra abierta
	bool
	isOpen() const;

	// Funcion para dibujar figuras
	void
	draw(const sf::Drawable& drawable);

	//Funcion que me ayuda a obetner la ventana
	sf::RenderWindow*
	GetWindow();

	// Funcion de inicializacion
	void
	init();

	// Funcion d actualizacion por frame
	void
	update();

	// Funcion de visualizacion en pantalla
	void
	render();

	// Funcion de liberacion de memoria
	void
	destroy();

private:
	sf::RenderWindow* m_window;
};