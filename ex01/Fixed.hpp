/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:04:00 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/05 15:04:02 by aperrein         ###   ########.fr       */
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
    ~Fixed();
    Fixed(Fixed const & copy);
    Fixed &     operator=(Fixed const & rhs);

    int         getRawBits(void) const;
    void        setRawBits(int const raw);

    Fixed(int const i_para);
    Fixed(float const f_para);

    float       toFloat(void) const;
    int         toInt(void) const;
    

};

std::ostream &     operator<<(std::ostream & o, Fixed const & rhs);

#endif
