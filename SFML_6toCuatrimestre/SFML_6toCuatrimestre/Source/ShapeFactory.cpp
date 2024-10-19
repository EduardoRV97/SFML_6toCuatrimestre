#include "ShapeFactory.h"

sf::Shape*
ShapeFactory::createShape(ShapeType shapeType)
{
    m_shapeType = shapeType;
    switch (shapeType) {

    case ShapeType::EMPTY: {
        return nullptr;
    }
    case ShapeType::CIRCLE: {
        sf::CircleShape* circle = new sf::CircleShape(50.0f); // Radio de 50
        circle->setFillColor(sf::Color::Green);
        m_shape = circle;
        return circle;
    }
    case ShapeType::RECTANGLE: {
        sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100.0f, 50.0f)); // Tamaño 100x50
        rectangle->setFillColor(sf::Color::Blue);
        m_shape = rectangle;
        return rectangle;
    }
    case ShapeType::TRIANGLE: {
        sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3); // Radio 50, 3 puntos para triángulo
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
ShapeFactory::Seek(const sf::Vector2f& targetPosition,
  float speed,
  float deltaTime,
  float range)
{
  // Obtener la posición actual de mi shape
  sf::Vector2f shapePosition = m_shape->getPosition();

  // Calcular la dirección desde el círculo hacia el objetivo
  // Nota: Dirección es la pi - pf
  sf::Vector2f direction = targetPosition - shapePosition;

  // Calcular la distancia al objetivo
  float lenght = std::sqrt(direction.x * direction.x + direction.y * direction.y);

  // Sí la distancia es mayor que el rango, mover la shape hacia el objetivo
  if (lenght > range)
  {
    direction /= lenght;
    m_shape->move(direction * speed * deltaTime);
  }
}

