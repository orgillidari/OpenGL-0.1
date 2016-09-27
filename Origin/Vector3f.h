#pragma once

#include <math.h>

namespace illidan
{
	class Vector3f
	{
	public:
		float X;
		float Y;
		float Z;
	
	public:
		Vector3f();
		Vector3f& operator=(const Vector3f& that);

	public:
		Vector3f(float x, float y, float z);
		Vector3f operator-(const Vector3f& that);
		Vector3f operator+(const Vector3f& that);
		float operator*(const Vector3f& that);
		Vector3f operator*(const float scale);
		Vector3f operator^(const Vector3f& that);

	public:
		float Length();
		void Normalize();
	};
}
