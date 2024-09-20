#include "ShapeFactory.h"

sf::Shape*
ShapeFactory::createShape(ShapeType shapeType)
{
    m_shapeType = shapeType;
    switch (shapeType) {

    case ShapeType::NONE: {
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

