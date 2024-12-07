#pragma once
#include "Prerrequisitos.h"

/**
 * @class Window
 * @brief Responsable de crear y manejar la ventana gráfica.
 *
 * Proporciona métodos para manejar eventos de la ventana, limpiar la pantalla,
 * y mostrar gráficos. Esta clase interactúa estrechamente con la biblioteca gráfica
 * utilizada.
 */
class 
Window
{
public:


	Window() = default;
	/**
		 * @brief Constructor que inicializa la ventana con las dimensiones y título especificados.
		 * @param width Ancho de la ventana.
		 * @param height Alto de la ventana.
		 * @param title Título de la ventana.
		 */
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

	// Dibuja un objeto que puede ser dibujado en la ventana.
	void
	draw(const sf::Drawable& drawable);


	//Funcion que me ayuda a obetner la ventana
	sf::RenderWindow*
	GetWindow();

	// Renderiza el contenido a una textura en lugar de la ventana principal.
	void
	renderToTexture();

	// Presenta el contenido en la interfaz gráfica de imgui.
	 
	void
	showInImGui();

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

	sf::Clock clock; ///< Reloj para calcular deltaTime.
	sf::Time deltaTime; // Almacena el tiempo transcurrido
	sf::RenderTexture m_renderTexture;
private:
	sf::RenderWindow* m_window;
	sf::View m_view;
};