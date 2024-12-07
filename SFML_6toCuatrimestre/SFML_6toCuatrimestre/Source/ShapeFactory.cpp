#include "ShapeFactory.h"

sf::Shape*
ShapeFactory::createShape(ShapeType shapeType){
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
        sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100.0f, 50.0f)); // Tama�o 100x50
        rectangle->setFillColor(sf::Color::Blue);
        m_shape = rectangle;
        return rectangle;
    }
    case ShapeType::TRIANGLE: {
        sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3); // Radio 50, 3 puntos para tri�ngulo
        triangle->setFillColor(sf::Color::Red);
        m_shape = triangle;
        return triangle;
    }
    default:
        return nullptr;
    }
}
// Establece la posici�n de la forma.
void
ShapeFactory::setPosition(float x, float y){
  if (m_shape) {
    m_shape->setPosition(x, y);
  }
}
// Establece la posici�n de la forma.
void
ShapeFactory::setPosition(const sf::Vector2f& position)
{
  if (m_shape) {
    m_shape->setPosition(position);
  }
}
// Establece la rotaci�n de la forma.
void 
ShapeFactory::setRotation(float angle) {
  if (m_shape) {
    m_shape->setRotation(angle);
  }
}

void
ShapeFactory::setScale(const sf::Vector2f& scl) {
  if (m_shape) {
    m_shape->setScale(scl);
  }
}
// Establece el color
void
ShapeFactory::setFillColor(const sf::Color& color){
  m_shape->setFillColor(color);
}

/*

Funcion antigua de Seek--

void
ShapeFactory::Seek(const sf::Vector2f& targetPosition,
  float speed,
  float deltaTime,
  float range)
{
  // Obtener la posici�n actual de mi shape
  sf::Vector2f shapePosition = m_shape->getPosition();

  // Calcular la direcci�n desde el c�rculo hacia el objetivo
  // Nota: Direcci�n es la pi - pf
  sf::Vector2f direction = targetPosition - shapePosition;

  // Calcular la distancia al objetivo
  float lenght = std::sqrt(direction.x * direction.x + direction.y * direction.y);

  // S� la distancia es mayor que el rango, mover la shape hacia el objetivo
  if (lenght > range)
  {
    direction /= lenght;
    m_shape->move(direction * speed * deltaTime);
  }
}*/

