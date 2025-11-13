/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:00:40 by huidris           #+#    #+#             */
/*   Updated: 2025/11/12 23:24:55 by huidris          ###   ########.fr       */
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
		std::vector<int> _value;

	public:
		vect2();
		vect2(int v1, int v2);
		vect2 &operator=(const vect2 &other);

		~vect2();

		


};




#endif
