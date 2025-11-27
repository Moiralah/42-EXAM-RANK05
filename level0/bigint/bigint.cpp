/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 02:23:44 by huidris           #+#    #+#             */
/*   Updated: 2025/11/27 14:27:29 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

bigint::bigint() : _value("0") {}

bigint::bigint(int value)
{
	_value = toString(value);
}

bigint::bigint(const bigint &other): _value(other._value){}

bigint &bigint::operator=(const bigint &other)
{
	if (this != &other)
		_value = other._value;
	return *this;
}

bigint::~bigint(){}

bool bigint::operator>(const bigint &value)const
{
	if (_value.size() != value._value.size())
		return (_value.size() > value._value.size());
	return _value > value._value;
}

bool bigint::operator<(const bigint &value)const
{
	if (_value.size() != value._value.size())
		return (_value.size() < value._value.size());
	return _value < value._value;
}

bool bigint::operator>=(const bigint &value)const
{
	if (_value.size() != value._value.size())
		return (_value.size() >= value._value.size());
	return _value >= value._value;
}

bool bigint::operator<=(const bigint &value)const
{
	if (_value.size() != value._value.size())
		return (_value.size() <= value._value.size());
	return _value <= value._value;
}

bool bigint::operator==(const bigint &value)const
{
	return (_value == value._value);
}

bool bigint::operator!=(const bigint &value)const
{
	return (_value != value._value);
}

bigint bigint::operator+(bigint value)const
{
	int i = _value.size() - 1;
	int j = value._value.size() - 1;
	int carry = 0;
	std::string result;

	while (i >= 0 || j >= 0 || carry)
	{
		int sum = carry;
		if (i >= 0)
			sum += _value[i--] - '0';
		if (j >= 0)
			sum += value._value[j--] - '0';
		result.push_back((sum % 10) + '0');
		carry = sum / 10;
	}

	std::reverse(result.begin(), result.end());
	bigint ret;

	ret._value = result;
	return ret;
}

bigint &bigint::operator+=(const bigint &value)
{
	*this = *this + value;
	return *this;
}

bigint bigint::operator++()
{
	bigint a(1);
	*this = *this + a;
	return *this;
}

bigint bigint::operator++(int)
{
	bigint temp = *this;
	bigint a(1);
	*this = *this + a;
	return temp;
}

bigint bigint::operator<<(int shift)
{
	bigint result(*this);
	result._value.append(shift, '0');
	return result;
}

bigint bigint::operator>>(int shift)
{
	bigint result(*this);
	int i = result._value.size();
	if (shift >= i)
	{
		result._value = "0";
		return result;
	}
	result._value.erase(i - shift);
	return result;
}

bigint &bigint::operator<<=(int shift)
{
	_value.append(shift, '0');
	return *this;
}

bigint &bigint::operator>>=(int shift)
{
	int i = _value.size();
	if (shift >= i)
		_value = "0";
	else
		_value.erase(i - shift);
	return *this;
}

bigint &bigint::operator>>=(bigint shift)
{
	int n = toInt(shift._value);
	return (*this >>= n);
}

std::string bigint::getValue(void) const
{
	return _value;
}

std::string bigint::toString(int value) const
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

int bigint::toInt(const std::string &value)
{
	std::istringstream iss(value);
	int num;
	iss >> num;
	return num;
}

std::ostream &operator<<(std::ostream &os, const bigint &value)
{
	os << value.getValue();
	return os;
}
