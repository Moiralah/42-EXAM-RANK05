/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 02:23:44 by huidris           #+#    #+#             */
/*   Updated: 2025/11/12 17:29:22 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>

class bigint
{
	private:
		std::string _value;
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

		std::string getValue(void) const;

		std::string toString(int value) const;
		int toInt(const std::string &value);
};

std::ostream &operator<<(std::ostream &os, const bigint &value);

#endif
