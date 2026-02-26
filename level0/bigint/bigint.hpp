#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <iostream>
#include <sstream>
#include <algorithm>

class bigint
{
	private:
		std::string _v;
	public:
		bigint();
		bigint(int value);
		bigint(const bigint &other);

		~bigint();

		bigint &operator=(const bigint &other);

		bool operator>(const bigint &value)const;
		bool operator<(const bigint &value)const;
		bool operator>=(const bigint &value)const;
		bool operator<=(const bigint &value)const;
		bool operator==(const bigint &value)const;
		bool operator!=(const bigint &value)const;

		bigint operator+(bigint value)const;
		bigint &operator+=(const bigint &value);

		bigint operator++();
		bigint operator++(int);
		bigint operator<<(int shift);
		bigint operator>>(int shift);
		bigint &operator<<=(int shift);
		bigint &operator>>=(int shift);
		bigint &operator>>=(bigint shift);

		std::string getVal()const;

};

std::ostream &operator<<(std::ostream &os, const bigint &value);

#endif
