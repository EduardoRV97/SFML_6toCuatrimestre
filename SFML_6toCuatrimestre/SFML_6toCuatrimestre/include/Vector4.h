#pragma once
#include "Prerrequisitos.h"

class Vector4 {
public:
	float x, y, z, w;

	// Constructor por defecto
	Vector4() : x(0), y(0), z(0), w(0) {}

	// Constructor parametrizado
	Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	// Sobrecarga del operador + para sumar dos Vector4
	Vector4 operator+(const Vector4& other) const {
		return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
	}

	// Sobrecarga del operador - Para restardos Vector4
	Vector4 operator-(const Vector4& other) const {
		return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
	}

	//Sobrecarga del operador * para multiplicar un Vector4 por un escalar
	Vector4 operator*(float scalar) const {
		return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	//Magnitud de Vector4

	float magnitud() const {
		return sqrt(x * x + y * y + z * z + w * w);
	}

	//Funcion para normalizar un Vector 4

	Vector4 normalize() const {
		float mag4 = magnitud();
		if (mag4 == 0) {
			return Vector4(0, 0, 0, 0);
		}
		return Vector4(x / mag4, y / mag4, z / mag4, w / mag4);
	}

	//Metodo para obetner un puntero del Vector4

	float* data() {
		return &x;
	}

	// Metodo para obtener un puntero a los datos del vector4

	const float* data() const {
		return &x;
	}
};
