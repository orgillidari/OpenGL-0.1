#include "Vector3f.h"


namespace illidan
{
	Vector3f::Vector3f()
		: X(0), Y(0), Z(0)
	{
	}

	Vector3f::Vector3f(float x, float y, float z)
		: X(x), Y(y), Z(z)
	{
	}

	Vector3f& Vector3f::operator=(const Vector3f& that)
	{
		if (this != &that)
		{
			X = that.X;
			Y = that.Y;
			Z = that.Z;
		}
		return *this;
	}

	Vector3f Vector3f::operator-(const Vector3f& that)
	{
		return Vector3f(X - that.X, Y - that.Y, Z - that.Z);
	}

	Vector3f Vector3f::operator+(const Vector3f& that)
	{
		return Vector3f(X + that.X, Y + that.Y, Z + that.Z);
	}

	float Vector3f::operator*(const Vector3f& that)
	{
		return X * that.X +  Y * that.Y + Z * that.Z;
	}

	Vector3f Vector3f::operator*(const float scale)
	{
		return Vector3f(X * scale, Y * scale, Z * scale);
	}

	Vector3f Vector3f::operator^(const Vector3f& that)
	{
		return Vector3f(Y * that.Z - Z * that.Y, X * that.Z - Z * that.X, X * that.Y - Y * that.X);
	}

	float Vector3f::Length()
	{
		return (float)sqrt(X * X + Y * Y + Z * Z);
	}

	void Vector3f::Normalize()
	{
		float length = Length();
		X /= length;
		Y /= length;
		Z /= length;
	}
}