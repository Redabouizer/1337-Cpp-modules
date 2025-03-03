#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int 				value;
		static const int	fractBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const float val);
		Fixed(const int val);
		~Fixed(void);

		Fixed&			operator=(const Fixed& other);
		int 			getRawBits(void) const;
		void			setRawBits(const int raw);
		
		int 			toInt(void) const;
		float			toFloat(void) const;
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);