#pragma once

#include<math.h>

class Vector2D
{
public:

	Vector2D(float x, float y) : m_x(x), m_y(y) {}
	
	float getX() { return m_x; }

	float getY() { return m_y; }


	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	//void NULLifier(Vector2D& vec) {
	//	if (vec.getX() == NULL)
	//	{
	//		vec.setX(m_x);
	//	}
	//	if (vec.getY() == NULL)
	//	{
	//		vec.setY(m_x);
	//	}

	//}

	float length() { return sqrt(m_x * m_x + m_y * m_y); }

	//addittion of two vectors

	Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	}

	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	//multiply by a scalar number

	Vector2D operator*(float scalar)
	{
		return Vector2D(m_x * scalar, m_y * scalar);
	}

	Vector2D& operator*=(float scalar)
	{
		m_x *= scalar;
		m_y *= scalar;
		return *this;
	}

	//substraction of two vectors

	Vector2D operator- (const Vector2D& v2) const
	{
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}

	friend Vector2D& operator -=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;
		return v1;
	}

	//divide by a scalar

	Vector2D operator/(float scalar) {
		return Vector2D(m_x / scalar, m_y / scalar);
	}

	Vector2D& operator/=(float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;
		
		return *this;
	}

	//normalizing a vector

	void normalize()
	{
		float L = length();

		if (L > 0) //we never want to divide by 0
		{
			(*this) *= 1 / L;
		}
	}


private:
	float m_x;
	float m_y;
};