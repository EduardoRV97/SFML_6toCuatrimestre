#include "ShapeFactory.h"

sf::Shape*
ShapeFactory::createShape(ShapeType shapeType)
{
    m_shapeType = shapeType;
    switch (shapeType) 
    {

    case ShapeType::EMPTY:
    {
        return nullptr;
    }
    case ShapeType::CIRCLE: 
    {
        sf::CircleShape* circle = new sf::CircleShape(10.0f); // Radio de 50
        circle->setFillColor(sf::Color::Green);
        m_shape = circle;
        return circle;
    }
    case ShapeType::RECTANGLE: 
    {
        sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100.0f, 50.0f)); // Tamaño 100x50
        rectangle->setFillColor(sf::Color::Blue);
        m_shape = rectangle;
        return rectangle;
    }
    case ShapeType::TRIANGLE: 
    {
        sf::CircleShape* triangle = new sf::CircleShape(30.0f, 3); // Radio 50, 3 puntos para triángulo
        triangle->setFillColor(sf::Color::Red);
        m_shape = triangle;
        return triangle;
    }
    default:
        return nullptr;
    }
}

void 
ShapeFactory::setPosition(float x, float y)
{
  m_shape->setPosition(x, y);
}

void
ShapeFactory::setPosition(const sf::Vector2f& position)
{
  m_shape->setPosition(position);
}

void
ShapeFactory::setFillColor(const sf::Color& color)
{
  m_shape->setFillColor(color);
}

void
ShapeFactory::Seek(
  const sf::Vector2f& targetPosition,
  float speed,
  float deltaTime,
  float range)
{
  // Obtener la posicion actual de mi shape
  sf::Vector2f shapePosition = m_shape->getPosition();

  // Calcular la direccion desde el circulo hacia el objetivo
  // Nota: Direccion es la pi - pf
  sf::Vector2f direction = targetPosition - shapePosition;

  // Calcular la distancia al objetivo
  float lenght = std::sqrt(direction.x * direction.x + direction.y * direction.y);

  // Si la distancia es mayor que el rango, mover la shape al objetivo
  if (lenght > range)
  {
    direction /= lenght;
    m_shape->move(direction * speed * deltaTime);
  }
}

void ShapeFactory::puntosMover(const sf::Vector2f& punto1,
  const sf::Vector2f& punto2,
  const sf::Vector2f& punto3,
  const sf::Vector2f& punto4,
  const sf::Vector2f& punto5,
  float velocidad,
  float deltaTime)
{
  // Almacena los puntos en un arreglo para facilitar el acceso
  sf::Vector2f puntos[5] = { punto1, punto2, punto3, punto4, punto5 };

  // Obtener la posición actual
  sf::Vector2f pi = m_shape->getPosition();

  // Calcular la dirección hacia el punto de destino
  sf::Vector2f direction = puntos[m_currentPoint] - pi;

  // Calcular la distancia entre el punto actual y el destino
  float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

  // Si estamos lo suficientemente cerca del punto actual, cambiar al siguiente
  if (length < 10.0f)
  {
    // Mover al siguiente punto 
    m_currentPoint = (m_currentPoint + 1) % 5;
  }

  // Normalizar la dirección y mover la figura hacia el punto de destino
  if (length > 0.0f)
  {
    direction /= length; // Normaliza la dirección
    m_shape->move(direction * velocidad * deltaTime); // Mueve la figura
  }
}


