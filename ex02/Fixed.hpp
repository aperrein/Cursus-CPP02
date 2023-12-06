/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:15:24 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/05 15:15:26 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

private:

    int                   _fpvalue;
    static const int      _fract = 8;


public:

    Fixed();
    Fixed(int const i_para);
    Fixed(float const f_para);
    ~Fixed();
    Fixed(Fixed const & copy);

    Fixed &     operator=(Fixed const & rhs);

    Fixed       operator+(Fixed const & rhs) const;
    Fixed       operator-(Fixed const & rhs) const;
    Fixed       operator*(Fixed const & rhs) const;
    Fixed       operator/(Fixed const & rhs) const;

    Fixed &     operator++(void);
    Fixed &     operator--(void);
    Fixed       operator++(int);
    Fixed       operator--(int);

    int         operator>(Fixed const & rhs) const;
    int         operator<(Fixed const & rhs) const;
    int         operator>=(Fixed const & rhs) const;
    int         operator<=(Fixed const & rhs) const;
    int         operator==(Fixed const & rhs) const;
    int         operator!=(Fixed const & rhs) const;

    int         getRawBits(void) const;
    void        setRawBits(int const raw);

    static Fixed &  min(Fixed & a, Fixed & b);
    static Fixed &  max(Fixed & a, Fixed & b);
    static const Fixed &  min(const Fixed & a, const Fixed & b);
    static const Fixed &  max(const Fixed & a, const Fixed & b);

    float           toFloat(void) const;
    int             toInt(void) const;
    

};

std::ostream &     operator<<(std::ostream & o, Fixed const & rhs);

#endif

