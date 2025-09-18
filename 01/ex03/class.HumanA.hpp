#ifndef HUMAN_A_CLASS
# define HUMAN_A_CLASS

# include "class.Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon&		_weapon;
	public:
		void	attack();

	HumanA(std::string name, Weapon&);
	~HumanA();
};

#endif
