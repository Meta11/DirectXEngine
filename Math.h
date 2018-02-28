#pragma once
#include <cmath>

struct Vector3D {
	float x, y, z;
	explicit Vector3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

	inline Vector3D& operator+=(const Vector3D &right);
	inline Vector3D& operator-=(const Vector3D &right);
	inline float dot(const Vector3D& other) const;
	inline float magnitude() const;
	inline float magnitudeSquared() const;
	inline Vector3D normalize() const;
	inline Vector3D perpCw() const;
	inline Vector3D perpCcw() const;
	inline Vector3D projectOnto(const Vector3D& target) const;
};

inline Vector3D operator+(const Vector3D &left, const Vector3D &right);
inline Vector3D operator-(const Vector3D &left, const Vector3D &right);
inline Vector3D operator*(float scalar, const Vector3D &vector);
inline Vector3D operator*(const Vector3D &vector, float scalar);
inline Vector3D lerp(const Vector3D& source, const Vector3D& target, const float alpha);

#include "Math.inl"