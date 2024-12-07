#pragma once
#include "Prerrequisitos.h"

class Vector3 {
public:
	float x, y, z;

	// Constructor por defecto
	Vector3() : x(0), y(0), z(0) {}

	// Constructor parametrizado
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	// Sobrecarga del operador + para sumar dos Vector3
	Vector3 operator+(const Vector3& other) const {
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	// Sobrecarga del operador - Para restardos Vector3
	Vector3 operator-(const Vector3& other) const {
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	//Sobrecarga del operador * para multiplicar un Vector3 por un escalar
	Vector3 operator*(float scalar) const {
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	//Magnitud de Vector3

	float magnitud() const {
		return sqrt(x * x + y * y + z * z);
	}

	Vector3 normalize() const {
		float mag3 = magnitud();
		if (mag3 == 0) {
			return Vector3(0, 0, 0);
		}
		return Vector3(x / mag3, y / mag3, z / mag3);
	}

	//Metodo para obetner un puntero del Vector3

	float* data() {
		return &x;
	}

	// Metodo para obtener un puntero a los datos del vector
	const float* data() const {
		return &x;
	}
};