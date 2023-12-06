/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 09:44:22 by aperrein          #+#    #+#             */
/*   Updated: 2023/09/14 09:44:24 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

private:

    int             _fpvalue;
    static const int      _fract = 8;


public:

    Fixed();
    ~Fixed();
    Fixed(Fixed const & copy);
    Fixed &     operator=(Fixed const &rhs);


    int         getRawBits(void) const;
    void        setRawBits(int const raw);
    

};

#endif
