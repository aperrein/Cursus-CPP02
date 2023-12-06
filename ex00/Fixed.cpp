/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:44:33 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/14 09:44:35 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fpvalue(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed &         Fixed::operator=( Fixed const & rhs)
{
	std::cout << "Copy assignation operator called\n";
	this->_fpvalue = rhs.getRawBits();
	return (*this);
}

int             Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_fpvalue);
}

void            Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->_fpvalue = raw;
}