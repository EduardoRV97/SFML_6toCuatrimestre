#pragma once
#include "Prerrequisitos.h"
#include "Vector3.h"
class Quaternion {
public:
  float w, x, y, z;

  // Constructor por defecto que inicializa el Quaterni�n a 0
  Quaternion() : w(0), x(0), y(0), z(0) {}

  // Constructor parametrizado que inicializa los valores de w, x, y, z
  Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

  // Constructor que inicializa un Quaterni�n a partir de un �ngulo y un eje (Vector3)
  Quaternion(float angle, const Vector3& axis) {
    float halfAngle = angle / 2;
    float sinHalfAngle = sin(halfAngle);
    w = cos(halfAngle);
    x = axis.x * sinHalfAngle;
    y = axis.y * sinHalfAngle;
    z = axis.z * sinHalfAngle;
  }

  // Sobrecarga del operador + para sumar dos Quaterniones
  Quaternion operator+(const Quaternion& q) const {
    return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
  }

  // Sobrecarga del operador * para multiplicar un Quaterni�n por un escalar
  Quaternion operator*(float scalar) const {
    return Quaternion(w * scalar, x * scalar, y * scalar, z * scalar);
  }

  // Sobrecarga del operador * para multiplicar dos Quaterniones
  Quaternion operator*(const Quaternion& q) const {
    return Quaternion(
      w * q.w - x * q.x - y * q.y - z * q.z,  // Parte escalar
      w * q.x + x * q.w + y * q.z - z * q.y,  // Parte vectorial x
      w * q.y - x * q.z + y * q.w + z * q.x,  // Parte vectorial y
      w * q.z + x * q.y - y * q.x + z * q.w   // Parte vectorial z
    );
  }

  // M�todo para calcular la magnitud de un Quaterni�n
  float magnitude() const {
    return sqrt(w * w + x * x + y * y + z * z);
  }

  // M�todo para normalizar un Quaternion
  Quaternion normalize() const {
    float mag = magnitude();
    return Quaternion(w / mag, x / mag, y / mag, z / mag);
  }

  // M�todo para calcular el conjugado de un  Quaternion
  Quaternion conjugate() const {
    return Quaternion(w, -x, -y, -z);
  }

  // M�todo para calcular el inverso de un Quaternion
  Quaternion inverse() const {
    float magSquared = w * w + x * x + y * y + z * z;
    return conjugate() * (1.0f / magSquared);
  }

  // M�todo para rotar un vector utilizando un Quaternion
  Vector3 rotate(const Vector3& v) const {
    Quaternion qv(0, v.x, v.y, v.z);  // Convertir vector en cuaterni�n
    Quaternion result = (*this) * qv * inverse();  // Rotaci�n
    return Vector3(result.x, result.y, result.z);  // Convertir de nuevo a vector
  }

  // M�todo para acceder a los componentes del cuaterni�n de manera no constante
  float* data() {
    return &w;  // Devuelve un puntero al primer elemento (w)
  }

  // M�todo para acceder a los componentes del cuaterni�n de manera constante
  const float* data() const {
    return &w;  // Devuelve un puntero constante al primer elemento (w)
  }
};