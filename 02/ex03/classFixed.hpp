#ifndef FIXED_CLASS
# define FIXED_CLASS

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int	_val;
		static const int _frac = 8;
	public:
		int 	getRawBits(void) const;
		void	setRawBits(int const);
		float	toFloat(void) const;
		int		toInt(void) const;
	
	//CONSTRUCTORS & ASSIGNMENT:
		Fixed();
		Fixed(const Fixed&);
		Fixed(const int);
		Fixed(const float);
		Fixed& operator=(const Fixed&);

	//COMPARISON OPERATOR OVERLOADS:
		bool operator<(const Fixed&) const;
		bool operator>(const Fixed&) const;
		bool operator<=(const Fixed&) const;
		bool operator>=(const Fixed&) const;
		bool operator==(const Fixed&) const;
		bool operator!=(const Fixed&) const;

	//ARITHMETIC OPERATOR OVERLOADS:
		float operator+(const Fixed&) const;
		float operator-(const Fixed&) const;
		float operator*(const Fixed&) const;
		float operator/(const Fixed&) const;

	//INCREMENTATION OPERATOR OVERLOADS:
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

	//MIN & MAX CHECKS:
		static Fixed& min(Fixed&, Fixed&);
		static const Fixed& min(const Fixed&, const Fixed&);
		static Fixed& max(Fixed&, Fixed&);
		static const Fixed& max(const Fixed&, const Fixed&);


	//DESTRUCTORS:
		~Fixed();
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
