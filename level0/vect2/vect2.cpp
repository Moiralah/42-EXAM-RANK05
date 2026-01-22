#include "vect2.hpp"

/* Constructors */

vect2::vect2()
{
	_v[0] = 0;
	_v[1] = 0;
}

vect2::vect2(int x, int y)
{
	_v[0] = x;
	_v[1] = y;
}

vect2::vect2(const vect2 &other)
{
	_v[0] = other._v[0];
	_v[1] = other._v[1];
}

vect2::~vect2() {}

vect2 &vect2::operator=(const vect2 &other)
{
	if (this != &other)
	{
		_v[0] = other._v[0];
		_v[1] = other._v[1];
	}
	return *this;
}

/* Access */

int &vect2::operator[](int index)
{
	return _v[index];
}

const int &vect2::operator[](int index) const
{
	return _v[index];
}

/* Arithmetic */

vect2 vect2::operator+(const vect2 &rhs) const
{
	return vect2(_v[0] + rhs._v[0], _v[1] + rhs._v[1]);
}

vect2 vect2::operator-(const vect2 &rhs) const
{
	return vect2(_v[0] - rhs._v[0], _v[1] - rhs._v[1]);
}

vect2 vect2::operator*(int scalar) const
{
	return vect2(_v[0] * scalar, _v[1] * scalar);
}

vect2 &vect2::operator+=(const vect2 &rhs)
{
	_v[0] += rhs._v[0];
	_v[1] += rhs._v[1];
	return *this;
}

vect2 &vect2::operator-=(const vect2 &rhs)
{
	_v[0] -= rhs._v[0];
	_v[1] -= rhs._v[1];
	return *this;
}

vect2 &vect2::operator*=(int scalar)
{
	_v[0] *= scalar;
	_v[1] *= scalar;
	return *this;
}

/* Unary */

vect2 vect2::operator-() const
{
	return vect2(-_v[0], -_v[1]);
}

/* Increment / Decrement */

vect2 &vect2::operator++()
{
	++_v[0];
	++_v[1];
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 tmp(*this);
	++(*this);
	return tmp;
}

vect2 &vect2::operator--()
{
	--_v[0];
	--_v[1];
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 tmp(*this);
	--(*this);
	return tmp;
}

/* Comparison */

bool vect2::operator==(const vect2 &rhs) const
{
	return _v[0] == rhs._v[0] && _v[1] == rhs._v[1];
}

bool vect2::operator!=(const vect2 &rhs) const
{
	return !(*this == rhs);
}

/* Non-member operators */

vect2 operator*(int scalar, const vect2 &v)
{
	return v * scalar;
}

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
	os << "{" << v[0] << ", " << v[1] << "}";
	return os;
}
