#include "bigint.hpp"

bigint::bigint() : _v("0"){}

bigint::bigint(int val)
{
    std::stringstream oss;
    oss << val;
    _v = oss.str();
}

bigint::bigint(const bigint &other) : _v(other._v){}

bigint::~bigint(){}

bigint &bigint::operator=(const bigint &other)
{
    if(this != &other)
        _v = other._v;
    return *this;
}

bool bigint::operator>(const bigint &value)const
{
    if(_v.size() != value._v.size())
        return _v.size() > value._v.size();
    return _v > value._v;
}

bool bigint::operator<(const bigint &value)const
{
    if(_v.size() != value._v.size())
        return _v.size() < value._v.size();
    return _v < value._v;
}

bool bigint::operator>=(const bigint &value)const
{
    if(_v.size() != value._v.size())
        return _v.size() > value._v.size();
    return _v > value._v;
}

bool bigint::operator<=(const bigint &value)const
{
    if(_v.size() != value._v.size())
        return _v.size() <= value._v.size();
    return _v <= value._v;
}

bool bigint::operator==(const bigint &value)const
{
    return _v == value._v;
}

bool bigint::operator!=(const bigint &value)const
{
    return _v != value._v;
}

bigint bigint::operator+(bigint value)const
{
    int i = _v.size() - 1;
    int j = value._v.size() - 1;
    int carry = 0;
    std::string res;

    while(i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if( i >= 0)
            sum += _v[i--] - '0';
        if ( j >= 0)
            sum += value._v[j--] - '0';
        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    std::reverse(res.begin(), res.end());
    bigint result;
    result._v = res;
    return result;
}

bigint &bigint::operator+=(const bigint &value)
{
    *this = *this + value;
    return *this;
}

bigint bigint::operator++()
{
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint temp = *this;
    *this += bigint(1);
    return temp;
}

bigint bigint::operator>>(int shift)
{
    int i = _v.size();
    if ( i > shift)
    {
        _v.erase(i - shift);
        return *this;
    }
    return bigint(0);
}

bigint bigint::operator<<(int shift)
{
    while(shift > 0)
    {
        _v.append("0");
        shift--;
    }
    return *this; 
}

bigint &bigint::operator<<=(int shift)
{
    *this << shift;
    return *this;
}

bigint &bigint::operator>>=(int shift)
{
    *this >> shift;
    return *this;
}

bigint &bigint::operator>>=(bigint shift)
{
    std::stringstream oss;
    oss << shift._v;
    int num;
    oss >> num;

    *this >>= num;
    return *this;
}

std::string bigint::getVal() const
{
    return _v;
}

std::ostream &operator<<(std::ostream &os, const bigint &value)
{
    os << value.getVal();
    return os;
}