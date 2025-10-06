#ifndef FIXED_CLASS
# define FIXED_CLASS

# include <iostream>

class	Fixed
{
	private:
		int	_val;
		static const int _frac = 8;
	public:
		Fixed();
		Fixed(const Fixed& f);
		Fixed& operator=(const Fixed& f);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
