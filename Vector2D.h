#ifndef VECTOR2D_H_DEFINED
#define VECTOR2D_H_DEFINED

class Vector2D
{
public:
	Vector2D(float x, float y): m_x(x), m_y(y) {}
	~Vector2D() {}

	float getX() { return m_x; }
	float getY() { return m_y; }

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	float length();

	Vector2D operator+(const Vector2D& v2) const
	{
		return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	}
	
	friend Vector2D operator+=(Vector2D& v1, Vector2D& v2) {
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	// The global operator function is made friend of this class so
	// that it can access private members
	// friend Vector2D &operator+(Vector2D& v1, Vector2D& v2);

private:

	float m_x;
	float m_y;

};

#endif