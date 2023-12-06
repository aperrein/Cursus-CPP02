/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:17:47 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/05 15:17:48 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void): _fpvalue(0)
{
    //std::cout << "Default constructor called\n";
}

Fixed::~Fixed(void)
{
   // std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed const & copy)
{
	//std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed &         Fixed::operator=( Fixed const & rhs)
{
	//std::cout << "Copy assignation operator called\n";
	this->_fpvalue = rhs.getRawBits();
	return (*this);
}

int             Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called\n";
	return (this->_fpvalue);
}

void            Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called\n";
	this->_fpvalue = raw;
}


//-------------ex01-----------------------------------------------------


Fixed::Fixed(int const i_para)
{
    //std::cout << "Int constructor called\n";
    this->setRawBits(i_para << this->_fract);
}

Fixed::Fixed(float const f_para)
{
    //std::cout << "Float constructor called\n";
    this->setRawBits((int)roundf(f_para * (1 << this->_fract)));
}

float           Fixed::toFloat(void) const
{
    return ((float)this->getRawBits() / (1 << this->_fract));
}

int             Fixed::toInt(void) const
{
    return (this->getRawBits() >> this->_fract);
}


std::ostream &     operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return (o);
}

//--------------------------------operator--------------------------------------


Fixed           Fixed::operator+(Fixed const & rhs) const
{
    Fixed       res;

    res.setRawBits(this->_fpvalue + rhs.getRawBits());
    return (res);
}

Fixed           Fixed::operator-(Fixed const & rhs) const
{
    Fixed       res;

    res.setRawBits(this->_fpvalue - rhs.getRawBits());
    return (res);
}

Fixed           Fixed::operator*(Fixed const & rhs) const
{
    Fixed       res;

    res.setRawBits((this->_fpvalue * rhs.getRawBits()) >> this->_fract);
    return (res);
}

Fixed           Fixed::operator/(Fixed const & rhs) const
{
    Fixed       res;

    res.setRawBits((this->_fpvalue << this->_fract)/ rhs.getRawBits());
    return (res);
}

//---------------------------compare-------------------------------------

int             Fixed::operator>(Fixed const & rhs) const
{
    if (this->getRawBits() > rhs.getRawBits())
        return (1);
    return (0);
}

int             Fixed::operator<(Fixed const & rhs) const
{
    if (this->getRawBits() < rhs.getRawBits())
        return (1);
    return (0);
}

int             Fixed::operator>=(Fixed const & rhs) const
{
    if (this->getRawBits() >= rhs.getRawBits())
        return (1);
    return (0);
}

int             Fixed::operator<=(Fixed const & rhs) const
{
    if (this->getRawBits() <= rhs.getRawBits())
        return (1);
    return (0);
}

int             Fixed::operator==(Fixed const & rhs) const
{
    if (this->getRawBits() == rhs.getRawBits())
        return (1);
    return (0);
}

int             Fixed::operator!=(Fixed const & rhs) const
{
    if (this->getRawBits() != rhs.getRawBits())
        return (1);
    return (0);
}

Fixed &        Fixed::min(Fixed & a, Fixed & b)
{
    if (a < b)
        return(a);
    return (b);
}

Fixed &        Fixed::max(Fixed & a, Fixed & b)
{
    if (a > b)
        return(a);
    return (b);
}

const Fixed &         Fixed::min(const Fixed & a, const Fixed & b)
{
    if (a < b)
        return(a);
    return (b);
}

const Fixed &         Fixed::max(const Fixed & a, const Fixed & b)
{
    if (a > b)
        return(a);
    return (b);
}


//-----------------------------------crement-------------------------------------------

Fixed &             Fixed::operator++(void)
{
    (this->_fpvalue)++;
    return (*this);
}

Fixed &             Fixed::operator--(void)
{
    (this->_fpvalue)--;
    return (*this);
}

Fixed               Fixed::operator++(int)
{
    Fixed   temp(*this);

    (this->_fpvalue)++;
    return (temp);
}

Fixed               Fixed::operator--(int)
{
    Fixed   temp(*this);

    (this->_fpvalue)--;
    return (temp);
}