#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>

class Fixed {
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(Fixed const &src);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed();

		Fixed&			operator=(Fixed const &rSym);
		Fixed			operator+(Fixed const &rSym) const;
		Fixed			operator-(Fixed const &rSym) const;
		Fixed			operator*(Fixed const &rSym) const;
		Fixed			operator/(Fixed const &rSym) const;
		bool			operator<(Fixed const &rSym) const;
		bool			operator>(Fixed const &rSym) const;
		bool			operator<=(Fixed const &rSym) const;
		bool			operator>=(Fixed const &rSym) const;
		bool			operator==(Fixed const &rSym) const;
		bool			operator!=(Fixed const &rSym) const;
		Fixed&			operator++();
		Fixed			operator++(int);
		Fixed&			operator--();
		Fixed			operator--(int);

		int				getRawBits() const;
		void			setRawBits(int const raw);
		float			toFloat() const;
		int				toInt() const;
		
		static Fixed &			min(Fixed &a, Fixed &b);
		static Fixed const &	min(Fixed const &a, Fixed const &b);
		static Fixed &			max(Fixed &a, Fixed &b);
		static Fixed const &	max(Fixed const &a, Fixed const &b);


};

std::ostream&	operator<<(std::ostream& o, Fixed const &rSym);

#endif