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
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	
		Fixed();
		Fixed(const Fixed& f);
		Fixed(const int);
		Fixed(const float);
		Fixed operator=(const Fixed& f);
		~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif
