/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:00:40 by huidris           #+#    #+#             */
/*   Updated: 2026/01/22 14:07:16 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT2_HPP
# define VECT2_HPP

#include <iostream>
#include <sstream>
#include <vector>

class vect2
{
	private:
		int _v[2];

	public:
		// Constructors / destructor
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &other);
		~vect2();

		vect2 &operator=(const vect2 &other);

		// Access
		int &operator[](int index);
		const int &operator[](int index) const;

		// Arithmetic
		vect2 operator+(const vect2 &rhs) const;
		vect2 operator-(const vect2 &rhs) const;
		vect2 operator*(int scalar) const;

		vect2 &operator+=(const vect2 &rhs);
		vect2 &operator-=(const vect2 &rhs);
		vect2 &operator*=(int scalar);

		// Unary
		vect2 operator-() const;

		// Increment / Decrement
		vect2 &operator++();     // ++v
		vect2 operator++(int);   // v++
		vect2 &operator--();     // --v
		vect2 operator--(int);   // v--

		// Comparison
		bool operator==(const vect2 &rhs) const;
		bool operator!=(const vect2 &rhs) const;
};

// Scalar on the left: 3 * v
vect2 operator*(int scalar, const vect2 &v);

// Output
std::ostream &operator<<(std::ostream &os, const vect2 &v);

#endif
