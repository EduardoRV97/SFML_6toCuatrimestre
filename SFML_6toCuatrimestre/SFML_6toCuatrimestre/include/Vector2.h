#pragma once
#include "Prerrequisitos.h"

class Vector2 {
public:
  float x, y;

  // Constructor por defecto
  Vector2() : x(0), y(0) {}

  // Constructor parametrizado
  Vector2(float x, float y) : x(x), y(y) {}

  // Sobrecarga del operador + para sumar dos vectores
  Vector2 operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
  }

  // Sobrecarga del operador - para restar dos vectores
  Vector2 operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
  }

  // Sobrecarga del operador * para multiplicar por un escalar
  Vector2 operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
  }

  // M�todo para calcular la magnitud del vector
  float magnitude() const {
    return std::sqrt(x * x + y * y);
  }

  // M�todo para normalizar el vector
  Vector2 normalize() const {
    float mag = magnitude();
    if (mag == 0) {
      return Vector2(0, 0);
    }
    return Vector2(x / mag, y / mag);
  }

  // M�todo para obtener un puntero a los datos del vector
  float* data() {
    return &x;
  }

  // M�todo constante para obtener un puntero a los datos del vector sin permitir modificaci�n
  const float* data() const {
    return &x;
  }
};
